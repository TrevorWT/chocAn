# Compiler and flags
CXX	:= g++
CXXFLAGS	:= -std=c++17 -Wall -Wextra -Iinclude

# Sources and objects
SRC	:= main.cpp $(wildcard src/*.cpp)
OBJ	:= $(SRC:.cpp=.o)

# Final executable name
TARGET := chocan

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJ)

	$(CXX) $(CXXFLAGS) -o $@ $(OBJ)

# Compile any .cpp into .o
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)