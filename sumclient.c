#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdlib.h>
int main(int argc, char*argv[])
{
	int sockfd,newsockfd,length;
	int i;
	long int a,b,sum=0;
	struct sockaddr_in server;
	struct sockaddr_in client;

	printf("\nEnter the port number");
	scanf("%d",&i);

	
	if((sockfd=socket(AF_INET,SOCK_STREAM,0))==-1)
	{
		printf("\nSocket error\n");
		exit(0);
	}
	server.sin_family=AF_INET;
	server.sin_port=htons(i);
	server.sin_addr.s_addr=INADDR_ANY;

	if((connect(sockfd,(struct sockaddr*)&server, sizeof(struct sockaddr))<0))
	{
	printf("\nConnect error");
	exit(0);
	}
	printf("\nEnter the numbers: \n");
	scanf("%ld%ld", &a,&b);

	long int tmp1 = htonl(a);
	send(sockfd, &tmp1, sizeof(tmp1),0);
	long int tmp2 = htonl(b);
	send(sockfd, &tmp2, sizeof(tmp2),0);

	long int tmp3;
	recv(sockfd, &tmp3, sizeof(tmp3),0);
	sum=ntohl(tmp3);
	printf("Sum received from server: %ld\n",sum);
    
}

