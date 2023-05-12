#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
void accion_alarma (int s)
{printf("Señal alarma: %d\n",s);}
void acction_flotante (int s)
{printf("Se recibió un flotante %d \n",s );}
void acction_inte( int s)
{printf ("Se recibio un SEGINT %d \n",s);}
void suar(int s)
{printf ("Se recibio un SIGUSR1 %d\n",s);}
int con=0;
int main ()
{
    int pid=getpid();
    printf("Mi pid es:%d\n",getpid());

    struct sigaction tratamiento_alarma;
    struct sigaction tratamiento_flotante;
    struct sigaction tratamiento_interrup;
    struct sigaction usu1;

    tratamiento_alarma.sa_handler = accion_alarma;
    tratamiento_flotante.sa_handler = acction_flotante;
    tratamiento_interrup.sa_handler = acction_inte;
    usu1.sa_handler = suar;

    sigaction (SIGALRM, &tratamiento_alarma,NULL);
    sigaction(SIGFPE, &tratamiento_flotante,NULL);
    sigaction(SIGINT,&tratamiento_interrup,NULL);
    sigaction(SIGUSR1,&usu1,NULL);

    while (1) {
        printf("Esperando...\n" );
        pause();
        con++;
        if (con==5)
            kill(pid,SIGTERM);
    }


}