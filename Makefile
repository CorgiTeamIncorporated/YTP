GCC_FOLDER=C:\Users\exp101t\Downloads\x86_64-7.3.0-release-posix-seh-rt_v5-rev0\mingw64

LIBS=-lsfml-graphics -lsfml-window -lsfml-system

CXX=$(GCC_FOLDER)\bin\g++.exe
LIB_DIR=$(GCC_FOLDER)\lib
HEADER_DIR=$(GCC_FOLDER)\include

all: Game.o Unit.o AnimatedSprite.o
	$(CXX) main.cpp Game.o AnimatedSprite.o Unit.o -I $(HEADER_DIR) -I "include" -L $(LIB_DIR) $(LIBS) -o main.exe

Game.o: src/Game.cpp include/Game.hpp
	$(CXX) -c src/Game.cpp -I $(HEADER_DIR) -I "include" -L $(LIB_DIR) $(LIBS) -o Game.o

Unit.o: src/Unit.cpp include/Unit.hpp
	$(CXX) -c src/Unit.cpp -I $(HEADER_DIR) -I "include" -L $(LIB_DIR) $(LIBS) -o Unit.o

AnimatedSprite.o: src/AnimatedSprite.cpp include/AnimatedSprite.hpp
	$(CXX) -c src/AnimatedSprite.cpp -I $(HEADER_DIR) -I "include" -L $(LIB_DIR) $(LIBS) -o AnimatedSprite.o

clean:
	del *.o