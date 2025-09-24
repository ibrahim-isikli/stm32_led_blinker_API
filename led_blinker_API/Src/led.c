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


LED_state_t LED_on(LED_handle *h)
{
	if(!h)
		return LED_ERR_NULL; // different method of null check

	HAL_GPIO_WritePin(h->port, h->pin, GPIO_PIN_SET);

	return LED_OK;
}

LED_state_t LED_off(LED_handle *h)
{
	if(!h)
		return LED_ERR_NULL;

	HAL_GPIO_WritePin(h->port, h->pin, GPIO_PIN_RESET);

	return LED_OK;
}

LED_state_t LED_toggle(LED_handle *h)
{
	if(!h)
		return LED_ERR_NULL;

	HAL_GPIO_TogglePin(h->port, h->pin);
	return LED_OK;
}

LED_state_t LED_blink_start(LED_handle *h, uint32_t period_ms)
{
	if(!h || period_ms == 0u)
		return LED_ERR;

	h->period_ms = period_ms;
	h->last_ms = HAL_GetTick();
	h->enabled = SET;

	return LED_OK;
}

LED_state_t LED_blink_stop(LED_handle *h)
{
	if(!h)
		return LED_ERR_NULL;

	h->enabled = RESET;
	h->period_ms = 0u;

	return LED_OK;
}

LED_state_t LED_tick(LED_handle *h)
{
	if(!h || !h->enabled || h->period_ms == 0)
		return LED_ERR;

	uint32_t now = HAL_GetTick();

	if(now - h->last_ms >= h->period_ms)
	{
		LED_toggle(h);
		h->last_ms = now;
	}
	return LED_OK;
}

