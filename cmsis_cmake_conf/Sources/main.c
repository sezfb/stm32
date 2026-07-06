#include <stdint.h>
#include "stm32f446xx.h"

#include "rcc.h"
#include "gpio.h"
#include "tim6_7.h"

int main(void)
{
    RCC_GPIOA_Enable();
    RCC_TIM6_Enable();

    GPIO_Init();

    TIM6_Init();
    TIM6_Start();

    while (1)
    {
        if (TIM6_UpdateFlag())
        {
            TIM6_ClearUpdateFlag();

            GPIOA->ODR ^= (1U << 5);
        }
    }
}