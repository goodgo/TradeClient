#include <string>
#include "BusinessBase.h"
#include "Context.h"
#include "UserMessage.h"

#include "../SDK/DynamicMsgFactoryManager.h"
#include "../SDK/DynamicMsgFactory.h"
#include "../SDK/DataSet.h"
#include "../SDK/DataSetRow.h"

CBusinessBase::CBusinessBase(std::string BusinessId)
{
	DynamicMsgFactoryManager* dmfm = CContext::GetInstance().GetModuleServer()->get_DMFM();
	DynamicMsgFactory* dmf = dmfm->get_factory(BusinessId);

	m_iCurRow = 0;
	m_pRequest = new Request(dmf);
	m_pRequest->_callback = reinterpret_cast<IRespondInterface*>(this);
	m_pRequest->_status = General;
	
	//m_pDataSetRow = new DataSetRow;
}

CBusinessBase::~CBusinessBase()
{	
	delete m_pRequest;
	delete m_pDataSetRow;
}

//��ȡӦ������ݼ���
int
CBusinessBase::GetResDataSet()
{
	m_pRequest->_data_set_group->get(RESPOND)->output(m_ResDataSet);
	return 1;
}

int 
CBusinessBase::GetNextRow()
{
	if (m_iCurRow < m_ResDataSet.Length()-1)
	{	
		m_pDataSetRow = m_ResDataSet.Get(m_iCurRow++);
		return 1;
	}
	return 0;
}

//������ֶθ�ֵ
int
CBusinessBase::SetKeyValue(std::string strKey, std::string strValue)
{
	return m_pDataSetRow->Set(strKey, strValue);
}

//ͨ���ֶ��������ֶ�ֵ
std::string
CBusinessBase::GetValueByKey(std::string strKey)
{
	for (int iCurRow = 0; iCurRow < m_ResDataSet.Length() - 1; iCurRow++)
	{
		return m_ResDataSet.Get(iCurRow)->GetString(strKey);
	}
	return "";
}

//������������ݼ���
void
CBusinessBase::AddRow(DataSetRow* pDataSetRow)
{
	m_ReqDataSet.Append(pDataSetRow, false);
	//delete m_pDataSetRow;
	//m_pDataSetRow->clear();
	//return m_pRequest->_data_set_group->get(REQUEST)->input(m_ReqDataSet);
}

bool
CBusinessBase::SendRequest()
{
	//SetReqDataSet();
	ASSERT(m_ResDataSet.Length());
	m_pRequest->_data_set_group->get(REQUEST)->input(m_ReqDataSet);
	CContext::GetInstance().GetModuleServer()->append_req(m_pRequest);
	CContext::GetInstance().GetModuleServer()->push_bell();
	return true;
}

CDuiString
CBusinessBase::GetSenderWndName()
{
	return m_SenderWndName;
}

HWND
CBusinessBase::GetHWND()
{
	return m_hWnd;
}

Request*
CBusinessBase::GetRequest()
{
	return m_pRequest;
}

CContext
CBusinessBase::GetContext()
{
	return CContext::GetInstance();
}
/*
bool
CBusinessBase::SetContextMarketID(UINT id)
{
	return true;
}

bool
CBusinessBase::SetContextName(CDuiString name)
{
	return true;
}

bool
CBusinessBase::SetContextPasswd(CDuiString passwd)
{
	return true;
}
*/
void
CBusinessBase::Respond()
{
	::PostMessage(GetHWND(), WM_USER_RETURN_RESPOND, (WPARAM)this, 0L);
}