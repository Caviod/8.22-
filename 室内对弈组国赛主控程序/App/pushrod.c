/******************************(C) COPYRIGHT 2019 SMU���ܳ�****************************
  *     @file           pushrod.c
  *     @brief          �Ƹ˿�
  *     @note
  *     @history
  *  Version    Date            Author          Modification
  *  V0.9.6     2019.6.30       min               debug
  ****************************(C) COPYRIGHT 2019 SMU���ܳ�*****************************/
#include "include.h"
#include "pushrod.h"


//�Ƹ˳�ʼ��
void pushrod_init()
{
   ftm_pwm_init(FTM0,Pushrod_CH0,Pushrod_Frequency,0);//Pushrod_OFF_Duty
   ftm_pwm_init(FTM0,Pushrod_CH1,Pushrod_Frequency,0);

   rod_up;
   systick_delay_ms(500);
   rod_static;
}

//�Ƹ˿��ƺ���
void rod_control(int8_t ud)
{
       if(ud == 1) //down
       {
	      ftm_pwm_duty(FTM0, Pushrod_CH0, Pushrod_ON_Duty);
	      ftm_pwm_duty(FTM0, Pushrod_CH1, Pushrod_OFF_Duty);
       }
       else if(ud == 2) //up
       {
	      ftm_pwm_duty(FTM0, Pushrod_CH0, Pushrod_OFF_Duty);
	      ftm_pwm_duty(FTM0, Pushrod_CH1, Pushrod_ON_Duty);
       }
       else  //stay
       {
	      ftm_pwm_duty(FTM0, Pushrod_CH0, Pushrod_OFF_Duty);
	      ftm_pwm_duty(FTM0, Pushrod_CH1, Pushrod_OFF_Duty);
       }
}

