#include "StockBusiness.h"
#include "../Base/UserMessage.h"

const std::string const BusinessId = "???    StockBusinessID";

CStockBusiness::CStockBusiness(HWND hWnd, CDuiString SenderWndName)
:CBusinessBase(BusinessId)
{
	m_hWnd = hWnd;

	m_SenderWndName = SenderWndName;

}

void 
CStockBusiness::RequestQuota()
{
	
}

void
CStockBusiness::Respond()
{
	::PostMessage(GetHWND(), WM_USER_RETURN_RESPOND, (WPARAM)this, 0L);
}