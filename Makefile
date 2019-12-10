# GCC_FOLDER=${MINGW730_PATH}
GCC_FOLDER=C:\x86_64-7.3.0-release-posix-seh-rt_v5-rev0\mingw64

LIBS=-lsfml-graphics -lsfml-window -lsfml-system

CXX=$(GCC_FOLDER)\bin\g++.exe
LIB_DIR=$(GCC_FOLDER)\lib
HEADER_DIR=$(GCC_FOLDER)\include

all: Spikes.o GameSprites.o GameTextures.o GameManager.o Unit.o AnimatedSprite.o MapObject.o Dungeon.o Zombie.o GameRoom.o
	$(CXX) main.cpp $^ -I $(HEADER_DIR) -I "include" -L $(LIB_DIR) $(LIBS) -o main.exe

debug: Spikes-debug.o GameSprites-debug.o GameTextures-debug.o GameManager-debug.o Unit-debug.o AnimatedSprite-debug.o MapObject-debug.o Dungeon-debug.o Zombie-debug.o GameRoom-debug.o
	$(CXX) -g main.cpp $^ -I $(HEADER_DIR) -I "include" -L $(LIB_DIR) $(LIBS) -o main-debug.exe

%-debug.o: src/%.cpp
	$(CXX) -g -c $< -I $(HEADER_DIR) -I "include" -L $(LIB_DIR) $(LIBS) -o $@

%.o: src/%.cpp
	$(CXX) -c $< -I $(HEADER_DIR) -I "include" -L $(LIB_DIR) $(LIBS) -o $@

clean:
	del *.o