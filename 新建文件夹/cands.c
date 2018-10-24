#include <stdio.h>

void my_strcpy(char * src, const char* dst){
	int ch;
	__asm{
loop:
						LDRB ch,[src],#1
						STRB ch,[dst],#1
						CMP ch,#0
						BNE loop
	};
}
int main(){
	const char* a="HelloWorld!";
	char b[20];
	__asm{
				MOV R0,a
				MOV R1,b
				BL	my_strcpy,{R0,R1}
	};
	printf("Original String:%s\n", a);
	printf("Copied String:%s\n", b);
	return 0;
}