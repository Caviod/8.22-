#include "common.h"
#include "include.h"


//��ʼ��Ӳ��
void BSP_Init(void)
{
       DisableInterrupts;
       /********************�ж����ȼ�����*******************/
       NVIC_SetPriorityGrouping(4);
       NVIC_SetPriority(CAN0_ORed_MB_IRQn, 0);//can�����ж����ȼ����
       NVIC_SetPriority(Qopenmv_IRQn, 1);   //OPENMV����
       NVIC_SetPriority(Yopenmv_IRQn, 1);   //OPENMV����
       NVIC_SetPriority(PIT0_IRQn,2);     //��misc.h    set_irq_priority(PORTD_IRQn,3);  �˺�����core_cm4.h��
       NVIC_SetPriority(PIT1_IRQn, 3);
       /*****************DMAͨ�����ȼ�����*****************/
       led_init (LED_MAX);
       key_init (KEY_MAX);                                        //������ʼ��
       /**********************************************************************************/
gpio_init(PTC13,GPO, 1);
/**********************************************************************************/
       pushrod_init();                                               //�Ƹ˳�ʼ��
/**********************************************************************************/
       electromagnet_init();                                         //�������ʼ��
/**********************************************************************************/
       RemoteInit();                                                 //ң������ʼ
/**********************************************************************************/
/**********************************************************************************/
       //version_init();                                               //�Ӿ���ʼ��
/**********************************************************************************/
       //GY901_init();
       PlannerError_uart_init();                                             //�����ǳ�ʼ��
       InitMPU6050();
/**********************************************************************************/
       LCD_Init();                                                   //OLED��ʼ��
//       pit_time_start(PIT1);                                         //�����Ʋ��ʱ
#if 1
       pit_time_start(PIT2);
       PIT_INIT();
#endif
       
/**********************************************************************************/
       Chassist_init(&RemoteData);        //PAODONG
       chassis_init();                                               //���̳�ʼ��
       EnableInterrupts;
}

unsigned char Flag_Holding = 0;
unsigned char Flag_Downing = 0;
extern unsigned char TaskIndex;


void OLED_Display()
{
    
}
unsigned long TimeMain = 0;
unsigned char Flag_SendIMUData = 0;
void  main(void)

{
       BSP_Init();  //��ʼ��
//       Dead_Recking_Reset(0, 0, 0);
       while(1)//1.9ms
       {
         Achieve_Gyro();
         //              Dead_Recking();
         if (Flag_Holding)
         {
           if (Check_HoldOrDownFinish())
           {
             Flag_Holding = 0;
           }
         }
         if (Flag_Downing)
         {
           if (Check_HoldOrDownFinish())
           {
             Flag_Downing = 0;
           }
         }
         
         if(Flag_SendIMUData) 
         {
           Flag_SendIMUData=0;
           Gyro_Send();//1.7ms
         }
         OLED_PrintFloat(0,0,DRx);
         OLED_PrintFloat(0,1,DRy);
         OLED_PrintFloat(0,2,DRw);
         LCD_Print16(0,3,gz);
         OLED_PrintFloat(0,4,Distance);
       }
}

