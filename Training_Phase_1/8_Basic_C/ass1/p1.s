	.file	"p1.c"
	.section	.rodata
.LC0:
	.string	"Enter the centimeter value :"
.LC1:
	.string	"%f"
	.align 8
.LC4:
	.string	"\n%.2f centimeters = %dfeets %.1finches\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB0:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	movl	$.LC0, %edi
	call	puts
	leaq	-24(%rbp), %rax
	movq	%rax, %rsi
	movl	$.LC1, %edi
	movl	$0, %eax
	call	__isoc99_scanf
	movss	-24(%rbp), %xmm0
	cvtss2sd	%xmm0, %xmm0
	movsd	.LC2(%rip), %xmm1
	divsd	%xmm1, %xmm0
	cvtsd2ss	%xmm0, %xmm2
	movss	%xmm2, -20(%rbp)
	movss	-20(%rbp), %xmm0
	cvttss2si	%xmm0, %eax
	movl	%eax, -16(%rbp)
	pxor	%xmm0, %xmm0
	cvtsi2ss	-16(%rbp), %xmm0
	movss	-20(%rbp), %xmm1
	subss	%xmm0, %xmm1
	movaps	%xmm1, %xmm0
	movss	.LC3(%rip), %xmm1
	mulss	%xmm1, %xmm0
	movss	%xmm0, -12(%rbp)
	cvtss2sd	-12(%rbp), %xmm1
	movss	-24(%rbp), %xmm0
	cvtss2sd	%xmm0, %xmm0
	movl	-16(%rbp), %eax
	movl	%eax, %esi
	movl	$.LC4, %edi
	movl	$2, %eax
	call	printf
	movl	$0, %eax
	movq	-8(%rbp), %rdx
	xorq	%fs:40, %rdx
	je	.L3
	call	__stack_chk_fail
.L3:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.section	.rodata
	.align 8
.LC2:
	.long	1202590843
	.long	1077836513
	.align 4
.LC3:
	.long	1094713344
	.ident	"GCC: (Ubuntu 5.4.0-6ubuntu1~16.04.4) 5.4.0 20160609"
	.section	.note.GNU-stack,"",@progbits
