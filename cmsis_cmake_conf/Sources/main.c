#include <stdint.h>
#include "stm32f446xx.h"

#include "rcc.h"
#include "gpio.h"
#include "tim6_7.h"
#include "nvic.h"

void TIM6_DAC_IRQHandler(void)
{
    // Проверить флаг обновления

    if (TIM6->SR & (1U << 0))
    {
        // Сбросить флаг

        TIM6->SR &= ~(1U << 0);

        // Переключить светодиод

        GPIOA->ODR ^= (1U << 5);
    }
}

int main(void)
{
    RCC_GPIOA_Enable();
    RCC_TIM6_Enable();

    GPIO_Init();

    TIM6_Init();

    NVIC_TIM6_Enable();

    TIM6_Start();

    while (1)
    {
    }
}