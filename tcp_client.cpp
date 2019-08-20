/***************************************************************************
struct  hostent
{
  char    *h_name;        // official name of host 
  char    **h_aliases;    // alias list 
  int     h_addrtype;     // host address type 
  int     h_length;       // length of address 
  char    **h_addr_list;  // list of addresses from name server 
  #define h_addr  h_addr_list[0]  // address, for backward compatiblity 
};
***************************************************************************/


#include <iostream>
#include <cstdlib>
#include <cstring>
#include <unistd.h>
//#include <string.h>
#include <netinet/in.h>
#include <netdb.h> // header file for gethostbyname

using namespace std;

void error(char const* const msg){
  cout << msg <<endl;
  exit(0);
}


int main(int argc, char* argv[]){
  int sockfd, portno, n;
  struct sockaddr_in serv_addr;
  struct hostent* server;
  char buffer[256];
  string berita;

  if( argc < 3){
    cout << "should be " << argv[0] << " hostname port" << endl;
    exit(0);
  }

  //1. create socket
  sockfd = socket(AF_INET,SOCK_STREAM,0);
  if( sockfd < 0)
    error("ERROR opening socket");

  portno = atoi(argv[2]);

  server = gethostbyname(argv[1]);
  if( server == NULL)
    error("ERROR no such host");

  bzero((char*)&serv_addr, sizeof(serv_addr));
  serv_addr.sin_family = AF_INET;
  bcopy((char*)server->h_addr, 
        (char*)&serv_addr.sin_addr.s_addr,
        server->h_length);
  
  //serv_addr.sin_addr.s_addr = server->h_addr;//error

  serv_addr.sin_port = htons(portno);
  
  //2. connecting to socket
  if( connect( sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0)
    error("ERROR connecting");

  //bzero((char*)buffer,256);
  cout << "Please enter message : ";
  getline(cin, berita); 
  strcpy( buffer, berita.c_str());

  //3. send message
  n = write( sockfd, buffer, strlen(buffer));
  if( n < 0)
    error("ERROR writing socket");

  bzero(buffer, 256);

  //4. receive message
  n = read( sockfd, buffer, 255);
  if( n < 0)
    error("ERROR reading from socket");

  cout << buffer << endl;

  //5. close socket
  close(sockfd);   

  return 0;
}
/****************************************************************
compile (example) : g++ tcp_client.cpp -o tcp_client
execute (example) : ./tcp_client localhost 20001
****************************************************************/
