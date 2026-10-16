#ifndef MPU6050_H
#define MPU6050_H


#include "driver/i2c_master.h" //esp32 i2c driver
#include "esp_err.h"

#define MPU6050_ADDE_DEFAULT 0x68
// deafauld address of mpu6050 i2c

#define MPU6050_REG_PWR_MGMT_1  0x6B 
// power management register clear to activate chip 
#define MPU6050_REG_ACCEL_XOUT_H 0x3B
//starting point of accelerometer data 
    /*X-axis 0x3B 0x3C
      Y-axis 0x3D 0x3E
      Z-axis 0x3F 0x40 */

esp_err_t mpu6050_init(i2c_master_bus_handle_t bus_handle, i2c_master_dev_handle_t *dev_handle);
esp_err_t mpu6050_read_accel(i2c_master_dev_handle_t dev_handle, int16_t *x, int16_t *y, int16_t *z);
#endif 