#ifndef __FUTURES_PASTORDER_UI_H__
#define __FUTURES_PASTORDER_UI_H__

//#include "stdafx.h"
#include "../Base/AbstractUI.h"

class CFuturesPastOrderUI : public CAbstractUI
{
public:
	CFuturesPastOrderUI(const CDuiString& strXML,CPaintManagerUI* pm);

	~CFuturesPastOrderUI();

    void Initialize();

    CDuiString GetVirtualwndName();

    void RefreshWnd();

	int GetIndex(){return FUTURES_PASTORDER_NODE_INDEX;};

    DUI_DECLARE_MESSAGE_MAP()

public:
		virtual void OnClick(TNotifyUI& msg);

		virtual void OnSelectChanged( TNotifyUI &msg );

		virtual void OnItemClick( TNotifyUI &msg );

		virtual void OnItemActive( TNotifyUI &msg );

private:
	CDateTimeUI* m_pBeginDateTime;

	CDateTimeUI* m_pEndDateTime;

	CButtonUI* m_pSureBtn;
};

#endif

