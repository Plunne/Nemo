#include <pthread.h>
#include <stdio.h>

pthread_mutex_t lock;

void delay(int d)
{
    for (int i=0; i < (d * 30000); i++)
    {
        __asm__("nop");
    }
}

void *task_thread1(void *unused)
{
    pthread_mutex_lock(&lock);
    
    for (int i=0; i < 30; i++)
    {
        puts("thread1");
        delay(500);
    }
    
    pthread_mutex_unlock(&lock);
}

void *task_thread2(void *unused)
{
    pthread_mutex_lock(&lock);
    
    for (int i=0; i < 30; i++)
    {
        puts("thread2");
        //delay(500);
    }
    
    pthread_mutex_unlock(&lock);
}

int main(int argc, char **argv)
{
    if (pthread_mutex_init(&lock, NULL) != 0) { 
        printf("\n mutex init has failed\n"); 
        return 1; 
    }
    
    pthread_t thread1;
    pthread_t thread2;
    pthread_create(&thread1, 0, task_thread1, 0);
    pthread_create(&thread2, 0, task_thread2, 0);
    pthread_join(thread1, 0);
    pthread_join(thread2, 0);
    
    pthread_mutex_destroy(&lock);

    return 0;
}
