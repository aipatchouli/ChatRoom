#### Tiny ChatRoom
使用 C/S 架构    
+ 服务端/客户端均为多线程
+ 客户端先联接到服务器，然后创建 Send 和 Receive 线程

##### 1. 服务器端
1. 创建 `socket`
```
int socket(int domain, int type, int protocol);
```
2. 绑定端口 `bind()`
```
int bind(int sockfd, const struct sockaddr *addr, socklen_t addrlen);
```
3. 监听 `listen()`
```
int listen(int sockfd, int backlog);
```
4. 接受连接 `accept()`
```
int accept(int sockfd, struct sockaddr *addr, socklen_t *addrlen);
```
5. 数据交换 `recv()` `send()`
```
ssize_t recv(int sockfd, void *buf, size_t len, int flags);
ssize_t send(int sockfd, const void *buf, size_t len, int flags);
```
6. 关闭连接 `close()`
```
int close(int sockfd);
```
##### 2. 客户端
1. 创建 `socket`
2. 连接服务器 `connect()`
```
int connect(int sockfd, const struct sockaddr *addr, socklen_t addrlen);
```
3. 数据交换 `recv()` `send()`
4. 关闭连接 `close()`
