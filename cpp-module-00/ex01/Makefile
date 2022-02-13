### VARS ###

UNAME_S := $(shell uname -s)

### PROGRAM ###

NAME = phonebook

### COMPILER ###

CXX = c++
CXXFLAGS = -std=c++98 -Wall -Wextra -Werror -MD

### SOURCES ###

SRC =	main.cpp		\
		PhoneBook.cpp	\
		Contact.cpp		\


OBJ = $(SRC:%.cpp=%.o)

DEP = $(SRC:%.cpp=%.d)

### RULES ###

PHONY := all
all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJ)

PHONY += sanitize
ifeq ($(UNAME_S),Linux)
sanitize: CXXFLAGS += -pedantic -g3 -fsanitize=address -fsanitize=leak -fsanitize=undefined -fsanitize=bounds -fsanitize=null
endif
ifeq ($(UNAME_S),Darwin)
sanitize: CXXFLAGS += -pedantic -g3 -fsanitize=address
endif
sanitize: $(NAME)

PHONY += thread
thread: CXXFLAGS += -g3 -fsanitize=thread
thread: $(NAME)

%.o: %.cpp | $(OBJ_PATH)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJ_PATH):
	mkdir -p $(OBJ_PATH)

PHONY += clean
clean:
	rm -rf $(OBJ)
	rm -rf $(DEP)

PHONY += fclean
fclean: clean
	rm -rf $(NAME)

PHONY += re
re: fclean all

-include $(DEP)

.PHONY: $(PHONY)
