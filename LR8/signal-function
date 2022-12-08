#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

// kill -s SIGUSR1 3422

/* Handler for SIGINT */
void signal_handler(int signalNumber) {
    printf("%d\n", signalNumber);
    if (signalNumber == SIGINT) {
        printf("Catch signal SIGINT\n");
    } else if (signalNumber == SIGTERM) {
        printf("Catch signal SIGTERM\n");
    } else if (signalNumber == SIGUSR1){
        printf("Catch signal SIGUSR1\n");
        exit(EXIT_SUCCESS);
    } else {
        fprintf(stderr, "Wrong Signal\n");
        exit(EXIT_FAILURE);
    }

    // exit(EXIT_SUCCESS);
}

int main() {
    setbuf(stdout, NULL);
    printf("PID: %d\n", (int)getpid());

    // Register signal_handler as handler for SIGINT
    if (signal(SIGINT, signal_handler) == SIG_ERR) {
        fprintf(stderr, "It is impossible to handle SIGINT!\n");
        exit(EXIT_FAILURE);
    }

    if (signal(SIGTERM, signal_handler) == SIG_ERR) {
        fprintf(stderr, "It is impossible to handle SIGTERM!\n");
        exit(EXIT_FAILURE);
    }

    if (signal(SIGPROF, SIG_DFL) == SIG_ERR) {
        fprintf(stderr, "It is impossible to reset SIGPROF!\n");
        exit(EXIT_FAILURE);
    }

    if (signal(SIGHUP, SIG_IGN) == SIG_ERR) {
        fprintf(stderr, "It is impossible to ignore SIGHUP!\n");
        exit(EXIT_FAILURE);
    }

    if (signal(SIGUSR1, signal_handler) == SIG_ERR) {
        fprintf(stderr, "It is impossible to handle SIGUSR1!\n");
        exit(EXIT_FAILURE);
    }

    while(1) {
        printf("The process is waiting for signal\n");
        pause();
    }

    fprintf(stderr, "The program is finished\n");

    return EXIT_SUCCESS;
}