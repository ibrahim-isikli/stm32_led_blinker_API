#include "led.h"

LED_state_t LED_init(LED_handle *h, GPIO_TypeDef *port, uint16_t pin)
{
	if((h == NULL) || (port == NULL)) 		// defensive programming, null check
		return LED_ERR;

	h->port 		= port;					// assign default values
	h->pin			= pin;
	h->period_ms 	= 0u;
	h->last_ms		= 0u;
	h->enabled 		= 0u;

	HAL_GPIO_WritePin(h->port, h->pin, GPIO_PIN_RESET);

	return LED_OK;

}
