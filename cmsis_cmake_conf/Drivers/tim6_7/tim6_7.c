#include "tim6_7.h"
#include "stm32f446xx.h"

void TIM6_Init(void)
{
    // PSC = 16 000 000 / 65536 ≈ 244.14 Гц
    TIM6->PSC = 16000 - 1;

    // ARR = 65536 / 244.14 ≈ 268.4 с = 4 минуты 28 секунд
    TIM6->ARR = 1500 - 1;

    // Обновить регистры
    TIM6->EGR |= (1U << 0);

    // Сбросить флаг
    TIM6->SR &= ~(1U << 0);

    TIM6->DIER |= (1U << 0); // разрешить прерывание по обновлению
}

void TIM6_Start(void)
{
    TIM6->CR1 |= (1U << 0);
}

uint8_t TIM6_UpdateFlag(void)
{
    return (TIM6->SR & (1U << 0));
}

void TIM6_ClearUpdateFlag(void)
{
    TIM6->SR &= ~(1U << 0);
}