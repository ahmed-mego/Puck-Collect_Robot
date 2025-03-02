/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

void HAL_TIM_MspPostInit(TIM_HandleTypeDef *htim);

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define R1_PWM_Pin GPIO_PIN_0
#define R1_PWM_GPIO_Port GPIOA
#define DIR1_Pin GPIO_PIN_1
#define DIR1_GPIO_Port GPIOA
#define DIR2_Pin GPIO_PIN_2
#define DIR2_GPIO_Port GPIOA
#define L2_PWM_Pin GPIO_PIN_3
#define L2_PWM_GPIO_Port GPIOA
#define STEP1_Pin GPIO_PIN_4
#define STEP1_GPIO_Port GPIOA
#define STEP2_Pin GPIO_PIN_5
#define STEP2_GPIO_Port GPIOA
#define R1_EN_Pin GPIO_PIN_6
#define R1_EN_GPIO_Port GPIOA
#define L1_EN_Pin GPIO_PIN_7
#define L1_EN_GPIO_Port GPIOA
#define R2_EN_Pin GPIO_PIN_4
#define R2_EN_GPIO_Port GPIOC
#define L2_EN_Pin GPIO_PIN_5
#define L2_EN_GPIO_Port GPIOC
#define R2_PWM_Pin GPIO_PIN_10
#define R2_PWM_GPIO_Port GPIOB
#define L1_PWM_Pin GPIO_PIN_9
#define L1_PWM_GPIO_Port GPIOA

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
