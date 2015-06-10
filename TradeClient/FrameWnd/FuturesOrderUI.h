#ifndef __FUTURES_ORDER_UI_H__
#define __FUTURES_ORDER_UI_H__

//#include "stdafx.h"
#include "../Base/AbstractUI.h"

class CFuturesOrderUI : public CAbstractUI
{
public:
	CFuturesOrderUI(const CDuiString& strXML,CPaintManagerUI* pm);

	~CFuturesOrderUI();

	void Initialize();

    CDuiString GetVirtualwndName();

    void RefreshWnd();

	int GetIndex(){return FUTURES_ORDER_NODE_INDEX;};

    LPCTSTR GetItemText(CControlUI* pControl, int iIndex, int iSubItem);

    DUI_DECLARE_MESSAGE_MAP()

public:
		virtual void OnClick(TNotifyUI& msg);

		virtual void OnSelectChanged( TNotifyUI &msg );

		virtual void OnItemClick( TNotifyUI &msg );

		virtual void OnItemActive( TNotifyUI &msg );

private:

};

#endif

