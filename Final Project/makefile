dungeon: Character.o main.o space.o entrance.o dh.o armory.o kitchen.o hallway.o barracks.o troll.o treasure.o
	g++ Character.o main.o space.o entrance.o dh.o armory.o kitchen.o hallway.o barracks.o troll.o treasure.o -o dungeon

Character.o: Character.cpp Character.hpp
	g++ -c Character.cpp

main.o: main.cpp
	g++ -c main.cpp

entrance.o: entrance.cpp entrance.hpp
	g++ -c entrance.cpp

armory.o: armory.cpp armory.hpp
	g++ -c armory.cpp

dh.o: dh.cpp dh.hpp
	g++ -c dh.cpp

kitchen.o: kitchen.cpp kitchen.hpp
	g++ -c kitchen.cpp

hallway.o: hallway.cpp hallway.hpp
	g++ -c hallway.cpp

barracks.o: barracks.cpp barracks.hpp
	g++ -c barracks.cpp

troll.o: troll.cpp troll.hpp
	g++ -c troll.cpp

treasure.o: treasure.cpp treasure.hpp
	g++ -c treasure.cpp

clean:
	rm *.o dungeon
