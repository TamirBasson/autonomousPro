#include "mpu9250driver/mpu9250driver.h"

#include <chrono>
#include <memory>

#include "LinuxI2cCommunicator.h"

using namespace std::chrono_literals;
constexpr double DEG2RAD = M_PI / 180.0;
mpu9250driver::mpu9250driver() : Node("mpu9250publisher")
{
  // Create concrete I2C communicator and pass to sensor
  std::unique_ptr<I2cCommunicator> i2cBus = std::make_unique<LinuxI2cCommunicator>();
  mpu9250_ = std::make_unique<MPU9250Sensor>(std::move(i2cBus));
  // Declare parameters
  declareParameters();
  // Set parameters
  mpu9250_->setGyroscopeRange(
      static_cast<MPU9250Sensor::GyroRange>(this->get_parameter("gyro_range").as_int()));
  mpu9250_->setAccelerometerRange(
      static_cast<MPU9250Sensor::AccelRange>(this->get_parameter("accel_range").as_int()));
  mpu9250_->setDlpfBandwidth(
      static_cast<MPU9250Sensor::DlpfBandwidth>(this->get_parameter("dlpf_bandwidth").as_int()));
  mpu9250_->setGyroscopeOffset(this->get_parameter("gyro_x_offset").as_double(),
                               this->get_parameter("gyro_y_offset").as_double(),
                               this->get_parameter("gyro_z_offset").as_double());
  mpu9250_->setAccelerometerOffset(this->get_parameter("accel_x_offset").as_double(),
                                   this->get_parameter("accel_y_offset").as_double(),
                                   this->get_parameter("accel_z_offset").as_double());
  // Check if we want to calibrate the sensor
  if (this->get_parameter("calibrate").as_bool()) {
    RCLCPP_INFO(this->get_logger(), "Calibrating...");
    mpu9250_->calibrate();
  }
  mpu9250_->printConfig();
  mpu9250_->printOffsets();
  // Create publisher
  publisher_ = this->create_publisher<sensor_msgs::msg::Imu>("/imu", 10);
  std::chrono::duration<int64_t, std::milli> frequency =
      1000ms / this->get_parameter("gyro_range").as_int();
  timer_ = this->create_wall_timer(frequency, std::bind(&mpu9250driver::handleInput, this));
}

void mpu9250driver::handleInput()
{
  auto message = sensor_msgs::msg::Imu();
  message.header.stamp = this->get_clock()->now();
  message.header.frame_id = "base_link";
  // Direct measurements
  message.linear_acceleration_covariance = {0};
  message.linear_acceleration.x = mpu9250_->getAccelerationX();
  message.linear_acceleration.y = mpu9250_->getAccelerationY();
  message.linear_acceleration.z = mpu9250_->getAccelerationZ();
  message.angular_velocity_covariance[0] = {0};
  message.angular_velocity.x = mpu9250_->getAngularVelocityX()*DEG2RAD;
  message.angular_velocity.y = mpu9250_->getAngularVelocityY()*DEG2RAD;
  message.angular_velocity.z = mpu9250_->getAngularVelocityZ()*DEG2RAD;
  if(message.angular_velocity.x < -2.0)
    message.angular_velocity.x=0;
  if(message.angular_velocity.y < -2.0)
    message.angular_velocity.y=0;
  if(message.angular_velocity.z < -2.0)
    message.angular_velocity.z=0;
  // Calculate euler angles, convert to quaternion and store in message
  message.orientation_covariance = {0};
  calculateOrientation(message);
  publisher_->publish(message);
}

void mpu9250driver::declareParameters()
{
  this->declare_parameter<bool>("calibrate", true);
  this->declare_parameter<int>("gyro_range", MPU9250Sensor::GyroRange::GYR_250_DEG_S);
  this->declare_parameter<int>("accel_range", MPU9250Sensor::AccelRange::ACC_2_G);
  this->declare_parameter<int>("dlpf_bandwidth", MPU9250Sensor::DlpfBandwidth::DLPF_260_HZ);
  this->declare_parameter<double>("gyro_x_offset", 0.0);
  this->declare_parameter<double>("gyro_y_offset", 0.0);
  this->declare_parameter<double>("gyro_z_offset", 0.0);
  this->declare_parameter<double>("accel_x_offset", 0.0);
  this->declare_parameter<double>("accel_y_offset", 0.0);
  this->declare_parameter<double>("accel_z_offset", 0.0);
  this->declare_parameter<int>("frequency", 0.0);
}

void mpu9250driver::calculateOrientation(sensor_msgs::msg::Imu& imu_message)
{
  // Calculate Euler angles
  double roll, pitch, yaw;
  roll = atan2(imu_message.linear_acceleration.y, imu_message.linear_acceleration.z);
  pitch = atan2(-imu_message.linear_acceleration.y,
                (sqrt(imu_message.linear_acceleration.y * imu_message.linear_acceleration.y +
                      imu_message.linear_acceleration.z * imu_message.linear_acceleration.z)));
  yaw = atan2(mpu9250_->getMagneticFluxDensityY(), mpu9250_->getMagneticFluxDensityX());

  // Convert to quaternion
  double cy = cos(yaw * 0.5);
  double sy = sin(yaw * 0.5);
  double cp = cos(pitch * 0.5);
  double sp = sin(pitch * 0.5);
  double cr = cos(roll * 0.5);
  double sr = sin(roll * 0.5);

  imu_message.orientation.x = cy * cp * sr - sy * sp * cr;
  imu_message.orientation.y = sy * cp * sr + cy * sp * cr;
  imu_message.orientation.z = sy * cp * cr - cy * sp * sr;
  imu_message.orientation.w = cy * cp * cr + sy * sp * sr;
}

int main(int argc, char* argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<mpu9250driver>());
  rclcpp::shutdown();
  return 0;
}
