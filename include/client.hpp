#ifndef CLIENT_HPP
#define CLIENT_HPP

#include "global.hpp"

class client {
public:
    client(int port, string ip);
    ~client();
    void run();                    // 启动客户端服务
    static void SendMsg(int sock); // 发送线程
    static void RecvMsg(int sock); // 接收线程

private:
    int server_port;  // 服务器端口
    string server_ip; // 服务器ip
    int sock{};       // 与服务器建立连接的套接字描述符
};

#endif