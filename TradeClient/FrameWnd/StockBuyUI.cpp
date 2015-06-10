#include <map>
#include <vector>
#include "StockBuyUI.h"
#include "../Base/CharacterSet.h"
#include "../Base/UserMessage.h"
#include "../Base/TimeKit.h"

//#include "../Business/QuotaBusiness.h"
//#include "../Business/CancelBusiness.h"
//#include "../Business/OrderBusiness.h"

DUI_BEGIN_MESSAGE_MAP(CStockBuyUI, CNotifyPump)
DUI_ON_MSGTYPE(DUI_MSGTYPE_CLICK, OnClick)
DUI_ON_MSGTYPE(DUI_MSGTYPE_SELECTCHANGED, OnSelectChanged)
DUI_ON_MSGTYPE(DUI_MSGTYPE_ITEMACTIVATE, OnItemActive)
DUI_ON_MSGTYPE(DUI_MSGTYPE_ITEMCLICK, OnItemClick)
DUI_ON_MSGTYPE(DUI_MSGTYPE_ITEMSELECT, OnItemSelect)
DUI_ON_MSGTYPE(DUI_MSGTYPE_RETURN, OnReturn)
DUI_END_MESSAGE_MAP()

std::vector<std::string> vecOrderBuyList;
typedef std::vector<std::string>::iterator iterOrderBuyList;

std::vector<std::string> vecOrderSellList;
typedef std::vector<std::string>::iterator iterOrderSellList;

CStockBuyUI::CStockBuyUI(const CDuiString& strXML,CPaintManagerUI* pm):CAbstractUI(pm)
{
	CDialogBuilder builder;
    CControlUI* pContainer = builder.Create(strXML.GetData(), NULL, NULL, GetPaintMgr(), NULL); 
    if( pContainer ) 
	{
        this->Add(pContainer);
    }
    else 
	{
        this->RemoveAll();
        return;
    }
	m_iCurList = OrderList;
}

CStockBuyUI::~CStockBuyUI()
{

}

void CStockBuyUI::Initialize()
{
	CVerticalLayoutUI* StockBuyUI = static_cast<CVerticalLayoutUI*>(GetPaintMgr()->FindControl(_T("StockBuyUI")));

	m_pStockIDEdt = static_cast<CEditUI*>(GetPaintMgr()->FindSubControlByName(StockBuyUI,_T("StockIDEdt")));
	m_pStockIDEdt->SetNumberOnly(true);
	
	m_pStockNameLab = static_cast<CLabelUI*>(GetPaintMgr()->FindSubControlByName(StockBuyUI,_T("StockNameLab")));
    m_pBuyPriceEdt = static_cast<CEditUI*>(GetPaintMgr()->FindSubControlByName(StockBuyUI,_T("BuyPriceEdt")));
	
	m_pPriceAddBtn = static_cast<CButtonUI*>(GetPaintMgr()->FindSubControlByName(StockBuyUI,_T("PriceAddBtn")));
    m_pPriceSubBtn = static_cast<CButtonUI*>(GetPaintMgr()->FindSubControlByName(StockBuyUI,_T("PriceSubBtn")));
    
	m_pCanUseCapitalLab = static_cast<CLabelUI*>(GetPaintMgr()->FindSubControlByName(StockBuyUI,_T("CanUseCapitalLab")));
	m_pCanBuyNumLab = static_cast<CLabelUI*>(GetPaintMgr()->FindSubControlByName(StockBuyUI,_T("CanBuyNumLab")));
    m_pBuyNumEdt = static_cast<CEditUI*>(GetPaintMgr()->FindSubControlByName(StockBuyUI,_T("BuyNumEdt")));
    m_pBuyNumEdt->SetNumberOnly(true);
	
	m_pRefillBtn = static_cast<CButtonUI*>(GetPaintMgr()->FindSubControlByName(StockBuyUI,_T("RefillBtn")));
	m_pBuyBtn = static_cast<CButtonUI*>(GetPaintMgr()->FindSubControlByName(StockBuyUI,_T("BuyBtn")));
    
	m_pRefreshBtn = static_cast<CButtonUI*>(GetPaintMgr()->FindSubControlByName(StockBuyUI,_T("RefreshBtn")));   
	m_pCancelAllBtn = static_cast<CButtonUI*>(GetPaintMgr()->FindSubControlByName(StockBuyUI,_T("CancelAllBtn")));	
	m_pCancelBuyBtn = static_cast<CButtonUI*>(GetPaintMgr()->FindSubControlByName(StockBuyUI,_T("CancelBuyBtn")));
    m_pCancelSellBtn = static_cast<CButtonUI*>(GetPaintMgr()->FindSubControlByName(StockBuyUI,_T("CancelSellBtn")));

    m_pSwitchTab = static_cast<CTabLayoutUI*>(GetPaintMgr()->FindSubControlByName(StockBuyUI,_T("SwitchTab")));

	m_pStockOrderList = static_cast<CListUI*>(GetPaintMgr()->FindSubControlByName(StockBuyUI,_T("StockOrderList")));
	m_pStockDealList = static_cast<CListUI*>(GetPaintMgr()->FindSubControlByName(StockBuyUI,_T("StockDealList")));
	m_pStockPositionList = static_cast<CListUI*>(GetPaintMgr()->FindSubControlByName(StockBuyUI,_T("StockPositionList")));
}

CDuiString CStockBuyUI::GetVirtualwndName()
{
	return _T("StockBuyNode");
}

void CStockBuyUI::RefreshWnd()
{
	
}

void CStockBuyUI::OnPriceAdd(void)
{
	CDuiString str = m_pBuyPriceEdt->GetText().GetData();
	if (!str.IsEmpty())
	{
		if (str[0] == _T('.') && str[1] >= 48 && str[1] <= 97)
		{	
			CDuiString zero = _T("0");
			m_pBuyPriceEdt->SetText(zero+str);
		}
		else
		{
			double f = _tstof(str.GetData()) + 0.01f;
			str.Format(_T("%.3f"), f);
			m_pBuyPriceEdt->SetText(str);
		}
	}
}

void CStockBuyUI::OnPriceSub(void)
{
	CDuiString str = m_pBuyPriceEdt->GetText().GetData();
	if (!str.IsEmpty())
	{
		if (str[0] == _T('.') && str[1] >= 48 && str[1] <= 97)
		{	
			CDuiString zero = _T("0");
			m_pBuyPriceEdt->SetText(zero+str);
		}
		else
		{
			double f = _tstof(str.GetData()) - 0.01f;
			if (f < 0.000f) { f = 0.000f; }
			str.Format(_T("%.3f"), f);
			m_pBuyPriceEdt->SetText(str);
		}
	}
}

void CStockBuyUI::OnRefill(void)
{
	m_pStockIDEdt->SetText(_T(""));
	m_pStockNameLab->SetText(_T(""));
	m_pBuyPriceEdt->SetText(_T(""));
}

void CStockBuyUI::OnBuy(void)
{
	if (6 != m_pStockIDEdt->GetText().GetLength() 
		  || m_pBuyPriceEdt->GetText().IsEmpty()
		  || m_pBuyNumEdt->GetText().IsEmpty())
	{
		return;
	}
	/*
	DataSetRow* pDataSetRow = new DataSetRow;	
	COrderBusiness* OrderBusiness = new COrderBusiness(GetHWND(), this->GetSenderWndName()); 
	
	pDataSetRow->Set("股票代码", Base::CharacterSet::UnicodeToANSI(m_pStockIDEdt->GetText().GetData());
	pDataSetRow->Set("股票名称", Base::CharacterSet::UnicodeToANSI(m_pStockNameLab->GetText().GetData());
	pDataSetRow->Set("买入价格", Base::CharacterSet::UnicodeToANSI(m_pBuyPriceEdt->GetText().GetData());
	pDataSetRow->Set("买入量",   Base::CharacterSet::UnicodeToANSI(m_pBuyNumEdt->GetText().GetData());
	
	CDuiString strTime = Base::CTimeKit::GetCurDateTime(TIME_FORMAT);
	pDataSetRow->Set("委托时间", Base::CharacterSet::UnicodeToANSI(strTime.Mid(0, 6));
	pDataSetRow->Set("委托日期", Base::CharacterSet::UnicodeToANSI(strTime.Mid(6,-1));
	
	OrderBusiness->AddRow(pDataSetRow);
	OrderBusiness->SendeRequest();
	delete pDataSetRow;
	*/
}

void CStockBuyUI::OnRefresh(void)
{
	
}

void CStockBuyUI::OnCancelAll(void)
{
	/*
	DataSetRow* pDataSetRow = new DataSetRow;		
	CCancelBusiness* CancelBusiness = new CCancelBusiness(GetHWND(), this->GetSenderWndName());
	for (int iNum = 0; iNum < vecOrderBuyList.size(); iNum++)
	{
		pDataSetRow->Set("订单号", vecOrderBuyList.at(iNum));
		CancelBusiness->AddRow(pDataSetRow);
	}
	for (int iNum = 0; iNum < vecOrderSellList.size(); iNum++)
	{		
		pDataSetRow->Set("订单号", vecOrderSellList.at(iNum));
		CancelBusiness->AddRow(pDataSetRow);
	}
	CancelBusiness->SendeRequest();
	delete pDataSetRow;
	*/
}

void CStockBuyUI::OnCancelBuy(void)
{
	/*
	CCancelBusiness* CancelBusiness = new CCancelBusiness(GetHWND(), this->GetSenderWndName());
	DataSetRow* pDataSetRow = new DataSetRow;
	for (int iNum = 0; iNum < setOrderBuyList.count(); iNum++)
	{
		pDataSetRow->Set("订单号", vecOrderBuyList.at(iNum));
		CancelBusiness->AddRow(pDataSetRow);
	}
	delete pDataSetRow;
	CancelBusiness->SendRequest();
	*/
}

void CStockBuyUI::OnCancelSell(void)
{
	/*
	CCancelBusiness* CancelBusiness = new CCancelBusiness(GetHWND(), this->GetSenderWndName());
	DataSetRow* pDataSetRow = new DataSetRow;
	for (int iNum = 0; iNum < vecOrderBuyList.count(); iNum++)
	{
		pDataSetRow->Set("订单号", vecOrderSellList.at(iNum));
		CancelBusiness->AddRow(pDataSetRow);
	}
	delete pDataSetRow;
	CancelBusiness->SendRequest();
	*/
}

void CStockBuyUI::OnClick(TNotifyUI& msg)
{
	if (msg.pSender->GetName() == _T("PriceAddBtn"))
	{
		OnPriceAdd();
	}
	else if (msg.pSender->GetName() == _T("PriceSubBtn"))
	{
		OnPriceSub();
	}
	else if (msg.pSender->GetName() == _T("RefillBtn"))
	{
		OnRefill();
	}
	else if (msg.pSender->GetName() == _T("BuyBtn"))
	{
		OnBuy();
	}
	else if (msg.pSender->GetName() == _T("RefreshBtn"))
	{
		OnRefresh();
	}
	else if (msg.pSender->GetName() == _T("CancelAllBtn"))
	{
		OnCancelAll();
	}
	else if (msg.pSender->GetName() == _T("CancelBuyBtn"))
	{	
		OnCancelBuy();
	}
	else if (msg.pSender->GetName() == _T("CancelSellBtn"))
	{
		OnCancelSell();
	}
}

void CStockBuyUI::OnSelectChanged(TNotifyUI& msg)
{
	if (msg.pSender->GetName() == _T("OrderOpt"))
	{
		m_pSwitchTab->SelectItem(OrderList);
		m_iCurList = OrderList;
	}
	else if (msg.pSender->GetName() == _T("DealOpt"))
	{
		m_pSwitchTab->SelectItem(DealList);
		m_iCurList = DealList;
	}		
	else if (msg.pSender->GetName() == _T("PositionOpt"))
	{
		m_pSwitchTab->SelectItem(PositionList);
		m_iCurList = PositionList;	
	}
}

void CStockBuyUI::OnItemClick(TNotifyUI& msg)
{
	
}

void CStockBuyUI::OnReturn( TNotifyUI &msg)
{
	if (msg.pSender->GetName() == _T("StockIDEdt"))
	{
		if (6 == m_pStockIDEdt->GetText().GetLength())
		{
			OnQuotaReq(GetHWND(), (WPARAM)&m_pStockIDEdt->GetText(), NULL);
		}		
	}
}

void CStockBuyUI::OnItemActive(TNotifyUI& msg)
{
	if (OrderList != m_iCurList)
	{
		return;
	}

	int iSelect = m_pStockOrderList->GetCurSel();
	CListTextElementUI *pNewElem = new CListTextElementUI;
	CListTextElementUI *pOldElem = static_cast<CListTextElementUI* >(m_pStockOrderList->GetItemAt(iSelect));

	m_pStockOrderList->RemoveAt(iSelect);
	
	pNewElem->SetTag(m_pStockOrderList->GetCount());
	m_pStockOrderList->AddAt(pNewElem, 0);	
	CDuiString strTime = Base::CTimeKit::GetCurDateTime(TIME_FORMAT);
	
	pNewElem->SetText(0, pOldElem->GetText(0));
	pNewElem->SetText(1, pOldElem->GetText(1));	
	pNewElem->SetText(2, pOldElem->GetText(2));
	pNewElem->SetText(3, pOldElem->GetText(3));
	pNewElem->SetText(4, pOldElem->GetText(4));
	pNewElem->SetText(5, _T(""));	
	pNewElem->SetText(6, _T("撤单"));
	pNewElem->SetText(7, strTime.Mid(0, 6));
	pNewElem->SetText(8, strTime.Mid(6,-1));
	pNewElem->SetText(9, _T("123456789"));
	pNewElem->SetText(10, pOldElem->GetText(10));
	
	//send to sdk
	//::PostMessage(GetHWND(), WM_USER_STOCK_ORDER_REQ, (WPARAM)pNewElem, 0L);
	
	OnOrderReq(GetHWND(), (WPARAM)(pNewElem), (LPARAM)(OrderBuy));
}

void CStockBuyUI::OnItemSelect(TNotifyUI& msg)
{
	if (msg.pSender->GetName() == _T("StockIDComb"))
	{
		m_pStockIDEdt->SetText(msg.pSender->GetText());
		
		OnQuotaReq(GetHWND(), (WPARAM)(&m_pStockIDEdt->GetText()), (LPARAM)(0L));
	}
}

LRESULT CStockBuyUI::OnQuotaReq(HWND hWnd, WPARAM wParam, LPARAM lParam)
{	
	ASSERT(wParam);
/*
	DataSetRow* pDataSetRow = new DataSetRow;	
	CQuotaBusiness* QuotaBusiness = new CQuotaBusiness(GetHWND(),this->GetVirtualwndName());
	pDataSetRow->Set("证券代码", Base::CharacterSet::UnicodeToANSI(s->GetData()));
	QuotaBusiness->AddRow(pDataSetRow);
	QuotaBusiness->SendRequest();
	delete pDataSetRow;
*/	
	return 0;
}

LRESULT CStockBuyUI::OnOrderReq(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
	ASSERT(wParam);
	int i = static_cast<int>(lParam);

	CListTextElementUI* pElem = reinterpret_cast<CListTextElementUI*>(wParam);
	std::string sContractNumber = Base::CharacterSet::UnicodeToANSI(pElem->GetText(9));		
	//iterOrderNumber iter = std::find(vecOrderNumber.begin(), vecOrderNumber.end(), sContractNumber);
	//ASSERT(iter);
	//vecOrderNumber.erase(iter);

	DUITRACE(_T("new a order bussiness request, send to sdk."));
	return 0;
}

LRESULT CStockBuyUI::OnDealReq(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
	DUITRACE(_T("new a deal bussiness request, send to sdk."));

	return 0;	
}

LRESULT CStockBuyUI::OnPositionReq(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
	DUITRACE(_T("new a position bussiness request, send to sdk."));
	return 0;	
}


LRESULT CStockBuyUI::OnQuotaRes(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
	LRESULT lRes = TRUE;
	/*
	CBusinessBase* QuotaBusiness = static_cast<CQuotaBusiness*>(wParam);
	QuotaBusiness->GetResData();
	
	m_pStockIDEdt->SetText(Base::CharacterSet::ANSIToUnicode(QuotaBusiness->GetString("证券代码"));
	m_pStockNameLab->SetText(Base::CharacterSet::ANSIToUnicode(QuotaBusiness->GetString("证券名称"));

	*/
	return lRes;
}

LRESULT CStockBuyUI::OnOrderRes(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
	/*
	CBusinessBase* OrderBusiness = static_cast<COrderBusiness*>(wParam);
	OrderBusiness->GetResData();

	CListTextElementUI *pElem = new CListTextElementUI;	
	pElem->SetOwner(m_pStockOrderList);
	pElem->SetTag(m_pStockOrderList->GetCount());
	m_pStockOrderList->AddAt(pElem, 0);
	
	pElem->SetText(0, Base::CharacterSet::ANSIToUnicode(OrderBusiness->GetString("证券代码"));
	pElem->SetText(1, Base::CharacterSet::ANSIToUnicode(OrderBusiness->GetString("证券名称"));
	pElem->SetText(2, Base::CharacterSet::ANSIToUnicode(OrderBusiness->GetString("委托数量"));
	pElem->SetText(3, Base::CharacterSet::ANSIToUnicode(OrderBusiness->GetString("成交数量"));
	pElem->SetText(4, Base::CharacterSet::ANSIToUnicode(OrderBusiness->GetString("委托价格"));
	pElem->SetText(5, Base::CharacterSet::ANSIToUnicode(OrderBusiness->GetString("成交均价"));
	if ("B" == ::CharUpper((TCHAR *)OrderBusiness->GetString("操作").c_str()))
		pElem->SetText(6, _T("买"));
	else if ("S" == ::CharUpper((TCHAR *)OrderBusiness->GetString("操作").c_str()))
		pElem->SetText(6, _T("卖"));
	pElem->SetText(7, Base::CharacterSet::ANSIToUnicode(OrderBusiness->GetString("委托时间"));
	pElem->SetText(8, Base::CharacterSet::ANSIToUnicode(OrderBusiness->GetString("委托日期"));
	pElem->SetText(9, Base::CharacterSet::ANSIToUnicode(OrderBusiness->GetString("合同编号"));
	pElem->SetText(10, Base::CharacterSet::ANSIToUnicode(OrderBusiness->GetString("交易市场"));
	
	delete OrderBusiness;
	*/
	return 0;
}

LRESULT CStockBuyUI::OnDealRes(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
	DUITRACE(_T("receive a request add to deal list."));
	return 0;
}

LRESULT CStockBuyUI::OnPositionRes(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
	DUITRACE(_T("receive a request add to position list."));
	return 0;
}

LRESULT CStockBuyUI::HandleCustomMessage( UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled )
{
	LRESULT lRes = TRUE;
	switch(uMsg)
	{
	case 1:
		break;
/*
		case WM_USER_STOCK_Quota_REQ:
			lRes = OnQuotaReq(GetHWND(), wParam, lParam);
			break;
		case WM_USER_STOCK_ORDER_REQ:
			lRes = OnOrderReq( GetHWND(), wParam, lParam);
			break;		
		case WM_USER_STOCK_DEAL_REQ:
			lRes = OnDealReq( GetHWND(), wParam, lParam);
			break;
		case WM_USER_STOCK_POSITION_REQ:
			lRes = OnPositionReq( GetHWND(), wParam, lParam);
			break;

		case WM_USER_STOCK_QUOTA_RES:
			lRes = OnQuotaRes( GetHWND(), wParam, lParam );
			break;	
		case WM_USER_STOCK_ORDER_RES:
			lRes = OnOrderRes( GetHWND(), wParam, lParam);
			break;		
		case WM_USER_STOCK_DEAL_RES:
			lRes = OnDealRes( GetHWND(), wParam, lParam);
			break;	
		case WM_USER_STOCK_POSITION_RES:
			lRes = OnPositionRes( GetHWND(), wParam, lParam);
			break;	
*/
		default:
			break;
	}
	return lRes;
}