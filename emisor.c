#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

int main ()
{
    while (1) {
        sleep(2);
        kill(5166,SIGFPE);
        kill(5166,SIGALRM);
        kill(5166,SIGINT);
        kill(5166,SIGUSR1);
        printf("Envié dos señales \n");
    }
}