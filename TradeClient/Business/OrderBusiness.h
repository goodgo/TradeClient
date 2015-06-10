#ifndef __ORDER_BUSINESS_H__
#define __ORDER_BUSINESS_H__

#pragma once

#include "../Base/BusinessBase.h"

class COrderBusiness : public CBusinessBase
{
public:
	COrderBusiness(HWND hWnd, CDuiString SenderWndName);
};

#endif