#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<string.h>
#include<unistd.h>
int main()
{
int sockfd, i;
char buf[100]; 
/* We will use this buffer for communication */
struct sockaddr_in sa, ta;
sockfd = socket(AF_INET, SOCK_DGRAM, 0);
/* The structure "sockaddr_in" is defined in <netinet/in.h> for the internet family of protocols. */ 
 sa.sin_family = AF_INET;
 sa.sin_addr.s_addr = htonl(INADDR_ANY); 
// can be used inet_addr("127.0.0.1")
 sa.sin_port = htons(60018);
memset(&(sa.sin_zero),'\0',8);

i = bind(sockfd, (struct sockaddr *)&sa, sizeof(sa));
 printf("test %d %d\n", sockfd, i); 


/* We again initialize the buffer, and receive a  message from the client. */
for(i=0; i < 100; i++) buf[i] = '\0';

int len = sizeof(ta);
recvfrom(sockfd, buf, 100, 0, (struct sockaddr *) &ta, &len);

printf("Received message from IP: %s and port: %i\n", inet_ntoa(ta.sin_addr), ntohs(ta.sin_port));
printf("Msg from client: %s\n", buf);			

/* We initialize the buffer, copy the message to it,
and send the message to the client. */
 for(i=0; i < 100; i++) buf[i] = '\0';
strcpy(buf, "Message from server");
sendto(sockfd, buf, 100, 0, (struct sockaddr*)&ta, sizeof(ta));


close(sockfd);
}
