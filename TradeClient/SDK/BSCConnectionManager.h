#pragma once

#include "BSCConnection.h"
#include <map>
#include "DynamicMsgFactoryManager.h"
#include "pugixml.hpp"

using namespace std;

class BSCConnectionManager
{
public:
	BSCConnectionManager();
	~BSCConnectionManager();

	BSCConnection* new_connect();
	BSCConnection* Find_in_socket(int);
	
	void append(BSCConnection*);
	
	int SendReq(Request*&);
	DynamicMsgFactoryManager* DMFM();
private:
	pugi::xml_document _xml;
	DynamicMsgFactoryManager* _DSFM;
	map<int, BSCConnection*> _conns;
};

