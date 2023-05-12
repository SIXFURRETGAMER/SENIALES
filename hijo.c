#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int val=10;

void sum(int s)
{val=val+5;}

int main()
{
    int pid=0;
    struct sigaction nino;
    nino.sa_handler=sum;
    sigaction(SIGCHLD,&nino,NULL);
    pid=fork();
    if (pid==0)
    {
        val=val-3;
        printf ("val=%d\n",val);

        return 0;
    }
    waitpid(pid,NULL,0);
    printf ("val=%d\n",val);
    return 0;
}