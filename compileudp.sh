#!/bin/bash

# Compile the program
cd server
g++ -std=c++11 -o udpserver udpdriver.cpp TCPServer.cpp

cd ../client
g++ -std=c++11 -o udpserver udpdriver.cpp TCPClient.cpp