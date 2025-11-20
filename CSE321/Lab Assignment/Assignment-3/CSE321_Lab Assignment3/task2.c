#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

struct msg {

    long int type;
    char txt[6];

};



int main() {

    pid_t child1;
    int msg_id;

    struct msg send_data;

    msg_id = msgget((key_t)12, 0666 | IPC_CREAT);


    printf("Please enter the workspace name:\n");

    char workspace[6];
    scanf("%s", workspace);

    if (strcmp(workspace, "cse321") != 0) {

        printf("Invalid workspace name\n");
        msgctl(msg_id, IPC_RMID, 0);
        exit(1);
    }

    send_data.type = 1;

    strcpy(send_data.txt, workspace);

    msgsnd(msg_id, &send_data, sizeof(send_data.txt),0);	

    printf("Workspace name sent to OTP generator: %s\n", send_data.txt);

    child1 = fork();

    if (child1 == 0){

        struct msg re_dat, otp_dat;

        msgrcv(msg_id, &re_dat, sizeof(re_dat), 1, 0);
        printf("OTP generator received workspace name from log in: %s\n", re_dat.txt);


        snprintf(otp_dat.txt, sizeof(otp_dat.txt), "%d", getpid());

        otp_dat.type = 2;

        msgsnd(msg_id, &otp_dat, sizeof(otp_dat.txt), 0);
        printf("OTP sent to log in from OTP generator: %s\n", otp_dat.txt);


        otp_dat.type = 3;

        msgsnd(msg_id, &otp_dat, sizeof(otp_dat.txt), 0);
        printf("OTP sent to mail from OTP generator: %s\n", otp_dat.txt);

        pid_t child2 = fork();

        if (child2 == 0) {
            struct msg mail_dat;

            msgrcv(msg_id, &mail_dat, sizeof(mail_dat.txt), 3, 0);
            printf("Mail received OTP from OTP generator: %s\n", mail_dat.txt);


            send_data.type = 4;
            msgsnd(msg_id, &mail_dat, sizeof(mail_dat.txt), 0);
            printf("OTP sent to log in from mail: %s\n", mail_dat.txt);

            exit(0);
        }

        wait(NULL);
        exit(0);

    }

    wait(NULL);

    struct msg re_dat_otp, re_mail;

    msgrcv(msg_id, &re_dat_otp, sizeof(re_dat_otp.txt), 2, 0);


    printf("Log in received OTP from OTP generator: %s\n", re_dat_otp.txt);
    
    

    msgrcv(msg_id, &re_mail, sizeof(re_mail.txt), 4, 0);


    printf("Log in received OTP from mail: %s\n", re_mail.txt);

    if (strcmp(re_dat_otp.txt, re_mail.txt) == 0) {

        printf("OTP Verified\n");
    }

    else {
        printf("OTP Incorrect\n");
    }

    msgctl(msg_id, IPC_RMID, 0);

    return 0;

}

