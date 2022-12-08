#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include<time.h>

#define NUM 1
#define AMOUNT 10
#define UPPER 10
#define LOWER 1

void* threadFunc(void* arg){
    int i=1;
    while(1){
        printf("  Child Thread.Iteration %d\n",i);
        sleep(1);
        i++;
    }
    return NULL;
}
void createThread(){
    pthread_t thread;
    int res;
    if (res = pthread_create(&thread, NULL, &threadFunc, NULL) != 0){
        perror("Thread creation failed");
        exit(EXIT_FAILURE);
    }
    int i=1;
    while (1){
        printf("Main thread.Iteration %d\n",i);
        sleep(3);
        i++;
    }
    free(&thread);
}

struct param
{
    char*str;
    char*name;
    int num;
};
void pThreadFunc(void * arg){
    struct param p = *(struct param*)arg;
    int num = p.num;
    for(int i=0; i<num; i++){
        printf("%s. %s (%d)\n", p.name, p.str, i);
        sleep(1);
    }
}
void paramThread(){
    sleep(1);
    pthread_t thread1;
    int res1;
    struct param p1;
    p1.str = "Hello from thread 1";
    p1.name = "Thread 1";
    p1.num = 2;
    if (res1 = pthread_create(&thread1, NULL, &pThreadFunc, &p1) != 0){
        perror("Thread 1 creation failed");
        exit(EXIT_FAILURE);
    }
    
    sleep(1);
    pthread_t thread2;
    int res2;
    struct param p2;
    p2.str = "Hello from thread 2";
    p2.name = "Thread 2";
    p2.num = 4;
    if (res2 = pthread_create(&thread2, NULL, &pThreadFunc, &p2) != 0){
        perror("Thread 2 creation failed");
        exit(EXIT_FAILURE);
    }
    
    sleep(1);
    pthread_t thread3;
    int res3;
    struct param p3;
    p3.str = "Hello from thread 3";
    p3.name = "Thread 3";
    p3.num = 6;
    if (res3 = pthread_create(&thread3, NULL, &pThreadFunc, &p3) != 0){
        perror("Thread 3 creation failed");
        exit(EXIT_FAILURE);
    }
    
    sleep(1);
    pthread_t thread4;
    int res4;
    struct param p4;
    p4.str = "Hello from thread 4";
    p4.name = "Thread 4";
    p4.num = 8;
    if (res4 = pthread_create(&thread4, NULL, &pThreadFunc, &p4) != 0){
        perror("Thread 4 creation failed");
        exit(EXIT_FAILURE);
    }
    
    sleep(10);
    
    free(&thread1);
    free(&thread2);
    free(&thread3);
    free(&thread4);
}


void* rand_func(void* arg){
    srand(time(NULL));
    int st = *(int*)arg;
    int a[AMOUNT];
    for(int i=0; i<AMOUNT; i++){
        a[i]=(rand()%(UPPER-LOWER+1))+LOWER;
        printf("%d \n",a[i]);
        if(a[i]==st){
            printf("Found %d\n",st);
            return NULL;
            
        }
        sleep(1);
    }
    
    return NULL;
}
void* jThread(void* arg){
    for(int i=0; i<AMOUNT; i++){
        printf("  Child Thread.Iteration %d\n",i);
        sleep(1);
    }
    return NULL;
}
void syncThread(){
    pthread_t thread;
    int res;
    if (res = pthread_create(&thread, NULL, &jThread, NULL) != 0){
        perror("Thread creation failed");
        exit(EXIT_FAILURE);
    }
    int i = NUM;
    pthread_t thread2;
    int res2;
    if (res2 = pthread_create(&thread2, NULL, &rand_func, &i) != 0){
        perror("Thread creation failed");
        exit(EXIT_FAILURE);
    }
    int resj;
    if (resj = pthread_join(thread, NULL) != 0){
        perror("Thread join failed");
        exit(EXIT_FAILURE);
    }
    int resj2;
    if (resj2 = pthread_join(thread2, NULL) != 0){
        perror("Thread join failed");
        exit(EXIT_FAILURE);
    }
    printf("Main thread finished \n");
    free(&thread);
}

void* simpThread(void* arg){
    int list[AMOUNT];
    if (AMOUNT==1)
    {
        list[0]=1;
    }
    if(AMOUNT>1){
        list[0]=1;
        list[1]=2;
    }
    int l=2;
    int s=2;
    while(s<AMOUNT){
        int flag=0;
        for(int i=2; i<=l/2;++i){
            if(l%i==0){
                flag=1;
                break;
            }
        }
        if(flag==0){
            list[s]=l;
            l++;
            s++;
        }
    }
    for (int i=0; i<AMOUNT; i++){
        printf("%d \n",list[i]);
    }
    return *list;
}
void* catThread(void* arg){
    
    return NULL;
}
void resThread(){
    
   // int (*p)[AMOUNT];
    pthread_t thread;
    int res;
    if (res = pthread_create(&thread, NULL, &simpThread, NULL) != 0){
        perror("Thread creation failed");
        exit(EXIT_FAILURE);
    }
    int resj;
    if(resj = pthread_join(thread, NULL) != 0){
        perror("Thread join failed");
        exit(EXIT_FAILURE);
    }
    /*for (int i=0; i<AMOUNT; i++){
        printf("%d \n",p+i);
    }*/
}

int main (int argc, char * argv[]){
    
    //createThread();
    //paramThread();
    syncThread();
    //resThread();
    return 0;
}
