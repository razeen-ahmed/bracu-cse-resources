#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){


    char palin[100];

    printf("Enter a string:\n");
    scanf("%s",palin);

    char *start = palin;
    char *end = palin +strlen(palin)-1;
    int flag = 1;


    //printf("%c",*start);
    //printf("%c",*end);

    while (start < end){


        if(*start !=  *end){
            flag = 0;
            break;


        }
        else if(start == strlen(palin)+palin-1){
            //printf()
            flag = 1;

        }

        start++;
        end--;

    }

    if (flag == 0){
        printf("Not a palindrome");

    }
    else if (flag == 1){
        printf("Palindrome");

    }


    return 0;

}

