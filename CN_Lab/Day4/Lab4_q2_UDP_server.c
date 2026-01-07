#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

int main() {
    int sock;
    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_len = sizeof(client_addr);
    int nums[2], sum;

    sock = socket(AF_INET, SOCK_DGRAM, 0);
    if (sock < 0) {
        perror("Socket error");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(12345);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    bind(sock, (struct sockaddr *)&server_addr, sizeof(server_addr));
    printf("UDP Server listening on port 12345...\n");

    recvfrom(sock, nums, sizeof(nums), 0, (struct sockaddr *)&client_addr, &addr_len);
    printf("Received numbers: %d and %d\n", nums[0], nums[1]);

    sum = nums[0] + nums[1];
    sendto(sock, &sum, sizeof(sum), 0, (struct sockaddr *)&client_addr, addr_len);
    printf("Sent sum: %d\n", sum);

    close(sock);
    return 0;
}

