#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"


int main() {
	int parent_to_child[2]; //[read, write] pair

	int child_to_parent[2]; // [read, write] pair

	pipe(parent_to_child);
	pipe(child_to_parent);

	char write_contents[1] = {'a'};
	char read_contents[1];
	// read(int fd, char * buf, int n)
	// write(int fd, char *buf, int n)
	write(parent_to_child[1], write_contents, 1);
	int pid = fork();
	if (pid == 0) { // in the child
		// child logic
		write(child_to_parent[1], write_contents, 1);
		if (read(parent_to_child[0], write_contents, 1) == 1){
			printf("%d: received ping\n", getpid());
		}
	}
	else {
		// back to parent
		pid = wait((int *) 0); // we are waiting for any child process to finish
		if (read(child_to_parent[0], read_contents, 1) == 1){
			printf("%d: received pong\n", getpid());
		}
	}
	exit(0);
}

/*
my take aways here are that when you fork, you create a new clone of the process. 
in that clone, the process id is 0, which is why the pid==0 part of the if statement 
runs. In the parent process, however, the pid is the pid of the child process, so in the parent
program we call wait to wait for the child process to finish (address 0 because we don't care about exit code)
*/