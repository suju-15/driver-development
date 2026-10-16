#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/i2c_master.h"
#include "mpu6050.h" // Your new header

void app_main(void) {
    // 1. Setup I2C Bus Configuration
    i2c_master_bus_config_t i2c_mst_config = {
        .clk_source = I2C_CLK_SRC_DEFAULT,
        .i2c_port = 0,
        .scl_io_num = 9,  // Change to your SCL pin
        .sda_io_num = 8,  // Change to your SDA pin
        .glitch_ignore_cnt = 7,
    };
    i2c_master_bus_handle_t bus_handle;
    ESP_ERROR_CHECK(i2c_new_master_bus(&i2c_mst_config, &bus_handle));

    // 2. Initialize MPU6050
    i2c_master_dev_handle_t mpu_handle;
    ESP_ERROR_CHECK(mpu6050_init(bus_handle, &mpu_handle));
    printf("MPU6050 initialized successfully!\n");

    // 3. Read loop
    int16_t x, y, z;
    while (1) {
        if (mpu6050_read_accel(mpu_handle, &x, &y, &z) == ESP_OK) {
           // printf("Accel: X: %d, Y: %d, Z: %d\n", x, y, z);
            printf("%d,%d,%d\n",x,y,z);
        } else {
            printf("Failed to read sensor!\n");
        }
        vTaskDelay(pdMS_TO_TICKS(50)); // Read every 500ms
    }
}