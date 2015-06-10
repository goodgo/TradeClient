#include "LoginBusiness.h"
#include "../Base/UserMessage.h"

const std::string const BusinessId = "LoginBusinessID";

CLoginBusiness::CLoginBusiness(HWND hWnd, CDuiString SenderWndName)
:CBusinessBase(BusinessId)
{
	m_hWnd = hWnd;
	m_SenderWndName = SenderWndName;
}