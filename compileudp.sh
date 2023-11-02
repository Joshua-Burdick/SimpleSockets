#!/bin/bash

# Compile the program
cd server
g++ -std=c++11 -o udpserver ../executables/udpdriver.cpp UDPServer.cpp

cd ../client
g++ -std=c++11 -o udpserver ../executables/udpdriver.cpp UDPClient.cpp