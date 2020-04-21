##
## Makefile for CPP_abstractvm_2019 
##
## Made by Simon Frezard, Li Wang-Faure, Julien Barriere
##
## Started on  Wed Jan 8 13:33:56 2020 
## Last update Mon Jan 12 8:05:32 PM 2020 main.cpp
##

NAME = abstractVM

SRC = 	main.cpp	\
		IOperand/IOperand.cpp	\
		IOperand/Operand.cpp	\
		Factory/Factory.cpp		\
		Parser/Parser.cpp	\
		Memory/Memory.cpp	\
		Exception/Exception.cpp	\
		Factory/commands.cpp \
		# add cpp files here no need for headers

OBJ=$(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	g++ $(OBJ) -o $(NAME) 

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all