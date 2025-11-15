#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int main(int argc, char *argv[]) {
	if (argc != 2) {
		printf("Invalid number of arguments \n");
	}

	char* sleep_time_str = argv[1];
	int sleep_time = atoi(sleep_time_str);
	sleep(sleep_time);
	exit(0);
}
