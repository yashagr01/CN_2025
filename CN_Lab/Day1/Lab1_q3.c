#include <stdio.h>

int main() {
    unsigned int num;
    char byte1, byte2, byte3, byte4;

    // Input an unsigned integer
    printf("Enter a 4-byte unsigned integer: ");
    scanf("%u", &num);

    // Extract each byte using bitwise AND and right shift
    byte1 = (char)(num & 0xFF);          // Least significant byte
    byte2 = (char)((num >> 8) & 0xFF);
    byte3 = (char)((num >> 16) & 0xFF);
    byte4 = (char)((num >> 24) & 0xFF);  // Most significant byte

    // Print the bytes
    printf("\nExtracted Bytes (in decimal):\n");
    printf("Byte 1 (LSB)  = %d\n", (unsigned char)byte1);
    printf("Byte 2        = %d\n", (unsigned char)byte2);
    printf("Byte 3        = %d\n", (unsigned char)byte3);
    printf("Byte 4 (MSB)  = %d\n", (unsigned char)byte4);

    return 0;
}

