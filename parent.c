#include "types.h"
#include "user.h"

int main(void){

	int child_pid = fork();
	if(child_pid<0){
		printf(1,"Fork failed with pid %d \n",child_pid);

	}else if(child_pid>0){
		printf(1,"This is the parent process with id %d and it's child id is %d\n",getpid(), child_pid);

	}else{
		printf(1,"This is the child process with id %d\n", child_pid);
		
	}
	return 0;
}
