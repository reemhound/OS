
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void fillArr (int n, int*arr){
    srand(time(NULL));
    for (int i=0;i<n;i++){
        *(arr+i)=rand()%200-100;
    }
}
int bigAver (int n, int*arr){
    int sum=0;
    for (int i=0; i<n; i++) {
        sum+=*(arr+i);
    }
    int aver=sum/n;
    
    int am=0;
    for (int i=0; i<n; i++) {
        if(*(arr+i)>aver)am++;
    }
    return am;
}
int afterNegative(int n,int*arr){
    int sum=0;
    int i;
    for (i=0; i<n; i++) {
        if(*(arr+i)<0){
            break;
        }
    }
    i++;
    for (i; i<n; i++) {
        sum+=*(arr+i);
    }
    return sum;
}
