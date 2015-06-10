#include "StockDailyOrderUI.h"

DUI_BEGIN_MESSAGE_MAP(CStockDailyOrderUI, CNotifyPump)
DUI_ON_MSGTYPE(DUI_MSGTYPE_CLICK, OnClick)
DUI_ON_MSGTYPE(DUI_MSGTYPE_SELECTCHANGED, OnSelectChanged)
DUI_ON_MSGTYPE(DUI_MSGTYPE_ITEMCLICK, OnItemClick)
DUI_END_MESSAGE_MAP()

CStockDailyOrderUI::CStockDailyOrderUI(const CDuiString& strXML,CPaintManagerUI* pm):CAbstractUI(pm)
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

CStockDailyOrderUI::~CStockDailyOrderUI()
{

}

void CStockDailyOrderUI::Initialize()
{
	CVerticalLayoutUI* StockDailyOrderUI = static_cast<CVerticalLayoutUI*>(GetPaintMgr()->FindControl(_T("StockDailyOrderUI")));

}

CDuiString CStockDailyOrderUI::GetVirtualwndName()
{
	return _T("StockDailyOrderNode");
}

void CStockDailyOrderUI::RefreshWnd()
{
	
}

void CStockDailyOrderUI::OnClick(TNotifyUI& msg)
{

}

void CStockDailyOrderUI::OnSelectChanged(TNotifyUI& msg)
{
	
}
void CStockDailyOrderUI::OnItemClick(TNotifyUI& msg)
{
	
}
void CStockDailyOrderUI::OnItemActive(TNotifyUI& msg)
{
	
}