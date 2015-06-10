#ifndef __LOGINCONTROLLER_H__
#define __LOGINCONTROLLER_H__

#pragma once

#include "ControllerBase.h"

class CLoginCtrl : public CControllerBase
{
public:
	CLoginCtrl();
	~CLoginCtrl();
	
	LRESULT OnClick();
	LRESULT OnSelectUsrName();
	LRESULT OnLoginSucc();
	LRESULT OnLoginErr();
	LRESULT OnRegisterUsr();
	LRESULT OnRememberUsrName();
	LRESULT OnRememberUsrPasswd();
	LRESULT OnForgetPasswd();

public:
	LRESULT OnLogin();
	LRESULT OnLogout();
	LRESULT OnRecvRespon();

private:
	CDuiString GetName();
	CDuiString GetPasswd();
};

#endif