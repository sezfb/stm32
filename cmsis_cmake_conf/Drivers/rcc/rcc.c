#include "rcc.h"
#include "stm32f446xx.h"

void RCC_GPIOA_Enable(void)
{
    // GPIOA Clock Enable
    RCC->AHB1ENR |= (1U << 0);
}

void RCC_TIM6_Enable(void)
{
    // TIM6 Clock Enable
    RCC->APB1ENR |= (1U << 4);
}