#ifndef __USER_MESSAGE_H__
#define __USER_MESSAGE_H__

#define WM_USER_TIME_CLOCK		WM_USER + 1 //ʱ�Ӹ���

#define WM_USER_RETURN_RESPOND  WM_USER + 2 //Ӧ����Ϣ

#define WM_USER_PRODUCTLIST_REQ	WM_USER + 3 //��Ʒ�б�����
/*
#define WM_USER_LOGIN_RES		WM_USER + 2 //��½��ϢӦ��

#define WM_USER_STOCK_QUOTA_REQ      WM_USER + 4 //��������

#define WM_USER_STOCK_QUOTA_RES      WM_USER + 5 //����Ӧ��

#define WM_USER_STOCK_ORDER_REQ	WM_USER + 6 //��Ʊί������

#define WM_USER_STOCK_ORDER_RES	WM_USER + 7 //��Ʊί��Ӧ��

#define WM_USER_STOCK_DEAL_REQ	WM_USER + 8 //��Ʊ�ɽ�����

#define WM_USER_STOCK_DEAL_RES	WM_USER + 9 //��Ʊ�ɽ�Ӧ��

#define WM_USER_STOCK_POSITION_REQ	WM_USER + 10 //��Ʊ�ֲ�����

#define WM_USER_STOCK_POSITION_RES	WM_USER + 11 //��Ʊ�ֲ�Ӧ��
*/
class loginres
{
public:
	bool status;
};

#endif