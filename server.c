//server

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <strings.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netdb.h>
#include <inttypes.h>
#include <stdbool.h>
#include <netdb.h>

void print_sock_info(struct sockaddr_in *s_in, char *str1, char *str2){
	char* ip_addr = inet_ntoa(s_in->sin_addr);
	u_short port_addr = ntohs(s_in->sin_port);

	printf("%s", str1);
	printf("%s", str2);
	printf("IP : %s\n", ip_addr);
	printf("port : %u",port_addr);
}

int main(int argc, char *argv[]){
	//initialize viriables
	int recive_from, f_size;
	char msg[512];
	//initialize addresses of peer and mine
	struct sockaddr_in s_in, client;
	//declering udp socket with IPv4
	int udp_socket_fd = socket(AF_INET, SOCK_DGRAM, 0);
	
	//resetting bits of struct sock_in to '0'
	bzero((char*) &s_in, sizeof(s_in));
	//initializing address to IPv4
	s_in.sin_family = (short)AF_INET;
	//setting IP address
	s_in.sin_addr.s_addr = htonl(INADDR_ANY);
	//setting port to the right endian small/big
	s_in.sin_port = htons((u_short)1234);


	//binding socket to IP and SOCKET addresses
	bind(udp_socket_fd, (struct sockaddr*) &s_in, sizeof(s_in));
	
	//listening loop
	while(true) {
		
		f_size = sizeof(client);
		
		recive_from = recvfrom(udp_socket_fd, msg , sizeof(msg), 0,(struct sockaddr*) &client, &f_size);

		//displays sender info
		print_sock_info(&client, "UDP", " from:\n");
		//Display messege
		printf("\nnew messege : \n%s\n", msg);
		exit(0);
	}


	return 0;
}
	

	
