# Setting some variables in order to simlify

# Set the compiler
CC = g++

# Set flags for linker
CFLAGS = -c -Wall

# Set directiry with .o files
OBJ_DIR = build

SRC_DIR = src

# Set source files
SOURCE = $(SRC_DIR)/main.cpp \
		$(SRC_DIR)/Matrix.cpp \

# Set object files
# patsubst change all objects before colon 
# to the objects after colon
OBJ = $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SOURCE))

main: $(OBJ)
	$(CC) $(OBJ) -o $@ 

build/%.o: src/%.cpp
	$(CC) $< $(CFLAGS) -o $@  

clean:
	rm -rf build/*.o *.o main
