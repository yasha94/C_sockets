//client 

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
#include <string.h>
#define words "this is working"


int main(int argc, char *argv[]){
	//initializing variables
	int send_to, f_size;
	char msg[512];
	//initializing my address and address of peer
	struct sockaddr_in to;

	//declering udp socket with IPv4
	int udp_socket_fd = socket(AF_INET, SOCK_DGRAM, 0);

	f_size = sizeof(to);

	//resetting bits of struct 'to' to '0'
	bzero((char*) &to, sizeof(to));
	//initializing address to IPv4
	to.sin_family = (short)AF_INET;
	//setting port to right endian
	to.sin_port = htons((u_short)1234);

	strcpy(msg, words);
	sendto(udp_socket_fd, msg, sizeof(msg), 0,(struct sockaddr*) &to, f_size);

	printf("messeage sent.\n");

	return 0;

}




