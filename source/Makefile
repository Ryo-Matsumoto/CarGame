all:CarGame

CarGame: main.o car.o world.o resource.o
	gcc -o CarGame main.o world.o car.o resource.o -D FREEGLUT_STATIC -lfreeglut_static -lopengl32 -lwinmm -lgdi32 -lglu32

main.o: main.cpp world.h car.h
	gcc -c main.cpp -D FREEGLUT_STATIC -lfreeglut_static -lopengl32 -lwinmm -lgdi32 -lglu32

world.o: world.cpp
	gcc -c world.cpp -D FREEGLUT_STATIC -lfreeglut_static -lopengl32 -lwinmm -lgdi32 -lglu32

car.o: car.cpp
	gcc -c car.cpp -D FREEGLUT_STATIC -lfreeglut_static -lopengl32 -lwinmm -lgdi32 -lglu32

resource.o: resource.rc
	windres resource.rc -o resource.o