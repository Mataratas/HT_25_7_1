#pragma once
#include "../netcommon.h"
#include "CDBAccess.h"


#if defined(_WIN64) || defined(_WIN32)
#pragma comment (lib, "Ws2_32.lib")
#endif

#include "../utils.h"

//==================================================================================================
class CTCPServer{
public:
	CTCPServer();
	~CTCPServer();
	auto process_clients()-> bool;
	auto str_wsa_error(size_t)-> std::string const;
	auto init_ok()->bool const { return !_err_cnt;};

private:
	
#if defined(_WIN64) || defined(_WIN32)
	SOCKET _socket{ INVALID_SOCKET };
	WSAData _wData;
#elif defined(__linux__)
	int _socket{-1};	
#endif
	std::string _name{ "localhost" };
	std::string _user,_pwd_hash;
	size_t _err_cnt{};
	uint64_t _usr_db_id{};
	std::shared_ptr<DBCTX>_hDB;
	std::unordered_map<size_t, std::shared_ptr<CUser>> _um_users;
	std::map<std::string, std::shared_ptr<CMessage>> _msg_pool;
#if defined(_WIN64) || defined(_WIN32)
	auto _send_to_client(SOCKET,IOMSG&)->bool;
	auto _process_client_msg(SOCKET,IOMSG&, bool&) -> bool;
#elif defined(__linux__)
	auto _send_to_client(int,IOMSG&)->bool;
	auto _process_client_msg(int,IOMSG&, bool&) -> bool;
#endif
	auto _login_used(const std::string&) -> bool;
	auto _is_valid_user_pwd(const std::string& pwd) -> bool;
	auto _db_init() -> bool;
	auto _hash_func(const std::string&) -> size_t;

};

using TSPS = CTCPServer;


