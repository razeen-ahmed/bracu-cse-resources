#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

    char pass[100];
    int num = 0;
    
    FILE * fp = fopen("letters.txt","r");

    fgets(pass,100,fp);

    //printf("Enter the String: \n");
    //fgets(pass,100,stdin);
    
    //printf("%s",pass);
    
    fclose(fp);

    FILE * fp1 = fopen("output_file.txt","w");

    for (int i =0; i<strlen(pass); i++){
        if(pass[i] == ' ' && num ==0){
                num +=1;
                fprintf( fp1,"%c" ,pass[i]);

        }
        else if(pass[i] == ' ' && num !=0){
            continue;
        }

        else if(pass[i]!=' '){
            num=0;
            fprintf( fp1, "%c" ,pass[i]);
        }
    }

    fclose(fp1);

    return 0;
}

