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

void taskTest(void *pvParameters) {
	while(1) {
		printf("Geraldo\n");
		vTaskDelay(pdMS_TO_TICKS(5000));
	}
}



