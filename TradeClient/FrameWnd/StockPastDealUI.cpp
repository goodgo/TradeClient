#include "StockPastDealUI.h"

DUI_BEGIN_MESSAGE_MAP(CStockPastDealUI, CNotifyPump)
DUI_ON_MSGTYPE(DUI_MSGTYPE_CLICK, OnClick)
DUI_ON_MSGTYPE(DUI_MSGTYPE_SELECTCHANGED, OnSelectChanged)
DUI_ON_MSGTYPE(DUI_MSGTYPE_ITEMCLICK, OnItemClick)
DUI_END_MESSAGE_MAP()

CStockPastDealUI::CStockPastDealUI(const CDuiString& strXML,CPaintManagerUI* pm):CAbstractUI(pm)
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

CStockPastDealUI::~CStockPastDealUI()
{

}

void CStockPastDealUI::Initialize()
{
	CVerticalLayoutUI* StockPastDealUI = static_cast<CVerticalLayoutUI*>(GetPaintMgr()->FindControl(_T("StockPastDealUI")));

}

CDuiString CStockPastDealUI::GetVirtualwndName()
{
	return _T("StockPastDealNode");
}

void CStockPastDealUI::RefreshWnd()
{
	
}

void CStockPastDealUI::OnClick(TNotifyUI& msg)
{

}

void CStockPastDealUI::OnSelectChanged(TNotifyUI& msg)
{
	
}
void CStockPastDealUI::OnItemClick(TNotifyUI& msg)
{
	
}
void CStockPastDealUI::OnItemActive(TNotifyUI& msg)
{
	
}