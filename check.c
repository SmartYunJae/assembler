#include "myas.h"

int is_valid(char *op, char *args)
{
	char *source,*destination;
	char tmp[256];
	if(strcmp(op,"mov")!=0)  //if instruction is not move
		return 0;

	strcpy(tmp,args);
	source = strtok(tmp,","); //divide with ','symbol
	destination = strtok(NULL, "\n");
	//invalid pattern
	if(source[0]=='('&&destination[0]=='(') //mem to mem
		return 0;
	else if(source[0]=='$'&&destination[0]=='$') //immediate to immediate
		return 0;
	else if(destination[0]=='$') // destination has immediate value
		return 0;
	else
		return 1;
}
