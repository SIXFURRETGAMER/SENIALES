#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <sys/wait.h>

void pausado(int s)
{printf ("CONTINUO %d\n",s);}

int main()
{
    struct sigaction pausa;

    pausa.sa_handler = pausado;

    sigaction (SIGCONT, &pausa,NULL);

    int pid=getpid();
    printf("Mi pid es:%d\n",pid);
    kill(pid,SIGSTOP);
    printf ("Continua\n");
    kill(pid,SIGKILL);
}