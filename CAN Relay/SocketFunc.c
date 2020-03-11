#include "SocketFunc.h"

int SocketStartup(char *argv[])
{
	int successfulConn; //Variable used for error checking
    int sockfd, newsockfd; //Socket variable in which the system registers onSS
    int portNumber;
    char buffer[256];
    socklen_t clilen;
    struct sockaddr_in serv_addr, cli_addr; //Struct containing an internet address.
    printf("%s\n", argv[2]);


    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
	{
        successfulConn = SOCKET_ERROR;
        //error("ERROR opening socket");
        printf("ERROR opening socket\n");

	}

    //Setting all values in a buffer to zero.
    bzero((char *) &serv_addr, sizeof(serv_addr));
    portNumber = atoi(argv[2]);
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    //Converts a port number in host byte order to a port number in network byte order.
    serv_addr.sin_port = htons(portNumber); 

    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) 
	{
        successfulConn = SOCKET_ERROR;
		// error("ERROR on binding");
		printf("ERROR on binding\n");
	}


	while(((strcmp(buffer, "stop") != 0) || successfulConn != SOCKET_ERROR))
	{	

		listen(sockfd,5);
		clilen = sizeof(cli_addr);
		newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);

		if (newsockfd < 0) 
		{        
            successfulConn = SOCKET_ERROR;
		    //error("ERROR on accept");
		    printf("ERROR on accept\n");

		}    
		
		bzero(buffer,256);
		successfulConn = read(newsockfd,buffer,255);

		if (successfulConn < 0) 
		{
            successfulConn = SOCKET_ERROR;
		    //error("ERROR on accept");
		    printf("ERROR reading from socket\n");
			//error("ERROR reading from socket");
		}

		printf("Here is the message: %s\n",buffer);


		close(newsockfd);
	}

    return successfulConn; 
}

