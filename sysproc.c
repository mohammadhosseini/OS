#include "types.h"
#include "x86.h"
#include "defs.h"
#include "date.h"
#include "param.h"
#include "memlayout.h"
#include "mmu.h"
#include "proc.h"

int
sys_fork(void)
{
  return fork();
}

/*int
sys_getPerformanceData(void){

	return secwait();
}*/

int
sys_exit(void)
{
  exit();
  return 0;  // not reached
}

int
sys_wait(void)
{
  return wait();
}


int sys_wait2(void)
{
    int* A=0;
    int* B=0;

    argptr(0,(char **)A,sizeof(int));
    argptr(1,(char **)B,sizeof(int));
    cprintf("%d %d",*A,*B);
    wait2(A,B);

    return 1;
}

int
sys_kill(void)
{
  int pid;

  if(argint(0, &pid) < 0)
    return -1;
  return kill(pid);
}

int
sys_getpid(void)
{
  return proc->pid;
}

int
sys_getppid(void)
{
   return proc->parent->pid;
}

int
sys_sbrk(void)
{
  int addr;
  int n;

  if(argint(0, &n) < 0)
    return -1;
  addr = proc->sz;
  if(growproc(n) < 0)
    return -1;
  return addr;
}

int
sys_sleep(void)
{
  int n;
  uint ticks0;

  if(argint(0, &n) < 0)
    return -1;
  acquire(&tickslock);
  ticks0 = ticks;
  while(ticks - ticks0 < n){
    if(proc->killed){
      release(&tickslock);
      return -1;
    }
    sleep(&ticks, &tickslock);
  }
  release(&tickslock);
  return 0;
}

// return how many clock tick interrupts have occurred
// since start.
int sys_uptime(void){
  uint xticks;

  acquire(&tickslock);
  xticks = ticks;
  release(&tickslock);
  return xticks;
}

int sys_rrsanity(){
    return 0;
}

int sys_frrsanity(){
    return 0;
}


int sys_printValid(){
    flag = !flag;
    return 0;
}

int sys_gsanity(){
    return 0;
}

int sys_sanitytest(){
    return 0;
}

int sys_nice(){
    if(proc->priority>0)
        proc->priority--;
    return 0;
}
