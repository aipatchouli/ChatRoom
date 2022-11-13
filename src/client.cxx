#include "../include/client.hpp"

client::client(int port, string ip)
    : server_port(port), server_ip(std::move(ip)){};

client::~client() {
    close(sock);
}

void client::run() {
    // Create socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket");
        _exit(1);
    }

    // Connect to server
    struct sockaddr_in server_addr {};
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(server_port);
    server_addr.sin_addr.s_addr = inet_addr(server_ip.c_str());

    if (connect(sock, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("connect");
        _exit(1);
    }
    std::cout << "Connected to server" << std::endl;

    // Create thread to receive and send messages
    std::thread receive_thread(&client::RecvMsg, sock);
    std::thread send_thread(&client::SendMsg, sock);
    send_thread.join();
    std::cout << "Send thread joined" << std::endl;
    receive_thread.join();
    std::cout << "Receive thread joined" << std::endl;
}

void client::SendMsg(int sock) {
    std::array<char, 1024> sendbuf{};
    while (true) {
        sendbuf.fill(0);
        std::cin.getline(sendbuf.data(), sendbuf.size());
        ssize_t ret = send(sock, sendbuf.data(), sendbuf.size(), 0);
        auto isexit = [](const std::array<char, 1024>& buf) {
            return buf.size() == 4 && buf[0] == 'e' && buf[1] == 'x' && buf[2] == 'i' && buf[3] == 't';
        };
        if (ret <= 0 || isexit(sendbuf)) {
            perror("send");
            break;
        }
    }
}

void client::RecvMsg(int sock) {
    std::array<char, 1024> buffer{};
    while (true) {
        buffer.fill(0);
        ssize_t ret = recv(sock, buffer.data(), buffer.size(), 0);
        if (ret <= 0) {
            perror("recv");
            break;
        }
        std::cout << "收到服务器发来的信息：" << buffer.data() << std::endl;
    }
}