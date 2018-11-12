#include "myas.h"

extern int is_valid(char *op, char *args);

int instr_trans(char *op, char *args, char* mcode)
{
	
	char *source, *destination;
	char tmp[256];
	if(!is_valid(op, args)){
		printf("Error: %s %s is not valid\n", op, args);
		strcpy(mcode,"Error");
		return 0;
	}
	strcpy(tmp,args);
	source = strtok(tmp,",");
	destination = strtok(NULL,"\n");

	if(source[0]=='%'&&destination[0]=='%') // reg to reg
		strcpy(mcode,"89");

	else if(source[0]=='('&&destination[0]=='%') // mem to reg( addressing w.o/ disp)
		strcpy(mcode,"8b");

	else if(source[0]=='-'&&destination[0]=='%') // mem to reg( addressing w/ disp)
		strcpy(mcode,"8b"); 

	else if(source[0]=='0'&&destination[0]=='%') // mem to reg(eax)
		strcpy(mcode,"a1");

	else if(source[0]=='%'&&destination[0]=='0') // reg(eax) to mem
		strcpy(mcode,"a3");

	else if(source[0]=='$'&&destination[0]=='%'){// immediate to reg
		if(destination[2]=='c')
			strcpy(mcode,"b9");
		else if(destination[2]=='d')
			strcpy(mcode,"ba");
		else
			strcpy(mcode,"b8");
	}
	else

			strcpy(mcode,"error");


	return 1;	
}
