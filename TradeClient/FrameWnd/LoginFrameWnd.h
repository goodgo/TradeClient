#pragma once

#include "../stdafx.h"
#include <exdisp.h>
#include <comdef.h>
//#include "../Base/LoginController.h"

class CLoginFrameWnd : public WindowImplBase
{
public:
	CLoginFrameWnd();

	~CLoginFrameWnd();

	LPCTSTR GetWindowClassName() const;

	UINT GetClassStyle();

	//void OnFinalMessage(HWND hWnd);

	virtual CDuiString GetSkinFolder();

	virtual CDuiString GetSkinFile();

	virtual UILIB_RESOURCETYPE GetResourceType() const;
	
	virtual LPCTSTR GetResourceID() const;

    void InitWindow();

    void Notify(TNotifyUI& msg);

    virtual LRESULT HandleCustomMessage(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);

	///自定义消息回调
	LRESULT OnRespond(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);

	void OnLogin( TNotifyUI& msg );

    DUI_DECLARE_MESSAGE_MAP()

		void OnClick( TNotifyUI& msg );

		virtual void OnItemSelect( TNotifyUI& msg );

private:

	CButtonUI* m_pCloseBtn;

	CEditUI* m_pNameEdt;

	CComboBoxUI* m_pNameComb;

	CButtonUI* m_pRegisterBtn;

	CEditUI* m_pPasswdEdt;

	CButtonUI* m_pFindPasswdBtn;

    CButtonUI* m_pLoginBtn;
};