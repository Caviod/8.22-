#ifndef __VERSION_H__
#define  __VERSION_H__



#define Qopenmv_UART_Port UART0
#define Yopenmv_UART_Port UART2


#define Qopenmv_Vector  UART0_RX_TX_VECTORn
#define Yopenmv_Vector  UART2_RX_TX_VECTORn

#define Qopenmv_IRQn  UART0_RX_TX_IRQn
#define Yopenmv_IRQn  UART2_RX_TX_IRQn


#define Openmv_Baud 115200


typedef struct
{
       int Mid_X;
       int Mid_Y;//���յ��ķ��������������ֵ
       int Curl;    //����

       unsigned char RxBuffer[5];
       unsigned char RxCnt;
       unsigned char Block_Count_Flag;
       /*��������ر���*/
       int Block_Count;//���Ӽ���
       int Mid_Y_Last;//��һ�ν��յķ�������������ֵ
       int Mid_X_Last;
       int Block_Jump_flag;//�жϷ�������ı�־λ
       int Jump_Count;//������ά�ּ���
}Str_Openmv;


extern void version_init();
extern Str_Openmv  Qopenmv;
extern Str_Openmv  Yopenmv;

#endif