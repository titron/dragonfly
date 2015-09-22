/**
  ******************************************************************************
  * @file    Project/STM32F10x_StdPeriph_Template/stm32f10x_conf.h 
  * @author  MCD Application Team
  * @version V3.5.0
  * @date    08-April-2011
  * @brief   Library configuration file.
  ******************************************************************************
  * @attention
  *
  * THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
  * WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE
  * TIME. AS A RESULT, STMICROELECTRONICS SHALL NOT BE HELD LIABLE FOR ANY
  * DIRECT, INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING
  * FROM THE CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE
  * CODING INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
  *
  * <h2><center>&copy; COPYRIGHT 2011 STMicroelectronics</center></h2>
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __STM32F10x_CONF_H
#define __STM32F10x_CONF_H

/* Includes ------------------------------------------------------------------*/
/* Uncomment/Comment the line below to enable/disable peripheral header file inclusion */
#include "stm32f10x_adc.h"
#include "stm32f10x_bkp.h"
#include "stm32f10x_can.h"
#include "stm32f10x_cec.h"
#include "stm32f10x_crc.h"
#include "stm32f10x_dac.h"
#include "stm32f10x_dbgmcu.h"
#include "stm32f10x_dma.h"
#include "stm32f10x_exti.h"
#include "stm32f10x_flash.h"
#include "stm32f10x_fsmc.h"
#include "stm32f10x_gpio.h"
#include "stm32f10x_i2c.h"
#include "stm32f10x_iwdg.h"
#include "stm32f10x_pwr.h"
#include "stm32f10x_rcc.h"
#include "stm32f10x_rtc.h"
#include "stm32f10x_sdio.h"
#include "stm32f10x_spi.h"
//#include "stm32f10x_systick.h"//added by titron
#include "stm32f10x_tim.h"
#include "stm32f10x_usart.h"
#include "stm32f10x_wwdg.h"
#include "misc.h" /* High level functions for NVIC and SysTick (add-on to CMSIS functions) */

/* Exported types ------------------------------------------------------------*/
#if 0 //comment by titron
/* Exported constants --------------------------------------------------------*/
/* Comment the line below to compile the library in release mode */
#define DEBUG

/* Comment the line below to disable the specific peripheral inclusion */
/************************************* ADC ************************************/
//#define _ADC
//#define _ADC1
//#define _ADC2

/************************************* CAN ************************************/
//#define _CAN

/************************************* DMA ************************************/
//#define _DMA
//#define _DMA_Channel1
//#define _DMA_Channel2
//#define _DMA_Channel3
//#define _DMA_Channel4
//#define _DMA_Channel5
//#define _DMA_Channel6
//#define _DMA_Channel7

/************************************* EXTI ***********************************/
#define _EXTI

/************************************* GPIO ***********************************/
#define _GPIO
//#define _GPIOA
#define _GPIOB
//#define _GPIOC
//#define _GPIOD
//#define _GPIOE
#define _AFIO

/************************************* I2C ************************************/
//#define _I2C
//#define _I2C1
//#define _I2C2

/************************************* IWDG ***********************************/
//#define _IWDG

/************************************* NVIC ***********************************/
#define _NVIC
#define _SCB

/************************************* BKP ************************************/
//#define _BKP

/************************************* PWR ************************************/
//#define _PWR

/************************************* RCC ************************************/
#define _RCC

/************************************* RTC ************************************/
//#define _RTC

/************************************* SPI ************************************/
//#define _SPI
//#define _SPI1
//#define _SPI2

/************************************* SysTick ********************************/
#define _SysTick

/************************************* TIM ************************************/
//#define _TIM
#define _TIM2
#define _TIM3
//#define _TIM4

/************************************* USART **********************************/
//#define _USART
//#define _USART1
//#define _USART2
//#define _USART3

/************************************* WWDG ***********************************/
//#define _WWDG

/* In the following line adjust the value of External High Speed oscillator (HSE)
   used in your application */
#define HSE_Value    ((u32)16000000)   /* Value of the External oscillator in Hz*/
/* Exported constants --------------------------------------------------------*/
/* Uncomment the line below to expanse the "assert_param" macro in the 
   Standard Peripheral Library drivers code */
/* #define USE_FULL_ASSERT    1 */
#endif

/* Exported macro ------------------------------------------------------------*/
#ifdef  USE_FULL_ASSERT

/**
  * @brief  The assert_param macro is used for function's parameters check.
  * @param  expr: If expr is false, it calls assert_failed function which reports 
  *         the name of the source file and the source line number of the call 
  *         that failed. If expr is true, it returns no value.
  * @retval None
  */
  #define assert_param(expr) ((expr) ? (void)0 : assert_failed((uint8_t *)__FILE__, __LINE__))
/* Exported functions ------------------------------------------------------- */
  void assert_failed(uint8_t* file, uint32_t line);
#else
  #define assert_param(expr) ((void)0)
#endif /* USE_FULL_ASSERT */

#endif /* __STM32F10x_CONF_H */

/******************* (C) COPYRIGHT 2011 STMicroelectronics *****END OF FILE****/
