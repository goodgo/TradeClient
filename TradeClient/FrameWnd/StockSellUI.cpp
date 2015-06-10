#include "StockSellUI.h"

DUI_BEGIN_MESSAGE_MAP(CStockSellUI, CNotifyPump)
DUI_ON_MSGTYPE(DUI_MSGTYPE_CLICK, OnClick)
DUI_ON_MSGTYPE(DUI_MSGTYPE_SELECTCHANGED, OnSelectChanged)
DUI_ON_MSGTYPE(DUI_MSGTYPE_ITEMCLICK, OnItemClick)
DUI_END_MESSAGE_MAP()

CStockSellUI::CStockSellUI(const CDuiString& strXML,CPaintManagerUI* pm):CAbstractUI(pm)
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
}

CStockSellUI::~CStockSellUI()
{

}

void CStockSellUI::Initialize()
{
	CVerticalLayoutUI* StockSellUI = static_cast<CVerticalLayoutUI*>(GetPaintMgr()->FindControl(_T("StockSellUI")));
	
	m_pStockIDEdt = static_cast<CEditUI*>(GetPaintMgr()->FindSubControlByName(StockSellUI,_T("StockIDEdt")));
    m_pStockIDEdt->SetNumberOnly(true);
	
	m_pStockNameLab = static_cast<CLabelUI*>(GetPaintMgr()->FindSubControlByName(StockSellUI,_T("StockNameLab")));
    m_pSellPriceEdt = static_cast<CEditUI*>(GetPaintMgr()->FindSubControlByName(StockSellUI,_T("SellPriceEdt")));
	m_pPriceAddBtn = static_cast<CButtonUI*>(GetPaintMgr()->FindSubControlByName(StockSellUI,_T("PriceAddBtn")));
    m_pPriceSubBtn = static_cast<CButtonUI*>(GetPaintMgr()->FindSubControlByName(StockSellUI,_T("PriceSubBtn")));
    
	m_pCanUseCapitalLab = static_cast<CLabelUI*>(GetPaintMgr()->FindSubControlByName(StockSellUI,_T("CanUseCapitalLab")));
	m_pCanSellNumLab = static_cast<CLabelUI*>(GetPaintMgr()->FindSubControlByName(StockSellUI,_T("CanSellNumLab")));
    m_pSellNumEdt = static_cast<CEditUI*>(GetPaintMgr()->FindSubControlByName(StockSellUI,_T("SellNumEdt")));
	m_pSellNumEdt->SetNumberOnly(true);

    m_pRefillBtn = static_cast<CButtonUI*>(GetPaintMgr()->FindSubControlByName(StockSellUI,_T("RefillBtn")));
	m_pSellBtn = static_cast<CButtonUI*>(GetPaintMgr()->FindSubControlByName(StockSellUI,_T("SellBtn")));
    
	//m_pOrderOpt = static_cast<COptionUI*>(GetPaintMgr()->FindSubControlByName(StockSellUI,_T("OrderOpt")));
    //m_pDealOpt = static_cast<COptionUI*>(GetPaintMgr()->FindSubControlByName(StockSellUI,_T("DealOpt")));
	//m_pPositionOpt = static_cast<COptionUI*>(GetPaintMgr()->FindSubControlByName(StockSellUI,_T("PositionOpt")));
    
	m_pRefreshBtn = static_cast<CButtonUI*>(GetPaintMgr()->FindSubControlByName(StockSellUI,_T("RefreshBtn")));   
	m_pCancelAllBtn = static_cast<CButtonUI*>(GetPaintMgr()->FindSubControlByName(StockSellUI,_T("CancelAllBtn")));	
	m_pCancelSellBtn = static_cast<CButtonUI*>(GetPaintMgr()->FindSubControlByName(StockSellUI,_T("CancelSellBtn")));
    m_pCancelSellBtn = static_cast<CButtonUI*>(GetPaintMgr()->FindSubControlByName(StockSellUI,_T("CancelSellBtn")));

    m_pSwitchTab = static_cast<CTabLayoutUI*>(GetPaintMgr()->FindSubControlByName(StockSellUI,_T("SwitchTab")));
}

CDuiString CStockSellUI::GetVirtualwndName()
{
	return _T("StockSellNode");
}

void CStockSellUI::RefreshWnd()
{
	
}

void CStockSellUI::OnPriceAdd(void)
{
	CDuiString str = m_pSellPriceEdt->GetText().GetData();
	if (!str.IsEmpty() )
	{
		if (str[0] == _T('.') && str[1] >= 48 && str[1] <= 97)
		{	
			CDuiString zero = _T("0");
			m_pSellPriceEdt->SetText(zero+str);
		}
		else
		{
			double f = _tstof(str.GetData()) + 0.01f;
			str.Format(_T("%.3f"), f);
			m_pSellPriceEdt->SetText(str);
		}
	}
}

void CStockSellUI::OnPriceSub(void)
{
	CDuiString str = m_pSellPriceEdt->GetText().GetData();
	if (!str.IsEmpty())
	{
		if (str[0] == _T('.') && str[1] >= 48 && str[1] <= 97)
		{	
			CDuiString zero = _T("0");
			m_pSellPriceEdt->SetText(zero+str);
		}
		else
		{
			double f = _tstof(str.GetData()) - 0.01f;
			if (f < 0.000f) { f = 0.000f; }
			str.Format(_T("%.3f"), f);
			m_pSellPriceEdt->SetText(str);
		}
	}
}

void CStockSellUI::OnRefill(void)
{
	m_pStockIDEdt->SetText(_T(""));
	m_pStockNameLab->SetText(_T(""));
	m_pSellPriceEdt->SetText(_T(""));
}

void CStockSellUI::DoOrder(void)
{
	
}

void CStockSellUI::OnRefresh(void)
{
	
}

void CStockSellUI::OnCancelAll(void)
{
	
}

void CStockSellUI::OnCancelBuy(void)
{
	
}

void CStockSellUI::OnCancelSell(void)
{
	
}

void CStockSellUI::OnClick(TNotifyUI& msg)
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
		DoOrder();
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

void CStockSellUI::OnSelectChanged(TNotifyUI& msg)
{
	if (msg.pSender->GetName() == _T("OrderOpt"))
		m_pSwitchTab->SelectItem(0);
	else if (msg.pSender->GetName() == _T("DealOpt"))
		m_pSwitchTab->SelectItem(1);
	else if (msg.pSender->GetName() == _T("PositionOpt"))
		m_pSwitchTab->SelectItem(2);
}

void CStockSellUI::OnItemClick(TNotifyUI& msg)
{
	
}
void CStockSellUI::OnItemActive(TNotifyUI& msg)
{
	
}