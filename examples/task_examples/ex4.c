#include <stdio.h>
#include <stdlib.h>
#define CHUNK 200

struct myString{
	int size;
	char* data;
};
typedef struct myString Struct;

Struct readinput()
{
	
	char* input = NULL;
	char tempbuf[CHUNK];
	size_t inputlen = 0, templen = 0;
	do {
		fgets(tempbuf, CHUNK, stdin);
		templen = strlen(tempbuf);
		input = realloc(input, inputlen+templen);
		strcpy(input+inputlen, tempbuf);
		inputlen += templen;
	} while (templen==CHUNK-1 && tempbuf[CHUNK-2]!='\n');

	Struct out;
	out.size = inputlen - 1;
	out.data = input;
	
	return out;
}

int main(void){

	
    Struct myStr = readinput();
    int flag = 0;

    for(int i = 0; i < myStr.size; i ++)
    	if ( myStr.data[i] != myStr.data[myStr.size - i - 1]){
    		flag = 1;
    		break;
    	}

    if(flag == 0){
    	printf("POLYNDROM!\n");
    }

	
}
