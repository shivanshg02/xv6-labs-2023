#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"
#include "kernel/fs.h"
#include "kernel/fcntl.h"

int main() {


}


int create_process(int fd) {
	int fd[2]; // [read, write]
	pipe(fd);
	char *buf[1];
	int prime = read(fd[0], buf, 1);
	for (int i = 0; i<2; i++){
		if (i%prime != 0) { 
			write(fd[1], i, 1);
		}
	}

}


// feed numbers 2 to 35

// fork with 