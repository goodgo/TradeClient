#include <winsock2.h>
#include <exdisp.h>
#include <comdef.h>

#include "FrameWnd/MainFrameWnd.h"

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE /*hPrevInstance*/, LPSTR /*lpCmdLine*/, int nCmdShow)
{
    CPaintManagerUI::SetInstance(hInstance);
    CPaintManagerUI::SetResourcePath(CPaintManagerUI::GetInstancePath());

    HRESULT Hr = ::CoInitialize(NULL);
    if( FAILED(Hr) ) return 0;

    CMainFrameWnd* pFrame = new CMainFrameWnd();
    if( pFrame == NULL ) return 0;
    pFrame->Create(NULL, _T("TradeClient"), UI_WNDSTYLE_FRAME, WS_EX_WINDOWEDGE | WS_EX_APPWINDOW);
	pFrame->CenterWindow();
    ::ShowWindow(*pFrame, SW_SHOW);
    CPaintManagerUI::MessageLoop();
	
	delete pFrame;
    ::CoUninitialize();
    return 0;
}