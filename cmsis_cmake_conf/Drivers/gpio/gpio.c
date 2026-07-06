#include "gpio.h"
#include "stm32f446xx.h"

void GPIO_Init(void)
{
    // PA5 Output

    GPIOA->MODER &= ~(3U << 10);
    GPIOA->MODER |=  (1U << 10);

    GPIOA->OTYPER &= ~(1U << 5);

    GPIOA->OSPEEDR |= (3U << 10);

    GPIOA->PUPDR &= ~(3U << 10);
}