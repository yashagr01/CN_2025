// Write a TCP socket program where the client will send two numbers & server will return the sum of these to the client in c language.
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>

int main() {
    int sock;
    struct sockaddr_in server_addr;
    int nums[2], sum;

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Socket error");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(12345);
    inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr);

    connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr));

    printf("Enter two integers: ");
    scanf("%d %d", &nums[0], &nums[1]);

    write(sock, nums, sizeof(nums));
    read(sock, &sum, sizeof(sum));
    printf("Received sum from server: %d\n", sum);

    close(sock);
    return 0;
}

