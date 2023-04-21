.section	.rodata
.LC0:
	.string	"%d\n"
	.text
	.globl	main
main: 
.L0: 
	pushq	 %rbp 
	movq	 %rsp,  %rbp 
	movq	 -8(%rbp),  %r10 
	movq	 $10,  %r10 
	movq	 %r10,  %rax 
	movq	 %r10 , -8(%rbp) 
	movq	 $7,  %r10 
	cqo 
	idivq	 %r10 
	movq	 %rdx , -24(%rbp) 
	imul	 $10,  %rdx 
	movq	 -8(%rbp),  %r10 
	subq	 %rdx,  %r10 
	movq	 %r10,  %rax 
	movq	 %r10 , -48(%rbp) 
	movq	 $5,  %r10 
	cqo 
	idivq	 %r10 
	movq	 -8(%rbp),  %r10 
	shl	 $2,  %r10 
	movq	 %rax , -64(%rbp) 
	movq	 -48(%rbp),  %r11 
	movq	 %r11,  %rax 
	movq	 -8(%rbp),  %r12 
	cqo 
	idivq	 %r12 
	cmp	 $0,  %rdx 
	movq	 -96(%rbp),  %r13 
	movq 	$0,  %r13 
	sete	 %r13b 
	movq	 %r10 , -80(%rbp) 
	movq	 %r13 , -96(%rbp) 
	movq	 -96(%rbp),  %r10 
	cmp	 $0,  %r10 
	je	 .L2 
.L1: 
	movq	 -64(%rbp),  %r11 
	movq	 %r11 , -104(%rbp) 
	jmp	 .L3 
.L2: 
	movq	 -80(%rbp),  %r10 
	movq	 %r10 , -104(%rbp) 
.L3: 
	movq	 -104(%rbp),  %r10 
	movq	 -8(%rbp),  %r11 
	movq	 %r11, %rsi 
	leaq 	.LC0(%rip),  %rdi 
	sub	 $112, %rsp 
	movq	 %r10 , -112(%rbp) 
	call 	printf@PLT 
	add	 $112, %rsp 
	movq	 -24(%rbp),  %r10 
	movq	 %r10, %rsi 
	leaq 	.LC0(%rip),  %rdi 
	sub	 $112, %rsp 
	call 	printf@PLT 
	add	 $112, %rsp 
	movq	 -48(%rbp),  %r10 
	movq	 %r10, %rsi 
	leaq 	.LC0(%rip),  %rdi 
	sub	 $112, %rsp 
	call 	printf@PLT 
	add	 $112, %rsp 
	movq	 -64(%rbp),  %r10 
	movq	 %r10, %rsi 
	leaq 	.LC0(%rip),  %rdi 
	sub	 $112, %rsp 
	call 	printf@PLT 
	add	 $112, %rsp 
	movq	 -80(%rbp),  %r10 
	movq	 %r10, %rsi 
	leaq 	.LC0(%rip),  %rdi 
	sub	 $112, %rsp 
	call 	printf@PLT 
	add	 $112, %rsp 
	movq	 -112(%rbp),  %r10 
	movq	 %r10, %rsi 
	leaq 	.LC0(%rip),  %rdi 
	sub	 $112, %rsp 
	call 	printf@PLT 
	add	 $112, %rsp 
	movq	 $0, %rax 
	popq	 %rbp 
	ret	 
