#include "gtp.h"
#include "i2c_config.h"
#include "chndot.h"


Gtp_T tp_dev;

GT911_T g_GT911;
Int8U gtp_configbuf[256];


Int8U GtpCheckTime=0;

//GT911配置参数表
//第一个字节为版本号(0X60),必须保证新的版本号大于等于GT911内部
//flash原有版本号,才会更新配置.
 Int8U GT911_CFG_TBL[]=
{

	/* 0x52,0XE0,0X01,0X20,0X03,0x05,0x35,0x80,0x01,0x0F,//0x8047-0x8050
    0x19,0x0F,0x5A,0x46,0x03,0x05,0x00,0x00,0x00,0x00,//0x8051-0x805a
    0x00,0x00,0x00,0x19,0x1B,0x1D,0x14,0x8C,0x2D,0x0E,//0x805b-0x8064
    0x32,0x30,0xFB,0x10,0x00,0x00,0x00,0x9B,0x02,0x2D,//0X8065-0X806E
    0x00,0x01,0x00,0x00,0x00,0x00,0x64,0x00,0x00,0x00,//0X806F-0X8078
    0x00,0x28,0x7D,0x94,0x85,0x02,0x08,0x00,0x00,0x47,//0X8079-0X8082 
    0x0A,0x1F,0x35,0x0C,0x22,0x77,0x0E,0x23,0x46,0x10,//0X8083-0X808C
    0x28,0xFB,0x10,0x30,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x1C,0x1A,0x18,0x16,0x14,0x12,0x10,0x0E,
    0x0C,0x0A,0x08,0x06,0x04,0x02,0xFF,0xFF,0xFF,0xFF,
    0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
    0xFF,0xFF,0x00,0x02,0x04,0x06,0x08,0x0A,0x0C,0x0F,
    0x10,0x12,0x13,0x14,0x16,0x18,0x1C,0x1D,0x1E,0x1F,
    0x20,0x21,0x22,0x24,0x26,0x28,0x29,0x2A,0xFF,0xFF,
    0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
    0xFF,0xFF,0xFF,0xFF,0x4a,0x01*/
	0x52,0x00,0x04,0x58,0x02,0x0A,0x0D,0x00,0x01,0x0F,0x28,0x0F,0x50,0x32,0x03,0x05,0x00,0x00,0x00,0x00,0x00,0x00,0x0F,0x17,0x19,0x1C,0x14,0x8C,0x23,0x0A,0x1F,0x21,0x0C,0x08,0x00,0x00,0x01,0xB9,0x03,0x1D,0x00,0x00,0x00,0x00,0x00,0x03,0x64,0x32,0x00,0x00,0x00,0x15,0x4C,0x94,0xC5,0x02,0x07,0x00,0x00,0x04,0xA0,0x18,0x00,0x80,0x1F,0x00,0x67,0x28,0x00,0x54,0x34,0x00,0x46,0x43,0x00,0x46,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x02,0x04,0x06,0x08,0x0A,0x0C,0x0E,0x10,0x12,0x14,0xFF,0xFF,0xFF,0xFF,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x02,0x04,0x06,0x08,0x0A,0x0C,0x0F,0x10,0x12,0x13,0x14,0x16,0x18,0x1C,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x4A,0x01
/*	
0x60,	//0x8047	版本号

0xE0,0x01,	//0x8048/8049	X坐标输出最大值480

0x56,0x03,	//0x804a/804b	Y坐标输出最大值854

0x01,	//0x804c	输出触点个数上限

0x35,	//0x804d	软件降噪，下降沿触发

0x00,	//0x804e	reserved

0x02,	//0x804f	手指按下去抖动次数

0x08,	//0x8050	原始坐标窗口滤波值

0x28,	//0x8051	大面积触点个数

0x0A,	//0x8052	噪声消除值

0x5A,	//0x8053	屏上触摸点从无到有的阈值

0x46,	//0x8054	屏上触摸点从有到无的阈值

0x03,	//0x8055	进低功耗时间	s

0x05,	//0x8056


0x00,	//0x8057	X坐标输出门上限

0x00,	//0x8058	Y坐标输出门上限

0x00,0X00,	//0x8059-0x805a	reserved

0x00,	//0x805b	reserved

0x00,	//0x805c	reserved

0x00,	//0x805d	划线过程中小filter设置

0x18,	//0x805e	拉伸区间	1	系数

0x1A,	//0x805f	拉伸区间	2	系数

0x1E,	//0x8060	拉伸区间	3	系数

0x14,	//0x8061	各拉伸区间基数

0x8C,	//0x8062	、、

0x28,	//0x8063	、、

0x0C,	//0x8064	、、

0x71,	//0x8065	驱动组A的驱动频率倍频系数

0x73,	//0x8066	驱动组B的驱动频率倍频系数

0xB2,	//0x8067	驱动组A、B的基频

0x04,	//0x8068

0x00,	//0x8069	相邻两次驱动信号输出时间间隔

0x00,	//0x806a

0x00,	//0x806b	、、

0x02,	//0x806c	、、

0x03,	//0x806d	原始值放大系数

0x1D,	//0x806e	、、

0x00,	//0x806f	reserved

0x01,	//0x8070	、、

0x00,0x00,	//reserved

0x00,	//0x8073	、、

0x00,0x00,0x00,0x00,0x00,0x00,	//0x8071 - 0x8079 reserved

0x50,	//0x807a	跳频范围的起点频率

0xA0,	//0x807b	跳频范围的终点频率

0x94,	//0x807c	多次噪声检测后确定噪声量，1-63有效

0xD5,	//0x807d	噪声检测超时时间

0x02,	//0x807e	、、

0x07,	//0x807f	判别有干扰的门限

0x00,0x00,	//0x8081	reserved

0x04,	//0x8082	跳频检测区间频段1中心点基频（适用于驱动A、B）

0xA4,	//0x8083

0x55,	//0x8084	跳频检测区间频段1中心点倍频系数

0x00,	//0x8085	跳频检测区间频段2中心点基频(驱动A、B在此基础上换算)

0x91,	//0x8086

0x62,	//0x8087	跳频检测区间频段2中心点倍频系数

0x00,	//0x8088	跳频检测区间频段3中心点基频（适用于驱动A、B）

0x80,	//0x8089

0x71,	//0x808a	跳频检测区间频段3中心点倍频系数

0x00,	//0x808b	跳频检测区间频段4中心点基频（适用于驱动A、B）

0x71,	//0x808c

0x82,	//0x808d	跳频检测区间频段4中心点倍频系数

0x00,	//0x808e	跳频检测区间频段5中心点基频（适用于驱动A、B）

0x65,	//0x808f

0x95,	//0x8090	跳频检测区间频段5中心点倍频系数

0x00,	0x65,	//reserved

0x00,	//0x8093	key1位置	0：无按键

0x00,	//0x8094	key2位置	0：无按键

0x00,	//0x8095	key3位置	0：无按键

0x00,	//0x8096	key4位置	0：无按键

0x00,	//0x8097	reserved

0x00,	//0x8098	reserved

0x00,	//0x8099	reserved

0x00,	//0x809a	reserved

0x00,	//0x809b	reserved

0x00,	//0x809c	reserved

0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,

0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,	//0x809d-0x80b2	reserved

0x00,	//0x80b3	合框距离

0x00,	//0x80b4

0x00,0x00,	//0x80b6	reserved

0x06,	//0x80b7

0x08,	//0x80b8

0x0A,	//0x80b9

0x0C,	//0x80ba

0x0E,	//0x80bb

0x10,	//0x80bc

0x12,	//0x80bd

0x14,	//0x80be

0x16,	//0x80bf

0x18,	//0x80c0

0x1A,	//0x80c1

0x1C,	//0x80c2

0xFF,	//0x80c3

0xFF,	//0x80c4

0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,

0x00,0x00,0x00

,0x00,	//0x80c5-0x80d4	reserved

0x00,	//0x80d5

0x02,	//0x80d6

0x04,	//0x80d7

0x06,	//0x80d8

0x08,	//0x80d9

0x0A,	//0x80da

0x0C,	//0x80db

0x0F,	//0x80dc

0x10,	//0x80dd

0x12,	//0x80de

0x13,	//0x80df

0x14,	//0x80e0

0x16,	//0x80e1

0x18,	//0x80e2

0x1C,	//0x80e3

0x1D,	//0x80e4

0x1E,	//0x80e5

0x1F,	//0x80e6

0x20,	//0x80e7

0x21,	//0x80e8

0xFF,	//0x80e9

0xFF,	//0x80ea

0xFF,	//0x80eb

0xFF,	//0x80ec

0xFF,	//0x80ed

0xFF,	//0x80ee

0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,

0x00,0x00,0x00,0x00	//0x80ef-0x80fe	reserved
*/
	/*
   0x60,0XE0,0X01,0X20,0X03,0x05,0x35,0x80,0x01,0x0F,//0x8047-0x8050
    0x19,0x0F,0x5A,0x46,0x03,0x05,0x00,0x00,0x00,0x00,//0x8051-0x805a
    0x00,0x00,0x00,0x19,0x1B,0x1D,0x14,0x8C,0x2D,0x0E,//0x805b-0x8064
    0x32,0x30,0xFB,0x10,0x00,0x00,0x00,0x9B,0x02,0x2D,//0X8065-0X806E
    0x00,0x01,0x00,0x00,0x00,0x00,0x64,0x00,0x00,0x00,//0X806F-0X8078
    0x00,0x28,0x7D,0x94,0x85,0x02,0x08,0x00,0x00,0x47,//0X8079-0X8082 
    0x0A,0x1F,0x35,0x0C,0x22,0x77,0x0E,0x23,0x46,0x10,//0X8083-0X808C
    0x28,0xFB,0x10,0x30,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x1C,0x1A,0x18,0x16,0x14,0x12,0x10,0x0E,
    0x0C,0x0A,0x08,0x06,0x04,0x02,0xFF,0xFF,0xFF,0xFF,
    0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
    0xFF,0xFF,0x00,0x02,0x04,0x06,0x08,0x0A,0x0C,0x0F,
    0x10,0x12,0x13,0x14,0x16,0x18,0x1C,0x1D,0x1E,0x1F,
    0x20,0x21,0x22,0x24,0x26,0x28,0x29,0x2A,0xFF,0xFF,
    0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
    0xFF,0xFF,0xFF,0xFF */
};  


	Int8U s_GT911_CfgParams_new[]=
	{
  0x63,0xE0,0x01,0x20,0x03,0x0A,0x05,0x00,0x01,0x08,0x28,
	0x0B,0x50,0x32,0x03,0x05,0x00,0x00,0x00,0x00,0x11,0x11,
	0x00,0x00,0x00,0x00,0x00,0x89,0x28,0x0A,0x4A,0x47,0x31,
	0x0D,0x00,0x00,0x01,0xB9,0x02,0x25,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x1D,0x89,0x94,0xC5,
	0x02,0x07,0x00,0x00,0x04,0xE3,0x22,0x00,0xB0,0x2E,0x00,
	0x8B,0x3F,0x00,0x73,0x57,0x00,0x69,0x76,0x00,0x69,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x08,0x0A,0x0C,0x0E,0x10,0x12,0x14,0x16,0x18,
	0x1A,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,  
	0x02,0x04,0x05,0x06,0x08,0x0A,0x0C,0x0E,0x1D,0x1E,0x1F,
	0x20,0x22,0x24,0x28,0x29,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x74,0x01

	};


	Int8U s_GT911_CfgParams[]=

{

0x00,	//0x8047	版本号

0xE0,0x01,	//0x8048/8049	X坐标输出最大值480

0x56,0x03,	//0x804a/804b	Y坐标输出最大值854

0x05,	//0x804c	输出触点个数上限

0x35,	//0x804d	软件降噪，下降沿触发

0x00,	//0x804e	reserved

0x02,	//0x804f	手指按下去抖动次数

0x08,	//0x8050	原始坐标窗口滤波值

0x28,	//0x8051	大面积触点个数

0x0A,	//0x8052	噪声消除值

0x5A,	//0x8053	屏上触摸点从无到有的阈值

0x46,	//0x8054	屏上触摸点从有到无的阈值

0x03,	//0x8055	进低功耗时间	s

0x05,	//0x8056	坐标上报率

0x00,	//0x8057	X坐标输出门上限

0x00,	//0x8058	Y坐标输出门上限

0x00,0X00,	//0x8059-0x805a	reserved

0x00,	//0x805b	reserved

0x00,	//0x805c	reserved

0x00,	//0x805d	划线过程中小filter设置

0x18,	//0x805e	拉伸区间	1	系数

0x1A,	//0x805f	拉伸区间	2	系数

0x1E,	//0x8060	拉伸区间	3	系数

0x14,	//0x8061	各拉伸区间基数

0x8C,	//0x8062	、、

0x28,	//0x8063	、、

0x0C,	//0x8064	、、

0x71,	//0x8065	驱动组A的驱动频率倍频系数

0x73,	//0x8066	驱动组B的驱动频率倍频系数

0xB2,	//0x8067	驱动组A、B的基频

0x04,	//0x8068

0x00,	//0x8069	相邻两次驱动信号输出时间间隔

0x00,	//0x806a

0x00,	//0x806b	、、

0x02,	//0x806c	、、

0x03,	//0x806d	原始值放大系数

0x1D,	//0x806e	、、

0x00,	//0x806f	reserved

0x01,	//0x8070	、、

0x00,0x00,	//reserved

0x00,	//0x8073	、、

0x00,0x00,0x00,0x00,0x00,0x00,	//0x8071 - 0x8079 reserved

0x50,	//0x807a	跳频范围的起点频率

0xA0,	//0x807b	跳频范围的终点频率

0x94,	//0x807c	多次噪声检测后确定噪声量，1-63有效

0xD5,	//0x807d	噪声检测超时时间

0x02,	//0x807e	、、

0x07,	//0x807f	判别有干扰的门限

0x00,0x00,	//0x8081	reserved

0x04,	//0x8082	跳频检测区间频段1中心点基频（适用于驱动A、B）

0xA4,	//0x8083

0x55,	//0x8084	跳频检测区间频段1中心点倍频系数

0x00,	//0x8085	跳频检测区间频段2中心点基频(驱动A、B在此基础上换算)

0x91,	//0x8086

0x62,	//0x8087	跳频检测区间频段2中心点倍频系数

0x00,	//0x8088	跳频检测区间频段3中心点基频（适用于驱动A、B）

0x80,	//0x8089

0x71,	//0x808a	跳频检测区间频段3中心点倍频系数

0x00,	//0x808b	跳频检测区间频段4中心点基频（适用于驱动A、B）

0x71,	//0x808c

0x82,	//0x808d	跳频检测区间频段4中心点倍频系数

0x00,	//0x808e	跳频检测区间频段5中心点基频（适用于驱动A、B）

0x65,	//0x808f

0x95,	//0x8090	跳频检测区间频段5中心点倍频系数

0x00,	0x65,	//reserved

0x00,	//0x8093	key1位置	0：无按键

0x00,	//0x8094	key2位置	0：无按键

0x00,	//0x8095	key3位置	0：无按键

0x00,	//0x8096	key4位置	0：无按键

0x00,	//0x8097	reserved

0x00,	//0x8098	reserved

0x00,	//0x8099	reserved

0x00,	//0x809a	reserved

0x00,	//0x809b	reserved

0x00,	//0x809c	reserved

0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,

0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,	//0x809d-0x80b2	reserved

0x00,	//0x80b3	合框距离

0x00,	//0x80b4

0x00,0x00,	//0x80b6	reserved

0x06,	//0x80b7

0x08,	//0x80b8

0x0A,	//0x80b9

0x0C,	//0x80ba

0x0E,	//0x80bb

0x10,	//0x80bc

0x12,	//0x80bd

0x14,	//0x80be

0x16,	//0x80bf

0x18,	//0x80c0

0x1A,	//0x80c1

0x1C,	//0x80c2

0xFF,	//0x80c3

0xFF,	//0x80c4

0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,

0x00,0x00,0x00

,0x00,	//0x80c5-0x80d4	reserved

0x00,	//0x80d5

0x02,	//0x80d6

0x04,	//0x80d7

0x06,	//0x80d8

0x08,	//0x80d9

0x0A,	//0x80da

0x0C,	//0x80db

0x0F,	//0x80dc

0x10,	//0x80dd

0x12,	//0x80de

0x13,	//0x80df

0x14,	//0x80e0

0x16,	//0x80e1

0x18,	//0x80e2

0x1C,	//0x80e3

0x1D,	//0x80e4

0x1E,	//0x80e5

0x1F,	//0x80e6

0x20,	//0x80e7

0x21,	//0x80e8

0xFF,	//0x80e9

0xFF,	//0x80ea

0xFF,	//0x80eb

0xFF,	//0x80ec

0xFF,	//0x80ed

0xFF,	//0x80ee

0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,

0x00,0x00,0x00,0x00,	//0x80ef-0x80fe	reserved

0x0B,	//0x80ff	配置信息校验

0x01	//0x8100	配置以更新标记

};


void Gtp_IO_Init(void)
{
	int i;
	int n;
	for(i=0;i<200;i++)
	gtp_configbuf[i]=0;
	
I2C0_Init();
GTP_PD_Low();
GTP_PD_DIR_OUT();
	
GPIO_ClrBit(GPIOG,GTP_INT_PIN);
GPIO_OpenBit(GPIOG, GTP_INT_PIN, DIR_OUTPUT, PULL_UP);
	

	n=2000000;
while(n--);
GPIO_SetBit(GPIOG,GTP_INT_PIN);
	
n=500000;
while(n--);
	
GTP_PD_High();

//GT911_RD_Reg(0x8047,&gtp_configbuf[0],185);
n=3000000;
while(n--);

GPIO_CloseBit(GPIOG, GTP_INT_PIN);
GTP_INT_DIR_IN(); //设定INT引脚为输入悬空

n=5000000;
while(n--);

GT911_Init();
//GT911_InitHard();

GT911_ReadStatue();
GT911_ReadFirmwareVersion();
	
	GT911_RD_Reg(0x8047,&gtp_configbuf[0],186);
	
	
	for(i=0;i<186;i++)
		if(gtp_configbuf[i]!=GT911_CFG_TBL[i])
		{
			break;
			}

}




Int8U GT911_ReadStatue(void)

{

Int8U buf[4];

GT911_RD_Reg(GT911_PRODUCT_ID_REG, (Int8U *)&buf[0], 3);

GT911_RD_Reg(GT911_CONFIG_VERSION_REG, (Int8U *)&buf[3], 1);

//printf("TouchPad_ID:%c,%c,%c\r\nTouchPad_Config_Version:%2x\r\n",buf[0],buf[1],buf[2],buf[3]);

return buf[3];

}


//发送GT911配置参数
//mode:0,参数不保存到flash
//     1,参数保存到flash
Int8U GT911_Send_Cfg(Int8U mode)
{
	Int8U buf[2];
	Int8U i=0;
	buf[0]=0;
	buf[1]=mode;	//是否写入到GT911 FLASH?  即是否掉电保存
for(i=0;i<sizeof(GT911_CFG_TBL)-2;i++)buf[0]+=GT911_CFG_TBL[i];//计算校验和
    buf[0]=(~buf[0])+1;
	GT911_WR_Reg(GT_CFGS_REG,(Int8U*)GT911_CFG_TBL,sizeof(GT911_CFG_TBL)-2);//发送寄存器配置
	GT911_WR_Reg(GT_CHECK_REG,buf,2);//写入校验和,和配置更新标记
	return 0;
}  
//向GT911写入一次数据
//reg:起始寄存器地址
//buf:数据缓缓存区
//len:写数据长度
//返回值:0,成功;1,失败.
Int8U GT911_WR_Reg(Int16U reg,Int8U *buf,Int8U len)
{
	Int8U i;
	Int8U ret=0;
	//I2C0_WriteData(unsigned char devadd,unsigned char iadd,unsigned char d)

i2cIoctl(I2CNUM_0, I2C_IOC_SET_SUB_ADDRESS, reg, 2);

	i2cWrite(I2CNUM_0,&buf[0], len);
 
	return ret; 
}
//从GT911读出一次数据
//reg:起始寄存器地址
//buf:数据缓缓存区
//len:读数据长度			  
void GT911_RD_Reg(Int16U reg,Int8U *buf,Int8U len)
{
	Int8U i; 
i2cIoctl(I2CNUM_0, I2C_IOC_SET_SUB_ADDRESS, reg, 2);


	i2cRead(I2CNUM_0, &buf[0], len);

  
} 
//初始化GT911触摸屏
//返回值:0,初始化成功;1,初始化失败 


Int8U GT911_Init(void)
{
	Int8U temp[5]; 

	GT911_RD_Reg(GT_PID_REG,temp,4);//读取产品ID
	temp[4]=0;

	//UART0_SendStr(temp);  
	//printf("CTP ID:%s\r\n",temp);	//打印ID
	if(strcmp((char*)temp,"911")==0)//ID==9147
	{


		
		temp[0]=0X02;			
	//	GT911_WR_Reg(GT_CTRL_REG,temp,1);//软复位GT911
		GT911_RD_Reg(GT_CFGS_REG,temp,1);//读取GT_CFGS_REG寄存器
		if(temp[0]<0X60)//默认版本比较低,需要更新flash配置
		{
		//	UART0_SendStr("Default Ver:%d\r\n");  
					GT911_InitHard();
			//printf("Default Ver:%d\r\n",temp[0]);
			//GT911_Send_Cfg(1);//更新并保存配置
		}
	//	delay_ms(10);
	//	temp[0]=0X00;	 
	//	GT911_WR_Reg(GT_CTRL_REG,temp,1);//结束复位  
		return 0;
	} 
	return 1;
}
const Int16U GT911_TPX_TBL[5]={GT_TP1_REG,GT_TP2_REG,GT_TP3_REG,GT_TP4_REG,GT_TP5_REG};

Int8U GT911_Scan(void)
{
	Int8U bcdbuf[10];
	Int8U buf[4];
	Int8U i=0;
	Int8U res=0;
	Int8U temp;
	Int32U xytemp;
	Int8U mode;

	//	GT911_ReadStatue();
		buf[0]=0;
//		GT911_WR_Reg(GT911_COMMAND_REG, (uint8_t *)buf, 1);
		GT911_RD_Reg(GT_GSTID_REG,&mode,1);//读取触摸点的状态 
		if((mode&0XF)&&((mode&0XF)<6))
		{
			temp=0XFF<<(mode&0XF);//将点的个数转换为1的位数,匹配tp_dev.sta定义 
			tp_dev.sta=(~temp)|TP_PRES_DOWN|TP_CATH_PRES; 
			for(i=0;i<5;i++)
			{
				if(tp_dev.sta&(1<<i))	//触摸有效?
				{
					GT911_RD_Reg(GT911_TPX_TBL[i],buf,4);	//读取XY坐标值
					if(tp_dev.touchtype&0X01)//横屏
					{
						tp_dev.y[i]=((Int16U)buf[1]<<8)+buf[0];
						tp_dev.x[i]=800-(((Int16U)buf[3]<<8)+buf[2]);
					}else
					{
						tp_dev.x[i]=((Int16U)buf[1]<<8)+buf[0];
						tp_dev.y[i]=((Int16U)buf[3]<<8)+buf[2];
						
//						xytemp=((Int32U)tp_dev.x[0]*78125)/100000;
////						bcdbuf[0]=xytemp/100+0x30;
////						bcdbuf[1]=xytemp%100/10+0x30;
////						bcdbuf[2]=xytemp%100%10+0x30;
////						bcdbuf[3]=0;
////						
////						ASCII_Printf(bcdbuf,ASCII1632_MODE,ASCII1632_WIDTH,ASCII1632_HIGH,ASCII1632,100,100,0,0xffff);
						
//						xytemp=((Int32U)tp_dev.y[0]*78125)/100000;
////						bcdbuf[0]=xytemp/100+0x30;
////						bcdbuf[1]=xytemp%100/10+0x30;
////						bcdbuf[2]=xytemp%100%10+0x30;
////						bcdbuf[3]=0;						
////						ASCII_Printf(bcdbuf,ASCII1632_MODE,ASCII1632_WIDTH,ASCII1632_HIGH,ASCII1632,100,136,0,0xffff);
					//	Datas_dis(tp_dev.x[0], 100 , 100  );
					//	Datas_dis(tp_dev.y[0], 100 , 136  );
					}  
					//printf("x[%d]:%d,y[%d]:%d\r\n",i,tp_dev.x[i],i,tp_dev.y[i]);
				}			
			} 
			res=1;
			if(tp_dev.x[0]==0 && tp_dev.y[0]==0)mode=0;	//读到的数据都是0,则忽略此次数据
			
		}
 		if(mode&0X80&&((mode&0XF)<6))
		{
			temp=0;
			GT911_WR_Reg(GT_GSTID_REG,&temp,1);//清标志 		
		}
		
	if(((mode&0XF)==00))//无触摸点按下
	{ 
		if(tp_dev.sta&TP_PRES_DOWN)	//之前是被按下的
		{
			tp_dev.sta&=0;//~(1<<7)|0xfc;	//标记按键松开
		}else						//之前就没有被按下
		{ 
			tp_dev.x[0]=0xffff;
			tp_dev.y[0]=0xffff;
			tp_dev.sta&=0XE0;	//清除点有效标记	
		}	 
	} 		

	
////	if(tp_dev.sta&TP_PRES_DOWN)
////		ASCII_Printf("Down",ASCII1632_MODE,ASCII1632_WIDTH,ASCII1632_HIGH,ASCII1632,100,180,0,0xffff);
////	else
////		ASCII_Printf(" Up ",ASCII1632_MODE,ASCII1632_WIDTH,ASCII1632_HIGH,ASCII1632,100,180,0,0xffff);
	return res;	

}



//扫描触摸屏(采用查询方式)
//mode:0,正常扫描.
//返回值:当前触屏状态.
//0,触屏无触摸;1,触屏有触摸


Int8U GT911_Scan_OLD(Int8U mode)
{
	Int8U bcdbuf[10];
	Int8U buf[4];
	Int8U i=0;
	Int8U res=0;
	Int8U temp;
	Int32U xytemp;
	
	static Int8U t=0;//控制查询间隔,从而降低CPU占用率   
	t++;
	if((t%10)==0||t<10)//空闲时,每进入10次CTP_Scan函数才检测1次,从而节省CPU使用率
	{
	//	GT911_ReadStatue();
		buf[0]=0;
//		GT911_WR_Reg(GT911_COMMAND_REG, (uint8_t *)buf, 1);
		GT911_RD_Reg(GT_GSTID_REG,&mode,1);//读取触摸点的状态 
		if((mode&0XF)&&((mode&0XF)<6))
		{
			temp=0XFF<<(mode&0XF);//将点的个数转换为1的位数,匹配tp_dev.sta定义 
			tp_dev.sta=(~temp)|TP_PRES_DOWN|TP_CATH_PRES; 
			for(i=0;i<5;i++)
			{
				if(tp_dev.sta&(1<<i))	//触摸有效?
				{
					GT911_RD_Reg(GT911_TPX_TBL[i],buf,4);	//读取XY坐标值
					if(tp_dev.touchtype&0X01)//横屏
					{
						tp_dev.y[i]=((Int16U)buf[1]<<8)+buf[0];
						tp_dev.x[i]=800-(((Int16U)buf[3]<<8)+buf[2]);
					}else
					{
						tp_dev.x[i]=((Int16U)buf[1]<<8)+buf[0];
						tp_dev.y[i]=((Int16U)buf[3]<<8)+buf[2];
						
						xytemp=((Int32U)tp_dev.x[0]*78125)/100000;
						bcdbuf[0]=xytemp/100+0x30;
						bcdbuf[1]=xytemp%100/10+0x30;
						bcdbuf[2]=xytemp%100%10+0x30;
						bcdbuf[3]=0;
						
						ASCII_Printf(bcdbuf,ASCII1632_MODE,ASCII1632_WIDTH,ASCII1632_HIGH,ASCII1632,100,100,0,0xffff);
						
						xytemp=((Int32U)tp_dev.y[0]*78125)/100000;
						bcdbuf[0]=xytemp/100+0x30;
						bcdbuf[1]=xytemp%100/10+0x30;
						bcdbuf[2]=xytemp%100%10+0x30;
						bcdbuf[3]=0;						
						ASCII_Printf(bcdbuf,ASCII1632_MODE,ASCII1632_WIDTH,ASCII1632_HIGH,ASCII1632,100,136,0,0xffff);
					//	Datas_dis(tp_dev.x[0], 100 , 100  );
					//	Datas_dis(tp_dev.y[0], 100 , 136  );
					}  
					//printf("x[%d]:%d,y[%d]:%d\r\n",i,tp_dev.x[i],i,tp_dev.y[i]);
				}			
			} 
			res=1;
			if(tp_dev.x[0]==0 && tp_dev.y[0]==0)mode=0;	//读到的数据都是0,则忽略此次数据
			t=0;		//触发一次,则会最少连续监测10次,从而提高命中率
		}
 		if(mode&0X80&&((mode&0XF)<6))
		{
			temp=0;
			GT911_WR_Reg(GT_GSTID_REG,&temp,1);//清标志 		
		}
		
	if(((mode&0XF)==00))//无触摸点按下
	{ 
		if(tp_dev.sta&TP_PRES_DOWN)	//之前是被按下的
		{
			tp_dev.sta&=0;//~(1<<7)|0xfc;	//标记按键松开
		}else						//之前就没有被按下
		{ 
			tp_dev.x[0]=0xffff;
			tp_dev.y[0]=0xffff;
			tp_dev.sta&=0XE0;	//清除点有效标记	
		}	 
	} 		
	}
	
	if(t>100)t=10;//重新从10开始计数
	if(tp_dev.sta&TP_PRES_DOWN)
		ASCII_Printf("Down",ASCII1632_MODE,ASCII1632_WIDTH,ASCII1632_HIGH,ASCII1632,100,180,0,0xffff);
	else
		ASCII_Printf(" Up ",ASCII1632_MODE,ASCII1632_WIDTH,ASCII1632_HIGH,ASCII1632,100,180,0,0xffff);
	return res;
}




Int16U GT911_ReadFirmwareVersion(void)

{

Int8U buf[2];

GT911_RD_Reg(GT911_FIRMWARE_VERSION_REG, buf, 2);

return ((Int16U)buf[1] << 8) + buf[0];

}


void GT911_Soft_Reset(void)

{

uint8_t buf[1];

buf[0] = 0x02;

GT911_WR_Reg(GT911_COMMAND_REG, (uint8_t *)buf, 1);

}



void GT911_InitHard(void)

{
	Int32U n=0;
	Int8U buf[2];

uint8_t config_Checksum = 0,i;

//GT911_Reset_Sequence();


/* I2C总线初始化在 bsp.c 中执行 */

GT911_Soft_Reset(); /*软复位*/
	
	GT911_RD_Reg(GTP_REG_SENSOR_ID, buf, 1);
	


/*读取配置文件版本，计算校验和*/

//s_GT911_CfgParams_new[0] = GT911_ReadStatue();
	
	GT911_Send_Cfg(1);
	/*

for(i=0;i<184;i++)
{
config_Checksum += GT911_CFG_TBL[i];
}

GT911_CFG_TBL[184] = (~config_Checksum)+1;

/// 发送配置信息参数  

GT911_WR_Reg(GT911_CONFIG_REG, (uint8_t *)GT911_CFG_TBL, 184);//sizeof(s_GT911_CfgParams_new));

*/

n=5000000;
while(n--);

GT911_Soft_Reset(); /*软复位*/

buf[0]=0;
GT911_WR_Reg(GT911_COMMAND_REG, (uint8_t *)buf, 1);

/*初始化校准，等待200ms*/


n=5000000;
while(n--);

g_GT911.Enable =1;
}



void GT911_Reset_Sequence(void)

{
int i;
GPIO_SetBit(GPIOG, GTP_INT_PIN);
GPIO_OpenBit(GPIOG, GTP_INT_PIN, DIR_OUTPUT, PULL_UP);


GTP_PD_Low(); //RST引脚低电平

GPIO_SetBit(GPIOG, GTP_INT_PIN);

//GT911_INT_1(); //INT引脚高电平

i=2000000;
while(i--);
i=2000000;
while(i--);
//delays(200000); //延时30ms，最短1

GTP_PD_High(); //RST引脚高电平

GPIO_SetBit(GPIOG, GTP_INT_PIN);


i=2000000;
while(i--);
i=2000000;
while(i--);
//delays(200000); //延时30ms，最短1

GPIO_ClrBit(GPIOG, GTP_INT_PIN);


i=2000000;
while(i--);
i=2000000;
while(i--);
//delays(200000); //延时30ms，最短1

GPIO_SetBit(GPIOG, GTP_INT_PIN);



}


/*
*********************************************************************************************************

*

函 数 名: GT911_Scan

*	功能说明: 读取GT911触摸数据。读取全部的数据。

*	形 参: 无

*	返 回 值: 无

*********************************************************************************************************

*/

/*
void GT911_Scan(void)

{

uint8_t buf[40];

uint8_t Clearbuf = 0;

uint8_t i;

static uint8_t s_tp_down = 0;

if (g_GT911.Enable == 0)

{

return;

}

GT911_RD_Reg(GT911_READ_XY_REG, buf, 1);

//if ((buf[0] & 0x0F) == 0)

//{

////touch release

//GT911_WR_Reg(GT911_CLEARBUF_REG, (uint8_t *)&Clearbuf, 1);

//return;

//}


GT911_RD_Reg(0x8043,&buf[1],1);


GT911_RD_Reg(GT911_READ_XY_REG+1, &buf[1], 39);

GT911_WR_Reg(GT911_CLEARBUF_REG, (uint8_t *)&Clearbuf, 1);



g_GT911.TouchpointFlag = buf[0];

g_GT911.Touchkey1trackid = buf[1];

g_GT911.X1 = ((uint16_t)buf[3] << 8) + buf[2];

g_GT911.Y1 = ((uint16_t)buf[5] << 8) + buf[4];

g_GT911.S1 = ((uint16_t)buf[7] << 8) + buf[6];

g_GT911.Touchkey2trackid = buf[9];

g_GT911.X2 = ((uint16_t)buf[11] << 8) + buf[10];

g_GT911.Y2 = ((uint16_t)buf[13] << 8) + buf[12

];

g_GT911.S2 = ((uint16_t)buf[15] << 8) + buf[14];

g_GT911.Touchkey3trackid = buf[17];

g_GT911.X3 = ((uint16_t)buf[19] << 8) + buf[18];

g_GT911.Y3 = ((uint16_t)buf[21] << 8) + buf[20];

g_GT911.S3 = ((uint16_t)buf[23] << 8) + buf[22];

g_GT911.Touchkey4trackid = buf[25];

g_GT911.X4 = ((uint16_t)buf[27] << 8) + buf[26];

g_GT911.Y4 = ((uint16_t)buf[29] << 8) + buf[28];

g_GT911.S4 = ((uint16_t)buf[31] << 8) + buf[30];

g_GT911.Touchkey5trackid = buf[33];

g_GT911.X5 = ((uint16_t)buf[35] << 8) + buf[34];

g_GT911.Y5 = ((uint16_t)buf[37] << 8) + buf[36];

g_GT911.S5 = ((uint16_t)buf[39] << 8) + buf[38];

if (s_tp_down == 0)

{

s_tp_down = 1;

//touch down

}

else

{

//touch move

}


}

*/