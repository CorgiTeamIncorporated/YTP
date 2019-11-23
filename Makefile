GCC_FOLDER=D:\Soft\MinGW\mingw64

LIBS=-lsfml-graphics -lsfml-window -lsfml-system

CXX=$(GCC_FOLDER)\bin\g++.exe
LIB_DIR=$(GCC_FOLDER)\lib
HEADER_DIR=$(GCC_FOLDER)\include

all: Game.o Unit.o AnimatedSprite.o MapObject.o
	$(CXX) main.cpp $^ -I $(HEADER_DIR) -I "include" -L $(LIB_DIR) $(LIBS) -o main.exe

debug: Game-debug.o Unit-debug.o AnimatedSprite-debug.o MapObject-debug.o
	$(CXX) -g main.cpp $^ -I $(HEADER_DIR) -I "include" -L $(LIB_DIR) $(LIBS) -o main-debug.exe

%-debug.o: src/%.cpp include/%.hpp
	$(CXX) -g -c $< -I $(HEADER_DIR) -I "include" -L $(LIB_DIR) $(LIBS) -o $@

%.o: src/%.cpp include/%.hpp
	$(CXX) -c $< -I $(HEADER_DIR) -I "include" -L $(LIB_DIR) $(LIBS) -o $@

clean:
	del *.o