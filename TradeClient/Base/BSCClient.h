#ifndef __BSC_CLIENT_H__
#define __BSC_CLIENT_H__

#pragma once

//#include "Request.h"
//#include "ServiceProxy.h"

class CBSCClient
{
public:
	BSCClient();
	static BSCClient& GetInstance();
	static bool SendRequest(Request *);
	static ServiceProxy* m_pServiceProxy;

	bool IsConnected();
	bool NeedReConnect();
	
private:
	long GeneralSerial();
	bool PacketRequest();
};

#endif