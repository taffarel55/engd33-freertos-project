/*
 * controller.c
 *
 *  Created on: 7 de jul de 2023
 *      Author: dbserver
 */

#include "controller.h"

void initTest(void) {
	xTaskCreate(taskTest,
				"taskTest",
				128,
				NULL,
				1,
				NULL);
}

void initSendDataPointTask(void) {
	xTaskCreate(xSendDataPointTask,
				"xSendDataPointTask",
				128,
				NULL,
				1,
				NULL);
}

void taskTest(void *pvParameters) {
	while(1) {
		printf("Geraldo\n");
		vTaskDelay(pdMS_TO_TICKS(5000));
	}
}

void xSendDataPointTask(void *pvParameters) {
	while (1) {
		point.x = randomInt(MIN_COORDINATE, MAX_COORDINATE);
		point.y = randomInt(MIN_COORDINATE, MAX_COORDINATE);
		xQueueSend(DataPointQueue, point, portMAX_DELAY)

		vTaskDelay(pdMS_TO_TICKS(1000));
	}
	
}



