#include <converter.h>

static int get_length_by_bits(uint64_t number, const char bits) {
    int length = 0;
    for (; number; number /= bits, ++length);
    return length;
}

static char get_symbol_by_remainder(char remainder) {
    if (remainder > 9)
        remainder += 7;
    return remainder + '0';
}

static char* convert_to_bit(uint64_t decimal, int bits) {
    int length = get_length_by_bits(decimal, bits);

    char* output = malloc(length);
    output[length] = '\0';
    for (; decimal; decimal /= bits, --length) {
        output[length - 1] = get_symbol_by_remainder((char) (decimal % bits));
    }

    return output;
}

char* convert_to_binary(uint64_t decimal) {
    return convert_to_bit(decimal, BINARY);
}

char* convert_to_octal(uint64_t decimal) {
    return convert_to_bit(decimal, OCTAL);
}

char* convert_to_hexadecimal(uint64_t decimal) {
    return convert_to_bit(decimal, HEXADECIMAL);
}

static int get_string_length(const char* string) {
    int length = -1;
    for (; string[++length] != '\0';);
    return length;
}

static char get_number_by_remainder(char remainder) {
    if (remainder > 16)
        remainder -= 7;
    return remainder;
}

static uint64_t convert_to_decimal(const char* number, int bits) {
    int length = get_string_length(number);

    uint64_t output = 0;
    for (uint64_t multiplier = 1; length; multiplier *= bits, --length)
        output += (uint64_t) (get_number_by_remainder(number[length - 1] - '0')) * multiplier;

    return output;
}

uint64_t convert_to_decimal_from_binary(const char* binary) {
    return convert_to_decimal(binary, BINARY);
}

uint64_t convert_to_decimal_from_octal(const char* octal) {
    return convert_to_decimal(octal, OCTAL);
}

uint64_t convert_to_decimal_from_hexadecimal(const char* hexadecimal) {
    return convert_to_decimal(hexadecimal, HEXADECIMAL);
}