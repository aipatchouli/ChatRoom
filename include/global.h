#ifndef _GLOBAL_H
#define _GLOBAL_H

#include <arpa/inet.h>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <fcntl.h>
#include <fstream>
#include <hiredis/hiredis.h>
#include <iostream>
#include <mysql/mysql.h>
#include <netinet/in.h>
#include <pthread.h>
#include <set>
#include <sys/shm.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <thread>
#include <unistd.h>
#include <unordered_map>
#include <vector>
//以下新增
#include<boost/asio.hpp>
#include<boost/bind.hpp>
#include<cerrno>
#include<sys/epoll.h>
using namespace std;

#endif
