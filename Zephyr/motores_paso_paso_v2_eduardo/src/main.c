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


void main(void)
{
	int ret = 0;
	int vel_motor=1000;
	int count_step = 0;
	int round_step = 4076;

	const int numberSteps = 4;
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

	

	while (1) {
		ret = gpio_pin_toggle_dt(&led);
		if (ret < 0) {
			return;
		}
		k_msleep(SLEEP_TIME_MS);
	}
}



void sentidoHorario() // en dirección de las agujas del reloj
{
contadorPasos++;
if (contadorPasos >= cantidadPasos) contadorPasos = 0;
escribirSalidas(contadorPasos);
}

//ret = gpio_pin_set_dt(&coil1, 1/0)
//Cambio el valor de coil1  de 0 a 1
gpio_pin_set_dt(&coil1, 1);




void escribirSalidas(int paso)
{
digitalWrite(pinMotor1, bitRead(tablaPasos[paso], 0));
digitalWrite(pinMotor2, bitRead(tablaPasos[paso], 1));
digitalWrite(pinMotor3, bitRead(tablaPasos[paso], 2));
digitalWrite(pinMotor4, bitRead(tablaPasos[paso], 3));
}
