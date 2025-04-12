/*
 * Copyright (c) 2020 The ZMK Contributors
 *
 * SPDX-License-Identifier: MIT
 */
#if 0
#include <zephyr/kernel.h>
#include <zephyr/device.h>
#include <zephyr/init.h>
#include <zephyr/drivers/gpio.h>
#include <zephyr/sys/sys_io.h>
#include <zephyr/devicetree.h>


#include <zephyr/logging/log.h>

LOG_MODULE_DECLARE(zmk, CONFIG_ZMK_LOG_LEVEL);

static int pinmux_nice_nano_v2_init(void) {
#if (CONFIG_BOARD_NICE_NANO_V2)
    const struct device *p0 = DEVICE_DT_GET(DT_NODELABEL(gpio0));
    gpio_pin_configure(p0, 13, GPIO_OUTPUT);
    gpio_pin_set(p0, 13, 1);
    LOG_WRN("Enabling Power GPIO");
#endif
    return 0;
}

SYS_INIT(pinmux_nice_nano_v2_init, EARLY, 10);

#endif
