#include "StockCancelUI.h"


DUI_BEGIN_MESSAGE_MAP(CStockCancelUI, CNotifyPump)
DUI_ON_MSGTYPE(DUI_MSGTYPE_CLICK, OnClick)
DUI_ON_MSGTYPE(DUI_MSGTYPE_SELECTCHANGED, OnSelectChanged)
DUI_ON_MSGTYPE(DUI_MSGTYPE_ITEMCLICK, OnItemClick)
DUI_END_MESSAGE_MAP()

CStockCancelUI::CStockCancelUI(const CDuiString& strXML,CPaintManagerUI* pm):CAbstractUI(pm)
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

CStockCancelUI::~CStockCancelUI()
{

}

void CStockCancelUI::Initialize()
{
	CVerticalLayoutUI* StockCancelUI = static_cast<CVerticalLayoutUI*>(GetPaintMgr()->FindControl(_T("StockCancelUI")));	

	m_pSelectAllBtn = static_cast<CButtonUI*>(GetPaintMgr()->FindSubControlByName(StockCancelUI,_T("SelectAllBtn")));
	m_pCancelBtn = static_cast<CButtonUI*>(GetPaintMgr()->FindSubControlByName(StockCancelUI,_T("CancelBtn")));
	m_pCancelAllBtn = static_cast<CButtonUI*>(GetPaintMgr()->FindSubControlByName(StockCancelUI,_T("CancelAllBtn")));
	m_pCancelBuyBtn = static_cast<CButtonUI*>(GetPaintMgr()->FindSubControlByName(StockCancelUI,_T("CancelBuyBtn")));
    m_pCancelSellBtn = static_cast<CButtonUI*>(GetPaintMgr()->FindSubControlByName(StockCancelUI,_T("CancelSellBtn")));
	m_pStockIDEdt= static_cast<CEditUI*>(GetPaintMgr()->FindSubControlByName(StockCancelUI,_T("StockIDEdt")));
    m_pSelectIDBtn = static_cast<CButtonUI*>(GetPaintMgr()->FindSubControlByName(StockCancelUI,_T("SelectIDBtn")));
}

CDuiString CStockCancelUI::GetVirtualwndName()
{
	return _T("StockCancelNode");
}

void CStockCancelUI::RefreshWnd()
{
	
}

void CStockCancelUI::OnClick(TNotifyUI& msg)
{

}

void CStockCancelUI::OnSelectChanged(TNotifyUI& msg)
{
	
}
void CStockCancelUI::OnItemClick(TNotifyUI& msg)
{
	
}
void CStockCancelUI::OnItemActive(TNotifyUI& msg)
{
	
}