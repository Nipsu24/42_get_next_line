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
to retrieve information from files for later parsing (e.g. in context of game maps of 42_so_long or 42_cub3D).

## Function
The function uses a static *char in order to keep track of the file content still to be read. A buffersize for briefly storing read characters
of a line is defined in the header file but can also be altered when compiling using `-D BUFFER_SIZE=n`. Once a newline or a null-terminator 
charactoer is detected, the content of a line is stored in a char * string and given out by the function to the caller function. In the bonus
part the function is altered in order to take multiple file-descriptors at once, unsing an array of static strings within the function.

## Requirements
-`gcc` compiler
with `<fcntl.h>` and `<stdio.h>` 

## Instructions

### 1. Compiling a program with the function

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
Example of main.c (reads first 10 lines of the given test.txt file):
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
### 3. Bonus Part
Bonus files are to be compiled in the same way as the basic files described above. The header
needs to be changed to:
```
#include "get_next_line_bonus.h"
```
This version of the get_next_line function is able to process multiple filedescriptors at once.
A respective main.c file could look as follows:
```
#include <fcntl.h> 
#include <stdio.h> 
#include "get_next_line_bonus.h"

int	main(void)
{
	int		fd;
	int		fd2;
	char	*line;
	char	*line2;
	int		i;

	i = 0;
	fd = open("test.txt", O_RDONLY);
	fd2 = open("test_2.txt", O_RDONLY);
	if (fd < 0 && fd2 < 0)
	{
		perror("Error opening file");
		return (1);
	}
	while (i < 10)
	{
		line = get_next_line(fd);
		line2 = get_next_line(fd2);
		printf("%s", line);
		printf("%s", line2);
		free(line);
		free(line2);
		i++;
	}
	close(fd);
	close(fd2);
	return (0);
}
```
## Testing
This library has been tested with [Francinette](https://github.com/xicodomingues/francinette).
