#!/bin/bash

# Compile the program
cd server
g++ -std=c++11 -o ../executables/udpserver udpdriver.cpp UDPServer.cpp

cd ../client
g++ -std=c++11 -o ../executables/udpclient udpdriver.cpp UDPClient.cpp