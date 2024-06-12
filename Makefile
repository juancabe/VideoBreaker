RAYLIBDEPS = -lraylib -lGL -lm -lpthread -ldl -lrt -lX11

main: src/main.cpp objects/bar.o objects/coords.o
	g++ src/main.cpp objects/bar.o objects/coords.o -o main $(RAYLIBDEPS)

objects/bar.o: src/bar.cpp headers/bar.hpp objects/coords.o
	g++ -c src/bar.cpp -o objects/bar.o $(RAYLIBDEPS)

objects/coords.o: src/coords.cpp headers/coords.hpp
	g++ -c src/coords.cpp -o objects/coords.o
