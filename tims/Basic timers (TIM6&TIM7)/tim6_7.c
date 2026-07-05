#include "tim6_7.h"
#include <stdio.h>

void tim6_init(void)
{   
    // 84,000,000 / (8399 + 1) = 10,000 Hz
    TIM6_PSC = 8399;

    // частота × время = количество тиков
    // 10,000 Hz * 5с = 50,000 тиков
    // 
    TIM6_ARR = 49999; // начало с 0, по этому 49999 + 1


    TIM6_CR1 |= (1 << 7);
    TIM6_CR1 &= ~(1 << 4);
    TIM6_CR1 &= ~(1 << 3);
    TIM6_CR1 &= ~(1 << 2);
    TIM6_CR1 &= ~(1 << 0);

    // TIM6_DIER |= (1 << 8); // DMA, само по себе ничего не дает
    // надо включить NVIC, чтобы CPU реагировал на прерывания от таймера
}

void tim6_ON(void)
{  TIM6_CR1 |= (1 << 0);  }

void tim6_OFF(void)
{  TIM6_CR1 &= ~(1 << 0);   }

void tim6_STATUS(void)
{
    uint32_t status = TIM6_CNT;

    printf("TIM6_CNT = %lu\r\n", (unsigned long)status);
}

