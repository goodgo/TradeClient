#include "StockCapitalPositionUI.h"

DUI_BEGIN_MESSAGE_MAP(CStockCapitalPositionUI, CNotifyPump)
DUI_ON_MSGTYPE(DUI_MSGTYPE_CLICK, OnClick)
DUI_ON_MSGTYPE(DUI_MSGTYPE_SELECTCHANGED, OnSelectChanged)
DUI_ON_MSGTYPE(DUI_MSGTYPE_ITEMCLICK, OnItemClick)
DUI_END_MESSAGE_MAP()

CStockCapitalPositionUI::CStockCapitalPositionUI(const CDuiString& strXML,CPaintManagerUI* pm):CAbstractUI(pm)
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

CStockCapitalPositionUI::~CStockCapitalPositionUI()
{

}

void CStockCapitalPositionUI::Initialize()
{
	CVerticalLayoutUI* StockCapitalPositionUI = static_cast<CVerticalLayoutUI*>(GetPaintMgr()->FindControl(_T("StockCapitalPositionUI")));

	m_pRemainCapitalLab = static_cast<CLabelUI*>(GetPaintMgr()->FindSubControlByName(StockCapitalPositionUI,_T("RemainCapitalLab")));
    m_pFreezeCapitalLab = static_cast<CLabelUI*>(GetPaintMgr()->FindSubControlByName(StockCapitalPositionUI,_T("FreezeCapitalLab")));
    m_pTotalCapitalLab = static_cast<CLabelUI*>(GetPaintMgr()->FindSubControlByName(StockCapitalPositionUI,_T("TotalCapitalLab")));
    m_pCanUseCapitalLab = static_cast<CLabelUI*>(GetPaintMgr()->FindSubControlByName(StockCapitalPositionUI,_T("CanUseCapitalLab")));
    m_pMarketValueLab = static_cast<CLabelUI*>(GetPaintMgr()->FindSubControlByName(StockCapitalPositionUI,_T("MarketValueLab")));
}

CDuiString CStockCapitalPositionUI::GetVirtualwndName()
{
	return _T("StockCapitalPositionNode");
}

void CStockCapitalPositionUI::RefreshWnd()
{
	
}

void CStockCapitalPositionUI::OnClick(TNotifyUI& msg)
{

}

void CStockCapitalPositionUI::OnSelectChanged(TNotifyUI& msg)
{
	
}
void CStockCapitalPositionUI::OnItemClick(TNotifyUI& msg)
{
	
}
void CStockCapitalPositionUI::OnItemActive(TNotifyUI& msg)
{
	
}