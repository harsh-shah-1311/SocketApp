#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>

#include"main.h"

int i;

void *thread1(void *p)
{
	char s1[20],str[100];
	int nsfd;
	nsfd = *(int *)p;
	if(recv(nsfd,s1,sizeof(s1),0)>0)
	{
        	printf("%s from %d\n",s1,nsfd);
	}
        snprintf(str,100,"hello %s",s1);
        if(send(nsfd,str,sizeof(str),0))
	{
		printf("send to %d\n",nsfd);
	}
}

int main(int argc, char **argv)
{
	struct sockaddr_in v,v1;
	int sfd,size,temp,nsfd;
	char str[100],s1[20];
	pthread_t t;

/*********** CREATE THE SOCKET *************/

	sfd = socket(AF_INET, SOCK_STREAM, 0);
	if(sfd<0)
	{
		printf("socket");
		return 0;
	}

/********* bind the socket with the ip *************/

	v.sin_family = AF_INET;
	v.sin_port = htons(atoi(argv[1]));
	v.sin_addr.s_addr = inet_addr("0.0.0.0");

	if(bind(sfd,(struct sockaddr *)&v, sizeof(struct sockaddr)))
	{
		printf("bind\n");
		return 0;
	}

/******* decide the size of the queue of the client request *************/

	if(listen(sfd,1))
	{
		printf("listen\n");
		return 0;
	}

/************** Waiting for a request and if request generated then accept the request **************/

	v1.sin_family = AF_INET;
	v1.sin_port = htons(atoi(argv[1]));
	v1.sin_addr.s_addr = inet_addr("0.0.0.0");
	size = sizeof(struct sockaddr);

	while(1)
	{
		if(i==5)
		{
			printf("memory not avaiable\n");
			goto loop;
		}

		nsfd = accept(sfd,(struct sockaddr *)&v1, &size);
		if(nsfd < 0)
		{
			printf("accept\n");
			return 0;
		}
		if(nsfd>=0)
		{
			//temp=malloc(1);
			temp=nsfd;
			pthread_create(&t,NULL,thread1,(void *)&temp);
			i++;
			printf("connection establish\n");	
		}
	}
loop:
	while(1)
	{
		sleep(2);
	}
}
