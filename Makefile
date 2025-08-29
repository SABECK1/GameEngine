CC=gcc
SRC=./src/*.c
OUT=./out/game.exe

# Include directories
INCLUDES= \
    -I"C:\SDL\SDL\x86_64-w64-mingw32\include" \
    -I"C:\SDL\SDL IMAGE\x86_64-w64-mingw32\include"

# Library directories and libraries
LIBS= \
    -L"C:\SDL\SDL\x86_64-w64-mingw32\lib" \
    -L"C:\SDL\SDL IMAGE\x86_64-w64-mingw32\lib" \
    -lSDL3 -lSDL3_image

all: build run

build:
	$(CC) $(SRC) -o $(OUT) $(INCLUDES) $(LIBS)

run:
	$(OUT)
