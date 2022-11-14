#include "../include/server.hpp"

int main() {
    server server1(10086, "127.0.0.1");
    server1.run();
}