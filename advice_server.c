#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

int main(int argc, char *argv[])
{
  char *advice[] = {
    "Take smaller bites\r\n",
    "You might want to rethink that haircut\r\n"
  };
  int listener_d = socket(PF_INET, SOCK_STREAM, 0);  // 创建套接字

  // 创建一个表示“互联网30000端口”的套接字
  struct sockaddr_in name;
  name.sin_family = PF_INET;
  name.sin_port = (in_port_t)htons(30000);
  name.sin_addr.s_addr = htonl(INADDR_ANY);
  bind(listener_d, (struct sockaddr *) &name, sizeof(name));

  // 监听
  listen(listener_d, 10);
  puts("Waiting for connection");

  while (1) {
  // 接受连接
  struct sockaddr_storage client_addr;
  unsigned int address_size = sizeof(client_addr);
  int connect_d = accept(listener_d, (struct sockaddr *)&client_addr, &address_size);

  char *msg = advice[rand() % 5];
  // 用send()函数向套接字输出数据
  send(connect_d, msg, strlen(msg), 0);

  close(connect_d);
  }

  return 0;
}
