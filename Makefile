RAYLIBDEPS = -lraylib -lGL -lm -lpthread -ldl -lrt -lX11

main: src/main.cpp objects/gameModel.o
	g++ src/main.cpp objects/bar.o objects/coords.o objects/gameModel.o -o main $(RAYLIBDEPS)

objects/gameModel.o: headers/gameModel.hpp src/gameModel.cpp objects/bar.o
	g++ -c src/gameModel.cpp -o objects/gameModel.o

objects/bar.o: src/bar.cpp headers/bar.hpp objects/coords.o
	g++ -c src/bar.cpp -o objects/bar.o $(RAYLIBDEPS)

objects/coords.o: src/coords.cpp headers/coords.hpp
	g++ -c src/coords.cpp -o objects/coords.o
