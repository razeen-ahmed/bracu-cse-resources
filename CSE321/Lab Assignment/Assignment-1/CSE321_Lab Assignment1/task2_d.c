#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

    char email[25];
    char check[10];
    int count = 0;

    int flag1 = 0; // check @


    printf("Enter the String: \n");
    scanf("%s",email);
    //fgets(pass,25,stdin);

    for (int i =0; i<strlen(email); i++){
        if(email[i] =='@'){

            flag1 = 1;

        }
        else if(flag1 == 1){

            check[count] = email[i];
            count+=1;

        }


    }

   // printf("%s",check);
    if(strcmp(check , "sheba.xyz")== 0){
        printf("Email address is okay");

        }
    else{
        printf("Email address is outdated");
    }



    return 0;
}

