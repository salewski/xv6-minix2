// init: The initial user-level program

#include <xv6/types.h>
#include <xv6/stat.h>
#include <xv6/user.h>
#include <xv6/fcntl.h>

char *argv[] = { "sh", 0 };

int
main(void)
{
  int pid, wpid;

  if(open("/dev/console", O_RDWR) < 0){
    mknod("/dev/console", 1, 1);
    open("/dev/console", O_RDWR);
  }
  dup(0);  // stdout
  dup(0);  // stderr

  for(;;){
    printf(1, "init: starting /bin/sh\n");
    pid = fork();
    if(pid < 0){
      printf(1, "init: fork failed\n");
      exit();
    }
    if(pid == 0){
      exec("/bin/sh", argv);
      printf(1, "init: exec /bin/sh failed\n");
      exit();
    }
    while((wpid=wait()) >= 0 && wpid != pid)
      printf(1, "zombie!\n");
  }
}
