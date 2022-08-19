#include <Socket.h>

int main()
{
	int sockfd;

	struct sockaddr_in server_addr, client_addr;

	char server_msg[SIZE];
	char client_msg[SIZE];

	int client_addr_len = sizeof(client_addr);

	memset(server_msg,'\0',sizeof(server_msg));
	memset(client_msg,'\0',sizeof(client_msg));

	sockfd =socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);

	if(sockfd < 0)
	{
		perror("socket() error");
		exit(EXIT_FAILURE);
	}

	cout<<"Server Socket is created"<<endl;

	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons(PORTNO);
	server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");


	int rbind = bind(sockfd,(struct sockaddr *)&server_addr, sizeof(server_addr))
	if(rbind < 0)
	{
		perror("bind() error");
		exit(EXIT_FAILURE);	
	}

	cout<<"Server done with the bind"<<endl;

	cout<<"\nServer is now open for clients to send/recv msgs"<<endl;

	

	return 0;
}