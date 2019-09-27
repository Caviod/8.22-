/**
  ****************************(C) COPYRIGHT 2019 SMU���ܳ�****************************
  *     @file           CAN_Control.h
  *     @brief          CAN���߿���ͷ�ļ�
  *     @note
  *     @history
  *  Version    Date            Author          Modification
  *  V1.0.1     2019.5.19       min               finish
  ****************************(C) COPYRIGHT 2019 SMU���ܳ�****************************
  */
#ifndef __CAN_CONTROL_H
#define __CAN_CONTROL_H


#define CAN_TX_ID          0x200
#define CAN_RX_ID          0x201


#define Chassis_CAN_CH    CAN0
#define CAN_VECTOR        CAN0_ORed_MB_VECTORn

#define CAN_TX_MB       MB_NUM_7            //����MBs��������
#define CAN_RX_MB       MB_NUM_6            //����MBs��������
#define DATA_LEN        8                   //can ���͵����ݳ��ȣ����Ϊ8




typedef struct
{
  short Angle;  //��е�Ƕ�
  short Rpm;    //ת��
  short Torque ;// ת��
  short Speed_Out ;//
}str_MotorData;

extern str_MotorData  MotorData[4];

extern void CAN_Init();
extern void Chassis_CAN_Cmd(int16 Motor1_Speed,int16 Motor2_Speed,int16 Motor3_Speed,int16 Motor4_Speed);

extern uint16 CAN_Receive_id ;                 /*CAN����ID*/
extern uint8 rx_buf_len;                       /*CAN�������ݳ���*/
extern uint8 CAN_Receive_Buf[16];              /*CAN��������*/
extern uint8 CAN_Receive_Flag;                  /*CAN���յ����ݱ�־*/
extern uint8 Motor_Data[4][8];                  /*�����ĸ������CAN���߷�������*/

#endif