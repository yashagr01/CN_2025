#include <stdio.h>
#include <stdlib.h>

void print_bytes(unsigned int num) {
    unsigned char *ptr = (unsigned char*)&num;
    printf("----------------------------------\n");
    printf("Memory Address -> Value\n");
    for (int i = 0; i < 4; i++) {
        printf("%p -> %d\n", (void*)(ptr + i), *(ptr + i));
    }
}

unsigned int convert_endian(unsigned int num) {
    return ((num >> 24) & 0xFF) |
           ((num >> 8) & 0xFF00) |
           ((num << 8) & 0xFF0000) |
           ((num << 24) & 0xFF000000);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <number>\n", argv[0]);
        return 1;
    }

    unsigned int num = atoi(argv[1]);
    unsigned char *ptr = (unsigned char*)&num;

    printf("Extracted byte from the LSB of the Number=%d\n", ptr[0]);
    printf("Extracted byte from the 2nd byte of the Number=%d\n", ptr[1]);

    printf("\nMemory representation of the Number\n");
    print_bytes(num);

    if (ptr[0] == (num & 0xFF)) {
        printf("\nThe LSB of the number is stored at the lowest memory address\n");
        printf("Hence, the host machine is in Little Endian\n");
    } else {
        printf("\nThe MSB of the number is stored at the lowest memory address\n");
        printf("Hence, the host machine is in Big Endian\n");
    }

    unsigned int converted = convert_endian(num);
    printf("\nThe Number is converted to ");
    printf(ptr[0] == (num & 0xFF) ? "Big Endian now\n" : "Little Endian now\n");

    printf("Memory representation of the converted Number\n");
    print_bytes(converted);

    printf("\nThe number in %s Format is %u\n", 
           ptr[0] == (num & 0xFF) ? "Big Endian" : "Little Endian", converted);

    return 0;
}

