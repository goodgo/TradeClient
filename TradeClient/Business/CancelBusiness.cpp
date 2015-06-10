#include "CancelBusiness.h"
#include "../Base/UserMessage.h"

const std::string const BusinessId = "CancelBusinessID";

CCancelBusiness::CCancelBusiness(HWND hWnd, CDuiString SenderWndName)
:CBusinessBase(BusinessId)
{
	m_hWnd = hWnd;
	m_SenderWndName = SenderWndName;
}