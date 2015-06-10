#include "FuturesCapitalPositionUI.h"

DUI_BEGIN_MESSAGE_MAP(CFuturesCapitalPositionUI, CNotifyPump)
DUI_ON_MSGTYPE(DUI_MSGTYPE_CLICK, OnClick)
DUI_ON_MSGTYPE(DUI_MSGTYPE_SELECTCHANGED, OnSelectChanged)
DUI_ON_MSGTYPE(DUI_MSGTYPE_ITEMCLICK, OnItemClick)
DUI_END_MESSAGE_MAP()

CFuturesCapitalPositionUI::CFuturesCapitalPositionUI(const CDuiString& strXML,CPaintManagerUI* pm):CAbstractUI(pm)
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

CFuturesCapitalPositionUI::~CFuturesCapitalPositionUI()
{

}

void CFuturesCapitalPositionUI::Initialize()
{
	CVerticalLayoutUI* FundCapitalPositionUI = static_cast<CVerticalLayoutUI*>(GetPaintMgr()->FindControl(_T("FundCapitalPositionUI")));	

	m_pRemainCapitalLab = static_cast<CLabelUI*>(GetPaintMgr()->FindSubControlByName(FundCapitalPositionUI,_T("RemainCapitalLab")));
    m_pFreezeCapitalLab = static_cast<CLabelUI*>(GetPaintMgr()->FindSubControlByName(FundCapitalPositionUI,_T("FreezeCapitalLab")));
    m_pTotalCapitalLab = static_cast<CLabelUI*>(GetPaintMgr()->FindSubControlByName(FundCapitalPositionUI,_T("TotalCapitalLab")));
    m_pCanUseCapitalLab = static_cast<CLabelUI*>(GetPaintMgr()->FindSubControlByName(FundCapitalPositionUI,_T("CanUseCapitalLab")));
    m_pMarketValueLab = static_cast<CLabelUI*>(GetPaintMgr()->FindSubControlByName(FundCapitalPositionUI,_T("MarketValueLab")));
}

CDuiString CFuturesCapitalPositionUI::GetVirtualwndName()
{
	return _T("FuturesCapitalPositionNode");
}

void CFuturesCapitalPositionUI::RefreshWnd()
{
	
}

void CFuturesCapitalPositionUI::OnClick(TNotifyUI& msg)
{

}

void CFuturesCapitalPositionUI::OnSelectChanged(TNotifyUI& msg)
{
	
}
void CFuturesCapitalPositionUI::OnItemClick(TNotifyUI& msg)
{
	
}
void CFuturesCapitalPositionUI::OnItemActive(TNotifyUI& msg)
{
	
}