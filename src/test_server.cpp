#include "../include/server.h"

int main() {
    server serv(100100, "127.0.0.1");
    serv.run();
}
