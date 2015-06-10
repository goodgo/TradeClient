#ifndef __FUTURES_BUSINESS_H__
#define __FUTURES_BUSINESS_H__

#pragma once

#include "TradeBusiness.h"

class CFuturesBuiness : public CTradeBusiness
{
public:
	CFuturesBusiness();
	bool CreateRequest(); 
	void DoTrade();

	bool SelectOrders();
	bool SelectDeal();
	bool SelectPosition();

private:
	bool Respond();
};

#endif