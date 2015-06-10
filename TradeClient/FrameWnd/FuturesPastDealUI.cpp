#include "FuturesPastDealUI.h"

DUI_BEGIN_MESSAGE_MAP(CFuturesPastDealUI, CNotifyPump)
DUI_ON_MSGTYPE(DUI_MSGTYPE_CLICK, OnClick)
DUI_ON_MSGTYPE(DUI_MSGTYPE_SELECTCHANGED, OnSelectChanged)
DUI_ON_MSGTYPE(DUI_MSGTYPE_ITEMCLICK, OnItemClick)
DUI_END_MESSAGE_MAP()

CFuturesPastDealUI::CFuturesPastDealUI(const CDuiString& strXML,CPaintManagerUI* pm):CAbstractUI(pm)
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

CFuturesPastDealUI::~CFuturesPastDealUI()
{

}

void CFuturesPastDealUI::Initialize()
{
	CVerticalLayoutUI* FuturesPastDealUI = static_cast<CVerticalLayoutUI*>(GetPaintMgr()->FindControl(_T("FuturesPastDealUI")));	

}

CDuiString CFuturesPastDealUI::GetVirtualwndName()
{
	return _T("FuturesPastDealNode");
}

void CFuturesPastDealUI::RefreshWnd()
{
	
}

void CFuturesPastDealUI::OnClick(TNotifyUI& msg)
{

}

void CFuturesPastDealUI::OnSelectChanged(TNotifyUI& msg)
{
	
}
void CFuturesPastDealUI::OnItemClick(TNotifyUI& msg)
{
	
}
void CFuturesPastDealUI::OnItemActive(TNotifyUI& msg)
{
	
}