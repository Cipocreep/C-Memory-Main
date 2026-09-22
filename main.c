#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>

char *ft_strdup(char *src);
int *ft_range(int min, int max);
char **ft_split(char *str, char *charset);
char *ft_strjoin(int size, char **strs, char *sep);
char *ft_convert_base(char *nbr, char *base_from, char *base_to);
int ft_ultimate_range(int **range, int min, int max);

void	test_ex0(char* (*test_ex)(char*))
{
	char src1[]= "hello, how are you doing? 42words forty-two; fifty+and+one";
	char src2[]= "";
	char *null_ptr = NULL; 
	
	printf("Our original string is: %s\n", src1);
	char *dup1 = test_ex(src1);
	printf("Our duplicated string is: %s\n", dup1);
	assert(strcmp(src1, dup1) == 0);
	free(dup1);

	printf("Our original string is: %s\n", src2);
	char *dup2 = test_ex(src2);
	printf("Our duplicated string is: %s\n", dup2);
	assert(strcmp(src2, dup2) == 0);
	free(dup2);

	printf("Testing NULL pointer:\n");
	char *dup3 = test_ex(null_ptr);
	assert(dup3 == NULL);
	printf("NULL pointer working!\n");
	free(dup3);

	printf("\nTests Ex0 Passed!\n\n");
}

void	test_ex1(int* (*test_ex)(int, int))
{
	int *array1 = malloc(14 * sizeof(int));
	int *array2;
	int ite = 0;
	int num = -10;

	while (ite < 14)
	{
		array1[ite] = num;
		ite++;
		num++;
	}

	ite = 0;
	printf("Our original array:\n");
	while (ite < 14)
	{
		printf("%i, ", array1[ite]);
		ite++;
	}
	ite = 0;

	printf("\nThe one our function made:\n");
	array2 = test_ex(-10, 4);
	while (ite < 14)
	{
		printf("%i, ", array2[ite]);
		ite++;
	}
	assert(sizeof(array1) == sizeof(array2));

	printf("\nChecking Null Pointers...\n");
	assert(test_ex(4, 4) == NULL);
	assert(test_ex(5, -264) == NULL);

	free(array1);
	free(array2);
	printf("\nTests Ex1 Passed!\n\n");
}

void	test_ex2(int (*test_ex)(int **, int, int))
{
	int *pointer_to_array1;
	int *pointer_to_array2;
	int *array1 = malloc(14 * sizeof(int));
	int *array2 = malloc(32 * sizeof(int));
	int returned_num;
	int ite = 0;
	int num = -10;

	while (ite < 14)
	{
		array1[ite] = num;
		ite++;
		num++;
	}
	ite = 0;
	num = -33;
	while (ite < 32)
	{
		array2[ite] = num;
		ite++;
		num++;
	}

	ite = 0;
	printf("An exemple array:\n");
	while (ite < 14)
	{
		printf("%i, ", array1[ite]);
		ite++;
	}
	ite = 0;

	printf("\nThe one our function made thanks to passing the address:\n");
	returned_num = test_ex(&pointer_to_array1, -10, 4);
	assert(returned_num == 14);

	while (ite < 14)
	{
		printf("%i, ", pointer_to_array1[ite]);
		ite++;
	}
	ite = 0;
	printf("\nAn exemple array:\n");
	while (ite < 32)
	{
		printf("%i, ", array2[ite]);
		ite++;
	}
	ite = 0;

	printf("\nThe one our function made thanks to passing the address:\n");
	returned_num = test_ex(&pointer_to_array2, -33, -1);
	assert(returned_num == 32);

	while (ite < 32)
	{
		printf("%i, ", pointer_to_array2[ite]);
		ite++;
	}

	printf("\nChecking Null Pointers...\n");
	assert(test_ex(&pointer_to_array1, 4, 4) == 0);
	assert(test_ex(&pointer_to_array1, 4, 4) == 0);
	assert(test_ex(&pointer_to_array1, 5, -264) == 0);
	free(array1);
	free(array2);
	free(pointer_to_array1);
	free(pointer_to_array2);

	printf("\nTests Ex2 Passed!\n\n");
}

void	test_ex3(char *(*test_ex)(int, char **, char *))
{
	char **srt_of_str;
	char *returned_str;
	// char *str1;
	// char *str2;
	// char *str3;
	// char *str4;


	srt_of_str = malloc(5 * sizeof(char *));
	srt_of_str[0] = "I";
	srt_of_str[1] = "was";
	srt_of_str[2] = "tossing";
	srt_of_str[3] = "your";
	srt_of_str[4] = "salad";
	// int ite = 0;
	// int num = -10;

	returned_str = test_ex(5, srt_of_str, " ");
	printf("\nOur string: '%s'\n", returned_str);
	assert(strcmp(returned_str, "I was tossing your salad") == 0);
	free(returned_str);

	returned_str = test_ex(5, srt_of_str, "*&^#");
	printf("\nOur string: '%s'\n", returned_str);
	assert(strcmp(returned_str, "I*&^#was*&^#tossing*&^#your*&^#salad") == 0);
	free(returned_str);

	returned_str = test_ex(5, srt_of_str, "");
	printf("\nOur string: '%s'\n", returned_str);
	assert(strcmp(returned_str, "Iwastossingyoursalad") == 0);
	free(returned_str);

	returned_str = test_ex(0, srt_of_str, " ");
	printf("\nOur string: '%s'\n", returned_str);
	free(returned_str);

	free(srt_of_str);

	printf("\nTests Ex3 Passed!\n\n");
}


void	test_ex4(char *(*test_ex)(char *, char *, char *))
{
	char base_from[17] = "0123456789abcdef";
	char base_to[11] = "0123456789";
	char nbr[3] = "6f";
	char *converted_nbr;

	converted_nbr = test_ex(nbr, base_from, base_to);
	printf("Our original base: %s\n", base_from);
	printf("Our base to convert to: %s\n", base_to);
	printf("Our original number: %s\n", nbr);
	printf("Our converted number: %s\n\n", converted_nbr);
	assert(strcmp(converted_nbr, "111") == 0);

	char nbr2[4] = "-6f";

	converted_nbr = test_ex(nbr2, base_from, base_to);
	printf("Our original base: %s\n", base_from);
	printf("Our base to convert to: %s\n", base_to);
	printf("Our original number: %s\n", nbr2);
	printf("Our converted number: %s\n\n", converted_nbr);
	assert(strcmp(converted_nbr, "-111") == 0);

	char nbr3[4] = "+6f";

	converted_nbr = test_ex(nbr3, base_from, base_to);
	printf("Our original base: %s\n", base_from);
	printf("Our base to convert to: %s\n", base_to);
	printf("Our original number: %s\n", nbr3);
	printf("Our converted number: %s\n\n", converted_nbr);
	assert(strcmp(converted_nbr, "111") == 0);

	char nbr5[33] = "01111111111111111111111111111111";
	char base_from2[3] = "01";
	char base_to2[11] = "0123456789";

	converted_nbr = test_ex(nbr5, base_from2, base_to2);
	printf("Our original base: %s\n", base_from2);
	printf("Our base to convert to: %s\n", base_to2);
	printf("Our original number: %s\n", nbr5);
	printf("Our converted number: %s\n\n", converted_nbr);
	assert(strcmp(converted_nbr, "2147483647") == 0);

	char nbr6[35] = "-10000000000000000000000000000000";

	converted_nbr = test_ex(nbr6, base_from2, base_to2);
	printf("Our original base: %s\n", base_from2);
	printf("Our base to convert to: %s\n", base_to2);
	printf("Our original number: %s\n", nbr6);
	printf("Our converted number: %s\n\n", converted_nbr);
	assert(strcmp(converted_nbr, "-2147483648") == 0);

	char base_from3[4] = "01\t";
	char base_to3[11] = "0123456789";

	converted_nbr = test_ex("010011\t101", base_from3, base_to3);
	printf("Testing bases that should fail (it's got a tabulation inside): 01\\t\n");
	printf("It returns: %s\n\n", converted_nbr);
	assert(converted_nbr == NULL);

	converted_nbr = test_ex(nbr6, "01", "abcdefghijkle");
	printf("Testing bases that should fail: %s\n", "abcdefghijkle");
	printf("It returns: %s\n\n", converted_nbr);
	assert(converted_nbr == NULL);

	converted_nbr = test_ex(nbr6, "01", "123456+890");
	printf("Testing bases that should fail: %s\n", "123456+890");
	printf("It returns: %s\n\n", converted_nbr);
	assert(converted_nbr == NULL);

	char nbr4[5] = "/+6f";

	converted_nbr = test_ex(nbr4, base_from, base_to);
	printf("Our original base: %s\n", base_from);
	printf("Our base to convert to: %s\n", base_from);
	printf("Testing number that should fail: %s\n", nbr4);
	printf("It returns: %s\n\n", converted_nbr);
	assert(converted_nbr == NULL);

	converted_nbr = test_ex("478", "0123457", "012345678");
	printf("Our original base: %s\n", "0123457");
	printf("Our base to convert to: %s\n", "012345678");
	printf("Testing number that should fail: %s\n", "478");
	printf("It returns: %s\n", converted_nbr);
	assert(converted_nbr == NULL);

	printf("\nTests Ex4 Passed!\n\n");
}

void	test_ex5(char **(*test_ex)(char *, char *))
{
	char string[22] = "#Hello#/truc/6machin6";
	char charset[5] = "#/6*";
	char string2[29] = "#Hello#/truc/6machin6#Hello#";
	int ite = 0;
	char **split;
	char **array_of_arrays = malloc(8 * 4);
	// char array_inside_array = malloc(8);
	array_of_arrays[0] = "#Hello#";
	array_of_arrays[1] = "/truc/";
	array_of_arrays[2] = "6machin6";
	array_of_arrays[3] = "#Hello#";
	split = test_ex(string, charset);
	printf("Our original string: %s\n", string);
	printf("Our separators: %s\n", charset);
	while (ite < 3)
	{
		printf("Our string: \n%s\n", split[ite]);
		printf("Should be identical to: \n%s\n", array_of_arrays[ite]);
		assert(strcmp(array_of_arrays[ite], split[ite]) == 0);
		ite++;
	}

	array_of_arrays[1] = "#Hello#";
	array_of_arrays[2] = "/truc/";
	array_of_arrays[3] = "6machin6";

	ite = 0;
	split = test_ex(string2, charset);
	printf("\nOur original string: %s\n", string2);
	printf("Our separators: %s\n", charset);
	while (ite < 4)
	{
		printf("Our string: \n%s\n", split[ite]);
		printf("Should be identical to: \n%s\n", array_of_arrays[ite]);

		assert(strcmp(array_of_arrays[ite], split[ite]) == 0);
		ite++;
	}


	printf("\nTests Ex5 Passed!\n\n");
}



int	main(void)
{
	printf("Ex0: ft_strdup:\n\n");
	test_ex0(ft_strdup);

	printf("Ex1: ft_range:\n\n");
	test_ex1(ft_range);

	printf("Ex2: ft_ultimate_range:\n\n");
	test_ex2(ft_ultimate_range);

	printf("Ex3: ft_strjoin:\n\n");
	test_ex3(ft_strjoin);

	printf("Ex4: ft_convert_base:\n\n");
	test_ex4(ft_convert_base);

	printf("Ex5: ft_split:\n\n");
	test_ex5(ft_split);
}
