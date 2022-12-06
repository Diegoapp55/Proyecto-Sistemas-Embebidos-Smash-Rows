/*
 * Copyright (c) 2016 Intel Corporation
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <stdio.h>
#include <zephyr/logging/log.h>
LOG_MODULE_REGISTER(main, CONFIG_LOG_DEFAULT_LEVEL);
/* LOG_MODULE_REGISTER(main, CONFIG_LOG_DEFAULT_LEVEL); */
/* LOG_MODULE_DECLARE(main, CONFIG_LOG_DEFAULT_LEVEL); */

#include "wifi.h"
#include "dhcp.h"
#include "tcp_client.h"



#include <zephyr/kernel.h>
#include <zephyr/drivers/gpio.h>
#include <esp_log.h>

/* 1000 msec = 1 sec */
#define SLEEP_TIME   3

/* Define all coils for the motors */
/*Nodo del blink para depurar*/
#define LED0_NODE DT_ALIAS(led0)
/*Nodos del motor 1*/
#define COIL1_NODE DT_ALIAS(coil1alias)
#define COIL2_NODE DT_ALIAS(coil2alias)
#define COIL3_NODE DT_ALIAS(coil3alias)
#define COIL4_NODE DT_ALIAS(coil4alias)

/*Nodos del motor 2*/
#define COIL5_NODE DT_ALIAS(coil5alias)
#define COIL6_NODE DT_ALIAS(coil6alias)
#define COIL7_NODE DT_ALIAS(coil7alias)
#define COIL8_NODE DT_ALIAS(coil8alias)

/*Nodo del RFID*/
#define RFID_NODE DT_ALIAS(rfid0alias)

#define SUCCESSFUL 0
#define OK 0
#define ERROR 1

/*Llamado a los pines reales del led*/
static const struct gpio_dt_spec led = GPIO_DT_SPEC_GET(LED0_NODE, gpios);

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

/*Llamado al pin real del RFID*/
static const struct gpio_dt_spec rfid0 = GPIO_DT_SPEC_GET(RFID_NODE, gpios);

int leerTabla(int paso[], int posicion){
	int lectura = paso[posicion];
	return lectura;
}

int led_debug_init(void)
{
	if (!device_is_ready(led.port))
		return ERROR;
	if(gpio_pin_configure_dt(&led, GPIO_OUTPUT_ACTIVE) < 0)
    return ERROR;
  return SUCCESSFUL;
}

/* Función que configura los pines como salidas (o entradas) y con valor inicial igual a 0 */
void pins_config_init(void)
{
  int ret;
	ret = gpio_pin_configure_dt(&coil1, GPIO_OUTPUT_LOW);
  printk("%d ", ret);
	ret = gpio_pin_configure_dt(&coil2, GPIO_OUTPUT_LOW);
  printk("%d ", ret);
	ret = gpio_pin_configure_dt(&coil3, GPIO_OUTPUT_LOW);
  printk("%d ", ret);
	ret = gpio_pin_configure_dt(&coil4, GPIO_OUTPUT_LOW);
  printk("%d ", ret);
	ret = gpio_pin_configure_dt(&coil5, GPIO_OUTPUT_LOW);
  printk("%d ", ret);
	ret = gpio_pin_configure_dt(&coil6, GPIO_OUTPUT_LOW);
  printk("%d ", ret);
	ret = gpio_pin_configure_dt(&coil7, GPIO_OUTPUT_LOW);
  printk("%d ", ret);
	ret = gpio_pin_configure_dt(&coil8, GPIO_OUTPUT_LOW);
  printk("%d ", ret);

	/*pin del RFID*/
	ret = gpio_pin_configure_dt(&rfid0, GPIO_INPUT);
	printk("%d ", ret);																						/*Si hay un error puede ser acá, no estoy seguro de esto*/

}



/* A partir de aquí modificamos el void*/


void main(void)
{
	int ret = 0;
	int llego = 0;
	int arduino = 0;
	int vel_motor=1000;
	int count_step = 0;
	int round_step = 4076;


	const int numberSteps = 3200;
	const int tableSteps[4] = {0x8, 0x4, 0x2, 0x1};

	/*Lo del blink para depurar*/
	/* if (!device_is_ready(led.port)) { */
	/* 	return; */
	/* } */

	/* ret = gpio_pin_configure_dt(&led, GPIO_OUTPUT_ACTIVE); */
	/* if (ret < 0) { */
	/* 	return; */
	/* } */


  /* Iniciar led de debug */
  if(led_debug_init() == ERROR)
    return;

  /* Iniciar steppers */
  pins_config_init();

	//Si no se mueve lo suficiente, probar antes con while(1)
	while(1){
		arduino = gpio_pin_get_dt(&rfid0);
		//printk("Lectura=%d, ",arduino);
		if (gpio_pin_get_dt(&rfid0)==1){
		llego = 1;


		while (count_step<numberSteps) { //En vez de 1 poner señal de control que se active con la orden de dispensar y se apague hasta que lo haga
			// ret = gpio_pin_set_dt(&coil1, 1/0)
			// Cambio el valor de los pines coilX
				for (int i = 0; i < 4; i++) {
					switch (tableSteps[i]) {
						case 0x8:
							gpio_pin_set_dt(&coil1, 0);
							gpio_pin_set_dt(&coil2, 1);
							gpio_pin_set_dt(&coil3, 1);
							gpio_pin_set_dt(&coil4, 1);
							break;
						case 0x4:
							gpio_pin_set_dt(&coil1, 1);
							gpio_pin_set_dt(&coil2, 0);
							gpio_pin_set_dt(&coil3, 1);
							gpio_pin_set_dt(&coil4, 1);
							break;
						case 0x2:
							gpio_pin_set_dt(&coil1, 1);
							gpio_pin_set_dt(&coil2, 1);
							gpio_pin_set_dt(&coil3, 0);
							gpio_pin_set_dt(&coil4, 1);
							break;
						case 0x1:
							gpio_pin_set_dt(&coil1, 1);
							gpio_pin_set_dt(&coil2, 1);
							gpio_pin_set_dt(&coil3, 1);
							gpio_pin_set_dt(&coil4, 0);
							break;
					}
					k_msleep(SLEEP_TIME);
					count_step++; //Revisar si esto está bien o es mejor ponerlo fuera del for para que cuente vueltasy no cada paso
				}


			// ret = gpio_pin_toggle_dt(&led);
			// if (ret < 0) {
			// 	return;
			// }
		}

	k_msleep(5*SLEEP_TIME);
	count_step=0;

		while (count_step<numberSteps) { //En vez de 1 poner señal de control que se active con la orden de dispensar y se apague hasta que lo haga
			// ret = gpio_pin_set_dt(&coil1, 1/0)
			// Cambio el valor de los pines coilX
				for (int i = 0; i < 4; i++) {
					switch (tableSteps[i]) {
						case 0x8:
							gpio_pin_set_dt(&coil5, 0);
							gpio_pin_set_dt(&coil6, 1);
							gpio_pin_set_dt(&coil7, 1);
							gpio_pin_set_dt(&coil8, 1);
							break;
						case 0x4:
							gpio_pin_set_dt(&coil5, 1);
							gpio_pin_set_dt(&coil6, 0);
							gpio_pin_set_dt(&coil7, 1);
							gpio_pin_set_dt(&coil8, 1);
							break;
						case 0x2:
							gpio_pin_set_dt(&coil5, 1);
							gpio_pin_set_dt(&coil6, 1);
							gpio_pin_set_dt(&coil7, 0);
							gpio_pin_set_dt(&coil8, 1);
							break;
						case 0x1:
							gpio_pin_set_dt(&coil5, 1);
							gpio_pin_set_dt(&coil6, 1);
							gpio_pin_set_dt(&coil7, 1);
							gpio_pin_set_dt(&coil8, 0);
							break;
					}
					k_msleep(SLEEP_TIME);
					count_step++; //Revisar si esto está bien o es mejor ponerlo fuera del for para que cuente vueltasy no cada paso
				}


			//ret = gpio_pin_toggle_dt(&led);
			//if (ret < 0) {
			//	return;
			//}
		}

		k_msleep(5*SLEEP_TIME);
		count_step=0;

	}
	else{
		llego = 0;

		// return;							/* Esto también ni idea, lo puse porque quedaba lendo*/
	}

	printf("aviso1\n");
	LOG_INF("WiFi demo");

	wifi_connect();

	dhcpv4_startup();

	LOG_INF("Should have DHCPv4 lease at this point.");

	LOG_INF("Start tcp_client_start");

	k_msleep(1000);

	tcp_client_start();

	//printk("Llego=%d\n", llego);
}

}
