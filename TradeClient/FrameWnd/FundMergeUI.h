#ifndef __FUND_MERGE_UI_H__
#define __FUND_MERGE_UI_H__

//#include "stdafx.h"
#include "../Base/AbstractUI.h"

class CFundMergeUI : public CAbstractUI
{
public:
	CFundMergeUI(const CDuiString& strXML,CPaintManagerUI* pm);

     ~CFundMergeUI();

    void Initialize();

    CDuiString GetVirtualwndName();

    void RefreshWnd();

	int GetIndex(){return FUND_MERGE_NODE_INDEX;};

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

	CLabelUI* m_pMergeStatusLab;

	CLabelUI* m_pCanMergeNumLab;

	CEditUI* m_pMergeEdt;

	CButtonUI* m_pShareAddBtn;

	CButtonUI* m_pShareSubBtn;

	CButtonUI* m_pRefillBtn;

	CButtonUI* m_pMergeBtn;
	
	CTabLayoutUI* m_pSwitchTab;
};

#endif