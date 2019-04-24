global asmAverage
section .text

asmAverage:
	xorpd xmm0, xmm0
	cvtsi2ss xmm2, rsi
	cmp rsi, 0
	je fin

loop:
	movss xmm1, [rdi]
	addss xmm0, xmm1
	add rdi, 4
	sub rsi, 1
	jnz loop

	divss xmm0, xmm2

fin:
	movss [rdx], xmm0
	ret