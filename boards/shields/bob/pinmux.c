/*
 * Copyright (c) 2020 The ZMK Contributors
 *
 * SPDX-License-Identifier: MIT
 */

#include <zephyr/kernel.h>
#include <zephyr/device.h>
#include <zephyr/init.h>
#include <zephyr/drivers/gpio.h>
#include <zephyr/sys/sys_io.h>
#include <zephyr/devicetree.h>

static int pinmux_nice_nano_v2_init(void) {
#if (CONFIG_BOARD_NICE_NANO_V2)
    const struct device *p0 = DEVICE_DT_GET(DT_NODELABEL(gpio0));
    gpio_pin_configure(p0, 13, GPIO_OUTPUT);
    gpio_pin_set(p0, 13, 1);
#endif
    return 0;
}

SYS_INIT(pinmux_nice_nano_v2_init, APPLICATION, CONFIG_GPIO_INIT_PRIORITY);
