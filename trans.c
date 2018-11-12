#include "myas.h"

int instr_trans(char *op, char *args, char* mcode)
{
	
	char *source, *destination;
	
	if(!is_valid(op, args)){
		printf("Error: %s %s is not valid\n", op, args);
		return 0;
	}

	source = strtok(args,",");
	destination = strtok(NULL,"\n");

	if(source[0]=='%'&&destination[0]=='%') // reg to reg
		strcpy(mcode,"89");
	if(source[0]=='('&&destination[0]=='%') // mem to reg( addressing w.o/ disp)
		strcpy(mcode,"8b");
	if(source[0]=='-'&&destination[0]=='%') // mem to reg( addressing w/ disp)
		strcpy(mcode,"8b"); 
	if(source[0]=='0'&&destination[0]=='%') // mem to reg(eax)
		strcpy(mcode,"a1");
	if(source[0]=='%'&&destination[0]=='0') // reg(eax) to mem
		strcpy(mcode,"a3");
	if(source[0]=='$'&&destination[0]=='%') // immediate to reg
		strcpy(mcode,"b8");


	return 1;	
}
