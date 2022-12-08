#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>
#include <string.h>
#include <sys/types.h>
#include <pwd.h>
#include <sys/utsname.h>

void quadEqua (int a, int b, int c);


int main (int argc, char ** argv){
    if (argc == 1){
        printf("-one: \n   first task\n");
        printf("   (ax^2 + bx + c = 0)\n   -one a b c\n");
        printf("-four:\n   fourth task\n");
        printf("   environ variable\n");
        printf("-five:\n   fifth task\n");
        printf("   (getenv)\n   -five NAME\n");
        printf("-six:\n   sixth task\n");
        printf("   (setenv)\n   -six NAME value\n");
        printf("-seven:\n   seventh task\n");
        printf("   (unsetenv)\n   -seven NAME\n");
        printf("-eight:\n   eight task\n");
        printf("   (User Data)\n   -eight\n");
        printf("-nine:\n   nineth task\n");
        printf("   (Device Data)\n   -nine\n");
        return 0;
    }
    if(strcmp(argv[1], "-one")==0){
        quadEqua(atoi(argv[2]),atoi(argv[3]),atoi(argv[4]));
    }
    if(strcmp(argv[1], "-four")==0){
        int i=0;
        extern char** environ;
        while (environ[i]!=NULL)
        {

            printf("%s\n ", environ[i]);
            i++;
        }     
    }
    if(strcmp(argv[1], "-five")==0){
        if(argv[2]==NULL){
            printf("-five:\n   fifth task\n");
            printf("   (getenv)\n   -five NAME\n");
        }
        else{
            const char* env=getenv(argv[2]);
            printf("%s\n",env);
        }
    }
    if(strcmp(argv[1], "-six")==0){
        if(argv[2]==NULL || argv[3]==NULL){
            printf("-six:\n   sixth task\n");
            printf("   (setenv)\n   -six NAME value\n");
        }
        else{
            char*name= argv[2];
            char*value = argv[3];
            int set = setenv(name, value,1);
            const char* env=getenv(name);
            printf("%s: %s\n",name, env);
        }
    }
    if(strcmp(argv[1], "-seven")==0){
        int clear, unset;
        /*if(argv[2]==NULL){
            clear = clearenv();
        }*/
        //else{
            unset = unsetenv(argv[2]);
            if (unset==0 && (getenv(argv[2]))==NULL){
                printf("deletion completed\n");
            }
        //}
    }
    if(strcmp(argv[1], "-eight")==0){
        uid_t uid=  getuid();
        char* log = getlogin();
        
        struct passwd* psw = getpwuid(uid);
        
        printf("NAME: %s\n", psw->pw_name);
        printf("UID: %d\n", psw->pw_uid);
        printf("GID: %d\n", psw->pw_gid);
        printf("FULL NAME: %s\n", psw->pw_gecos);
        printf("SHELL: %s\n", psw->pw_shell);
        printf("DIR: %s\n", psw->pw_dir);
        printf("PASS: %d\n", psw->pw_passwd);
    }
    if(strcmp(argv[1], "-nine")==0){
        //char* nameh;
       //int ghn=gethostname(nameh, size_t namelen);
       // printf("hostname: %s\n",nameh);
        struct utsname name;
        int un=uname(&name);
        printf("System name: %s\n", name.sysname);
        printf("node name: %s\n", name.nodename);
        printf("realease: %s\n", name.release);
        printf("version: %s\n", name.version);
        printf("machine: %s\n", name.machine);
        long id=gethostid();
        printf("Host ID: %ld\n", id);
    }
    return 0;
}
void quadEqua (int a, int b, int c){
    float x1=0, x2=0;
    float d=0;

    d=(b*b)-4*a*c;
    if(d<0) printf("NULL");
    else{
        x1=(-b+sqrt(d))/(2*a);
        if(d==0)printf("X: %.2f;\n", x1);
        else{
            x2=(-b-sqrt(d))/(2*a);
            printf("X1: %.2f;\nX2: %.2f;\n", x1,x2);
        }
    }
}