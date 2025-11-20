#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>


int main() {
    pid_t child, gchild_1, gchild_2, gchild_3;
	
    
    	
    //Child
    child = fork();
     	
     if (child > 0) {
  	printf("1. Parent process ID: 0\n");
        wait(NULL);
        }   	
        		
    else if (child == 0) {
        printf("2. Child process ID: %d\n", getpid());

       // grand child starts
       
        gchild_1 = fork();

        if (gchild_1 == 0) {
            printf("3. Grandchild process ID: %d\n", getpid());
            exit(1);
            }
        wait(NULL);

       gchild_2 = fork();
        if (gchild_2 == 0) {
            printf("4. Grandchild process ID: %d\n", getpid());
            exit(1);
            }
        wait(NULL);

        gchild_3 = fork();
        if (gchild_3 == 0) {
            printf("5. Grandchild process ID: %d\n", getpid());
            exit(1);
            }
        wait(NULL);
        
    	exit(1);
    	} 
  	
  

    return 0;
}



