#ifndef __CONTEXT_H__
#define __CONTEXT_H__

#pragma once

#include "../stdafx.h"
//#include "BSCClient.h"
//#include "../SDK/ModuleServer.h"

class CContext
{
public:
	static CContext& GetInstance()
	{    
		static CContext Context;
		return Context;
	};	
	/*
	void RunModuleServer()
	{
		if (NULL == m_pModuleServer)
		{
			m_pModuleServer = new ModuleServer();
			m_pModuleServer->Init();
			m_pModuleServer->Run(1);
		}
	}
	
	ModuleServer* GetModuleServer()
	{
		ASSERT(m_pModuleServer);

		return m_pModuleServer;
	}
	*/
	//CBSCClient* GetClient(){};

	//UINT m_uMarketID;

	CDuiString m_sProductName;

	CDuiString m_sUsrName;

	CDuiString m_sUsrPasswd;

	bool m_isConnected;

	bool m_isConnecting;

private:
	//CBSCClient* m_pClient;

	//ModuleServer* m_pModuleServer;
};

#endif