#include "FuturesCapitalFlowUI.h"

DUI_BEGIN_MESSAGE_MAP(CFuturesCapitalFlowUI, CNotifyPump)
DUI_ON_MSGTYPE(DUI_MSGTYPE_CLICK, OnClick)
DUI_ON_MSGTYPE(DUI_MSGTYPE_SELECTCHANGED, OnSelectChanged)
DUI_ON_MSGTYPE(DUI_MSGTYPE_ITEMCLICK, OnItemClick)
DUI_END_MESSAGE_MAP()

CFuturesCapitalFlowUI::CFuturesCapitalFlowUI(const CDuiString& strXML,CPaintManagerUI* pm):CAbstractUI(pm)
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

CFuturesCapitalFlowUI::~CFuturesCapitalFlowUI()
{

}

void CFuturesCapitalFlowUI::Initialize()
{
	CVerticalLayoutUI* FuturesCapitalFlowUI = static_cast<CVerticalLayoutUI*>(GetPaintMgr()->FindControl(_T("CFuturesCapitalFlowUI")));	

}

CDuiString CFuturesCapitalFlowUI::GetVirtualwndName()
{
	return _T("FuturesCapitalFlowNode");
}

void CFuturesCapitalFlowUI::RefreshWnd()
{
	
}

void CFuturesCapitalFlowUI::OnClick(TNotifyUI& msg)
{

}

void CFuturesCapitalFlowUI::OnSelectChanged(TNotifyUI& msg)
{
	
}
void CFuturesCapitalFlowUI::OnItemClick(TNotifyUI& msg)
{
	
}
void CFuturesCapitalFlowUI::OnItemActive(TNotifyUI& msg)
{
	
}