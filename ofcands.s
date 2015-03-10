	.file	"ofcands.cpp"
	.text
	.p2align 4,,15
	.globl	_Z4dumpv
	.type	_Z4dumpv, @function
_Z4dumpv:
.LFB57:
	.cfi_startproc
	rep
	ret
	.cfi_endproc
.LFE57:
	.size	_Z4dumpv, .-_Z4dumpv
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC0:
	.string	"%d"
.LC1:
	.string	"Case %d:\n"
.LC2:
	.string	"%d %d"
.LC3:
	.string	"%6s %d %d %d %d %d %d"
.LC4:
	.string	"(%d, %d, %d)\n"
	.section	.text.startup,"ax",@progbits
	.p2align 4,,15
	.globl	main
	.type	main, @function
main:
.LFB58:
	.cfi_startproc
	pushq	%r12
	.cfi_def_cfa_offset 16
	.cfi_offset 12, -16
	movl	$num_cases, %esi
	movl	$.LC0, %edi
	xorl	%eax, %eax
	xorl	%r12d, %r12d
	pushq	%rbp
	.cfi_def_cfa_offset 24
	.cfi_offset 6, -24
	pushq	%rbx
	.cfi_def_cfa_offset 32
	.cfi_offset 3, -32
	subq	$32, %rsp
	.cfi_def_cfa_offset 64
	call	scanf
	movl	num_cases(%rip), %eax
.L31:
	leal	-1(%rax), %edx
	testl	%eax, %eax
	movl	%edx, num_cases(%rip)
	jle	.L35
.L20:
	addl	$1, %r12d
	movl	$.LC1, %esi
	movl	$1, %edi
	movl	%r12d, %edx
	xorl	%eax, %eax
	call	__printf_chk
	xorl	%eax, %eax
	movl	$num_queries, %edx
	movl	$num_shapes, %esi
	movl	$.LC2, %edi
	call	scanf
	movl	num_shapes(%rip), %eax
	testl	%eax, %eax
	jle	.L4
	movl	$shapes, %ebx
	xorl	%ebp, %ebp
	.p2align 4,,10
	.p2align 3
.L5:
	movslq	%ebp, %rax
	addl	$1, %ebp
	leaq	(%rax,%rax,4), %rdx
	leaq	(%rax,%rdx,2), %rdx
	salq	$2, %rdx
	leaq	shapes+16(%rdx), %rax
	addq	$shapes, %rdx
	leaq	4(%rdx), %rcx
	leaq	12(%rdx), %rsi
	leaq	8(%rdx), %r8
	leaq	12(%rax), %rdi
	leaq	4(%rax), %r9
	movq	%rdi, 8(%rsp)
	leaq	8(%rax), %rdi
	xorl	%eax, %eax
	movq	%rdi, (%rsp)
	movl	$.LC3, %edi
	call	scanf
	movl	8(%rbx), %eax
	movl	(%rbx), %edx
	addl	%eax, %edx
	addl	4(%rbx), %eax
	movl	%edx, 36(%rbx)
	movl	%eax, 40(%rbx)
	addq	$44, %rbx
	cmpl	%ebp, num_shapes(%rip)
	jg	.L5
	.p2align 4,,10
	.p2align 3
.L4:
	movl	num_queries(%rip), %eax
	leal	-1(%rax), %edx
	testl	%eax, %eax
	movl	%edx, num_queries(%rip)
	jle	.L6
	leaq	28(%rsp), %rdx
	leaq	24(%rsp), %rsi
	xorl	%eax, %eax
	movl	$.LC2, %edi
	call	scanf
	movl	num_shapes(%rip), %edx
	testl	%edx, %edx
	jle	.L21
	subl	$1, %edx
	movl	24(%rsp), %r11d
	movl	28(%rsp), %ebx
	leaq	(%rdx,%rdx,4), %rcx
	movl	$shapes+12, %eax
	xorl	%edi, %edi
	xorl	%r8d, %r8d
	xorl	%esi, %esi
	leaq	(%rdx,%rcx,2), %rdx
	xorl	%ecx, %ecx
	leaq	shapes+56(,%rdx,4), %rbp
	jmp	.L16
	.p2align 4,,10
	.p2align 3
.L8:
	movl	-12(%rax), %r9d
	movl	-8(%rax), %edx
	movl	-4(%rax), %r10d
	subl	%r11d, %r9d
	subl	%ebx, %edx
	imull	%r9d, %r9d
	imull	%edx, %edx
	imull	%r10d, %r10d
	addl	%r9d, %edx
	cmpl	%r10d, %edx
	je	.L24
	jge	.L15
.L32:
	addl	8(%rax), %esi
	addl	12(%rax), %ecx
	addl	$1, %edi
	addl	16(%rax), %r8d
.L15:
	addq	$44, %rax
	cmpq	%rbp, %rax
	je	.L36
.L16:
	cmpb	$83, (%rax)
	jne	.L8
	movl	-12(%rax), %edx
	cmpl	%r11d, %edx
	je	.L9
	cmpl	24(%rax), %r11d
	je	.L9
	movl	-8(%rax), %r9d
.L10:
	cmpl	%r9d, %ebx
	je	.L13
.L11:
	cmpl	%ebx, 28(%rax)
	je	.L13
.L14:
	cmpl	%r11d, %edx
	jge	.L15
	cmpl	%r9d, %ebx
	.p2align 4,,2
	jle	.L15
	cmpl	24(%rax), %r11d
	jge	.L15
	cmpl	28(%rax), %ebx
	jl	.L32
	addq	$44, %rax
	cmpq	%rbp, %rax
	jne	.L16
	.p2align 4,,10
	.p2align 3
.L36:
	testl	%edi, %edi
	movl	$1, %eax
	jne	.L37
.L17:
	movl	$255, %edx
	testb	%al, %al
	cmovne	%edx, %r8d
	cmovne	%edx, %ecx
	cmovne	%edx, %esi
	jmp	.L7
	.p2align 4,,10
	.p2align 3
.L9:
	movl	-8(%rax), %r9d
	cmpl	%ebx, %r9d
	jg	.L11
	cmpl	%ebx, 28(%rax)
	jl	.L10
	.p2align 4,,10
	.p2align 3
.L24:
	xorl	%eax, %eax
	xorl	%r8d, %r8d
	xorl	%ecx, %ecx
	xorl	%esi, %esi
	testl	%edi, %edi
	je	.L17
.L37:
	leal	(%rdi,%rsi,2), %esi
	leal	(%rdi,%rdi), %r9d
	leal	(%rdi,%rcx,2), %ecx
	leal	(%rdi,%r8,2), %r8d
	movl	%esi, %edx
	movl	%esi, %eax
	sarl	$31, %edx
	idivl	%r9d
	movl	%ecx, %edx
	sarl	$31, %edx
	movl	%eax, %esi
	movl	%ecx, %eax
	idivl	%r9d
	movl	%r8d, %edx
	sarl	$31, %edx
	movl	%eax, %ecx
	movl	%r8d, %eax
	idivl	%r9d
	movl	%eax, %r8d
.L7:
	movl	%esi, %edx
	movl	$1, %edi
	movl	$.LC4, %esi
	xorl	%eax, %eax
	call	__printf_chk
	jmp	.L4
	.p2align 4,,10
	.p2align 3
.L13:
	cmpl	%r11d, %edx
	jg	.L15
	cmpl	24(%rax), %r11d
	.p2align 4,,4
	jg	.L14
	.p2align 4,,4
	jmp	.L24
.L6:
	movl	num_cases(%rip), %eax
	testl	%eax, %eax
	jle	.L31
	movq	stdout(%rip), %rsi
	movl	$10, %edi
	call	fputc
	movl	num_cases(%rip), %eax
	leal	-1(%rax), %edx
	testl	%eax, %eax
	movl	%edx, num_cases(%rip)
	jg	.L20
.L35:
	addq	$32, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 32
	xorl	%eax, %eax
	popq	%rbx
	.cfi_def_cfa_offset 24
	popq	%rbp
	.cfi_def_cfa_offset 16
	popq	%r12
	.cfi_def_cfa_offset 8
	ret
.L21:
	.cfi_restore_state
	movl	$255, %r8d
	movl	$255, %ecx
	movl	$255, %esi
	jmp	.L7
	.cfi_endproc
.LFE58:
	.size	main, .-main
	.globl	shapes
	.bss
	.align 32
	.type	shapes, @object
	.size	shapes, 4488
shapes:
	.zero	4488
	.globl	num_queries
	.align 4
	.type	num_queries, @object
	.size	num_queries, 4
num_queries:
	.zero	4
	.globl	num_shapes
	.align 4
	.type	num_shapes, @object
	.size	num_shapes, 4
num_shapes:
	.zero	4
	.globl	num_cases
	.align 4
	.type	num_cases, @object
	.size	num_cases, 4
num_cases:
	.zero	4
	.ident	"GCC: (Ubuntu/Linaro 4.6.1-9ubuntu3) 4.6.1"
	.section	.note.GNU-stack,"",@progbits
