/*
 * Copyright (c) 2016 Intel Corporation
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <zephyr/kernel.h>
#include <zephyr/drivers/gpio.h>

/* 1000 msec = 1 sec */
#define SLEEP_TIME_MS   1000

/* The devicetree node identifier for the "pin_output" alias. */
#define PIN_OUT_NODE DT_ALIAS(pin_output)

/*
 * A build error on this line means your board is unsupported.
 * See the sample documentation for information on how to fix this.
 */
static const struct gpio_dt_spec pin_output = GPIO_DT_SPEC_GET(PIN_OUT_NODE, gpios);

void main(void)
{
	int ret;

	if (!device_is_ready(pin_output.port)) {
		return;
	}

	ret = gpio_pin_configure_dt(&pin_output, GPIO_OUTPUT_ACTIVE);
	if (ret < 0) {
		return;
	}

	while (1) {
		ret = gpio_pin_toggle_dt(&pin_output);
		if (ret < 0) {
			return;
		}
		k_msleep(SLEEP_TIME_MS);
	}
}
