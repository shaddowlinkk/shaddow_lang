#include "../include/token.h"
#include "../include/util.h"
#include "../include/parser.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

tokenList *start_parser(char* filename){
	char *fileData = get_src(filename);
	char token[255]="";
	tokenList **list=NULL;
	memset(token ,0,255);
	int len = strlen(fileData);
	for(int i=0; i<strlen(fileData);i++){
		if(fileData[i]>31){
			strncat(token,&fileData[i],1);
		}else if(fileData[i]==0x40){
			printf("%s||",token);
			token *new = calloc(sizeof(token));
			new->type= getToken(token);
			(*list)=(list)*&new;
			memset(token,0,255);
		}else if(fileData[i]==0x0a||fileData[i]==0x0d){
			if(fileData[i]==0x0d)
				i++;
			printf("%s=",token);
			printf("%d\n",(*list)->type);
			memset(token ,0,255);
		}
	}
}
