#ifndef LED_H
#define LED_H

#ifdef __cplusplus
extern "C" {
#endif


#if defined(STM32L100xC) || defined(STM32L151xC) || defined(STM32L152xC) || defined(STM32L162xC)    \
 || defined(STM32L151xCA) || defined(STM32L151xD) || defined(STM32L151xDX) || defined(STM32L152xCA) \
 || defined(STM32L152xD) || defined(STM32L152xDX) || defined(STM32L162xCA) || defined(STM32L162xD)  \
 || defined(STM32L162xDX) || defined(STM32L151xE) || defined(STM32L152xE) || defined(STM32L162xE)
#include "stm32l1xx_hal.h"
#endif

typedef enum
{
	LED_OK = (uint8_t)0,
	LED_ERR,
}LED_state_t;


typedef struct
{
	GPIO_TypeDef *port;
	uint16_t pin;
	uint32_t period_ms;
	uint32_t last_ms;
	uint8_t enabled;
}LED_handle;

LED_state_t LED_init(LED_handle *h, GPIO_TypeDef *port, uint16_t pin);




#endif
