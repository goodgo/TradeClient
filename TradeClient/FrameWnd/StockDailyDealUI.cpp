#include "StockDailyDealUI.h"

DUI_BEGIN_MESSAGE_MAP(CStockDailyDealUI, CNotifyPump)
DUI_ON_MSGTYPE(DUI_MSGTYPE_CLICK, OnClick)
DUI_ON_MSGTYPE(DUI_MSGTYPE_SELECTCHANGED, OnSelectChanged)
DUI_ON_MSGTYPE(DUI_MSGTYPE_ITEMCLICK, OnItemClick)
DUI_END_MESSAGE_MAP()

CStockDailyDealUI::CStockDailyDealUI(const CDuiString& strXML,CPaintManagerUI* pm):CAbstractUI(pm)
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

CStockDailyDealUI::~CStockDailyDealUI()
{

}

void CStockDailyDealUI::Initialize()
{
	CVerticalLayoutUI* StockDailyDealUI = static_cast<CVerticalLayoutUI*>(GetPaintMgr()->FindControl(_T("StockDailyDealUI")));

}

CDuiString CStockDailyDealUI::GetVirtualwndName()
{
	return _T("StockDailyDealNode");
}

void CStockDailyDealUI::RefreshWnd()
{
	
}

void CStockDailyDealUI::OnClick(TNotifyUI& msg)
{

}

void CStockDailyDealUI::OnSelectChanged(TNotifyUI& msg)
{
	
}
void CStockDailyDealUI::OnItemClick(TNotifyUI& msg)
{
	
}
void CStockDailyDealUI::OnItemActive(TNotifyUI& msg)
{
	
}