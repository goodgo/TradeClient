#include "../StdAfx.h"
#include "../FrameWnd/MessageBoxWnd.h"
#include "UserMessage.h"

void MessageBoxDialog(HWND hWnd, UINT ErrorCode, LPCTSTR lpExMsg, UINT uType)
{
	CMessageBoxWnd::MsgType type = CMessageBoxWnd::Info;
	if (uType == MB_ICONWARNING) type = CMessageBoxWnd::Warn;
	else if (uType == MB_ICONERROR) type = CMessageBoxWnd::Error;
	else if (uType == MB_ICONINFORMATION) type = CMessageBoxWnd::Info;

	CMessageBoxWnd* pWhd = new CMessageBoxWnd(type, ErrorCode, lpExMsg);
	if (pWhd == NULL) { return; }
	pWhd->Create(hWnd, NULL, UI_CLASSSTYLE_DIALOG, 0, 0, 0, 0, 0, NULL);
	pWhd->CenterWindow();
	pWhd->ShowModal();
}