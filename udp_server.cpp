#include <iostream>
#include <cstdio> // library containing perror() 
#include <cstdlib> // library containing exit(), atoi()
#include <cstring> // library containing bzero()
#include <unistd.h> // header file for : close(), write()
#include <netinet/in.h> //header for : struct sockaddr_in, SOCK_DGRAM, etc

using namespace std;

void error(char const * const msg){
  perror(msg);
  exit(0);
}

int main(int argc, char* argv[]){
  int sock, length, n;
  //unsigned int from_len;
  socklen_t from_len;
  struct sockaddr_in server, from;
  char buffer[1024];

  if( argc < 2)
    error("ERROR ... no port is provided.");

  //1. open socket
  sock = socket(AF_INET, SOCK_DGRAM, 0);
  if( sock < 0)
    error("ERROR ... opening socket.");

  length = sizeof(server);
  bzero((char*)&server, length);

  server.sin_family = AF_INET;
  server.sin_addr.s_addr = INADDR_ANY;
  server.sin_port = htons(atoi(argv[1]));

  //2. binding
  if(bind( sock, (sockaddr*)&server, length) < 0)
    error("ERROR ... binding");

  while(1){

    bzero((char*)buffer, 1024);

    //3. receive package
    n = recvfrom( sock,
                  buffer, //buffer to store data
                  1024, // maximum size of data
                  0, // ??? flag
                  (struct sockaddr*)&from, // source address
                  &from_len); // length of the address
    if( n < 0)
      error("ERROR ... receiving");

    //write(1, "Receiving a datagram : ", 21);
    //write(1, buffer, n);
    cout << "Receiving a datagram : " << buffer << endl;

    //4. send package
    n = sendto( sock,
                "Got your message\n", // data to be sent
                17, // length of the data
                0, // ??? flag
                (struct sockaddr*)&from, // destination address
                from_len); // length of the address
    if( n < 0 )
      error("ERROR ... sending");  

  }

  //5. close socket
  close(sock);

  return 0;
}
