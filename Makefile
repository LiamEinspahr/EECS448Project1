prog: main.o board.o player.o aiEasy.o Executive.o display.o Ship.o
	g++ -g -std=c++11 -Wall main.o board.o player.o aiEasy.o Executive.o display.o Ship.o -o Battleship

main.o: main.cpp Executive.o
	g++ -g -std=c++11 -Wall -c main.cpp

Executive.o: Executive.h Executive.cpp player.o board.o display.o Ship.o
	g++ -g -std=c++11 -Wall -c Executive.cpp

board.o: board.h board.cpp
	g++ -g -std=c++11 -Wall -c board.cpp

player.o: player.h player.cpp board.o
	g++ -g -std=c++11 -Wall -c player.cpp

aiEasy.o: aiEasy.h aiEasy.cpp board.o
	g++ -g -std=c++11 -Wall -c aiEasy.cpp

display.o: display.h display.cpp
	g++ -g -std=c++11 -Wall -c display.cpp

Ship.o: Ship.h Ship.cpp
	g++ -g -std=c++11 -Wall -c Ship.cpp

clean:
	rm *.o Battleship
