//
// Created by nathan on 6/29/2021.
//
#include <string.h>
#include "../include/actions.h"
int loadAction(char *dirpath,char **fileNames){
    if(strchr(dirpath,'.')!=NULL){
        (*fileNames)=dirpath;
        return 3100;
    }
    return -1;
}
