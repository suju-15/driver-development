# driver-development

Device drivers, written from scratch and kept in one place - one folder per driver.

Each folder is a self-contained project (its own build files, example app and
documentation), so a driver can be read on its own, copied out, or reused.

## Drivers

| Driver | Bus | Target | Notes |
|---|---|---|---|
| [`mpu6050/`](mpu6050/) | I2C | ESP32-C3 (ESP-IDF) | 6-axis accelerometer + gyroscope, packaged as a reusable component |

## Layout

```
mpu6050/            # one folder per driver
  components/       # the driver itself, as a reusable component
  main/             # a small example app that uses it
  README.md         # how to build, flash and use it
```

## Conventions

- The **bus layer** (I2C/SPI transactions) stays separate from the **device layer**
  (registers, scaling, units). That separation is what makes a driver portable.
- Each driver's `README.md` documents the registers used, the wiring, and the units
  of every value it returns.
- Drivers are written against the reference manual, not copied from a vendor HAL.

## History note

`mpu6050/` was originally its own repository, `mpu6050_i2c_driver`. It was moved here
so that all drivers live together. The original repo is archived; this copy contains
the code but not the original commit history.
