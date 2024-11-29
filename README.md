<div align="center">

# Converter from decimal to binary/octal/hexadecimal in C

## Usage as Library

</div>

Available functions:

- `char* convert_to_binary(uint64_t decimal);` - converts decimal to binary.
- `char* convert_to_octal(uint64_t decimal);`  - converts octal to binary.
- `char* convert_to_hexadecimal(uint64_t decimal);` - converts hexadecimal to binary.
- `uint64_t convert_to_decimal_from_binary(const char *binary);` - converts binary to decimal.
- `uint64_t convert_to_decimal_from_octal(const char *octal);` - converts octal to decimal.
- `uint64_t convert_to_decimal_from_hexadecimal(const char *hexadecimal);` - converts hexadecimal to decimal.

**WARNING!** Don't forget to free dynamic arrays!

```C
free(array);
```

<div align="center">

## Example usage

</div>

Run the compiled program via the console and don't forget to include a decimal number in the arguments.

```C++
$ Converter 15
BIN: 1111
OCT: 17
DEC: 15
HEX: F
```
