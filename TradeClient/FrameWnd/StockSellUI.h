#ifndef __STOCK_SELL_UI_H__
#define __STOCK_SELL_UI_H__

#include "../Base/AbstractUI.h"

class CStockSellUI : public CAbstractUI
{
public:
	CStockSellUI(const CDuiString& strXML,CPaintManagerUI* pm);	
	
	~CStockSellUI();

    void Initialize();

    CDuiString GetVirtualwndName();

    void RefreshWnd(void);	

    int GetIndex(){return STOCK_SELL_NODE_INDEX;};

private:

	void OnPriceAdd(void);

	void OnPriceSub(void);

	void OnRefill(void);

	void DoOrder(void);

	void OnRefresh(void);

	void OnCancelAll(void);

	void OnCancelBuy(void);

	void OnCancelSell(void);

    DUI_DECLARE_MESSAGE_MAP()

public:
		virtual void OnClick(TNotifyUI& msg);

		virtual void OnSelectChanged( TNotifyUI &msg );

		virtual void OnItemClick( TNotifyUI &msg );

		virtual void OnItemActive( TNotifyUI &msg );

private:
	CEditUI* m_pStockIDEdt;

	CLabelUI* m_pStockNameLab;

	CEditUI* m_pSellPriceEdt;

	CButtonUI* m_pPriceAddBtn;

	CButtonUI* m_pPriceSubBtn;

	CLabelUI* m_pCanUseCapitalLab;

	CLabelUI* m_pCanSellNumLab;

	CEditUI* m_pSellNumEdt;

	CButtonUI* m_pRefillBtn;

	CButtonUI* m_pSellBtn;
	
	//COptionUI* m_pOrderOpt;
	//COptionUI* m_pDealOpt;
	//COptionUI* m_pPositionOpt;

	CButtonUI* m_pRefreshBtn;

	CButtonUI* m_pCancelAllBtn;

	CButtonUI* m_pCancelBuyBtn;

	CButtonUI* m_pCancelSellBtn;

	CTabLayoutUI* m_pSwitchTab;
};

#endif

