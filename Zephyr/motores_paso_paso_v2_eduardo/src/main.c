/*
 * Copyright (c) 2016 Intel Corporation
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <zephyr/kernel.h>
#include <zephyr/drivers/gpio.h>
#include <esp_log.h>

/* 1000 msec = 1 sec */
#define SLEEP_TIME_MS   1000

/* Define all coils for the motors */
#define COIL1_NODE DT_ALIAS(coil1)
#define PIN_OUT_NODE DT_ALIAS(coil2)
#define PIN_OUT_NODE DT_ALIAS(coil3)
#define PIN_OUT_NODE DT_ALIAS(coil4)

static const struct gpio_dt_spec coil1 = GPIO_DT_SPEC_GET(COIL1_NODE, gpios);
static const struct gpio_dt_spec coil2 = GPIO_DT_SPEC_GET(PIN_OUT_NODE, gpios);
static const struct gpio_dt_spec coil3 = GPIO_DT_SPEC_GET(PIN_OUT_NODE, gpios);
static const struct gpio_dt_spec coil4 = GPIO_DT_SPEC_GET(PIN_OUT_NODE, gpios);



void main(void)
{
	int vel_motor=1000;
	int count_step = 0;
	int round_step = 4076;

	if (!device_is_ready(led.port)) {
		return;
	}

	ret = gpio_pin_configure_dt(&led, GPIO_OUTPUT_ACTIVE);
	if (ret < 0) {
		return;
	}

	while (1) {
		ret = gpio_pin_toggle_dt(&led);
		if (ret < 0) {
			return;
		}
		k_msleep(SLEEP_TIME_MS);
	}
}
