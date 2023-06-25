/*
 * maincode.c
 *
 *  Created on: Jun 24, 2023
 *      Author: dbserver
 */

#include <stdint.h>
#include "main.h"
#include "cmsis_os.h"
#include "FreeRTOS.h"
#include "task.h"

TaskHandle_t hledTask;

void ledTask(void *arg);

void start_rtos(void) {
	xTaskCreate(ledTask,
				"ledTask",
				128,
				NULL,
				1,
				&hledTask);

	vTaskStartScheduler();

	while(1);
}

void ledTask(void *arg) {
	while(1) {
		HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, 1);
		HAL_GPIO_WritePin(LD_EXT_GPIO_Port, LD_EXT_Pin, 0);
		vTaskDelay(pdMS_TO_TICKS(100));
		HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, 0);
		HAL_GPIO_WritePin(LD_EXT_GPIO_Port, LD_EXT_Pin, 1);
		vTaskDelay(pdMS_TO_TICKS(100));
	}
}
