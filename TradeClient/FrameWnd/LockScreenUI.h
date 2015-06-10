#pragma once

#include "../stdafx.h"
#include <exdisp.h>
#include <comdef.h>

class CLockScreenUI : public WindowImplBase
{
public:
	CLockScreenUI();

	~CLockScreenUI();

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

	void OnUnLock( TNotifyUI& msg );

    DUI_DECLARE_MESSAGE_MAP()

		virtual void OnClick( TNotifyUI& msg );

private:

	CVerticalLayoutUI* m_pLayoutUI;

	CEditUI* m_pPasswdEdt;

    CButtonUI* m_pUnLockBtn;

};