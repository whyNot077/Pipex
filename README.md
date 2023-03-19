# Pipex : Replicates the functionality of the shell command pipeline!

<details>
<summary>External functions</summary>
<div markdown="1">
open, close, read, write, malloc, free, perror, strerror, access, 
dup, dup2, execve, exit, fork, pipe, unlink, wait, waitpid  

- perror(): This function is used to print an error message to the console.
```c
perror("Error message");
```

- strerror(): This function is used to get a string describing the error code passed as an argument.
```c
char *errorString = strerror(errno);
printf("Error message: %s\n", errorString);
```

- access(): This function is used to check if a file or directory can be accessed.
```c
int result = access("file.txt", R_OK);
if (result == -1) {
   perror("Error accessing file");
   exit(EXIT_FAILURE);
}
```

- dup(): This function is used to duplicate a file descriptor.
```c
int fd2 = dup(fd);
if (fd2 == -1) {
   perror("Error duplicating file descriptor");
   exit(EXIT_FAILURE);
}
```

- dup2(): This function is used to duplicate a file descriptor to a specified file descriptor.
```c
int fd2 = dup2(fd, STDOUT_FILENO);
if (fd2 == -1) {
   perror("Error duplicating file descriptor");
   exit(EXIT_FAILURE);
}
```

- execve(): This function is used to replace the current process with a new process.
```c
char *args[] = {"ls", "-l", NULL};
execve("/bin/ls", args, NULL);
perror("Error executing program");
exit(EXIT_FAILURE);
```

- fork(): This function is used to create a new process.
```c
pid_t childPid = fork();
if (childPid == -1) {
   perror("Error forking process");
   exit(EXIT_FAILURE);
}
if (childPid == 0) {
   // Child process
} else {
   // Parent process
}
```

- pipe(): This function is used to create a pipe for interprocess communication.
```c
int pipefd[2];
int result = pipe(pipefd);
if (result == -1) {
   perror("Error creating pipe");
   exit(EXIT_FAILURE);
}
```
</div>
</details>