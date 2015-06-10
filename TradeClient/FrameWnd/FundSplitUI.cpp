#include "FundSplitUI.h"

DUI_BEGIN_MESSAGE_MAP(CFundSplitUI, CNotifyPump)
DUI_ON_MSGTYPE(DUI_MSGTYPE_CLICK, OnClick)
DUI_ON_MSGTYPE(DUI_MSGTYPE_SELECTCHANGED, OnSelectChanged)
DUI_ON_MSGTYPE(DUI_MSGTYPE_ITEMCLICK, OnItemClick)
DUI_END_MESSAGE_MAP()

CFundSplitUI::CFundSplitUI(const CDuiString& strXML,CPaintManagerUI* pm):CAbstractUI(pm)
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

CFundSplitUI::~CFundSplitUI()
{

}

void CFundSplitUI::Initialize()
{
	CVerticalLayoutUI* FundSplitUI = static_cast<CVerticalLayoutUI*>(GetPaintMgr()->FindControl(_T("FundSplitUI")));	
	
	m_pMomFundLab = static_cast<CLabelUI*>(GetPaintMgr()->FindSubControlByName(FundSplitUI,_T("MomFundLab")));
    m_pAFundLab = static_cast<CLabelUI*>(GetPaintMgr()->FindSubControlByName(FundSplitUI,_T("AFundLab")));
    m_pBFundLab = static_cast<CLabelUI*>(GetPaintMgr()->FindSubControlByName(FundSplitUI,_T("BFundLab")));
    m_pSplitStatusLab = static_cast<CLabelUI*>(GetPaintMgr()->FindSubControlByName(FundSplitUI,_T("SplitStatusLab")));
    m_pCanSplitNumLab = static_cast<CLabelUI*>(GetPaintMgr()->FindSubControlByName(FundSplitUI,_T("CanSplitNumLab")));
    m_pSplitEdt = static_cast<CEditUI*>(GetPaintMgr()->FindSubControlByName(FundSplitUI,_T("SplitEdt")));
	m_pShareAddBtn = static_cast<CButtonUI*>(GetPaintMgr()->FindSubControlByName(FundSplitUI,_T("ShareAddBtn")));
    m_pShareSubBtn = static_cast<CButtonUI*>(GetPaintMgr()->FindSubControlByName(FundSplitUI,_T("ShareSubBtn")));
    m_pRefillBtn = static_cast<CButtonUI*>(GetPaintMgr()->FindSubControlByName(FundSplitUI,_T("RefillBtn")));
    m_pSplitBtn = static_cast<CButtonUI*>(GetPaintMgr()->FindSubControlByName(FundSplitUI,_T("SplitBtn")));

    m_pSwitchTab = static_cast<CTabLayoutUI*>(GetPaintMgr()->FindSubControlByName(FundSplitUI,_T("FundSplitTab")));
}

CDuiString CFundSplitUI::GetVirtualwndName()
{
	return _T("FundSplitNode");
}

void CFundSplitUI::RefreshWnd()
{
	
}

void CFundSplitUI::OnClick(TNotifyUI& msg)
{

}

void CFundSplitUI::OnSelectChanged(TNotifyUI& msg)
{
	if (msg.pSender->GetName() == _T("OrderOpt"))
		m_pSwitchTab->SelectItem(0);
	else if (msg.pSender->GetName() == _T("DealOpt"))
		m_pSwitchTab->SelectItem(1);
	else if (msg.pSender->GetName() == _T("PositionOpt"))
		m_pSwitchTab->SelectItem(2);
}

void CFundSplitUI::OnItemClick(TNotifyUI& msg)
{
	
}
void CFundSplitUI::OnItemActive(TNotifyUI& msg)
{
	
}