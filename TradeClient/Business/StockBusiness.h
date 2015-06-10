#ifndef __STOCK_BUSINESS_H__
#define __STOCK_BUSINESS_H__

#pragma once

#include <string>
#include "../Base/BusinessBase.h"


class CStockBusiness :
	public CBusinessBase//, public CTradeBusiness
{
public:

	CStockBusiness(HWND hWnd, CDuiString SenderWndName);

	void RequestQuota();

	void DoTrade();

	bool SelectOrders();

	bool SelectDeal();

	bool SelectPosition();

private:

	void Respond();
};

#endif