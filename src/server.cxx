#include <utility>

#include "../include/server.hpp"

server::server(int port, string ip)
    : server_port(port), server_ip(std::move(ip)) {
}

server::~server() {
    for (auto sock : sock_arr) {
        close(sock);
    }
    close(server_sockfd);
}

// 启动服务器
void server::run() {
    // 创建socket
    server_sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_sockfd < 0) {
        perror("socket");
        _exit(1);
    }
    // 定义sockaddr_in
    struct sockaddr_in server_sockaddr {};
    server_sockaddr.sin_family = AF_INET;
    server_sockaddr.sin_port = htons(server_port);
    server_sockaddr.sin_addr.s_addr = inet_addr(server_ip.c_str());

    // 绑定socket
    if (bind(server_sockfd, (struct sockaddr*)&server_sockaddr, sizeof(server_sockaddr)) < 0) {
        perror("bind");
        _exit(1);
    }

    // 监听socket
    if (listen(server_sockfd, MAXWAIT) < 0) {
        perror("listen");
        _exit(1);
    }

    // 接受客户端连接
    struct sockaddr_in client_addr {};
    socklen_t len = sizeof(client_addr);

    while (true) {
        int client_sockfd = accept(server_sockfd, (struct sockaddr*)&client_addr, &len);
        if (client_sockfd < 0) {
            perror("accept");
            _exit(1);
        }
        std::cout << " Client connected with socketfd: " << client_sockfd << std::endl;
        sock_arr.push_back(client_sockfd);
        std::thread receive_thread(&server::RecvMsg, client_sockfd);
        receive_thread.detach();
    }
}

// 子线程函数
void server::RecvMsg(int sock) {
    std::array<char, 1024> buffer{};
    auto isexit = [](const std::array<char, 1024>& buf) {
        return buf.size() == 4 && buf[0] == 'e' && buf[1] == 'x' && buf[2] == 'i' && buf[3] == 't';
    };
    while (true) {
        buffer.fill(0);
        ssize_t ret = recv(sock, buffer.data(), buffer.size(), 0);
        if (ret <= 0 || isexit(buffer)) {
            perror("recv");
            break;
        }
        std::cout << "Client " << sock << ": " << buffer.data() << std::endl;
    }
}