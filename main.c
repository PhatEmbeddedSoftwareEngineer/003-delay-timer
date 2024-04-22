#include "stm32f10x.h"                  // Device header
#include "timer.h"
int main(void)
{
	SetSystem72Mhz();
	ConfigureTimer3();
	ConfigureTimer2();
	RCC->APB2ENR |= (1<<2);
	GPIOA->CRL = 0x33444444;
	while(1)
	{
		GPIOA->ODR ^= (1<<7);
		delay_timer2(1000);
		GPIOA->ODR ^= (1<<6);
		delay(1000);
		
	}
}
