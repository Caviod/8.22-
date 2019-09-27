# ifndef _EQTASK_H_
# define _EQTASK_H_

//˳��Ĺ���
typedef enum
{
    Forward,
    Back,
    Left,
    Right,
    Stop,
    HoldChess,
    DownChess,
    Forward_Left,
    SpecialStop,
    SpecialForward,
    YuandiXuanzhuan_You,
    NoneCMD
}_EQ_RunCMD;//һ�����������ָ��ö��

typedef struct
{
    _EQ_RunCMD TaskCommand;//�����������ָ��
    int TaskPara;//����������в�������TaskCommand���ʹ�þ��൱�ڴ�����ǰ��2������ָ��
    int TaskProcess;//������Ľ���ֵ����������Ľ���ֵ=TaskParaʱ�������
    unsigned char IsFinish;//�������Ƿ����
}_EQ_Task;//һ������Ľṹ��

void RenewTaskProcess(_EQ_Task * NowTask);
void CreateTaskPool();
void DoTask();
extern void ConfigTask(_EQ_Task * NowTask, _EQ_RunCMD CMD, int Para);
extern _EQ_Task EQ_TaskPool[60];//�����

extern void DoTaskEx(uint8 action);
# endif