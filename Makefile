TARGET = Converter

SRC_FOLDER = ./src/
BUILD_FOLDER = ./build/
BIN_FOLDER = $(BUILD_FOLDER)bin/

$(BIN_FOLDER)$(TARGET): $(BUILD_FOLDER) $(BUILD_FOLDER)main.o $(BUILD_FOLDER)converter.o
	gcc $(BUILD_FOLDER)main.o $(BUILD_FOLDER)converter.o -o $(BIN_FOLDER)$(TARGET)

$(BUILD_FOLDER):
	if not exist "$(BIN_FOLDER)" (mkdir "$(BIN_FOLDER)")

$(BUILD_FOLDER)main.o: $(SRC_FOLDER)main.c
	gcc -c $(SRC_FOLDER)main.c -o $(BUILD_FOLDER)main.o

$(BUILD_FOLDER)converter.o: $(SRC_FOLDER)converter.c
	gcc -c $(SRC_FOLDER)converter.c -o $(BUILD_FOLDER)converter.o

clean:
	rmdir /s /q "$(BUILD_FOLDER)"