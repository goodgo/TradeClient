#include "MessageBoxWnd.h"

DUI_BEGIN_MESSAGE_MAP(CMessageBoxWnd, WindowImplBase)
DUI_ON_MSGTYPE(DUI_MSGTYPE_CLICK, OnClick)
DUI_END_MESSAGE_MAP()

CMessageBoxWnd::CMessageBoxWnd(MsgType type, UINT code, CDuiString msg)
{
	m_uType = type;
	m_dstrExMsg = msg;
	m_uMsgCode = code;
}

CMessageBoxWnd::~CMessageBoxWnd()
{
	//delete this;
}

LPCTSTR CMessageBoxWnd::GetWindowClassName() const
{
	return _T("MessageBoxWnd");
}

UINT CMessageBoxWnd::GetClassStyle()
{
	return CS_DBLCLKS;
}

//void CMessageBoxWnd::OnFinalMessage(HWND hWnd);
//{
//	delete this;
//}

CDuiString CMessageBoxWnd::GetSkinFolder()
{
	return _T("skin");
}

CDuiString CMessageBoxWnd::GetSkinFile()
{
	return _T("xml\\MessageBoxDialog.xml");
}

UILIB_RESOURCETYPE CMessageBoxWnd::GetResourceType() const
{
	return UILIB_FILE;
}

LPCTSTR CMessageBoxWnd::GetResourceID() const
{
	return 0;
}

void CMessageBoxWnd::InitWindow()
{
	m_pCloseBtn = static_cast<CButtonUI*>(m_PaintManager.FindControl(_T("CloseBtn")));
	m_pSureBtn = static_cast<CButtonUI*>(m_PaintManager.FindControl(_T("SureBtn")));
	m_pCancelBtn = static_cast<CButtonUI*>(m_PaintManager.FindControl(_T("CancelBtn")));

	CTextUI* pContentText = static_cast<CTextUI*>(m_PaintManager.FindControl(_T("Content")));
	if (pContentText && !m_dstrExMsg.IsEmpty())
	{
		pContentText->SetText(m_dstrExMsg);
	}
		
}

void CMessageBoxWnd::Notify(TNotifyUI& msg)
{
	return WindowImplBase::Notify(msg);
}

void CMessageBoxWnd::OnClick(TNotifyUI& msg)
{
	if (msg.pSender->GetName() == _T("CloseBtn"))
	{
		Close();
		return;
	}
	else if (msg.pSender->GetName() == _T("m_pSureBtn"))
	{
		Close();
		return;
	}
	else if (msg.pSender->GetName() == _T("CancelBtn"))
	{
		Close();
		return;
	}
}