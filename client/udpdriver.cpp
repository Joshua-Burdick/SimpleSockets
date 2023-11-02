#include <iostream>
#include <cstring>
#include "UDPClient.h"

#define PORT	 8080 
#define MAXLINE 1024 

// Driver code 
int main() {
	char buffer[MAXLINE]; 
	const char *hello = "Hello from client"; 
	
    UDPClient client(PORT);
	
	client.send(hello, strlen(hello));
	std::cout<<"Hello message sent."<<std::endl; 
		
	client.read(buffer, MAXLINE);
	std::cout<<"Server: "<<buffer<<std::endl;

	return 0; 
}
