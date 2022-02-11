### PROGRAM ###

NAME = "megaphone"

### COMPILER ###

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror

### PATH ###

SRC_PATH = src
OBJ_PATH = obj
INC_PATH = inc

### SOURCES ###

SRC_FILES = megaphone.cpp

SRC = $(addprefix $(SRC_PATH)/, $(SRC_FILES))

OBJ_FILES = $(SRC_FILES:%.cpp=%.o)

OBJ = $(addprefix $(OBJ_PATH)/, $(OBJ_FILES))

DEP_FILES = $(SRC_FILES:%.cpp=%.d)

DEP = $(addprefix $(OBJ_PATH)/, $(DEP_FILES))

### LIBS ###

CXXFLAGS += -I ./$(INC_PATH)/

### RULES ###

PHONY := all
all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJ)

PHONY += sanitize
ifeq ($(UNAME_S),Linux)
sanitize: CFLAGS += -pedantic -g3 -fsanitize=address -fsanitize=leak -fsanitize=undefined -fsanitize=bounds -fsanitize=null
endif
ifeq ($(UNAME_S),Darwin)
sanitize: CFLAGS += -pedantic -g3 -fsanitize=address
endif
sanitize: $(NAME)

PHONY += thread
thread: CFLAGS += -g3 -fsanitize=thread
thread: $(NAME)

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.cpp | $(OBJ_PATH)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJ_PATH):
	mkdir -p $(OBJ_PATH)

PHONY += clean
clean:
	rm -rf $(OBJ_PATH)

PHONY += fclean
fclean: clean
	rm -rf $(NAME)

PHONY += re
re: fclean all

-include $(DEP)

.PHONY: $(PHONY)
