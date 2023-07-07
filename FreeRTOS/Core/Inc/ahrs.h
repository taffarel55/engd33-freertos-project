/*
 * ahrs.h
 *
 *  Created on: 6 de jul de 2023
 *      Author: dbserver
 */

#ifndef INC_AHRS_H_
#define INC_AHRS_H_

#include <stdio.h>
#include "cmsis_os.h"
#include "FreeRTOS.h"
#include "task.h"

void init_AHRS(void);
void AHRSTask(void *arg);

#endif /* INC_AHRS_H_ */
