/* ###################################################################
**     This component module is generated by Processor Expert. Do not modify it.
**     Filename    : PTC.h
**     Project     : Mini Project
**     Processor   : MK64FN1M0VLL12
**     Component   : Init_GPIO
**     Version     : Component 01.006, Driver 01.06, CPU db: 3.00.000
**     Repository  : Kinetis
**     Compiler    : GNU C Compiler
**     Date/Time   : 2022-11-22, 18:25, # CodeGen: 5
**     Abstract    :
**          This file implements the GPIO (PTC) module initialization
**          according to the Peripheral Initialization settings, and
**          defines interrupt service routines prototypes.
**     Settings    :
**          Component name                                 : PTC
**          Device                                         : PTC
**          Settings                                       : 
**            Clock gate                                   : <Automatic>
**            Pin 0                                        : Initialize
**              Pin direction                              : Input
**              Output value                               : 0
**              Open drain                                 : <Automatic>
**              Pull resistor                              : <Automatic>
**              Pull selection                             : <Automatic>
**              Slew rate                                  : <Automatic>
**              Drive strength                             : <Automatic>
**              Interrupt/DMA request                      : Interrupt on either edge
**              Passive filter                             : <Automatic>
**              Lock                                       : <Automatic>
**            Pin 1                                        : Initialize
**              Pin direction                              : Input
**              Output value                               : 0
**              Open drain                                 : <Automatic>
**              Pull resistor                              : <Automatic>
**              Pull selection                             : <Automatic>
**              Slew rate                                  : <Automatic>
**              Drive strength                             : <Automatic>
**              Interrupt/DMA request                      : Interrupt on either edge
**              Passive filter                             : <Automatic>
**              Lock                                       : <Automatic>
**            Pin 2                                        : Initialize
**              Pin direction                              : Input
**              Output value                               : 0
**              Open drain                                 : <Automatic>
**              Pull resistor                              : <Automatic>
**              Pull selection                             : <Automatic>
**              Slew rate                                  : <Automatic>
**              Drive strength                             : <Automatic>
**              Interrupt/DMA request                      : Interrupt on either edge
**              Passive filter                             : <Automatic>
**              Lock                                       : <Automatic>
**            Pin 3                                        : Initialize
**              Pin direction                              : Input
**              Output value                               : 0
**              Open drain                                 : <Automatic>
**              Pull resistor                              : <Automatic>
**              Pull selection                             : <Automatic>
**              Slew rate                                  : <Automatic>
**              Drive strength                             : <Automatic>
**              Interrupt/DMA request                      : Interrupt on either edge
**              Passive filter                             : <Automatic>
**              Lock                                       : <Automatic>
**            Pin 4                                        : Do not initialize
**            Pin 5                                        : Do not initialize
**            Pin 6                                        : Do not initialize
**            Pin 7                                        : Do not initialize
**            Pin 8                                        : Do not initialize
**            Pin 9                                        : Do not initialize
**            Pin 10                                       : Do not initialize
**            Pin 11                                       : Do not initialize
**            Pin 12                                       : Do not initialize
**            Pin 13                                       : Do not initialize
**            Pin 14                                       : Do not initialize
**            Pin 15                                       : Do not initialize
**            Pin 16                                       : Do not initialize
**            Pin 17                                       : Do not initialize
**            Pin 18                                       : Do not initialize
**          Pin selection/routing                          : 
**            Pin 0                                        : Enabled
**              Pin                                        : J1_11
**            Pin 1                                        : Enabled
**              Pin                                        : J1_5
**            Pin 2                                        : Enabled
**              Pin                                        : J1_14
**            Pin 3                                        : Enabled
**              Pin                                        : J1_16
**            Pin 4                                        : Disabled
**            Pin 5                                        : Disabled
**            Pin 6                                        : Disabled
**            Pin 7                                        : Disabled
**            Pin 8                                        : Disabled
**            Pin 9                                        : Disabled
**            Pin 10                                       : Disabled
**            Pin 11                                       : Disabled
**            Pin 12                                       : Disabled
**            Pin 13                                       : Disabled
**            Pin 14                                       : Disabled
**            Pin 15                                       : Disabled
**            Pin 16                                       : Disabled
**            Pin 17                                       : Disabled
**            Pin 18                                       : Disabled
**          Interrupts                                     : 
**            Port interrupt                               : Enabled
**              Interrupt                                  : INT_PORTC
**              Interrupt request                          : Enabled
**              Interrupt priority                         : 0
**              ISR Name                                   : MyIRQ
**          Initialization                                 : 
**            Call Init method                             : yes
**            Utilize after reset values                   : default
**     Contents    :
**         Init - void PTC_Init(void);
**
**     Copyright : 1997 - 2015 Freescale Semiconductor, Inc. 
**     All Rights Reserved.
**     
**     Redistribution and use in source and binary forms, with or without modification,
**     are permitted provided that the following conditions are met:
**     
**     o Redistributions of source code must retain the above copyright notice, this list
**       of conditions and the following disclaimer.
**     
**     o Redistributions in binary form must reproduce the above copyright notice, this
**       list of conditions and the following disclaimer in the documentation and/or
**       other materials provided with the distribution.
**     
**     o Neither the name of Freescale Semiconductor, Inc. nor the names of its
**       contributors may be used to endorse or promote products derived from this
**       software without specific prior written permission.
**     
**     THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
**     ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
**     WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
**     DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
**     ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
**     (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
**     LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
**     ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
**     (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
**     SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
**     
**     http: www.freescale.com
**     mail: support@freescale.com
** ###################################################################*/
/*!
** @file PTC.h
** @version 01.06
** @brief
**          This file implements the GPIO (PTC) module initialization
**          according to the Peripheral Initialization settings, and
**          defines interrupt service routines prototypes.
*/         
/*!
**  @addtogroup PTC_module PTC module documentation
**  @{
*/         

#ifndef PTC_H_
#define PTC_H_

/* MODULE PTC. */

#include "PTC_Init.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Initialization method user name */
#define PTC_Init PTC_Init
/* PDD macros peripheral base address parameter */
#define PTC_DEVICE PTC_BASE_PTR
/*
** ===================================================================
** The interrupt service routine must be implemented by user in one
** of the user modules (see PTC.c file for more information).
** ===================================================================
*/
PE_ISR(MyIRQ);

#ifdef __cplusplus
}
#endif

/* END PTC. */
#endif /* #ifndef __PTC_H_ */
/*!
** @}
*/
/*
** ###################################################################
**
**     This file was created by Processor Expert 10.5 [05.21]
**     for the Freescale Kinetis series of microcontrollers.
**
** ###################################################################
*/


