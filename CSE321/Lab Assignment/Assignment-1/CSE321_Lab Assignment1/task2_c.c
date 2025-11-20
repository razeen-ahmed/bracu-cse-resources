#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

    char pass[25];
    int num = 0;
    char message[100];
    int flag1 = 0; // lowercase
    int flag2 = 0; // Uppercase
    int flag3 = 0; // Digit
    int flag4 = 0; // Special
    int flag0 = 0;

    printf("Enter the String: \n");
    scanf("%s",pass);
    //fgets(pass,25,stdin);

    for (int i =0; i<strlen(pass); i++){
        if(pass[i] >='a' && pass[i] <='z'){

            flag1 = 1;

        }
        else if(pass[i] >='A' && pass[i] <='Z'){

            flag2 = 1;

        }
        else if(pass[i] >='0' && pass[i] <='9'){

            flag3 = 1;

        }

        else if(pass[i] =='_' | pass[i] =='$'| pass[i] =='#'|| pass[i] =='@'){

            flag4 = 1;

        }


    }

    if(flag1 == 0){
        printf("Lowercase character missing, ");
        flag0 = 1;

        }
    if(flag2 == 0){
        printf("Uppercase character missing, ");
        flag0 = 1;
    }
    if(flag3== 0){
        printf("Digit missing, ");
        flag0 = 1;
    }

    if(flag4 == 0){
        printf("Special character missing");
        flag0 = 1;
    }


    if(flag0 == 0){
        printf("OK \n");
    }



    return 0;
}

