#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/util.h"
#include "../include/parser.h"
#include "../include/actions.h"

int main(int argc, char**argv){
	if(argc <2){
		printf("not enough args");
		return 1;
	}
	if(strcmp(argv[1],"cat")==0){
	if(!(argc<3)) return 21;
		char *buf =get_src(argv[2]);
		printf(buf);
	}
	if(strcmp(argv[1],"test")==0){
	if((argc>3)) return 21;
		start_parser(argv[2]);
		return 10;	
	}
	if(strcmp(argv[1],"INITesting")==0){
		char buff[64];
		get_iniData("tesing","test","test.ini",buff);
		printf("%s",buff);
		return 11;
	}
	if(strcmp(argv[1],"actionTesting")==0){
		char **dirbuff;
		printf("loadActionReturn:%d\n",loadAction("test.ini",dirbuff));
		printf("dirBuffData:%s\n",*dirbuff);
		return 12;
	}
}
