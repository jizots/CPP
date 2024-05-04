.PHONY:all clean fclean re

NAME	=	RPN
CXX		=	c++
CXXFLAGS	=	-Wall -Wextra -Werror
CXXFLAGS	+=	-std=c++98
CXXFLAGS	+=	-g

SRCS	=	main.cpp RPN.cpp

SRCS_DIR	=	./srcs/
OBJS_DIR	=	./objs/

OBJS	=	${addprefix ${OBJS_DIR},${SRCS:%.cpp=%.o}}

all:	${OBJS_DIR} ${NAME}

${OBJS_DIR}:
	mkdir -p ${OBJS_DIR}

${OBJS_DIR}%.o: ${SRCS_DIR}%.cpp
	${CXX} ${CXXFLAGS} -c $< -o $@

$(NAME): ${OBJS}
	${CXX} ${CXXFLAGS} -o ${NAME} ${OBJS}

clean:
	rm -rf ${OBJS_DIR}

fclean: clean
	rm -f ${NAME}

re: fclean all