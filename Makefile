# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ceccentr <ceccentr@42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/23 14:41:04 by ceccentr          #+#    #+#              #
#    Updated: 2021/02/24 11:50:54 by ceccentr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = containers

SRCS_NAME = main.cpp test_list.cpp test_map.cpp test_vector.cpp test_stack.cpp test_queue.cpp
SRCS_DIR = ./srcs/
SRCS = $(addprefix $(SRCS_DIR), $(SRCS_NAME))

HEADER_NAME = List.hpp ITList.hpp Stack.hpp Test_header.hpp Queue.hpp Vector.hpp Map.hpp ITVector.hpp ITMap.hpp Node.hpp
HEADER_DIR = ./includes/
HEADER = $(addprefix $(HEADER_DIR), $(HEADER_NAME))

GCC_FLAG = -Wall -Werror -Wextra -std=c++98
# CC = clang++ $(GCC_FLAG) вернуть когда закончу!!!
CC = clang++
DEBUG = -g

RED=\033[1;31m
GREEN=\033[1;32m
YELLOW=\033[1;33m
DEFAULT=\033[0m

OBJS = $(SRCS:.cpp=.o)

.PHONY: all clean fclean re

all: $(NAME)

$(OBJS): %.o: %.cpp $(HEADER)
	@$(CC) -c $< -o $@ $(DEBUG)
	@echo "[$(GREEN)OK$(DEFAULT)]$(YELLOW) Компиляция завершена $(DEFAULT)$<"

$(NAME): $(OBJS)
	@$(CC) -o $@ $^

clean:
	@rm -f $(OBJS)
	@echo "[$(GREEN)OK$(DEFAULT)]$(YELLOW) Очищены: $(DEFAULT) $(OBJS)"

fclean: clean
	@rm -f $(NAME)
	@echo "[$(GREEN)OK$(DEFAULT)]$(YELLOW) Удален:  $(DEFAULT) $(NAME)"

re: fclean all