/*
 * ahrs.c
 *
 *  Created on: 6 de jul de 2023
 *      Author: dbserver
 */

#include "ahrs.h"

void init_AHRS(void) {
	xTaskCreate(AHRSTask,
				"AHRSTask",
				128,
				NULL,
				1,
				NULL);
}

void AHRSTask(void *arg) {
	while(1) {
		printf("[AHRS] Tarefa AHRS rodando a cada 1s \n");
		vTaskDelay(pdMS_TO_TICKS(1000));
	}
}

