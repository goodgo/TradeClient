#pragma once

#include "DynamicMsgFactory.h"
#include "pugixml.hpp"
#include <string>
#include <map>

using namespace std;

class SDK_API DynamicMsgFactoryManager
{
public:
	DynamicMsgFactoryManager(pugi::xml_document*);
	~DynamicMsgFactoryManager();

	DynamicMsgFactory* get_factory(string);
	int size();

	void move_begin();
	string move_get_id();
	void move_next();
private:
	pugi::xml_document* _xml;
	map<string, DynamicMsgFactory*> _factorys;
	vector<string> _vecFactoryID;
	int _indexVec;
};
