/*
 * maincode.c
 *
 *  Created on: Jun 24, 2023
 *      Author: dbserver
 */

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include "main.h"
#include "cmsis_os.h"
#include "FreeRTOS.h"
#include "task.h"
#include "ahrs.h"
#include "controller.h"

void ledTask(void *arg);

void start_rtos(void) {

	vInitController();

	xTaskCreate(ledTask, "ledTask", configMINIMAL_STACK_SIZE, NULL, 1, NULL);

	vTaskStartScheduler();

	while(1);
}

void ledTask(void *arg) {
	while(1) {
		HAL_GPIO_TogglePin(LD2_GPIO_Port, LD2_Pin);
		vTaskDelay(pdMS_TO_TICKS(100));
	}
}





