#pragma once

#include <string>
#include <google/protobuf/message.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/descriptor.pb.h>
#include <google/protobuf/dynamic_message.h>
#define SDK_API __declspec(dllexport)
using namespace std;
using namespace google::protobuf;


class DynamicMsgWriteRow{
public:
	DynamicMsgWriteRow(Message*, const Descriptor*);

	int SetInt(const string&, const int&);
	int SetFloat(const string&, const float&);
	int SetString(const string&, const string&);

	int SetIntByNumber(const int&, const int&);
	int SetFloatByNumber(const int&, const float&);
	int SetStringByNumber(const int&, const string&);

	FieldDescriptor::Type GetFieldTypeByIndex(const int&);
	string GetFieldNameByIndex(const int&);
	int Field_Count();
private:
	Message* _row;
	const Reflection* _ref_table;
	const Reflection* _ref_row;
	const Descriptor* _descrip;
};
