#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>

int is_prime(int n) {
    if (n < 2) return 0;
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0) return 0;
    return 1;
}

int next_prime(int n) {
    int next = n + 1;
    while (!is_prime(next)) next++;
    return next;
}

int main() {
    int sockfd, newsockfd;
    struct sockaddr_in servaddr, cliaddr;
    int number, prime;
    socklen_t len = sizeof(cliaddr);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(12345);
    servaddr.sin_addr.s_addr = INADDR_ANY;

    bind(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr));
    listen(sockfd, 5);
    printf("TCP Server listening on port 12345...\n");

    newsockfd = accept(sockfd, (struct sockaddr*)&cliaddr, &len);
    read(newsockfd, &number, sizeof(number));
    printf("Received: %d\n", number);

    prime = next_prime(number);
    write(newsockfd, &prime, sizeof(prime));
    printf("Sent next prime: %d\n", prime);

    close(newsockfd);
    close(sockfd);
    return 0;
}

