/*
* FILE          : SocketFunc.h
* PROJECT       : CAN Relay
* PROGRAMMER    : Oloruntoba Samuel Lagunju
* DATE          : April 6th 2020
* DESCRIPTION   : Contains methods that will cause the relay to act as a server
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/in.h>
#include <pthread.h>
#include <err.h>
#include <stdbool.h>
#include <netdb.h> 

#include "sockCANFunc.h"

#define SOCKET_ERROR 0
#define DEFAULT_INTERNET_PROTOCOL 0
#define THREAD_ERROR 0
#define SOCKET_SUCCESS 1
#define THREAD_SUCCESS 1
#define DEFAULT_SERVER_PORT 4040
#define LRG_BUFSIZ 256  //Definition used for a large size array

void* serverThread(void* inputMsg);