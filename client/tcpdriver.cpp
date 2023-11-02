#include <iostream>
#include <cstring>
#include "TCPClient.h"

#define PORT 8080
#define MAXLINE 1024

int main(int argc, char* argv[]) {
    TCPClient client(PORT);

    client.connect("127.0.0.1");

    // Send message
    char* message = "Hello from client!";
    client.send(message, strlen(message));
    printf("Message sent from client.\n");

    // Read message
    char buffer[MAXLINE] = {0};
    client.read(buffer, MAXLINE);
    printf("Received message: %s\n", buffer);

    return 0;
}