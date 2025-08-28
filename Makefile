compile: build run

build:
	gcc ./src/main.c -o ./out/game.exe -I "C:\SDL\x86_64-w64-mingw32\include" -L "C:\SDL\x86_64-w64-mingw32\lib" -lSDL3
run:
	./out/game.exe