#include <stdio.h>
#include "converter.h"

unsigned long long getNumberByStr(char* str) {
    unsigned long long output = 0;
    for (unsigned char pointer = 0; str[pointer] != '\0'; ++pointer) {
        if (pointer > 0) output *= 10;
        output += (unsigned long long) (str[pointer] - '0');
    }
    return output;
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("To few arguments!");
        return 1;
    }

    unsigned long long number = getNumberByStr(argv[1]);
    char* binary = convertToBinary(number);
    char* octal = convertToOctal(number);
    char* hexadecimal = convertToHexadecimal(number);

    printf("BIN: %s\n", binary);
    printf("OCT: %s\n", octal);
    printf("DEC: %llu\n", number);
    printf("HEX: %s\n\n", hexadecimal);
    
    printf("DEC FROM BIN: %llu\n", convertToDecimalFromBinary(binary));
    printf("DEC FROM OCT: %llu\n", convertToDecimalFromOctal(octal));
    printf("DEC FROM HEX: %llu\n", convertToDecimalFromHexadecimal(hexadecimal));
    return 0;
}