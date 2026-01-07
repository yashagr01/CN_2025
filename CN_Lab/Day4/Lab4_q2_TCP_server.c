 // Write a TCP socket program where the client will send two numbers & server will return the sum of these to the client in c language.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

int main() {
    int server_sock, client_sock;
    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_len = sizeof(client_addr);
    int nums[2], sum;

    server_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (server_sock < 0) {
        perror("Socket error");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(12345);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    bind(server_sock, (struct sockaddr *)&server_addr, sizeof(server_addr));
    listen(server_sock, 1);
    printf("TCP Server listening on port 12345...\n");

    client_sock = accept(server_sock, (struct sockaddr *)&client_addr, &addr_len);
    read(client_sock, nums, sizeof(nums));
    printf("Received numbers: %d and %d\n", nums[0], nums[1]);

    sum = nums[0] + nums[1];
    write(client_sock, &sum, sizeof(sum));
    printf("Sent sum: %d\n", sum);

    close(client_sock);
    close(server_sock);
    return 0;
}

