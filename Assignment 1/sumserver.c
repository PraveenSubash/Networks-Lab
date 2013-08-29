#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdlib.h>

int main()
{
	int sockfd, newsockfd, clilen;
	int i,size,number;
	long int a,b,sum=0;
	int buf[100];
	struct sockaddr_in server;
	struct sockaddr_in client;
	printf("\nEnter the port number: ");
	scanf("%d",&i);
	
	sockfd = socket(AF_INET, SOCK_STREAM, 0);

	if(sockfd<0)
		printf("\nSocket creation error");
	else
		printf("\nSocket created successfully");

	server.sin_family=AF_INET;
	server.sin_port=htons(i);
	server.sin_addr.s_addr=INADDR_ANY;
	
	
	if(bind(sockfd, (struct sockaddr *)&server,sizeof(struct sockaddr))<0)
		printf("\n Binding error");
	else
		printf("\nSocket is binded at port:%d",i);
	
	if (listen(sockfd,5)<0)
		printf("\nListening error");
	else
		printf("\nserver is in listening mode");

	size=sizeof(struct sockaddr);

	if((newsockfd=accept(sockfd,(struct sockaddr*)&client,&size))<0)
		printf("\naccept error");
	else
		printf("\nconnection established\n");
	long int tmp1;
	recv(newsockfd, &tmp1, sizeof(tmp1),0);
	a = ntohl(tmp1);
	printf("1st number from client: %ld\n",a);
	long int tmp2;
	recv(newsockfd, &tmp2, sizeof(tmp2),0);
	b = ntohl(tmp2);
	printf("2nd number from client: %ld\n",b);
	sum=a+b;
	printf("Sum is: %ld\n",sum);

	long int tmp3 = htonl(sum);
	send(newsockfd, &tmp3, sizeof(tmp3),0);
	

	if((number=recv(newsockfd,buf,25,0))<0)
	{
		perror("\n Receive error");
		exit(0);
	}
	
	
 	
	
}
