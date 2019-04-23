section .data
	;msg db "abcdefdcba",0
	msg db "2002",0
	siMsg db "Si es palindromo",10
	siMsgLen equ $-siMsg
	noMsg db "No es palindromo",10
	noMsgLen equ $-noMsg
	separador db 10

section .bss 
	inverso resb 20

section .text
	global _start

_start:
	mov rax, msg
	mov rbx, 0

cuenta:
	inc rax
	inc rbx
	mov cl, [rax]
	cmp cl, 0
	jne cuenta

;mostramos el mensaje
;realizamos un sys_write
	mov rax, 1
	mov rdi, 1
	mov rsi, msg
	mov rdx, rbx
	syscall

	mov rax, 1
	mov rdi, 1
	mov rsi, separador
	mov rdx, 1
	syscall	

;guardamos los datos en el arreglo inverso
	mov r8, rbx
	mov r9, inverso
	mov rax, msg
	add rax, r8

inversion:
	dec rax
	mov r10, [rax]
	mov [r9], r10
	inc r9
	cmp rax, msg
	jne inversion

	mov r12, 0

bucleComparacion:
	mov r8, msg
	mov r9, inverso
	mov r10, [r8]
	mov r11, [r9]
	cmp r10, r11
	jne noEsPalindromo
	inc r8
	inc r9
	inc r12
	cmp r12, rbx
	jne bucleComparacion

esPalindromo:
	mov rax, 1
	mov rdi, 1
	mov rsi, siMsg
	mov rdx, siMsgLen
	syscall

	jmp salida

noEsPalindromo:
	mov rax, 1
	mov rdi, 1
	mov rsi, noMsg
	mov rdx, noMsgLen
	syscall


;sys_exit
salida:
	mov rax, 60
	mov rdi, 0
	syscall