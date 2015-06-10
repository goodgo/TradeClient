#ifndef __LOGIN_BUSINESS_H__
#define __LOGIN_BUSINESS_H__

#pragma once

#include "../Base/BusinessBase.h"

class CLoginBusiness : public CBusinessBase
{
public:
	CLoginBusiness(HWND hWnd, CDuiString SenderWndName);
};

#endif