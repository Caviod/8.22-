/**
  ****************************(C) COPYRIGHT 2019 SMU���ܳ�****************************
  *     @file           destination.c
  *     @brief          Ŀ������
  *     @note           ���Ŀ���Ƕ��������װ�ɺ���������е���
  *     @history
  *  Version    Date            Author          Modification
  *  V0.9.6     2019.6.26       min               debug
  ****************************(C) COPYRIGHT 2019 SMU���ܳ�****************************
  */
#include "destination.h"
/*��������*/
void destination(uint8 Destination);
void destination_init(void);//�����ʼ��
void car_position_update(PositionTypeDef *Position_t);//���µ�ǰ��λ����Ϣ
void destination_calculate(PositionTypeDef *Position_t,uint8 Destination);

/*ȫ�ֱ�������*/
//��������
uint8 ChessBoard[8][8]=
{
  {1,   2,      3,      4,      5,      6,      7,      8},
  {9,   10,     11,     12,     13,     14,     15,     16},
  {17,  18,     19,     20,     21,     22,     23,     24},
  {25,  26,     27,     28,     29,     30,     31,     32},
  {33,  34,     35,     36,     37,     38,     39,     40},
  {41,  42,     43,     44,     45,     46,     47,     48},
  {49,  50,     51,     52,     53,     54,     55,     56},
  {57,  58,     59,     60,     61,     62,     63,     64}
};
//AprilTag�ֲ�����
uint8 TagBoard[8][4]=
{
  {0,   1,      2,      3},
  {4,   5,      6,      7},
  {8,   9,      10,     11},
  {12,  13,     14,     15},
  {16,  17,     18,     19},
  {20,  21,     22,     23},
  {24,  25,     26,     27},
  {28,  29,     30,     31}
};
PositionTypeDef CarPosition;
PositionTypeDef Tag1Position;
PositionTypeDef Tag2Position;
PositionTypeDef DestinationPosition;

//�����ʼ��
void destination_init()
{

}

//���������ܺ���
void destination(uint8 Destination)
{
  car_position_update(&CarPosition);//���µ�ǰ����λ����Ϣ
  if(CarPosition.Now_Position==Destination)//�����ǰλ���Ѿ�������Ŀ��λ�ã��򷵻�
    return;
  destination_calculate(&DestinationPosition,Destination);//����Ŀ����к���

}

//����Ŀ����λ��
void destination_calculate(PositionTypeDef *Position_t,uint8 Destination)
{
  Position_t->Row_Position=Destination/4+1;//����Ϣ����������4��1
  if(Position_t->Row_Position%2==1)//��Ϊ�����У����е����������Զ���һ
    Position_t->Col_Position=Destination%4*2+1;
  else if(Position_t->Row_Position%2==0)//��Ϊż���У������������������Զ��Ӷ�
    Position_t->Col_Position=Destination%4*2+2;
}
//���³�λ��
void car_position_update(PositionTypeDef *Position_t)
{
  //position_calculate(&Tag1Position,&Openmv1_Msg);
 // position_calculate(&Tag2Position,&Openmv2_Msg);

  Position_t->Col_Position=Tag1Position.Col_Position;
  Position_t->Row_Position=Tag2Position.Row_Position;
  Position_t->Now_Position=ChessBoard[Position_t->Col_Position][Position_t->Row_Position];
}

//λ�ü���
//void position_calculate(PositionTypeDef *Position_t,AprilTag_MSG *Openmv_Msg_t)
//{
//  Position_t->Row_Position=Openmv_Msg_t->tag_id/4+1;//����Ϣ����������4��1
//  if(Position_t->Row_Position%2==1)//��Ϊ�����У����е����������Զ���һ
//    Position_t->Col_Position=Openmv_Msg_t->tag_id%4*2+1;
//  else if(Position_t->Row_Position%2==0)//��Ϊż���У������������������Զ��Ӷ�
//    Position_t->Col_Position=Openmv_Msg_t->tag_id%4*2+2;
//  Position_t->Now_Position=ChessBoard[Position_t->Col_Position][Position_t->Row_Position];//������л�ȡλ����Ϣ
//}



