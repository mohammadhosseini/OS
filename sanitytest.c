#include "types.h"
#include "stat.h"
#include "user.h"

void printIt() {
    int i;
    int array_size = 500;
    printf(1, "\n");
    for (i=0;i<array_size;i++){
        printf(2, "PID %d prints for the %d time.\n",getpid(),i);
    }
}

void my_sanitytest(void) {
    int fork_cnt = 30;
    int pid;
    int fork_id;

    int i;
    for (i=0;i<fork_cnt;i++){
        fork_id = fork();
        if(fork_id == 0) {
            pid = getpid();
            if(pid %3 == 0){
                nice();
            }
            else if(pid %3 == 1){
                nice();
                nice();
            }
            printIt();
            exit();
        }
    }

    for(i=0;i<fork_cnt;i++){
        int rTime,wTime;
        wait2(&wTime,&rTime);
        printf(2, "PID : %d - Wait time : %d - Running time : %d - Turn Around time : %d.\n", wTime, rTime, wTime + rTime);

    }
}

int main(void) {
    my_sanitytest();
    exit();
}
