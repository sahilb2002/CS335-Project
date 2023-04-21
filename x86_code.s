.section	.rodata
.LC0:
	.string	"%d\n"
	.text
	.globl	main
foo: 
.L0: 
	pushq	 %rbp 
	movq	 %rsp,  %rbp 
	movq	 16(%rbp),  %r10 
	cmp	 $0,  %r10 
	movq	 -8(%rbp),  %r11 
	movq 	$0,  %r11 
	sete	 %r11b 
	movq	 %r11 , -8(%rbp) 
	movq	 -8(%rbp),  %r10 
	cmp	 $0,  %r10 
	je	 .L2 
.L1: 
	movq	 $1, %rax 
	popq	 %rbp 
	ret	 
.L2: 
	movq	 16(%rbp),  %r10 
	subq	 $1,  %r10 
	sub	 $24,  %rsp 
	pushq	 %r10 
	call	 foo 
	add	 $32,  %rsp 
	movq	 16(%rbp),  %r10 
	addq	 %rax,  %r10 
	movq	 %r10 , -32(%rbp) 
	movq	 -32(%rbp),  %r10 
	movq	 %r10, %rax 
	popq	 %rbp 
	ret	 
	movq	 $0, %rax 
	popq	 %rbp 
	ret	 
main: 
.L3: 
	pushq	 %rbp 
	movq	 %rsp,  %rbp 
	sub	 $8,  %rsp 
	movq	 $2, %rax 
	pushq	 %rax 
	call	 foo 
	add	 $16,  %rsp 
	movq	 -24(%rbp),  %r10 
	movq	 $0,  %r10 
	movq	 %r10 , -24(%rbp) 
	movq	 %rax , -16(%rbp) 
.L4: 
	movq	 -24(%rbp),  %r10 
	cmp	 $10,  %r10 
	movq	 -32(%rbp),  %r11 
	movq 	$0,  %r11 
	setl	 %r11b 
	movq	 %r11 , -32(%rbp) 
	movq	 -32(%rbp),  %r10 
	cmp	 $0,  %r10 
	je	 .L8 
.L5: 
	jmp	 .L7 
.L6: 
	movq	 -24(%rbp),  %r10 
	movq	 %r10 , -40(%rbp) 
	addq	 $1,  %r10 
	movq	 %r10 , -24(%rbp) 
	jmp	 .L4 
.L7: 
	movq	 -16(%rbp),  %r10 
	addq	 $1,  %r10 
	movq	 %r10, %rsi 
	leaq 	.LC0(%rip),  %rdi 
	sub	 $48, %rsp 
	movq	 %r10 , -16(%rbp) 
	call 	printf@PLT 
	add	 $48, %rsp 
	jmp	 .L6 
.L8: 
	movq	 $0, %rax 
	popq	 %rbp 
	ret	 
