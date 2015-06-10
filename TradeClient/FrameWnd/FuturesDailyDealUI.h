#ifndef __FUTURES_DAILYDEAL_UI_H__
#define __FUTURES_DAILYDEAL_UI_H__

//#include "stdafx.h"
#include "../Base/AbstractUI.h"

class CFuturesDailyDealUI : public CAbstractUI
{
public:
	CFuturesDailyDealUI(const CDuiString& strXML,CPaintManagerUI* pm);

	~CFuturesDailyDealUI();

    void Initialize();

    CDuiString GetVirtualwndName();

    void RefreshWnd();

	int GetIndex(){return FUTURES_DAILYDEAL_NODE_INDEX;};

    DUI_DECLARE_MESSAGE_MAP()

public:
		virtual void OnClick(TNotifyUI& msg);

		virtual void OnSelectChanged( TNotifyUI &msg );

		virtual void OnItemClick( TNotifyUI &msg );

		virtual void OnItemActive( TNotifyUI &msg );

};

#endif

