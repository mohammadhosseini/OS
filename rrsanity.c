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


int main(void) {
//    rrsanity();
 //   exit();

    int i=0;
    for(i=0;i<10;i++){
        int pid = fork();
        if(pid<0){
            printf(0,"fork creation failed!\n");
        }else if(pid==0){
            mprint();
            exit();
        }
    }
    for(int i=0;i<10;i++){
        int temp_wtime;
        int temp_rtime;
        wait2(&temp_wtime,&temp_rtime);
        printf(2, "PID : %d - wait time : %d - Running time : %d - Turn Around time : %d.\n", temp_wtime,temp_rtime,temp_wtime+temp_rtime);
    }
}
