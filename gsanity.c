#include "types.h"
#include "stat.h"
#include "user.h"

void printIt() {
    int i;
    int array_size = 50;
    printf(1, "\n");
    for (i=0;i<array_size ;i++){
        printf(2, "process %d is printing for the %d time.\n", getpid(), i);
    }
}

void my_gsanity(void) {
    printf(2, "Father pid is %d.\n", getpid());
    //sleep(600);
    sleep(200);
    int fork_id;
    fork_id = fork();
    if(fork_id == 0) {
        printIt();
        exit();
    }
    printIt();
}

int main(void) {
    my_gsanity();
    while(wait()>0);
    exit();
}

