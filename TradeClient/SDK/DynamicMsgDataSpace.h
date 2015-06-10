#pragma once

#include <string>
#include <vector>
#include <google/protobuf/message.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/descriptor.pb.h>
#include <google/protobuf/dynamic_message.h>
#include "DynamicMsgWriteRow.h"
#include "DynamicMsgReadRow.h"

#define SDK_EXPORTS
#ifdef SDK_EXPORTS
#define SDK_API __declspec(dllexport)
#else
#define SDK_API __declspec(dllimport)
#endif

using namespace std;
using namespace google::protobuf;

class DynamicMsgDataSpace
{
public:
	void Init(FileDescriptorProto*,const string&,const string&);
	~DynamicMsgDataSpace();

	DynamicMsgWriteRow* add_row();
	DynamicMsgReadRow* first();		
	DynamicMsgReadRow* next();
	int size();
	
	bool Serialize(string&);
	bool Parse(const string&);
	void DataReset();
private:
	DynamicMsgReadRow* _get_Read_row();

	vector<DynamicMsgWriteRow*> _vecDSWRow;
	vector<DynamicMsgReadRow*> _vecDSRRow;
	int _current_line_no;
	
private:
	Message* _table;
	const Message* _message;
	const Reflection* _reflection;
	const FieldDescriptor* _field;
	const Descriptor* _descriptor;
	const Descriptor* _descriptor_row;
	DescriptorPool* _pool;
	const FileDescriptor* _file_descriptor;
	DynamicMessageFactory* _factory;
};

