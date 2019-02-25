#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>

#include"main.h"

int main(int argc, char **argv)
{
	int sfd;
	char s1[20],str[100];
	struct sockaddr_in v;
	
/********** CREATE THE SOCKET **************/

	sfd = socket(AF_INET, SOCK_STREAM, 0);
	if(sfd<0)
	{
		printf("socket\n");
		return 0;
	}

/************* Send the request to the server for connect **********/

	v.sin_family = AF_INET;
	v.sin_port = htons(atoi(argv[1]));
	v.sin_addr.s_addr = inet_addr(argv[2]);

	if(connect(sfd,(struct sockaddr *)&v, sizeof(v)))
	{
		printf("connect\n");
		return 0;
	}

	printf("connected successfully\n");

	printf("enter the message :");
	gets(s1);

	if(send(sfd, s1, strlen(s1)+1,0))
	{
		printf("send successfully\n");
	}
	sleep(1);
	while(1)
	{
		if(recv(sfd,str,sizeof(str),MSG_DONTWAIT)>0)
		{
			printf("%s\n",str);
			break;
		}
	}
	while(1);
}
