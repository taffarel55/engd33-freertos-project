/*
 * controller.h
 *
 *  Created on: 7 de jul de 2023
 *      Author: dbserver
 */

#ifndef INC_CONTROLLER_H_
#define INC_CONTROLLER_H_

#include <stdio.h>
#include <stdlib.h>
#include "cmsis_os.h"
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "math_util.h"


#define SYNC_DATA_MAX_ITEMS 5
#define QUEUE_SIZE 10

typedef struct {
    double lat; // Latitude em graus decimais
    double lon; // Longitude em graus decimais
} st_gpsPoint;


#define SYNC_TIME_MS 250

BaseType_t vInitController(void);


#endif /* INC_CONTROLLER_H_ */
