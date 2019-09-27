/******************************(C) COPYRIGHT 2019 SMU���ܳ�****************************
  *     @file           chassis.h
  *     @brief          ʵ�ֵ��̵Ŀ���
  *     @note
  *     @history
  *  Version    Date            Author          Modification
  *  V1.0.1     2019.6.8        min               debug
****************************(C) COPYRIGHT 2019 SMU���ܳ�*****************************/
#ifndef __CHASSIS_H
#define __CHASSIS_H

#include "include.h"



#define Chassis_PID_Maxout  16000
#define Chassis_PID_Maxiout 10000

#define Chassis_Kp 1.5//1.5
#define Chassis_Ki 0.005//0.005
#define Chassis_Kd 0//0


#define Angle_PID_Maxout 3000
#define Angle_PID_Maxiout 3000

//#define speed_max   2000
//#define Angle_Kp 5  //9
//#define Angle_Ki 0
//#define Angle_Kd 0 //39

//#define FrontLine_PID_Maxout 1000
//#define FrontLine_PID_Maxiout 0

typedef enum
{
       Chassis_Stable,//�����ȶ�ģʽ
       Chassis_Remote,//����ң��ģʽ
       Chassis_Round,
       Angle_X_Loop ,
       Q_MidX_Z_LOOP,
       Y_Mid_Z_LOOP,
       Y_Curl_Z_loop,
       Q_Curl_Z_loop,
       QZ_CH_CX_loop,
       QZ_CH_CX_loop2,
       QZ_CH_CX_loop333,
       DA_Loop
}ControlMode;

typedef enum
{
       MVerr_loop,
       MVCurl_LOOP,
       Cemian_MVCurl_LOOP,
       Yaw_Loop,
       Cemian_MVerr_LOOP,
       Q_MVCurl_LOOP,
       Image_Loop,
       Direction_Angle_Loop
}Enum_AngleMode;

typedef struct __Chassis_t
{
  int Chassis_Now_Speed[4];
  int Chassis_Speed[4];                //��������������ķ�����ָ�ֵ
  int Chassis_Give_Current[4];        //PID������ĸ����Ӹ�ֵ
}Chassis_t;

extern int AngleControlValue ;//ƫ���Ǳջ�������
extern int XControlValue;//ƫ���Ǳջ�������
extern int YControlValue ;
extern float dist_to_target;



extern ControlMode NowMode;
extern void chassis_init(void);
extern void chassis_inverse(int *vx, int *vy, int *wz, int Wheel_Speed[]);
extern void chassis(uint8 ChassisMode,int CSPEED);




//���̿��Ƶ��ܺ���
extern void RemoteControl(float RemoteWz);

extern Chassis_t Chassis_Motion;
#endif