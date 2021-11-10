/* Copyright 2020 Espressif Systems (Shanghai) PTE LTD
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#pragma once

#include <stdint.h>
#include "serial_io.h"
#if defined(NILAI_USES_STM32F4xx)
#    define NILAI_HAL_HEADER          "stm32f4xx_hal.h"
#    define NILAI_UART_DATA_REG       DR
#    define NILAI_UART_IRQ_STATUS_REG SR
#elif defined(NILAI_USES_STM32F7xx)
#    define NILAI_HAL_HEADER          "stm32f7xx_hal.h"
#    define NILAI_UART_DATA_REG       RDR
#    define NILAI_UART_IRQ_STATUS_REG ISR
#elif defined(NILAI_USES_STM32L4xx)
#    define NILAI_HAL_HEADER          "stm32l4xx_hal.h"
#    define NILAI_UART_DATA_REG       RDR
#    define NILAI_UART_IRQ_STATUS_REG ISR
#else
#    define NILAI_HAL_HEADER ""
#    error No STM32 were defined in NilaiTFOConfig!
#endif

typedef struct {
    UART_HandleTypeDef *huart;
    GPIO_TypeDef *port_io0;
    uint16_t pin_num_io0;
    GPIO_TypeDef *port_rst;
    uint16_t pin_num_rst;
} loader_stm32_config_t;

void loader_port_stm32_init(loader_stm32_config_t *config);