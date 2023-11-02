#include <iostream>
#include <unistd.h> 
#include <cstring>
#include <sys/types.h> 
#include <sys/socket.h> 
#include <arpa/inet.h> 
#include <netinet/in.h> 

#define PORT	 8080 
#define MAXLINE 1024 

// Driver code 
int main() {
	char buffer[MAXLINE]; 
	const char *hello = "Hello from server"; 
	sockaddr_in servaddr, cliaddr;

    int socket_fd = socket(AF_INET, SOCK_DGRAM, 0);
	
	// Creating socket file descriptor 
	if (socket_fd < 0) { 
		perror("socket creation failed"); 
		exit(EXIT_FAILURE); 
	} 
	
	memset(&servaddr, 0, sizeof(servaddr)); 
	memset(&cliaddr, 0, sizeof(cliaddr)); 
	
	// Filling server information 
	servaddr.sin_family = AF_INET; // IPv4 
	servaddr.sin_addr.s_addr = INADDR_ANY; 
	servaddr.sin_port = htons(PORT); 
	
	// Bind the socket with the server address 
	if (bind(socket_fd, (const sockaddr*)&servaddr, sizeof(servaddr)) < 0) {
		perror("bind failed"); 
		exit(EXIT_FAILURE); 
	} 

	socklen_t len = sizeof(cliaddr); //len is value/result 

	int n = recvfrom(socket_fd, buffer, MAXLINE, MSG_WAITALL, (sockaddr*) &cliaddr, &len); 
	buffer[n] = '\0'; 
	printf("Client : %s\n", buffer);

	sendto(socket_fd, hello, strlen(hello), MSG_CONFIRM, (const sockaddr*) &cliaddr, len); 
	printf("Hello message sent.\n");

    close(socket_fd);
	
	return 0; 
}
