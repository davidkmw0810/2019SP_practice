#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <string.h>

int main(int argc, char *argv[]){
	
	char* point;

	if(argc<2){
		fprintf(stderr,"%s : no arguments\n", argv[0]);
		exit(1);
	}


	for(i=1; i<argc; i++){
		if(mkdir(argv[i], 0777) == -1){
			point = strrchr(argc, '/');
			
		}
	}

}

