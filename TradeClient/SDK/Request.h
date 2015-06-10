#pragma once

#include "DynamicMsgGroup.h"
#include "IRespondInterface.h"
#include "L2.pb.h"

enum ReqStatus{General=1, Subscription};

class SDK_API Request
{
public:
	Request(DynamicMsgFactory* factory, ReqStatus status = General){
		_status = status;
		_data_set_group = new DynamicMsgGroup;
		_data_set_group->add_dataSet(factory, REQUEST); 
		_data_set_group->add_dataSet(factory, RESPOND);
	}
	~Request();

	IRespondInterface* _callback;
	int _mfunc;
	int _sfunc;
	int	_produceID;
	int _moduleNumber;
	ReqStatus _status;
	DynamicMsgGroup* _data_set_group;
};

