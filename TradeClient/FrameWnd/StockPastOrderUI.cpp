#include "StockPastOrderUI.h"

DUI_BEGIN_MESSAGE_MAP(CStockPastOrderUI, CNotifyPump)
DUI_ON_MSGTYPE(DUI_MSGTYPE_CLICK, OnClick)
DUI_ON_MSGTYPE(DUI_MSGTYPE_SELECTCHANGED, OnSelectChanged)
DUI_ON_MSGTYPE(DUI_MSGTYPE_ITEMCLICK, OnItemClick)
DUI_END_MESSAGE_MAP()

CStockPastOrderUI::CStockPastOrderUI(const CDuiString& strXML,CPaintManagerUI* pm):CAbstractUI(pm)
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

CStockPastOrderUI::~CStockPastOrderUI()
{

}

void CStockPastOrderUI::Initialize()
{
	CVerticalLayoutUI* StockPastOrderUI = static_cast<CVerticalLayoutUI*>(GetPaintMgr()->FindControl(_T("StockPastOrderUI")));
}

CDuiString CStockPastOrderUI::GetVirtualwndName()
{
	return _T("StockPastOrderNode");
}

void CStockPastOrderUI::RefreshWnd()
{
	
}

void CStockPastOrderUI::OnClick(TNotifyUI& msg)
{

}

void CStockPastOrderUI::OnSelectChanged(TNotifyUI& msg)
{
	
}
void CStockPastOrderUI::OnItemClick(TNotifyUI& msg)
{
	
}
void CStockPastOrderUI::OnItemActive(TNotifyUI& msg)
{
	
}