#ifndef __STOCK_BUY_UI_H__
#define __STOCK_BUY_UI_H__

#include <vector>
#include "../Base/AbstractUI.h"

#define TIME_FORMAT _T("%02d%02d%02d%04d%02d%02d")
class CStockBuyUI : public CAbstractUI
{
public:

	CStockBuyUI(const CDuiString& strXML,CPaintManagerUI* pm);	
	
	~CStockBuyUI();

    void Initialize();

    CDuiString GetVirtualwndName();

    void RefreshWnd();

    int GetIndex(){return STOCK_BUY_NODE_INDEX;};

	virtual LRESULT HandleCustomMessage( UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled );

private:

	void OnPriceAdd(void);

	void OnPriceSub(void);

	void OnRefill(void);

	void OnBuy(void);

	void OnRefresh(void);

	void OnCancelAll(void);

	void OnCancelBuy(void);

	void OnCancelSell(void);

	//void OnQuotaReq(void);

	LRESULT OnQuotaReq(HWND hWnd, WPARAM wParam, LPARAM lParam);
	
	LRESULT OnOrderReq(HWND hWnd, WPARAM wParam, LPARAM lParam);
	
	LRESULT OnDealReq(HWND hWnd, WPARAM wParam, LPARAM lParam);	

	LRESULT OnPositionReq(HWND hWnd, WPARAM wParam, LPARAM lParam);

	LRESULT OnQuotaRes(HWND hWnd, WPARAM wParam, LPARAM lParam);

	LRESULT OnOrderRes(HWND hWnd, WPARAM wParam, LPARAM lParam);

	LRESULT OnDealRes(HWND hWnd, WPARAM wParam, LPARAM lParam);

	LRESULT OnPositionRes(HWND hWnd, WPARAM wParam, LPARAM lParam);

public:

    DUI_DECLARE_MESSAGE_MAP()

		virtual void OnClick(TNotifyUI& msg);

		virtual void OnSelectChanged( TNotifyUI &msg );

		virtual void OnItemClick( TNotifyUI &msg );

		virtual void OnItemActive( TNotifyUI &msg );
	
		virtual void OnItemSelect( TNotifyUI &msg);

		virtual void OnReturn( TNotifyUI &msg);

private:
	int m_iCurList;
	enum {
		OrderList=0,
		DealList,
		PositionList
	};
	enum {
		OrderBuy=0,
		OrderCancel
	};
private:

	CEditUI* m_pStockIDEdt;

	CLabelUI* m_pStockNameLab;

	CEditUI* m_pBuyPriceEdt;

	CButtonUI* m_pPriceAddBtn;

	CButtonUI* m_pPriceSubBtn;

	CLabelUI* m_pCanUseCapitalLab;

	CLabelUI* m_pCanBuyNumLab;

	CEditUI* m_pBuyNumEdt;

	CButtonUI* m_pRefillBtn;

	CButtonUI* m_pBuyBtn;

	CButtonUI* m_pRefreshBtn;

	CButtonUI* m_pCancelAllBtn;

	CButtonUI* m_pCancelBuyBtn;

	CButtonUI* m_pCancelSellBtn;

	CTabLayoutUI* m_pSwitchTab;

	CListUI* m_pStockOrderList;
	
	CListUI* m_pStockDealList;

	CListUI* m_pStockPositionList;

	std::vector<string*> m_vecBuyOrders;

	std::vector<string*> m_vecSellOrders;

	int m_iOrderListFields;

	int m_iDealListFields;

	int m_iPositionFields;
};

#endif

