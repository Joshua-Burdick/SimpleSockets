#include <iostream>
#include <cstring>
#include "TCPClient.h"

#define PORT 8080

int main(int argc, char* argv[]) {
    TCPClient client(PORT);

    client.connect("127.0.0.1");

    // Send message
    char* message = "Hello from client!";
    client.send(message, strlen(message));
    printf("Message sent from client.\n");

    // Read message
    char buffer[1024] = {0};
    client.read(buffer, 1024);
    printf("Received message: %s\n", buffer);

    return 0;
}