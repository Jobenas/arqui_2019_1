section .data
	message db "Hello World",10

section .text
	global _start

_start:
;primera llamada al sistema
	mov rsi, message
	mov rax, 1
	mov rdi, 1
	mov rdx, 12
	syscall

;segunda llamada al sistema
	mov rax, 60
	mov rdi, 0
	syscall