#pragma once

#include "../stdafx.h"

#define STOCK_BUY_NODE_INDEX				0
#define STOCK_SELL_NODE_INDEX				1
#define STOCK_CANCEL_NODE_INDEX				2
#define FUND_SPLIT_NODE_INDEX				3
#define FUND_MERGE_NODE_INDEX				4
#define STOCK_CAPITALPOSITION_NODE_INDEX	5
#define STOCK_DAILYORDER_NODE_INDEX			6
#define STOCK_PASTORDER_NODE_INDEX			7
#define STOCK_DAILYDEAL_NODE_INDEX			8
#define STOCK_PASTDEAL_NODE_INDEX			9
#define STOCK_CAPITALFLOW_NODE_INDEX		10

#define FUTURES_ORDER_NODE_INDEX			11
#define FUTURES_CAPITALPOSITION_NODE_INDEX	12
#define FUTURES_DAILYORDER_NODE_INDEX		13
#define FUTURES_PASTORDER_NODE_INDEX		14
#define FUTURES_DAILYDEAL_NODE_INDEX		15
#define FUTURES_PASTDEAL_NODE_INDEX			16
#define FUTURES_CAPITALFLOW_NODE_INDEX		17

class CAbstractUI : public CContainerUI, public CNotifyPump
{
public:
    CAbstractUI(CPaintManagerUI* pm):m_hWnd(NULL),m_pPaintManager(pm){};

    virtual ~CAbstractUI(){};

    virtual void Initialize() {};

    virtual CDuiString GetVirtualwndName() = 0;

    virtual void RefreshWnd() = 0;

    virtual int GetIndex() = 0;

    virtual bool CanChange() 
    {
        return true;
    }

    virtual LRESULT HandleCustomMessage( UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled )
    {
        bHandled = FALSE;
        return 0;
    }

    /// ÉèÖÃ´°¿Ú¾ä±ú
    inline void SetHWND(HWND hwnd)
    {
        m_hWnd = hwnd;
    }

    inline HWND GetHWND() 
    {
        return m_hWnd;
    }

    inline CPaintManagerUI* GetPaintMgr()
    {
        return m_pPaintManager;
    }

private:

    CPaintManagerUI* m_pPaintManager;

    HWND    m_hWnd;

protected:

};