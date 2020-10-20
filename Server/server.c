#include <stdio.h>

#include <stdlib.h>

#include <string.h>

#include <unistd.h>

#include <arpa/inet.h>

#include <sys/types.h>

#include <sys/socket.h>

#include <wiringPi.h> 

#define  BUFF_SIZE   1024

#define A 0
#define B 1
#define C 2
#define D 3
#define E 4
#define F 5
#define G 6
#define DP 7
#define LED1 21
#define LED2 22

int seg[10][7] = 
{{0,0,0,0,0,0,1},
   {1,0,0,1,1,1,1},
   {0,0,1,0,0,1,0},
   {0,0,0,0,1,1,0},
   {1,0,0,1,1,0,0},
   {0,1,0,0,1,0,0},
   {0,1,0,0,0,0,0},
   {0,0,0,1,1,0,1},
   {0,0,0,0,0,0,0},
   {0,0,0,0,1,0,0}
   };


int   main( void)

{

	if (wiringPiSetup() ==-1)
		return 1;
   
  pinMode(A,1);
  pinMode(B,1);
  pinMode(C,1);
  pinMode(D,1);
  pinMode(E,1);
  pinMode(F,1);
  pinMode(G,1);
  pinMode(DP,1);
  pinMode(LED1,1);
  pinMode(LED2,1);
   char music_buff[100];


   int   server_socket;

   int   client_socket;

   int   client_addr_size;

 

   struct sockaddr_in   server_addr;

   struct sockaddr_in   client_addr;

 

   char   buff_rcv[BUFF_SIZE+5];

   char   buff_snd[BUFF_SIZE+5];

 

 

 

   server_socket  = socket( PF_INET, SOCK_STREAM, 0);

   if( -1 == server_socket)

   {

      printf( "server socket 생성 실패\n");

      exit( 1);

   }

 

   memset( &server_addr, 0, sizeof( server_addr));

   server_addr.sin_family     = AF_INET;

   server_addr.sin_port       = htons( 4000);

   server_addr.sin_addr.s_addr= htonl( INADDR_ANY);

 

   if( -1 == bind( server_socket, (struct sockaddr*)&server_addr, sizeof( server_addr) ) )

   {

      printf( "bind() 실행 에러\n");

      exit( 1);

   }

 

   if( -1 == listen(server_socket, 5))

   {

      printf( "listen() 실행 실패\n");

      exit( 1);

   }


int b;
while(1)
{
printf("재생모드를 선택해주세요 자동반복모드: 1 / 선택듣기모드 : 2 \n\n\n");
scanf("%d", &b);


if(b==1)
{
   while( 1)

   {

      client_addr_size  = sizeof( client_addr);

      client_socket     = accept( server_socket, (struct sockaddr*)&client_addr, &client_addr_size);

 

      if ( -1 == client_socket)

      {

         printf( "클라이언트 연결 수락 실패\n");

         exit( 1);

      }

 

      read ( client_socket, buff_rcv, BUFF_SIZE);

	int ret = atoi(buff_rcv);
	
	if(ret>=0&&ret<10)
        {	   
	    printf( "\n\n\n\n %d 번 노래를 재생합니다!!!\n\n\n\n", ret);
	    digitalWrite(A,seg[ret][0]);
	    digitalWrite(B,seg[ret][1]);
	    digitalWrite(C,seg[ret][2]);
	    digitalWrite(D,seg[ret][3]);
	    digitalWrite(E,seg[ret][4]);
	    digitalWrite(F,seg[ret][5]);
	    digitalWrite(G,seg[ret][6]);	    
	    
	    //digitalWrite(LED1,1);
	    //digitalWrite(LED2,0);
	    sprintf(music_buff,"mpg123 %d.mp3",ret);
	    system(music_buff);
	    while(1)
	    {
	    if(ret==10)
	       ret = 0;
	    sprintf(music_buff,"mpg123 %d.mp3",ret+1);
	    system(music_buff);
	    }
	}
	    digitalWrite(A,1);
	    digitalWrite(B,1);
	    digitalWrite(C,1);
	    digitalWrite(D,1);
	    digitalWrite(E,1);
	    digitalWrite(F,1);
	    digitalWrite(G,1);
	    digitalWrite(DP,0);

     sprintf( buff_snd, "%s 번 노래 재생을 마쳤습니다.",buff_rcv);

      write( client_socket, buff_snd, strlen( buff_snd)+1);          // +1: NULL까지 포함해서 전송

      close( client_socket);
}
}

else if(b==2)
{
   while( 1)

   {

      client_addr_size  = sizeof( client_addr);

      client_socket     = accept( server_socket, (struct sockaddr*)&client_addr, &client_addr_size);

 

      if ( -1 == client_socket)

      {

         printf( "클라이언트 연결 수락 실패\n");

         exit( 1);

      }

 

      read ( client_socket, buff_rcv, BUFF_SIZE);

	int ret = atoi(buff_rcv);
	
	if(ret>=0&&ret<10)
        {	   
	    printf( "\n\n\n\n  %d 번 노래를 재생합니다!!!\n\n\n\n", ret);
	    digitalWrite(A,seg[ret][0]);
	    digitalWrite(B,seg[ret][1]);
	    digitalWrite(C,seg[ret][2]);
	    digitalWrite(D,seg[ret][3]);
	    digitalWrite(E,seg[ret][4]);
	    digitalWrite(F,seg[ret][5]);
	    digitalWrite(G,seg[ret][6]);	    
	    
	    digitalWrite(LED1,1);
	    digitalWrite(LED2,0);
	    sprintf(music_buff,"mpg123 %d.mp3",ret);
	    system(music_buff);
        
	}
	    digitalWrite(A,1);
	    digitalWrite(B,1);
	    digitalWrite(C,1);
	    digitalWrite(D,1);
	    digitalWrite(E,1);
	    digitalWrite(F,1);
	    digitalWrite(G,1);
	    digitalWrite(DP,0);
	    digitalWrite(LED1,0);
	    digitalWrite(LED2,1);
     sprintf( buff_snd, "%s 번 노래 재생을 마쳤습니다.",buff_rcv);

      write( client_socket, buff_snd, strlen( buff_snd)+1);          // +1: NULL까지 포함해서 전송

      close( client_socket);
}
}
else
   printf("잘못 입력하셨습니다\n");
}

}
