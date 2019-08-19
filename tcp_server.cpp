/****************************************************
Simple TCP server. Port number is passed as argument.
source : http://www.linuxhowtos.org/C_C++/socket.htm
         https://www.bogotobogo.com/cplusplus/sockets_server_client.php
execute : ./tcp_server port#
example : ./tcp_server 2001

data type (https://www.gta.ufrj.br/ensino/eel878/sockets/sockaddr_inman.html):
struct sockaddr_in
{
  short   sin_family; // must be AF_INET 
  u_short sin_port;
  struct  in_addr sin_addr;
  char    sin_zero[8]; // Not used, must be zero
};

struct in_addr {
    unsigned long s_addr;  // load with inet_aton()
};

struct sockaddr
{
    __SOCKADDR_COMMON (sa_);    // Common data: address family and length. 
    char sa_data[14];           // Address data.
};
****************************************************/

#include <iostream>
#include <cstdlib> //header file for exit(), atoi()

#include <unistd.h> //header file for read(), write(), close()
#include <string.h> //header file for bzero()
//#include <sys/types.h>
//#include <errno.h>
//#include <sys/socket.h>
#include <arpa/inet.h> // header file for : inet_addr(). we can comment it if we donot use the function
#include <netinet/in.h> // header file for : socket(), bind(), listen(), accept(), AF_INET, INADDR_ANY, etc

using namespace std;

void error(const char* const msg){
  //perror(msg);
  cout << msg << endl;
  exit(1);
}


int main(int argc, char* argv[]){
  int sockfd, newsockfd, portno;
  //socklen_t clilen;
  unsigned int clilen;
  char buffer[256];
  struct sockaddr_in serv_addr, cli_addr;
  int n;

  if( argc < 2){
    cout << "error, no port is provided" << endl;
    exit(1);
  }

  //1. create socket
  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if(sockfd < 0)
    error("ERROR opening socket");

  portno = atoi(argv[1]);

  bzero((char*)&serv_addr, sizeof(serv_addr));
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
  //serv_addr.sin_addr.s_addr = INADDR_ANY;// bind to any
  serv_addr.sin_port = htons(portno);

  //2. bind
  if(bind(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr))<0)
    error("ERROR on binding");

  //3. listen
  if( listen(sockfd, 5)) //5 quee
    error("ERROR on listening");

  clilen = sizeof(cli_addr);
  
  //4. accept
  newsockfd = accept(sockfd, (struct sockaddr*)&cli_addr, &clilen);
  if( newsockfd < 0)
    error("Error on accept");

  bzero(buffer, 256);
  
  //5. read from socket
  n = read(newsockfd, buffer, 255);
  if( n < 0)
    error("ERROR on reading from socket");

  cout << "here is message : " << buffer << endl;
  //printf("here is message : %s\n", buffer);

  //6. write to socket
  n = write(newsockfd, "I got your message", 18);
  if( n < 0)
    error("ERROR on writing to socket");

  close(newsockfd);
  close(sockfd);

  return 0;
}
/****************************************************************
compile (example) : g++ tcp_server.cpp -o tcp_server
execute (example) : ./tcp_server 20001
****************************************************************/
