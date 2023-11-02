#include <iostream>
#include <cstring>

#include "UDPServer.h"

#define PORT	 8080 
#define MAXLINE 1024 

// Driver code 
int main() {
	char buffer[MAXLINE]; 
	const char *hello = "Hello from server"; 
	
    	UDPServer server(PORT);

    	server.bind();

	server.read(buffer, MAXLINE);
	printf("Client: %s\n", buffer);

	server.send(hello, strlen(hello));
	printf("Hello message sent.\n");
	
	return 0; 
}
