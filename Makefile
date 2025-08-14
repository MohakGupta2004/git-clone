SRC = $(wildcard *.cpp src/*.cpp)
OBJ = $(SRC:.cpp=.o)

run: $(OBJ)
	g++ $(OBJ) -o ./bin/mygit

%.o: %.cpp
	g++ -c $< -o $@

