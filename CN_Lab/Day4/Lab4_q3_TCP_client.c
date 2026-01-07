#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>

int main() {
    int sockfd;
    struct sockaddr_in servaddr;
    int number, result;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(12345);
    inet_pton(AF_INET, "127.0.0.1", &servaddr.sin_addr);

    connect(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr));

    printf("Enter a number: ");
    scanf("%d", &number);

    write(sockfd, &number, sizeof(number));
    read(sockfd, &result, sizeof(result));

    printf("Next prime number: %d\n", result);

    close(sockfd);
    return 0;
}

