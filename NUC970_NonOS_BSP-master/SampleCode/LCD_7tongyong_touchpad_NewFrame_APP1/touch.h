

#ifndef _TOUCH_H
#define _TOUCH_H

#include"main.h"
#include"pic_exec.h"
#include"tsc2046.h"



//#define CAP_TOUCH




#define TOU_SHAKE_TIME	2

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
#define F0CUT_TOUCH_CODE 		0xffff000d 
#define F5CUT_TOUCH_CODE 		0xffff000e 
#define FAST_FWD_TOUCH_CODE 	0xffff000f 
#define FAST_BACK_TOUCH_CODE 	0xffff0010 
#define F5PRE_FLG_TOUCH_CODE 	0xffff0011 
//-------------------触摸 默认系数
#define A0_PER	52633872
#define A1_PER	4294941618
#define A2_PER	23
#define A3_PER	4293444804
#define A4_PER	18
#define A5_PER	16652
#define A6_PER	65536

//-------------------触摸 默认值
#ifdef	LCD_TOUCH_REVERSE
	#define TOU_DEGREE_X	210157
	#define TOU_DEGREE_Y	142551

	#define TOU_OFFSET_X	2059
	#define TOU_OFFSET_Y	1946
#else
	#define TOU_DEGREE_X	206956
	#define TOU_DEGREE_Y	137504

	#define TOU_OFFSET_X	2038
	#define TOU_OFFSET_Y	1935
#endif
/*******
#define TOU_DEGREE_X	206956
#define TOU_DEGREE_Y	137504

#define TOU_OFFSET_X	2038
#define TOU_OFFSET_Y	1935
******/


//------------------按钮坐标
#define BUTT_Y_EXT10		10
#define BUTT_Y_EXT20		20
#define BUTT_Y_EXT40		40
#define BUTT_Y_EXT30		30
#define BUTT_Y_EXT15		15
#define BUTT_GAP5		5

//F
#define F_KEY_X1		F_KEY_X
#define F_KEY_Y1		(F_KEY_Y-BUTT_Y_EXT10)
#define F_KEY_X2		(F_KEY_X1+F_KEY_WIDE)
#define F_KEY_Y2		(F_KEY_Y+F_KEY_HIGH+BUTT_Y_EXT10)
//F1--
#define F1_LABEL_X1		(F1_X-BUTT_Y_EXT20)
#define F1_LABEL_Y1		F1_Y
#define F1_LABEL_X2		(F1_X+F1_4_WIDE+BUTT_Y_EXT15)
#define F1_LABEL_Y2		(F1_LABEL_Y1+F1_4_HIGH)
//F2--
#define F2_DIVIDE_X1	(F2_X-BUTT_Y_EXT20)
#define F2_DIVIDE_Y1	F2_Y
#define F2_DIVIDE_X2	(F2_X+F1_4_WIDE+BUTT_Y_EXT15)
#define F2_DIVIDE_Y2	(F2_DIVIDE_Y1+F1_4_HIGH)
//F3--
#define F3_PROG_X1		(F3_X-BUTT_Y_EXT20)
#define F3_PROG_Y1		F3_Y
#define F3_PROG_X2		(F3_X+F1_4_WIDE+BUTT_Y_EXT15)
#define F3_PROG_Y2		(F3_PROG_Y1+F1_4_HIGH)
//F4--
#define F4_PUSH_X1		(F4_X-BUTT_Y_EXT20)
#define F4_PUSH_Y1		F4_Y
#define F4_PUSH_X2		(F4_X+F1_4_WIDE+BUTT_Y_EXT15)
#define F4_PUSH_Y2		(F4_PUSH_Y1+F1_4_HIGH)
//---F1完成
#define F1_FINISH_X1		(FINISHED_X-BUTT_Y_EXT10)
#define F1_FINISH_Y1		(FINISHED_Y-BUTT_Y_EXT10)
#define F1_FINISH_X2		(FINISHED_X+F1_4_WIDE+BUTT_Y_EXT10)
#define F1_FINISH_Y2		(FINISHED_Y+F1_4_HIGH+BUTT_Y_EXT10)
//F2退出
#define F2_CANCEL_X1		(F2OUT_X-BUTT_Y_EXT10)
#define F2_CANCEL_Y1		(F2OUT_Y-BUTT_Y_EXT10)
#define F2_CANCEL_X2		(F2OUT_X+F1_4_WIDE+BUTT_Y_EXT10)
#define F2_CANCEL_Y2		(F2OUT_Y+F1_4_HIGH+BUTT_Y_EXT10)
//删除
#define DELETE_X1		DELETE_X
#define DELETE_Y1		(DELETE_Y-BUTT_Y_EXT20)
#define DELETE_X2		(DELETE_X1+DELETE_WIDE)
#define DELETE_Y2		(DELETE_Y+DELETE_HIGH+BUTT_Y_EXT30)
//全删
#define DELETE_ALL_X1		DELETE_ALL_X
#define DELETE_ALL_Y1		(DELETE_ALL_Y-BUTT_Y_EXT15)
#define DELETE_ALL_X2		(DELETE_ALL_X1+DELETE_WIDE)
#define DELETE_ALL_Y2		(DELETE_ALL_Y+DELETE_HIGH+BUTT_Y_EXT30)
//运行
#define RUN_X1		DELETE_X1
#define RUN_Y1		DELETE_Y1
#define RUN_X2		DELETE_X2
#define RUN_Y2		DELETE_Y2
//停止
#define STOP_X1		STOP_X
#define STOP_Y1		(STOP_Y-BUTT_Y_EXT10)
#define STOP_X2		(STOP_X1+DELETE_WIDE)
#define STOP_Y2		(STOP_Y+DELETE_HIGH+BUTT_Y_EXT30)
//前进
#define FORWARD_X1		FRONT_PAGE_X
#define FORWARD_Y1		(FRONT_PAGE_Y-BUTT_Y_EXT10)
#define FORWARD_X2		(FORWARD_X1+FORWARD_WIDE)
#define FORWARD_Y2		(FRONT_PAGE_Y+FORWARD_HIGH+BUTT_Y_EXT10)
//后退
#define BACKWARD_X1		BACK_PAGE_X
#define BACKWARD_Y1		(BACK_PAGE_Y-BUTT_Y_EXT10)
#define BACKWARD_X2		(BACKWARD_X1+FORWARD_WIDE)
#define BACKWARD_Y2		(BACK_PAGE_Y+FORWARD_HIGH+BUTT_Y_EXT10)
//向上
#define UP_TO_X1		UP_ARROW_X
#define UP_TO_Y1		(UP_ARROW_Y-BUTT_Y_EXT10)
#define UP_TO_X2		(UP_TO_X1+FORWARD_WIDE)
#define UP_TO_Y2		(UP_ARROW_Y+FORWARD_HIGH+BUTT_Y_EXT10)
//向下
#define DOWN_TO_X1		DOWN_ARROW_X
#define DOWN_TO_Y1		(DOWN_ARROW_Y-BUTT_Y_EXT10)
#define DOWN_TO_X2		(DOWN_TO_X1+FORWARD_WIDE)
#define DOWN_TO_Y2		(DOWN_ARROW_Y+FORWARD_HIGH+BUTT_Y_EXT10)
//输入框
#define INPUT_X1		SIZE_WINDOW_X
#define INPUT_Y1		(SIZE_WINDOW_Y-BUTT_Y_EXT20)
#define INPUT_X2		(INPUT_X1+SIZE_WINDOW_WIDE)
#define INPUT_Y2		(SIZE_WINDOW_Y+SIZE_WINDOW_HIGH+BUTT_Y_EXT20)
//主模式 按钮
#define WORK_MODE_X1		PROGRAM_X
#define WORK_MODE_Y1		PROGRAM_Y
#define WORK_MODE_X2		(WORK_MODE_X1+WORKMODE_WIDE)
#define WORK_MODE_Y2		(WORK_MODE_Y1+WORKMODE_HIGH)
//插入
#define INSERT_X1		(L_R_ARROW_X-BUTT_Y_EXT10)
#define INSERT_Y1		(L_R_ARROW_Y-BUTT_Y_EXT10)
#define INSERT_X2		(L_R_ARROW_X+F1_4_WIDE+BUTT_Y_EXT10)
#define INSERT_Y2		(L_R_ARROW_Y+F1_4_HIGH+BUTT_Y_EXT10)
//开始运行
#define START_X1		REMIND_WINDOW_X
#define START_Y1		(REMIND_WINDOW_Y-50)
#define START_X2		(START_X1+600)
#define START_Y2		479//(START_Y1+30)
//子菜单 向上
#define SUB_UP_TO_X1		(SUB_UP_ARROW_X-BUTT_Y_EXT10)
#define SUB_UP_TO_Y1		(SUB_UP_ARROW_Y-BUTT_Y_EXT10)
#define SUB_UP_TO_X2		(SUB_UP_ARROW_X+FORWARD_WIDE+BUTT_Y_EXT10)
#define SUB_UP_TO_Y2		(SUB_UP_ARROW_Y+FORWARD_HIGH+BUTT_Y_EXT10)
//子菜单 向下
#define SUB_DOWN_TO_X1		(SUB_DOWN_ARROW_X-BUTT_Y_EXT10)
#define SUB_DOWN_TO_Y1		(SUB_DOWN_ARROW_Y-BUTT_Y_EXT10)
#define SUB_DOWN_TO_X2		(SUB_DOWN_ARROW_X+FORWARD_WIDE+BUTT_Y_EXT10)
#define SUB_DOWN_TO_Y2		(SUB_DOWN_ARROW_Y+FORWARD_HIGH+BUTT_Y_EXT10)
//自刀提示 按钮
#define SELF_OK_X1		SELF_OK_X
#define SELF_OK_Y1		(SELF_OK_Y-BUTT_Y_EXT20)
#define SELF_OK_X2		(SELF_OK_X1+SELF_OK_WIDE)
#define SELF_OK_Y2		(SELF_OK_Y+SELF_OK_HIGH+BUTT_Y_EXT20)
//
#define SELF_CANCEL_X1		SELF_CANCEL_X
#define SELF_CANCEL_Y1		(SELF_CANCEL_Y-BUTT_Y_EXT20)
#define SELF_CANCEL_X2		(SELF_CANCEL_X1+SELF_OK_WIDE)
#define SELF_CANCEL_Y2		(SELF_CANCEL_Y+SELF_OK_HIGH+BUTT_Y_EXT20)
//----按钮 计数器
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
//手动 下  前进，后退
#define MAN_FORWARD_X1	MAN_FRONT_PAGE_X
#define MAN_FORWARD_Y1	MAN_FRONT_PAGE_Y
#define MAN_FORWARD_X2	(MAN_FORWARD_X1+FORWARD_WIDE)
#define MAN_FORWARD_Y2	(MAN_FORWARD_Y1+FORWARD_HIGH)

#define MAN_BACKWARD_X1	MAN_BACK_PAGE_X
#define MAN_BACKWARD_Y1	MAN_BACK_PAGE_Y
#define MAN_BACKWARD_X2	(MAN_BACKWARD_X1+FORWARD_WIDE)
#define MAN_BACKWARD_Y2	(MAN_BACKWARD_Y1+FORWARD_HIGH)
//手动 下	快退
#define MAN_FAST_BACK_X1 (MAN_FAST_BACK_X-BUTT_Y_EXT10)
#define MAN_FAST_BACK_Y1 (MAN_FAST_BACK_Y)
#define MAN_FAST_BACK_X2 (MAN_FAST_BACK_X+FORWARD_WIDE+BUTT_Y_EXT10)
#define MAN_FAST_BACK_Y2 (MAN_FAST_BACK_Y+FORWARD_HIGH)
//手动 下	快进
#define MAN_FAST_FWD_X1	 (MAN_FAST_FWD_X-BUTT_Y_EXT10)
#define MAN_FAST_FWD_Y1	 (MAN_FAST_FWD_Y)
#define MAN_FAST_FWD_X2	 (MAN_FAST_FWD_X+FORWARD_WIDE+BUTT_Y_EXT10)
#define MAN_FAST_FWD_Y2	 (MAN_FAST_FWD_Y+FORWARD_HIGH)


#define MAN_STOP_X1		MAN_STOP_X
#define MAN_STOP_Y1		(MAN_STOP_Y-10)
#define MAN_STOP_X2		(MAN_STOP_X+DELETE_WIDE+10)
#define MAN_STOP_Y2		(MAN_STOP_Y+DELETE_HIGH+20)

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

//手轮 开关 指示
#define WHEEL_SWITCH_X1		(WHEEL_STA_X-BUTT_Y_EXT30)
#define WHEEL_SWITCH_X2		(WHEEL_STA_X+64+BUTT_Y_EXT30)
#define WHEEL_SWITCH_Y1		(WHEEL_STA_Y-BUTT_Y_EXT30)
#define WHEEL_SWITCH_Y2		(WHEEL_STA_Y+64)

//--刀标记  触摸按钮
//F0 all cut flag
#define F0CUT_BUTTON_X1		F0_CUTYES_X
#define F0CUT_BUTTON_X2		(F0_CUTYES_X+DELETE_WIDE)
#define F0CUT_BUTTON_Y1		(F0_CUTYES_Y-BUTT_Y_EXT20)
#define F0CUT_BUTTON_Y2		(F0_CUTYES_Y+DELETE_HIGH+BUTT_Y_EXT20)
//F5 1 cut flag
#define F5CUT_BUTTON_X1		F5_CUTYES_X
#define F5CUT_BUTTON_X2		(F5_CUTYES_X+DELETE_WIDE)
#define F5CUT_BUTTON_Y1		(F5_CUTYES_Y-BUTT_Y_EXT20)
#define F5CUT_BUTTON_Y2		(F5_CUTYES_Y+DELETE_HIGH+BUTT_Y_EXT20)
//f5 压纸循环
#define F5PRE_FLG_X1	(F5_PRE_FLG_X-BUTT_Y_EXT20)
#define F5PRE_FLG_X2	(F5_PRE_FLG_X+F1_4_WIDE+BUTT_Y_EXT20)
#define F5PRE_FLG_Y1	F5_PRE_FLG_Y
#define F5PRE_FLG_Y2	(F5_PRE_FLG_Y+F1_4_WIDE)
//----------------------------------------------------------------------------

//F1 触摸校准--块
#define START_F1_TOU_X1		1
#define START_F1_TOU_Y1		1//START_HELP_TOU_Y1
#define START_F1_TOU_X2		799//300
#define START_F1_TOU_Y2		200//START_HELP_TOU_Y2




extern Int8U Touch_down_flag; 

extern Int32U Touch_code;
extern TOUCH Touch_Pos;


void ToucScan(void);
void TouchKey_exec(void);
void GetTouch_pos(void);
void GetTouchKeyCode(void);
void TouchButton_dis(Int32U code,Int8U down_flag);



#endif
