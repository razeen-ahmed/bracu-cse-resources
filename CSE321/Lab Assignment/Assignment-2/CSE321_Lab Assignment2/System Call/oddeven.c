#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int main(int argc, char *argv[]) {

    int n = argc-1;
    int arr[n];


    for (int i = 0; i < n; i++) {
        arr[i] = atoi(argv[i + 1]);
    }


    for (int i = 0; i < n; i++) {
        if (arr[i] % 2 == 0) { 
            printf("Even = %d \n", arr[i]); 
        } 
        else { 
            printf("Odd = %d\n", arr[i]); 
        }
    }


    return 0;

}




