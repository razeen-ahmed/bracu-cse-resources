#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <fcntl.h>



int main(){

	pid_t a, b;

	
	a = fork();
	
	if (a>0){
		wait(&a);
		printf("I am parent");	
	
	
	}
	
	else if (a ==0){
		b = fork();
		
		if (b>0){
			wait(&b);
			printf("I am child\n");
		
		}
			
		else if(b == 0){	
			
			printf("I am grandchild\n");
		}
	
	
	}




	return 0;
}



