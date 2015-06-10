#include "TradeController.h"

CTradeCtrl::CTradeCtrl(WindowImplBase* Wnd):m_pThisWnd(Wnd)
{
}

CTradeCtrl::~CTradeCtrl()
{

}

void CTradeCtrl::OnClick(TNotifyUI& msg)
{
    if( msg.pSender == m_pThisWnd->m_pLogoutBtn )  
    {
        PostQuitMessage(0);  
        return; 
    }
    else if( msg.pSender == m_pThisWnd->m_pLockBtn ) 
    { 
        SendMessage(WM_SYSCOMMAND, SC_MINIMIZE, 0); 
        return; 
    }
    else if( msg.pSender == m_pThisWnd->m_pExitBtn ) 
    { 
        SendMessage(WM_SYSCOMMAND, SC_MAXIMIZE, 0); 
        return; 
    }
    else if( msg.pSender == m_pThisWnd->m_pRestoreBtn )
    { 
        SendMessage(WM_SYSCOMMAND, SC_RESTORE, 0); 
        return; 
    }
    else if (msg.pSender->GetName() == _T(""))
    {
         
    }
    else if (msg.pSender->GetName() == _T(""))
    {
       
    }
	return 0;
}

void CTradeCtrl::OnSelectChanged( TNotifyUI &msg )
{
    CDuiString name = msg.pSender->GetName();
    CTabLayoutUI* pControl = static_cast<CTabLayoutUI*>(m_pThisWnd->m_PaintManager.FindControl(_T("MarketSwitch")));
    
    static COptionUI* pLastButton = NULL;
    static CAbstractUI* pLastTab = NULL;
    CAbstractUI* pUI = NULL;

    for (int idx=0; idx<m_pThisWnd->m_TabContainer.GetSize(); ++idx)
    {
        if (name == m_pThisWnd->m_TabContainer[idx])
        {
            pUI = (CAbstractUI*)m_pThisWnd->m_TabContainer.Find(name);
        }
    }
    if (pUI == NULL) return;

    if (pLastTab != NULL && pUI != pLastTab && !pLastTab->CanChange()) 
	{
        if (pLastButton) pLastButton->Selected(true);
		//::MessageBox(NULL, _T(""), _T(""), MB_OK);
		return;
    }
    
    if (pUI && pUI!=pLastTab) 
	{
        pUI->RefreshWnd();
        pControl->SelectItem(pUI->GetIndex());
        pLastTab = pUI;
        pLastButton = static_cast<COptionUI*>(m_pThisWnd->m_PaintManager.FindControl(msg.pSender->GetName()));
    }
}