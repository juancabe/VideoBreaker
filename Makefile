RAYLIBDEPS = -lraylib -lGL -lm -lpthread -ldl -lrt -lX11

main: src/main.cpp objects/gameModel.o
	g++ src/main.cpp objects/bar.o objects/coords.o objects/gameModel.o objects/point.o objects/ball.o -o main $(RAYLIBDEPS)

objects/gameModel.o: headers/gameModel.hpp src/gameModel.cpp objects/bar.o objects/point.o objects/ball.o
	g++ -c src/gameModel.cpp -o objects/gameModel.o

objects/bar.o: src/bar.cpp headers/bar.hpp objects/coords.o objects/point.o
	g++ -c src/bar.cpp -o objects/bar.o $(RAYLIBDEPS)

objects/coords.o: src/coords.cpp headers/coords.hpp
	g++ -c src/coords.cpp -o objects/coords.o

objects/point.o: src/point.cpp headers/point.hpp
	g++ -c src/point.cpp -o objects/point.o

objects/ball.o: src/ball.cpp headers/ball.hpp objects/point.o
	g++ -c src/ball.cpp -o objects/ball.o $(RAYLIBDEPS)

