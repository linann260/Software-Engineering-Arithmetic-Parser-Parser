# Makefile for evaluate.cpp

# Compiler
CC := g++

# Compiler flags
CFLAGS := -Wall -std=c++11

# Source files
SRCS := evaluate.cpp

# Header files
HEADERS := Evaluate.h

# Object files
OBJS := $(SRCS:.cpp=.o)

# Executable name
TARGET := evaluate

# Build rule for the executable
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

# Build rule for object files
%.o: %.cpp $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

# Clean rule
clean:
	rm -f $(OBJS) $(TARGET)
