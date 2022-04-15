#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>


int main(int argc,char *argv[])
{  
   char PORTNO[6];  
   int choice;
   char message[20];
    if(argc==2)
    {   
	do
	{
	     printf("***Menu***\n");
	     printf("1.Check Messages\n");
	     printf("2.Send Message\n");
	     printf("3.Exit\n");
	     choice=(int)atoi(argv[1]);
	     switch(choice)
	     {
		     case 1 : 
			      printf("Enter the port no\n");
		 	      scanf("%s",PORTNO);
			      execlp("./ur","./ur",PORTNO,NULL);  
			      break;


		     case 2:
			      printf("Enter the port no\n");
			      scanf("%s",PORTNO);
			      printf("Enter the message\n");
			      scanf("%s",message);
			      execlp("./us","./us",PORTNO,message,NULL);
			      //printf("Do you want to Exit Press 3\n");
			      //scanf("%d",&choice);
			      break;

		     case 3 : printf("You have Exited\n");
			      break;
	    }

 	}while(choice!=3);
    
    }
    else
    {
	printf("Invalid numer of Arguments\n");
        printf("You need two arguments ./up [option]\n");
	printf("Menu for your reference\n");
	printf("***Menu***\n");
        printf("1.Check Messages\n");
        printf("2.Send Message\n");
        printf("3.Exit\n");
     }
     return 0;
}	

