#ifndef __STOCK_DAILYDEAL_UI_H__
#define __STOCK_DAILYDEAL_UI_H__

//#include "stdafx.h"
#include "../Base/AbstractUI.h"

class CStockDailyDealUI : public CAbstractUI
{
public:
	CStockDailyDealUI(const CDuiString& strXML,CPaintManagerUI* pm);

	~CStockDailyDealUI();

    void Initialize();

    CDuiString GetVirtualwndName();

    void RefreshWnd();

	int GetIndex(){return STOCK_DAILYDEAL_NODE_INDEX;};

    DUI_DECLARE_MESSAGE_MAP()

public:
		virtual void OnClick(TNotifyUI& msg);

		virtual void OnSelectChanged( TNotifyUI &msg );

		virtual void OnItemClick( TNotifyUI &msg );

		virtual void OnItemActive( TNotifyUI &msg );

};

#endif

