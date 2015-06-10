#ifndef __TRADECONTROLLER_H__
#define __TRADECONTROLLER_H__

//#include "../stdafx.h"
//#include "../FrameWnd/TradeFrameWnd.h"
//#include "../Base/ControllerBase.h"

//#define 

class CTradeCtrl : public CControllerBase
{
public:
	CTradeCtrl(WindowImplBase* Wnd);
	~CTradeCtrl();
	void OnClick(TNotifyUI& msg);
	void OnOnSelectChanged(TNotifyUI& msg);
	void OnSelectProduct(TNotifyUI& msg);
	void OnLockAccount(TNotifyUI& msg);
	void OnSelectBuySellOpt(TNotifyUI& msg);
	void OnSetStockID(TNotifyUI& msg);
	void OnSetDelegPrice(TNotifyUI& msg);
	void OnSetDelegPriceSAdd(TNotifyUI& msg);
	void OnSetDelegPriceSSub(TNotifyUI& msg);
	void OnSetDelegPriceLAdd(TNotifyUI& msg);
	void OnSetDelegPriceLSub(TNotifyUI& msg);
	void OnSetDelegNum(TNotifyUI& msg);
	void OnSetCommStock(TNotifyUI& msg);
	void OnRecvRespon(TNotifyUI& msg);
	void OnFreshInfo(TNotifyUI& msg);
	
	void DoOrder(TNotifyUI& msg);
	void DoWithdrawBuyOrder(TNotifyUI& msg);
	void DoWithdrawSellOrder(TNotifyUI& msg);
	void DoPurchase(TNotifyUI& msg);
	void DoRedeem(TNotifyUI& msg);
	void DoBuyBaskets(TNotifyUI& msg);
	void DoSellBaskets(TNotifyUI& msg);
	void DoBuyPurchase(TNotifyUI& msg);
	void DoSellRedeem(TNotifyUI& msg);
	void DoFastPurchase(TNotifyUI& msg);
	void DoFastRedeem(TNotifyUI& msg);
	
	void QueryOrders(TNotifyUI& msg);
	void QueryDeals(TNotifyUI& msg);
	void QueryPositions(TNotifyUI& msg);

private:
	//CTradeFrameWnd* m_pThisWnd;
};

#endif