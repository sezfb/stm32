p. 619 of "stm32f446xx-advanced.pdf"

0x4000 1400 - 0x4000 17FF TIM7
0x4000 1000 - 0x4000 13FF TIM6

Формула для TIMxCLK:

TIMxCLK= | PCLKx     * если APB_Prescaler = 1 |
         | 2 × PCLKx * если APB_Prescaler > 1 |
	​
PCLK1 — частота шины APB1.
PCLK2 — частота шины APB2.

RCC_CFGR → PPRE1 и PPRE2 - регистры для проверки делителя APB1 и APB2

TIM2–TIM7, TIM12–TIM14 используют PCLK1.
TIM1, TIM8, TIM9–TIM11 используют PCLK2.

Prescaler (TIMx_PSC) - задаем PSC для : APB1 / PSC + 1 

TIMx_CNT - хранит текущее значение счетчика

Auto-Reload Register (TIMx_ARR) - определяет максимальное значение счетчика

Update Event (UEV) - возникает при переполнении счетчика :
* обновления PSC;
* обновления ARR (если включен preload);
* установки флага обновления;
* генерации прерывания/триггера (если настроено)

ARPE (TIMx_CR1.ARPE) - пределяет, когда новое значение ARR начнет действовать, сразу или после UEV

* Буферизация PSC - после записи в TIMx_PSC он вступает в силу только после ближайшего Update Event (UEV), это сделано, чтобы не менять частоту счета посреди текущего периода

CEN (TIMx_CR1.CEN) - вкл/выкл таймера