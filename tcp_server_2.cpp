#include <iostream>
#include <cstdlib>
#include <cstring>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>

using namespace std;

void do_stuff(int sockfd);
void error(char const * const msg){
  cout << msg << endl;
  exit(1);
}

int main(int argc, char* argv[]){
  struct sockaddr_in serv_addr, cli_addr;
  //unsigned int cli_len;
  socklen_t cli_len;
  
  int sockfd, new_sockfd, portno, pid;

  if( argc < 2)
    error("ERROR no port is provided");

  sockfd = socket( AF_INET, SOCK_STREAM, 0);
  if( sockfd < 0)
    error("ERROR creating socket");

  portno = atoi(argv[1]);

  bzero((char*)&serv_addr,sizeof(serv_addr));

  serv_addr.sin_family = AF_INET;
  serv_addr.sin_addr.s_addr = INADDR_ANY;
  serv_addr.sin_port = htons(portno);

  if(bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    error("ERROR on binding");

  if( listen(sockfd,5) < 0)
    error("ERROR on listening");

  cli_len = sizeof(cli_addr);

  while(1){
    new_sockfd = accept( sockfd, (struct sockaddr*)&cli_addr, &cli_len);
    if( new_sockfd < 0)
      error("ERROR on accept");

    pid = fork();
    if(pid == 0){
      close(sockfd);
      do_stuff(new_sockfd);
      exit(0);
    }else{
      close(new_sockfd);

      if( pid < 0)
         error("ERROR on fork");     
    }
  }

  close(sockfd);
  return 0;
}

void do_stuff(int sockfd){
  char buffer[256];
  int n;

  n = read(sockfd, buffer, 255);
  if( n < 0)
    error("ERROR on reading from socket");

  cout << "Here is the message : " << buffer << endl;

  n = write(sockfd, "I got your message", 18);
  if( n < 0 )
    error("ERROR on writing to socket");

}
