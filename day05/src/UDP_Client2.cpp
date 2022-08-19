#include <Socket.h>

int main()
{
	int sockfd;
	struct sockaddr_in server_addr, client_addr;

	char server_msg[SIZE];
	char client_msg[SIZE];

	int server_addr_len = sizeof(server_addr);

	memset(server_msg,'\0',sizeof(server_msg));
	memset(client_msg,'\0',sizeof(client_msg));

	sockfd =socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);

	if(sockfd < 0)
	{
		perror("socket() error");
		exit(EXIT_FAILURE);
	}

	cout<<"Client Socket is created"<<endl;

	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons(PORTNO);
	server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

	// int rbind = bind(sockfd,(struct sockaddr *)&server_addr, sizeof(server_addr));
	// if(rbind < 0)
	// {
	// 	perror("bind() error");
	// 	exit(EXIT_FAILURE);	
	// }

	cout<<"Client done with the bind"<<endl;

	strcpy(client_msg,":bye");
	if(sendto(sockfd, client_msg, strlen(client_msg), 0,
		(struct sockaddr*)&server_addr, server_addr_len)<0)
	{
		perror("sendto() error");
		exit(EXIT_FAILURE);
	}

	cout<<"Sent \""<<client_msg<<"\" to the server"<<endl;
	// int retRF = recvfrom(sockfd, server_msg, sizeof(server_msg), 0,
	// 	     (struct sockaddr*)&server_addr, (socklen_t*)&server_addr_len);

	// if(retRF < 0)
	// {
	// 	perror("recvfrom() error");
	// 	exit(EXIT_FAILURE);
	// }

	// cout<<"\n\nReceived from Server:\n\n\t"<<client_msg<<endl;

	close(sockfd);

	return 0;
}