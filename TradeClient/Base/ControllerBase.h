#ifndef __CONTROLLER_BASE_H__
#define __CONTROLLER_BASE_H__

#pragma once

class CControllerBase
{
public:
	virtual LRESULT OnClick();
	virtual LRESULT OnSelectChanged();
	virtual LRESULT OnItemClick();
	virtual LRESULT OnItemActive();

	virtual LRESULT OnInit();
	virtual LRESULT OnClose();
	virtual LRESULT OnMinimize();
	virtual LRESULT OnMaximize();
	virtual LRESULT OnRestore();
	virtual LRESULT OnRecvRespon();
};
#endif