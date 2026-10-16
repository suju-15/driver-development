#include "mpu6050.h"
#include "esp_log.h"
#include "driver/i2c_master.h"
#include "esp_err.h"


esp_err_t mpu6050_init(i2c_master_bus_handle_t bus_handle, i2c_master_dev_handle_t *dev_handle)
{
    i2c_device_config_t dev_cfg= {
        .dev_addr_length =I2C_ADDR_BIT_7,
        .device_address=MPU6050_ADDE_DEFAULT,
        .scl_speed_hz=400000 //400khz i2c clk
    };

    esp_err_t ret=i2c_master_bus_add_device(bus_handle,&dev_cfg,dev_handle);
    if(ret!=ESP_OK) return ret;

    uint8_t write_buf[2]= {MPU6050_REG_PWR_MGMT_1, 0x00};
    return i2c_master_transmit(*dev_handle,write_buf,2,-1);

}

esp_err_t mpu6050_read_accel(i2c_master_dev_handle_t dev_handle, int16_t *x, int16_t *y, int16_t *z)
{
    uint8_t reg_addr=MPU6050_REG_ACCEL_XOUT_H;
    uint8_t data[6];

    esp_err_t ret = i2c_master_transmit_receive(dev_handle, &reg_addr, 1, data, 6, -1);

    if(ret== ESP_OK)
    {
        *x=(int16_t)((data[0]<<8)| data[1]);
        *y=(int16_t)((data[2]<<8)| data[3]);
        *z=(int16_t)((data[4]<<8)| data[5]);

    }
    return ret;
}