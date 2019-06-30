#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(void) {
    // make 2 pipe
    int fd1[2]; // child's read[0] child's write[1]
	int fd2[2]; // parent's read[0] parent's write[1]
    pid_t pid;
    char buf1[257];
	char buf2[257];
    int len, status;

    if (pipe(fd1) == -1) {
        perror("pipe");
        exit(1);
    }
    
	if (pipe(fd2) == -1) {
        perror("pipe");
        exit(1);
    }

    switch (pid = fork()) {
        case -1 :
            perror("fork");
            exit(1);
            break;
        case 0 : /* child */
            close(fd2[0]);
			close(fd2[1]);

            write(fd1[1], "Hello Parent!\n", 15);
			sleep(3);
			buf2[0] = '\0';
			len = read(fd1[0], buf2, 256);
			printf("C read : %d\n", len);
            write(1, buf2, len);

			close(fd1[0]);
			close(fd1[1]);
			break;
        default :
            close(fd1[0]);
            close(fd1[1]);
            
			printf("P write : %ld\n", write(fd2[1], "Hello Child!\n", 14));
			sleep(1);
            buf1[0] = '\0';
			len = read(fd2[0], buf1, 256);
			write(1, buf1, len);

            close(fd2[0]);
			close(fd2[1]);
			waitpid(pid, &status, 0);
			break;
    }

    return 0;
}
