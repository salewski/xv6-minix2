#include <sys/types.h>
#include <signal.h>
#include <setjmp.h>


// xv6 has no signals

sighandler_t signal(int sig, sighandler_t func)
{
 return(SIG_DFL);
}

void longjmp(jmp_buf env, int val)
{
  return;
}

int setjmp(jmp_buf env)
{
  return(0);
}
