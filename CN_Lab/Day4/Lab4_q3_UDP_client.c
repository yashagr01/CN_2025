#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>

int main() {
    int sockfd;
    struct sockaddr_in servaddr;
    int number, result;
    socklen_t len = sizeof(servaddr);

    sockfd = socket(AF_INET, SOCK_DGRAM, 0);

    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(12345);
    inet_pton(AF_INET, "127.0.0.1", &servaddr.sin_addr);

    printf("Enter a number: ");
    scanf("%d", &number);

    sendto(sockfd, &number, sizeof(number), 0, (struct sockaddr*)&servaddr, len);
    recvfrom(sockfd, &result, sizeof(result), 0, (struct sockaddr*)&servaddr, &len);

    printf("Next prime number: %d\n", result);

    close(sockfd);
    return 0;
}

