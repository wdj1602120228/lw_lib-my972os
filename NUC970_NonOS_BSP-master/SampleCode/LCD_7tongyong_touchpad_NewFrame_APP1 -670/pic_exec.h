


#ifndef _PIC_EXEC_H
#define _PIC_EXEC_H

#include"main.h"
#include "file.h"



#define TOUCH_ENB 0
extern unsigned int  DisWuCha;

#define F1_4_WIDE	48
#define F1_4_HIGH	48

#define F_KEY_WIDE	56
#define F_KEY_HIGH	46

#define FORWARD_WIDE	F1_4_WIDE
#define FORWARD_HIGH	F1_4_HIGH

#define DELETE_WIDE		82
#define DELETE_HIGH		31
//-------计数器 弹出框
#define CALCUL_WIN_X	325//320
#define CALCUL_WIN_Y	105
#define CALCUL_WIDE		472//412
#define CALCUL_HIGH		336//280
#define CALCUL_COLOR	0x879e

#define CALCUL_TEXT_X	(CALCUL_WIN_X+5)
#define CALCUL_TEXT_Y	(CALCUL_WIN_Y+5)
#define CALCUL_TEXT_H	30
#define CALCUL_TEXT_W	450//390
#define CALCUL_TEXT_END	(CALCUL_TEXT_X+CALCUL_TEXT_W-12)

#define CALCUL_RESULT_X	(CALCUL_TEXT_X+160)
#define CALCUL_RESULT_Y	(CALCUL_TEXT_Y+CALCUL_TEXT_H+5)
#define CALCUL_RESULT_H	30
#define CALCUL_RESULT_W	275//225
//
#define BUTT_WIDE	75//65
#define BUTT_HIGH	60//55//45
#define BUTT_GAP1	5
#define BUTT_GAP2	5
#define BUTT_X1		(CALCUL_WIN_X+5)
#define BUTT_X2		(BUTT_X1+BUTT_WIDE+BUTT_GAP1)
#define BUTT_X3		(BUTT_X2+BUTT_WIDE+BUTT_GAP1)
#define BUTT_X4		(BUTT_X3+BUTT_WIDE+BUTT_GAP1)
#define BUTT_X5		(BUTT_X4+BUTT_WIDE+BUTT_GAP1)
#define BUTT_X6		(BUTT_X5+BUTT_WIDE+BUTT_GAP1)


#define BUTT_Y1		(CALCUL_RESULT_Y+30+5)
#define BUTT_Y2		(BUTT_Y1+BUTT_HIGH+BUTT_GAP2)
#define BUTT_Y3		(BUTT_Y2+BUTT_HIGH+BUTT_GAP2)
#define BUTT_Y4		(BUTT_Y3+BUTT_HIGH+BUTT_GAP2)
#define BUTT_Y5		(BUTT_Y4+BUTT_HIGH+BUTT_GAP2)
//方向箭头
#define BUTT_WIDE_ARROW	60//50
#define BUTT_HIGH_ARROW	125//95

//--------软键盘 按钮定义
#define BUTT_INSERT	0
#define BUTT_EXIT	1
#define BUTT_EQU	2
#define BUTT_ENTER	3
#define BUTT_RUN	4
#define BUTT_CLEAR	5
#define BUTT_DOT	6
#define BUTT_MUL	7
#define BUTT_DIV	8
#define BUTT_PLUS	9
#define BUTT_0	10
#define BUTT_1	11
#define BUTT_2	12
#define BUTT_3	13
#define BUTT_4	14
#define BUTT_5	15
#define BUTT_6	16
#define BUTT_7	17
#define BUTT_8	18
#define BUTT_9	19
#define BUTT_SUB	20
#define BUTT_UP		21
#define BUTT_DOWN	22

// #define BUTT_SPAC	23
#define BUTT_LEFT	23
#define BUTT_RIGHT	24

//----输入法 定义
#define NUMBER_INPUT	0
#define CHAR_INPUT		1
#define PINYIN_INPUT	2



#define PRO_MESS_COLOR1 0xFF5b
#define PRO_MESS_COLOR2 0xFFff


#define PROC_NUM_Y	(10+10)

#define PRO_MESS_X		45//70
#define PRO_MESS_Y		(PROC_NUM_Y-35)
#define PRO_MESS_WIDE	650
#define PRO_MESS_HIGH	270

#define INPUT_NAME_WIN_X	(PRO_MESS_X+330)
#define INPUT_NAME_WIN_Y	(PRO_MESS_Y+40)
#define INPUT_NAME_WIDE		315
#define INPUT_NAME_HIGH		50

#define INPUT_SEL_X		(INPUT_NAME_WIN_X+10)
#define INPUT_SEL_Y		(INPUT_NAME_WIN_Y+INPUT_NAME_HIGH+5)
#define INPUT_SEL_GAP	30
#define INPUT_SEL_ROW	4

#define INPUT_WORD_COL	10
#define INPUT_WORD_GAP	30
#define INPUT_LIB_X		INPUT_SEL_X
#define INPUT_LIB_Y		(INPUT_SEL_Y+INPUT_SEL_GAP*4+5)


//------------文件缓存地址--------
#define  PIC_DIS_SAVE1		(DOWNFILE_SDRAM_ADD+0x200000)//0xa0400000    //当前显示区块 暂存区1
#define  PIC_DIS_SAVE2		(PIC_DIS_SAVE1+0x100000)//0xa047d000    //当前显示区块 暂存区2
#define  PIC_DIS_SAVE3		(PIC_DIS_SAVE2+0x100000)//0xa0500000    //当前显示区块 暂存区3
#define  PIC_DIS_SAVE4		(PIC_DIS_SAVE3+0x100000)//0xa057d000    //当前显示区块 暂存区4


#define  df_zk_sdram        (PIC_DIS_SAVE4+0x100000)//0xa0600000             //字库2M

#define  START_PIC_sdram   (df_zk_sdram+0x200000)  //0xa0600000         //开机图片
#define  WOEK_BACK_dis     (START_PIC_sdram+1152100)        //工作背景

#define  PROGRAM_sdram      (WOEK_BACK_dis+1152100) //编程
#define  LABELS_sdram       (PROGRAM_sdram+27700)  //标签
#define  PARAMETER_sdram    (LABELS_sdram+27700)  //参数
#define  RULER_sdram        (PARAMETER_sdram+27700)//尺
#define  DIVIDE_sdram		(RULER_sdram+27700)   //等分
#define  WATCH_sdram		(DIVIDE_sdram+27700)   //时钟
#define  TEACH_sdram		(WATCH_sdram+27700)   //示教
#define  MANUAL_sdram		(TEACH_sdram+27700)   //手动
#define  AUTO_sdram		    (MANUAL_sdram+27700)   //自动
#define  SELECT_PRO_sdram	(AUTO_sdram+27700)   //选择程序
#define  AUTO_KNIFE_sdram   (SELECT_PRO_sdram+27700)   //自刀
#define  PULSE_DEGREE_sdram   (AUTO_KNIFE_sdram+27700)   //脉冲当量
#define  LOCK_sdram   		(PULSE_DEGREE_sdram+27700)   //锁

#define  LABEL_FUN_sdram	(LOCK_sdram+27700)//标签功能
#define  PROCESS_sdram		(LABEL_FUN_sdram+190800) //程序
#define  TOOLS_sdram		(PROCESS_sdram+190800) //工具
#define  DIVIDE_FUN_sdram	(TOOLS_sdram+190800) //等分功能
#define  RULER_FUN_sdram		(DIVIDE_FUN_sdram+190800) //基准功能
#define  CALENDAR_sdram		(RULER_FUN_sdram+190800) //日历
#define  LOCK_KEY_sdram		(CALENDAR_sdram+190800) //锁 钥匙

#define  F1UP_sdram			(LOCK_KEY_sdram+190800)//F1up
#define  F2UP_sdram			(F1UP_sdram+6970)//F1up
#define  F3UP_sdram			(F2UP_sdram+6970)//F1up
#define  F4UP_sdram			(F3UP_sdram+6970)//F1up
#define  FINISHED_sdram		(F4UP_sdram+6970)//完成
#define  F2_OUT_UP_sdram	(FINISHED_sdram+6970) //F2退出up
#define  F1_RULER_UP_sdram	(F2_OUT_UP_sdram+6970)//F1尺子up
#define  F2_TOOLS_UP_sdram	(F1_RULER_UP_sdram+6970)//F2工具up

//新加，手动状态下  F1 工具   F2 尺寸
#define  F1_Manual_TOOLS_UP_sdram	(F2_TOOLS_UP_sdram+6970)//F1工具up
#define  F2_Manual_RULER_UP_sdram	(F1_Manual_TOOLS_UP_sdram+6970)//F2尺子up


#define  F3_PLUS_UP_sdram	(F2_Manual_RULER_UP_sdram+6970)//F3++up
#define  F3_CLOCK_UP_sdram	(F3_PLUS_UP_sdram+6970)//F3时钟up
#define  F4_MINUS_UP_sdram	(F3_CLOCK_UP_sdram+6970)//F4--up
#define  F5_CUT_UP_sdram	(F4_MINUS_UP_sdram+6970)//F5刀
#define  L_R_ARROW_sdram	(F5_CUT_UP_sdram+6970)//左右箭头
#define  TEACH_MOD_sdram	(F5_CUT_UP_sdram+6970)//示教模式
#define  AUTO_KNIFE_MOD_sdram	(TEACH_MOD_sdram+12100)//自刀模式

#define  KNIFE_UP_sdram		(AUTO_KNIFE_MOD_sdram+12100)//刀上
#define  KNIFE_DOWN_sdram	(KNIFE_UP_sdram+7340)//刀下
#define  PRESS_UP_sdram		(KNIFE_DOWN_sdram+7340)//压上
#define  PRESS_DOWN_sdram	(PRESS_UP_sdram+7340)//压下

#define  RED_A_sdram		(PRESS_DOWN_sdram+7340)  //红色A
#define  RED_B_sdram		(RED_A_sdram+6200)  //红色B
#define  BLACK_A_sdram		(RED_B_sdram+6200)  //黑色A
#define  BLACK_B_sdram		(BLACK_A_sdram+6200)  //黑色B
#define  RED_LINE_sdram		(BLACK_B_sdram+6200)   //红线
#define  HAND_IR_sdram		(RED_LINE_sdram+6200) //手 红外

#define  FRONT_KNIFE_sdram	(HAND_IR_sdram+6200)//刀前
#define  RED_KNIFE_F_sdram	(FRONT_KNIFE_sdram+3050)//红刀
#define  PUSH_PAPER_F_sdram (RED_KNIFE_F_sdram+1200)//推纸
#define	 PRE_AUTO_F_sdram		(PUSH_PAPER_F_sdram+1785)//k 自动循环---------------------------------

#define  SCHEDULE_sdram		(PRE_AUTO_F_sdram+1256)//进度
#define  SCHEDULE_DOT_sdram	(SCHEDULE_sdram+16700)//进度位置
#define  RIGHT_ARROW_sdram	(SCHEDULE_DOT_sdram+600)// 右箭头 -->
#define  TIME_COL_sdram		(RIGHT_ARROW_sdram+720) //时间条
#define  PUSH_PAPER_TOOL_sdram	(TIME_COL_sdram+75910) //推纸器

#define  CANCEL_UP_sdram  	(PUSH_PAPER_TOOL_sdram+98648) //取消up
#define  CANCEL_DOWN_sdram  (CANCEL_UP_sdram+7750) //取消down
#define  ENTER_UP_sdram		(CANCEL_DOWN_sdram+7750)//确定up
#define  ENTER_DOWN_sdram	(ENTER_UP_sdram+7750)//确定down
#define  STOP_UP_sdram		(ENTER_DOWN_sdram+7750)//停止up
#define  STOP_DOWN_sdram	(STOP_UP_sdram+7750)//停止down
#define  RUN_UP_sdram		(STOP_DOWN_sdram+7750)//运行up
#define  RUN_DOWN_sdram		(RUN_UP_sdram+7750)//运行down

#define  INPUT_SIZE_sdram	(RUN_DOWN_sdram+7750) //输入尺寸
#define  REMIND_sdram		(INPUT_SIZE_sdram+9900)//提示栏

#define  PUSH_KNIFE_sdram	(REMIND_sdram+9900) //推纸/刀
#define  POSITION_sdram		(PUSH_KNIFE_sdram+5700)//位置
#define  ORDER_sdram		(POSITION_sdram+5700)  //序号

#define  MIDDLE_PAGE_sdram	(ORDER_sdram+5700)//中间活页
#define  LEFT_PAGE_sdram	(MIDDLE_PAGE_sdram+693656)// 左边活页

#define  DELETE_UP_sdram		(LEFT_PAGE_sdram+693656)//删除up
#define  DELETE_ALL_UP_sdram	(DELETE_UP_sdram+8000)//全删up
#define  PEAR_sdram			(DELETE_ALL_UP_sdram+8000)//鸭梨

#define  F_KEY_UP_sdram		(PEAR_sdram+86940) //F键up
#define  FRONT_PAGE_UP_sdram	(F_KEY_UP_sdram+7785)//前进up
#define  BACK_PAGE_UP_sdram		(FRONT_PAGE_UP_sdram+6970)//后退
#define  UP_ARROW_UP_sdram		(BACK_PAGE_UP_sdram+6970)//上箭头up
#define  DOWN_ARROW_UP_sdram		(UP_ARROW_UP_sdram+6970)//下箭头up
#define  FAST_FORWD_UP_sdram	(DOWN_ARROW_UP_sdram+6970)	//快进up
#define  FAST_BACK_UP_sdram		(FAST_FORWD_UP_sdram+6970) 	//快退up
#define  F5_PRE_FLG_BUTT_UP_sdram (FAST_BACK_UP_sdram+6970)//压纸 循环button

#define	 F4_WHEEL0_sdram		(F5_PRE_FLG_BUTT_UP_sdram+6970) //电子手轮开关0
#define	 F4_WHEEL1_sdram		(F4_WHEEL0_sdram+6970) //电子手轮开关1
#define  WHEEL0_sdram		(F4_WHEEL1_sdram+6970)//手轮关0
#define  WHEEL1_sdram		(WHEEL0_sdram+12345)//手轮开1
// #define  test_sdram		(WHEEL1_sdram+12345)//手轮开1

#define  F0_YESALLCUT_sdram		(WHEEL1_sdram+12345)//F0 all刀标记+
#define  F0_NOALLCUT_sdram		(F0_YESALLCUT_sdram+7750)//F0 all刀标记-
#define  F5_YESCUT_sdram	(F0_NOALLCUT_sdram+7750)//F5 刀标记+
#define  F5_NOCUT_sdram		(F5_YESCUT_sdram+7750)//F5 刀标记-

//+++++++++++english
#define  PROGRAM_EN_sdram	(F5_NOCUT_sdram+7750)
#define  LABELS_EN_sdram       (PROGRAM_EN_sdram+27700)  //标签
#define  PARAMETER_EN_sdram    (LABELS_EN_sdram+27700)  //参数
#define  BENCH_EN_sdram        (PARAMETER_EN_sdram+27700)//基准
#define  DIVIDE_EN_sdram		(BENCH_EN_sdram+27700)   //等分
#define  WATCH_EN_sdram		(DIVIDE_EN_sdram+27700)   //时钟
#define  TEACH_EN_sdram		(WATCH_EN_sdram+27700)   //示教
#define  MANUAL_EN_sdram		(TEACH_EN_sdram+27700)   //手动
#define  AUTO_EN_sdram		    (MANUAL_EN_sdram+27700)   //自动
#define  SELECT_PRO_EN_sdram	(AUTO_EN_sdram+27700)   //选择程序
#define  AUTO_KNIFE_EN_sdram   (SELECT_PRO_EN_sdram+27700)   //自刀
#define  PULSE_DEGREE_EN_sdram   (AUTO_KNIFE_EN_sdram+27700)   //脉冲当量
#define  LOCK_EN_sdram   		(PULSE_DEGREE_EN_sdram+27700)   //锁

#define  LABEL_FUN_EN_sdram	(LOCK_EN_sdram+27700)//标签功能
#define  PROCESS_EN_sdram		(LABEL_FUN_EN_sdram+190800) //程序
#define  TOOLS_EN_sdram		(PROCESS_EN_sdram+190800) //工具
#define  DIVIDE_FUN_EN_sdram	(TOOLS_EN_sdram+190800) //等分功能
#define  RULER_FUN_EN_sdram		(DIVIDE_FUN_EN_sdram+190800) //基准功能
#define  CALENDAR_EN_sdram		(RULER_FUN_EN_sdram+190800) //日历
#define  LOCK_KEY_EN_sdram		(CALENDAR_EN_sdram+190800) //锁 钥匙

#define  INPUT_SIZE_EN_sdram	(LOCK_KEY_EN_sdram+190800) //输入尺寸
#define  REMIND_EN_sdram		(INPUT_SIZE_EN_sdram+9900)//提示栏

#define  PUSH_KNIFE_EN_sdram	(REMIND_EN_sdram+9900) //推纸/刀
#define  POSITION_EN_sdram		(PUSH_KNIFE_EN_sdram+5700)//位置
#define  ORDER_EN_sdram		(POSITION_EN_sdram+5700)  //序号
//+++++++++++english

//---------------------------------
#define  K_SIZE_sdram		(ORDER_EN_sdram+5700)//0x82000000       //刀数据 缓存区


//**************图片显示位置定义*******
#define WORKMODE_WIDE	137
#define WORKMODE_HIGH	67
//编程
#define  PROGRAM_X		640
#define  PROGRAM_Y		400
//标签
#define  LABELS_X		PROGRAM_X
#define  LABELS_Y		PROGRAM_Y
//参数
#define  PARAMETER_X	PROGRAM_X
#define  PARAMETER_Y	PROGRAM_Y
//尺
#define  RULER_X	PROGRAM_X
#define  RULER_Y	PROGRAM_Y
//等分
#define  DIVIDE_X	PROGRAM_X
#define  DIVIDE_Y	PROGRAM_Y
//时钟
#define  WATCH_X	PROGRAM_X
#define  WATCH_Y	PROGRAM_Y
//示教
#define  TEACH_X	PROGRAM_X
#define  TEACH_Y	PROGRAM_Y
//手动
#define  MANUAL_X	PROGRAM_X
#define  MANUAL_Y	PROGRAM_Y
 //自动
#define  AUTO_X	  	PROGRAM_X
#define  AUTO_Y		PROGRAM_Y 
//选择程序
#define  SELECT_PRO_X	  	PROGRAM_X
#define  SELECT_PRO_Y		PROGRAM_Y 
//自刀
#define  SELF_KNIFE_X	  	PROGRAM_X
#define  SELF_KNIFE_Y		PROGRAM_Y 
//脉冲当量
#define  PULSE_DEG_X		PROGRAM_X
#define  PULSE_DEG_Y		PROGRAM_Y
//锁
#define  LOCK_X			PROGRAM_X
#define  LOCK_Y			PROGRAM_Y

//标签功能-------------------------
#define  LABEL_FUN_X	  	360
#define  LABEL_FUN_Y		141
//程序
#define  PROCESS_X	  	LABEL_FUN_X
#define  PROCESS_Y		LABEL_FUN_Y
//工具
#define  TOOLS_X	  	LABEL_FUN_X
#define  TOOLS_Y	  	LABEL_FUN_Y
//等分功能
#define  DIVIDE_FUN_X	  	LABEL_FUN_X
#define  DIVIDE_FUN_Y	  	LABEL_FUN_Y
//基准功能
#define  RULER_FUN_X	  	LABEL_FUN_X
#define  RULER_FUN_Y	  	LABEL_FUN_Y
//日历
#define  CALENDA_X	  	LABEL_FUN_X
#define  CALENDA_Y	  	LABEL_FUN_Y
//锁 钥匙
#define  LOCK_KEY_X		LABEL_FUN_X
#define  LOCK_KEY_Y		LABEL_FUN_Y

//F1up-------------------
#define  F1_X	  	730
#define  F1_Y		140
//F2up
#define  F2_X	  	F1_X
#define  F2_Y		(F1_Y+58)
//F3up
#define  F3_X	  	F1_X
#define  F3_Y		(F2_Y+58)
//F4up
#define  F4_X	  	F1_X
#define  F4_Y		(F3_Y+58)
//完成up
#define  FINISHED_X	  	650
#define  FINISHED_Y		140
//F2退出up
#define  F2OUT_X		FINISHED_X
#define  F2OUT_Y		(FINISHED_Y+80)
//左右箭头
#define  L_R_ARROW_X	FINISHED_X
#define  L_R_ARROW_Y	(F2OUT_Y+80)
//子菜单 向上
#define  SUB_UP_ARROW_X	(FINISHED_X+80)
#define  SUB_UP_ARROW_Y	 F2OUT_Y
//子菜单 向下
#define  SUB_DOWN_ARROW_X	SUB_UP_ARROW_X
#define  SUB_DOWN_ARROW_Y	L_R_ARROW_Y

//示教模式
#define  TEACH_MOD_X		500
#define  TEACH_MOD_Y		250
//自刀模式
#define  AUTO_KNIFE_MOD_X		500
#define  AUTO_KNIFE_MOD_Y		250

//刀上
#define  KNIFE_X		550
#define  KNIFE_Y		140
//刀下
#define  KNIFE_DOWN_X		KNIFE_X
#define  KNIFE_DOWN_Y		KNIFE_Y

//刀上1
#define  KNIFE1_X		480
#define  KNIFE1_Y		140
//刀下1
#define  KNIFE1_DOWN_X		KNIFE1_X
#define  KNIFE1_DOWN_Y		KNIFE1_Y

//压上
#define  PRESS_X		(KNIFE_X+60)
#define  PRESS_Y		(KNIFE_Y)
//压下
#define  PRESS_DOWN_X		(PRESS_X)
#define  PRESS_DOWN_Y		(PRESS_Y)


//红色A
#define  RED_A_X		570
#define  RED_A_Y		250
//黑色A
#define  BLACK_A_X		RED_A_X
#define  BLACK_A_Y		RED_A_Y
//红色B
#define  RED_B_X		(RED_A_X+50)
#define  RED_B_Y		RED_A_Y
//黑色B
#define  BLACK_B_X		RED_B_X
#define  BLACK_B_Y		RED_B_Y
//手红外
#define  HAND_IR_X		520
#define  HAND_IR_Y		RED_A_Y

//红线
#define  RED_LINE_X		HAND_IR_X
#define  RED_LINE_Y		HAND_IR_Y

//刀前
#define  FRONT_KNIFE_X	450//470
#define  FRONT_KNIFE_Y	61//65
//红刀
#define  RED_KNIFE_X	350//320
#define  RED_KNIFE_Y	160
#define  PUSH_FLAG_X	RED_KNIFE_X
#define  PUSH_FLAG_Y	RED_KNIFE_Y
//进度
#define  SCHEDULE_X		692
#define  SCHEDULE_Y		125//120
//进度块
#define  SCHEDULE_DOT_X	700
#define  SCHEDULE_DOT_Y	148//143
//#define  SCHEDULE_DOT_Y	161
//右箭头-->
#define  RIGHT_ARROW_X	55//75//80
#define  RIGHT_ARROW_Y	145
//时间条
#define  TIME_COL_X		10
#define  TIME_COL_Y		5
//推纸器
#define  PUSH_PAPER_TOOL_X	425
#define  PUSH_PAPER_TOOL_Y	0

//运行up
#define  RUN_X		270
#define  RUN_Y		400
/*
//运行down
#define  RUN_DOWN_X		RUN_X
#define  RUN_DOWN_Y		RUN_Y
//停止up
#define  STOP_X		(RUN_X+95)
#define  STOP_Y		RUN_Y
//停止down
#define  STOP_DOWN_X	STOP_X
#define  STOP_DOWN_Y	STOP_Y
//取消up
#define  CANCEL_X	(STOP_X+100)
#define  CANCEL_Y	RUN_Y
//取消down
#define  CANCEL_DOWN_X	CANCEL_X
#define  CANCEL_DOWN_Y	CANCEL_Y
//确定up
#define  ENTER_X		CANCEL_X
#define  ENTER_Y		(CANCEL_Y+45)
//确定down
#define  ENTER_DOWN_X	ENTER_X
#define  ENTER_DOWN_Y	ENTER_Y
*/
//输入尺寸
#define  INPUT_SIZE_X	10
#define  INPUT_SIZE_Y	400
//提示栏
#define  REMIND_X		INPUT_SIZE_X
#define  REMIND_Y		(INPUT_SIZE_Y+45)
//推纸——刀
#define  PUSH_KNIFE_X	320//280
#define  PUSH_KNIFE_Y	107//116
//位置
#define  POSITION_X		190//170
#define  POSITION_Y		PUSH_KNIFE_Y
//序号
#define  ORDER_X		60
#define  ORDER_Y		PUSH_KNIFE_Y

//中间活页
#define  MIDDLE_PAGE_X	0
#define  MIDDLE_PAGE_Y	104//112
//左边活页
#define  LEFT_PAGE_X	0
#define  LEFT_PAGE_Y	MIDDLE_PAGE_Y

//----------------活页大小
#define  M_PAGE_WIDE	800
#define  M_PAGE_HIGH	289
//尺寸输入框
#define  SIZE_WINDOW_X	130
#define  SIZE_WINDOW_Y	INPUT_SIZE_Y
#define  SIZE_WINDOW_WIDE	120
#define  SIZE_WINDOW_HIGH	30
//提示框
#define  REMIND_WINDOW_X	SIZE_WINDOW_X
#define  REMIND_WINDOW_Y	REMIND_Y
#define  REMIND_LENGTH		380  //提示框长度

#define  RIGHT_PAGE_X	360//380  //右边页 起始位置
//故障提示框大小
#define  START_PROM_WIDE	600
#define  START_PROM_HIGH	30
//开机第一行故障 提示
#define	 START_PROMPT_X1	REMIND_WINDOW_X
#define	 START_PROMPT_Y1	(REMIND_WINDOW_Y-50)
//推纸器复位 提示
#define  PUSH_RESET_PROMPT_X1	200
#define  PUSH_RESET_PROMPT_Y1	50
#define  PUSH_RESET_PROMPT_WIDE	450
#define  PUSH_RESET_PROMPT_HIGH	80
#define  PUSH_RESET_OK_X		(PUSH_RESET_PROMPT_X1+50)
#define  PUSH_RESET_OK_Y		(PUSH_RESET_PROMPT_Y1+50)
#define  PUSH_RESET_CANCEL_X	(PUSH_RESET_OK_X+200)
#define  PUSH_RESET_CANCEL_Y	PUSH_RESET_OK_Y
//*************注释区域
#define  COMMENT_X		20//起点
#define  COMMENT_Y		50
#define  COMMENT_H		650//宽
#define  COMMENT_V		425//高

#define  PROG_X		40//程序
#define  PROG_Y		76//80
#define  STEP_X		(PROG_X+200)//步骤
#define  STEP_Y		PROG_Y

#define  PROG_NUM_X		(PROG_X+100)//程序号
#define  PROG_NUM_Y		PROG_Y
#define  STEP_NUM_X		(STEP_X+60)//步骤号
#define  STEP_NUM_Y		PROG_Y


//标签页
#define TOTAL_SIZE_X 	220
#define TOTAL_SIZE_Y 	200

#define LABEL_SIZE_X 	TOTAL_SIZE_X
#define LABEL_SIZE_Y 	(TOTAL_SIZE_Y+50)

#define WASTE_SIZE_X 	TOTAL_SIZE_X
#define WASTE_SIZE_Y 	(LABEL_SIZE_Y+50)
//---等分页
#define DIVIDE_TOTAL_X	220
#define DIVIDE_TOTAL_Y	200
#define DIVIDE_NUM_X	DIVIDE_TOTAL_X//等分数
#define DIVIDE_NUM_Y	(DIVIDE_TOTAL_Y+60)

//鸭梨
#define  PEAR_X		330
#define  PEAR_Y		140
//F1尺子up
#define  F1_RULER_X	 F1_X
#define  F1_RULER_Y	 F1_Y
//F2工具up
#define  F2_TOOLS_X	 F2_X
#define  F2_TOOLS_Y	 F2_Y
//F3++up
#define  F3_PLUS_X	 F3_X
#define  F3_PLUS_Y	 F3_Y
//F3时钟up
#define  F3_CLOCK_X	 F3_X
#define  F3_CLOCK_Y	 F3_Y
//F4--up
#define  F4_MINUS_X	 F4_X
#define  F4_MINUS_Y	 F4_Y
//F5单刀
#define  F5_CUTYES_X	450
#define  F5_CUTYES_Y	200
#define  F5_CUTNO_X		F5_CUTYES_X
#define  F5_CUTNO_Y		F5_CUTYES_Y
//F0所有刀
#define  F0_CUTYES_X	(F5_CUTYES_X+130)
#define  F0_CUTYES_Y	F5_CUTYES_Y
#define  F0_CUTNO_X		F0_CUTYES_X
#define  F0_CUTNO_Y		F0_CUTYES_Y

//删除up
#define  DELETE_X		270
#define  DELETE_Y		400
//全删up
#define  DELETE_ALL_X	(DELETE_X+95)
#define  DELETE_ALL_Y	DELETE_Y
//停止up
#define  STOP_X		(DELETE_ALL_X+95)
#define  STOP_Y		DELETE_Y
//停止down
#define  STOP_DOWN_X	STOP_X
#define  STOP_DOWN_Y	STOP_Y

//F键up
#define  F_KEY_X		560
#define  F_KEY_Y		420
//前一页up
#define	 FRONT_PAGE_X	440
#define	 FRONT_PAGE_Y	315
//后一页up
#define	 BACK_PAGE_X	(FRONT_PAGE_X+60)
#define	 BACK_PAGE_Y	FRONT_PAGE_Y
//上箭头up
#define  UP_ARROW_X		(BACK_PAGE_X+60)
#define  UP_ARROW_Y		FRONT_PAGE_Y
//下箭头up
#define  DOWN_ARROW_X	(UP_ARROW_X+60)
#define  DOWN_ARROW_Y	FRONT_PAGE_Y
//手动模式   下    前进
#define  MAN_FRONT_PAGE_X	100
#define  MAN_FRONT_PAGE_Y	150//200
//手动模式   下   后退键
#define  MAN_BACK_PAGE_X	(MAN_FRONT_PAGE_X+100)
#define  MAN_BACK_PAGE_Y	MAN_FRONT_PAGE_Y
//快进
#define  MAN_FAST_FWD_X		MAN_FRONT_PAGE_X
#define  MAN_FAST_FWD_Y		(MAN_FRONT_PAGE_Y+90)
//快退
#define	 MAN_FAST_BACK_X	(MAN_FAST_FWD_X+100)
#define	 MAN_FAST_BACK_Y	MAN_FAST_FWD_Y

//手动模式   下	停止
#define	 MAN_STOP_X		(MAN_FRONT_PAGE_X+30)
#define	 MAN_STOP_Y		(MAN_FAST_FWD_Y+80)

//F5 压纸循环button
#define F5_PRE_FLG_X	F0_CUTYES_X
#define F5_PRE_FLG_Y	(F0_CUTYES_Y+45)


#define	 F4_WHEEL_X		F4_X  //F4电子手轮  
#define	 F4_WHEEL_Y		F4_Y

#define  WHEEL_STA_X	440  //电子手轮 开启/关闭 指示
#define  WHEEL_STA_Y	240	


//*************
#define CURR_SIZE_X		470//490 //当前尺寸 显示位置
#define CURR_SIZE_Y		5
#define FRONT_KNIF_X	500//535
#define FRONT_KNIF_Y	FRONT_KNIFE_Y
//------------参数页
#define PARA_START_X1		70
#define PARA_START_X2		220
#define PARA_START_Y		150
#define PARA_COL_WIDE		300
//--
#define PULSE_SET_X1		60
#define PULSE_SET_X2		360
#define PULSE_SET_Y		150

//------passcode 界面
#define PASSCODE_X		220
#define PASSCODE_Y		240
#define PASSCODE_INPUT_X	(PASSCODE_X+100)
#define PASSCODE_INPUT_Y	(PASSCODE_Y+50)
//******自刀提示
#define SELF_PROMP_X	100
#define SELF_PROMP_Y	200
//自刀OK
#define SELF_OK_X		(SELF_PROMP_X+20)
#define SELF_OK_Y		(SELF_PROMP_Y+75)
#define SELF_OK_WIDE	110
#define SELF_OK_HIGH	40
//自刀 取消
#define SELF_CANCEL_X	(SELF_OK_X+140)
#define SELF_CANCEL_Y	SELF_OK_Y
//--开机 run 提示
#define RUN_DIS_X		550
#define RUN_DIS_Y		REMIND_WINDOW_Y


#define MOV_DIR_X	700//运行方向指示
#define MOV_DIR_Y	65








//模式-----------------------
#define PROG_MODE		0x10//编程模式
#define AUTO_MODE		0x20//
#define MANUAL_MODE		0x30
#define TEACH_MODE		0x40
#define SELF_CUT_MODE	0x50
#define HELP_MODE		0x60

//编程子模式
#define PROG_LABEL_MODE		0x11//标签
#define PROG_DIVIDE_MODE	0x12//等分
#define PROG_PRO_MODE		0x13//程序选择
#define PROG_PRO_MESS_MODE	0x131//程序 信息
#define PROG_DEL_ALL_PRO_MODE	0x132//	删除所有pro
#define PROG_DEL_ALL_SIZE_MODE	0x133//	删除所有尺寸


//自动子模式
#define AUTO_RULER_MODE  0x21//基准
#define AUTO_TOOLS_MODE  0x22 //参数
#define AUTO_PLUS_MODE   0x23//F3++
#define AUTO_MINUS_MODE  0x24//F4--
#define AUTO_TO_SELF_MODE 0x25
//手动子模式
#define MANUAL_RULER_MODE  0x31//基准
#define MANUAL_TOOLS_MODE  0x32//
#define MANUAL_CLOCK_MODE  0x33
#define MANUAL_PULSE_MODE  0x34//设定脉冲当量
#define MANUAL_PASS_MODE   0x35//密码
#define MANUAL_SERVO_C_MODE   0x36//直流伺服 C 参数
//示教子模式
#define TEACH_LABEL_MODE	0x41//标签
#define TEACH_DIVIDE_MODE	0x42//等分
#define TEACH_PRO_MODE		0x43//程序选择
//自刀子模式
#define SELF_RULER_MODE  0x51//基准
#define SELF_TOOLS_MODE  0x52 //参数
#define SELF_PLUS_MODE   0x53//F3++
#define SELF_MINUS_MODE  0x54//F4--

//单位
#define UNIT_MM		0//公
#define UNIT_MIL	1//英
//语言
#define CHN_HAN    0
#define ENGLISH    1
#define INDONSIA   3
#define PORTUGAL   2
#define SPANISH	   4

#define FRENCH   5



//极限
#define FRONT_LIM_MIN		(15*100)
#define FRONT_LIM_MAX		(80*100)
//#define FRONT_LIM_MIN_in	(590)
//#define FRONT_LIM_MAX_in	(3149)

#define MIDD_LIM_MIN		(30*100)
#define MIDD_LIM_MAX		(150*100)
//#define MIDD_LIM_MIN_in		(1181)
//#define MIDD_LIM_MAX_in		(5905)

#define BACK_LIM_MIN		(600*100)
#define BACK_LIM_MAX		(2200*100)
//#define BACK_LIM_MIN_in		(23622)
//#define BACK_LIM_MAX_in		(86614)
#define AUTO_PUSH_DISTAN	(500*100)
#define AUTO_PUSH_NO		(10*100)

#define MARGIN_SIZE		40//25
#define DC_VIRTURE_SIZE 1500

//---------------------触摸 十字
#define TOUCH_X1	40
#define TOUCH_Y1	40

#define TOUCH_X2	TOUCH_X1
#define TOUCH_Y2	440

#define TOUCH_X3	760
#define TOUCH_Y3	TOUCH_Y2

#define TOUCH_X4	TOUCH_X3
#define TOUCH_Y4	TOUCH_Y1

#define TOUCH_X_MID	(C_GLCD_H_SIZE>>1)
#define TOUCH_Y_MID	(C_GLCD_V_SIZE>>1)

//---计算器 text
#define CAL_INPUT	0  //数字输入框
#define CAL_RESULT	1   //结果框


//-----------主板控制类型
#define  MOTOR_FREQ_5_SPD_RST	0  //变频器 5挡速+复位
#define  MOTOR_FREQ_3_SPD		1  //变频器 3挡速
#define  MOTOR_FREQ_3_SPD_RST	2  //变频器 3挡速+复位
#define	 MOTOR_DC_SERVO	 		3//直流伺服
#define	 MOTOR_DC670_SERVO	 	4//直流伺服670
#define	 MOTOR_DC670_SERVO_ZHU	5//直流伺服670
#define	 MOTOR_AC_SERVO	 		6//交流伺服
#define	 MOTOR_AC_SERVO670 		7//交流伺服670

//刀数
#define MAIX_KNIFE1		999  //总刀数1-999
#define MAIX_KNIFE2		399  //总刀数1-399

#define PRO_HEAD_BYTES    2//100

//每个程序长度
#define PROG_BYTES1		((MAIX_KNIFE1*5)+PRO_HEAD_BYTES)//MAIX_KNIFE1 刀数据 +2byte刀数
#define PROG_BYTES2		((MAIX_KNIFE2*5)+PRO_HEAD_BYTES)


#define PROG_GROPU1		300  //前300个程序
#define MAIX_PROG		500//共500个程序

//*************************************************


#define	PAGE_KNIFE	5		//每页刀数
#define	PAGE2_KNIFE	(PAGE_KNIFE*2)		//2页刀数
//*****************************************
//------*********标识符 预定义
#define NO_FLAG		0
#define PUSH_FLAG   1   //推纸 标志位定义
#define KNIFE_FLAG  2   //刀  标志位定义
#define PRE_AUTO_FLAG 3	//k自动循环

//*****************************************
#define NAME_BYTE	90

typedef struct
{
Int8U pro_name_flag[5];
Int8U pro_name[NAME_BYTE];//程序名90B
Int8U pro_year;	//调用时间
Int8U pro_month;//调用时间
Int8U pro_day;	//调用时间
Int16U pro_knifeSUM;//刀数
} PROCESS_HEAD;		//程序头格式(100B)



typedef struct 
{
Int32U size;
Int8U  k_flag;
} KNIFE_DATA;

typedef struct
{
Int16U year;
Int16U month;
Int16U day;
} START_DAY;

extern KNIFE_DATA OneKnife_data;
extern START_DAY Start_days;
typedef struct
{
Int16U pro_num;//程序号
Int16U pro_sum;//程序总数
//Int8U step_num;// 
//Int8U seg_sum;// 
} PROG_SEG;    //程序 段 参数

extern Int16U cursor_row;////光标 位置(行)
extern Int16U  TableDis_startcol;//起始列

extern const pInt8U NAME_flag;
extern Int16U ProNumGroup[MAIX_PROG+2];

extern PROCESS_HEAD Pro_head_temp;//

extern Int16U Knife_order;//当前刀号
extern Int16U Knife_sum;//总刀数
extern Int16U Knife_sum_before;//总刀数  校正
extern Int16U MAIX_Knife;//最多刀数

//extern Int16U Process_num;//当前程序 号
//extern Int16U MaixProcess_num;//最大 程序号
extern PROG_SEG Pro_data;//程序 段 号


extern unsigned char PorgSet_sel;

//extern unsigned char cursor_temp;
extern unsigned short WorkMode;

extern unsigned char BeforeKnifeNo_flag;

extern Int32U CurrentSize;
extern Int32U BeforeKnifeSize;
extern Int32U BeforeKnife_offset;
extern Int32U BeforeKnife_offset_in;
extern Int32U OriginalSize;//原点
extern Int32U CurrentSize_temp;

extern Int8U Unit;//单位
extern Int8U Language;//语言
extern Int8U PressValid_flag;//

extern Int32U FrontLimit;
extern Int32U MiddleLimit;
extern Int32U BackLimit;
extern Int32U Aheader;
extern Int32U StanDistance;
extern Int8U Pulse_degree;
extern Int8U PassModeIn_flag;
extern Int8U PassModeOk_flag;

extern Int32U Size_MIN;
extern Int32U Size_MAX;
extern Int32U Size_MIN_num;
extern Int32U Size_MAX_num;
extern Int32U FirstDays;
extern Int32U SecondDays;
extern Int32U AutoPushDistance;

extern Int8U FirstDayValid_flag;
extern Int8U SecondDayValid_flag;

extern Int8U PassCodeEn_flag;
//extern Int8U SelfCutEnter_flag;
extern Int32U TargetSize;
extern Int32U TargetSize_temp;
extern Int32U TargetSize_inch;

extern Int8U Forward_flag;
extern Int8U Backward_flag;

extern Int8U Run_flag;
extern Int8U BackStop_flag;
extern Int8U ForceStop_flag;
extern Int8U RunStop_flag;
extern Int32U stop_time;

extern Int8U MoveSpeed;
extern Int8U SelfLockEn_flag;
extern Int8U InTargetPosit_flag;

extern Int8U GoFrontEn_flag;
extern Int8U GoBackEn_flag;
extern Int8U GoFast_flag;
extern Int8U JogRunMode;
extern Int8U EncoderErr_flag;

extern Int8U RunDisplay_flag;
extern Int8U AutoPushRun_flag;


extern Int8U AutoCutExec_flag;
extern Int8U AutoCutStart_flag;
extern Int8U OneCutRoutine_flag;

extern Int8U PusherResetMove_flag;
extern Int16U PusherResetTime;


extern Int8U MotorType;
extern Int8U PushRstKey_flag;

extern Int8U InputTouch_flag;
extern Int8U ProcessRatio;
extern Int16U CodeSensorTime_AB;
extern Int8U CutPermit_flag;

extern Int8U ServoPressStop_flag;
extern Int8U DcServoGoTarget_flag;

extern Int16U LastAutoKnife_order;//  自刀 的前一刀
extern Int8U ReEnterAutoKnife_dis;  //再次进入自刀  提示

extern Int8U ACServoDrvErr_flag;
extern Int8U ACServoAlarmExec_flag;

extern Int8U ElectricWheelOn_flag; //电子手轮
extern Int8U MotorRun_flag;

extern Int32U current_inch;

extern Int8U InputMode;
extern Int8U PramSel_Page;//
extern Int8U Para_sel;// 
extern Int8U Para2_sel;//2
extern Int8U IR_SensorStus;
extern Int8U JogLevel;// Jog速度



//****************
void StartPic_dis(void);//开机画面显示

void WorkPic_dis(void);  //工作画面显示
void TextWindow_dis(void); //文本输入框
void Pear_dis(Int16U x, Int16U y);//鸭梨

extern void F1up_Manual_dis(Int16U x, Int16U y);//F1up
extern void F2up_Manual_dis(Int16U x, Int16U y);//F2up


void CurrentArea_save1(Int16U x,Int16U y, Int16U Wide,Int16U High);//暂存  当前区域 画面1
void CurrentArea_save2(Int16U x,Int16U y, Int16U Wide,Int16U High);//暂存  当前区域 画面2
void CurrentArea_save3(Int16U x,Int16U y, Int16U Wide,Int16U High);//暂存  当前区域 画面3
void CurrentArea_recover1(Int16U x, Int16U y, Int16U Wide,Int16U High);//恢复  当前区域 画面1
void CurrentArea_recover2(Int16U x, Int16U y, Int16U Wide,Int16U High);//恢复  当前区域 画面2
void CurrentArea_recover3(Int16U x, Int16U y, Int16U Wide,Int16U High);//恢复  当前区域 画面3

void InputNum_dis(pInt8U nums,Int8U cou); //尺寸输入显示

void ProNum_dis(Int16U pro_order); //程序号码显示
void StepNum_dis(Int16U step_sum,Int16U step_order); //步骤号码显示
void KnifeOrder_dis(Int16U row, Int16U order,Int16U num_color);//-----------------------显示一个序号
void KnifeSize_dis(Int16U row,  Int32U Knife_size,Int16U num_color);//--------------显示一个尺寸
void PushFlag_dis(Int8U row,  Int8U Knife_flag);//-------一个 推纸 标志显示

Int8U OneKnifeDataSel_dis(Int16U knife,Int8U row,Int16U num_color);  //一刀数据 高亮显示

void ProgSet_dis(Int32U size, Int16U x, Int16U y, Int8U set_flag);// 标签页内 尺寸显示
void LabelSel_dis(Int8U sel, Int8U flag);
void DivideSel_dis(Int8U sel, Int8U flag);

void CurrentSize_dis(Int32U size);//当前尺寸
void FrontKnifeSize_dis(Int32U size);//刀前尺寸
void CurrUint_dis(Int8U unit);  //当前尺寸 单位
void FrontKnifeUint_dis(Int8U unit);  //当前尺寸 单位
void ParameterPage_dis(Int8U sel, Int8U flag); //参数 设置显示
void TimeSetSel_dis(Int8U sel, Int8U flag); //时间 设定 显示

void PromptNum_dis(void);  //输入数据范围 提示
void SelPulseDegree_dis(Int8U sel,Int8U flag); //脉冲设定
void PassDaysSet_dis(Int8U sel,Int8U flag);//天数设定

void SetMotorSpeed(Int8U speed_sel);//设定速度
void Draw_cross(Int16U x,Int16U y,Int16U color);

void ProgressBar_dis(Int16U total, Int16U now);  //进度条 显示


extern void MoveForward(void);	//前进
extern void MoveBack(void); //后退
extern void MoveStop(void);	

extern void CursorMov_dis(Int8U row, Int8U show_flag);//红色光标
extern void StepOrder_dis(Int16U step_order); //(-刀号)  步骤显示

extern void F3_plus_dis(Int8U flag);
extern void F4_minus_dis(Int8U flag);
extern void Auto_dis(Int16U x, Int16U y);//自动
extern void ClrCalcNums_text(pInt8U pText,Int8U text_sel); //计算器数据 清除
extern void Calculator_Window(void);  //计算器
extern void CalcInputNums_dis(pInt8U nums); //计算公式  文本框


#endif
