#ifndef COMP_TOKEN
#define COMP_TOKEN
typedef enum _tokenType{
    LOAD,
    TARGET,
    CONNECT,
    LEVELCAP,
    START;
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
	token data;
	tokenList next;
}tokenList;
#endif
