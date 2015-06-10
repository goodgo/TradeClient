#include "FuturesOrderUI.h"

DUI_BEGIN_MESSAGE_MAP(CFuturesOrderUI, CNotifyPump)
DUI_ON_MSGTYPE(DUI_MSGTYPE_CLICK, OnClick)
DUI_ON_MSGTYPE(DUI_MSGTYPE_SELECTCHANGED, OnSelectChanged)
DUI_ON_MSGTYPE(DUI_MSGTYPE_ITEMCLICK, OnItemClick)
DUI_END_MESSAGE_MAP()

CFuturesOrderUI::CFuturesOrderUI(const CDuiString& strXML,CPaintManagerUI* pm):CAbstractUI(pm)
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

CFuturesOrderUI::~CFuturesOrderUI()
{

}

void CFuturesOrderUI::Initialize()
{
	CVerticalLayoutUI* FuturesOrderUI = static_cast<CVerticalLayoutUI*>(GetPaintMgr()->FindControl(_T("FuturesOrderUI")));	

}

CDuiString CFuturesOrderUI::GetVirtualwndName()
{
	return _T("FuturesOrderNode");
}

void CFuturesOrderUI::RefreshWnd()
{

}

void CFuturesOrderUI::OnClick(TNotifyUI& msg)
{
	
}
void CFuturesOrderUI::OnSelectChanged(TNotifyUI& msg)
{
	
}
void CFuturesOrderUI::OnItemClick(TNotifyUI& msg)
{
	
}
void CFuturesOrderUI::OnItemActive(TNotifyUI& msg)
{
	
}