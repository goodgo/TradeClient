#ifndef __BUSINESS_BASE_H__
#define __BUSINESS_BASE_H__

#include <string>
#include "Context.h"

#include "../SDK/ModuleServer.h"
#include "../SDK/Request.h"
#include "../SDK/DataSet.h"
#include "../SDK/DataSetRow.h"

#include "../SDK/IRespondInterface.h"
/*
//异步通知接口
class IRespondInterface
{
private:
	virtual void Respond()=0;
};
*/
//交易接口
class ITradeInterface
{
public:
	virtual void DoTrade()=0;
};

class CBusinessBase : public IRespondInterface
{
public:

	CBusinessBase(std::string BusinessId);
	
	virtual ~CBusinessBase();
	
	int SetReqDataSet();

	int GetNextRow();

	int GetResDataSet();

	int SetKeyValue(std::string strKey, std::string strValue);

	std::string GetValueByKey(std::string strKey);

	void AddRow(DataSetRow* pDataSetRow);

	Request* GetRequest();

	HWND GetHWND();	
	
	CDuiString GetSenderWndName();

	bool SendRequest();
	
	CContext GetContext();
/*
	bool SetContextMarketID(UINT id);	

	bool SetContextName(CDuiString name);

	bool SetContextPasswd(CDuiString passwd);
*/
	virtual void Respond();

private:

	int m_iCurRow;

	DataSet m_ReqDataSet;

	DataSet m_ResDataSet;

	DataSetRow* m_pDataSetRow;

	Request* m_pRequest;

protected:

	HWND m_hWnd;

	CDuiString m_SenderWndName;
};

#endif