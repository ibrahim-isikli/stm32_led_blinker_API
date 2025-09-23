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

#if defined(STM32L151xD) || defined(STM32L151xDX) || defined(STM32L152xD) || defined(STM32L152xDX) \
 || defined(STM32L162xD) || defined(STM32L162xDX) || defined(STM32L151xE) || defined(STM32L152xE)   \
 || defined(STM32L162xE)
static void               FLASH_OB_WRPConfigWRP3(uint32_t WRP3, FunctionalState NewState);
#endif /* STM32L151xD || STM32L152xD || STM32L162xD || STM32L151xE || STM32L152xE || STM32L162xE */
#if defined(STM32L151xE) || defined(STM32L152xE) || defined(STM32L162xE) || defined(STM32L151xDX) \
 || defined(STM32L152xDX) || defined(STM32L162xDX)
static void               FLASH_OB_WRPConfigWRP4(uint32_t WRP4, FunctionalState NewState);
#endif /* STM32L151xE || STM32L152xE || STM32L151xDX || ... */


#endif
