#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int
main(void)
{
        pid_t pid;

        pid = fork();
        if (!pid) {
                char *const argv[] = { "date", NULL };
                int ret;

                ret = execv("/bin/date", argv);

		printf("Merhaba-1\n");
                if (ret == -1) {
                        perror("execv");
                        exit(EXIT_FAILURE);
                }
        } else if (pid == -1) {
                perror("fork");
                exit(EXIT_FAILURE);
        }

	printf("Merhaba-2\n");

        return EXIT_SUCCESS;
}

