

#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>



void* ascii(void *dar){
	
	int num = 0;
	char var[10];
	
	printf("Enter the Name: \n");
	scanf("%s",var);
	
	for (int i=0; i<strlen(var); i++){
		
		num += (int)var[i];
		
	
	}	
	
	
	pthread_exit(num);


	}



int main(){
	pthread_t thread1, thread2, thread3;
	
	int count =0;	
	
	void* thread_ret1;
	void* thread_ret2;
	void* thread_ret3;
	
	pthread_create(&thread1,NULL,(void *)ascii,NULL);
	pthread_join(thread1, &thread_ret1);
	
	pthread_create(&thread2,NULL,(void *)ascii,NULL);
	pthread_join(thread2, &thread_ret2);
	
	pthread_create(&thread3,NULL,(void *)ascii,NULL);
	pthread_join(thread3, &thread_ret3);
	
	//printf("%d",(int*)thread_ret1);
	//printf("%d",(int*)thread_ret2);
	//printf("%d",(int*)thread_ret3);
	
	if ((int*)thread_ret1 == (int*)thread_ret2){
		if ((int*)thread_ret1 == (int*)thread_ret3){
		
			printf("Youreka!");
			
			}
		else{
			printf("Miracle");
		}	
		
		

	}
	
	else if (((int*)thread_ret1 == (int*)thread_ret3)){
		printf("Miracle!");
		
	
	}
	else if (((int*)thread_ret2 == (int*)thread_ret3)){
		printf("Miracle!");
		
	
	}
	
	else{
		printf("Hasta la vista!");
	}
	
	
	return 0;
	
}














