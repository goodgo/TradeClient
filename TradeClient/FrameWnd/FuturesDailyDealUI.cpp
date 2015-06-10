#include "FuturesDailyDealUI.h"

DUI_BEGIN_MESSAGE_MAP(CFuturesDailyDealUI, CNotifyPump)
DUI_ON_MSGTYPE(DUI_MSGTYPE_CLICK, OnClick)
DUI_ON_MSGTYPE(DUI_MSGTYPE_SELECTCHANGED, OnSelectChanged)
DUI_ON_MSGTYPE(DUI_MSGTYPE_ITEMCLICK, OnItemClick)
DUI_END_MESSAGE_MAP()

CFuturesDailyDealUI::CFuturesDailyDealUI(const CDuiString& strXML,CPaintManagerUI* pm):CAbstractUI(pm)
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

CFuturesDailyDealUI::~CFuturesDailyDealUI()
{

}

void CFuturesDailyDealUI::Initialize()
{
	CVerticalLayoutUI* FuturesCapitalFlowUI = static_cast<CVerticalLayoutUI*>(GetPaintMgr()->FindControl(_T("FuturesCapitalFlowUI")));	

}

CDuiString CFuturesDailyDealUI::GetVirtualwndName()
{
	return _T("FuturesDailyDealNode");
}

void CFuturesDailyDealUI::RefreshWnd()
{
	
}

void CFuturesDailyDealUI::OnClick(TNotifyUI& msg)
{

}

void CFuturesDailyDealUI::OnSelectChanged(TNotifyUI& msg)
{
	
}
void CFuturesDailyDealUI::OnItemClick(TNotifyUI& msg)
{
	
}
void CFuturesDailyDealUI::OnItemActive(TNotifyUI& msg)
{
	
}