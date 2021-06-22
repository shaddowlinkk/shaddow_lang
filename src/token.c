
// Created by nathan on 6/18/2021.
//
#include "../include/token.h"
#include <string.h>

tokenType getToken(char *string){
	if(strcmp(string,"load")==0){
		return LOAD;
	}else{
		return UNKNOWN;
	}		
}
