# Get Next Line

This project is an implementation of the get_next_line function, which allows you to read a text file or input from the standard input, one line at a time. The function returns the line that was read, or NULL if there is nothing else to read or if an error occurred.
Usage

## To use the get_next_line function, follow these steps:

Include the get_next_line.h header file, which contains the function prototype.
Compile your code using the -D BUFFER_SIZE=n flag, where n is the desired buffer size for the read() function. This flag should be added to your compiler call.
 ```
 $> cc -Wall -Wextra -Werror -D BUFFER_SIZE=n <files>.c
```
You can choose the default value for the buffer size.
Call the get_next_line function in a loop to read lines from the file descriptor. Each call will return the next line until there are no more lines to read or an error occurs.
Make sure to handle the returned line appropriately, including the terminating \n character. The line will include the \n character unless the end of the file was reached and it does not end with \n.

## Static Variable

The get_next_line function is developed using only one static variable, ensuring efficient memory usage and thread safety.

## Multiple File Descriptors
The get_next_line function can handle multiple file descriptors simultaneously. This means you can read from different file descriptors in separate calls without losing the reading thread of each file descriptor or returning a line from another file descriptor.

For example, you can call get_next_line to read from file descriptor 3, then 4, then 5, and then repeat the process without any conflicts.

## Note on File Changes and Binary Files
Please note that if the file pointed to by the file descriptor changes between consecutive calls to get_next_line, while read() has not reached the end of the file, the behavior of the function is considered undefined.

Similarly, reading binary files with get_next_line is also considered to have undefined behavior. However, you have the flexibility to implement a logical way to handle this behavior if desired.
Contributing

### Contributions to this project are welcome! If you find any issues or have improvements to suggest, please feel free to submit a pull request.
## License

### This project is licensed under the MIT license 
