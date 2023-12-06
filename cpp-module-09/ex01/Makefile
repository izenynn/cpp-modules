### VARS ###

UNAME_S := $(shell uname -s)

### PROGRAM ###

NAME = RPN

### COMPILER ###

CXX = c++

CXXFLAGS = -std=c++98 -Wall -Wextra -Werror -Wpedantic -Wshadow -MMD

### SOURCES ###

SRC = \
	main.cpp		\
	RPN.cpp			\

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
	./$(NAME) || true
	./$(NAME) "89 * 9 - 9 - 9 - 4 - 1 +"
	./$(NAME) "77 * 7 -"
	./$(NAME) "(1 + 1)" || true
	./$(NAME) "424242 +" || true
	./$(NAME) "4 + 4" || true
	./$(NAME) "21 +"
	./$(NAME) "42 -"
	./$(NAME) "24 -"
	./$(NAME) "22 - 0 /" || true

-include $(DEP)

.PHONY: $(PHONY)
