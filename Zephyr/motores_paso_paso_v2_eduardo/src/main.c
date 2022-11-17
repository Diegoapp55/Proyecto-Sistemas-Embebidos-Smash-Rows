/*
 * Copyright (c) 2016 Intel Corporation
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <zephyr/kernel.h>
#include <zephyr/drivers/gpio.h>
#include <esp_log.h>

/* 1000 msec = 1 sec */
#define SLEEP_TIME_US   1000

/* Define all coils for the motors */
/*Nodos del motor 1*/
#define COIL1_NODE DT_ALIAS(coil1_alias)
#define COIL2_NODE DT_ALIAS(coil2_alias)
#define COIL3_NODE DT_ALIAS(coil3_alias)
#define COIL4_NODE DT_ALIAS(coil4_alias)

/*Nodos del motor 2*/
#define COIL5_NODE DT_ALIAS(coil5_alias)
#define COIL6_NODE DT_ALIAS(coil6_alias)
#define COIL7_NODE DT_ALIAS(coil7_alias)
#define COIL8_NODE DT_ALIAS(coil8_alias)
#define OK 0

/*Llamado a los pines reales motor 1*/
static const struct gpio_dt_spec coil1 = GPIO_DT_SPEC_GET(COIL1_NODE, gpios);
static const struct gpio_dt_spec coil2 = GPIO_DT_SPEC_GET(COIL2_NODE, gpios);
static const struct gpio_dt_spec coil3 = GPIO_DT_SPEC_GET(COIL3_NODE, gpios);
static const struct gpio_dt_spec coil4 = GPIO_DT_SPEC_GET(COIL4_NODE, gpios);

/*Llamado a los pines reales motor 2*/
static const struct gpio_dt_spec coil5 = GPIO_DT_SPEC_GET(COIL5_NODE, gpios);
static const struct gpio_dt_spec coil6 = GPIO_DT_SPEC_GET(COIL6_NODE, gpios);
static const struct gpio_dt_spec coil7 = GPIO_DT_SPEC_GET(COIL7_NODE, gpios);
static const struct gpio_dt_spec coil8 = GPIO_DT_SPEC_GET(COIL8_NODE, gpios);

int leerTabla(int paso[], int posicion){
	int lectura = paso[posicion];
	return lectura;
}

void main(void)
{
	int ret = 0;
	int vel_motor=1000;
	int count_step = 0;
	int round_step = 4076;

	const int numberSteps = 32;
	const int tableSteps[4] = {B1000, B0100, B0010, B0001};

	//Definicion de los motores como salida
	ret = gpio_pin_configure_dt(&coil1, GPIO_OUTPUT_LOW);
	if (ret < OK) {
		return;
	}

	ret = gpio_pin_configure_dt(&coil2, GPIO_OUTPUT_LOW);
	if (ret < OK) {
		return;
	}

	ret = gpio_pin_configure_dt(&coil3, GPIO_OUTPUT_LOW);
	if (ret < OK) {
		return;
	}

	ret = gpio_pin_configure_dt(&coil4, GPIO_OUTPUT_LOW);
	if (ret < OK) {
		return;
	}

	ret = gpio_pin_configure_dt(&coil5, GPIO_OUTPUT_LOW);
	if (ret < OK) {
		return;
	}

	ret = gpio_pin_configure_dt(&coil6, GPIO_OUTPUT_LOW);
	if (ret < OK) {
		return;
	}

	ret = gpio_pin_configure_dt(&coil7, GPIO_OUTPUT_LOW);
	if (ret < OK) {
		return;
	}

	ret = gpio_pin_configure_dt(&coil8, GPIO_OUTPUT_LOW);
	if (ret < OK) {
		return;
	}

	//Si no se mueve lo suficiente, probar antes con while(1)
	while (count_step<numberSteps) { //En vez de 1 poner señal de control que se active con la orden de dispensar y se apague hasta que lo haga
		//ret = gpio_pin_set_dt(&coil1, 1/0)
		//Cambio el valor de los pines coilX
		for (int i = 0; i < 4; i++) {
			switch (tableSteps[i]) {
				case B1000:
					gpio_pin_set_dt(&coil1, 1);
					gpio_pin_set_dt(&coil2, 0);
					gpio_pin_set_dt(&coil3, 0);
					gpio_pin_set_dt(&coil4, 0);
					break;
				case B0100:
					gpio_pin_set_dt(&coil1, 0);
					gpio_pin_set_dt(&coil2, 1);
					gpio_pin_set_dt(&coil3, 0);
					gpio_pin_set_dt(&coil4, 0);
					break;
				case B0010:
					gpio_pin_set_dt(&coil1, 0);
					gpio_pin_set_dt(&coil2, 0);
					gpio_pin_set_dt(&coil3, 1);
					gpio_pin_set_dt(&coil4, 0);
					break;
				case B0001:
					gpio_pin_set_dt(&coil1, 0);
					gpio_pin_set_dt(&coil2, 0);
					gpio_pin_set_dt(&coil3, 0);
					gpio_pin_set_dt(&coil4, 1);
					break;
			}
			count_step++; //Revisar si esto está bien o es mejor ponerlo fuera del for para que cuente vueltasy no cada paso
			k_usleep(SLEEP_TIME_US);
		}
	}
}
