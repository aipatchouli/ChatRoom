#ifndef SERVER_HPP
#define SERVER_HPP

#include "global.hpp"
#include <sys/types.h>
#include <type_traits>
#include <vector>

class server {
public:
    server(int port, string ip);
    ~server();
    void run();
    static void RecvMsg(int sock);

private:
    int server_port;
    int server_sockfd{};
    string server_ip;
    static std::vector<bool> sock_arr;
};

#endif