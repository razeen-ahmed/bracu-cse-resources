#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void bub_sort(int arr[], int n){

    int temp;

    for (int i=0; i<n;i++){

       for (int j=0; j<n-i-1;j++){
            if (arr[j]<arr[j+1]){

                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;

            }

       }

    }

 
}


int main(int argc, char *argv[]){

    int n = argc-1;
    int arr[n];


    for (int i=0; i<n;i++){
        arr[i] = atoi(argv[i+1]);
    }

    bub_sort(arr, n);

    printf("Sorted Array: \n");
    	
    for(int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }

    printf("\n");
    
    
    return 0;

}





