#pragma once

#include "../stdafx.h"

class CMessageBoxWnd : public WindowImplBase
{
public:
	enum MsgType
	{
		Info,
		Warn,
		Error
	};

public:

	CMessageBoxWnd(MsgType type, UINT code, CDuiString msg);

	~CMessageBoxWnd();

	LPCTSTR GetWindowClassName() const;

	UINT GetClassStyle();

	//void OnFinalMessage(HWND hWnd);

	virtual CDuiString GetSkinFolder();

	virtual CDuiString GetSkinFile();

	virtual UILIB_RESOURCETYPE GetResourceType() const;

	virtual LPCTSTR GetResourceID() const;

	void InitWindow();

	void Notify(TNotifyUI& msg);

	DUI_DECLARE_MESSAGE_MAP()

		void OnClick(TNotifyUI& msg);

private:

	MsgType m_uType;

	CDuiString m_dstrExMsg;

	UINT m_uMsgCode;

	CButtonUI* m_pCloseBtn;

	CButtonUI* m_pSureBtn;

	CButtonUI* m_pCancelBtn;
};