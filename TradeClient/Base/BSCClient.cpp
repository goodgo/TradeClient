#include "BSCClient.h"

CBSCClient::CBSCClient()
{
	//this->m_pServiceProxy;
}

BSCClient& CBSCClient::GetInstance()
{
	static BSCClient BSC_client;
	return BSC_client;
}

bool CBSCClient::SendRequest(Request *)
{

}


bool CBSCClient::IsConnected()
{

}

bool CBSCClient::NeedReConnect()
{

}

long CBSCClient::GeneralSerial()
{

}

bool CBSCClient::PacketRequest()
{

}