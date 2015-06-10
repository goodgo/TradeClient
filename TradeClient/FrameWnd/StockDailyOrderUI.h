#ifndef __STOCK_DAILYORDER_UI_H__
#define __STOCK_DAILYORDER_UI_H__

//#include "stdafx.h"
#include "../Base/AbstractUI.h"

class CStockDailyOrderUI : public CAbstractUI
{
public:
	CStockDailyOrderUI(const CDuiString& strXML,CPaintManagerUI* pm);

	~CStockDailyOrderUI();

    void Initialize();

    CDuiString GetVirtualwndName();

    void RefreshWnd();

	int GetIndex(){return STOCK_DAILYORDER_NODE_INDEX;};

    DUI_DECLARE_MESSAGE_MAP()

public:
		virtual void OnClick(TNotifyUI& msg);

		virtual void OnSelectChanged( TNotifyUI &msg );

		virtual void OnItemClick( TNotifyUI &msg );

		virtual void OnItemActive( TNotifyUI &msg );

};

#endif