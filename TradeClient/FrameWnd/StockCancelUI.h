#ifndef __STOCK_CANCEL_UI_H__
#define __STOCK_CANCEL_UI_H__

#include "../Base/AbstractUI.h"

class CStockCancelUI : public CAbstractUI
{
public:
	CStockCancelUI(const CDuiString& strXML,CPaintManagerUI* pm);	
	
	~CStockCancelUI();

    void Initialize();

    CDuiString GetVirtualwndName();

    void RefreshWnd();

	int GetIndex(){return STOCK_CANCEL_NODE_INDEX;};

    DUI_DECLARE_MESSAGE_MAP()

public:
		virtual void OnClick(TNotifyUI& msg);

		virtual void OnSelectChanged( TNotifyUI &msg );

		virtual void OnItemClick( TNotifyUI &msg );

		virtual void OnItemActive( TNotifyUI &msg );

private:
	CButtonUI* m_pSelectAllBtn;

	CButtonUI* m_pCancelBtn;

	CButtonUI* m_pCancelAllBtn;

	CButtonUI* m_pCancelBuyBtn;

	CButtonUI* m_pCancelSellBtn;

	CEditUI* m_pStockIDEdt;

	CButtonUI* m_pSelectIDBtn;
};

#endif

