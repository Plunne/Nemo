#include <pthread.h>
#include <stdio.h>

void delay(int d)
{
    for (int i=0; i < (d * 30000); i++)
    {
        __asm__("nop");
    }
}

void *task_thread1(void *unused)
{
    for (int i=0; i < 4; i++)
    {
        puts("thread1");
        delay(500);
    }
}

void *task_thread2(void *unused)
{
    for (int i=0; i < 4; i++)
    {
        puts("thread2");
        delay(500);
    }
}

int main(int argc, char **argv)
{
    pthread_t thread1;
    pthread_t thread2; 
    pthread_create(&thread1, 0, task_thread1, 0);
    pthread_create(&thread2, 0, task_thread2, 0);
    pthread_join(thread1, 0);
    pthread_join(thread2, 0);

    return 0;
}

/* Avec les delay */
// Ordre aleatoire jusqu'a ce que les deux terminent leur job

/* Sans les delay */
// Le premier thread cree a deja eu le temps de finir avant meme que le second commence.
// Resultat :
// 4x thread1
// 4x thread2

/* Avec delay mais boucles 10x plus grandes pour les deux */
// Le premier thread va afficher autant de fois qu'il le peut avant le lancement du deuxieme.
// Le deuxieme va afficher autant de fois qu'il le peut avant que le premier reprenne la main.
// Cela ainsi de suite en alternant jusqu'a ce que le premier finisse son execution.
// Le deuxieme finit tout seul par la suite.

/* Sans delay mais boucles 10x plus grand uniquement pour le premier */
// Le premier thread va afficher autant de fois qu'il le peut avant le lancement du deuxieme.
// Le deuxieme va afficher et aura eu le temps de se finir.
// Le premier finit tout seul par la suite.

/* Sans delay mais boucles 10x plus grand uniquement pour le deuxieme */
// Le premier thread va afficher et aura eu le temps de se finir avant le lancement du deuxieme.
// Le deuxime se deroule tout seul seul d'une traite par la suite.
