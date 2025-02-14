#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <dirent.h>
#include <sys/stat.h>
#include <time.h>

static void do_ls(char *path);

int
main(int argc, char *argv[])
{
    int i;

    if (argc < 2) {
        fprintf(stderr, "%s: no arguments\n", argv[0]);
        exit(1);
    }
    for (i = 1; i < argc; i++) {
        do_ls(argv[i]);
    }
    exit(0);
}

static void
do_ls(char *path)
{
    DIR *d;
    struct dirent *ent;
    struct stat dir;

    d = opendir(path);          /* (1) */
    if (!d) {
        perror(path);
        exit(1);
    }
    while (ent = readdir(d)) {  /* (2) */

	    lstat(ent->d_name, &dir);

        printf("%s\n", ent->d_name);
        printf("uid : %d ", dir.st_uid);
        printf("last mtime : %s\n", ctime(&dir.st_mtime));
    }
    closedir(d);                /* (1') */
}
