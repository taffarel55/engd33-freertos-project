/*
 * maincode.c
 *
 *  Created on: Jun 24, 2023
 *      Author: dbserver
 */

#include <stdint.h>
#include <stdio.h>
#include "main.h"
#include "cmsis_os.h"
#include "FreeRTOS.h"
#include "task.h"
#include "ahrs.h"
#include "controller.h"

TaskHandle_t hledTask;

void ledTask(void *arg);

void start_rtos(void) {
	srand(time(NULL));
	xTaskCreate(ledTask,
				"ledTask",
				128,
				NULL,
				1,
				&hledTask);

	//init_AHRS();
	initTest();

	vTaskStartScheduler();

	while(1);
}

void ledTask(void *arg) {
	while(1) {
		HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, 1);
		printf("Led ligada sem a placa\n");
		vTaskDelay(pdMS_TO_TICKS(1000));

		HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, 0);
		printf("Led desligada sem a placa\n");
		vTaskDelay(pdMS_TO_TICKS(1000));
	}
}


