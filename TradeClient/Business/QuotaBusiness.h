#ifndef __QUOTA_BUSINESS_H__
#define __QUOTA_BUSINESS_H__

#include <string>
#include "../Base/BusinessBase.h"

class CQuotaBusiness : public CBusinessBase
{
public:
	CQuotaBusiness(HWND hWnd, CDuiString SenderWndName);
};

#endif