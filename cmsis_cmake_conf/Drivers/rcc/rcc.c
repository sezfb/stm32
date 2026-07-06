#include "rcc.h"
#include "stm32f446xx.h"

void RCC_TIM6_Enable(void)
{
    RCC->APB1ENR |= RCC_APB1ENR_TIM6EN;
}

void RCC_GPIOA_Enable(void)
{
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;
}

void RCC_USART2_Enable(void)
{
    RCC->APB1ENR |= RCC_APB1ENR_USART2EN;
}