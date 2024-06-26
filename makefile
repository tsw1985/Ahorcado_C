CXX := g++
CXXFLAGS := -Iheader -Wall -g
LDFLAGS := 
SRC_DIR := src
OBJ_DIR := obj
BIN_DIR := bin

SOURCES := $(wildcard $(SRC_DIR)/*.cpp)
OBJECTS := $(SOURCES:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)
TARGET := $(BIN_DIR)/main

all: $(TARGET)

$(TARGET): $(OBJECTS) | $(BIN_DIR)
	$(CXX) $(LDFLAGS) -o $@ $(OBJECTS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $@

$(BIN_DIR):
	mkdir -p $@

clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)

.PHONY: all clean