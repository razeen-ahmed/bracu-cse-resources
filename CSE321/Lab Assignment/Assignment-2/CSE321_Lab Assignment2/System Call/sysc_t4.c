
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>


int main(int argc, char *argv[]) {
    
    pid_t pid_child;

    pid_child = fork();

    //executing sorting	
    if (pid_child == 0) {
        execv("./sort", argv);
    } 
    
    //executing oddeven
    else {
            
        wait(NULL);
        execv("./oddeven", argv);
    
        } 

    return 0;
}

