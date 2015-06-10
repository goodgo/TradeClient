#pragma once

#include "DynamicMsg.h"
#include "pugixml.hpp"
#include <map>

using namespace std;

class SDK_API DynamicMsgGroup
{
public:
	DynamicMsgGroup();
	~DynamicMsgGroup();

    DynamicMsg* get(DynamicMsgStatus);
	DynamicMsg* add_dataSet(DynamicMsgFactory*, DynamicMsgStatus);
	int size() const;
	void clear();
	bool Serialize(string&, DynamicMsgStatus);
	void DataReset();
private:
	pugi::xml_document _xml;
	map<DynamicMsgStatus, DynamicMsg*> _group;
};

