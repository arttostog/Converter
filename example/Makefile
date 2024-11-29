OUTPUT = converter
GCC_FLAGS = -Wall -I../include

ifeq ($(OS), Windows_NT)
	CLEAN_COMMAND = del $(OUTPUT).exe
else
	CLEAN_COMMAND = rm $(OUTPUT)
endif

$(OUTPUT):
	gcc $(GCC_FLAGS) ./src/main.c ../src/converter.c -o $(OUTPUT)

clean:
	$(CLEAN_COMMAND)