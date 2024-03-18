<div align="center">

# Converter from decimal to binary/octal/hexadecimal in C

### Usage as Program

</div>

Run the compiled program via the console and don't forget to include a decimal number in the arguments.

```C
$ Converter 15
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

Default Data Type (DDT):

It is used in functions. You can configure it in the `converter.h` file.

```C
#define DDT unsigned long long // Default Data Type
```

Available functions:
- `char* convert_to_binary(DDT decimal);` - converts decimal to binary.
- `char* convert_to_octal(DDT decimal);`  - converts octal to binary.
- `char* convert_to_hexadecimal(DDT decimal);` - converts hexadecimal to binary.

- `DDT convert_to_decimal_from_binary(const char *binary);` - converts binary to decimal.
- `DDT convert_to_decimal_from_octal(const char *octal);` - converts octal to decimal.
- `DDT convert_to_decimal_from_hexadecimal(const char *hexadecimal);` - converts hexadecimal to decimal.

**WARNING!** Don't forget to free dynamic arrays!

```C
free(array);
```