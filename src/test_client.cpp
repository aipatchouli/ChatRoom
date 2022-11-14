#include "../include/client.hpp"

int main() {
    client client1(10086, "127.0.0.1");
    client1.run();    
}