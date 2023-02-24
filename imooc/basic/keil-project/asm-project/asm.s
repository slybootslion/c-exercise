.global _start
	
_start:
	mov r0,#0
	mov r1,#1
loop:
	add r0,r0,r1
	add r1,r1,#1
	cmp r1,#100
	ble loop
	
stop:
	b stop
	