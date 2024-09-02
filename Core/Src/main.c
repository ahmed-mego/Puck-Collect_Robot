/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
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
/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
#define R1_PWM TIM_CHANNEL_1
#define L1_PWM TIM_CHANNEL_2 // timer1
#define R2_PWM TIM_CHANNEL_3
#define L2_PWM TIM_CHANNEL_4
#define uart_buffer_size 80
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
TIM_HandleTypeDef htim1;
TIM_HandleTypeDef htim2;
TIM_HandleTypeDef htim3;
UART_HandleTypeDef huart1;

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_TIM1_Init(void);
static void MX_TIM2_Init(void);
static void MX_USART1_UART_Init(void);
static void MX_TIM3_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
volatile uint8_t uart_buffer[uart_buffer_size] = {};

uint8_t buffer_counter = 0;
uint16_t  stepDelay = 500;
uint8_t CW = 1, CCW = 0;

void microDelay (uint16_t delay)
{
	__HAL_TIM_SET_COUNTER(&htim3, 10);
	while (__HAL_TIM_GET_COUNTER(&htim3) < delay);
}

void stepperMotor_1 (int steps, uint8_t direction, uint16_t delay)
{
	if (direction == 0)
		HAL_GPIO_WritePin(GPIOA, DIR1_Pin, GPIO_PIN_SET);
	else if (direction == 1)
		HAL_GPIO_WritePin(GPIOA, DIR1_Pin, GPIO_PIN_RESET);
	for (int i = 0; i < steps; i++)
	{
		HAL_GPIO_WritePin(GPIOA, STEP1_Pin, GPIO_PIN_SET);
		microDelay(delay);
		HAL_GPIO_WritePin(GPIOA, STEP1_Pin, GPIO_PIN_RESET);
		microDelay(delay);
	}
}

void stepperMotor_2 (int steps, uint8_t direction, uint16_t delay)
{
	if (direction == 0)
		HAL_GPIO_WritePin(GPIOA, DIR2_Pin, GPIO_PIN_SET);
	else if(direction == 1)
		HAL_GPIO_WritePin(GPIOA, DIR2_Pin, GPIO_PIN_RESET);
	for (int i = 0; i < steps; i++)
	{
		HAL_GPIO_WritePin(GPIOA, STEP2_Pin, GPIO_PIN_SET);
		microDelay(delay);
		HAL_GPIO_WritePin(GPIOA, STEP2_Pin, GPIO_PIN_RESET);
		microDelay(delay);
	}
}

void dcMotor_1 (uint8_t direction, uint16_t PWM)
{
	HAL_GPIO_WritePin(GPIOA, L1_EN_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOA, R1_EN_Pin, GPIO_PIN_SET);
	if (direction == 0)
	{

		__HAL_TIM_SET_COMPARE(&htim2, R1_PWM, 65535);
		__HAL_TIM_SET_COMPARE(&htim1, L1_PWM, PWM);
	}
	else if (direction == 1)
	{
		__HAL_TIM_SET_COMPARE(&htim1, L1_PWM, 65535);
		__HAL_TIM_SET_COMPARE(&htim2, R1_PWM, PWM);
	}
}

void dcMotor_2 (uint8_t direction, uint16_t PWM)

{
	HAL_GPIO_WritePin(GPIOA, L2_EN_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOA, R2_EN_Pin, GPIO_PIN_SET);
	if (direction == 0)
	{
		__HAL_TIM_SET_COMPARE(&htim2, R2_PWM, 65535);
		__HAL_TIM_SET_COMPARE(&htim2, L2_PWM, PWM);
	}
	else if (direction == 1)
	{
		__HAL_TIM_SET_COMPARE(&htim2, L2_PWM, 65535);
		__HAL_TIM_SET_COMPARE(&htim2, R2_PWM, PWM);
	}
}

uint8_t ArrayChecksum(uint8_t* Arr,uint8_t Arr_size)
{
    uint16_t ChecksumCode = 0;
    for(uint8_t ArrItem = 0;ArrItem<Arr_size;ArrItem++)
    {
        ChecksumCode +=Arr[ArrItem];
    }

    ChecksumCode = ~ChecksumCode;
    ChecksumCode = ChecksumCode % 255;
    return (uint8_t)ChecksumCode;
}

uint8_t it_char = 0;
void HAL_UART_RxCpltCallback(UART_HandleTypeDef* huart)
{

    if (huart->Instance == USART1)
    {

		 HAL_UART_Receive_IT(&huart1,(uint8_t*)&it_char, 1);
		 uart_buffer[buffer_counter] = it_char;
		 HAL_UART_Transmit(&huart1, (uint8_t*)&uart_buffer[buffer_counter], 1, 100);
		 if(buffer_counter < uart_buffer_size-1)
		 buffer_counter++;
		 else
		 {
			 buffer_counter= 0;
		 }
    }
//	 buffer_counter= (buffer_counter+1) % 10;
}

uint8_t Decode_Pi_CMD(uint8_t buffer[], uint8_t size)
{
	if (buffer[0] != 0xAA)
	{

		return 1;
	}

	if (buffer[size-1] != 0x55)
	{

		return 1;
	}

	if (ArrayChecksum(buffer, size-1))
	{

		return 2;
	}

	if (buffer[1] == 0)
	{
		uint8_t dir = buffer[3];
		uint16_t step = (((uint16_t)buffer[4])<<8) | buffer[5];
		stepperMotor_1(step, dir, stepDelay);
	}

	if (buffer[1] == 1)
	{
		uint8_t dir = buffer[3];
		uint16_t step  = (((uint16_t)buffer[4]) << 8) | buffer[5];
		stepperMotor_2(step, dir, stepDelay);
	}

	if (buffer[1] == 2)
	{
		uint8_t dir = buffer[3];
		uint16_t pwm  = (((uint16_t)buffer[4]) << 8) | buffer[5];
		dcMotor_1(dir, pwm);
	}

	if (buffer[1] == 3)
	{
		uint8_t dir = buffer[2];
		uint16_t pwm  = (((uint16_t)buffer[4]) << 8) | buffer[5];
		dcMotor_2(dir, pwm);
	}

	return 0;
}


/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{

  /* USER CODE BEGIN 1 */
  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_TIM1_Init();
  MX_TIM2_Init();
  MX_USART1_UART_Init();
  MX_TIM3_Init();
  /* USER CODE BEGIN 2 */
  HAL_TIM_Base_Start(&htim1);
  HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_2);
  HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_1);
  HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_3);
  HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_4);

  HAL_GPIO_WritePin(GPIOA, DIR1_Pin, GPIO_PIN_RESET);
  HAL_GPIO_WritePin(GPIOA, STEP1_Pin, GPIO_PIN_RESET);
  HAL_GPIO_WritePin(GPIOA, DIR2_Pin, GPIO_PIN_RESET);
  HAL_GPIO_WritePin(GPIOA, STEP2_Pin, GPIO_PIN_RESET);

  HAL_UART_Receive_IT(&huart1, (uint8_t*)&it_char, 1);
  HAL_Delay(5000);
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  int8_t CommandPos = 0 ;
  while (1)
  {
//	  HAL_GPIO_WritePin(GPIOA,STEP1_Pin, 0);
//	  HAL_GPIO_WritePin(GPIOA,DIR1_Pin, 0);
//
//	  stepperMotor_1(500, CCW, stepDelay);
//	  HAL_Delay(1000);
//	  stepperMotor_1(500, CW, stepDelay);
//	  HAL_Delay(1000);
	  HAL_NVIC_DisableIRQ (USART1_IRQn);
	  uint8_t shadow_buffer[uart_buffer_size];
	  int i =0;
	  for(i = CommandPos; i < uart_buffer_size; i++)
	  {
		  if(uart_buffer[i] == 0xAA && i+7<uart_buffer_size)
		  {
			  if(uart_buffer[i+7] == 0x55 )
			  {
				  CommandPos = i;
				  break;
			  }
		  }
	  }
	  if(i == uart_buffer_size)

	  {
		  CommandPos= 0;
		  HAL_NVIC_EnableIRQ(USART1_IRQn);
		  continue;
	  }
	  int j = 0;
	  for(i = CommandPos; i < 8+CommandPos; i++)
	  {
		  shadow_buffer[j] = uart_buffer[i];
		  uart_buffer[i] = 0;
		  j++;
	  }
	  //uart_buffer[CommandPos] = 0xFA;


	  HAL_NVIC_EnableIRQ(USART1_IRQn);

	  uint8_t state = Decode_Pi_CMD(shadow_buffer, 8);

	  HAL_UART_Transmit(&huart1, &state, 1, 100);
	  HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_13);
//	  HAL_Delay(100);
//
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage
  */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE2);

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
  RCC_OscInitStruct.PLL.PLLM = 8;
  RCC_OscInitStruct.PLL.PLLN = 72;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 4;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief TIM1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM1_Init(void)
{

  /* USER CODE BEGIN TIM1_Init 0 */

  /* USER CODE END TIM1_Init 0 */

  TIM_ClockConfigTypeDef sClockSourceConfig = {0};
  TIM_MasterConfigTypeDef sMasterConfig = {0};
  TIM_OC_InitTypeDef sConfigOC = {0};
  TIM_BreakDeadTimeConfigTypeDef sBreakDeadTimeConfig = {0};

  /* USER CODE BEGIN TIM1_Init 1 */

  /* USER CODE END TIM1_Init 1 */
  htim1.Instance = TIM1;
  htim1.Init.Prescaler = 22;
  htim1.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim1.Init.Period = 65535;
  htim1.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim1.Init.RepetitionCounter = 0;
  htim1.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&htim1) != HAL_OK)
  {
    Error_Handler();
  }
  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  if (HAL_TIM_ConfigClockSource(&htim1, &sClockSourceConfig) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_TIM_PWM_Init(&htim1) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim1, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sConfigOC.OCMode = TIM_OCMODE_PWM1;
  sConfigOC.Pulse = 0;
  sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
  sConfigOC.OCNPolarity = TIM_OCNPOLARITY_HIGH;
  sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;
  sConfigOC.OCIdleState = TIM_OCIDLESTATE_RESET;
  sConfigOC.OCNIdleState = TIM_OCNIDLESTATE_RESET;
  if (HAL_TIM_PWM_ConfigChannel(&htim1, &sConfigOC, TIM_CHANNEL_2) != HAL_OK)
  {
    Error_Handler();
  }
  sBreakDeadTimeConfig.OffStateRunMode = TIM_OSSR_DISABLE;
  sBreakDeadTimeConfig.OffStateIDLEMode = TIM_OSSI_DISABLE;
  sBreakDeadTimeConfig.LockLevel = TIM_LOCKLEVEL_OFF;
  sBreakDeadTimeConfig.DeadTime = 0;
  sBreakDeadTimeConfig.BreakState = TIM_BREAK_DISABLE;
  sBreakDeadTimeConfig.BreakPolarity = TIM_BREAKPOLARITY_HIGH;
  sBreakDeadTimeConfig.AutomaticOutput = TIM_AUTOMATICOUTPUT_DISABLE;
  if (HAL_TIMEx_ConfigBreakDeadTime(&htim1, &sBreakDeadTimeConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM1_Init 2 */

  /* USER CODE END TIM1_Init 2 */
  HAL_TIM_MspPostInit(&htim1);

}

/**
  * @brief TIM2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM2_Init(void)
{

  /* USER CODE BEGIN TIM2_Init 0 */

  /* USER CODE END TIM2_Init 0 */

  TIM_ClockConfigTypeDef sClockSourceConfig = {0};
  TIM_MasterConfigTypeDef sMasterConfig = {0};
  TIM_OC_InitTypeDef sConfigOC = {0};

  /* USER CODE BEGIN TIM2_Init 1 */

  /* USER CODE END TIM2_Init 1 */
  htim2.Instance = TIM2;
  htim2.Init.Prescaler = 22;
  htim2.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim2.Init.Period = 65535 ;
  htim2.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim2.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&htim2) != HAL_OK)
  {
    Error_Handler();
  }
  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  if (HAL_TIM_ConfigClockSource(&htim2, &sClockSourceConfig) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_TIM_PWM_Init(&htim2) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim2, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sConfigOC.OCMode = TIM_OCMODE_PWM1;
  sConfigOC.Pulse = 0;
  sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
  sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;
  if (HAL_TIM_PWM_ConfigChannel(&htim2, &sConfigOC, TIM_CHANNEL_1) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_TIM_PWM_ConfigChannel(&htim2, &sConfigOC, TIM_CHANNEL_3) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_TIM_PWM_ConfigChannel(&htim2, &sConfigOC, TIM_CHANNEL_4) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM2_Init 2 */

  /* USER CODE END TIM2_Init 2 */
  HAL_TIM_MspPostInit(&htim2);

}

/**
  * @brief TIM3 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM3_Init(void)
{

  /* USER CODE BEGIN TIM3_Init 0 */

  /* USER CODE END TIM3_Init 0 */

  TIM_ClockConfigTypeDef sClockSourceConfig = {0};
  TIM_MasterConfigTypeDef sMasterConfig = {0};

  /* USER CODE BEGIN TIM3_Init 1 */

  /* USER CODE END TIM3_Init 1 */
  htim3.Instance = TIM3;
  htim3.Init.Prescaler = 72;
  htim3.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim3.Init.Period = 65535;
  htim3.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim3.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&htim3) != HAL_OK)
  {
    Error_Handler();
  }
  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  if (HAL_TIM_ConfigClockSource(&htim3, &sClockSourceConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim3, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM3_Init 2 */
  HAL_TIM_Base_Start(&htim3);

  /* USER CODE END TIM3_Init 2 */

}

/**
  * @brief USART1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_USART1_UART_Init(void)
{

  /* USER CODE BEGIN USART1_Init 0 */

  /* USER CODE END USART1_Init 0 */

  /* USER CODE BEGIN USART1_Init 1 */

  /* USER CODE END USART1_Init 1 */
  huart1.Instance = USART1;
  huart1.Init.BaudRate = 9600;
  huart1.Init.WordLength = UART_WORDLENGTH_8B;
  huart1.Init.StopBits = UART_STOPBITS_1;
  huart1.Init.Parity = UART_PARITY_NONE;
  huart1.Init.Mode = UART_MODE_TX_RX;
  huart1.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart1.Init.OverSampling = UART_OVERSAMPLING_16;
  if (HAL_UART_Init(&huart1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART1_Init 2 */

  /* USER CODE END USART1_Init 2 */

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};
/* USER CODE BEGIN MX_GPIO_Init_1 */
/* USER CODE END MX_GPIO_Init_1 */

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOH_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_13|R2_EN_Pin|L2_EN_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, DIR1_Pin|DIR2_Pin|STEP1_Pin|STEP2_Pin
                          |R1_EN_Pin|L1_EN_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pins : PC13 L2_EN_Pin */
  GPIO_InitStruct.Pin = GPIO_PIN_13|L2_EN_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /*Configure GPIO pins : DIR1_Pin DIR2_Pin STEP1_Pin STEP2_Pin */
  GPIO_InitStruct.Pin = DIR1_Pin|DIR2_Pin|STEP1_Pin|STEP2_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_PULLDOWN;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : R1_EN_Pin L1_EN_Pin */
  GPIO_InitStruct.Pin = R1_EN_Pin|L1_EN_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pin : R2_EN_Pin */
  GPIO_InitStruct.Pin = R2_EN_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_PULLDOWN;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(R2_EN_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pins : PB1 PB15 */
  GPIO_InitStruct.Pin = GPIO_PIN_1|GPIO_PIN_15;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_RISING;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

/* USER CODE BEGIN MX_GPIO_Init_2 */
/* USER CODE END MX_GPIO_Init_2 */
}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
