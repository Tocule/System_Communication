#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define REMOTEPORT 1234
#define BUFLEN 1024

int main(int argc,char *argv[])
{
  /*
  if(argc!=2)
  {
	printf("Invalid Arguments\n");
	exit(0);
  }
  */  
  int sockfd;
  char buffer[BUFLEN];
  ///char *messageStr = "very important Good Morning message with 100s of emojis!!!";
  struct sockaddr_in   receiverAddr;
  if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0)
  {
    perror("socket failed");
    exit(EXIT_FAILURE);
  }
  //puts(argv[0]);
  short PORTNO=(short)atoi(argv[1]);
  //printf("%d\n",PORTNO);
  memset(&receiverAddr, 0, sizeof(receiverAddr));
  receiverAddr.sin_family = AF_INET;
  receiverAddr.sin_port = htons(PORTNO);
  receiverAddr.sin_addr.s_addr = INADDR_ANY;     //We dont want to bind the socket to specific address//
  sendto(sockfd, (const char *)argv[2], strlen(argv[2]), 0, (const struct sockaddr *) &receiverAddr, sizeof(receiverAddr));
  printf("%s message sent.....\n",argv[2]);
  close(sockfd);
  return 0;
}

