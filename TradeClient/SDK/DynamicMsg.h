#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "DynamicMsgDataSpace.h"
#include "DynamicMsgFactory.h"
#include "DataSet.h"
#include "pugixml.hpp"


#define MAX_ID 10000

enum DynamicMsgStatus{REQUEST=1, RESPOND};

class SDK_API DynamicMsg
{
public:
	DynamicMsg(DynamicMsgFactory* df, DynamicMsgStatus, pugi::xml_document*);
	~DynamicMsg();

	int ID();
	DynamicMsgFactory* Factory();
	DynamicMsgDataSpace* DataSpace();
	DynamicMsgStatus Status();

	int input(DataSet&);
	int output(DataSet&);
	
	bool Serialize(string &);
	bool Parse(const string &);

	void DataReSet();
private:
	DynamicMsgFactory *_Factory;
	DynamicMsgDataSpace _DataSpace;
	DynamicMsgStatus _status;
	int _ID;
	pugi::xml_document* _xml;
};

