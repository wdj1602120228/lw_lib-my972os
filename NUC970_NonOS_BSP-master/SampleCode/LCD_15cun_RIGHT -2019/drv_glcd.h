
//#include"pic.h"

#ifndef __GLCD_DRV_H
#define __GLCD_DRV_H

#include"main.h"
//#include "arm_comm.h"

// pixel clock frequency < 6.4MHz
// ~5.4Mhz = 408 clk per line * (240 line + 3 Vsynch pulse
//           + 5 front porch + 15 back porch)

#define BLACK_COLOR 0
#define WHITE_COLOR 0xffff
#define RED_COLOR 0xf800
#define BLUE_COLOR 0x001f
#define GREEN_COLOR 0x7e0
#define VIOLET_COLOR 0xf81f
#define YELLOW_COLOR 0xffe0
#define QINGSE_COLOR 0x07ff


#define BASESECTORSIZE 10
#define NUM1632_BLACK_ADD 0
#define NUM1632_RED_ADD 10
#define NUM2448_BALCK_ADD 20
#define NUM2448_RED_ADD 37
#define NUM3264_ADD 52

#define DAO_ADD 300
#define SHOUZHI_ADD 310
#define TUIZHI_ADD 320
#define HENGGANG_ADD 330
#define MAOHAO_ADD 340
#define DOT1632_ADD 350
#define DOT2448_ADD 360
#define KONGBAI_ADD 470
#define DAOSHANG_ADD 480
#define DAOXIA_ADD 490
#define YASHANG_ADD 500
#define YAXIA_ADD 510

#define SHOUZHANG_ADD 620
#define BEIJING_ADD 630
#define REDDAO_ADD 640
#define LUDAO_ADD 650
#define BEIJING_A_BLACK_ADD 660
#define BEIJING_B_BLACK_ADD 670
#define BEIJING_A_RED_ADD 680
#define BEIJING_B_RED_ADD 690
#define BEIJING_REDLINE_ADD 700
#define DOT3264_ADD 710


#define  SDRAM0_BASE_ADDR (Int32U)0x83000000
//#define  NORFLASH1_BASE_ADDR (Int32U)0x81000000

#define LCD_VRAM_BASE_ADDR ((Int32U)SDRAM0_BASE_ADDR)
//#define LCD_CURSOR_BASE_ADDR ((Int32U)0xFFE10800)


////#define LCD_VRAM_BASE_ADDR ((Int32U)SDRAM0_BASE_ADDR)
////#define LCD_CURSOR_BASE_ADDR ((Int32U)0xFFE10800)


/*
#define C_GLCD_REFRESH_FREQ     (50HZ)
//-------------------------群创070TN83
#define C_GLCD_H_SIZE           800
#define C_GLCD_H_PULSE          48
#define C_GLCD_H_FRONT_PORCH    40
#define C_GLCD_H_BACK_PORCH     40
#define C_GLCD_V_SIZE           480
#define C_GLCD_V_PULSE          3
#define C_GLCD_V_FRONT_PORCH    13
#define C_GLCD_V_BACK_PORCH     29

#define C_GLCD_PWR_ENA_DIS_DLY  10000//lcd power start delay
#define C_GLCD_ENA_DIS_DLY      10000
*/
/*
//-------------------------群创070TN92
#define C_GLCD_H_SIZE           800
#define C_GLCD_H_PULSE          20
#define C_GLCD_H_FRONT_PORCH    210
#define C_GLCD_H_BACK_PORCH     46
#define C_GLCD_V_SIZE           480
#define C_GLCD_V_PULSE          3
#define C_GLCD_V_FRONT_PORCH    22
#define C_GLCD_V_BACK_PORCH     23

#define C_GLCD_PWR_ENA_DIS_DLY  10000//lcd power start delay
#define C_GLCD_ENA_DIS_DLY      10000
*/
//-------------------------HB070-DM463  7'



#define LCD_TYPE_AUO_10 		 1 //友达
#define LCD_TYPE_LSA40AT9001	2
#define LCD_TYPE_15in			3
#if (LCD_TYPE ==LCD_TYPE_AUO_10)

  #define C_GLCD_H_SIZE           800
  #define C_GLCD_H_PULSE          128
  #define C_GLCD_H_FRONT_PORCH    40
  #define C_GLCD_H_BACK_PORCH     88
  #define C_GLCD_V_SIZE           600
  #define C_GLCD_V_PULSE          4
  #define C_GLCD_V_FRONT_PORCH    39
  #define C_GLCD_V_BACK_PORCH     27
  /*
  #define C_GLCD_H_SIZE           800
  #define C_GLCD_H_PULSE          128
  #define C_GLCD_H_FRONT_PORCH    40
  #define C_GLCD_H_BACK_PORCH     88
  #define C_GLCD_V_SIZE           600
  #define C_GLCD_V_PULSE          3
  #define C_GLCD_V_FRONT_PORCH    1
  #define C_GLCD_V_BACK_PORCH     27
  */
#elif(LCD_TYPE ==LCD_TYPE_LSA40AT9001)
//-------------------------LSA40AT9001 奇美 10.4'
  #define C_GLCD_H_SIZE           800
  #define C_GLCD_H_PULSE          20
  #define C_GLCD_H_FRONT_PORCH    210//320//
  #define C_GLCD_H_BACK_PORCH     46//320//
  #define C_GLCD_V_SIZE           600
  #define C_GLCD_V_PULSE          5//16//
  #define C_GLCD_V_FRONT_PORCH    12//38//
  #define C_GLCD_V_BACK_PORCH     23//38//
#elif(LCD_TYPE ==LCD_TYPE_15in)
  #define C_GLCD_H_SIZE           1024
  #define C_GLCD_H_PULSE          20
  #define C_GLCD_H_FRONT_PORCH    320//210
  #define C_GLCD_H_BACK_PORCH     320//46
  #define C_GLCD_V_SIZE           768//600
  #define C_GLCD_V_PULSE          16//5
  #define C_GLCD_V_FRONT_PORCH    38//12
  #define C_GLCD_V_BACK_PORCH     38//23
#else
 #define C_GLCD_H_SIZE           800
  #define C_GLCD_H_PULSE          128
  #define C_GLCD_H_FRONT_PORCH    40
  #define C_GLCD_H_BACK_PORCH     88
  #define C_GLCD_V_SIZE           600
  #define C_GLCD_V_PULSE          3
  #define C_GLCD_V_FRONT_PORCH    1
  #define C_GLCD_V_BACK_PORCH     27
#endif



#define C_GLCD_PWR_ENA_DIS_DLY  10000//lcd power start delay
#define C_GLCD_ENA_DIS_DLY      10000


#define CRSR_PIX_32     0
#define CRSR_PIX_64     1
#define CRSR_ASYNC      0
#define CRSR_FRAME_SYNC 2

#define RED 0
#define GREEN    5
#define BLUE     12


#define LVDS_CON_PIN BIT12
#define LVDS_CON_FUN() (GPIO_OpenBit(GPIOF, LVDS_CON_PIN, DIR_OUTPUT, NO_PULL_UP))//P1_MUX_SET_bit.P1_20=1//IO mode
#define LVDS_CON_DIROUT()	 (GPIO_OpenBit(GPIOF, LVDS_CON_PIN, DIR_OUTPUT, NO_PULL_UP))//GPIO_ClrBit(GPIOD, LED0)//P1_DIR_SET_bit.P1_20=1//out mode
#define LVDS_CON_ON()  GPIO_SetBit(GPIOF, LVDS_CON_PIN)//P1_OUTP_SET_bit.P1_20=1
#define LVDS_CON_OFF()  GPIO_ClrBit(GPIOF, LVDS_CON_PIN)//P1_OUTP_CLR_bit.P1_20=1


extern char Bcd[5];

void GLCD_Init (void);
void GLCD_Ctrl (Boolean bEna);
void GLCD_Cursor_Cfg(int Cfg);
void GLCD_Cursor_En(int cursor);
void GLCD_Cursor_Dis(int cursor);
void GLCD_Move_Cursor(int x, int y);
void GLCD_Copy_Cursor (const Int32U *pCursor, int cursor, int size);
void GLCD_ClearBuffer(Int32U Addr);
void GLCD_Buffer_Fill(Int16U color);
void GLCD_DrawLine(Int32S x1,Int32S y1,Int32S x2,Int32S y2,Int16U color);
void DrawLine(Int32S x1,Int32S y1,Int32S x2,Int32S y2,Int16U color);
void PutPixel(Int32U x,Int32U y,Int16U color);
void GLCD_SetWindow(Int32S x1,Int32S y1,Int32S x2,Int32S y2,Int16U Linecolor);
void GLCD_SetWindow_Fill(Int32S x1,Int32S y1,Int32S x2,Int32S y2,Int16U Linecolor,Int16U Windowcolor);
void PutBlockColor(Int32S x1,Int32S x2,Int32S y,Int16U color);
void GLCD_Circle(Int32S centerx, Int32S centery, Int32U radius,Int16U Linecolor);//bresenham画圆算法
void GLCD_Circle_Fill(Int32S centerx, Int32S centery, Int32U radius, Int16U Linecolor, Int16U Boardcolor);
void GLCD_Triangle(Int32S x1,Int32S y1,Int32S x2,Int32S y2,
						Int32S x3,Int32S y3,Int16U Linecolor);
void GLCD_Triangle_Fill(Int32S x1,Int32S y1,Int32S x2,Int32S y2,
						Int32S x3,Int32S y3,Int16U Linecolor,Int16U Boardcolor);
void GLCD_Display_BMP(pInt16U bmpaddr,Int32U x,Int32U y);
void LCD_PutHz(pInt8U HzData,Int32U StartX,Int32U StartY,Int32U LineColor,Int32U FillColor);

    void LoadNumber(char n,int x,int y);
    void LoadNumber1632(char n,int x,int y);
    void LoadNumber2448(char n,int x,int y);
	void LoadHG(int x,int y);
	void LoadMH(int x,int y);

void InPutDis(Int8U num,Int16U Xp,Int16U Yp,Int16U Colar) ; //测试输入 

#endif // __GLCD_DRV_H
