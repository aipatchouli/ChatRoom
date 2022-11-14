#ifndef _GLOBAL_HPP
#define _GLOBAL_HPP

#include <arpa/inet.h>
#include <array>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <fcntl.h>
#include <iostream>
#include <netinet/in.h>
#include <sys/shm.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <thread>
#include <unistd.h>
#include <utility>
#include <vector>
using string = std::string;
enum {
MAXWAIT = 20
};
#endif // _GLOBAL_HPP