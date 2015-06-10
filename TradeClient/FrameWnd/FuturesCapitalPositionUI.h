#ifndef __FUTURES_CAPITALPOSITION_UI_H__
#define __FUTURES_CAPITALPOSITION_UI_H__

//#include "stdafx.h"
#include "../Base/AbstractUI.h"

class CFuturesCapitalPositionUI : public CAbstractUI
{
public:
	CFuturesCapitalPositionUI(const CDuiString& strXML,CPaintManagerUI* pm);

	~CFuturesCapitalPositionUI();

    void Initialize();

    CDuiString GetVirtualwndName();

    void RefreshWnd();

	int GetIndex(){return FUTURES_CAPITALPOSITION_NODE_INDEX;};

    DUI_DECLARE_MESSAGE_MAP()

public:
		virtual void OnClick(TNotifyUI& msg);

		virtual void OnSelectChanged( TNotifyUI &msg );

		virtual void OnItemClick( TNotifyUI &msg );

		virtual void OnItemActive( TNotifyUI &msg );

private:
	CLabelUI* m_pRemainCapitalLab;

	CLabelUI* m_pFreezeCapitalLab;

	CLabelUI* m_pTotalCapitalLab;

	CLabelUI* m_pCanUseCapitalLab;

	CLabelUI* m_pMarketValueLab;
};

#endif

