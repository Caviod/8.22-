/**
  ****************************(C) COPYRIGHT 2019 SMU���ܳ�****************************
  *     @file           queen.h
  *     @brief          �˻ʺ������ͷ�ļ�
  *     @note           
  *     @history
  *  Version    Date            Author          Modification
  *  V0.9.6     2019.6.26       min               debug
  ****************************(C) COPYRIGHT 2019 SMU���ܳ�****************************
  */
#ifndef __QUEEN_H
#define __QUEEN_H

#include "include.h"

//�˴�ö��Ϊ�˻ʺ�������
enum
{
  Get_Queen_Location=0,//��ȡ�ʺ������
  Go_To_Chessboard,//ǰ������
  Queen_Process,//�˻ʺ����

  Total_Task_Amount                //�ܵ�����������
};

//�˴�ö��Ϊ�����ƶ�����
enum
{
  Go_To_Queen=0,//ǰ������
  Pick_Queen,//ץ��ʺ���
  Go_To_Destination,//ǰ��Ŀ������
  Put_Queen,//���ûʺ���
  
  Total_Process_Task_Amount           //�ܵ�����������
};

//�˽ṹ�嶨����˻ʺ�����ı���
typedef struct __Queen
{
  uint8 Queen_Loaction[8][2];//�˻ʺ�˸�����λ���Լ�Ŀ��λ��
  
  
}QueenTypeDef;

#endif