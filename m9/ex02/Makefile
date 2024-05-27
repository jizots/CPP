.PHONY: all clean fclean re debug

NAME    = PmergeMe
CXX     = c++
CXXFLAGS    = -Wall -Wextra -Werror
CXXFLAGS    += -std=c++98
CXXFLAGS	+=	-MMD -MP
CXXFLAGS    += -g

SRCS    = main.cpp PmergeMe.cpp

SRCS_DIR    = ./srcs/
OBJS_DIR    = ./objs/

OBJS    = ${addprefix ${OBJS_DIR},${SRCS:%.cpp=%.o}}
DEPS    = ${OBJS:.o=.d}

all: ${OBJS_DIR} ${NAME}

${OBJS_DIR}:
	mkdir -p ${OBJS_DIR}

${OBJS_DIR}%.o: ${SRCS_DIR}%.cpp
	${CXX} ${CXXFLAGS} -c $< -o $@

$(NAME): ${OBJS}
	${CXX} ${CXXFLAGS} -o ${NAME} ${OBJS}

debug: CXXFLAGS += -DDEBUG
debug: fclean ${OBJS_DIR} ${NAME}

clean:
	rm -rf ${OBJS_DIR}

fclean: clean
	rm -f ${NAME}

re: fclean all

-include ${DEPS}