#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/util.h"

int main(int argc, char**argv){
	if(argc <3){
		printf("not anuf args");
		return 1;
	}
	if(strcmp(argv[1],"cat")==0){
		char *buf =get_src(argv[2]);
		printf(buf);
	}
}