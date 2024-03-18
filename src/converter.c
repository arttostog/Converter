#include "converter.h"

char _get_length_by_bits(DDT number, const char bits) {
    char length = 0;
    for (; number; number /= bits, ++length);
    return length;
}

char _get_symbol_by_remainder(char remainder) {
    if (remainder > 9)
        remainder += 7;
    return remainder + '0';
}

char* _convert_to_bit(DDT decimal, const char bits) {
    char length = _get_length_by_bits(decimal, bits);

    char* output = malloc(length * sizeof(char));
    output[length] = '\0';
    for (; decimal; decimal /= bits, --length) {
        output[length - 1] = _get_symbol_by_remainder((char) (decimal % bits));
    }

    return output;
}

char* convert_to_binary(DDT decimal) {
    return _convert_to_bit(decimal, BINARY);
}

char* convert_to_octal(DDT decimal) {
    return _convert_to_bit(decimal, OCTAL);
}

char* convert_to_hexadecimal(DDT decimal) {
    return _convert_to_bit(decimal, HEXADECIMAL);
}

DDT _get_string_length(const char* string) {
    char length = -1;
    for (; string[++length] != '\0';);
    return length;
}

char _get_number_by_remainder(char remainder) {
    if (remainder > 16)
        remainder -= 7;
    return remainder;
}

DDT _convert_to_decimal(const char* number, const char bits) {
    char length = _get_string_length(number);

    DDT output = 0;
    for (DDT multiplier = 1; length; multiplier *= bits, --length)
        output += (DDT) (_get_number_by_remainder(number[length - 1] - '0')) * multiplier;

    return output;
}

DDT convert_to_decimal_from_binary(const char* binary) {
    return _convert_to_decimal(binary, BINARY);
}

DDT convert_to_decimal_from_octal(const char* octal) {
    return _convert_to_decimal(octal, OCTAL);
}

DDT convert_to_decimal_from_hexadecimal(const char* hexadecimal) {
    return _convert_to_decimal(hexadecimal, HEXADECIMAL);
}