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

- unlink(): This function is used to delete a file.   
```c
int result = unlink("file.txt");
if (result == -1) {
   perror("Error deleting file");
   exit(EXIT_FAILURE);
}
```

- wait(): This function is used to wait for a child process to terminate.   
```c
pid_t childPid = fork();
if (childPid == -1) {
   perror("Error forking process");
   exit(EXIT_FAILURE);
}
if (childPid == 0) {
   // Child process
   exit(EXIT_SUCCESS);
} else {
   // Parent process
   int status;
   pid_t result = wait(&status);
   if (result == -1) {
      perror("Error waiting for child process");
      exit(EXIT_FAILURE);
   }
   if (WIFEXITED(status)) {
      printf("Child process exited with status %d\n", WEXITSTATUS(status));
   }
}
```

- waitpid(): This function is used to wait for a specific child process to terminate.   
```c
pid_t childPid = fork();
if (childPid == -1) {
   perror("Error forking process");
   exit(EXIT_FAILURE);
}
if (childPid == 0) {
   // Child process
   exit(EXIT_SUCCESS);
} else {
   // Parent process
   int status;
   pid_t result = waitpid(childPid, &status, 0);
   if (result == -1) {
      perror("Error waiting for child process");
      exit(EXIT_FAILURE);
   }
   if (WIFEXITED(status)) {
      printf("Child process exited with status %d\n", WEXITSTATUS(status));
   }
}
```

</div>
</details>

## What is a Process?
A process is an executing program with a unique process identifier (PID) assigned by the operating system when it is started. Each process has its own virtual memory space, including its allocated memory, stack and heap.  

## What are IPC Mechanisms?

Interprocess communication (IPC) mechanisms allow processes to communicate and share data with each other. Some common IPC mechanisms are pipes, message queues and shared memory. Pipes are a simple form of IPC that allow unidirectional data flows between two processes, where one process writes data to the pipe and the other reads from the pipe.  

Processes can communicate with each other using IPC mechanisms such as pipes, message queues and shared memory. Pipes are a simple form of IPC that allow two processes to communicate via a unidirectional stream of data. One process writes data to the pipe and the other reads data from the pipe.   

- Pipes: Unidirectional communication channels for transferring data between processes.    

- Named pipes (FIFOs): Similar to pipes, but can be used between unrelated processes, identified by a name in the file system.  

- Message queues: A method of exchanging messages between processes, managed by the operating system. Message queues facilitate the transmission of messages containing data to designated receivers.  

- Shared memory: A region of memory that is accessible to multiple processes, allowing them to exchange data. Shared memory is an efficient alternative to pipes or message queues for exchanging data between processes.  

- Semaphores: Synchronisation primitives that help coordinate activities between processes and protect shared resources from concurrent access by multiple processes.  

- Sockets: Communication endpoints that allow data to be exchanged between processes over a network or within the same machine. Sockets are useful for implementing client-server and other network-based applications.  

IPC mechanisms are essential for building complex systems involving multiple processes or threads. They allow processes to communicate and synchronise their activities, facilitating the development of efficient, reliable and scalable systems.  

## How does a Pipe Work?  

A pipe is an IPC mechanism that allows unidirectional data transfer between two processes. One process writes data to the pipe, while the other reads data from the pipe. In Unix-like systems, the pipe system call creates a pipe, and the read and write system calls handle the data transfer through the pipe.   

Typically, a process creates a pipe using the fork system call, which spawns a new process. After the fork, the process uses the pipe() system call to create a new pipe and is given a pair of file descriptors. One file descriptor handles writing to the pipe, while the other handles reading from the pipe.  

The parent process writes to the pipe using the write file descriptor and the child process reads from the pipe using the read file descriptor. This setup allows bi-directional communication between the two processes using the pipe.   

Pipes are commonly used in shell scripting and other Unix-based systems to link two or more commands. This allows the output of one command to serve as the input for another, a technique known as pipeline processing, which allows complex data processing pipelines to be created with minimal effort.  

```c
int	main(int argc, char *argv[], char *envp[])
{
	t_pipe	*pipe;
	t_args	*args;

	args = get_args(argc, argv);
	pipe = init_pipe(args);
	get_path(pipe, envp);
	create_pipes_and_execute(pipe, args, envp);
	close_pipe(pipe, args);
	return (0);
}
```