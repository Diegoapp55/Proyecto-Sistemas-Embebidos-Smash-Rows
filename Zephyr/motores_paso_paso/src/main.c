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

/*
 * A build error on this line means your board is unsupported.
 * See the sample documentation for information on how to fix this.
 */

 //definicion de pines
 const int pinMotor1 = 8;    // 28BYJ48 - In1
 const int pinMotor2 = 9;    // 28BYJ48 - In2
 const int pinMotor3 = 10;   // 28BYJ48 - In3
 const int pinMotor4 = 11;   // 28BYJ48 - In4

 //definicion variables
 int velocidadMotor = 1000;  // variable para determinar la velocidad

 int contadorPasos = 0;      // contador para los pasos
 int pasosPorVuelta = 4076;  // pasos para una vuelta completa

//secuencia media fase usar velocidadMotor = 1000
 const int cantidadPasos = 8;
 const int tablaPasos[8] = { B1000, B1100, B0100, B0110, B0010, B0011, B0001, B1001 };


static const struct gpio_dt_spec motor1 = GPIO_DT_SPEC_GET(LED0_NODE, gpios);

void main(void)
{


	ret = gpio_pin_configure_dt(&motor1, GPIO_OUTPUT_ACTIVE);
	if (ret < 0) {
		return;
	}

	ret = gpio_pin_configure_dt(&motor2, GPIO_OUTPUT_ACTIVE);
	if (ret < 0) {
		return;
	}

	ret = gpio_pin_configure_dt(&motor3, GPIO_OUTPUT_ACTIVE);
	if (ret < 0) {
		return;
	}

	ret = gpio_pin_configure_dt(&motor4, GPIO_OUTPUT_ACTIVE);
	if (ret < 0) {
		return;
	}
}





int ret;

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
