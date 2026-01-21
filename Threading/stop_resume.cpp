#include<iostream>
#include<cstdlib>
#include<signal.h>
#include<unistd.h>

void sigint_handler(int signum)
{
    puts("Ctrl + C received.Bye");
    exit(EXIT_SUCCESS);
}


int main(void)
{
    pid_t pid;

    signal(SIGINT, sigint_handler);

    pid = fork();
    if(pid == 0)
    {
        signal(SIGINT, sigint_handler);
        while(true)
        {
            puts("CHILD:doing my work");
        }
    }else{
        while(true)
        {
            kill(pid, SIGTSTP);
            sleep(rand()%3);
            kill(pid, SIGCONT);
            sleep(rand()%4);
        }
    }

    return 0;
}