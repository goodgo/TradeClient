#pragma once

#include <exdisp.h>
#include <comdef.h>
#include <time.h>
#include "LoginFrameWnd.h"
#include "../Base/UserMessage.h"
#include "../Base/version.h"
#include "../Base/Context.h"
#include "../Base/AbstractUI.h"
#include "LockScreenUI.h"
#include "StockBuyUI.h"
#include "StockSellUI.h"
#include "StockCancelUI.h"
#include "FundSplitUI.h"
#include "FundMergeUI.h"
#include "StockCapitalPositionUI.h"
#include "StockDailyOrderUI.h"
#include "StockPastOrderUI.h"
#include "StockDailyDealUI.h"
#include "StockPastDealUI.h"
#include "StockCapitalFlowUI.h"
#include "FuturesOrderUI.h"
#include "FuturesCapitalPositionUI.h"
#include "FuturesDailyOrderUI.h"
#include "FuturesPastOrderUI.h"
#include "FuturesDailyDealUI.h"
#include "FuturesPastDealUI.h"
#include "FuturesCapitalFlowUI.h"
//#include "../Controller/TradeController.h"
//#include "../SDK/ModuleServer.h"

class CMainFrameWnd : public WindowImplBase
{
public:
	CMainFrameWnd();

	~CMainFrameWnd();

	LPCTSTR GetWindowClassName() const;

	UINT GetClassStyle();

	void OnFinalMessage(HWND hWnd);

	CDuiString GetSkinFolder();

	CDuiString GetSkinFile();

	UILIB_RESOURCETYPE GetResourceType() const;
	
	LPCTSTR GetResourceID() const;

	void AdaptWindowSize( UINT cxScreen );

    void InitWindow();

	DWORD WINAPI RunModuleServerThr(LPVOID pM);

    CControlUI* CreateControl(LPCTSTR pstrClassName);

    void Notify(TNotifyUI& msg);

    LRESULT HandleCustomMessage(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
	
	LRESULT OnRespond(WPARAM wParam, LPARAM lParam, BOOL& bHandled);
	
	LRESULT OnProductListReq(WPARAM wParam, LPARAM lParam, BOOL& bHandled);

	void OnLogin( TNotifyUI& msg );

	void OnLogout( TNotifyUI& msg );

	void OnLock( TNotifyUI& msg );

    DUI_DECLARE_MESSAGE_MAP()

		void OnClick( TNotifyUI& msg);

		void OnSelectChanged( TNotifyUI &msg );

		void OnItemClick( TNotifyUI &msg );

	LRESULT OnUpdataTimeClock(void);

public:
	//CTradeCtrl* m_pTradeCtrl;
	static HWND m_hwnd;


private: 

	WINDOWPLACEMENT m_OldWndPlacement;  // 保存窗口原来的位置

	SYSTEMTIME m_sysTime;

	CButtonUI* m_pLogoutBtn;

    CButtonUI* m_pLoginBtn;

	CButtonUI* m_pLockBtn;

	CButtonUI* m_pRefreshAllBtn;

	CComboBoxUI* m_pProductComb;

	CTreeViewUI* m_pMenuTree;

	CButtonUI* m_pMinBtn;

	CButtonUI* m_pMaxBtn;

	CButtonUI* m_pRestoreBtn;

	CButtonUI* m_pCloseBtn;

	CLabelUI* m_pVersionLab;

	CLabelUI* m_pStatusLab;

	CLabelUI* m_pTimeLab;

	//保存tab容器
	CStdStringPtrMap m_TabContainer;
};