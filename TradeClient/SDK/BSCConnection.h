#pragma once

#include "DynamicMsgFactoryManager.h"
#include "Request.h"
#include "L2.pb.h"
#include <string>
#include <exception>  
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#ifdef _WIN32
	#include <winsock2.h>
#else
	#include<sys/types.h>
	#include<sys/stat.h>
	#include<fcntl.h>
	#include <arpa/inet.h>
	#include <unistd.h>
	#include <sys/socket.h>
	#include <netinet/in.h>
#endif

using namespace std;


#define BSC_FEATURE   0xBC
#define BSC_VERSION   0x01
#define L1_TYPE_UNI   0x0001
#define L1_TYPE_MUTI  0x0002

#define L2_FLAG_ACK  0x0001
#define L2_FLAG_PUB  0x0002

struct bsc_addr{
	unsigned char moduleNumber;
	unsigned char accessNodeId;
	uint16_t connectSN;
};

struct L1{
	unsigned char FeatureCode;
	unsigned char Version;
	uint16_t Length;
	struct bsc_addr srcAddr;
	struct bsc_addr dstAddr;
	unsigned char type;
	unsigned char ttl;
	uint16_t L2_header_len;
	unsigned char body[0];
};


enum BSCConnStatus{Init = 1, Prepare, Sending};

class BSCConnection
{
public: 
	BSCConnection(DynamicMsgFactoryManager*, const string&, const string&);
	~BSCConnection();

	int send_a_req(Request*&);
	int recv_a_req(Request*&);

	int reset_connect();
	int build_connect();
	int get_socket();

private:
	DynamicMsgFactoryManager*	_DSFM;
	int _socket;
	string _ip;
	string _port;
	BSCConnStatus _status; //init, prepare, Sending;

	map<long, Request*> _wait_for_response;
	Request* _sub_resquest;
};

