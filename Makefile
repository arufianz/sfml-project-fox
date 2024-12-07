all: build_dir compile link run

build_dir:
	mkdir -p build

compile:
	g++ -c main.cpp -I"C:\library\SFML-2.6.2\include" -DSFML_STATIC -o build/main.o
# g++ -S main.cpp -I"C:\library\SFML-2.6.2\include" -o main.s

link:
	g++ build/main.o -o build/main -L"C:\library\SFML-2.6.2\lib" -lsfml-graphics-s -lsfml-window-s -lsfml-system-s -lopengl32 -lfreetype -lwinmm -lgdi32 -mwindows -lsfml-main

run:
	./build/main
	
clean:
	rm -rf build