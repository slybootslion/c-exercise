.global _start
	
@0x40000000,0x4000FFFF
_start:
	mov r0,#2
	mov r1,#3
	ldr sp,=0x4000FFF0
	bl add
	
stop:
	b stop
	