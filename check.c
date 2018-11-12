#include "myas.h"

int is_valid(char *op, char *args)
{
	char *source,*destination;
	char tmp[256];
	if(strcmp(op,"mov")!=0)  //if instruction is not move
		return 0;

	strcpy(tmp,args);
	source = strtok(tmp,","); //divide with ',' 
	destination = strtok(NULL, "\n");

	if(source[0]=='('&&destination[0]=='(') //if source, destination is memory
		return 0;
	else if(source[0]=='$'&&destination[0]=='$') //if source, destination is immediate
		return 0;
	else if(destination[0]=='$') // if destination is immediate
		return 0;
	else
		return 1;
}
