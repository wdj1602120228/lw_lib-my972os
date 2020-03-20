#ifndef IO_H
#define IO_H

#include "main.h"


#define BellOUT BIT13

#define BellOUT_DirInit (GPIO_OpenBit(GPIOF, BellOUT, DIR_OUTPUT, NO_PULL_UP))
#define BellOUT_ON      GPIO_SetBit(GPIOF, BellOUT)
#define BellOUT_OFF     GPIO_ClrBit(GPIOF, BellOUT)
#define BellOUT_ANTI    outpw(REG_GPIOF_DATAOUT,inpw(REG_GPIOF_DATAOUT)^BellOUT)


/*
#define BellOUT (1<<9)
#define BellOUT_DirInit FIO0DIR |=  BellOUT
#define BellOUT_ON      FIO0SET |=  BellOUT
#define BellOUT_OFF     FIO0CLR |=  BellOUT
#define BellOUT_ANTI    FIO0PIN ^=BellOUT
*/

#define LED0 BIT12

#define LED0_DirInit (GPIO_OpenBit(GPIOF, LED0, DIR_OUTPUT, NO_PULL_UP))
#define LED0_ON      GPIO_ClrBit(GPIOF, LED0)
#define LED0_OFF     GPIO_SetBit(GPIOF, LED0)

/*
#define LED0    (1<<13)
#define LED0_DirInit    FIO0DIR |=  LED0
#define LED0_ON         FIO0SET |=  LED0
#define LED0_OFF        FIO0CLR |=  LED0
#define LED0_ANTI       FIO0PIN ^=  LED0
*/


#define LED1 BIT14

#define LED1_DirInit (GPIO_OpenBit(GPIOD, LED1, DIR_OUTPUT, NO_PULL_UP))
#define LED1_ON      GPIO_ClrBit(GPIOD, LED1)
#define LED1_OFF     GPIO_SetBit(GPIOD, LED1)


#define LED2 BIT12

#define LED2_DirInit (GPIO_OpenBit(GPIOD, LED2, DIR_OUTPUT, NO_PULL_UP))
#define LED2_ON      GPIO_ClrBit(GPIOD, LED2)
#define LED2_OFF     GPIO_SetBit(GPIOD, LED2)


#define LCD_BRI_PIN BIT13

#define LCD_BRI_DIR (GPIO_OpenBit(GPIOD, LCD_BRI_PIN, DIR_OUTPUT, NO_PULL_UP))
#define LCD_BRI_ON      GPIO_SetBit(GPIOD, LCD_BRI_PIN)
#define LCD_BRI_OFF     GPIO_ClrBit(GPIOD, LCD_BRI_PIN)


/*
#define LED1    (1<<18)
#define LED1_DirInit    FIO1DIR |=  LED1
#define LED1_ON         FIO1SET |=  LED1
#define LED1_OFF        FIO1CLR |=  LED1
#define LED1_ANTI       FIO1PIN ^=  LED1
*/

#define M_DOUT  BIT3
#define M_DOUT_DirInit    (GPIO_OpenBit(GPIOB, M_DOUT, DIR_OUTPUT, NO_PULL_UP))
#define M_DOUT_ON         GPIO_SetBit(GPIOB, M_DOUT)
#define M_DOUT_OFF        GPIO_ClrBit(GPIOB, M_DOUT)
//#define M_DOUT_ANTI       FIO3PIN ^=  M_DOUT

/*


#define M_DOUT  (1<<19)
#define M_DOUT_DirInit    FIO3DIR |=  M_DOUT
#define M_DOUT_ON         FIO3SET |=  M_DOUT
#define M_DOUT_OFF        FIO3CLR |=  M_DOUT
#define M_DOUT_ANTI       FIO3PIN ^=  M_DOUT
*/

#define M_POUT  BIT2
#define M_POUT_DirInit   (GPIO_OpenBit(GPIOB, M_POUT, DIR_OUTPUT, NO_PULL_UP))
#define M_POUT_ON         GPIO_SetBit(GPIOB, M_POUT)
#define M_POUT_OFF        GPIO_ClrBit(GPIOB, M_POUT)
//#define M_POUT_ANTI       FIO3PIN ^=  M_POUT

/*
#define M_POUT  (1<<18)
#define M_POUT_DirInit    FIO3DIR |=  M_POUT
#define M_POUT_ON         FIO3SET |=  M_POUT
#define M_POUT_OFF        FIO3CLR |=  M_POUT
#define M_POUT_ANTI       FIO3PIN ^=  M_POUT
*/





/*
#define LED2    (1<<22)
#define LED2_DirInit    FIO0DIR |=  LED2
#define LED2_ON         FIO0CLR |=  LED2
#define LED2_OFF        FIO0SET |=  LED2
#define LED2_ANTI       FIO0PIN ^=  LED2
*/

#define RLOUT1  BIT11
#define RLOUT1_DirInit    (GPIO_OpenBit(GPIOG, RLOUT1, DIR_OUTPUT, NO_PULL_UP))
#define RLOUT1_OFF         GPIO_ClrBit(GPIOG, RLOUT1)
#define RLOUT1_ON        GPIO_SetBit(GPIOG, RLOUT1)
//#define RLOUT1_ANTI       (FIO0PIN ^= ( RLOUT1))
/*
#define RLOUT1  (1<<4)
#define RLOUT1_DirInit    (FIO0DIR |=  RLOUT1)
#define RLOUT1_ON         (FIO0SET |=  RLOUT1)
#define RLOUT1_OFF        (FIO0CLR |=  RLOUT1)
#define RLOUT1_ANTI       (FIO0PIN ^= ( RLOUT1))
*/



#define RLOUT2  BIT12
#define RLOUT2_DirInit    (GPIO_OpenBit(GPIOG, RLOUT2, DIR_OUTPUT, NO_PULL_UP))
#define RLOUT2_OFF          GPIO_ClrBit(GPIOG, RLOUT2)
#define RLOUT2_ON        GPIO_SetBit(GPIOG, RLOUT2)

/*
#define RLOUT2  (1<<5)
#define RLOUT2_DirInit    (FIO0DIR |=  RLOUT2)
#define RLOUT2_ON         (FIO0SET |=  RLOUT2)
#define RLOUT2_OFF        (FIO0CLR |=  RLOUT2)
#define RLOUT2_ANTI       (FIO0PIN ^= ( RLOUT2))
*/



#define RLOUT3  BIT13
#define RLOUT3_DirInit    (GPIO_OpenBit(GPIOG, RLOUT3, DIR_OUTPUT, NO_PULL_UP))
#define RLOUT3_OFF          GPIO_ClrBit(GPIOG, RLOUT3)
#define RLOUT3_ON        GPIO_SetBit(GPIOG, RLOUT3)


/*

#define RLOUT3  (1<<6)
#define RLOUT3_DirInit    (FIO0DIR |=  RLOUT3)
#define RLOUT3_ON        ( FIO0SET |=  RLOUT3)
#define RLOUT3_OFF        (FIO0CLR |=  RLOUT3)
#define RLOUT3_ANTI      ( FIO0PIN ^= ( RLOUT3))

*/


#define RLOUT4  BIT14
#define RLOUT4_DirInit    (GPIO_OpenBit(GPIOG, RLOUT4, DIR_OUTPUT, NO_PULL_UP))
#define RLOUT4_OFF           GPIO_ClrBit(GPIOG, RLOUT4)
#define RLOUT4_ON       GPIO_SetBit(GPIOG, RLOUT4)



#define RLOUT1_1  BIT10
#define RLOUT1_1_DirInit    (GPIO_OpenBit(GPIOG, RLOUT1_1, DIR_OUTPUT, NO_PULL_UP))
#define RLOUT1_1_OFF           GPIO_ClrBit(GPIOG, RLOUT1_1)
#define RLOUT1_1_ON       GPIO_SetBit(GPIOG, RLOUT1_1)


/*

#define RLOUT4  (1<<7)
#define RLOUT4_DirInit    (FIO0DIR |=  RLOUT4)
#define RLOUT4_ON         (FIO0SET |=  RLOUT4)
#define RLOUT4_OFF        (FIO0CLR |=  RLOUT4)
#define RLOUT4_ANTI       (FIO0PIN ^=(  RLOUT4))

*/


#define RLOUT5  BIT14
#define RLOUT5_DirInit    (GPIO_OpenBit(GPIOF, RLOUT5, DIR_OUTPUT, NO_PULL_UP))
#define RLOUT5_OFF          GPIO_ClrBit(GPIOF, RLOUT5)
#define RLOUT5_ON        GPIO_SetBit(GPIOF, RLOUT5)

/*

#define RLOUT5  (1<<11)
#define RLOUT5_DirInit    (FIO1DIR |=  RLOUT5)
#define RLOUT5_ON         (FIO1SET |=  RLOUT5)
#define RLOUT5_OFF        (FIO1CLR |=  RLOUT5)
#define RLOUT5_ANTI       (FIO1PIN ^=(  RLOUT5))

*/

#define OOUT1  BIT4
#define OOUT1_DirInit   (GPIO_OpenBit(GPIOH, OOUT1, DIR_OUTPUT, NO_PULL_UP))
#define OOUT1_OFF          GPIO_ClrBit(GPIOH, OOUT1)
#define OOUT1_ON        GPIO_SetBit(GPIOH, OOUT1)
//#define OOUT1_ANTI       (FIO0PIN ^=(  OOUT1))




/*
#define OOUT1  (1<<23)
#define OOUT1_DirInit    (FIO0DIR |=  OOUT1)
#define OOUT1_ON         (FIO0SET |=  OOUT1)
#define OOUT1_OFF        (FIO0CLR |=  OOUT1)
#define OOUT1_ANTI       (FIO0PIN ^=(  OOUT1))

*/


#define OOUT2  BIT5
#define OOUT2_DirInit   (GPIO_OpenBit(GPIOH, OOUT2, DIR_OUTPUT, NO_PULL_UP))
#define OOUT2_OFF           GPIO_ClrBit(GPIOH, OOUT2)
#define OOUT2_ON       GPIO_SetBit(GPIOH, OOUT2)


/*

#define OOUT2  (1<<24)
#define OOUT2_DirInit    (FIO0DIR |= OOUT2)
#define OOUT2_ON         (FIO0SET |=  OOUT2)
#define OOUT2_OFF       ( FIO0CLR |=  OOUT2)
#define OOUT2_ANTI       (FIO0PIN ^= ( OOUT2))
*/


#define OOUT3  BIT6
#define OOUT3_DirInit   (GPIO_OpenBit(GPIOH, OOUT3, DIR_OUTPUT, NO_PULL_UP))
#define OOUT3_OFF          GPIO_ClrBit(GPIOH, OOUT3)
#define OOUT3_ON        GPIO_SetBit(GPIOH, OOUT3)



/*
#define OOUT3  (1<<25)
#define OOUT3_DirInit    (FIO0DIR |=  OOUT3)
#define OOUT3_ON         (FIO0SET |=  OOUT3)
#define OOUT3_OFF       ( FIO0CLR |=  OOUT3)
#define OOUT3_ANTI       (FIO0PIN ^=(  OOUT3))
*/


#define OOUT4  BIT7
#define OOUT4_DirInit   (GPIO_OpenBit(GPIOH, OOUT4, DIR_OUTPUT, NO_PULL_UP))
#define OOUT4_OFF         GPIO_ClrBit(GPIOH, OOUT4)
#define OOUT4_ON        GPIO_SetBit(GPIOH, OOUT4)


/*
#define OOUT4  (1<<26)
#define OOUT4_DirInit    (FIO0DIR |=  OOUT4)
#define OOUT4_ON         (FIO0SET |=  OOUT4)
#define OOUT4_OFF        (FIO0CLR |=  OOUT4)
#define OOUT4_ANTI       (FIO0PIN ^= ( OOUT4))
*/



#define AOUT1_CLR()    OOUT1_ON
#define AOUT2_CLR()    OOUT2_ON
#define AOUT3_CLR()    OOUT3_ON
#define AOUT4_CLR()    OOUT4_ON
//#define AOUT5_CLR()    OOUT5_OFF


#define AOUT1_SET()    OOUT1_OFF
#define AOUT2_SET()    OOUT2_OFF
#define AOUT3_SET()    OOUT3_OFF
#define AOUT4_SET()    OOUT4_OFF
//#define AOUT5_SET()    OOUT5_ON



#define M_ZIN BIT9
#define M_ZIN_DirInit     (GPIO_OpenBit(GPIOF, M_ZIN, DIR_INPUT, NO_PULL_UP))
#define M_ZIN_PIN        GPIO_ReadBit(GPIOF,M_ZIN)


/*
#define M_ZIN (1<<11)
#define M_ZIN_DirInit     FIO2DIR &= ~( M_ZIN)
#define M_ZIN_PIN         (FIO2PIN &  M_ZIN)

*/


#define OIN1 BIT4
#define OIN1_DirInit     (GPIO_OpenBit(GPIOF, OIN1, DIR_INPUT, NO_PULL_UP))
#define OIN1_PIN        GPIO_ReadBit(GPIOF,OIN1)


/*

#define OIN1   (1<<0)
#define OIN1_DirInit     FIO1DIR &= ~( OIN1)
#define OIN1_PIN         (FIO1PIN &  OIN1)
*/

#define OIN2 BIT3
#define OIN2_DirInit     (GPIO_OpenBit(GPIOF, OIN2, DIR_INPUT, NO_PULL_UP))
#define OIN2_PIN        GPIO_ReadBit(GPIOF,OIN2)


/*
#define OIN2    (1<<1)
#define OIN2_DirInit     FIO1DIR &= ~( OIN2)
#define OIN2_PIN         (FIO1PIN &  OIN2)
*/


#define OIN3 BIT2
#define OIN3_DirInit     (GPIO_OpenBit(GPIOF, OIN3, DIR_INPUT, NO_PULL_UP))
#define OIN3_PIN        GPIO_ReadBit(GPIOF,OIN3)


/*
#define OIN3    (1<<9)
#define OIN3_DirInit     FIO1DIR &= ~( OIN3)
#define OIN3_PIN         (FIO1PIN &  OIN3)
*/


#define OIN4 BIT1
#define OIN4_DirInit     (GPIO_OpenBit(GPIOF, OIN4, DIR_INPUT, NO_PULL_UP))
#define OIN4_PIN        GPIO_ReadBit(GPIOF,OIN4)


/*
#define OIN4    (1<<10)
#define OIN4_DirInit     FIO1DIR &= ~( OIN4)
#define OIN4_PIN         (FIO1PIN &  OIN4)
*/

#define OIN5 BIT0
#define OIN5_DirInit     (GPIO_OpenBit(GPIOF, OIN5, DIR_INPUT, NO_PULL_UP))
#define OIN5_PIN        GPIO_ReadBit(GPIOF,OIN5)


/*
#define OIN5    (1<<4)
#define OIN5_DirInit     FIO1DIR &= ~( OIN5)
#define OIN5_PIN         (FIO1PIN &  OIN5)
*/


#define OIN6 BIT7
#define OIN6_DirInit     (GPIO_OpenBit(GPIOF, OIN6, DIR_INPUT, NO_PULL_UP))
#define OIN6_PIN        GPIO_ReadBit(GPIOF,OIN6)


/*
#define OIN6    (1<<8)
#define OIN6_DirInit     FIO1DIR &= ~( OIN6)
#define OIN6_PIN         (FIO1PIN &  OIN6)
*/


#define OIN7 BIT6
#define OIN7_DirInit     (GPIO_OpenBit(GPIOF, OIN7, DIR_INPUT, NO_PULL_UP))
#define OIN7_PIN        GPIO_ReadBit(GPIOF,OIN7)


/*
#define OIN7    (1<<13)
#define OIN7_DirInit     FIO1DIR &= ~( OIN7)
#define OIN7_PIN         (FIO1PIN &  OIN7)
*/

#define OIN8 BIT5
#define OIN8_DirInit     (GPIO_OpenBit(GPIOF, OIN8, DIR_INPUT, NO_PULL_UP))
#define OIN8_PIN        GPIO_ReadBit(GPIOF,OIN8)


/*
#define OIN8    (1<<14)
#define OIN8_DirInit     FIO1DIR &= ~( OIN8)
#define OIN8_PIN         (FIO1PIN &  OIN8)   
*/

#define OIN11 BIT11
#define OIN11_DirInit     (GPIO_OpenBit(GPIOD, OIN11, DIR_INPUT, NO_PULL_UP))
#define OIN11_PIN        GPIO_ReadBit(GPIOD,OIN11)

/*
#define OIN9    (1<<15)
#define OIN9_DirInit     FIO1DIR &= ~( OIN9)
#define OIN9_PIN         (FIO1PIN &  OIN9)  
*/


#define OIN12 BIT10
#define OIN12_DirInit     (GPIO_OpenBit(GPIOD, OIN12, DIR_INPUT, NO_PULL_UP))
#define OIN12_PIN        GPIO_ReadBit(GPIOD,OIN12)

/*

#define OIN10 (1<<16)
#define OIN10_DirInit     FIO2DIR &= ~( OIN10)
#define OIN10_PIN         (FIO2PIN &  OIN10)
*/


#define OIN13 BIT9
#define OIN13_DirInit     (GPIO_OpenBit(GPIOD, OIN13, DIR_INPUT, NO_PULL_UP))
#define OIN13_PIN        GPIO_ReadBit(GPIOD,OIN13)


/*


//#define OIN11 17
//#define OIN11_DirInit     FIO1DIR &= ~( OIN11)
//#define OIN11_PIN         (FIO1PIN &  OIN11)

*/

/*
#define OIN11 (1<<17)
#define OIN11_DirInit     FIO1DIR &= ~( OIN11)
#define OIN11_PIN         (FIO1PIN &  OIN11)
*/


#define OIN10 BIT8
#define OIN10_DirInit     (GPIO_OpenBit(GPIOD, OIN10, DIR_INPUT, NO_PULL_UP))
#define OIN10_PIN        GPIO_ReadBit(GPIOD,OIN10)


/*
#define OIN12 (1<<2)
#define OIN12_DirInit     FIO1DIR &= ~( OIN12)
#define OIN12_PIN         (FIO1PIN &  OIN12)
*/


#define OIN9 BIT8
#define OIN9_DirInit     (GPIO_OpenBit(GPIOF, OIN9, DIR_INPUT, NO_PULL_UP))
#define OIN9_PIN        GPIO_ReadBit(GPIOF,OIN9)


/*
#define OIN13 (1<<3)
#define OIN13_DirInit     FIO1DIR &= ~( OIN13)
#define OIN13_PIN         (FIO1PIN &  OIN13)
*/


#define OIN14 BIT8
#define OIN14_DirInit     (GPIO_OpenBit(GPIOD, OIN14, DIR_INPUT, NO_PULL_UP))
#define OIN14_PIN        GPIO_ReadBit(GPIOD,OIN14)

/*
#define OIN14 (1<<5)
#define OIN14_DirInit     FIO1DIR &= ~( OIN14)
#define OIN14_PIN         (FIO1PIN &  OIN14)
*/


#define OIN15 BIT8
#define OIN15_DirInit     (GPIO_OpenBit(GPIOF, OIN15, DIR_INPUT, NO_PULL_UP))
#define OIN15_PIN        GPIO_ReadBit(GPIOF,OIN15)
/*
#define OIN15 (1<<6)
#define OIN15_DirInit     FIO1DIR &= ~( OIN15)
#define OIN15_PIN         (FIO1PIN &  OIN15)

*/

/*


#define SCK 1<<15
#define SCk_DirOut      FIO0DIR|=  SCK
#define SCk_ON         (FIO0SET |=  SCK)
#define SCk_OFF        (FIO0CLR |=  SCK)
#define SCk_ANTI       (FIO0PIN ^= ( SCK))
*/

/*
#define MISO 1<<17
#define MISO_DirOut      FIO0DIR|=  MISO
#define MISO_ON         (FIO0SET |=  MISO)
#define MISO_OFF        (FIO0CLR |=  MISO)
#define MISO_ANTI       (FIO0PIN ^= ( MISO))
*/

/*
#define MOSI 1<<18
#define MOSI_DirOut      FIO0DIR|=  MOSI
#define MOSI_ON         (FIO0SET |=  MOSI)
#define MOSI_OFF        (FIO0CLR |=  MOSI)
#define MOSI_ANTI       (FIO0PIN ^= ( MOSI))
*/

/*
#define CS 1<<16
#define CS_DirOut      FIO0DIR|=  CS
#define CS_ON         (FIO0SET |=  CS)
#define CS_OFF        (FIO0CLR |=  CS)
#define CS_ANTI       (FIO0PIN ^= ( CS))

*/


#define I2CNUM_0    0
#define I2CNUM_1    1

extern void IO_Init(void);
extern void IO_Test(void);
extern void CheckOp_IN(void);

extern void I2C_Init(void);
extern void I2C_Test(void);

extern void Sys_DevInit(void);

#endif 
