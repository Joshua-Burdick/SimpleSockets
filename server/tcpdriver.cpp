#include <iostream>
#include <cstring>
#include "TCPServer.h"

#define PORT 8080
#define MAXLINE 1024

int main(int argc, char* argv[]) {
    TCPServer server(PORT);

    server.bind();

    server.listen();
    server.accept();

    // Read messages
    char buffer[MAXLINE] = {0};
    server.read(buffer, MAXLINE);
    printf("Received message: %s\n", buffer);

    // Send message
    char* message = "Hello from server!";
    server.send(message, strlen(message));
    printf("Message sent from server.\n");

    return 0;
}