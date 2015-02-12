CPP_FILES := $(shell find . -name "*.cpp" )
COMPILE_FLAGS := -std=c++11
EXECUTABLE_NAME := main

all:
	g++ $(CPP_FILES) -o $(EXECUTABLE_NAME) $(COMPILE_FLAGS)
