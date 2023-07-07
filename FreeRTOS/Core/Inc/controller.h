/*
 * controller.h
 *
 *  Created on: 7 de jul de 2023
 *      Author: dbserver
 */

#ifndef INC_CONTROLLER_H_
#define INC_CONTROLLER_H_

#define MAX_COORDINATE 10
#define MIN_COORDINATE -10

#include <stdio.h>
#include "cmsis_os.h"
#include "FreeRTOS.h"
#include <queue.h>
#include "math_util.h"
#include "task.h"

typedef struct dataPoint {
    int x,
    int y,
} DataPoint;

struct DataPoint point

QueueHandle_t DataPointQueue;
DataPointQueue = xQueueCreate(20 * sizeof(DataPoint), sizeof(DataPoint));


void initTest(void);
void taskTest(void *pvParameters);

#endif /* INC_CONTROLLER_H_ */
