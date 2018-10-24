;文件名：TEST1.s
;功能：实现两个寄存器相加

			AREA	Example1,CODE,READONLY	;声明代码段Example1
SWI_A	EQU	&1
SWI_B	EQU &11
	
			ENTRY
			
			CODE32
			
START	MOV		R0,#0
			MOV		R1,#10
			
LOOP	BL		ADD_SUB
			B			LOOP
	
ADD_SUB
			ADDS	R0,R0,R1
			BX		LR
			END