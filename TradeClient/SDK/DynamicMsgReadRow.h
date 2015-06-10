#pragma once

#include <string>
#include <google/protobuf/message.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/descriptor.pb.h>
#include <google/protobuf/dynamic_message.h>

using namespace std;
using namespace google::protobuf;

class DynamicMsgReadRow{
public:
	DynamicMsgReadRow(int, const Message*, const Descriptor*);
    
	int GetInt(const string&);
	float GetFloat(const string&);
	string GetString(const string&);
	
	string GetFieldNameByIndex(const int&);
	FieldDescriptor::Type GetFieldTypeByIndex(const int&);
	
	int size();
private:
	int _line_no;
	const Message* _row;
	const Reflection* _ref_row;
	const Descriptor* _descrip;
};
