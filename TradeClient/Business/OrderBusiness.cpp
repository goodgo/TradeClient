#include "OrderBusiness.h"
#include "../Base/UserMessage.h"

const std::string const BusinessId = "OrderBusinessID";

COrderBusiness::COrderBusiness(HWND hWnd, CDuiString SenderWndName)
:CBusinessBase(BusinessId)
{
	m_hWnd = hWnd;
	m_SenderWndName = SenderWndName;
}