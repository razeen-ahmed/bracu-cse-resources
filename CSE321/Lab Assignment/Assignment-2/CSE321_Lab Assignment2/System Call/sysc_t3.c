#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>



int count = 1; // First parent process considered

void odd_child(int pid) {


    if (pid%2 != 0) {
        int new_pid = fork();
        if (new_pid == 0) {
            printf("New child process created: %d\n", getpid());
            count++;
            exit(1);
        }
        else if (new_pid > 0) {
            count++;
            wait();
        }
    }

}



int main() {

	    int a, b, c;

	    a = fork();
	    if (a == 0) {
		printf("child process a: %d\n", getpid());
	    }
	    else if (a > 0) {
		count++;
		wait();
	    }

	    b = fork();
	    if (b == 0) {
		printf("child process b: %d\n", getpid());
	    }
	    else if (b > 0) {
		count++;
		wait();
	    }


	    c = fork();
	    if (c == 0) {
		printf("child process c: %d\n", getpid());
	    }
	    else if (c > 0) {
		count++;
		wait();
	    }

	    odd_child(a);
	    odd_child(b);
	    odd_child(c);



	    return 0;

}



