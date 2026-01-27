##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## Makefile
##

# Variables
SRC     = $(wildcard *.c) $(shell find ./src -name '*.c')  # Source files in root and ./src
OBJ     = $(SRC:.c=.o)                                     # Object files
NAME    = my_radar                                         # Executable name
CC      = gcc                                              # Compiler
CFLAGS  = -O3 -march=native -mtune=native -flto -ffast-math -fomit-frame-pointer -funroll-loops \
         -finline-functions -fdata-sections -ffunction-sections -Wall -Wextra -Werror -I/usr/include -Wno-error -pthread               # Compiler flags
HEADERS = $(shell find -name '*.h')              # Dynamically find all header files
LDFLAGS = -lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio -lm -flto -Wl,--gc-sections -s -pthread # Linker flags

# Default target
all: $(NAME)

# Build executable
$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(LDFLAGS)

# Compile source files into object files
%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

# Clean targets
clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

# Mark non-file targets as phony
.PHONY: all clean fclean re
