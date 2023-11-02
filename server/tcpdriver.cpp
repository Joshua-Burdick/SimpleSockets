#include <iostream>
#include <cstring>
#include "Server.h"

#define PORT 8080
#define TYPE UDP

int main(int argc, char* argv[]) {
    TCPServer server(PORT);

    server.bind();

    server.listen();
    server.accept();

    // Read messages
    char buffer[1024] = {0};
    server.read(buffer, 1024);
    printf("Received message: %s\n", buffer);

    // Send message
    char* message = "Hello from server!";
    server.send(message, strlen(message));
    printf("Message sent from server.\n");

    return 0;
}