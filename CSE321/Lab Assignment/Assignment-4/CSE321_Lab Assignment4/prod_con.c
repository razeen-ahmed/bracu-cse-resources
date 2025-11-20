#include <pthread.h>   
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#define MAX 10 //producers and consumers can produce and consume upto MAX
#define BUFLEN 6
#define NUMTHREAD 2      /* number of threads */


void * consumer(void *id);
void * producer(void *id);


char buffer[BUFLEN];
char source[BUFLEN]; //from this array producer will store it's production into buffer
int pCount = 0;
int cCount = 0;
int buflen;



//initializing pthread mutex and condition variables
pthread_mutex_t count_mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t nonEmpty  = PTHREAD_COND_INITIALIZER;
pthread_cond_t full  = PTHREAD_COND_INITIALIZER;
int thread_id[NUMTHREAD]  = {0,1};
int i = 0; 
int j = 0;


int count = 0;
pthread_mutex_t mutex;


int main()
{
    //int i;
    /* define the type to be pthread */
    pthread_t thread[NUMTHREAD];

    strcpy(source,"abcde");
    buflen = strlen(source);
    /* create 2 threads*/
    /* create one consumer and one producer */
    /* define the properties of multi threads for both threads  */
    //Write Code Here
    
    
    pthread_mutex_init(&mutex, NULL);
    
    pthread_create(&thread[0], NULL, producer, (void *)&thread_id[0]);
    pthread_create(&thread[1], NULL, consumer, (void *)&thread_id[1]);
	
	
    pthread_join(thread[0], NULL);
    pthread_join(thread[1], NULL);
    
    pthread_mutex_destroy(&mutex);

    return 0;
    

}


void * producer(void *id)
{
		/*
	1. Producer stores the values in the buffer (Here copies values from source[] to buffer[]).
	2. Use mutex and thread communication (wait(), sleep() etc.) for the critical section.
	3. Print which produ4. Producer can produce up cer is storing which values using which thread inside the critical section.
	to MAX
	*/
	//Write code here

	int *thread_id = (int *)id;
	

	for (pCount = 0; pCount < MAX; pCount++)
	{
	 	pthread_mutex_lock(&mutex);  // Lock the critical section


	    while (count == BUFLEN) {
	    
		pthread_mutex_unlock(&mutex);
		sleep(2);
		pthread_mutex_lock(&mutex);
	    }
	    

	    buffer[i] = source[pCount % buflen];
	    
	    printf("%d produced %c by Thread %d\n", pCount, buffer[i],*thread_id);
	    i = (i + 1) % BUFLEN;
	    count++;

	    pthread_mutex_unlock(&mutex);
	    sleep(2);
	}

	return NULL;

}

void * consumer(void *id)
{
	   	/*
	1. Consumer takes out the value from the buffer and makes it empty.
	2. Use mutex and thread communication (wait(), sleep() etc.) for critical section
	3. Print which consumer is taking which values using which thread inside the critical section.
	4. Consumer can consume up to MAX
	*/
	//Write code here
	
	int *thread_id = (int *)id;


	for (cCount = 0; cCount < MAX; cCount++) {
	    pthread_mutex_lock(&mutex);


	    while (count == 0) {
	    pthread_mutex_unlock(&mutex);
	    
	    sleep(2);
	    pthread_mutex_lock(&mutex);
	    }

	    printf("%d consumed %c by Thread %d\n", cCount, buffer[j], *thread_id);
	    
	    j = (j + 1) % BUFLEN;
	    
	    count--;

	    pthread_mutex_unlock(&mutex);
	    
	    sleep(2);
	}

	return NULL;
}






