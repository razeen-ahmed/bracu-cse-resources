#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <string.h>
#include <fcntl.h>



int main(int argc, char *argv[]){

	int fd;
	
	char buffer[100];
	//char red[50];
	fd = open(argv[1],O_CREAT|O_APPEND|O_WRONLY ,0644);
	
	//fgets(buffer,100,stdin);
	
	while (strcmp(buffer ,"-1\n")!=0){
		fgets(buffer,100,stdin);
		
		//printf("%s",buffer);
		if (strcmp(buffer ,"-1\n")!=0){
			write(fd,buffer,strlen(buffer));
		}	
	}
	
	close(fd);
	
	
	return 0;
}





