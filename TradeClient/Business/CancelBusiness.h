#ifndef __CANCEL_BUSINESS_H__
#define __CANCEL_BUSINESS_H__

#pragma once

#include "../Base/BusinessBase.h"

class CCancelBusiness : public CBusinessBase
{
public:
	CCancelBusiness(HWND hWnd, CDuiString SenderWndName);
};

#endif