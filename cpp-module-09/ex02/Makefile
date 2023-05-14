### VARS ###

UNAME_S := $(shell uname -s)

### PROGRAM ###

NAME = PmergeMe

### COMPILER ###

CXX = c++
CXXFLAGS = -std=c++98 -Wall -Wextra -Werror -MMD

### SOURCES ###

SRC = \
	main.cpp					\
	PmergeMe.cpp				\

OBJ = $(SRC:%.cpp=%.o)

DEP = $(SRC:%.cpp=%.d)

### RULES ###

PHONY := all
all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJ)

PHONY += sanitize
ifeq ($(UNAME_S),Linux)
sanitize: CXXFLAGS += -Wshadow -pedantic -g3 -fsanitize=address -fsanitize=leak -fsanitize=undefined -fsanitize=bounds -fsanitize=null
endif
ifeq ($(UNAME_S),Darwin)
sanitize: CXXFLAGS += -Wshadow -pedantic -g3 -fsanitize=address
endif
sanitize: $(NAME)

PHONY += thread
thread: CXXFLAGS += -g3 -fsanitize=thread
thread: $(NAME)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

PHONY += clean
clean:
	rm -rf $(OBJ)
	rm -rf $(DEP)

PHONY += fclean
fclean: clean
	rm -rf $(NAME)

PHONY += re
re: fclean all

PHONY += check
check: $(NAME)
	@./$(NAME) `python3 -c 'import random; print(" ".join(map(str, random.sample(range(1, 100001), 100))))'`

-include $(DEP)

.PHONY: $(PHONY)
