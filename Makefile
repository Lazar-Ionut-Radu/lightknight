# Compiler
CXX = g++
CXXFLAGS = -std=c++17 -O2 -Wall -Wextra -I./include -g

# Directories
SRC_DIR = src
BUILD_DIR = build
TEST_DIR = tests

# Source files
SRCS = $(wildcard $(SRC_DIR)/*.cc)
OBJS = $(patsubst $(SRC_DIR)/%.cc, $(BUILD_DIR)/%.o, $(SRCS))

# Test sources and executables
TEST_SRCS = $(wildcard $(TEST_DIR)/*.cpp)
TESTS = $(patsubst $(TEST_DIR)/%.cpp, $(BUILD_DIR)/%, $(TEST_SRCS))

# Executable
LIGHTKNIGHT = $(BUILD_DIR)/LIGHTKNIGHT

# Default target
all: $(LIGHTKNIGHT) $(TESTS)

# Build engine
$(LIGHTKNIGHT): $(OBJS)
	@mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Build object files
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Build tests
$(BUILD_DIR)/%: $(TEST_DIR)/%.cpp $(OBJS)
	@mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Clean build artifacts
clean:
	rm -rf $(BUILD_DIR)/*
