#include "include.h"
#include "version.h"

Str_Openmv  Qopenmv={0};
Str_Openmv  Yopenmv={0};
/**********************************�ָ���*******************************************/
void X_block_count(Str_Openmv * OpenMV);

void Rec_Qopenmv_handler()
{
       uart_getchar(Qopenmv_UART_Port,&Qopenmv.RxBuffer[Qopenmv.RxCnt++]);
       if (Qopenmv.RxBuffer[0]!='A') //�ж�����ͷ
       {
	      Qopenmv.RxCnt = 0;
	      return;
       }
       if (Qopenmv.RxCnt < 4)
       {
	      return;
       }
       else
       {
	      Qopenmv.Mid_X=Qopenmv.RxBuffer[1]-80;
	      Qopenmv.Curl=Qopenmv.RxBuffer[2]-128;
	      Qopenmv.Mid_Y=Qopenmv.RxBuffer[3];
              X_block_count(&Qopenmv);
	      Qopenmv.RxCnt = 0;
       }
}

void Rec_Yopenmv_handler()
{
       uart_getchar(Yopenmv_UART_Port,&Yopenmv.RxBuffer[Yopenmv.RxCnt++]);
       if (Yopenmv.RxBuffer[0]!='A') //�ж�����ͷ
       {
	      Yopenmv.RxCnt = 0;
	      return;
       }
       if (Yopenmv.RxCnt < 4)
       {
	      return;
       }
       else
       {
	      Yopenmv.Mid_X=Yopenmv.RxBuffer[1]-80;
	      Yopenmv.Curl=Yopenmv.RxBuffer[2]-128;
	      Yopenmv.Mid_Y=Yopenmv.RxBuffer[3];
              X_block_count(&Yopenmv);
              
	      Yopenmv.RxCnt = 0;
       }
}

void Qopenmv_init()     //ǰOPENMV��ʼ��
{
       uart_init(Qopenmv_UART_Port,Openmv_Baud);
       set_vector_handler(Qopenmv_Vector,Rec_Qopenmv_handler); //ע����
       uart_rx_irq_en(Qopenmv_UART_Port);
}




void Yopenmv_init()     //ǰOPENMV��ʼ��
{
       uart_init(Yopenmv_UART_Port, Openmv_Baud);
       set_vector_handler(Yopenmv_Vector, Rec_Yopenmv_handler); //ע����
       uart_rx_irq_en(Yopenmv_UART_Port);
}



void version_init()
{
       Qopenmv_init();
       Yopenmv_init();
}

#define Jump_Standard 30//������߶�
#define Jump_Keep 3//����󱣳ֲ�����ļ���

void X_block_count(Str_Openmv * OpenMV)
{
  
  if(OpenMV->Block_Count_Flag==0&&OpenMV->Mid_X_Last!=0)
  {
    OpenMV->Block_Count_Flag=1;
    OpenMV->Block_Count++;
  }
  
    //��������־λû�б���λ��˵��û�з������䣬�����ʱ��ǰ����������ֵ��ȥ��������ֵ����30�У����ж������˵�һ�����䡪��ǰ������
  if (OpenMV->Mid_X_Last - OpenMV->Mid_X>Jump_Standard && OpenMV->Mid_X<0 &&OpenMV->Mid_X_Last>0)
    {
      OpenMV->Block_Count++;
    }
    //��������־λû�б���λ��˵��û�з������䣬�����ʱ��ǰ����������ֵ��ȥ��������ֵС��-30�У����ж������˵ڶ������䡪����������
    else if (OpenMV->Mid_X_Last - OpenMV->Mid_X<-Jump_Standard && OpenMV->Mid_X>0 &&OpenMV->Mid_X_Last<0)
    {
       OpenMV->Block_Count--;
    }
//SEND(10*Yopenmv.Block_Count, Yopenmv.Mid_X, Yopenmv.Mid_X_Last, 0);
    OpenMV->Mid_X_Last = OpenMV->Mid_X;
}

