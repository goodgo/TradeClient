#include "LoginFrameWnd.h"
#include "../Base/Context.h"
#include "../Base/UserMessage.h"
#include "../Base/CharacterSet.h"
//#include "../Business/LoginBusiness.h"
#include <ShellAPI.h>

DUI_BEGIN_MESSAGE_MAP(CLoginFrameWnd, WindowImplBase)
DUI_ON_MSGTYPE(DUI_MSGTYPE_CLICK, OnClick)
DUI_ON_MSGTYPE(DUI_MSGTYPE_ITEMSELECT, OnItemSelect)
DUI_END_MESSAGE_MAP()

CLoginFrameWnd::CLoginFrameWnd()
{
	
}

CLoginFrameWnd::~CLoginFrameWnd()
{
	//delete this;
}

LPCTSTR CLoginFrameWnd::GetWindowClassName() const
{
	return _T("LoginFrameWnd");
}

UINT CLoginFrameWnd::GetClassStyle()
{
	return CS_DBLCLKS;
}

//void CLoginFrameWnd::OnFinalMessage(HWND hWnd);
//{
//	delete this;
//}

CDuiString CLoginFrameWnd::GetSkinFolder()
{
	return _T("skin");
}

CDuiString CLoginFrameWnd::GetSkinFile()
{
	return _T("xml\\login.xml");
}

UILIB_RESOURCETYPE CLoginFrameWnd::GetResourceType() const
{
	return UILIB_FILE;
}
	
LPCTSTR CLoginFrameWnd::GetResourceID() const
{
	return 0;
}

void CLoginFrameWnd::InitWindow()
{
	m_pCloseBtn = static_cast<CButtonUI*>(m_PaintManager.FindControl(_T("CloseBtn")));
    m_pNameEdt = static_cast<CEditUI*>(m_PaintManager.FindControl(_T("NameEdt")));
    m_pNameComb = static_cast<CComboBoxUI*>(m_PaintManager.FindControl(_T("NameComb")));
	m_pRegisterBtn = static_cast<CButtonUI*>(m_PaintManager.FindControl(_T("RegisterBtn")));
	m_pPasswdEdt = static_cast<CEditUI*>(m_PaintManager.FindControl(_T("PasswdEdt")));
	m_pFindPasswdBtn = static_cast<CButtonUI*>(m_PaintManager.FindControl(_T("FindPasswdBtn")));
	m_pLoginBtn = static_cast<CButtonUI*>(m_PaintManager.FindControl(_T("LoginBtn")));
}

void CLoginFrameWnd::Notify(TNotifyUI& msg)
{
	return WindowImplBase::Notify(msg);
}

void CLoginFrameWnd::OnClick( TNotifyUI& msg )
{
	if (msg.pSender->GetName() == _T("CloseBtn"))
	{
		Close();
		return;
	}
	else if (msg.pSender->GetName() == _T("LoginBtn"))
	{
		OnLogin(msg);
	}
	else if (msg.pSender->GetName() == _T("RegisterBtn"))
	{
		//::ShellExecute(NULL, NULL, _T("http://www.chinaetf.com.cn/"), NULL, NULL, NULL); 
	}
	else if (msg.pSender->GetName() == _T("FindPasswdBtn"))
	{
		//::ShellExecute(NULL, NULL, _T("http://www.chinaetf.com.cn/about.php"), NULL, NULL, NULL); 
	}
}

void CLoginFrameWnd::OnItemSelect( TNotifyUI& msg )
{
	if (msg.pSender->GetName() == _T("NameComb"))
	{
		m_pNameEdt->SetText(msg.pSender->GetText());
	}
}

void CLoginFrameWnd::OnLogin( TNotifyUI& msg )
{
	if (!m_pNameEdt->GetText().IsEmpty()
		&& !m_pPasswdEdt->GetText().IsEmpty())
	{
		//new a Business, send to sdk
		/*
		CLoginBusiness* LoginBusiness = new CLoginBusiness(GetHWND(), this->GetWindowClassName());
		std::string sValue;
		sValue = Base::CharacterSet::UnicodeToANSI(m_pNameEdt->GetText().GetData());
		LoginBusiness->SetKeyValue("LoginName", sValue);
		sValue = Base::CharacterSet::UnicodeToANSI(m_pPasswdEdt->GetText().GetData()); 	
		LoginBusiness->SetKeyValue("LoginPasswd", sValue);
		LoginBusiness->SendRequest();
		*/
	/*	
		loginres *res = new loginres();
		if (m_pNameEdt->GetText() == _T("lytz002") && m_pPasswdEdt->GetText() == _T("123"))
		{						
			res->status = true;
		}
		else
		{
			res->status = false;
		}
		::PostMessage(GetHWND(),WM_USER_LOGIN_RES,(WPARAM)res, NULL);
*/
	}
}

LRESULT CLoginFrameWnd::OnRespond(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
{
	LRESULT lRes = TRUE;
	//消息类型转换,解析消息
	/*
	CLoginBusiness* LoginBusiness = static_cast<CLoginBusiness*>(wParam);
	LoginBusiness->GetResDataSet();

	bool bStatus = LoginBusiness->GetValueByKey("LoginStatus");
	if (true == bStatus)
	{
		::MessageBox(GetHWND(), _T("登陆成功!"), NULL, NULL);
		CContext::GetInstance().m_sUsrName = m_pNameEdt->GetText();
		CContext::GetInstance().m_sUsrPasswd = m_pPasswdEdt->GetText();
		Close();
	}
	else if(false == bStatus)
	{
		::MessageBox(GetHWND(), _T("登陆名或密码错误!"), NULL, NULL);
		lRes = FALSE;
	}
	delete LoginBusiness;
	return lRes;
	*/

	loginres *res = (loginres *)wParam;
	if (res->status == true)
	{		
		::MessageBox(GetHWND(), _T("登陆成功!"), NULL, NULL);
		CContext::GetInstance().m_sUsrName = m_pNameEdt->GetText();
		CContext::GetInstance().m_sUsrPasswd = m_pPasswdEdt->GetText();
		Close();
	}
	else if(res->status == false)
	{
		::MessageBox(GetHWND(), _T("登陆名或密码错误!"), NULL, NULL);
		lRes = FALSE;
	}
	return lRes;

}

LRESULT CLoginFrameWnd::HandleCustomMessage(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
{
	bHandled = TRUE;
	LRESULT lRes = TRUE; 

	switch(uMsg)
	{
		case WM_USER_RETURN_RESPOND:
			lRes = OnRespond(uMsg, wParam,lParam, bHandled);
			break;
		default:
			lRes = FALSE;
			bHandled= FALSE;
			break;
	}
	return lRes;
}