# Makefile for Matrix Operations
# Author: Justin Daugherty
# Date: 2025-04-02

CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -g
LDFLAGS = -lgtest -lgtest_main -pthread

SRC = main.cpp matrix.cpp
TEST_SRC = test.cpp matrix.cpp
OBJ = $(SRC:.cpp=.o)
TEST_OBJ = $(TEST_SRC:.cpp=.o)

EXEC = matrix_program
TEST_EXEC = matrix_tests

all: $(EXEC)

# Compiles the main program
$(EXEC): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

# Compiles the tests
test: $(TEST_OBJ)
	$(CXX) $(CXXFLAGS) -o $(TEST_EXEC) $^ $(LDFLAGS)
	./$(TEST_EXEC)

# Clean up generated files
clean:
	rm -f $(OBJ) $(TEST_OBJ) $(EXEC) $(TEST_EXEC)
