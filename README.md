#### Tiny ChatRoom
使用 C/S 架构
##### 1. 服务器端
1. 创建socket
2. 绑定端口 bind()
3. 监听 listen()
4. 接受连接 accept()
5. 数据交换 recv() send()
6. 关闭连接 close()
##### 2. 客户端
1. 创建socket
2. 连接服务器 connect()
3. 数据交换 recv() send()
4. 关闭连接 close()

![alt 流程](https://doc.shiyanlou.com/courses/3573/1116908/87c29545a64eed3b2b2338ef5f901fc4-0)