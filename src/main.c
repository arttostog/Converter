#include <stdio.h>
#include "converter.h"

char check_input(char* string) {
    char input_whitelist[11] = { '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '\0'};

    for (int i = 0, status = 0; string[i] != '\0'; status = 0, ++i) {
        for (int j = 0; input_whitelist[j] != '\0'; ++j)
            if (string[i] == input_whitelist[j])  {
                status = 1;
                break;
            }
        if (status) continue;
        return 1;
    }
    return 0;
}

uint64_t get_number_by_string(char* string) {
    uint64_t output = 0;
    for (int pointer = 0; string[pointer] != '\0'; output = output * 10 + (uint64_t) (string[pointer] - '0'), ++pointer);
    return output;
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        perror("Too few or too many arguments!");
        return 1;
    }

    char* input_number = argv[1];
    if (check_input(input_number)) {
        perror("Unsupported characters!");
        return 2;
    }

    uint64_t number = get_number_by_string(input_number);
    char* binary = convert_to_binary(number);
    char* octal = convert_to_octal(number);
    char* hexadecimal = convert_to_hexadecimal(number);

    printf("BIN: %s\n", binary);
    printf("OCT: %s\n", octal);
    printf("DEC: %llu\n", number);
    printf("HEX: %s\n\n", hexadecimal);

    free(binary);
    free(octal);
    free(hexadecimal);
}