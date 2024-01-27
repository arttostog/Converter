#include "converter.h"
#include <malloc.h>

char *convertToBit(unsigned long long decimal, unsigned char bit) {
    unsigned char length = 0;
    for (unsigned long long i = decimal; i; i /= bit, ++length);

    char* output = malloc(length * sizeof(char));
    output[length] = '\0';
    for (; decimal; decimal /= bit, --length) {
        char remainder = (char) (decimal % bit);
        if (remainder < 10) {
            output[length - 1] = remainder + '0';
            continue;
        }
        output[length - 1] = remainder + '7';
    }
    
    return output;
}

char *convertToBinary(unsigned long long decimal) {
    return convertToBit(decimal, 2);
}

char *convertToOctal(unsigned long long decimal) {
    return convertToBit(decimal, 8);
}

char *convertToHexadecimal(unsigned long long decimal) {
    return convertToBit(decimal, 16);
}

unsigned long long convertToDecimal(const char *number, unsigned char bit) {
    unsigned char length = 0;
    for (; number[length] != '\0'; length++);

    unsigned long long output = 0;
    for (unsigned long long multiplier = 1; length; --length, multiplier *= bit) {
        char remainder = number[length - 1] - '0';
        if (remainder >= 17) remainder -= 7;
        output += (unsigned long long) (remainder) * multiplier;
    }

    return output;
}

unsigned long long convertToDecimalFromBinary(const char *binary) {
    return convertToDecimal(binary, 2);
}

unsigned long long convertToDecimalFromOctal(const char *octal) {
    return convertToDecimal(octal, 8);
}

unsigned long long convertToDecimalFromHexadecimal(const char *hexadecimal) {
    return convertToDecimal(hexadecimal, 16);
}