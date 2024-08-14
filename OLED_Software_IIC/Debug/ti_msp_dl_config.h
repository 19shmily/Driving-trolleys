/*
 * Copyright (c) 2023, Texas Instruments Incorporated - http://www.ti.com
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/*
 *  ============ ti_msp_dl_config.h =============
 *  Configured MSPM0 DriverLib module declarations
 *
 *  DO NOT EDIT - This file is generated for the MSPM0G350X
 *  by the SysConfig tool.
 */
#ifndef ti_msp_dl_config_h
#define ti_msp_dl_config_h

#define CONFIG_MSPM0G350X

#if defined(__ti_version__) || defined(__TI_COMPILER_VERSION__)
#define SYSCONFIG_WEAK __attribute__((weak))
#elif defined(__IAR_SYSTEMS_ICC__)
#define SYSCONFIG_WEAK __weak
#elif defined(__GNUC__)
#define SYSCONFIG_WEAK __attribute__((weak))
#endif

#include <ti/devices/msp/msp.h>
#include <ti/driverlib/driverlib.h>
#include <ti/driverlib/m0p/dl_core.h>

#ifdef __cplusplus
extern "C" {
#endif

/*
 *  ======== SYSCFG_DL_init ========
 *  Perform all required MSP DL initialization
 *
 *  This function should be called once at a point before any use of
 *  MSP DL.
 */


/* clang-format off */

#define POWER_STARTUP_DELAY                                                (16)


#define CPUCLK_FREQ                                                     32000000



/* Defines for PWM_0 */
#define PWM_0_INST                                                         TIMA0
#define PWM_0_INST_IRQHandler                                   TIMA0_IRQHandler
#define PWM_0_INST_INT_IRQN                                     (TIMA0_INT_IRQn)
#define PWM_0_INST_CLK_FREQ                                               125000
/* GPIO defines for channel 0 */
#define GPIO_PWM_0_C0_PORT                                                 GPIOA
#define GPIO_PWM_0_C0_PIN                                          DL_GPIO_PIN_8
#define GPIO_PWM_0_C0_IOMUX                                      (IOMUX_PINCM19)
#define GPIO_PWM_0_C0_IOMUX_FUNC                     IOMUX_PINCM19_PF_TIMA0_CCP0
#define GPIO_PWM_0_C0_IDX                                    DL_TIMER_CC_0_INDEX
/* GPIO defines for channel 1 */
#define GPIO_PWM_0_C1_PORT                                                 GPIOA
#define GPIO_PWM_0_C1_PIN                                         DL_GPIO_PIN_22
#define GPIO_PWM_0_C1_IOMUX                                      (IOMUX_PINCM47)
#define GPIO_PWM_0_C1_IOMUX_FUNC                     IOMUX_PINCM47_PF_TIMA0_CCP1
#define GPIO_PWM_0_C1_IDX                                    DL_TIMER_CC_1_INDEX



/* Defines for TIMER_1s */
#define TIMER_1s_INST                                                    (TIMG0)
#define TIMER_1s_INST_IRQHandler                                TIMG0_IRQHandler
#define TIMER_1s_INST_INT_IRQN                                  (TIMG0_INT_IRQn)
#define TIMER_1s_INST_LOAD_VALUE                                          (312U)




/* Defines for I2C_MPU6050 */
#define I2C_MPU6050_INST                                                    I2C1
#define I2C_MPU6050_INST_IRQHandler                              I2C1_IRQHandler
#define I2C_MPU6050_INST_INT_IRQN                                  I2C1_INT_IRQn
#define I2C_MPU6050_BUS_SPEED_HZ                                          100000
#define GPIO_I2C_MPU6050_SDA_PORT                                          GPIOB
#define GPIO_I2C_MPU6050_SDA_PIN                                   DL_GPIO_PIN_3
#define GPIO_I2C_MPU6050_IOMUX_SDA                               (IOMUX_PINCM16)
#define GPIO_I2C_MPU6050_IOMUX_SDA_FUNC                IOMUX_PINCM16_PF_I2C1_SDA
#define GPIO_I2C_MPU6050_SCL_PORT                                          GPIOB
#define GPIO_I2C_MPU6050_SCL_PIN                                   DL_GPIO_PIN_2
#define GPIO_I2C_MPU6050_IOMUX_SCL                               (IOMUX_PINCM15)
#define GPIO_I2C_MPU6050_IOMUX_SCL_FUNC                IOMUX_PINCM15_PF_I2C1_SCL


/* Defines for UART_0 */
#define UART_0_INST                                                        UART0
#define UART_0_INST_IRQHandler                                  UART0_IRQHandler
#define UART_0_INST_INT_IRQN                                      UART0_INT_IRQn
#define GPIO_UART_0_RX_PORT                                                GPIOA
#define GPIO_UART_0_TX_PORT                                                GPIOA
#define GPIO_UART_0_RX_PIN                                         DL_GPIO_PIN_1
#define GPIO_UART_0_TX_PIN                                         DL_GPIO_PIN_0
#define GPIO_UART_0_IOMUX_RX                                      (IOMUX_PINCM2)
#define GPIO_UART_0_IOMUX_TX                                      (IOMUX_PINCM1)
#define GPIO_UART_0_IOMUX_RX_FUNC                       IOMUX_PINCM2_PF_UART0_RX
#define GPIO_UART_0_IOMUX_TX_FUNC                       IOMUX_PINCM1_PF_UART0_TX
#define UART_0_BAUD_RATE                                                  (9600)
#define UART_0_IBRD_33_kHZ_9600_BAUD                                         (1)
#define UART_0_FBRD_33_kHZ_9600_BAUD                                         (9)





/* Port definition for Pin Group GPIO_sheng */
#define GPIO_sheng_PORT                                                  (GPIOB)

/* Defines for PIN_0: GPIOB.4 with pinCMx 17 on package pin 52 */
#define GPIO_sheng_PIN_0_PIN                                     (DL_GPIO_PIN_4)
#define GPIO_sheng_PIN_0_IOMUX                                   (IOMUX_PINCM17)
/* Port definition for Pin Group GPIO_guang */
#define GPIO_guang_PORT                                                  (GPIOB)

/* Defines for PIN_1: GPIOB.1 with pinCMx 13 on package pin 48 */
#define GPIO_guang_PIN_1_PIN                                     (DL_GPIO_PIN_1)
#define GPIO_guang_PIN_1_IOMUX                                   (IOMUX_PINCM13)
/* Port definition for Pin Group GPIO_OLED */
#define GPIO_OLED_PORT                                                   (GPIOA)

/* Defines for PIN_SCL: GPIOA.12 with pinCMx 34 on package pin 5 */
#define GPIO_OLED_PIN_SCL_PIN                                   (DL_GPIO_PIN_12)
#define GPIO_OLED_PIN_SCL_IOMUX                                  (IOMUX_PINCM34)
/* Defines for PIN_SDA: GPIOA.13 with pinCMx 35 on package pin 6 */
#define GPIO_OLED_PIN_SDA_PIN                                   (DL_GPIO_PIN_13)
#define GPIO_OLED_PIN_SDA_IOMUX                                  (IOMUX_PINCM35)
/* Port definition for Pin Group GPIO_huidu */
#define GPIO_huidu_PORT                                                  (GPIOA)

/* Defines for PIN_l3: GPIOA.25 with pinCMx 55 on package pin 26 */
#define GPIO_huidu_PIN_l3_PIN                                   (DL_GPIO_PIN_25)
#define GPIO_huidu_PIN_l3_IOMUX                                  (IOMUX_PINCM55)
/* Defines for PIN_l2: GPIOA.27 with pinCMx 60 on package pin 31 */
#define GPIO_huidu_PIN_l2_PIN                                   (DL_GPIO_PIN_27)
#define GPIO_huidu_PIN_l2_IOMUX                                  (IOMUX_PINCM60)
/* Defines for PIN_l1: GPIOA.24 with pinCMx 54 on package pin 25 */
#define GPIO_huidu_PIN_l1_PIN                                   (DL_GPIO_PIN_24)
#define GPIO_huidu_PIN_l1_IOMUX                                  (IOMUX_PINCM54)
/* Defines for PIN_m: GPIOA.17 with pinCMx 39 on package pin 10 */
#define GPIO_huidu_PIN_m_PIN                                    (DL_GPIO_PIN_17)
#define GPIO_huidu_PIN_m_IOMUX                                   (IOMUX_PINCM39)
/* Defines for PIN_r1: GPIOA.31 with pinCMx 6 on package pin 39 */
#define GPIO_huidu_PIN_r1_PIN                                   (DL_GPIO_PIN_31)
#define GPIO_huidu_PIN_r1_IOMUX                                   (IOMUX_PINCM6)
/* Defines for PIN_r2: GPIOA.18 with pinCMx 40 on package pin 11 */
#define GPIO_huidu_PIN_r2_PIN                                   (DL_GPIO_PIN_18)
#define GPIO_huidu_PIN_r2_IOMUX                                  (IOMUX_PINCM40)
/* Defines for PIN_r3: GPIOA.28 with pinCMx 3 on package pin 35 */
#define GPIO_huidu_PIN_r3_PIN                                   (DL_GPIO_PIN_28)
#define GPIO_huidu_PIN_r3_IOMUX                                   (IOMUX_PINCM3)
/* Port definition for Pin Group GPIO_Encoder */
#define GPIO_Encoder_PORT                                                (GPIOB)

/* Defines for L_A: GPIOB.7 with pinCMx 24 on package pin 59 */
// pins affected by this interrupt request:["L_A","R_A"]
#define GPIO_Encoder_INT_IRQN                                   (GPIOB_INT_IRQn)
#define GPIO_Encoder_INT_IIDX                   (DL_INTERRUPT_GROUP1_IIDX_GPIOB)
#define GPIO_Encoder_L_A_IIDX                                (DL_GPIO_IIDX_DIO7)
#define GPIO_Encoder_L_A_PIN                                     (DL_GPIO_PIN_7)
#define GPIO_Encoder_L_A_IOMUX                                   (IOMUX_PINCM24)
/* Defines for R_A: GPIOB.24 with pinCMx 52 on package pin 23 */
#define GPIO_Encoder_R_A_IIDX                               (DL_GPIO_IIDX_DIO24)
#define GPIO_Encoder_R_A_PIN                                    (DL_GPIO_PIN_24)
#define GPIO_Encoder_R_A_IOMUX                                   (IOMUX_PINCM52)
/* Port definition for Pin Group GPIO_BUTTON */
#define GPIO_BUTTON_PORT                                                 (GPIOB)

/* Defines for PIN_MOD1: GPIOB.9 with pinCMx 26 on package pin 61 */
#define GPIO_BUTTON_PIN_MOD1_PIN                                 (DL_GPIO_PIN_9)
#define GPIO_BUTTON_PIN_MOD1_IOMUX                               (IOMUX_PINCM26)
/* Defines for PIN_MOD2: GPIOB.13 with pinCMx 30 on package pin 1 */
#define GPIO_BUTTON_PIN_MOD2_PIN                                (DL_GPIO_PIN_13)
#define GPIO_BUTTON_PIN_MOD2_IOMUX                               (IOMUX_PINCM30)
/* Defines for PIN_MOD3: GPIOB.15 with pinCMx 32 on package pin 3 */
#define GPIO_BUTTON_PIN_MOD3_PIN                                (DL_GPIO_PIN_15)
#define GPIO_BUTTON_PIN_MOD3_IOMUX                               (IOMUX_PINCM32)
/* Defines for PIN_MOD4: GPIOB.16 with pinCMx 33 on package pin 4 */
#define GPIO_BUTTON_PIN_MOD4_PIN                                (DL_GPIO_PIN_16)
#define GPIO_BUTTON_PIN_MOD4_IOMUX                               (IOMUX_PINCM33)
/* Defines for PIN_GO: GPIOB.8 with pinCMx 25 on package pin 60 */
#define GPIO_BUTTON_PIN_GO_PIN                                   (DL_GPIO_PIN_8)
#define GPIO_BUTTON_PIN_GO_IOMUX                                 (IOMUX_PINCM25)
#define GPIOA_EVENT_PUBLISHER_1_CHANNEL                                      (5)

/* clang-format on */

void SYSCFG_DL_init(void);
void SYSCFG_DL_initPower(void);
void SYSCFG_DL_GPIO_init(void);
void SYSCFG_DL_SYSCTL_init(void);
void SYSCFG_DL_PWM_0_init(void);
void SYSCFG_DL_TIMER_1s_init(void);
void SYSCFG_DL_I2C_MPU6050_init(void);
void SYSCFG_DL_UART_0_init(void);


bool SYSCFG_DL_saveConfiguration(void);
bool SYSCFG_DL_restoreConfiguration(void);

#ifdef __cplusplus
}
#endif

#endif /* ti_msp_dl_config_h */
