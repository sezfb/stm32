#ifndef TIM6_7_H
#define TIM6_7_H

#include <stdint.h>

void TIM6_Init(void);
void TIM6_Start(void);

uint8_t TIM6_UpdateFlag(void);

void TIM6_ClearUpdateFlag(void);

#endif