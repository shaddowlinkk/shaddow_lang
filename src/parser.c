#include "../include/token.h"
#include "../include/util.h"
#include "../include/parser.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

tokenList *start_parser(char* filename){
	char *fileData = get_src(filename);
	char tokenData[255]="";
	tokenList *list=NULL;
	memset(tokenData ,0,255);
	int len = strlen(fileData);
	for(int i=0; i<strlen(fileData);i++){
		if(fileData[i]>32){
			strncat(tokenData,&fileData[i],1);
		}else if(fileData[i]==0x20){
			printf("%s||",tokenData);
			token newp;
			newp.type= getToken(tokenData);
			addToken(&list,&newp);
			memset(tokenData,0,255);
		}else if(fileData[i]==0x0a||fileData[i]==0x0d){
			if(fileData[i]==0x0d)
				i++;
			printf("%s=",tokenData);
			printf("%d\n",(list)->data->type);
			memset(tokenData ,0,255);
		}
	}
}
