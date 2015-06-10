#ifndef __FUND_SPLIT_UI_H__
#define __FUND_SPLIT_UI_H__

//#include "stdafx.h"
#include "../Base/AbstractUI.h"

class CFundSplitUI : public CAbstractUI
{
public:
	CFundSplitUI(const CDuiString& strXML,CPaintManagerUI* pm);

     ~CFundSplitUI();

    void Initialize();

    CDuiString GetVirtualwndName();

    void RefreshWnd();

	int GetIndex(){return FUND_SPLIT_NODE_INDEX;};

	DUI_DECLARE_MESSAGE_MAP()

public:
		virtual void OnClick(TNotifyUI& msg);

		virtual void OnSelectChanged( TNotifyUI &msg );

		virtual void OnItemClick( TNotifyUI &msg );

		virtual void OnItemActive( TNotifyUI &msg );
private:
	CLabelUI* m_pMomFundLab;

	CLabelUI* m_pAFundLab;

	CLabelUI* m_pBFundLab;

	CLabelUI* m_pSplitStatusLab;

	CLabelUI* m_pCanSplitNumLab;

	CEditUI* m_pSplitEdt;

	CButtonUI* m_pShareAddBtn;

	CButtonUI* m_pShareSubBtn;

	CButtonUI* m_pRefillBtn;

	CButtonUI* m_pSplitBtn;
	
	CTabLayoutUI* m_pSwitchTab;
};

#endif