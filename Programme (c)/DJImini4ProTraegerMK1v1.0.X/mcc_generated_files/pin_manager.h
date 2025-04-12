/**
  @Generated Pin Manager Header File

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.h

  @Summary:
    This is the Pin Manager file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description
    This header file provides APIs for driver for .
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.7
        Device            :  PIC16F18323
        Driver Version    :  2.11
    The generated drivers are tested against the following:
        Compiler          :  XC8 2.31 and above
        MPLAB 	          :  MPLAB X 5.45	
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

#ifndef PIN_MANAGER_H
#define PIN_MANAGER_H

/**
  Section: Included Files
*/

#include <xc.h>

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set Servo aliases
#define Servo_TRIS                 TRISCbits.TRISC2
#define Servo_LAT                  LATCbits.LATC2
#define Servo_PORT                 PORTCbits.RC2
#define Servo_WPU                  WPUCbits.WPUC2
#define Servo_OD                   ODCONCbits.ODCC2
#define Servo_ANS                  ANSELCbits.ANSC2
#define Servo_SetHigh()            do { LATCbits.LATC2 = 1; } while(0)
#define Servo_SetLow()             do { LATCbits.LATC2 = 0; } while(0)
#define Servo_Toggle()             do { LATCbits.LATC2 = ~LATCbits.LATC2; } while(0)
#define Servo_GetValue()           PORTCbits.RC2
#define Servo_SetDigitalInput()    do { TRISCbits.TRISC2 = 1; } while(0)
#define Servo_SetDigitalOutput()   do { TRISCbits.TRISC2 = 0; } while(0)
#define Servo_SetPullup()          do { WPUCbits.WPUC2 = 1; } while(0)
#define Servo_ResetPullup()        do { WPUCbits.WPUC2 = 0; } while(0)
#define Servo_SetPushPull()        do { ODCONCbits.ODCC2 = 0; } while(0)
#define Servo_SetOpenDrain()       do { ODCONCbits.ODCC2 = 1; } while(0)
#define Servo_SetAnalogMode()      do { ANSELCbits.ANSC2 = 1; } while(0)
#define Servo_SetDigitalMode()     do { ANSELCbits.ANSC2 = 0; } while(0)

// get/set Sensor aliases
#define Sensor_TRIS                 TRISCbits.TRISC3
#define Sensor_LAT                  LATCbits.LATC3
#define Sensor_PORT                 PORTCbits.RC3
#define Sensor_WPU                  WPUCbits.WPUC3
#define Sensor_OD                   ODCONCbits.ODCC3
#define Sensor_ANS                  ANSELCbits.ANSC3
#define Sensor_SetHigh()            do { LATCbits.LATC3 = 1; } while(0)
#define Sensor_SetLow()             do { LATCbits.LATC3 = 0; } while(0)
#define Sensor_Toggle()             do { LATCbits.LATC3 = ~LATCbits.LATC3; } while(0)
#define Sensor_GetValue()           PORTCbits.RC3
#define Sensor_SetDigitalInput()    do { TRISCbits.TRISC3 = 1; } while(0)
#define Sensor_SetDigitalOutput()   do { TRISCbits.TRISC3 = 0; } while(0)
#define Sensor_SetPullup()          do { WPUCbits.WPUC3 = 1; } while(0)
#define Sensor_ResetPullup()        do { WPUCbits.WPUC3 = 0; } while(0)
#define Sensor_SetPushPull()        do { ODCONCbits.ODCC3 = 0; } while(0)
#define Sensor_SetOpenDrain()       do { ODCONCbits.ODCC3 = 1; } while(0)
#define Sensor_SetAnalogMode()      do { ANSELCbits.ANSC3 = 1; } while(0)
#define Sensor_SetDigitalMode()     do { ANSELCbits.ANSC3 = 0; } while(0)

/**
   @Param
    none
   @Returns
    none
   @Description
    GPIO and peripheral I/O initialization
   @Example
    PIN_MANAGER_Initialize();
 */
void PIN_MANAGER_Initialize (void);

/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handling routine
 * @Example
    PIN_MANAGER_IOC();
 */
void PIN_MANAGER_IOC(void);



#endif // PIN_MANAGER_H
/**
 End of File
*/