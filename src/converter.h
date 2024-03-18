#ifndef CONVERTER_H
#define CONVERTER_H

#include <malloc.h>

#define DDT unsigned long long // Default Data Type

#define BINARY 2
#define OCTAL 8
#define HEXADECIMAL 16

char* convert_to_binary(DDT decimal);
char* convert_to_octal(DDT decimal);
char* convert_to_hexadecimal(DDT decimal);

DDT convert_to_decimal_from_binary(const char* binary);
DDT convert_to_decimal_from_octal(const char* octal);
DDT convert_to_decimal_from_hexadecimal(const char* hexadecimal);

#endif