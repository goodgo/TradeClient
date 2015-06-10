#ifndef __USER_MESSAGE_H__
#define __USER_MESSAGE_H__

#define WM_USER_TIME_CLOCK		WM_USER + 1 //时钟更新

#define WM_USER_RETURN_RESPOND  WM_USER + 2 //应答消息

#define WM_USER_PRODUCTLIST_REQ	WM_USER + 3 //产品列表请求
/*
#define WM_USER_LOGIN_RES		WM_USER + 2 //登陆消息应答

#define WM_USER_STOCK_QUOTA_REQ      WM_USER + 4 //行情请求

#define WM_USER_STOCK_QUOTA_RES      WM_USER + 5 //行情应答

#define WM_USER_STOCK_ORDER_REQ	WM_USER + 6 //股票委托请求

#define WM_USER_STOCK_ORDER_RES	WM_USER + 7 //股票委托应答

#define WM_USER_STOCK_DEAL_REQ	WM_USER + 8 //股票成交请求

#define WM_USER_STOCK_DEAL_RES	WM_USER + 9 //股票成交应答

#define WM_USER_STOCK_POSITION_REQ	WM_USER + 10 //股票持仓请求

#define WM_USER_STOCK_POSITION_RES	WM_USER + 11 //股票持仓应答
*/
class loginres
{
public:
	bool status;
};

#endif