#include "Board_Image_Deal.h"



uint8 Search_Start_Row=0;
uint8 Board_Left_Edge_Col[80];
uint8 Board_Left_Edge_Row[80];
uint8 Board_Right_Edge_Col[80];
uint8 Board_Right_Edge_Row[80];

uint8 Board_Left_Edge[80];
uint8 Board_Right_Edge[80];
uint8 Board_Center_Line[80];
//Ѱ���ѱ���ʼ��
void board_init_deal()
{
  Search_Start_Row=0;
    for(uint8 j=IMAGE_MID_COL_ROW;j>ROW_START;j--)//�м�����������
    {
//      //����׺�����֮�����������Ǻ���
//      if(image[i][IMAGE_MID_COL]==White && image[i-1][IMAGE_MID_COL]==Black )//&&image[i-2][IMAGE_MID_COL]==Black&&image[i-3][IMAGE_MID_COL]==Black&&image[i-4][IMAGE_MID_COL]==Black)
//      {
//        for(uint8 j=i-1;j>ROW_START;j--)//����������
//        {
          //����ѵ��ڰ�����֮�����ж��ǰ���
          if(image[j+3][IMAGE_MID_COL]==Black &&image[j+2][IMAGE_MID_COL]==Black &&image[j+1][IMAGE_MID_COL]==Black && image[j][IMAGE_MID_COL]==Black && image[j-1][IMAGE_MID_COL]==White && image[j-2][IMAGE_MID_COL]==White && image[j-3][IMAGE_MID_COL]==White)
          {
            for(uint8 k=j-1;k>ROW_START;k--)//����������
            {
              //����ѵ��ڰ�����֮���������ж��Ǻ���
              if(image[k][IMAGE_MID_COL]==White && image[k-1][IMAGE_MID_COL]==Black && image[k-2][IMAGE_MID_COL]==Black && image[k-3][IMAGE_MID_COL]==Black && image[k-4][IMAGE_MID_COL]==Black)
              {
                Search_Start_Row=j;//��ֵjΪ�ѱ���ʼ��
              }
            }
          }
//        }
//      }
    }
}


uint8 ns_left_judge(uint8 row,uint8 col)
{
  //������½��������������ز�ͬ������������������Ҳ��ͬ
  if(image[row][col]!=image[row+1][col-1] && image[row][col]!=image[row][col-1])
    return 1;
  //������½���������ͬ
  else if(image[row][col]!=image[row][col-1] && image[row][col]==image[row+1][col-1])
    return 2;
  //����������������ͬ�����ϲ�ͬ
  else if(image[row][col]==image[row][col-1] && image[row][col]==image[row+1][col-1] && image[row][col]!=image[row-1][col-1])
    return 3;
  //���У����£����Ͼ���������ͬ
  else if(image[row][col]==image[row][col-1] && image[row][col]==image[row+1][col-1] && image[row][col]==image[row-1][col-1])
    return 4;
  else 
    return 0;
}


uint8 ns_right_judge(uint8 row,uint8 col)
{
  //�������¾���ͬ
  if(image[row][col]!=image[row+1][col+1] && image[row][col]!=image[row][col+1])
    return 1;
  //������½���������ͬ
  else if(image[row][col]!=image[row][col+1] && image[row][col]==image[row+1][col+1])
    return 2;
  //����������������ͬ�����ϲ�ͬ
  else if(image[row][col]==image[row][col+1] && image[row][col]==image[row+1][col+1] && image[row][col]!=image[row-1][col+1])
    return 3;
  //���У����£����Ͼ���������ͬ
  else if(image[row][col]==image[row][col+1] && image[row][col]==image[row+1][col+1] && image[row][col]==image[row-1][col+1])
    return 4;
  else
    return 0;
}

//�������:row��col�ֱ���������ʼ����к���
void ns_left_search(uint8 row,uint8 col)
{
  uint8 point_condition;
  uint8 search_next_row;
  uint8 search_next_col;
  uint8 search_point=0;
  uint8 search_ending_count=0;
  
  search_next_row=row;
  search_next_col=col;
  while(search_point<80 && search_ending_count<3)//������������
  {
    point_condition=ns_left_judge(search_next_row,search_next_col);//�ж���ʼ�����
    switch(point_condition)
    {
    case 1:
      search_next_row=search_next_row+1;
      search_next_col=search_next_col;
      search_ending_count++;
      break;
    case 2:
      search_next_row=search_next_row+1;
      search_next_col=search_next_col-1;
      break;
    case 3:
      search_next_row=search_next_row;
      search_next_col=search_next_col-1;
      break;
    case 4:
      search_next_row=search_next_row-1;
      search_next_col=search_next_col-1;
      search_ending_count++;
      break;
    default:
      break;
    }
    Board_Left_Edge_Col[search_point]=search_next_col;
    Board_Left_Edge_Row[search_point]=search_next_row;
    search_point++;
  }
}
//�ұ�����
void ns_right_search(uint8 row,uint8 col)
{
  uint8 point_condition;
  uint8 search_next_row;
  uint8 search_next_col;
  uint8 search_point=0;
  uint8 search_ending_count=0;
  
  search_next_row=row;
  search_next_col=col;
  while(search_point<80 && search_ending_count<3)//������������
  {
    point_condition=ns_right_judge(search_next_row,search_next_col);//�ж���ʼ�����
    switch(point_condition)
    {
    case 1:
      search_next_row=search_next_row+1;
      search_next_col=search_next_col;
      search_ending_count++;
      break;
    case 2:
      search_next_row=search_next_row+1;
      search_next_col=search_next_col+1;
      break;
    case 3:
      search_next_row=search_next_row;
      search_next_col=search_next_col+1;
      break;
    case 4:
      search_next_row=search_next_row-1;
      search_next_col=search_next_col+1;
      search_ending_count++;
      break;
    default:
      break;
    }
    Board_Right_Edge_Col[search_point]=search_next_col;
    Board_Right_Edge_Row[search_point]=search_next_row;
    search_point++;
  }
}

void ns_search()
{
  ns_left_search(Search_Start_Row,IMAGE_MID_COL);
  ns_right_search(Search_Start_Row,IMAGE_MID_COL);
}

void Board_Edge_Search()
{
  memset(Board_Left_Edge ,0,sizeof(Board_Left_Edge));
  memset(Board_Right_Edge ,0,sizeof(Board_Right_Edge));
  for(uint8 i=ROW_END;i>ROW_START;i--)//������������
  {
    for(uint8 k=IMAGE_MID_COL;k>COL_START;k--)//���м�������
    {
      
      //����ѵ��ڰ�����֮���������ж��ǰ���
      if(image[i][k+3]==Black && image[i][k+2]==Black && image[i][k+1]==Black && image[i][k]==Black && image[i][k-1]==White && image[i][k-2]==White && image[i][k-3]==White)
      {
        for(uint8 l=k-1;l>COL_START;l--)//������������
        {
          //����ѵ��ڰ�����֮���������ж��Ǻ���
          if(image[i][l]==White && image[i][l-1]==Black && image[i][l-2]==Black && image[i][l-3]==Black && image[i][l-4]==Black)
          {
            Board_Left_Edge[i]=k;//��ֵkΪ�ѱ���ʼ��
          }
        }
      }
      
    }
    for(uint8 k=IMAGE_MID_COL;k<COL_END;k++)//����������
    {
      
      //����ѵ��ڰ�����֮���������ж��ǰ���
      if(image[i][k-3]==Black && image[i][k-2]==Black && image[i][k-1]==Black && image[i][k]==Black && image[i][k+1]==White && image[i][k+2]==White && image[i][k+3]==White)
      {
        for(uint8 l=k-1;l>COL_START;l--)//������������
        {
          //����ѵ��ڰ�����֮���������ж��Ǻ���
          if(image[i][l]==White && image[i][l+1]==Black && image[i][l+2]==Black && image[i][l+3]==Black && image[i][l+4]==Black)
          {
            Board_Right_Edge[i]=k;//��ֵkΪ�ѱ���ʼ��
          }
        }
      }
      
    }
    if(Board_Left_Edge[i]!=0 && Board_Right_Edge[i]!=0)
      Board_Center_Line[i]=(Board_Left_Edge[i]+Board_Right_Edge[i])>>1;
  }
}
