#ifndef __FUTURES_DAILYORDER_UI_H__
#define __FUTURES_DAILYORDER_UI_H__

//#include "stdafx.h"
#include "../Base/AbstractUI.h"

class CFuturesDailyOrderUI : public CAbstractUI
{
public:
	CFuturesDailyOrderUI(const CDuiString& strXML,CPaintManagerUI* pm);

	~CFuturesDailyOrderUI();

    void Initialize();

    CDuiString GetVirtualwndName();

    void RefreshWnd();

	int GetIndex(){return FUTURES_DAILYORDER_NODE_INDEX;};

    DUI_DECLARE_MESSAGE_MAP()

public:
		virtual void OnClick(TNotifyUI& msg);

		virtual void OnSelectChanged( TNotifyUI &msg );

		virtual void OnItemClick( TNotifyUI &msg );

		virtual void OnItemActive( TNotifyUI &msg );

};

#endif