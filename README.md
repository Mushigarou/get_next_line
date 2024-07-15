# Get Next Line

get_next_line function developed using only one static variable allows you to read a file (not binary), one line at a time. The function returns the line that was read, or NULL if there is nothing else to read or if an error occurred.

```c
char	*get_next_line(int fd);
```

## Usage:

1 - Include the get_next_line.h header file

2 - Compile your code using the -D BUFFER_SIZE=n flag, where n is the desired buffer size for the read() function. This flag should be added as a flag to the compiler.
 ```
 $> cc -Wall -Wextra -Werror -D BUFFER_SIZE=n <files>.c
```
You can choose the default value for the buffer size by not giving the `-D` flag.

## Static Variable


## Multiple File Descriptors
The get_next_line (Bonus) function can handle multiple file descriptors simultaneously. This means you can read from different file descriptors in separate calls without losing the reading thread of each file descriptor or returning a line from another file descriptor.

```c
 	while (1)
 	{
 		while ((s = get_next_line(fd)))
 			printf("te.txt : %s", s);
 		while ((x =get_next_line(f)))
 			printf("t.txt : %s", x);
 		while ((k =get_next_line(t)))
 			printf("get_next_line_utils.txt : %s", k);
         if (!s && !k && !x)
 			break;
 	}
```

## Note on File Changes and Binary Files
If the file pointed to by the file descriptor changes between consecutive calls to get_next_line, while read() has not reached the end of the file, the function's behavior is undefined.

### This project is licensed under the MIT license 
