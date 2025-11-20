
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>



int t_id[5] = {0,1,2,3,4};

void *int_print(int *id){
	
	
	int num = (*id*5)+1;
 
	for (int i=num; i<((*id+1)*5)+1; i++){
		printf("thread-%d prints %d \n",*id,i);
	}
}


int main(){
	
	
	pthread_t thread[5];
	
	for (int i =0; i<5; i++){
	
	pthread_create(&thread[i], NULL, (void *)int_print, &t_id[i]);
	
	pthread_join(thread[i],NULL);
	
	//printf("thread-%d closed \n",t_id[i]);
	
	}
		



	return 0;
}














