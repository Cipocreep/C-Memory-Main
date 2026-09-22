all: build-C

build-C:	main.c ../ex0/ft_strdup.c ../ex1/ft_range.c ../ex2/ft_ultimate_range.c ../ex3/ft_strjoin.c ../ex4/ft_convert_base.c ../ex4/ft_convert_base2.c ../ex5/ft_split.c
	cc -Werror -Wall -Wextra $^ -o Tests-C-Memory
