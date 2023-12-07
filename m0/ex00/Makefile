.PHONY: all clean fclean re

NAME = Megaphone
CC = c++
CFLAGS = -Wall -Wextra -Werror
CFLAGS += -std=c++98

SRCS = megaphone.cpp

SRCS_DIR	= ./srcs/
OBJS_DIR	= ./objs/

OBJS = ${addprefix ${OBJS_DIR},${SRCS:%.cpp=%.o}}

all:	${OBJS_DIR} ${NAME}

${OBJS_DIR}:
	mkdir -p ${OBJS_DIR}

${OBJS_DIR}%.o:	${SRCS_DIR}%.cpp
	${CC} ${CFLAGS} -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean:
	rm -rf $(OBJS_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all