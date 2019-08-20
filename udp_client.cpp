#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring> // library for bcopy(), bzero()
#include <string>
#include <unistd.h>
#include <netinet/in.h>
#include <netdb.h>

using namespace std;

void error( char const * const & msg){
  perror(msg);
  exit(0);
}

int main(int argc, char* argv[]){
  int sock, portno, n;
  socklen_t serv_len;
  struct hostent* server;
  struct sockaddr_in serv_addr;
  string data_to_send;
  char buffer[256];

  if( argc < 3)
    error((string("should be : ") + string(argv[0]) + string(" hostname port")).c_str());

  //1. open socket
  sock = socket( AF_INET, SOCK_DGRAM, 0);
  if( sock < 0 )
    error("ERROR ... opening socket");

  serv_len = sizeof(serv_addr);
  bzero((char *)&serv_addr, serv_len);

  server = gethostbyname(argv[1]);
  if( server == NULL)
    error("ERROR ... no such host");

  portno = atoi(argv[2]);

  serv_addr.sin_family = AF_INET;

  bcopy( (char*)server->h_addr, 
        (char*)&serv_addr.sin_addr.s_addr, 
        server->h_length);

  serv_addr.sin_port = htons(portno);

  cout << "Type data to be sent : ";

  getline(cin, data_to_send);

  //2. send package
  n = sendto( sock,
              data_to_send.c_str(),
              data_to_send.length(),
              0,
              (struct sockaddr*)&serv_addr,
              serv_len);

  if( n < 0)
    error("ERROR ... sending");

  bzero(buffer, 256);

  //3. receive package
  n = recvfrom( sock,
                buffer,
                255,
                2,//0,
                (sockaddr*)&serv_addr,
                &serv_len);
  if( n < 0)
    error("ERROR ... receiving");

  //write( 1, "Got an ack: ", 12);
  //write( 1, buffer, n);
  cout << "Got an ack : " << buffer << endl;

  //4. close socket
  close(sock);

  return 0;
}

