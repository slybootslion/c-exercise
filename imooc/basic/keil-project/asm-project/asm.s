.global _start
	
_start:
	mov r0,#3
	mov r1,#5
	mul r2,r0,r1
	mov r1,#25
	sub r2,r1,r2
	add r2,r2,#6
stop:
	b stop
	