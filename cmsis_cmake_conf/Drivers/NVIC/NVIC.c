// Периферия
//    │
//    ├── выставляет флаг (SR), автомат при переполнении
//    │
//    ├── если в DIER бит UIE = 1, TIM6->DIER |= (1U << 0);
//    │
//    └────────► NVIC -   D:\STM_WORKSPACE\stm32_GIT\cmsis_cmake_conf\CMSIS\Device\ST\STM32F4xx\Include\stm32f446xx.h
//                  │     TIM6_DAC_IRQn               = 54,     /*!< TIM6 global and DAC1&2 underrun error  interruptss
//                  |                   
//                  ├── если ISER разрешил IRQ, каждый ISER — это 32 бита, каждый бит соответствует одному IRQ - 54 / 32 = 1 | 54 % 32 = 22 бит, NVIC->ISER[1] |= (1U << 22);
//                  │
//                  └────────► TIM6_DAC_IRQHandler()

#include "NVIC.h"                      
#include "stm32f446xx.h"
           
void NVIC_TIM6_Enable(void)
{
    // IRQ = 54
    // ISER1, бит 22
    NVIC->ISER[1] |= (1U << 22);
}   
