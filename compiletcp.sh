#!/bin/bash

# Compile the program
cd server
g++ -std=c++11 -o ../executables/tcpserver tcpdriver.cpp TCPServer.cpp

cd ../client
g++ -std=c++11 -o ../executables/tcpclient tcpdriver.cpp TCPClient.cpp