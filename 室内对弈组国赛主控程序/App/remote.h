/**
  ****************************(C) COPYRIGHT 2019 SMU���ܳ�ʵ����****************************
  *     @file           remote.h
  *     @brief          ң�ؿ�ͷ�ļ�
  *     @note
  *     @history
  *  Version    Date            Author          Modification
  *  V1.0.0     2019.6.10      ���Ʒ�                Finish
  ****************************(C) COPYRIGHT 2019 SMU���ܳ�ʵ����****************************
  */
#ifndef __REMOTE_H
#define __REMOTE_H

#include "include.h"
extern void initialization();
extern void get_speed();
extern void get_XYZ(int X,int Y, int Z);
extern void get_TargetSpeed();
extern void calculate_error();
extern void calculate_PID_output();
extern void calculate_output();
extern void get_lasttargetspeed();
extern void OpenMVCollectInit();

//�������
extern int16 output[4];
extern int16 Now_Speed[4];      //��ǰcan���͹������ĸ����ӵ��ٶ� 0��ǰ�� 1��ǰ��  2�Һ��� 3�����
extern int16 TargetSpeed[4];    //����Ŀ��ֵ
extern int16 NowError[4];       //���ֵ�ǰƫ��
extern int16 LastError[4];      //�����ϴ�ƫ��
extern int16 PrevError[4];      //�������ϴ�ƫ��

extern int X_Speed,Y_Speed,Z_Speed;




# define Remote_Uart_Port UART1//0
# define Collect_Uart_Port UART5//0
# define OpenMVCollect_Uart_Port UART3//0

typedef enum
{
  Left_Return0,
  Left_Left,
  Left_Right,
  Left_Up,
  Left_Down,
  Right_Return0,
  Right_Left,
  Right_Right,
  Right_Up,
  Right_Down,
  Start
}RemoteCMDMode;

/// <summary>
///����ң��ָ�����Ӧ�����Ӧ�Ĵ����ж���
///</summary>
void ReceiveCMD_Remote();
/// <summary>
///��ʼ��ң�����Ĵ���
///</summary>
void RemoteInit();


#ifndef Remote_UseDigitalReceive
typedef enum
{
    Sleep,
    SendLeftCMD,
    ReceivingLeftCMD,
    ReceivedLeftCMD,
    SendRightCMD,
    ReceivingRightCMD,
    ReceivedRightCMD
}Remote_State;


typedef struct
{
    uint8 Left_X;
    uint8 Left_Y;
    uint8 Right_X;
    uint8 Right_Y;
}ReceiveCMDData;
void GetRemoteCMDData(void);

#endif

extern unsigned char Flag_RemoteStopCar;

void SetSpeed_FromRemote_Analog(void);
extern ReceiveCMDData RemoteData;
extern void Chassist_init(ReceiveCMDData *Initial_Remote);
#endif