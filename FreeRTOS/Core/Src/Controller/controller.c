/*
 * controller.c
 *
 *  Created on: 7 de jul de 2023
 *      Author: dbserver
 */

#include "controller.h"

QueueHandle_t gpsQueue;

void vTaskDataSync(void *pvParameters);
void vTaskGetSetPointFromNetwork(void *pvParameters);
void vTaskSimulatePointsFromNetwork(void *pvParameters);

BaseType_t vInitController(void) {
	gpsQueue = xQueueCreate(QUEUE_SIZE, sizeof(st_gpsPoint));

	if (gpsQueue == NULL) {
		printf("Falha ao criar a fila\n");
	    return pdFALSE;
	}

	xTaskCreate(vTaskDataSync,"Data Sync Task", configMINIMAL_STACK_SIZE, NULL, 1, NULL);
	xTaskCreate(vTaskGetSetPointFromNetwork,"Set Point Task", 256, NULL, 1, NULL);
	xTaskCreate(vTaskSimulatePointsFromNetwork,"Generate data Task", 256, NULL, 1, NULL);

	return pdTRUE;
}

void vTaskDataSync(void *pvParameters) {
	while(1) {
		st_gpsPoint gpsPoint_st = {
				.lat = randomInt(0,255) / 360.0,
				.lon = randomInt(0,255) / 360.0,
		};

		int compassOrietantion = randomInt(0,360);

		printf("Recebendo dados dos dois sensores | Compass = %d deg | Lat = %f | Lon = %f \n",
				compassOrietantion, gpsPoint_st.lat, gpsPoint_st.lon);

		vTaskDelay(pdMS_TO_TICKS(1000));
	}
}

void vTaskGetSetPointFromNetwork(void *pvParameters) {

	st_gpsPoint gpsReceivedFromNetwork_st = {
		.lat = -1,
		.lon = -1
	};

	while(1) {
        printf("Get from internet | ");

        if (xQueueReceive(gpsQueue, (void *)&gpsReceivedFromNetwork_st, 0) == pdTRUE) {
            printf("Lat: %f, Lon: %f\n", gpsReceivedFromNetwork_st.lat, gpsReceivedFromNetwork_st.lon);
        } else {
        	printf("Nao tem dados na fila\n");
        }

		vTaskDelay(pdMS_TO_TICKS(3000));
	}
}

void vTaskSimulatePointsFromNetwork(void *pvParameters) {
    st_gpsPoint gpsPointGenerateFromNetwork_st;

    while (1) {
        printf("New value from network\n");

        // Simulação de geração de pontos de GPS a partir da rede
        gpsPointGenerateFromNetwork_st.lat = 0.2;
        gpsPointGenerateFromNetwork_st.lon = 0.3;

        if (xQueueSend(gpsQueue, (void *)&gpsPointGenerateFromNetwork_st, 10) != pdPASS) {
            printf("Fila cheia\n");
        }

        vTaskDelay(pdMS_TO_TICKS(5000));
    }
}






