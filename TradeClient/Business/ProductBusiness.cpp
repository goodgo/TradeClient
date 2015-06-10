#include "ProductBusiness.h"
#include "../Base/UserMessage.h"

const std::string const BusinessId = "ProductBusinessID";

CProductBusiness::CProductBusiness(HWND hWnd, CDuiString SenderWndName)
:CBusinessBase(BusinessId)
{
	m_hWnd = hWnd;
	m_SenderWndName = SenderWndName;
}