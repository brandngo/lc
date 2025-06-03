#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

volatile int g_var = 20;

int main(int argc, char **argv)
{
    int state = 0;
    pid_t pid;

    for (int i = 1; i < 3; i++) {
        pid = fork();
        sleep(1);
        if (pid > 0) {
            g_var++;
            printf("P: i=%d, g_var=%d\n", i, g_var);
            waitpid(pid, &state, 0);
        } else if (pid == 0) {
            printf("C: i=%d, g_var=%d\n", i, g_var);
            if (g_var > 20) {
                g_var += 2;
            } else {
                g_var -= 2;
            }
        } else {
            perror("fork");
        }
    }
    return 0;
}