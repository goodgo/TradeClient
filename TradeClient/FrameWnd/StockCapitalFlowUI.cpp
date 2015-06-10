#include "StockCapitalFlowUI.h"

DUI_BEGIN_MESSAGE_MAP(CStockCapitalFlowUI, CNotifyPump)
DUI_ON_MSGTYPE(DUI_MSGTYPE_CLICK, OnClick)
DUI_ON_MSGTYPE(DUI_MSGTYPE_SELECTCHANGED, OnSelectChanged)
DUI_ON_MSGTYPE(DUI_MSGTYPE_ITEMCLICK, OnItemClick)
DUI_END_MESSAGE_MAP()

CStockCapitalFlowUI::CStockCapitalFlowUI(const CDuiString& strXML,CPaintManagerUI* pm):CAbstractUI(pm)
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

CStockCapitalFlowUI::~CStockCapitalFlowUI()
{

}

void CStockCapitalFlowUI::Initialize()
{
	CVerticalLayoutUI* StockCapitalFlowUI = static_cast<CVerticalLayoutUI*>(GetPaintMgr()->FindControl(_T("StockCapitalFlowUI")));

}

CDuiString CStockCapitalFlowUI::GetVirtualwndName()
{
	return _T("StockCapitalFlowNode");
}

void CStockCapitalFlowUI::RefreshWnd()
{
	
}

void CStockCapitalFlowUI::OnClick(TNotifyUI& msg)
{

}

void CStockCapitalFlowUI::OnSelectChanged(TNotifyUI& msg)
{
	
}
void CStockCapitalFlowUI::OnItemClick(TNotifyUI& msg)
{
	
}
void CStockCapitalFlowUI::OnItemActive(TNotifyUI& msg)
{
	
}