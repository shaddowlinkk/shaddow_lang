#ifndef COMP_TOKEN
#define COMP_TOKEN
typedef enum _tokenType{
    LOAD,
    TARGET,
    CONNECT,
    LEVELCAP,
    START,
    UNKNOWN
}tokenType;

typedef union _tokenData{
	int* intData;
	char* stringData;
}tokenData;

typedef struct _tokens{
    tokenType type;
    tokenData data[];
}token;

typedef struct _tokenList{
	token *data;
	struct _tokenList *next;
}tokenList;

tokenType getToken(char *string);
void addToken(tokenList **list,token *newp);
#endif
