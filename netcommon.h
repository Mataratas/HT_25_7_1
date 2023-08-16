#pragma once
#ifdef __linux__
	#include <string.h>
	#include <unistd.h>
	#include <sys/socket.h>
	#include <netinet/in.h>
	#include <netdb.h>
	#include <arpa/inet.h>
	#define PORT 55169
#elif defined(_WIN64) || defined(_WIN32)
	//#undef UNICODE
	#define WIN32_LEAN_AND_MEAN
	#include <windows.h>
	#include <winsock2.h>
	#include <ws2tcpip.h>
	#include <stdlib.h>
	#include <stdio.h>
	#define PORT "55169"
#endif // _WIN64
#include <string>
#include<iostream>

#pragma warning(disable : 5208)

#define MSG_LENGTH 1024
#define USR_NAME_LEN 32

enum MessageTypes:UINT8 {
	//To send by client----------------------------------------------------------
	eAuth = 169,        //cl
	eNewUser,			//cl
	eExistingUser,		//cl
	eGetAvailableUsers,	//cl
	eGetUserMsg,        //cl
	eGetNextMsg,        //cl
	eGetMainMenu,       //cl
	eSendToAll,			//cl
	eSendToUser,		//cl
	eSendToUserMsgReady,//cl
	eLogOut,			//cl
	//To send by server----------------------------------------------------------
	eWelcome,			//srv
	eChooseLogin,       //srv
	eChoosePassword,	//srv
	eWrongLogin,		//srv
	eWrongPassword,		//srv
	eLoginUsed,			//srv
	eLoginOK,			//srv
	eAuthOK,			//srv
	eAvailableUsers,	//srv
	eMsgDelivered,		//srv
	eErrMsgNotDelivered,//srv
	eErrMsgBadFormat,	//srv 
	eNoMsg,
	eMsgNext,
	eMsgMainMenu,
	//To send by both----------------------------------------------------------
	eNone,
	eLogin,				//cl-srv
	ePassword,			//cl-srv
	eQuit				//cl-srv
};
using MT = MessageTypes;
//-----------------------------------------------------------------------------------------
typedef struct {
	MT mtype{ eAuth };
	char body[MSG_LENGTH]{'\0'};
	char user[32]{'\0'};
}IOMSG;
//-----------------------------------------------------------------------------------------
typedef struct ClientConnection {
	SOCKET skt{ INVALID_SOCKET };
	char s_ip[15]{ '\0' };
}CLC;
//-----------------------------------------------------------------------------------------
static void clear_message(IOMSG& msg) {
	msg.mtype = eNone;
	memset(msg.body, '\0', MSG_LENGTH); 
	memset(msg.user, '\0', USR_NAME_LEN);
}
//-----------------------------------------------------------------------------------------
static void print_message(IOMSG& msg) {
	std::cout << "mtype: "<<msg.mtype << " body: " << msg.body << " user: " << msg.user << std::endl;
}





