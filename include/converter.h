#ifndef CONVERTER_H
#define CONVERTER_H

#include <malloc.h>
#include <stdint.h>

#define BINARY 2
#define OCTAL 8
#define HEXADECIMAL 16

char* convert_to_binary(uint64_t decimal);
char* convert_to_octal(uint64_t decimal);
char* convert_to_hexadecimal(uint64_t decimal);

uint64_t convert_to_decimal_from_binary(const char* binary);
uint64_t convert_to_decimal_from_octal(const char* octal);
uint64_t convert_to_decimal_from_hexadecimal(const char* hexadecimal);

#endif