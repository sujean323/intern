/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
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
#include "stdbool.h"
#include <string.h>
#include <stdlib.h>

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */
#define BUFFER_SIZE 16
#define LIGHT_ON "1\t\n"
#define LIGHT_OFF "0\t\n"

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
UART_HandleTypeDef huart3;

/* USER CODE BEGIN PV */


/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_USART3_UART_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
uint8_t bUartReceived1;
uint8_t u8RxCount1;
uint8_t commandBuff[BUFFER_SIZE];
char castCommand[BUFFER_SIZE];
char strCut[5][5];
char d[] = " \r\n";
char *p; //strtok
char *q; //strchr
int i=0;
int colState = GPIO_PIN_RESET;


void lightOnCol1(){
	HAL_GPIO_WritePin(LED1_GPIO_Port, LED1_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(LED2_GPIO_Port, LED2_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(LED3_GPIO_Port, LED3_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(LED4_GPIO_Port, LED4_Pin, GPIO_PIN_SET);
}
void lightOnCol2(){
	HAL_GPIO_WritePin(LED5_GPIO_Port, LED5_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(LED6_GPIO_Port, LED6_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(LED7_GPIO_Port, LED7_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(LED8_GPIO_Port, LED8_Pin, GPIO_PIN_SET);
}
void lightOnCol3(){
	HAL_GPIO_WritePin(LED9_GPIO_Port, LED9_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(LED10_GPIO_Port, LED10_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(LED11_GPIO_Port, LED11_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(LED12_GPIO_Port, LED12_Pin, GPIO_PIN_SET);
}
void lightOnCol4(){
	HAL_GPIO_WritePin(LED13_GPIO_Port, LED13_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(LED14_GPIO_Port, LED14_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(LED15_GPIO_Port, LED15_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(LED16_GPIO_Port, LED16_Pin, GPIO_PIN_SET);
}
void lightOffCol1(){
	HAL_GPIO_WritePin(LED1_GPIO_Port, LED1_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LED2_GPIO_Port, LED2_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LED3_GPIO_Port, LED3_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LED4_GPIO_Port, LED4_Pin, GPIO_PIN_RESET);
}
void lightOffCol2(){
	HAL_GPIO_WritePin(LED5_GPIO_Port, LED5_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LED6_GPIO_Port, LED6_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LED7_GPIO_Port, LED7_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LED8_GPIO_Port, LED8_Pin, GPIO_PIN_RESET);
}
void lightOffCol3(){
	HAL_GPIO_WritePin(LED9_GPIO_Port, LED9_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LED10_GPIO_Port, LED10_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LED11_GPIO_Port, LED11_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LED12_GPIO_Port, LED12_Pin, GPIO_PIN_RESET);
}
void lightOffCol4(){
	HAL_GPIO_WritePin(LED13_GPIO_Port, LED13_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LED14_GPIO_Port, LED14_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LED15_GPIO_Port, LED15_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LED16_GPIO_Port, LED16_Pin, GPIO_PIN_RESET);
}
void getStatus(int pin){
	if(pin==1){
		if(colState == HAL_GPIO_ReadPin(LED1_GPIO_Port, LED1_Pin)){
			HAL_UART_Transmit_IT(&huart3, (uint8_t*)LIGHT_OFF, strlen(LIGHT_OFF));
		}
		else if(colState != HAL_GPIO_ReadPin(LED1_GPIO_Port, LED1_Pin)){
			HAL_UART_Transmit_IT(&huart3, (uint8_t*)LIGHT_ON, strlen(LIGHT_ON));
		}
	}
	if(pin==2){
		if(colState == HAL_GPIO_ReadPin(LED5_GPIO_Port, LED5_Pin)){
			HAL_UART_Transmit_IT(&huart3, (uint8_t*)LIGHT_OFF, strlen(LIGHT_OFF));
		}
		else if(colState != HAL_GPIO_ReadPin(LED5_GPIO_Port, LED5_Pin)){
			HAL_UART_Transmit_IT(&huart3, (uint8_t*)LIGHT_ON, strlen(LIGHT_ON));
		}
	}
	if(pin==3){
		if(colState == HAL_GPIO_ReadPin(LED9_GPIO_Port, LED9_Pin)){
			HAL_UART_Transmit_IT(&huart3, (uint8_t*)LIGHT_OFF, strlen(LIGHT_OFF));
		}
		else if(colState != HAL_GPIO_ReadPin(LED9_GPIO_Port, LED9_Pin)){
			HAL_UART_Transmit_IT(&huart3, (uint8_t*)LIGHT_ON, strlen(LIGHT_ON));
		}
	}
	if(pin==4){
		if(colState == HAL_GPIO_ReadPin(LED13_GPIO_Port, LED13_Pin)){
			HAL_UART_Transmit_IT(&huart3, (uint8_t*)LIGHT_OFF, strlen(LIGHT_OFF));
		}
		else if(colState != HAL_GPIO_ReadPin(LED13_GPIO_Port, LED13_Pin)){
			HAL_UART_Transmit_IT(&huart3, (uint8_t*)LIGHT_ON, strlen(LIGHT_ON));
		}
	}

}
void errMsg(){
	HAL_UART_Transmit_IT(&huart3, (uint8_t*)"Invalid Format\n", strlen("Invalid Format\n"));
}
void cleanBuf(){
	for(int i=0; i<5; i++){
		for(int j=0; j<5; j++)
			strCut[i][j] = '\0';
	}
	memset(commandBuff, '\0', BUFFER_SIZE);
	memset(castCommand, '\0', BUFFER_SIZE);
	i=0;
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
  MX_USART3_UART_Init();
  /* USER CODE BEGIN 2 */

  HAL_UART_Receive_IT(&huart3, commandBuff, BUFFER_SIZE);

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */

  while (1)
  {

    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */


		if(bUartReceived1)
		{

			/*************************/

			/*do something to data*/


			/*************************/


			bUartReceived1 = false;

			HAL_UART_Receive_IT(&huart3, commandBuff, BUFFER_SIZE);

		}

		q = strchr(commandBuff, '\r');

		if(q != NULL){
			for(size_t i=0; i<BUFFER_SIZE; i++) {
				castCommand[i] = (char)commandBuff[i];
			}

			//split
			p = strtok(castCommand, d);
			while(p != NULL && i<5){
				for(int j=0; j<5; j++){
					if(p[j] != '\0') {
						strCut[i][j] = p[j];
					}
					else break;  // Skip remaining characters if the substring ends
				}
				i++;
				p = strtok(NULL, d);
			}
		}


		if(strcmp(strCut[0], "get")==0){ // get
			if(strcmp(strCut[2], "1")==0){
				getStatus(1);
			}
			else if(strcmp(strCut[2], "2")==0){
				getStatus(2);
			}
			else if(strcmp(strCut[2], "3")==0){
				getStatus(3);
			}
			else if(strcmp(strCut[2], "4")==0){
				getStatus(4);
			}
			else{
				errMsg();
			}
			cleanBuf();
		}
		else if(strcmp(strCut[0], "set")==0){ // set
			if(strcmp(strCut[2], "1")==0){
				if(strcmp(strCut[3], "1")==0){
					lightOnCol1();
				}
				else if(strcmp(strCut[3], "0")==0){
					lightOffCol1();
				}
			}
			else if(strcmp(strCut[2], "2")==0){
				if(strcmp(strCut[3], "1")==0){
					lightOnCol2();
				}
				else if(strcmp(strCut[3], "0")==0){
					lightOffCol2();
				}
			}
			else if(strcmp(strCut[2], "3")==0){
				if(strcmp(strCut[3], "1")==0){
					lightOnCol3();
				}
				else if(strcmp(strCut[3], "0")==0){
					lightOffCol3();
				}
			}
			else if(strcmp(strCut[2], "4")==0){
				if(strcmp(strCut[3], "1")==0){
					lightOnCol4();
				}
				else if(strcmp(strCut[3], "0")==0){
					lightOffCol4();
				}
			}
			else{
				errMsg();
			}
			cleanBuf();
		}

  } //end while

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

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief USART3 Initialization Function
  * @param None
  * @retval None
  */
static void MX_USART3_UART_Init(void)
{

  /* USER CODE BEGIN USART3_Init 0 */

  /* USER CODE END USART3_Init 0 */

  /* USER CODE BEGIN USART3_Init 1 */

  /* USER CODE END USART3_Init 1 */
  huart3.Instance = USART3;
  huart3.Init.BaudRate = 115200;
  huart3.Init.WordLength = UART_WORDLENGTH_8B;
  huart3.Init.StopBits = UART_STOPBITS_1;
  huart3.Init.Parity = UART_PARITY_NONE;
  huart3.Init.Mode = UART_MODE_TX_RX;
  huart3.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart3.Init.OverSampling = UART_OVERSAMPLING_16;
  if (HAL_UART_Init(&huart3) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART3_Init 2 */
  __HAL_UART_ENABLE_IT(&huart3,UART_IT_IDLE);
  /* USER CODE END USART3_Init 2 */

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
  __HAL_RCC_GPIOD_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOC, LED13_Pin|LED14_Pin|LED16_Pin|LED6_Pin
                          |LED5_Pin|LED8_Pin|LED7_Pin|LED3_Pin
                          |LED4_Pin|LED1_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, LED15_Pin|LED10_Pin|LED9_Pin|LED12_Pin
                          |LED11_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(LED2_GPIO_Port, LED2_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pins : LED13_Pin LED14_Pin LED16_Pin LED6_Pin
                           LED5_Pin LED8_Pin LED7_Pin LED3_Pin
                           LED4_Pin LED1_Pin */
  GPIO_InitStruct.Pin = LED13_Pin|LED14_Pin|LED16_Pin|LED6_Pin
                          |LED5_Pin|LED8_Pin|LED7_Pin|LED3_Pin
                          |LED4_Pin|LED1_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /*Configure GPIO pins : LED15_Pin LED10_Pin LED9_Pin LED12_Pin
                           LED11_Pin */
  GPIO_InitStruct.Pin = LED15_Pin|LED10_Pin|LED9_Pin|LED12_Pin
                          |LED11_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /*Configure GPIO pin : button1_Pin */
  GPIO_InitStruct.Pin = button1_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(button1_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pin : LED2_Pin */
  GPIO_InitStruct.Pin = LED2_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(LED2_GPIO_Port, &GPIO_InitStruct);

/* USER CODE BEGIN MX_GPIO_Init_2 */
/* USER CODE END MX_GPIO_Init_2 */
}

/* USER CODE BEGIN 4 */
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart){
	HAL_UART_Receive_IT(&huart3, commandBuff, BUFFER_SIZE);
}
void RxHalfCpltCallback(UART_HandleTypeDef *huart){
	HAL_UART_Receive_IT(&huart3, commandBuff, BUFFER_SIZE);
}
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
