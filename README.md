<h1 align="center">get_next_line</h1>

> Hive Helsinki (School 42) third curriculum project (Rank01)

<h2 align="center">
	<a href="#about">About</a>
	<span> · </span>
	<a href="#function">Function</a>
	<span> · </span>
	<a href="#requirements">Requirements</a>
	<span> · </span>
	<a href="#instructions">Instructions</a>
  <span> · </span>
	<a href="#testing">Testing</a>
</h2>

## About
The repository contains a custom readline function which returns after passing it a file-descriptor a string with the content of the read line.
Being the third project in the 42 school's curriculum, it intends to familiarize oneself with the concept of memory allocation and proper
freeing of allocated memory in C. An alteration of this function is used in the course of future school projects written in C language, in order
to retrieve information from files for later parsing (e.g. in context of game maps of 42_so_long or 42_cub3D.

## Function

## Requirements
-`gcc` compiler
with `<fcntl.h>` and `<stdio.h> ` 

## Instructions

### 1. Compiling the printf library

To compile a program with the function, create a main.c file (see example in 2.)  within the repo folder and run:

```
$ gcc get_next_line.c get_next_line_utils.c main.c 
```

### 2. Using it in your code (basic example)

To use the function, include the header path in your main.c file (given all files are in the same folder):
```
#include "get_next_line.h"
```
Also include a file (e.g. test.txt) with some content in the folder.
Example of main.c (reads first 10 lines of the given document(test.txt)):
```
int	main(void)
{
	int		fd;
	char	*line;
	int		i;

	i = 0;
	fd = open("test.txt", O_RDONLY);
	if (fd < 0)
	{
		perror("Error opening file");
		return (1);
	}
	while (i < 10)
	{
		line = get_next_line(fd);
		printf("%s", line);
		free(line);
		i++;
	}
	close(fd);
	return (0);
}
```
Another main.c example for reading straight from the stdin of the terminal:
```
int	main(void)
{
	char	*line;
	int		i;

	i = 0;
	while (i < 10)
	{
		line = get_next_line(STDIN_FILENO);
		printf("%s", line);
		free(line);
		i++;
	}
	return (0);
}
```
