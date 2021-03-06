	CXX       := g++
CXX_FLAGS := -std=c++17

BIN     := bin
SRC     := src
INCLUDE := include
LIB     := lib
LIBRARIES   :=
EXECUTABLE  := main


all: $(BIN)/$(EXECUTABLE)

run: clean all
	cls
	echo "🚀 Executing..."
	./$(BIN)/$(EXECUTABLE)

$(BIN)/$(EXECUTABLE): $(SRC)/*.cpp
	echo "🚧 Building..."
	$(CXX) $(CXX_FLAGS) -I$(INCLUDE) -L$(LIB) $^ -o $@ $(LIBRARIES)

clean:
	echo "🧹 Clearing..."
	-rm $(BIN)/*
