#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>

int main() {
    int sock;
    struct sockaddr_in server_addr;
    socklen_t addr_len = sizeof(server_addr);
    int nums[2], sum;

    sock = socket(AF_INET, SOCK_DGRAM, 0);
    if (sock < 0) {
        perror("Socket error");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(12345);
    inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr);

    printf("Enter two integers: ");
    scanf("%d %d", &nums[0], &nums[1]);

    sendto(sock, nums, sizeof(nums), 0, (struct sockaddr *)&server_addr, addr_len);
    recvfrom(sock, &sum, sizeof(sum), 0, (struct sockaddr *)&server_addr, &addr_len);

    printf("Received sum from server: %d\n", sum);

    close(sock);
    return 0;
}

