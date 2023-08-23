# Compiler
CXX := g++

# Compiler flags
CXXFLAGS := -std=c++11 -Wall

# Source files
SRC := main.cpp

# Executable name
TARGET := fandogh-solver

# Default target (what gets built when you just run 'make')
all: $(TARGET)

# Rule for linking object files to create the executable
$(TARGET): $(SRC:.cpp=.o)
	$(CXX) $(CXXFLAGS) $^ -o $@

# Rule for compiling source files to object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up compiled files
clean:
	rm -f $(SRC:.cpp=.o) $(TARGET)