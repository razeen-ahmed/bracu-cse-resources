#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){


    int num1;
    int num2;
    int res;

    printf("Enter the 1st number:\n");
    scanf("%d",&num1);
    printf("Enter the 2nd number:\n");
    scanf("%d",&num2);


    if(num1 > num2){
        printf( "%d" ,num1 - num2);

    }
    else if(num1 < num2){

        printf( "%d" ,num1+num2);
    }

    else if(num1 == num2){

        printf( "%d" ,num1*num2);
    }



    return 0;
}

