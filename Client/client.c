#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h> 
#include <sys/types.h> 
#include <sys/socket.h> 

#define BUFF_SIZE 1024 

int main( int argc, char **argv)
 {
    

int a = 0;
while(1)
{
  int client_socket; 
  struct sockaddr_in server_addr;

   char buff[BUFF_SIZE+5];
    client_socket = socket( PF_INET, SOCK_STREAM, 0); 
    if( -1 == client_socket)
     { printf( "socket 생성 실패\n"); 
     exit( 1); 
     } 
     memset( &server_addr, 0, sizeof( server_addr));
      server_addr.sin_family = AF_INET; 
      server_addr.sin_port = htons( 4000); 
      server_addr.sin_addr.s_addr= inet_addr( "127.0.0.1");
      
       if( -1 == connect( client_socket, (struct sockaddr*)&server_addr, sizeof( server_addr) ) )
        { 
        printf( "접속 실패\n"); 
        exit( 1); 
        }
  scanf("%d",&a);
  if(a==0)
  {
  argv[1] = "0";
  write( client_socket, argv[1], strlen( argv[1])+1); // +1: NULL까지 포함해서 전송 
  read ( client_socket, buff, BUFF_SIZE);
  printf( "%s\n", buff); 
  close(client_socket);
  argv[1] = NULL;
  }

  else if(a==1)
  {
  argv[1] = "1";
  write( client_socket, argv[1], strlen( argv[1])+1); // +1: NULL까지 포함해서 전송 
  read ( client_socket, buff, BUFF_SIZE);
  printf( "%s\n", buff);
  close(client_socket);
  argv[1] = NULL;
  }
  
  else if(a==2)
  {
  argv[1] = "2";
  write( client_socket, argv[1], strlen( argv[1])+1); // +1: NULL까지 포함해서 전송 
  read ( client_socket, buff, BUFF_SIZE);
  printf( "%s\n", buff); 
  close(client_socket);
  argv[1] = NULL;
  }
  
  else if(a==3)
  {
  argv[1] = "3";
  write( client_socket, argv[1], strlen( argv[1])+1); // +1: NULL까지 포함해서 전송 
  read ( client_socket, buff, BUFF_SIZE);
  printf( "%s\n", buff); 
  close(client_socket);
  argv[1] = NULL;
  }
  
  else if(a==4)
  {
  argv[1] = "4";
  write( client_socket, argv[1], strlen( argv[1])+1); // +1: NULL까지 포함해서 전송 
  read ( client_socket, buff, BUFF_SIZE);
  printf( "%s\n", buff); 
  close(client_socket);
  argv[1] = NULL;
  }
  
  else if(a==5)
  {
  argv[1] = "5";
  write( client_socket, argv[1], strlen( argv[1])+1); // +1: NULL까지 포함해서 전송 
  read ( client_socket, buff, BUFF_SIZE);
  printf( "%s\n", buff); 
  close(client_socket);
  argv[1] = NULL;
  }
  
  else if(a==6)
  {
  argv[1] = "6";
  write( client_socket, argv[1], strlen( argv[1])+1); // +1: NULL까지 포함해서 전송 
  read ( client_socket, buff, BUFF_SIZE);
  printf( "%s\n", buff); 
  close(client_socket);
  argv[1] = NULL;
  }
  
  else if(a==7)
  {
  argv[1] = "7";
  write( client_socket, argv[1], strlen( argv[1])+1); // +1: NULL까지 포함해서 전송 
  read ( client_socket, buff, BUFF_SIZE);
  printf( "%s\n", buff); 
  close(client_socket);
  argv[1] = NULL;
  }
  
  else if(a==8)
  {
  argv[1] = "8";
  write( client_socket, argv[1], strlen( argv[1])+1); // +1: NULL까지 포함해서 전송 
  read ( client_socket, buff, BUFF_SIZE);
  printf( "%s\n", buff); 
  close(client_socket);
  argv[1] = NULL;
  }
  
  else if(a==9)
  {
  argv[1] = "9";
  write( client_socket, argv[1], strlen( argv[1])+1); // +1: NULL까지 포함해서 전송 
  read ( client_socket, buff, BUFF_SIZE);
  printf( "%s\n", buff); 
  close(client_socket);
  argv[1] = NULL;
  }


      }     

          return 0;
          
}
