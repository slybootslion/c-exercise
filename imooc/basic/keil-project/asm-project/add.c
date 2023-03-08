int add (int a, int b){
	int c;
	asm(
		"add r0,%1,%2\n"
		"mov %0,r0\n"
		:"=r"(c)
		:"r"(a),"r"(b)
		:"r0"
	);
	return c;
}