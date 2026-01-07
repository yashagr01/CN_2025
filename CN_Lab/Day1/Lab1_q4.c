#include <stdio.h>
#include <stdlib.h>

struct pkt {
    char ch1;     // Byte 1 (LSB)
    char ch2[2];  // Byte 2 and 3
    char ch3;     // Byte 4 (MSB)
};

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <number>\n", argv[0]);
        return 1;
    }

    unsigned int num = atoi(argv[1]);
    struct pkt p;

    printf("The input number = %u\n", num);

    // Extract and display each byte
    printf("digit in the 1st byte=%d\n", num & 0xFF);
    printf("digit in the 2nd byte=%d\n", (num >> 8) & 0xFF);
    printf("digit in the 3rd byte=%d\n", (num >> 16) & 0xFF);
    printf("digit in the 4th byte=%d\n", (num >> 24) & 0xFF);

    // Store each byte in structure members
    p.ch1 = (char)(num & 0xFF);
    p.ch2[0] = (char)((num >> 8) & 0xFF);
    p.ch2[1] = (char)((num >> 16) & 0xFF);
    p.ch3 = (char)((num >> 24) & 0xFF);

    // Print structure members
    printf("1st member of the structure=%d\n", (unsigned char)p.ch1);
    printf("2nd member of the structure=%d,%d\n", (unsigned char)p.ch2[0], (unsigned char)p.ch2[1]);
    printf("3rd member of the structure=%d\n", (unsigned char)p.ch3);

    // Reconstruct the original number
    unsigned int reconstructed = 0;
    reconstructed |= (unsigned char)p.ch1;
    reconstructed |= ((unsigned char)p.ch2[0] << 8);
    reconstructed |= ((unsigned char)p.ch2[1] << 16);
    reconstructed |= ((unsigned char)p.ch3 << 24);

    printf("The regenerated number = %u\n", reconstructed);

    return 0;
}

