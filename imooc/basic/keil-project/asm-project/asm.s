.global _start
	
@0x40000000,0x4000FFFF
_start:
	mov r0,#0x40000000
	mov r1,#1
	mov r2,#10
	bl write_data
	
	mov r0,#0x40000000
	ldr r1,=0x40000100
	mov r2,#10
	bl copy_data
	
stop:
	b stop
	
write_data:
	str r1,[r0],#4
	add r1,r1,#1
	cmp r1,r2
	ble write_data
	mov pc,lr
	
copy_data:
	ldr r3,[r0],#4
	str r3,[r1],#4
	sub r2,r2,#1
	cmp r2,#0
	bgt copy_data
	mov pc,lr
	
	
	
	
	
	