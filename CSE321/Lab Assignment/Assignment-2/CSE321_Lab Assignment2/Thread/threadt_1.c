
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>



int t_id[5] = {1,2,3,4,5};

void *openclose(int *id){
	printf("thread-%d running \n",*id);

}


int main(){
	
	
	pthread_t thread[5];
	
	for (int i =0; i<5; i++){
	
	pthread_create(&thread[i], NULL, (void *)openclose, &t_id[i]);
	
	pthread_join(thread[i],NULL);
	
	printf("thread-%d closed \n",t_id[i]);
	
	}
		



	return 0;
}














