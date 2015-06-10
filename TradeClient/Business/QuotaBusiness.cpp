#include "QuotaBusiness.h"
#include "../Base/UserMessage.h"

const std::string const BusinessId = "QuotaBusinessID";

CQuotaBusiness::CQuotaBusiness(HWND hWnd, CDuiString SenderWndName)
:CBusinessBase(BusinessId)
{
	m_hWnd = hWnd;
	m_SenderWndName = SenderWndName;

	this->GetRequest()->_status = Subscription;
}