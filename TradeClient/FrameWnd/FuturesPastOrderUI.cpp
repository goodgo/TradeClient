#include "FuturesPastOrderUI.h"

DUI_BEGIN_MESSAGE_MAP(CFuturesPastOrderUI, CNotifyPump)
DUI_ON_MSGTYPE(DUI_MSGTYPE_CLICK, OnClick)
DUI_ON_MSGTYPE(DUI_MSGTYPE_SELECTCHANGED, OnSelectChanged)
DUI_ON_MSGTYPE(DUI_MSGTYPE_ITEMCLICK, OnItemClick)
DUI_END_MESSAGE_MAP()

CFuturesPastOrderUI::CFuturesPastOrderUI(const CDuiString& strXML,CPaintManagerUI* pm):CAbstractUI(pm)
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

CFuturesPastOrderUI::~CFuturesPastOrderUI()
{

}

void CFuturesPastOrderUI::Initialize()
{
	CVerticalLayoutUI* FuturesPastOrderUI = static_cast<CVerticalLayoutUI*>(GetPaintMgr()->FindControl(_T("FuturesPastOrderUI")));
}

CDuiString CFuturesPastOrderUI::GetVirtualwndName()
{
	return _T("FuturesPastOrderNode");
}

void CFuturesPastOrderUI::RefreshWnd()
{
	
}

void CFuturesPastOrderUI::OnClick(TNotifyUI& msg)
{

}

void CFuturesPastOrderUI::OnSelectChanged(TNotifyUI& msg)
{
	
}
void CFuturesPastOrderUI::OnItemClick(TNotifyUI& msg)
{
	
}
void CFuturesPastOrderUI::OnItemActive(TNotifyUI& msg)
{
	
}