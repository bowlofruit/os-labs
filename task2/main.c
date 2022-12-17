#include "sys/wait.h"
#include "stdio.h"
#include "unistd.h"
#include <stdlib.h>

int main(int argc, char *argv[]) {
    char* arg[argc];
    for(int i = 1; i < argc; i++){
        arg[i - 1] = argv[i];
    }
    arg[argc - 1] = NULL;

    int pid = fork();
    int status;

    if (pid == 0) {
       execvp(argv[1], arg);
       exit(1);
    } else {
        waitpid(pid, &status, 0);
        if (status == 0){
            printf("Success!\n");
       } else{
            printf("Failed, exit code = %d\n", status);
       }
    }
    return 0;
}