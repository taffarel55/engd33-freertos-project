/*
 * controller.h
 *
 *  Created on: 7 de jul de 2023
 *      Author: dbserver
 */

#ifndef INC_CONTROLLER_H_
#define INC_CONTROLLER_H_

#include <stdio.h>
#include "cmsis_os.h"
#include "FreeRTOS.h"
#include "task.h"

void initTest(void);
void taskTest(void *pvParameters);

#endif /* INC_CONTROLLER_H_ */
