SRC := $(wildcard *.cpp src/*.cpp)
OBJ := $(patsubst %.cpp,bin/%.o,$(notdir $(SRC)))  # object files go to bin/
BIN := bin/mygit

# Default target
run: $(BIN)
	./$(BIN)

# Link all object files into the binary
$(BIN): $(OBJ)
	g++ $(OBJ) -o $(BIN)

# Compile rule for .cpp -> .o (inside bin/)
bin/%.o: %.cpp
	@mkdir -p bin
	g++ -c $< -o $@

# If .cpp is inside src/, still output .o in bin/
bin/%.o: src/%.cpp
	@mkdir -p bin
	g++ -c $< -o $@

clean:
	rm -rf bin

