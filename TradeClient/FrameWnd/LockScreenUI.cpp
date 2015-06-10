#include "LockScreenUI.h"
#include "../Base/Context.h"
#include <ShellAPI.h>

DUI_BEGIN_MESSAGE_MAP(CLockScreenUI, WindowImplBase)
DUI_ON_MSGTYPE(DUI_MSGTYPE_CLICK, OnClick)
DUI_END_MESSAGE_MAP()

CLockScreenUI::CLockScreenUI()
{
	
}

CLockScreenUI::~CLockScreenUI()
{
	//delete this;
}

LPCTSTR CLockScreenUI::GetWindowClassName() const
{
	return _T("LockScreenUI");
}

UINT CLockScreenUI::GetClassStyle()
{
	return CS_DBLCLKS;
}

//void CLockScreenUI::OnFinalMessage(HWND hWnd);
//{
//	delete this;
//}

CDuiString CLockScreenUI::GetSkinFolder()
{
	return _T("skin");
}

CDuiString CLockScreenUI::GetSkinFile()
{
	return _T("xml\\LockScreenUI.xml");
}

UILIB_RESOURCETYPE CLockScreenUI::GetResourceType() const
{
	return UILIB_FILE;
}
	
LPCTSTR CLockScreenUI::GetResourceID() const
{
	return 0;
}

void CLockScreenUI::InitWindow()
{
	CVerticalLayoutUI* LockScreenUI = static_cast<CVerticalLayoutUI*>(m_PaintManager.FindControl(_T("LockScreenUI")));

	m_pLayoutUI  = static_cast<CVerticalLayoutUI*>(m_PaintManager.FindSubControlByName(LockScreenUI,_T("LayoutUI")));
	m_pPasswdEdt = static_cast<CEditUI*>(m_PaintManager.FindSubControlByName(LockScreenUI,_T("PasswdEdt")));
	m_pUnLockBtn = static_cast<CButtonUI*>(m_PaintManager.FindSubControlByName(LockScreenUI,_T("UnLockBtn")));

	CDuiRect rcWnd;
	::GetWindowRect(*this, &rcWnd);

	RECT rc;
	rc.left = rcWnd.left + (rcWnd.GetWidth()-m_pLayoutUI->GetWidth())/2;
	rc.top  = rcWnd.top + (rcWnd.GetHeight()-m_pLayoutUI->GetHeight())/2;
	rc.right = rc.left + m_pLayoutUI->GetWidth();
	rc.bottom = rc.top + m_pLayoutUI->GetHeight();

	m_pLayoutUI->SetFloat(_T("true"));
	m_pLayoutUI->SetPos(rc);
}

void CLockScreenUI::Notify(TNotifyUI& msg)
{
	return WindowImplBase::Notify(msg);
}

void CLockScreenUI::OnUnLock( TNotifyUI& msg )
{
	if (m_pPasswdEdt->GetText() == CContext::GetInstance().m_sUsrPasswd)
	{
		::MessageBox(GetHWND(), _T("解锁成功!"), NULL, NULL);
		Close();
	}
	else
	{
		::MessageBox(GetHWND(), _T("解锁失败!"), NULL, NULL);
	}
}

void CLockScreenUI::OnClick( TNotifyUI& msg )
{
	if (msg.pSender->GetName() == _T("UnLockBtn"))
	{
		OnUnLock(msg);
	}
}



LRESULT CLockScreenUI::HandleCustomMessage(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
{
	bHandled = TRUE;
	LRESULT lRes = TRUE; 

	switch(uMsg)
	{
		case 1:
			break;
		default:
			lRes = FALSE;
			bHandled= FALSE;
			break;
	}
	return lRes;	
}