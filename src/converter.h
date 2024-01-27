#ifndef CONVERTER_H
#define CONVERTER_H

char* convertToBinary(unsigned long long decimal);
char* convertToOctal(unsigned long long decimal);
char* convertToHexadecimal(unsigned long long decimal);

unsigned long long convertToDecimalFromBinary(const char *binary);
unsigned long long convertToDecimalFromOctal(const char *octal);
unsigned long long convertToDecimalFromHexadecimal(const char *hexadecimal);

#endif