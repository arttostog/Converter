<div align="center">

# Converter from decimal to binary/octal/hexadecimal in C

### Usage as Program

</div>

Run the compiled program via the console and don't forget to include a decimal number in the arguments.

```C++
$ Converter.exe 15
BIN: 1111
OCT: 17
DEC: 15
HEX: F

// This functionality has been added in case anyone uses it as a library.
DEC FROM BIN: 15
DEC FROM OCT: 15
DEC FROM HEX: 15
```

<div align="center">

### Usage as Library

</div>

Include to your project `converter.h`.

```C
#include "converter.h"
```

Available functions:
- `char* convertToBinary(unsigned long long decimal);` - converts decimal to binary.
- `char* convertToOctal(unsigned long long decimal);`  - converts octal to binary.
- `char* convertToHexadecimal(unsigned long long decimal);` - converts hexadecimal to binary.

- `unsigned long long convertToDecimalFromBinary(const char *binary);` - converts binary to decimal.
- `unsigned long long convertToDecimalFromOctal(const char *octal);` - converts octal to decimal.
- `unsigned long long convertToDecimalFromHexadecimal(const char *hexadecimal);` - converts hexadecimal to decimal.

**WARNING!** Don't forget to free dynamic arrays!

```C
free(array);
```