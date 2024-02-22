# Name of your executable
TARGET = btc

# Compiler to use
CXX = c++
# Compiler flags
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -o3 -g

# Source files
SRC = main.cpp \
	BitcoinExchange.cpp

# Object files
OBJ = $(SRC:.cpp=.o)

# Build target
all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(TARGET)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(TARGET)

re: fclean all

# Phony targets
.PHONY: all clean re fclean