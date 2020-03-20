

#ifndef _TOUCH_H
#define _TOUCH_H

#include"main.h"
#include"pic_exec.h"

#include "tsc2046.h"
#include "comm_touch.h"


////#define CAP_TOUCH



#define TOU_SHAKE_TIME	5//10
#define TOU_SHAKE_TIME_UP 3

#define TOUCH_ERR_TIME   6000   //触摸 未释放  时间


#define INPUT_TOUCH_CODE	    0xffff0001
#define DELETE_ALL_TOUCH_CODE   0xffff0002
#define STOP_TOUCH_CODE   		0xffff0003
#define F_TOUCH_CODE   			0xffff0004
#define MODE_TOUCH_CODE   		0xffff0005
#define START_TOUCH_CODE   		0xffff0006

#define MUL_TOUCH_CODE  		0xffff0007
#define DIV_TOUCH_CODE  		0xffff0008
#define EQU_TOUCH_CODE  		0xffff0009
#define PUSH_OK_TOUCH_CODE  	0xffff000a
#define PUSH_CANCEL_TOUCH_CODE  0xffff000b
#define WHEEL_SWITCH_TOUCH_CODE 0xffff000c
// #define F0CUT_TOUCH_CODE 		0xffff000d 
// #define F5CUT_TOUCH_CODE 		0xffff000e 

#define TEACH_TOUCH_CODE      0xffff000f//示教mode
#define AUTOCUT_TOUCH_CODE      0xffff0010//自刀mode
 

//-------------------触摸 默认系数
#define A0_PER	54468369
#define A1_PER	4294939894
#define A2_PER	88
#define A3_PER	41803861
#define A4_PER	4294967167
#define A5_PER	4294945782
#define A6_PER	65536

/**
#ifdef	LCD_TOUCH_REVERSE
	#define TOU_DEGREE_X	264803//236530
	#define TOU_DEGREE_Y	211296//191881

	#define TOU_OFFSET_X	2190//2065
	#define TOU_OFFSET_Y	2050//
#else
	#define TOU_DEGREE_X	264803//206956
	#define TOU_DEGREE_Y	211296//137504

	#define TOU_OFFSET_X	2190//2038
	#define TOU_OFFSET_Y	2050//1935
#endif
**/
/*******
#define TOU_DEGREE_X	206956
#define TOU_DEGREE_Y	137504

#define TOU_OFFSET_X	2038
#define TOU_OFFSET_Y	1935
******/
//-----------触摸 模式
#define TOU_MODE_NO			0
#define TOU_MODE_CALC		1
#define TOU_MODE_F4			2
#define TOU_MODE_AUTOCUT_IN		3

//------------------按钮坐标
#define BUTT_Y_EXT10		10
#define BUTT_Y_EXT20		20
#define BUTT_Y_EXT40		40
#define BUTT_Y_EXT30		30
#define BUTT_Y_EXT35		35
#define BUTT_Y_EXT15		15
#define BUTT_GAP5		5

//---------主模式touch 按钮
#define ICONBUTT_TOU_HIGH	50
//编程
#define	PROG_MOD_TOU_X1		1
#define	PROG_MOD_TOU_Y1		(PROGRAM_BUTT_Y-BUTT_GAP5)
#define	PROG_MOD_TOU_X2		(F1_4_WIDE+BUTT_Y_EXT30)
#define	PROG_MOD_TOU_Y2		(PROGRAM_BUTT_Y+ICONBUTT_TOU_HIGH)
//自动
#define	AUTO_MOD_TOU_X1		PROG_MOD_TOU_X1
#define	AUTO_MOD_TOU_Y1		AUTO_BUTT_Y
#define	AUTO_MOD_TOU_X2		PROG_MOD_TOU_X2
#define	AUTO_MOD_TOU_Y2		(AUTO_BUTT_Y+ICONBUTT_TOU_HIGH)
//手动
#define	MANUAL_MOD_TOU_X1	PROG_MOD_TOU_X1
#define	MANUAL_MOD_TOU_Y1	MANUAL_BUTT_Y
#define	MANUAL_MOD_TOU_X2	PROG_MOD_TOU_X2
#define	MANUAL_MOD_TOU_Y2	(MANUAL_BUTT_Y+ICONBUTT_TOU_HIGH)
//示教
#define	TEACH_MOD_TOU_X1	PROG_MOD_TOU_X1
#define	TEACH_MOD_TOU_Y1	TEACH_BUTT_Y
#define	TEACH_MOD_TOU_X2	PROG_MOD_TOU_X2
#define	TEACH_MOD_TOU_Y2	(TEACH_BUTT_Y+ICONBUTT_TOU_HIGH)
//自刀
#define	AUTOCUT_MOD_TOU_X1	PROG_MOD_TOU_X1
#define	AUTOCUT_MOD_TOU_Y1	AUTOCUT_BUTT_Y
#define	AUTOCUT_MOD_TOU_X2	PROG_MOD_TOU_X2
#define	AUTOCUT_MOD_TOU_Y2	(AUTOCUT_BUTT_Y+ICONBUTT_TOU_HIGH)
//*****************************
//向上-------------------<
#define  MAIN_UP_BUTTON_X1	(SCHEDULE_X-BUTT_Y_EXT20)
#define  MAIN_UP_BUTTON_Y1	(SCHEDULE_Y-BUTT_Y_EXT10)
#define  MAIN_UP_BUTTON_X2	(SCHEDULE_X+SCHEDULE_WIDE+BUTT_Y_EXT15)
#define  MAIN_UP_BUTTON_Y2	(SCHEDULE_Y+40+BUTT_Y_EXT10)
//向下------------------->
#define  MAIN_DOWN_BUTTON_X1	MAIN_UP_BUTTON_X1
#define  MAIN_DOWN_BUTTON_Y1	(SCHEDULE_Y+SCHEDULE_HIGH-45)
#define  MAIN_DOWN_BUTTON_X2	MAIN_UP_BUTTON_X2
#define  MAIN_DOWN_BUTTON_Y2	(SCHEDULE_Y+SCHEDULE_HIGH+BUTT_Y_EXT10)
//F1--
#define F1_BUTTON_X1		(F1LABEL_BUTT_X-BUTT_Y_EXT10)
#define F1_BUTTON_Y1		F1LABEL_BUTT_Y
#define F1_BUTTON_X2		(F1LABEL_BUTT_X+F1_4_WIDE+BUTT_Y_EXT20)
#define F1_BUTTON_Y2		(F1LABEL_BUTT_Y+ICONBUTT_TOU_HIGH)
//F2--
#define F2_BUTTON_X1	F1_BUTTON_X1//F2DIVIDE_BUTT_X
#define F2_BUTTON_Y1	F2DIVIDE_BUTT_Y
#define F2_BUTTON_X2	F1_BUTTON_X2//(F2DIVIDE_BUTT_X+F1_4_WIDE)
#define F2_BUTTON_Y2	(F2DIVIDE_BUTT_Y+ICONBUTT_TOU_HIGH)
//F3--
#define F3_BUTTON_X1		F1_BUTTON_X1//F3PROJECT_BUTT_X
#define F3_BUTTON_Y1		F3PROJECT_BUTT_Y
#define F3_BUTTON_X2		F1_BUTTON_X2//(F3PROJECT_BUTT_X+F1_4_WIDE)
#define F3_BUTTON_Y2		(F3PROJECT_BUTT_Y+ICONBUTT_TOU_HIGH)
//F4--
#define F4_BUTTON_X1		F1_BUTTON_X1//F4SWITCH_BUTT_X
#define F4_BUTTON_Y1		F4SWITCH_BUTT_Y
#define F4_BUTTON_X2		F1_BUTTON_X2//(F4SWITCH_BUTT_X+F1_4_WIDE)
#define F4_BUTTON_Y2		(F4SWITCH_BUTT_Y+ICONBUTT_TOU_HIGH)
//后退
#define	 BACK_BUTT_X1	BACK_PAGE_X
#define	 BACK_BUTT_Y1	(BACK_PAGE_Y-BUTT_Y_EXT10)
#define	 BACK_BUTT_X2	(BACK_PAGE_X+F1_4_WIDE)
#define	 BACK_BUTT_Y2	(BACK_PAGE_Y+ICONBUTT_TOU_HIGH)
//前进
#define	 FWD_BUTT_X1	FRONT_PAGE_X
#define	 FWD_BUTT_Y1	(FRONT_PAGE_Y-BUTT_Y_EXT10)
#define	 FWD_BUTT_X2	(FRONT_PAGE_X+F1_4_WIDE)
#define	 FWD_BUTT_Y2	(FRONT_PAGE_Y+ICONBUTT_TOU_HIGH)
//快退
#define	 FAST_BACK_BUTT_X1	FAST_BACK_X
#define	 FAST_BACK_BUTT_Y1	(FAST_BACK_Y-BUTT_Y_EXT10)
#define	 FAST_BACK_BUTT_X2	(FAST_BACK_X+F1_4_WIDE)
#define	 FAST_BACK_BUTT_Y2	(FAST_BACK_Y+ICONBUTT_TOU_HIGH)
//快进
#define	 FAST_FWD_BUTT_X1	FAST_FWD_X
#define	 FAST_FWD_BUTT_Y1	(FAST_FWD_Y-BUTT_Y_EXT10)
#define	 FAST_FWD_BUTT_X2	(FAST_FWD_X+F1_4_WIDE)
#define	 FAST_FWD_BUTT_Y2	(FAST_FWD_Y+ICONBUTT_TOU_HIGH)

//F5--
#define F5_BUTTON_X1		F5_CUT_X//F1_BUTTON_X1
#define F5_BUTTON_Y1		(F5_CUT_Y-BUTT_Y_EXT10)
#define F5_BUTTON_X2		(F5_CUT_X+F1_4_WIDE)//(F5_BUTT_X+F1_4_WIDE)
#define F5_BUTTON_Y2		(F5_CUT_Y+ICONBUTT_TOU_HIGH)
//F0--
#define F0_BUTTON_X1		F0_ALL_CUT_X//F1_BUTTON_X1
#define F0_BUTTON_Y1		(F0_ALL_CUT_Y-BUTT_Y_EXT10)
#define F0_BUTTON_X2		(F0_ALL_CUT_X+F1_4_WIDE)//(F5_BUTT_X+F1_4_WIDE)
#define F0_BUTTON_Y2		(F0_ALL_CUT_Y+ICONBUTT_TOU_HIGH)
//F6--
#define F6_BUTTON_X1		F1_BUTTON_X1//F6_BUTT_X
#define F6_BUTTON_Y1		F6EXIT_BUTT_Y
#define F6_BUTTON_X2		F1_BUTTON_X2//(F6_BUTT_X+F1_4_WIDE)
#define F6_BUTTON_Y2		(F6EXIT_BUTT_Y+ICONBUTT_TOU_HIGH)
//OK
#define ENTER_OK_BUTT_X1	ENTER_OK_BUTT_X
#define ENTER_OK_BUTT_Y1	(ENTER_OK_BUTT_Y-BUTT_Y_EXT10)
#define ENTER_OK_BUTT_X2	(ENTER_OK_BUTT_X+F1_4_WIDE)
#define ENTER_OK_BUTT_Y2	(ENTER_OK_BUTT_Y+F1_4_HIGH)		//ok

// // //F4 标记框
// // #define F4_WIN_X1		F4_FLAG_WIN_X
// // #define F4_WIN_Y1		F4_FLAG_WIN_Y
// // #define F4_WIN_X2		(F4_FLAG_WIN_X+F4_FLAG_WIN_WIDE)
// // #define F4_WIN_Y2		(F4_FLAG_WIN_Y+F4_FLAG_WIN_HIGH)
// // //F1 气垫 按钮
// // #define F1_AIR_BUTT_X1	(F1_AIR_BED_X-BUTT_Y_EXT10)
// // #define F1_AIR_BUTT_Y1	(F1_AIR_BED_Y-BUTT_Y_EXT10)
// // #define F1_AIR_BUTT_X2	(F1_AIR_BED_X+FLAG_WIDE)
// // #define F1_AIR_BUTT_Y2	(F1_AIR_BED_Y+FLAG_HIGH)
// // //F2 理纸 按钮
// // #define	 F2_SORT_BUTT_X1	F2_SORT_PAPER_X
// // #define  F2_SORT_BUTT_Y1	F2_SORT_PAPER_Y
// // #define	 F2_SORT_BUTT_X2	(F2_SORT_PAPER_X+FLAG_WIDE)
// // #define  F2_SORT_BUTT_Y2	(F2_SORT_PAPER_Y+FLAG_HIGH)
// // //F3 撞纸 按钮
// // #define	 F3_CRASH_BUTT_X1	F3_CRASH_PAPER_X
// // #define  F3_CRASH_BUTT_Y1	F3_CRASH_PAPER_Y
// // #define	 F3_CRASH_BUTT_X2	(F3_CRASH_PAPER_X+FLAG_WIDE)
// // #define  F3_CRASH_BUTT_Y2	(F3_CRASH_PAPER_Y+FLAG_HIGH)
// // //F4推纸标志 按钮
// // #define  F4_PUSH_BUTT_X1	F4_PUSH_PAPER_X
// // #define	 F4_PUSH_BUTT_Y1	F4_PUSH_PAPER_Y
// // #define  F4_PUSH_BUTT_X2	(F4_PUSH_PAPER_X+FLAG_WIDE)
// // #define	 F4_PUSH_BUTT_Y2	(F4_PUSH_PAPER_Y+FLAG_HIGH)
// // //F5 红刀  按钮
// // #define	 F5_KNIFE_BUTT_X1	F5_RED_KNIFE_X
// // #define	 F5_KNIFE_BUTT_Y1	F5_RED_KNIFE_Y
// // #define	 F5_KNIFE_BUTT_X2	(F5_RED_KNIFE_X+FLAG_WIDE)
// // #define	 F5_KNIFE_BUTT_Y2	(F5_RED_KNIFE_Y+FLAG_HIGH)
// // //F6 退出 按钮
// // #define  F6_FLAG_EXIT_BUTT_X1	F6_FLAG_EXIT_X
// // #define  F6_FLAG_EXIT_BUTT_Y1	F6_FLAG_EXIT_Y
// // #define  F6_FLAG_EXIT_BUTT_X2	(F6_FLAG_EXIT_X+FLAG_WIDE)
// // #define  F6_FLAG_EXIT_BUTT_Y2	(F6_FLAG_EXIT_Y+FLAG_HIGH)

//--------------------------------------
//自刀提示 按钮
//ok
#define SELF_OK_X1		SELF_OK_X
#define SELF_OK_Y1		(SELF_OK_Y-BUTT_Y_EXT20)
#define SELF_OK_X2		(SELF_OK_X1+SELF_OK_WIDE)
#define SELF_OK_Y2		(SELF_OK_Y+SELF_OK_HIGH+BUTT_Y_EXT20)
//cancel
#define SELF_CANCEL_X1		SELF_CANCEL_X
#define SELF_CANCEL_Y1		(SELF_CANCEL_Y-BUTT_Y_EXT20)
#define SELF_CANCEL_X2		(SELF_CANCEL_X1+SELF_OK_WIDE)
#define SELF_CANCEL_Y2		(SELF_CANCEL_Y+SELF_OK_HIGH+BUTT_Y_EXT20)
//全删提示----
//ok
#define DEL_ALL_OK_X1	(DEL_ALL_HINT_X-BUTT_Y_EXT30)
#define DEL_ALL_OK_Y1	(DEL_ALL_OK_Y-BUTT_Y_EXT30)
#define DEL_ALL_OK_X2	(DEL_ALL_OK_X+80)
#define DEL_ALL_OK_Y2	(DEL_ALL_OK_Y+50)
//cancel
#define DEL_ALL_CANCEL_X1	(DEL_ALL_CANCEL_X-BUTT_Y_EXT20)
#define DEL_ALL_CANCEL_Y1	DEL_ALL_OK_Y1
#define DEL_ALL_CANCEL_X2	(DEL_ALL_CANCEL_X+100)
#define DEL_ALL_CANCEL_Y2	DEL_ALL_OK_Y2
//输入框
#define INPUT_X1		SIZE_WINDOW_X
#define INPUT_Y1		(SIZE_WINDOW_Y-BUTT_Y_EXT20)
#define INPUT_X2		(INPUT_X1+SIZE_WINDOW_WIDE)
#define INPUT_Y2		600//(SIZE_WINDOW_Y+SIZE_WINDOW_HIGH+BUTT_Y_EXT10)
//shift 按钮
#define SHIFT_BUTTON_X1	 SHIFT_BUTT_X
#define SHIFT_BUTTON_Y1	 SHIFT_BUTT_Y//-BUTT_Y_EXT20)
#define SHIFT_BUTTON_X2	 (SHIFT_BUTTON_X1+SHIFT_BUTT_WIDE)
#define SHIFT_BUTTON_Y2	 (SHIFT_BUTT_Y+SHIFT_BUTT_HIGH+BUTT_Y_EXT10)
//运行 按钮
#define RUN_BUTTON_X1	RUN_X
#define RUN_BUTTON_Y1	(RUN_Y-BUTT_Y_EXT10)
#define RUN_BUTTON_X2	(RUN_X+RUN_BIG_WIDE)
#define RUN_BUTTON_Y2	(RUN_Y+RUN_BIG_HIGH+BUTT_Y_EXT20)
//停止
#define STOP_BUTTON_X1		STOP_X
#define STOP_BUTTON_Y1		(STOP_Y-BUTT_Y_EXT10)
#define STOP_BUTTON_X2		(STOP_X+RUN_BIG_WIDE)
#define STOP_BUTTON_Y2		(STOP_Y+RUN_BIG_HIGH+BUTT_Y_EXT20)
//删除
#define DELETE_X1		DELETE_X
#define DELETE_Y1		(DELETE_Y-BUTT_Y_EXT10)
#define DELETE_X2		(DELETE_X+RUN_BIG_WIDE)
#define DELETE_Y2		(DELETE_Y+RUN_BIG_HIGH+BUTT_Y_EXT20)
//全删
#define DELETE_ALL_X1		DELETE_ALL_X
#define DELETE_ALL_Y1		(DELETE_ALL_Y-BUTT_Y_EXT10)
#define DELETE_ALL_X2		(DELETE_ALL_X+RUN_BIG_WIDE)
#define DELETE_ALL_Y2		(DELETE_ALL_Y+RUN_BIG_HIGH+BUTT_Y_EXT20)

//主模式 按钮==================
#define WORK_MODE_X1		(MODE_NAME_X1+BUTT_Y_EXT40)//PROGRAM_X
#define WORK_MODE_Y1		MODE_NAME_Y1//PROGRAM_Y
#define WORK_MODE_X2		(MODE_NAME_X2-BUTT_Y_EXT20)//(WORK_MODE_X1+WORKMODE_WIDE)
#define WORK_MODE_Y2		(MODE_NAME_Y2+BUTT_Y_EXT10)//(WORK_MODE_Y1+WORKMODE_HIGH)



//手动 下  前进，后退-------------------------------------------
#define MAN_FORWARD_X1	(MAN_FRONT_PAGE_X-BUTT_Y_EXT20)
#define MAN_FORWARD_Y1	(MAN_FRONT_PAGE_Y-BUTT_Y_EXT20)
#define MAN_FORWARD_X2	(MAN_FRONT_PAGE_X+FORWARD_WIDE+BUTT_Y_EXT20)
#define MAN_FORWARD_Y2	(MAN_FRONT_PAGE_Y+FORWARD_HIGH+BUTT_Y_EXT20)

#define MAN_BACKWARD_X1	(MAN_BACK_PAGE_X-BUTT_Y_EXT20)
#define MAN_BACKWARD_Y1	(MAN_BACK_PAGE_Y-BUTT_Y_EXT20)
#define MAN_BACKWARD_X2	(MAN_BACK_PAGE_X+FORWARD_WIDE+BUTT_Y_EXT20)
#define MAN_BACKWARD_Y2	(MAN_BACK_PAGE_Y+FORWARD_HIGH+BUTT_Y_EXT20)
//手动 下	快退
#define MAN_FAST_BACK_X1 (MAN_FAST_BACK_X-BUTT_Y_EXT20)
#define MAN_FAST_BACK_Y1 (MAN_FAST_BACK_Y-BUTT_Y_EXT20)
#define MAN_FAST_BACK_X2 (MAN_FAST_BACK_X+FORWARD_WIDE+BUTT_Y_EXT20)
#define MAN_FAST_BACK_Y2 (MAN_FAST_BACK_Y+FORWARD_HIGH+BUTT_Y_EXT20)
//手动 下	快进
#define MAN_FAST_FWD_X1	 (MAN_FAST_FWD_X-BUTT_Y_EXT20)
#define MAN_FAST_FWD_Y1	 (MAN_FAST_FWD_Y-BUTT_Y_EXT20)
#define MAN_FAST_FWD_X2	 (MAN_FAST_FWD_X+FORWARD_WIDE+BUTT_Y_EXT20)
#define MAN_FAST_FWD_Y2	 (MAN_FAST_FWD_Y+FORWARD_HIGH+BUTT_Y_EXT20)
//插入
#define INSERT_X1		L_R_ARROW_X
#define INSERT_Y1		(L_R_ARROW_Y-BUTT_Y_EXT10)
#define INSERT_X2		(L_R_ARROW_X+F1_4_WIDE)
#define INSERT_Y2		(L_R_ARROW_Y+F1_4_HIGH)
//子菜单 向上
#define SUB_UP_TO_X1		SUB_UP_ARROW_X
#define SUB_UP_TO_Y1		(SUB_UP_ARROW_Y-BUTT_Y_EXT10)
#define SUB_UP_TO_X2		(SUB_UP_ARROW_X+FORWARD_WIDE)
#define SUB_UP_TO_Y2		(SUB_UP_ARROW_Y+FORWARD_HIGH)
//子菜单 向下
#define SUB_DOWN_TO_X1		SUB_DOWN_ARROW_X
#define SUB_DOWN_TO_Y1		(SUB_DOWN_ARROW_Y-BUTT_Y_EXT10)
#define SUB_DOWN_TO_X2		(SUB_DOWN_ARROW_X+FORWARD_WIDE)
#define SUB_DOWN_TO_Y2		(SUB_DOWN_ARROW_Y+FORWARD_HIGH)


//----按钮 计算器-------------------------------------------
#define CALC_ONE_X1		(BUTT_X1+BUTT_GAP5)
#define CALC_ONE_Y1		(BUTT_Y1+BUTT_GAP5)
#define CALC_ONE_X2		(BUTT_X1+BUTT_WIDE-BUTT_GAP5)
#define CALC_ONE_Y2		(BUTT_Y1+BUTT_HIGH-BUTT_GAP5)

#define CALC_TWO_X1		(BUTT_X2+BUTT_GAP5)
#define CALC_TWO_Y1		(BUTT_Y1+BUTT_GAP5)
#define CALC_TWO_X2		(BUTT_X2+BUTT_WIDE-BUTT_GAP5)
#define CALC_TWO_Y2		(BUTT_Y1+BUTT_HIGH-BUTT_GAP5)

#define CALC_THREE_X1		(BUTT_X3+BUTT_GAP5)
#define CALC_THREE_Y1		(BUTT_Y1+BUTT_GAP5)
#define CALC_THREE_X2		(BUTT_X3+BUTT_WIDE-BUTT_GAP5)
#define CALC_THREE_Y2		(BUTT_Y1+BUTT_HIGH-BUTT_GAP5)

#define CALC_FOUR_X1		(BUTT_X1+BUTT_GAP5)
#define CALC_FOUR_Y1		(BUTT_Y2+BUTT_GAP5)
#define CALC_FOUR_X2		(BUTT_X1+BUTT_WIDE-BUTT_GAP5)
#define CALC_FOUR_Y2		(BUTT_Y2+BUTT_HIGH-BUTT_GAP5)

#define CALC_FIVE_X1		(BUTT_X2+BUTT_GAP5)
#define CALC_FIVE_Y1		(BUTT_Y2+BUTT_GAP5)
#define CALC_FIVE_X2		(BUTT_X2+BUTT_WIDE-BUTT_GAP5)
#define CALC_FIVE_Y2		(BUTT_Y2+BUTT_HIGH-BUTT_GAP5)

#define CALC_SIX_X1		(BUTT_X3+BUTT_GAP5)
#define CALC_SIX_Y1		(BUTT_Y2+BUTT_GAP5)
#define CALC_SIX_X2		(BUTT_X3+BUTT_WIDE-BUTT_GAP5)
#define CALC_SIX_Y2		(BUTT_Y2+BUTT_HIGH-BUTT_GAP5)

#define CALC_SEVEN_X1		(BUTT_X1+BUTT_GAP5)
#define CALC_SEVEN_Y1		(BUTT_Y3+BUTT_GAP5)
#define CALC_SEVEN_X2		(BUTT_X1+BUTT_WIDE-BUTT_GAP5)
#define CALC_SEVEN_Y2		(BUTT_Y3+BUTT_HIGH-BUTT_GAP5)

#define CALC_EIGHT_X1		(BUTT_X2+BUTT_GAP5)
#define CALC_EIGHT_Y1		(BUTT_Y3+BUTT_GAP5)
#define CALC_EIGHT_X2		(BUTT_X2+BUTT_WIDE-BUTT_GAP5)
#define CALC_EIGHT_Y2		(BUTT_Y3+BUTT_HIGH-BUTT_GAP5)

#define CALC_NINE_X1		(BUTT_X3+BUTT_GAP5)
#define CALC_NINE_Y1		(BUTT_Y3+BUTT_GAP5)
#define CALC_NINE_X2		(BUTT_X3+BUTT_WIDE-BUTT_GAP5)
#define CALC_NINE_Y2		(BUTT_Y3+BUTT_HIGH-BUTT_GAP5)

#define CALC_ZERO_X1		(BUTT_X2+BUTT_GAP5)
#define CALC_ZERO_Y1		(BUTT_Y4+BUTT_GAP5)
#define CALC_ZERO_X2		(BUTT_X2+BUTT_WIDE-BUTT_GAP5)
#define CALC_ZERO_Y2		(BUTT_Y4+BUTT_HIGH-BUTT_GAP5)

#define CALC_C_X1		(BUTT_X1+BUTT_GAP5)
#define CALC_C_Y1		(BUTT_Y4+BUTT_GAP5)
#define CALC_C_X2		(BUTT_X1+BUTT_WIDE-BUTT_GAP5)
#define CALC_C_Y2		(BUTT_Y4+BUTT_HIGH-BUTT_GAP5)

#define CALC_DOT_X1		(BUTT_X3+BUTT_GAP5)
#define CALC_DOT_Y1		(BUTT_Y4+BUTT_GAP5)
#define CALC_DOT_X2		(BUTT_X3+BUTT_WIDE-BUTT_GAP5)
#define CALC_DOT_Y2		(BUTT_Y4+BUTT_HIGH-BUTT_GAP5)

#define CALC_PLUS_X1		(BUTT_X4+BUTT_GAP5)
#define CALC_PLUS_Y1		(BUTT_Y1+BUTT_GAP5)
#define CALC_PLUS_X2		(BUTT_X4+BUTT_WIDE-BUTT_GAP5)
#define CALC_PLUS_Y2		(BUTT_Y1+BUTT_HIGH-BUTT_GAP5)

#define CALC_SUB_X1		(BUTT_X4+BUTT_GAP5)
#define CALC_SUB_Y1		(BUTT_Y2+BUTT_GAP5)
#define CALC_SUB_X2		(BUTT_X4+BUTT_WIDE-BUTT_GAP5)
#define CALC_SUB_Y2		(BUTT_Y2+BUTT_HIGH-BUTT_GAP5)

#define CALC_MUL_X1		(BUTT_X4+BUTT_GAP5)
#define CALC_MUL_Y1		(BUTT_Y3+BUTT_GAP5)
#define CALC_MUL_X2		(BUTT_X4+BUTT_WIDE-BUTT_GAP5)
#define CALC_MUL_Y2		(BUTT_Y3+BUTT_HIGH-BUTT_GAP5)

#define CALC_DIV_X1		(BUTT_X4+BUTT_GAP5)
#define CALC_DIV_Y1		(BUTT_Y4+BUTT_GAP5)
#define CALC_DIV_X2		(BUTT_X4+BUTT_WIDE-BUTT_GAP5)
#define CALC_DIV_Y2		(BUTT_Y4+BUTT_HIGH-BUTT_GAP5)

#define CALC_INS_X1		(BUTT_X5+BUTT_GAP5)
#define CALC_INS_Y1		(BUTT_Y1+BUTT_GAP5)
#define CALC_INS_X2		(BUTT_X5+BUTT_WIDE-BUTT_GAP5)
#define CALC_INS_Y2		(BUTT_Y1+BUTT_HIGH-BUTT_GAP5)

#define CALC_EXIT_X1		(BUTT_X5+BUTT_GAP5)
#define CALC_EXIT_Y1		(BUTT_Y2+BUTT_GAP5)
#define CALC_EXIT_X2		(BUTT_X5+BUTT_WIDE-BUTT_GAP5)
#define CALC_EXIT_Y2		(BUTT_Y2+BUTT_HIGH-BUTT_GAP5)

#define CALC_EQU_X1		(BUTT_X5+BUTT_GAP5)
#define CALC_EQU_Y1		(BUTT_Y3+BUTT_GAP5)
#define CALC_EQU_X2		(BUTT_X5+BUTT_WIDE-BUTT_GAP5)
#define CALC_EQU_Y2		(BUTT_Y3+BUTT_HIGH-BUTT_GAP5)

#define CALC_ENTER_X1		(BUTT_X5+BUTT_GAP5)
#define CALC_ENTER_Y1		(BUTT_Y4+BUTT_GAP5)
#define CALC_ENTER_X2		(BUTT_X5+BUTT_WIDE-BUTT_GAP5)
#define CALC_ENTER_Y2		(BUTT_Y4+BUTT_HIGH-BUTT_GAP5)

#define CALC_UP_X1		(BUTT_X6+BUTT_GAP5)
#define CALC_UP_Y1		BUTT_Y1
#define CALC_UP_X2		(CALC_UP_X1+BUTT_WIDE_ARROW)
#define CALC_UP_Y2		(CALC_UP_Y1+BUTT_HIGH_ARROW)

#define CALC_DOWN_X1		(BUTT_X6+BUTT_GAP5)
#define CALC_DOWN_Y1		BUTT_Y3
#define CALC_DOWN_X2		(CALC_DOWN_X1+BUTT_WIDE_ARROW)
#define CALC_DOWN_Y2		(CALC_DOWN_Y1+BUTT_HIGH_ARROW)

//开机推纸器 复位 提示
#define PUSH_RESET_WIDE		100
#define PUSH_RESET_HIGH		50
#define	PUSH_RESET_OK_X1	(PUSH_RESET_OK_X-BUTT_Y_EXT40)
#define	PUSH_RESET_OK_Y1	(PUSH_RESET_OK_Y-BUTT_Y_EXT40)
#define	PUSH_RESET_OK_X2	(PUSH_RESET_OK_X+PUSH_RESET_WIDE)
#define	PUSH_RESET_OK_Y2	(PUSH_RESET_OK_Y+PUSH_RESET_HIGH)

#define	PUSH_RESET_CANCEL_X1	(PUSH_RESET_CANCEL_X-BUTT_Y_EXT40)
#define	PUSH_RESET_CANCEL_Y1	(PUSH_RESET_CANCEL_Y-BUTT_Y_EXT40)
#define	PUSH_RESET_CANCEL_X2	(PUSH_RESET_CANCEL_X+PUSH_RESET_WIDE)
#define	PUSH_RESET_CANCEL_Y2	(PUSH_RESET_CANCEL_Y+PUSH_RESET_HIGH)

//开始运行.....
#define START_X1		START_PROMPT_X2//REMIND_WINDOW_X
#define START_Y1		(START_PROMPT_Y2-50)
#define START_X2		(START_X1+600)
#define START_Y2		599//(START_Y1+30)
//开机jog 按钮------------
#define START_JOG_BACK_X1	START_JOG_BACK_X
#define START_JOG_BACK_Y1	(START_JOG_BACK_Y-BUTT_Y_EXT20)
#define START_JOG_BACK_X2	(START_JOG_BACK_X+F1_4_WIDE)
#define START_JOG_BACK_Y2	(START_JOG_BACK_Y+F1_4_HIGH+BUTT_Y_EXT20)

#define START_JOG_FORW_X1	START_JOG_FORW_X
#define START_JOG_FORW_Y1	(START_JOG_FORW_Y-BUTT_Y_EXT20)
#define START_JOG_FORW_X2	(START_JOG_FORW_X+F1_4_WIDE)
#define START_JOG_FORW_Y2	(START_JOG_FORW_Y+F1_4_HIGH+BUTT_Y_EXT20)
//手轮 开关 指示
#define WHEEL_SWITCH_X1		(WHEEL_STA_X-BUTT_Y_EXT30)
#define WHEEL_SWITCH_X2		(WHEEL_STA_X+64+BUTT_Y_EXT30)
#define WHEEL_SWITCH_Y1		(WHEEL_STA_Y-BUTT_Y_EXT30)
#define WHEEL_SWITCH_Y2		(WHEEL_STA_Y+64)
//---------------------输入法 touch键盘
//--------input name key button
#define TOU_BUTT_ONE_X1		(TOUBUTT_X1+BUTT_GAP5)
#define TOU_BUTT_ONE_Y1		(TOUBUTT_Y1+BUTT_GAP5)
#define TOU_BUTT_ONE_X2		(TOUBUTT_X1+TOUBUTT_WIDE-BUTT_GAP5)
#define TOU_BUTT_ONE_Y2		(TOUBUTT_Y1+TOUBUTT_HIGH-BUTT_GAP5)	//1

#define TOU_BUTT_TWO_X1		(TOUBUTT_X2+BUTT_GAP5)
#define TOU_BUTT_TWO_Y1		(TOUBUTT_Y1+BUTT_GAP5)
#define TOU_BUTT_TWO_X2		(TOUBUTT_X2+TOUBUTT_WIDE-BUTT_GAP5)
#define TOU_BUTT_TWO_Y2		(TOUBUTT_Y1+TOUBUTT_HIGH-BUTT_GAP5)	//2

#define TOU_BUTT_THREE_X1		(TOUBUTT_X3+BUTT_GAP5)
#define TOU_BUTT_THREE_Y1		(TOUBUTT_Y1+BUTT_GAP5)
#define TOU_BUTT_THREE_X2		(TOUBUTT_X3+TOUBUTT_WIDE-BUTT_GAP5)
#define TOU_BUTT_THREE_Y2		(TOUBUTT_Y1+TOUBUTT_HIGH-BUTT_GAP5)	//3

#define TOU_BUTT_UP_X1		(TOUBUTT_X4+BUTT_GAP5)
#define TOU_BUTT_UP_Y1		(TOUBUTT_Y1+BUTT_GAP5)
#define TOU_BUTT_UP_X2		(TOUBUTT_X4+TOUBUTT_WIDE-BUTT_GAP5)
#define TOU_BUTT_UP_Y2		(TOUBUTT_Y1+TOUBUTT_HIGH-BUTT_GAP5)	//up
//---------------------
#define TOU_BUTT_FOUR_X1		(TOUBUTT_X1+BUTT_GAP5)
#define TOU_BUTT_FOUR_Y1		(TOUBUTT_Y2+BUTT_GAP5)
#define TOU_BUTT_FOUR_X2		(TOUBUTT_X1+TOUBUTT_WIDE-BUTT_GAP5)
#define TOU_BUTT_FOUR_Y2		(TOUBUTT_Y2+TOUBUTT_HIGH-BUTT_GAP5)	//4

#define TOU_BUTT_FIVE_X1		(TOUBUTT_X2+BUTT_GAP5)
#define TOU_BUTT_FIVE_Y1		(TOUBUTT_Y2+BUTT_GAP5)
#define TOU_BUTT_FIVE_X2		(TOUBUTT_X2+TOUBUTT_WIDE-BUTT_GAP5)
#define TOU_BUTT_FIVE_Y2		(TOUBUTT_Y2+TOUBUTT_HIGH-BUTT_GAP5)	//5

#define TOU_BUTT_SIX_X1		(TOUBUTT_X3+BUTT_GAP5)
#define TOU_BUTT_SIX_Y1		(TOUBUTT_Y2+BUTT_GAP5)
#define TOU_BUTT_SIX_X2		(TOUBUTT_X3+TOUBUTT_WIDE-BUTT_GAP5)
#define TOU_BUTT_SIX_Y2		(TOUBUTT_Y2+TOUBUTT_HIGH-BUTT_GAP5)	//6

#define TOU_BUTT_DOWN_X1		(TOUBUTT_X4+BUTT_GAP5)
#define TOU_BUTT_DOWN_Y1		(TOUBUTT_Y2+BUTT_GAP5)
#define TOU_BUTT_DOWN_X2		(TOUBUTT_X4+TOUBUTT_WIDE-BUTT_GAP5)
#define TOU_BUTT_DOWN_Y2		(TOUBUTT_Y2+TOUBUTT_HIGH-BUTT_GAP5)	//down
//---------------------
#define TOU_BUTT_SEVEN_X1		(TOUBUTT_X1+BUTT_GAP5)
#define TOU_BUTT_SEVEN_Y1		(TOUBUTT_Y3+BUTT_GAP5)
#define TOU_BUTT_SEVEN_X2		(TOUBUTT_X1+TOUBUTT_WIDE-BUTT_GAP5)
#define TOU_BUTT_SEVEN_Y2		(TOUBUTT_Y3+TOUBUTT_HIGH-BUTT_GAP5)	//7

#define TOU_BUTT_EIGHT_X1		(TOUBUTT_X2+BUTT_GAP5)
#define TOU_BUTT_EIGHT_Y1		(TOUBUTT_Y3+BUTT_GAP5)
#define TOU_BUTT_EIGHT_X2		(TOUBUTT_X2+TOUBUTT_WIDE-BUTT_GAP5)
#define TOU_BUTT_EIGHT_Y2		(TOUBUTT_Y3+TOUBUTT_HIGH-BUTT_GAP5)	//8

#define TOU_BUTT_NINE_X1		(TOUBUTT_X3+BUTT_GAP5)
#define TOU_BUTT_NINE_Y1		(TOUBUTT_Y3+BUTT_GAP5)
#define TOU_BUTT_NINE_X2		(TOUBUTT_X3+TOUBUTT_WIDE-BUTT_GAP5)
#define TOU_BUTT_NINE_Y2		(TOUBUTT_Y3+TOUBUTT_HIGH-BUTT_GAP5)	//9

#define TOU_BUTT_LEFT_X1		(TOUBUTT_X4+BUTT_GAP5)
#define TOU_BUTT_LEFT_Y1		(TOUBUTT_Y3+BUTT_GAP5)
#define TOU_BUTT_LEFT_X2		(TOUBUTT_X4+TOUBUTT_WIDE-BUTT_GAP5)
#define TOU_BUTT_LEFT_Y2		(TOUBUTT_Y3+TOUBUTT_HIGH-BUTT_GAP5)	//left
//---------------------
#define TOU_BUTT_CLR_X1		(TOUBUTT_X1+BUTT_GAP5)
#define TOU_BUTT_CLR_Y1		(TOUBUTT_Y4+BUTT_GAP5)
#define TOU_BUTT_CLR_X2		(TOUBUTT_X1+TOUBUTT_WIDE-BUTT_GAP5)
#define TOU_BUTT_CLR_Y2		(TOUBUTT_Y4+TOUBUTT_HIGH-BUTT_GAP5)	//c

#define TOU_BUTT_ZERO_X1		(TOUBUTT_X2+BUTT_GAP5)
#define TOU_BUTT_ZERO_Y1		(TOUBUTT_Y4+BUTT_GAP5)
#define TOU_BUTT_ZERO_X2		(TOUBUTT_X2+TOUBUTT_WIDE-BUTT_GAP5)
#define TOU_BUTT_ZERO_Y2		(TOUBUTT_Y4+TOUBUTT_HIGH-BUTT_GAP5)	//0

#define TOU_BUTT_OK_X1		(TOUBUTT_X3+BUTT_GAP5)
#define TOU_BUTT_OK_Y1		(TOUBUTT_Y4+BUTT_GAP5)
#define TOU_BUTT_OK_X2		(TOUBUTT_X3+TOUBUTT_WIDE-BUTT_GAP5)
#define TOU_BUTT_OK_Y2		(TOUBUTT_Y4+TOUBUTT_HIGH-BUTT_GAP5)	//ok

#define TOU_BUTT_RIGHT_X1		(TOUBUTT_X4+BUTT_GAP5)
#define TOU_BUTT_RIGHT_Y1		(TOUBUTT_Y4+BUTT_GAP5)
#define TOU_BUTT_RIGHT_X2		(TOUBUTT_X4+TOUBUTT_WIDE-BUTT_GAP5)
#define TOU_BUTT_RIGHT_Y2		(TOUBUTT_Y4+TOUBUTT_HIGH-BUTT_GAP5)	//right
//----------------------------------------------------------------------------
//----开机 帮助
#define START_HELP_TOU_X1	(HELP_RET_X-50)
#define START_HELP_TOU_Y1	1
#define START_HELP_TOU_X2	800
#define START_HELP_TOU_Y2	150
//F1 触摸校准--块
#define START_F1_TOU_X1		1
#define START_F1_TOU_Y1		START_HELP_TOU_Y1
#define START_F1_TOU_X2		300
#define START_F1_TOU_Y2		START_HELP_TOU_Y2
//F1 触摸校准项
#define ITEM_LEN	300
#define HELP_F1_X1	HELP_F1_X
#define HELP_F1_Y1	(HELP_F1_Y-BUTT_Y_EXT10)
#define HELP_F1_X2	(HELP_F1_X+ITEM_LEN)
#define HELP_F1_Y2	(HELP_F1_Y+BUTT_Y_EXT35)
//F2 注释项
#define HELP_F2_X1	HELP_F1_X
#define HELP_F2_Y1	(HELP_F2_Y-BUTT_Y_EXT10)
#define HELP_F2_X2	(HELP_F1_X+ITEM_LEN)
#define HELP_F2_Y2	(HELP_F2_Y+BUTT_Y_EXT35)
//F3 io测试项
#define HELP_F3_X1	HELP_F1_X
#define HELP_F3_Y1	(HELP_F3_Y-BUTT_Y_EXT10)
#define HELP_F3_X2	(HELP_F1_X+ITEM_LEN)
#define HELP_F3_Y2	(HELP_F3_Y+BUTT_Y_EXT35)
//F4 版本项
#define HELP_F4_X1	HELP_F1_X
#define HELP_F4_Y1	(HELP_F4_Y-BUTT_Y_EXT10)
#define HELP_F4_X2	(HELP_F1_X+ITEM_LEN)
#define HELP_F4_Y2	(HELP_F4_Y+BUTT_Y_EXT35)
//F5 每页行数设置
#define HELP_F5_X1	HELP_F1_X
#define HELP_F5_Y1	(HELP_F5_Y-BUTT_Y_EXT10)
#define HELP_F5_X2	(HELP_F1_X+ITEM_LEN)
#define HELP_F5_Y2	(HELP_F5_Y+BUTT_Y_EXT35)
//-------F2 page
#define F2_PAGE_UP_X1	(F2_PAGE_UP_X-BUTT_Y_EXT40)
#define F2_PAGE_UP_Y1	(F2_PAGE_UP_Y-BUTT_Y_EXT40)
#define F2_PAGE_UP_X2	(F2_PAGE_UP_X+120)
#define F2_PAGE_UP_Y2	600
//--
#define F2_PAGE_DOWN_X1	(F2_PAGE_DOWN_X-BUTT_Y_EXT40)
#define F2_PAGE_DOWN_Y1	(F2_PAGE_DOWN_Y-BUTT_Y_EXT40)
#define F2_PAGE_DOWN_X2	(F2_PAGE_DOWN_X+120)
#define F2_PAGE_DOWN_Y2	F2_PAGE_UP_Y2
//--
#define F2_RET_HELP_X1	(F2_RET_HELP_X-BUTT_Y_EXT20)
#define F2_RET_HELP_Y1	(F2_RET_HELP_Y-BUTT_Y_EXT40)
#define F2_RET_HELP_X2	800
#define F2_RET_HELP_Y2	F2_PAGE_UP_Y2
//F4  password  touch键盘
#define KEY_BUTT_1_X1	KEY_BUT_X1
#define KEY_BUTT_1_Y1	KEY_BUT_Y1
#define KEY_BUTT_1_X2	(KEY_BUT_X1+KEY_BUT_WIDE)
#define KEY_BUTT_1_Y2	(KEY_BUT_Y1+KEY_BUT_HIGH)
//2
#define KEY_BUTT_2_X1	KEY_BUT_X2
#define KEY_BUTT_2_Y1	KEY_BUT_Y1
#define KEY_BUTT_2_X2	(KEY_BUT_X2+KEY_BUT_WIDE)
#define KEY_BUTT_2_Y2	(KEY_BUT_Y1+KEY_BUT_HIGH)
//3
#define KEY_BUTT_3_X1	KEY_BUT_X3
#define KEY_BUTT_3_Y1	KEY_BUT_Y1
#define KEY_BUTT_3_X2	(KEY_BUT_X3+KEY_BUT_WIDE)
#define KEY_BUTT_3_Y2	(KEY_BUT_Y1+KEY_BUT_HIGH)
//4
#define KEY_BUTT_4_X1	KEY_BUT_X1
#define KEY_BUTT_4_Y1	KEY_BUT_Y2
#define KEY_BUTT_4_X2	(KEY_BUT_X1+KEY_BUT_WIDE)
#define KEY_BUTT_4_Y2	(KEY_BUT_Y2+KEY_BUT_HIGH)
//5
#define KEY_BUTT_5_X1	KEY_BUT_X2
#define KEY_BUTT_5_Y1	KEY_BUT_Y2
#define KEY_BUTT_5_X2	(KEY_BUT_X2+KEY_BUT_WIDE)
#define KEY_BUTT_5_Y2	(KEY_BUT_Y2+KEY_BUT_HIGH)
//6
#define KEY_BUTT_6_X1	KEY_BUT_X3
#define KEY_BUTT_6_Y1	KEY_BUT_Y2
#define KEY_BUTT_6_X2	(KEY_BUT_X3+KEY_BUT_WIDE)
#define KEY_BUTT_6_Y2	(KEY_BUT_Y2+KEY_BUT_HIGH)
//7
#define KEY_BUTT_7_X1	KEY_BUT_X1
#define KEY_BUTT_7_Y1	KEY_BUT_Y3
#define KEY_BUTT_7_X2	(KEY_BUT_X1+KEY_BUT_WIDE)
#define KEY_BUTT_7_Y2	(KEY_BUT_Y3+KEY_BUT_HIGH)
//8
#define KEY_BUTT_8_X1	KEY_BUT_X2
#define KEY_BUTT_8_Y1	KEY_BUT_Y3
#define KEY_BUTT_8_X2	(KEY_BUT_X2+KEY_BUT_WIDE)
#define KEY_BUTT_8_Y2	(KEY_BUT_Y3+KEY_BUT_HIGH)
//9
#define KEY_BUTT_9_X1	KEY_BUT_X3
#define KEY_BUTT_9_Y1	KEY_BUT_Y3
#define KEY_BUTT_9_X2	(KEY_BUT_X3+KEY_BUT_WIDE)
#define KEY_BUTT_9_Y2	(KEY_BUT_Y3+KEY_BUT_HIGH)
//clear
#define KEY_BUTT_C_X1	KEY_BUT_X1
#define KEY_BUTT_C_Y1	KEY_BUT_Y4
#define KEY_BUTT_C_X2	(KEY_BUT_X1+KEY_BUT_WIDE)
#define KEY_BUTT_C_Y2	(KEY_BUT_Y4+KEY_BUT_HIGH)
//0
#define KEY_BUTT_0_X1	KEY_BUT_X2
#define KEY_BUTT_0_Y1	KEY_BUT_Y4
#define KEY_BUTT_0_X2	(KEY_BUT_X2+KEY_BUT_WIDE)
#define KEY_BUTT_0_Y2	(KEY_BUT_Y4+KEY_BUT_HIGH)
//ok
#define KEY_BUTT_OK_X1	KEY_BUT_X3
#define KEY_BUTT_OK_Y1	KEY_BUT_Y4
#define KEY_BUTT_OK_X2	(KEY_BUT_X3+KEY_BUT_WIDE)
#define KEY_BUTT_OK_Y2	(KEY_BUT_Y4+KEY_BUT_HIGH)
//ver sel up
#define VER_SEL_UP_X1	(VER_SEL_UP_X-BUTT_Y_EXT40)
#define VER_SEL_UP_Y1	(VER_SEL_UP_Y-BUTT_Y_EXT20)
#define VER_SEL_UP_X2	(VER_SEL_UP_X+F1_4_WIDE+BUTT_Y_EXT40)
#define VER_SEL_UP_Y2	(VER_SEL_UP_Y+F1_4_HIGH+BUTT_Y_EXT20)
//down
#define VER_SEL_DOWN_X1	(VER_SEL_DOWN_X-BUTT_Y_EXT40)
#define VER_SEL_DOWN_Y1	(VER_SEL_DOWN_Y-BUTT_Y_EXT20)
#define VER_SEL_DOWN_X2	(VER_SEL_DOWN_X+F1_4_WIDE+BUTT_Y_EXT40)
#define VER_SEL_DOWN_Y2	(VER_SEL_DOWN_Y+F1_4_HIGH+BUTT_Y_EXT20)
//line set up
#define LINE_SET_UP_X1	(LINE_SET_UP_X-BUTT_Y_EXT40)
#define LINE_SET_UP_Y1	(LINE_SET_UP_Y-BUTT_Y_EXT20)
#define LINE_SET_UP_X2	(LINE_SET_UP_X+F1_4_WIDE+BUTT_Y_EXT40)
#define LINE_SET_UP_Y2	(LINE_SET_UP_Y+F1_4_HIGH+BUTT_Y_EXT20)
//down
#define LINE_SET_DOWN_X1	(LINE_SET_DOWN_X-BUTT_Y_EXT40)
#define LINE_SET_DOWN_Y1	(LINE_SET_DOWN_Y-BUTT_Y_EXT20)
#define LINE_SET_DOWN_X2	(LINE_SET_DOWN_X+F1_4_WIDE+BUTT_Y_EXT40)
#define LINE_SET_DOWN_Y2	(LINE_SET_DOWN_Y+F1_4_HIGH+BUTT_Y_EXT20)





extern Int8U Touch_down_flag; 

extern Int32U Touch_code;
extern TOUCH Touch_Pos;
//extern Int8U FlagTouRow_num;


void ToucScan(void);
void TouchKey_exec(void);
void GetTouch_pos(void);
void GetTouchKeyCode(void);
void TouchButton_dis(Int32U code,Int8U down_flag);



#endif
