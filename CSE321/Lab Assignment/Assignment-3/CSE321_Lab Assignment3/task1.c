#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/shm.h>
#include <sys/types.h>



struct shared{

    char sel[100];
    int b;

};



int main() {

    int pipef[2];
    int sm_id;

    pipe(pipef);

    sm_id = shmget((key_t)101, 1024, 0666 | IPC_CREAT);

    struct shared *accn;

    accn = (struct shared *)shmat(sm_id, NULL, 0);

    accn->b = 1000; //initializing account balance

    printf("Provide Your Input From Given Options:\n");

    printf("1. Type a to Add Money\n");
    printf("2. Type w to Withdraw Money\n");
    printf("3. Type c to Check Balance\n");

    scanf("%s", accn->sel);

    printf("Your selection: %s\n", accn->sel);



    pid_t child = fork();

    //child executing
    if (child == 0){
        close(pipef[0]);
        int money;
        int withdrawMoney;

        if (strcmp(accn->sel, "a") == 0) {


            printf("Enter amount to be added:\n");

            scanf("%d", &money);

            if (money > 0) {
                accn->b += money;

                printf("Balance added successfully\n");

                printf("Updated balance after addition:\n%d\n", accn->b);
            }

            else {
                printf("Adding failed, Invalid amount\n");
            }
        }
        else if (strcmp(accn->sel, "w") == 0) {


            printf("Enter amount to be withdrawn:\n");
            scanf("%d", &withdrawMoney);

            if (withdrawMoney > 0 && withdrawMoney <= accn->b) {
                accn->b -= withdrawMoney;
                printf("Balance withdrawn successfully\n");
                printf("Updated balance after withdrawal:\n%d\n", accn->b);

            }
            else {
            printf("Withdrawal failed, Invalid amount\n");
            }
        }
        else if (strcmp(accn->sel, "c") == 0) {
                printf("Current balance: %d\n", accn->b);
            }
        else {
            printf("Invalid selection\n");
        }

        write(pipef[1], "Thank you for using\n", 21);
        shmdt(accn);
        exit(0);
    }



    

    //parent executing
    else if (child>0){
        close(pipef[1]);
        wait(NULL);

        char buff[150];

        read(pipef[0], buff, sizeof(buff));

        printf("%s",buff);

        shmdt(accn);

        shmctl(sm_id, IPC_RMID, NULL);

    }



    return 0;

}

