#include <Winsock2.h>
#include "MainFrameWnd.h"
//#include "../Base/BusinessBase.h"
//#include "../Business/ProductBusiness.h"

const TCHAR* const kLogoutBtnCtrlName = _T("ExitBtn");
const TCHAR* const kLoginBtnCtrlName = _T("LoginBtn");
const TCHAR* const kLockBtnCtrlName = _T("LockBtn");
const TCHAR* const kRefreshAllBtnCtrlName = _T("RefreshAllBtn");

const TCHAR* const kUsrNameLabCtrlName = _T("UsrNameLab");
const TCHAR* const kProcductCombCtrlName = _T("ProductComb");
const TCHAR* const kMarketTabCtrlName = _T("MarketTab");
const TCHAR* const kMenuTreeCtrlName = _T("MenuTree");

const TCHAR* const kMinBtnCtrlName = _T("MinBtn");
const TCHAR* const kMaxBtnCtrlName = _T("MaxBtn");
const TCHAR* const kRestoreBtnCtrlName = _T("RestoreBtn");
const TCHAR* const kCloseBtnCtrlName = _T("CloseBtn");

const TCHAR* const kVersionLabCtrlName = _T("VersionLab");
const TCHAR* const kStatusLabCtrlName = _T("StatusLab");
const TCHAR* const kTimeLabCtrlName = _T("TimeLab");

//const TCHAR* const kLockUIName = _T("LockUI");
//const TCHAR* const kLockUIXML = _T("LockUI.xml");
//现货界面
const TCHAR* const kStockBuyUIName = _T("StockBuyUI");
const TCHAR* const kStockSellUIName = _T("StockSellUI");
const TCHAR* const kStockCancelUIName = _T("StockCancelUI");
const TCHAR* const kFundSplitUIName = _T("FundSplitUI");
const TCHAR* const kFundMergeUIName = _T("FundMergeUI");

const TCHAR* const kStockCapitalPositionUIName = _T("StockCapitalPositionUI");
const TCHAR* const kStockDailyOrderUIName = _T("StockDailyOrderUI");
const TCHAR* const kStockPastOrderUIName = _T("StockPastOrderUI");
const TCHAR* const kStockDailyDealUIName = _T("StockDailyDealUI");
const TCHAR* const kStockPastDealUIName = _T("StockPastDealUI");
const TCHAR* const kStockCapitalFlowUIName = _T("StockCapitalFlowUI");
//期货界面
const TCHAR* const kFuturesOrderUIName = _T("FuturesOrderUI");
const TCHAR* const kFuturesCapitalPositionUIName = _T("FuturesCapitalPositionUI");
const TCHAR* const kFuturesDailyOrderUIName = _T("FuturesDailyOrderUI");
const TCHAR* const kFuturesPastOrderUIName = _T("FuturesPastOrderUI");
const TCHAR* const kFuturesDailyDealUIName = _T("FuturesDailyDealUI");
const TCHAR* const kFuturesPastDealUIName = _T("FuturesPastDealUI");
const TCHAR* const kFuturesCapitalFlowUIName = _T("FuturesCapitalFlowUI");

const TCHAR* const kStockBuyUIXML = _T("xml\\StockBuyUI.xml");
const TCHAR* const kStockSellUIXML = _T("xml\\StockSellUI.xml");
const TCHAR* const kStockCancelUIXML = _T("xml\\StockCancelUI.xml");
const TCHAR* const kFundSplitUIXML = _T("xml\\FundSplitUI.xml");
const TCHAR* const kFundMergeUIXML = _T("xml\\FundMergeUI.xml");
const TCHAR* const kStockCapitalPositionUIXML = _T("xml\\StockCapitalPositionUI.xml");
const TCHAR* const kStockDailyOrderUIXML = _T("xml\\StockDailyOrderUI.xml");
const TCHAR* const kStockPastOrderUIXML = _T("xml\\StockPastOrderUI.xml");
const TCHAR* const kStockDailyDealUIXML = _T("xml\\StockDailyDealUI.xml");
const TCHAR* const kStockPastDealUIXML = _T("xml\\StockPastDealUI.xml");
const TCHAR* const kStockCapitalFlowUIXML = _T("xml\\StockCapitalFlowUI.xml");

const TCHAR* const kFuturesOrderUIXML = _T("xml\\FuturesOrderUI.xml");
const TCHAR* const kFuturesCapitalPositionUIXML = _T("xml\\FuturesCapitalPositionUI.xml");
const TCHAR* const kFuturesDailyOrderUIXML = _T("xml\\FuturesDailyOrderUI.xml");
const TCHAR* const kFuturesPastOrderUIXML = _T("xml\\FuturesPastOrderUI.xml");
const TCHAR* const kFuturesDailyDealUIXML = _T("xml\\FuturesDailyDealUI.xml");
const TCHAR* const kFuturesPastDealUIXML = _T("xml\\FuturesPastDealUI.xml");
const TCHAR* const kFuturesCapitalFlowUIXML = _T("xml\\FuturesCapitalFlowUI.xml");

DUI_BEGIN_MESSAGE_MAP(CMainFrameWnd, WindowImplBase)
DUI_ON_MSGTYPE(DUI_MSGTYPE_CLICK, OnClick)
DUI_ON_MSGTYPE(DUI_MSGTYPE_SELECTCHANGED, OnSelectChanged)
DUI_ON_MSGTYPE(DUI_MSGTYPE_ITEMCLICK, OnItemClick)
DUI_END_MESSAGE_MAP()

HWND CMainFrameWnd::m_hwnd = NULL;
//ModuleServer* CMainFrameWnd::m_pModuleServer = NULL;

CMainFrameWnd::CMainFrameWnd()
{
}

CMainFrameWnd::~CMainFrameWnd()
{
	for (int idx=0; idx<m_TabContainer.GetSize(); ++idx)
	{
		RemoveVirtualWnd(m_TabContainer[idx]);
	}
	//delete m_pFactory;
	//delete m_pModuleServer;
}

LPCTSTR CMainFrameWnd::GetWindowClassName() const
{
	return _T("MainFrameWnd");
}

UINT CMainFrameWnd::GetClassStyle()
{
	return CS_DBLCLKS;
}

void CMainFrameWnd::OnFinalMessage(HWND hWnd)
{
	delete this;
}

CDuiString CMainFrameWnd::GetSkinFolder()
{
	return _T("skin");
}

CDuiString CMainFrameWnd::GetSkinFile()
{
	return _T("xml\\skin.xml");
}

DuiLib::UILIB_RESOURCETYPE CMainFrameWnd::GetResourceType() const
{
    return UILIB_FILE;
}

LPCTSTR CMainFrameWnd::GetResourceID() const
{
	return 0;
}

void CMainFrameWnd::AdaptWindowSize( UINT cxScreen )
{
    int iX = 968, iY = 600;
    int iWidthList = 225, iWidthSearchEdit = 193;
    SIZE szFixSearchBtn = {201, 0};

    if(cxScreen <= 1024)      // 800*600  1024*768  
    {
        iX = 775;
        iY = 470;
    } 
    else if(cxScreen <= 1280) // 1152*864  1280*800  1280*960  1280*1024
    {
        iX = 968;
        iY = 600;
    }
    else if(cxScreen <= 1366) // 1360*768 1366*768
    {
        iX = 1058;
        iY = 656;
        iWidthList        += 21;
        iWidthSearchEdit  += 21;
        szFixSearchBtn.cx += 21;
    }
    else                      // 1440*900
    {
        iX = 1224;
        iY = 760;
        iWidthList        += 66;
        iWidthSearchEdit  += 66;
        szFixSearchBtn.cx += 66;
    }

    CControlUI *pctnPlaylist = m_PaintManager.FindControl(_T("ctnPlaylist"));
    CControlUI *peditSearch  = m_PaintManager.FindControl(_T("editSearch"));
    CControlUI *pbtnSearch   = m_PaintManager.FindControl(_T("btnSearch"));
    if (pctnPlaylist && peditSearch && pbtnSearch)
    {
        pctnPlaylist->SetFixedWidth(iWidthList);
        peditSearch->SetFixedWidth(iWidthSearchEdit);
        pbtnSearch->SetFixedXY(szFixSearchBtn);
    }

    ::SetWindowPos(m_PaintManager.GetPaintWindow(), NULL, 0, 0, iX, iY, SWP_FRAMECHANGED|SWP_NOZORDER|SWP_NOACTIVATE);
    CenterWindow();
}

void CMainFrameWnd::InitWindow()
{
	//m_pTradeCtrl = new CTradeCtrl(this);
    m_hwnd = GetHWND();
	
	m_pLogoutBtn = static_cast<CButtonUI*>(m_PaintManager.FindControl(kLogoutBtnCtrlName));
    m_pLoginBtn = static_cast<CButtonUI*>(m_PaintManager.FindControl(kLoginBtnCtrlName));
    m_pLockBtn = static_cast<CButtonUI*>(m_PaintManager.FindControl(kLockBtnCtrlName));
	m_pRefreshAllBtn = static_cast<CButtonUI*>(m_PaintManager.FindControl(kRefreshAllBtnCtrlName));

    m_pProductComb = static_cast<CComboBoxUI*>(m_PaintManager.FindControl(kProcductCombCtrlName));
	m_pMenuTree = static_cast<CTreeViewUI*>(m_PaintManager.FindControl(kMenuTreeCtrlName)); 

	m_pMinBtn = static_cast<CButtonUI*>(m_PaintManager.FindControl(kMinBtnCtrlName));
    m_pMaxBtn = static_cast<CButtonUI*>(m_PaintManager.FindControl(kMaxBtnCtrlName));
	m_pRestoreBtn = static_cast<CButtonUI*>(m_PaintManager.FindControl(kRestoreBtnCtrlName)); 
	m_pCloseBtn = static_cast<CButtonUI*>(m_PaintManager.FindControl(kCloseBtnCtrlName)); 

	m_pVersionLab = static_cast<CLabelUI*>(m_PaintManager.FindControl(kVersionLabCtrlName)); 
	m_pStatusLab = static_cast<CLabelUI*>(m_PaintManager.FindControl(kStatusLabCtrlName)); 
	m_pTimeLab = static_cast<CLabelUI*>(m_PaintManager.FindControl(kTimeLabCtrlName)); 

	CDuiString version = m_pVersionLab->GetText();
    version.Replace(_T("$Version"), _T(VERSION));
    m_pVersionLab->SetText(version);

	for (int idx=0; idx<m_TabContainer.GetSize(); ++idx)
	{
		CAbstractUI* pUI = (CAbstractUI*)m_TabContainer.Find(m_TabContainer[idx]);
		pUI->Initialize();
	}

	for (int idx=0; idx<m_TabContainer.GetSize(); ++idx)
	{
		CAbstractUI* pUI = (CAbstractUI*)m_TabContainer.Find(m_TabContainer[idx]);
		if (pUI->GetIndex() == 0)
		{
			pUI->RefreshWnd();
			break;
		}
	}

    //自适应窗口
    MONITORINFO oMonitor = {};
    oMonitor.cbSize = sizeof(oMonitor);
    ::GetMonitorInfo(::MonitorFromWindow(*this, MONITOR_DEFAULTTONEAREST), &oMonitor);
    AdaptWindowSize(oMonitor.rcMonitor.right - oMonitor.rcMonitor.left);
    ::GetWindowPlacement(*this, &m_OldWndPlacement);

	//时钟定时器
	::SetTimer(m_hWnd, 0, 1000, NULL);


	//DWORD threadID = 0;
	//HANDLE hThread = CreateThread(NULL, 0, &CMainFrameWnd::RunModuleServerThr, 0, 0, &threadID);
	
	//WaitForSingleObject(threadID, INFINITE);
	//CContext::GetInstance().RunModuleServer();
}
/**/
DWORD WINAPI CMainFrameWnd::RunModuleServerThr(LPVOID pM)
{
	DUITRACE(_T("RunModuleServerThr.................."));
	//CContext::GetInstance().RunModuleServer();
	return 0;
}

CControlUI* CMainFrameWnd::CreateControl(LPCTSTR pstrClassName)
{
	CDuiString strXML;
	CDialogBuilder builder;
	CAbstractUI* pUI = NULL;

	//现货交易
	if (_tcsicmp(pstrClassName, kStockBuyUIName) == 0)
	{
		pUI = new CStockBuyUI(kStockBuyUIXML, &m_PaintManager);
	}
	else if (_tcsicmp(pstrClassName, kStockSellUIName) == 0)
	{
		pUI = new CStockSellUI(kStockSellUIXML, &m_PaintManager);
	}
	else if (_tcsicmp(pstrClassName, kStockCancelUIName) == 0)
	{
		pUI = new CStockCancelUI(kStockCancelUIXML, &m_PaintManager);
	}	
	else if (_tcsicmp(pstrClassName, kFundSplitUIName) == 0)
	{
		pUI = new CFundSplitUI(kFundSplitUIXML, &m_PaintManager);
	}
	else if (_tcsicmp(pstrClassName, kFundMergeUIName) == 0)
	{
		pUI = new CFundMergeUI(kFundMergeUIXML, &m_PaintManager);
	}
	//现货查询
	else if (_tcsicmp(pstrClassName, kStockCapitalPositionUIName) == 0)
	{
		pUI = new CStockCapitalPositionUI(kStockCapitalPositionUIXML, &m_PaintManager);
	}
	else if (_tcsicmp(pstrClassName, kStockDailyOrderUIName) == 0)
	{
		pUI = new CStockDailyOrderUI(kStockDailyOrderUIXML, &m_PaintManager);
	}
	else if (_tcsicmp(pstrClassName, kStockPastOrderUIName) == 0)
	{
		pUI = new CStockPastOrderUI(kStockPastOrderUIXML, &m_PaintManager);
	}
	else if (_tcsicmp(pstrClassName, kStockDailyDealUIName) == 0)
	{
		pUI = new CStockDailyDealUI(kStockDailyDealUIXML, &m_PaintManager);
	}
	else if (_tcsicmp(pstrClassName, kStockPastDealUIName) == 0)
	{
		pUI = new CStockPastDealUI(kStockPastDealUIXML, &m_PaintManager);
	}
	else if (_tcsicmp(pstrClassName, kStockCapitalFlowUIName) == 0)
	{
		pUI = new CStockCapitalFlowUI(kStockCapitalFlowUIXML, &m_PaintManager);
	}

	//期货交易
	else if (_tcsicmp(pstrClassName, kFuturesOrderUIName) == 0)
	{
		pUI = new CFuturesOrderUI(kFuturesOrderUIXML, &m_PaintManager);
	}
	//期货查询
	else if (_tcsicmp(pstrClassName, kFuturesCapitalPositionUIName) == 0)
	{
		pUI = new CFuturesCapitalPositionUI(kFuturesCapitalPositionUIXML, &m_PaintManager);
	}
	else if (_tcsicmp(pstrClassName, kFuturesDailyOrderUIName) == 0)
	{
		pUI = new CFuturesDailyOrderUI(kFuturesDailyOrderUIXML, &m_PaintManager);
	}
	else if (_tcsicmp(pstrClassName, kFuturesPastOrderUIName) == 0)
	{
		pUI = new CFuturesPastOrderUI(kFuturesPastOrderUIXML, &m_PaintManager);
	}
	else if (_tcsicmp(pstrClassName, kFuturesDailyDealUIName) == 0)
	{
		pUI = new CFuturesDailyDealUI(kFuturesDailyDealUIXML, &m_PaintManager);
	}
	else if (_tcsicmp(pstrClassName, kFuturesPastDealUIName) == 0)
	{
		pUI = new CFuturesPastDealUI(kFuturesPastDealUIXML, &m_PaintManager);
	}
	else if (_tcsicmp(pstrClassName, kFuturesCapitalFlowUIName) == 0)
	{
		pUI = new CFuturesCapitalFlowUI(kFuturesCapitalFlowUIXML, &m_PaintManager);
	}
	
	if (pUI)
	{
		AddVirtualWnd(pUI->GetVirtualwndName(), pUI);
		pUI->SetHWND(GetHWND());
		m_TabContainer.Set(pUI->GetVirtualwndName(), pUI);
		return pUI;
	}
	return NULL;
}

void CMainFrameWnd::Notify(TNotifyUI& msg)
{
	return WindowImplBase::Notify(msg);
}

void CMainFrameWnd::OnClick(TNotifyUI& msg)
{
    if( msg.pSender == m_pLogoutBtn ) 
    {
		OnLogout(msg); 
    }
    else if( msg.pSender == m_pLoginBtn ) 
    { 
		OnLogin(msg);
    }
    else if( msg.pSender == m_pLockBtn ) 
    { 
		OnLock(msg);
    }
    else if( msg.pSender == m_pRefreshAllBtn ) 
    { 
		//
    }
    else if( msg.pSender == m_pMinBtn ) 
    { 
        SendMessage(WM_SYSCOMMAND, SC_MINIMIZE, 0);
    }
    else if( msg.pSender == m_pMaxBtn ) 
    { 
        SendMessage(WM_SYSCOMMAND, SC_MAXIMIZE, 0);
    }
    else if( msg.pSender == m_pRestoreBtn ) 
    { 
        SendMessage(WM_SYSCOMMAND, SC_RESTORE, 0);
    }
    else if( msg.pSender == m_pCloseBtn ) 
    { 
        PostQuitMessage(0);      
    }
	return;
}

void CMainFrameWnd::OnSelectChanged( TNotifyUI &msg )
{
	
}

void CMainFrameWnd::OnItemClick( TNotifyUI &msg )
{
	CDuiString name = msg.pSender->GetName();
	CTabLayoutUI* pTab = static_cast<CTabLayoutUI*>(m_PaintManager.FindControl(_T("Switch")));
    
    static CTreeNodeUI* pLastNode = NULL;
    static CAbstractUI* pLastTab = NULL;
    CAbstractUI* pUI = NULL;

    for (int idx=0; idx<m_TabContainer.GetSize(); ++idx)
    {
        if (name == m_TabContainer[idx])
        {
            pUI = (CAbstractUI*)m_TabContainer.Find(name);
        }
    }
    if (pUI == NULL) return;

    if (pLastTab != NULL && pUI != pLastTab && !pLastTab->CanChange()) 
	{
        //if (pLastNode) pLastNode->Selected(true);
		//::MessageBox(NULL, _T(""), _T(""), MB_OK);
		return;
    }
    
    if (pUI && pUI!=pLastTab) 
	{
        pUI->RefreshWnd();
        pTab->SelectItem(pUI->GetIndex());
        pLastTab = pUI;
        pLastNode = static_cast<CTreeNodeUI*>(m_PaintManager.FindControl(msg.pSender->GetName()));
    }
}

LRESULT CMainFrameWnd::HandleCustomMessage( UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled )
{
    LRESULT lRes = TRUE;
    bHandled = TRUE;
    switch(uMsg)
    {
		case WM_TIMER:
			lRes = OnUpdataTimeClock();
			break;		
		case WM_USER_RETURN_RESPOND:
			lRes = OnRespond(wParam, lParam, bHandled);
			break;
		case WM_USER_PRODUCTLIST_REQ:
			lRes = OnProductListReq(wParam, lParam, bHandled);
			break;
		default:
			bHandled = FALSE;
			break;
    }
	/*
	if (!bHandled)
	{
		for (int idx = 0; idx<m_TabContainer.GetSize(); ++idx)
		{
			CAbstractUI* pUI = (CAbstractUI*)m_TabContainer.Find(m_TabContainer[idx]);
			pUI->HandleCustomMessage(uMsg, wParam, lParam, bHandled);
		}
	}	
	*/
    return lRes;
}

LRESULT CMainFrameWnd::OnRespond(WPARAM wParam, LPARAM lParam, BOOL& bHandled)
{
	LRESULT lRes = FALSE;
	/*
	CBusinessBase* BusinessRes = static_cast<CBusinessBase*>(wParam);			
	CAbstractUI* pUI = (CAbstractUI*)m_TabContainer.Find(BusinessRes->GetSenderWndName());
	if (NULL != pUI)
    {
		pUI->HandleCustomMessage(uMsg, wParam, lParam, bHandled);
		lRes = TRUE;
    }
	else
	{
		DUITRACE(_T("find senderWndUI error:%s"), BusinessRes->GetSenderWndName());
	}
	
	*/
	return lRes;	
}

LRESULT CMainFrameWnd::OnProductListReq(WPARAM wParam, LPARAM lParam, BOOL& bHandled)
{
	if (!CContext::GetInstance().m_sUsrName.IsEmpty())
	{
		if (m_pProductComb)
		{
			/*
			DataSetRow* pDataSetRow = new DataSetRow;
			CBusinessBase* ProductBusiness = new CProductBusiness(GetHWND(), this->GetWindowClassName());
			pDataSetRow->Set("账号", Base::CharacterSet::UnicodeToANSI(CContext::GetInstance().m_sUsrName));
			ProductBusiness->AddRow(pDataSetRow);
			ProductBusiness->SendRequest();
			delete pDataSetRow;
			*/
			CDuiString sText;
			for (int i=0; i<3; i++)
			{
				CListLabelElementUI* p = new CListLabelElementUI;
				p->SetTag(i);				
				sText.SmallFormat(_T("礼一%d期"), i+1);
				p->SetText(sText);
				m_pProductComb->Add(p);
			}
			::MessageBox(m_hWnd, _T("已获取产品列表"), NULL, NULL );
			return TRUE;
		}
	}
	return FALSE;
}

/////////////
void CMainFrameWnd::OnLogin(TNotifyUI& msg)
{
    if (CContext::GetInstance().m_sUsrName.IsEmpty())
	{
		CLoginFrameWnd* pLoginFrame = new CLoginFrameWnd();
		if( pLoginFrame == NULL ) { Close(); return; }
		pLoginFrame->Create(m_hWnd, _T("Login"), UI_WNDSTYLE_DIALOG, 0, 0, 0, 0, 0, NULL);
		pLoginFrame->CenterWindow();
		pLoginFrame->ShowModal();

		delete pLoginFrame;//防gdi泄露

		//登陆成功获取产品
		::PostMessage(GetHWND(), WM_USER_PRODUCTLIST_REQ, NULL, NULL);
	}
	else
	{
		::MessageBox(GetHWND(), _T("已成功登陆!"), NULL, NULL);
		return;
	}
}

void CMainFrameWnd::OnLogout(TNotifyUI& msg)
{
	if (!CContext::GetInstance().m_sUsrName.IsEmpty())
	{
		CContext::GetInstance().m_sUsrName.Empty();
		CContext::GetInstance().m_sUsrPasswd.Empty();
		m_pProductComb->RemoveAll();
		::MessageBox(GetHWND(), _T("已注销!"), NULL, NULL);	
	}
}

void CMainFrameWnd::OnLock( TNotifyUI& msg )
{
	if (CContext::GetInstance().m_sUsrName.IsEmpty())
	{
		return;
	}
	/*
	CDuiRect rcWnd;
	::GetWindowRect(*this, &rcWnd);
	CLockScreenUI* pLockUI = new CLockScreenUI();
	if( pLockUI == NULL ) { Close(); return; }
	pLockUI->Create(m_hWnd, _T("Lock"), UI_WNDSTYLE_DIALOG, 0, rcWnd, NULL);
	pLockUI->CenterWindow();
	pLockUI->ShowModal();

	delete pLockUI;//防gdi泄露
	*/
	/*
	CDuiRect rcWnd;
	::GetWindowRect(*this, &rcWnd);

	RECT rc;
	rc.left = rcWnd.left + (rcWnd.GetWidth()-m_pLockVLay->GetWidth())/2;
	rc.top  = rcWnd.top + (rcWnd.GetHeight()-m_pLockVLay->GetHeight())/2;
	rc.right = rc.left + m_pLockVLay->GetWidth();
	rc.bottom = rc.top + m_pLockVLay->GetHeight();

	m_pLockVLay->SetInset(rc);
	m_pLockVLay->SetVisible(TRUE);
	*/
}

LRESULT CMainFrameWnd::OnUpdataTimeClock(void)
{
	static CDuiString sText;
	::GetLocalTime(&m_sysTime);
	
	sText.SmallFormat(_T("%4d/%02d/%02d  %02d:%02d:%02d"),
		m_sysTime.wYear, m_sysTime.wMonth, m_sysTime.wDay, m_sysTime.wHour, m_sysTime.wMinute, m_sysTime.wSecond);
	
	m_pTimeLab->SetText(sText);
	return TRUE;
}