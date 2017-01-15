#include "types.h"
#include "stat.h"
#include "user.h"

int main(void){
  printf(1,"the pid of parent of this process is %d\n", getppid());
  exit();
}
