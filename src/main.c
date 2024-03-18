#include <stdio.h>
#include "converter.h"

char check_input(char* string) {
    char input_whitelist[] = { '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '\0'};

    for (char i = 0, status = 0; string[i] != '\0'; status = 0, ++i) {
        for (char j = 0; input_whitelist[j] != '\0'; ++j)
            if (string[i] == input_whitelist[j])  {
                status = 1;
                break;
            }
        if (status) continue;
        return 1;
    }
    return 0;
}

DDT get_number_by_string(char* string) {
    DDT output = 0;
    for (char pointer = 0; string[pointer] != '\0'; output = output * 10 + (DDT) (string[pointer] - '0'), ++pointer);
    return output;
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Too few or too many arguments!");
        return 1;
    }

    char* input_number = argv[1];
    if (check_input(input_number)) {
        printf("Unsupported characters!");
        return 2;
    }

    DDT number = get_number_by_string(input_number);
    char* binary = convert_to_binary(number);
    char* octal = convert_to_octal(number);
    char* hexadecimal = convert_to_hexadecimal(number);

    printf("BIN: %s\n", binary);
    printf("OCT: %s\n", octal);
    printf("DEC: %llu\n", number);
    printf("HEX: %s\n\n", hexadecimal);
    
    printf("DEC FROM BIN: %llu\n", convert_to_decimal_from_binary(binary));
    printf("DEC FROM OCT: %llu\n", convert_to_decimal_from_octal(octal));
    printf("DEC FROM HEX: %llu", convert_to_decimal_from_hexadecimal(hexadecimal));

    free(binary);
    free(octal);
    free(hexadecimal);

    return 0;
}