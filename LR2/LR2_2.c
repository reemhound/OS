#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


int main (int argc, char ** argv){
    if (argc == 1){
        printf("task 2\n");
        printf("usage:\n");
        printf("-o \n");
        printf("$ opts -a 3 -b 12 -o '-'\n");
        return 0;
    }
    char *opts="a:b:o:";
    int a,b;
    char op;
    int opt;
    while((opt=getopt(argc,argv,opts))!=-1){
        switch (opt)
        {
        case 'a':
            a = atoi(optarg);
            break;
        case 'b':
            b = atoi(optarg);
            break;
        case 'o':
            op = optarg[0];
            break;
        }
    }
    switch (op)
    {
        case '+':
            printf("%d + %d = %d\n", a, b, a+b);
            break;
        case '-':
            printf("%d - %d = %d\n", a, b, a-b);
            break;
        case '*':
            printf("%d * %d = %d\n", a, b, a*b);
            break;
        case '/':
            printf("%d / %d = %d\n", a, b, a/b);
            break;
    }
    return 0;
}
