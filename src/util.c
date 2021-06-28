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
void get_iniData(char *Title,char *prop,char *filename, char *buff){
    FILE *dinoData = fopen(filename,"r");
    char line[1025],*eqPtr;
    char cTitle[64];
    sprintf(cTitle,"[%s]",Title);
    int foundTitle;
    while (fgets(line,1025,dinoData)!=0){
        if(strncmp(line,"//",2)==0) continue;
        if(line[0]=='#') continue;
        eqPtr = strchr(line,'=');
        if(eqPtr!=NULL&&foundTitle==1){
            if(strncmp(line,prop,strlen(prop))==0){
                fclose(dinoData);
                while (*(eqPtr+1)==' '){
                    eqPtr++;
                }
                strcpy(buff,eqPtr);
            }else{
                if(strncmp(cTitle,line, strlen(cTitle))){
                    foundTitle =1;
                }
            }
        }
    }
    fclose(dinoData);
}
