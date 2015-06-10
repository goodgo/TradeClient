#include "FuturesDailyOrderUI.h"

DUI_BEGIN_MESSAGE_MAP(CFuturesDailyOrderUI, CNotifyPump)
DUI_ON_MSGTYPE(DUI_MSGTYPE_CLICK, OnClick)
DUI_ON_MSGTYPE(DUI_MSGTYPE_SELECTCHANGED, OnSelectChanged)
DUI_ON_MSGTYPE(DUI_MSGTYPE_ITEMCLICK, OnItemClick)
DUI_END_MESSAGE_MAP()

CFuturesDailyOrderUI::CFuturesDailyOrderUI(const CDuiString& strXML,CPaintManagerUI* pm):CAbstractUI(pm)
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

CFuturesDailyOrderUI::~CFuturesDailyOrderUI()
{

}

void CFuturesDailyOrderUI::Initialize()
{
	CVerticalLayoutUI* FuturesDailyOrderUI = static_cast<CVerticalLayoutUI*>(GetPaintMgr()->FindControl(_T("FuturesDailyOrderUI")));	

}

CDuiString CFuturesDailyOrderUI::GetVirtualwndName()
{
	return _T("FuturesDailyOrderNode");
}

void CFuturesDailyOrderUI::RefreshWnd()
{
	
}

void CFuturesDailyOrderUI::OnClick(TNotifyUI& msg)
{

}

void CFuturesDailyOrderUI::OnSelectChanged(TNotifyUI& msg)
{
	
}
void CFuturesDailyOrderUI::OnItemClick(TNotifyUI& msg)
{
	
}
void CFuturesDailyOrderUI::OnItemActive(TNotifyUI& msg)
{
	
}