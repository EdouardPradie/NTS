##
## EPITECH PROJECT, 2023
## B-OOP-400-BDX-4-1-tekspice-edouard.pradie
## File description:
## Makefile
##

CC	=	g++

SRC_COMMANDLINE	=	src/CommandLine/Prompt.cpp	\

SRC_COMPONENTS	=	src/Components/Input.cpp		\
					src/Components/Output.cpp		\
					src/Components/Nand.cpp			\
					src/Components/And.cpp			\
					src/Components/Andl.cpp			\
					src/Components/Nor.cpp			\
					src/Components/Or.cpp			\
					src/Components/Orl.cpp			\
					src/Components/Xor.cpp			\
					src/Components/Xorl.cpp			\
					src/Components/True.cpp			\
					src/Components/False.cpp		\
					src/Components/Not.cpp			\
					src/Components/Notl.cpp			\
					src/Components/Clock.cpp		\
					src/Components/Factory.cpp		\
					src/CommandLine/Prompt.cpp		\
					src/Simulation/Simulation.cpp

SRC_EXCEPTIONS	=	src/Exceptions/Exception.cpp	\

SRC_PARSER	=	src/Parser/Parser.cpp

SRC_SIMULATION	=	src/Simulation/Simulation.cpp	\

SRC_MAIN	=	main.cpp

SRC_MAIN_TEST	=	main.cpp

OBJ	=	$(SRC_MAIN:.cpp=.o) $(SRC_COMMANDLINE:.cpp=.o) $(SRC_COMPONENTS:.cpp=.o) $(SRC_EXCEPTIONS:.cpp=.o) $(SRC_PARSER:.cpp=.o) $(SRC_SIMULATION:.cpp=.o)

OBJ_TEST	=	$(SRC_MAIN_TEST:.cpp=.o) $(SRC_COMPONENTS:.cpp=.o) $(SRC_EXCEPTIONS:.cpp=.o) $(SRC_PARSER:.cpp=.o)

NAME	=	nanotekspice

NAME_TESTS	=	unit_tests

CPPFLAGS	=	-I./include -W -Wall -Wextra -Wpedantic

LDLIBS	=	-lcriterion -lgcov

all:	$(NAME)
.PHONY:	all

$(NAME):	$(OBJ_TEST)
	$(CC) -o $(NAME) $(OBJ_TEST) $(CPPFLAGS) $(LDLIBS)

debug:	fclean
debug:	CFLAGS += -ggdb3
debug:	all
.PHONY:	debug

clean:
	rm -f *.o
	find -name *.o -delete
	rm -f *.gc*
	find -name *.gc* -delete
.PHONY:	clean

fclean:	clean
	rm -f $(NAME)
	rm -f $(NAME_TESTS)
.PHONY:	fclean

re: fclean all
.PHONY:	re