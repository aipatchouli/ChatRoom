#include "../include/client.h"

int main() {
    client clnt(100100, "127.0.0.1");
    clnt.run();
}
