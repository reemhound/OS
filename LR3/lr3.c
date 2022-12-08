#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void zombieProc();
void procStat ();
void procCreate();

int main (void){
    zombieProc();
    procStat ();
    procCreate();
    return 0;
}
void zombieProc(){
int status;

    if (!fork()){
        execlp("ls","ls",NULL);    
        fprintf(stderr, "Exec error\n");
    }
    system("ps");
    sleep(10);
    wait(&status);
    system("ps");
    if(WIFEXITED(status)){
        printf("Code %d\n", WEXITSTATUS(status));
    }
    
}
void procStat (){
    printf("Current process ID: %d\n", getpid());
    printf("Parent process ID: %d\n", getppid());
    printf("Group ID: %d\n", getpgrp());
    printf("Real owner ID: %d\n", getuid());
    printf("eUID: %d\n", geteuid());
    printf("Real group ID: %d\n", getgid());
    printf("eGID: %d\n", getegid());
}
void procCreate(){
    int c = 0;
    fork();
    c++ ;
    printf("Value: %d . Memory: %p .  Parent: %d .  Process: %d\n", c, &c, getppid(),getpid());
    fork();
    c++ ;
    printf("Value: %d . Memory: %p .  Parent: %d .  Process: %d\n", c, &c, getppid(),getpid());
    fork();
    c++ ;
    printf("Value: %d . Memory: %p .  Parent: %d .  Process: %d\n", c, &c, getppid(),getpid());
}