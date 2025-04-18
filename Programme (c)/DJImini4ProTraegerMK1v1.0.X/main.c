/**
  Generated Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This is the main file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  Description:
    This header file provides implementations for driver APIs for all modules selected in the GUI.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.7
        Device            :  PIC16F18323
        Driver Version    :  2.00
*/

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/

#include "mcc_generated_files/mcc.h"

void ServosISR(void);                                           // Prototpy f�r "ServosISR"
bool ServoStatus = false;                                       // definiert "ServoStatus"

/*
                         Main application
 */
void main(void){                                                // "Hauptprogramm"
    SYSTEM_Initialize();                                        // initialize the device
    TMR1_SetInterruptHandler(ServosISR);                        // Define interrupt Handler

    // When using interrupts, you need to set the Global and Peripheral Interrupt Enable bits
    // Use the following macros to:

    // Enable the Global Interrupts
    INTERRUPT_GlobalInterruptEnable();

    // Enable the Peripheral Interrupts
    INTERRUPT_PeripheralInterruptEnable();

    // Disable the Global Interrupts
    //INTERRUPT_GlobalInterruptDisable();

    // Disable the Peripheral Interrupts
    //INTERRUPT_PeripheralInterruptDisable();

    while (1){                                                                  // Endlosschleife
        if(Sensor_GetValue() == false){                                          // wenn "Sensor" gleich "false" ist
            ServoStatus = true;                                                 // setzt "ServoStatus" auf "true"
        }else{                                                                  // sonst
            ServoStatus = false;                                                // setzt "ServoStatus" auf "false"
        }                                                                       // 
    }                                                                           // 
}                                                                               // 

void ServosISR(void){                                                           // "ServosISR" (20s)
    Servo_SetHigh();                                                            // setzt "Servo" auf 1
    __delay_ms(1);                                                              // warte 1ms
    if(ServoStatus == true){                                                    // wenn "ServoStatus" gleich "true" ist
        __delay_us(1000);                                                       // warte 1000us
    }else{                                                                      // sonst
        __delay_us(350);                                                        // warte 350us
    }                                                                           // 
    Servo_SetLow();                                                             // setzt "Servo" auf 0
}                                                                               // 
/**
 End of File
*/