#include "FundMergeUI.h"

DUI_BEGIN_MESSAGE_MAP(CFundMergeUI, CNotifyPump)
DUI_ON_MSGTYPE(DUI_MSGTYPE_CLICK, OnClick)
DUI_ON_MSGTYPE(DUI_MSGTYPE_SELECTCHANGED, OnSelectChanged)
DUI_ON_MSGTYPE(DUI_MSGTYPE_ITEMCLICK, OnItemClick)
DUI_END_MESSAGE_MAP()

CFundMergeUI::CFundMergeUI(const CDuiString& strXML,CPaintManagerUI* pm):CAbstractUI(pm)
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

CFundMergeUI::~CFundMergeUI()
{

}

void CFundMergeUI::Initialize()
{
	CVerticalLayoutUI* FundMergeUI = static_cast<CVerticalLayoutUI*>(GetPaintMgr()->FindControl(_T("FundMergeUI")));	
	
	m_pMomFundLab = static_cast<CLabelUI*>(GetPaintMgr()->FindSubControlByName(FundMergeUI,_T("MomFundLab")));
    m_pAFundLab = static_cast<CLabelUI*>(GetPaintMgr()->FindSubControlByName(FundMergeUI,_T("AFundLab")));
    m_pBFundLab = static_cast<CLabelUI*>(GetPaintMgr()->FindSubControlByName(FundMergeUI,_T("BFundLab")));
    m_pMergeStatusLab = static_cast<CLabelUI*>(GetPaintMgr()->FindSubControlByName(FundMergeUI,_T("MergeStatusLab")));
    m_pCanMergeNumLab = static_cast<CLabelUI*>(GetPaintMgr()->FindSubControlByName(FundMergeUI,_T("CanMergeNumLab")));
    m_pMergeEdt = static_cast<CEditUI*>(GetPaintMgr()->FindSubControlByName(FundMergeUI,_T("MergeEdt")));
	m_pShareAddBtn = static_cast<CButtonUI*>(GetPaintMgr()->FindSubControlByName(FundMergeUI,_T("ShareAddBtn")));
    m_pShareSubBtn = static_cast<CButtonUI*>(GetPaintMgr()->FindSubControlByName(FundMergeUI,_T("ShareSubBtn")));
    m_pRefillBtn = static_cast<CButtonUI*>(GetPaintMgr()->FindSubControlByName(FundMergeUI,_T("RefillBtn")));
    m_pMergeBtn = static_cast<CButtonUI*>(GetPaintMgr()->FindSubControlByName(FundMergeUI,_T("MergeBtn")));

    m_pSwitchTab = static_cast<CTabLayoutUI*>(GetPaintMgr()->FindSubControlByName(FundMergeUI,_T("FundSplitTab")));
}

CDuiString CFundMergeUI::GetVirtualwndName()
{
	return _T("FundMergeNode");
}

void CFundMergeUI::RefreshWnd()
{
	
}

void CFundMergeUI::OnClick(TNotifyUI& msg)
{

}

void CFundMergeUI::OnSelectChanged(TNotifyUI& msg)
{
	if (msg.pSender->GetName() == _T("OrderOpt"))
		m_pSwitchTab->SelectItem(0);
	else if (msg.pSender->GetName() == _T("DealOpt"))
		m_pSwitchTab->SelectItem(1);
	else if (msg.pSender->GetName() == _T("PositionOpt"))
		m_pSwitchTab->SelectItem(2);
}

void CFundMergeUI::OnItemClick(TNotifyUI& msg)
{
	
}
void CFundMergeUI::OnItemActive(TNotifyUI& msg)
{
	
}