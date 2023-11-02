#include <iostream>
#include <unistd.h> 
#include <string.h> 
#include <sys/types.h> 
#include <sys/socket.h> 
#include <arpa/inet.h> 
#include <netinet/in.h> 

#define PORT	 8080 
#define MAXLINE 1024 

// Driver code 
int main() {
	char buffer[MAXLINE]; 
	const char *hello = "Hello from client"; 
	struct sockaddr_in	 servaddr;

    int socket_fd = socket(AF_INET, SOCK_DGRAM, 0);

	// Creating socket file descriptor 
	if (socket_fd < 0) { 
		perror("socket creation failed"); 
		exit(EXIT_FAILURE); 
	} 

	memset(&servaddr, 0, sizeof(servaddr)); 
	
	// Filling server information 
	servaddr.sin_family = AF_INET; 
	servaddr.sin_addr.s_addr = INADDR_ANY; 
	servaddr.sin_port = htons(PORT); 
	
	socklen_t len = sizeof(servaddr); 
	
	sendto(socket_fd, hello, strlen(hello), MSG_CONFIRM, (const sockaddr*) &servaddr, sizeof(servaddr)); 
	std::cout<<"Hello message sent."<<std::endl; 
		
	int n = recvfrom(socket_fd, buffer, MAXLINE, MSG_WAITALL, (sockaddr*) &servaddr, &len); 
	buffer[n] = '\0'; 
	std::cout<<"Server :"<<buffer<<std::endl; 

	close(socket_fd); 
	return 0; 
}
