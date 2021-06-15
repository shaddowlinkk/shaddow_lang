#include "../include/util.h"

char *get_src(char *filename){
	//open file
	FILE *src = fopen(filename ,"r");
	
	//get file size
	fseek(src,0,SEEK_END);
	int size = ftell(src);
	fseek(src,0,SEEK_SET);
	
	
	//read the data
	char *buf =(char *) malloc(sizeof(char)*(size+1));
	fread(buf,1,size,src);
	buf[size+1]='\0';
	fclose(src);
	
	//return
	return buf;
}
