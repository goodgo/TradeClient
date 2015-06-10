#pragma once

#include "DynamicMsgDataSpace.h"
#include <string>
#include <iostream>
#include <google/protobuf/compiler/importer.h>
#include <google/protobuf/compiler/parser.h>
#include <google/protobuf/io/tokenizer.h>
#include <google/protobuf/io/zero_copy_stream.h>
#include <google/protobuf/io/zero_copy_stream_impl.h>
#include <google/protobuf/io/coded_stream.h>
#include <fstream>

using namespace std;
using namespace google::protobuf;
using namespace google::protobuf::compiler;
using namespace google::protobuf::io;

class SDK_API DynamicMsgFactory
{
public:
	DynamicMsgFactory(const string&);

	~DynamicMsgFactory();

	FileDescriptorProto* get_file();

	string message_name();
private:
	string _fileName;
	FileDescriptorProto* _file_proto;
	Parser* _parser;
	ZeroCopyInputStream* _raw_input;
	Tokenizer* _input;
};

