	EXPORT	Add
	
	AREA	Addc,CODE,READONLY
	ENTRY
	CODE32
	
Add
	ADD		R0,R0,R1
	ADD		R0,R2,R3
	MOV		PC,LR
	
	END
