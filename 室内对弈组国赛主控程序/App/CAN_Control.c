/******************************(C) COPYRIGHT 2019 SMU���ܳ�****************************
*     @file           CAN_Control.c
*     @brief          CAN���߿���
*     @note
*     @history
*  Version    Date            Author          Modification
*  V1.0.1     2019.5.19       min               finish
****************************(C) COPYRIGHT 2019 SMU���ܳ�*****************************/
#include "include.h"
#include "CAN_Control.h"

//*************�������߱���***************
uint8 CAN_Control_Data[8];              /*CAN��������*/
CAN_USR_ID_t can_tx_id = {CAN_TX_ID,0,0};/*CAN��ID����*/
str_MotorData  MotorData[4];
//*************�������߱���***************
uint8 CAN_Receive_Data[8];              /*CAN��������*/
uint8 rx_buf_len;                       /*CAN�������ݳ���*/
uint8 Motor_Data[4][8];                 /*�����ĸ�2006���������ʵʱ����*/
uint8 CAN_Receive_Flag;                 /*CAN���յ����ݱ�־*/
CAN_USR_ID_t can_rx_id;                 /*CAN����ID*/
uint16   CAN_Receive_id ;
//************���庯��*********************
void CAN_Get_Message();
void can0_mb_handler();//�����ж�
void Chassis_CAN_Cmd(int16 Motor1_Speed,int16 Motor2_Speed,int16 Motor3_Speed,int16 Motor4_Speed);//����CAN���������


/*******************************************�ָ���***********************************************/
/*
* @brief          CAN��ʼ������
* @author             ������
* @retval             ���ؿ�
*/
void CAN_Init()           //����CAN���߳�ʼ��
{
       can_init(Chassis_CAN_CH,CAN_BAUD_1M,CAN_NORMAL,CAN_CLKSRC_BUS);                      //��ʼ��can��������1MHZ������ģʽ ,bus ʱ����Ϊʱ��Դ
       set_vector_handler(CAN_VECTOR,can0_mb_handler);                                       //����CAN�����жϷ��������ж�������
       can_rxbuff_enble(Chassis_CAN_CH,CAN_RX_MB,can_rx_id);                                  //ʹ�ܽ��ջ�����
       can_irq_en(Chassis_CAN_CH,CAN_RX_MB);                                                 //ʹ��CAN�����ж�
}

/**
* @brief          ����CAN���߷��͹���������
* @param[in]      Motor_Speed:�ĸ���������߸�ֵ - �����ɸ�
* @author         ������
* @retval         ���ؿ�
*/
void Chassis_CAN_Cmd(int16 Motor1_Speed,int16 Motor2_Speed,int16 Motor3_Speed,int16 Motor4_Speed)
{
       can_irq_dis(Chassis_CAN_CH,CAN_RX_MB);
       CAN_Control_Data[0]=(Motor1_Speed>>8)&0xff;               //���Ƶ����ĸ߰�λ
       CAN_Control_Data[1]=Motor1_Speed&0xff;                    //���Ƶ����ĵͰ�λ

       CAN_Control_Data[2]=(Motor2_Speed>>8)&0xff;               //���Ƶ����ĸ߰�λ
       CAN_Control_Data[3]=Motor2_Speed&0xff;                    //���Ƶ����ĵͰ�λ

       CAN_Control_Data[4]=(Motor3_Speed>>8)&0xff;               //���Ƶ����ĸ߰�λ
       CAN_Control_Data[5]=Motor3_Speed&0xff;                    //���Ƶ����ĵͰ�λ

       CAN_Control_Data[6]=(Motor4_Speed>>8)&0xff;               //���Ƶ����ĸ߰�λ
       CAN_Control_Data[7]=Motor4_Speed&0xff;                    //���Ƶ����ĵͰ�λ

       can_tx(Chassis_CAN_CH,CAN_TX_MB,can_tx_id,8,CAN_Control_Data);
       can_irq_en(Chassis_CAN_CH,CAN_RX_MB);
}

/**
* @brief          ����CAN���߷��͹���������
* @author         ������
* @retval         ���ؿ�
*/
void CAN_Get_Message()//CAN�������ݣ��ú������жϴ���
{
       can_rx(Chassis_CAN_CH,CAN_RX_MB,&can_rx_id,&rx_buf_len,CAN_Receive_Data);//��������
       switch (can_rx_id.ID)
       {
	    case 0x201:
	      {
		     MotorData[0].Rpm =CAN_Receive_Data[2]<<8|(CAN_Receive_Data[3]&0xff);
		     break;
	      }
	    case 0x202:
	      {
		     MotorData[1].Rpm  =CAN_Receive_Data[2]<<8|(CAN_Receive_Data[3]&0xff);
		     break;
	      }
	    case 0x203:
	      {
		     MotorData[2].Rpm =CAN_Receive_Data[2]<<8|(CAN_Receive_Data[3]&0xff);
		     break;
	      }
	    case 0x204:
	      {
		     MotorData[3].Rpm =CAN_Receive_Data[2]<<8|(CAN_Receive_Data[3]&0xff);
		     break;
	      }
       }
       gpio_turn(PTE26);   //��ת��ƽ
}

/**
* @brief          CAN���߽����жϷ�����
* @author
* @retval         ���ؿ�
*/
void can0_mb_handler(void)
{
       can_clear_flag(Chassis_CAN_CH,CAN_RX_MB);        //����������жϱ�־λ
       CAN_Get_Message();
}

