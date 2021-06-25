
// Created by nathan on 6/18/2021.
//
#include "../include/token.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

tokenType getToken(char *string){
	if(strcmp(string,"load")==0){
		return LOAD;
	}else{
		return UNKNOWN;
	}		
}
tokenList *newNode(token *newp){
	tokenList *nnode;
	nnode = (tokenList *) malloc(sizeof(tokenList));
	nnode->data=newp;
	nnode->next=NULL;
}

void addToken(tokenList **list,token *newp){
	tokenList **tracer = list;
	while(*tracer){
		tracer =&(*tracer)->next;
	}
	*tracer = newNode(newp);
}
