/**
 *    ||          ____  _ __                           
 * +------+      / __ )(_) /_______________ _____  ___ 
 * | 0xBC |     / __  / / __/ ___/ ___/ __ `/_  / / _ \
 * +------+    / /_/ / / /_/ /__/ /  / /_/ / / /_/  __/
 *  ||  ||    /_____/_/\__/\___/_/   \__,_/ /___/\___/
 *
 * Crazyflie control firmware
 *
 * Copyright (C) 2011-2012 Bitcraze AB
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, in version 3.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 *
 * debug.c - Various debug functions
 */
#include "FreeRTOSConfig.h"
#include "FreeRTOS.h"
#include "task.h"

#include "config.h"
#include "debug.h"
#include "nvicconf.h"
#include "uart.h"

#include "stm32f10x.h"

#include "usec_time.h"

#if (configCHECK_FOR_STACK_OVERFLOW == 1)
void vApplicationStackOverflowHook(xTaskHandle *pxTask, signed portCHAR *pcTaskName)
{
#ifdef __PRINT_INFO//comment by titron
  DEBUG_PRINT("\nStack overflow!\n");
#endif
  while(1);
}
#endif

#ifdef UART_OUTPUT_TRACE_DATA
void debugSendTraceInfo(unsigned int taskNbr)
{
  uint32_t traceData;
  traceData = (taskNbr << 29) | (usecTimestamp() & 0x1FFFFFF);
  uartSendDataDma(sizeof(traceData), (uint8_t*)&traceData);
}

void debugInitTrace(void)
{
}

#else
void debugSendTraceInfo(unsigned int taskNbr)
{
}
#endif
