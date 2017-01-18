#include "types.h"
#include "stat.h"
#include "user.h"

void printIt() {
    int i;
    int sizeOfArray = 1000;
    for (i=0;i<sizeOfArray;i++){

    }
}

void myfrrtest(void) {
    int number_of_forks = 10;
    int fork_id;
    printValid();
    int i;
    for (i=0;i<number_of_forks;i++){
        fork_id = fork();
        if(fork_id == 0) {
            printIt();
            exit();
        }
    }
    printValid();
}

int main(void) {
    myfrrtest();
    exit();
}
