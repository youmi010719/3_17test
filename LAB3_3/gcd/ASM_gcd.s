; ASM_gcd.s
	EXPORT asmfile
	AREA My_pro, CODE, READONLY
asmfile
	mov r0,#256
	mov r1,#64	
start
	cmp r0 , r1		;�Ƚ�R0��R1�Ĵ�С
	beq stop			;��Ⱦ��˳�
	cmp r0,r1		
	bge loop		
	sub r1,r1,r0
	b start
loop
	sub r0,r0,r1
	b start
stop
	b  stop 
	mov pc, lr
	end
