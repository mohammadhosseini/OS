#include "types.h"
#include "stat.h"
#include "user.h"

void mprint() {
    int i;
    int cnt = 100;
    printf(1, "\n");
    for (i=0;i<cnt;i++){
        printf(2, "Child %d prints for the %d time.\n",getpid(),i);
    }
}

void rrsanitytest(void) {
    int forkCount = 10;
    int wTime[forkCount];
    int rTime[forkCount];
    int forkId;

    int i;
    for (i=0;i<forkCount;i++){
        forkId = fork();
        if(forkId == 0) {
            mprint();
            exit();
        }
    }
    while(wait() > 0){
        printf(2, "PID : %d - Wait time : %d - Running time : %d - Turn Around time : %d.\n", getPerformanceData(&wTime[i], &rTime[i]), wTime[i], rTime[i], rTime[i] + wTime[i]);
    }
}

int main(void) {
    rrsanitytest();
    exit();
}
