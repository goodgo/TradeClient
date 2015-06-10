#pragma once

#define SDK_EXPORTS
#ifdef SDK_EXPORTS
#define SDK_API __declspec(dllexport)
#else
#define SDK_API __declspec(dllimport)
#endif

#include "VApp.h"
#include "DoorBell.h"
#include "Request.h"
#include "BSCConnectionManager.h"
#include <time.h>
#include <boost/lockfree/queue.hpp>
#include "LockQueue.h"
#include "pugixml.hpp"

using namespace std;

class SDK_API ModuleServer :
	public VApp
{
public:
	ModuleServer();
	~ModuleServer();
	int Init();

	void read_handle(int);
	void write_handle();

	void pull_bell();
	void push_bell();
	int append_req(Request*&);

	DynamicMsgFactoryManager* get_DMFM();
private:
	pugi::xml_document _SDKxml;
	DoorBell _bell;
	BSCConnectionManager _conn_manager;
	LockQueue<Request*> _out_queue;
};

