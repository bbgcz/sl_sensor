#pragma once

#include <opencv2/opencv.hpp>
#include <utility>

#include "sl_sensor_calibration/calibration_option.hpp"
#include "sl_sensor_calibration/camera_parameters.hpp"
#include "sl_sensor_calibration/projector_parameters.hpp"

namespace sl_sensor
{
namespace calibration
{
class Calibrator
{
public:
  Calibrator();
  void SetProjectorResolution(unsigned int projector_cols, unsigned int projector_rows);
  void SetCheckerboardInformation(unsigned int checkerboard_cols, unsigned int checkerboard_rows,
                                  unsigned int checkerboard_size_mm);
  void SetCalibrateCameraOnly(bool calibrate_camera_only);
  void SetCameraCalibrationOption(const CalibrationOption& camera_calibration_option);
  void SetProjectorCalibrationOption(const CalibrationOption& projector_calibration_option);
  void SetLocalHomographySettings(unsigned int window_radius, unsigned int minimum_valid_pixels);
  bool AddSingleCalibrationSequence(const cv::Mat& camera_shading, const cv::Mat& camera_mask,
                                    const std::string& label = "", const cv::Mat& up = cv::Mat(),
                                    const cv::Mat& vp = cv::Mat());

  std::pair<ProjectorParameters, CameraParameters> Calibrate();
  void Clear();

private:
  unsigned int resolution_x_proj_ = 0;
  unsigned int resolution_y_proj_ = 0;
  unsigned int window_radius_ = 10;
  unsigned int minimum_valid_pixels_ = 50;
  unsigned int checkerboard_cols_ = 10;
  unsigned int checkerboard_rows_ = 10;
  unsigned int checkerboard_size_mm_ = 10;
  unsigned int resolution_x_cam_ = 0;
  unsigned int resolution_y_cam_ = 0;

  CalibrationOption camera_calibration_option_;
  CalibrationOption projector_calibration_option_;

  std::vector<std::vector<cv::Point2f>> corner_camera_coordinates_storage_;
  std::vector<std::vector<cv::Point2f>> corner_projector_coordinates_storage_;
  std::vector<std::vector<cv::Point3f>> corner_3d_coordinates_storage_;
  std::vector<std::string> sequence_label_storage_;
};

}  // namespace calibration
}  // namespace sl_sensor