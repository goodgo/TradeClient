#ifndef __PRODUCT_BUSINESS_H__
#define __PRODUCT_BUSINESS_H__

#pragma once

#include "../Base/BusinessBase.h"

class CProductBusiness : public CBusinessBase
{
public:
	CProductBusiness(HWND hWnd, CDuiString SenderWndName);
};

#endif