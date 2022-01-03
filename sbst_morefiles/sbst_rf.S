	.section .text
	.global _sbst_rf
	.type _sbst_rf, @function

_sbst_rf:
	
	or		x17, zero, x1		# saving return address
	or		x19, zero, x2		# saving stack pointer
	xor		x18, x18, x18		# result 
	la		x16, RF_PATTERNS

	p.lw		x1,  0(x16!)
	p.lw 		x2,  0(x16!)
	p.lw 		x3,  0(x16!)
	p.lw 		x4,  0(x16!)
	p.lw 		x5,  4(x16!)
	p.lw 		x6,  0(x16!)
	p.lw 		x7,  0(x16!)
	p.lw 		x8,  0(x16!)
	p.lw 		x9,  0(x16!)
	p.lw 		x10, 4(x16!)
	p.lw 		x11, 0(x16!)
	p.lw 		x12, 0(x16!)
	p.lw 		x13, 0(x16!)
	p.lw 		x14, 0(x16!)
	p.lw 		x15, 0(x16!)
	xor		x18, x1,  x18
	xor		x18, x2,  x18
	xor		x18, x3,  x18
	xor		x18, x4,  x18
	xor		x18, x5,  x18
	xor		x18, x6,  x18
	xor		x18, x7,  x18
	xor		x18, x8,  x18
	xor		x18, x9,  x18
	xor		x18, x10, x18
	xor		x18, x11, x18
	xor		x18, x12, x18
	xor		x18, x13, x18
	xor		x18, x14, x18
	xor		x18, x15, x18
	sw		x1,  4(x19)
	sw		x2,  4(x19)
	sw		x3,  4(x19)
	sw		x4,  4(x19)
	sw		x5,  4(x19)
	sw		x6,  4(x19)
	sw		x7,  4(x19)
	sw		x8,  4(x19)
	sw		x9,  4(x19)
	sw		x10, 4(x19)
	sw		x11, 4(x19)
	sw		x12, 4(x19)
	sw		x13, 4(x19)
	sw		x14, 4(x19)
	sw		x15, 4(x19)
	xori		x1,  x1,  -1
	xori		x2,  x2,  -1
	xori		x3,  x3,  -1
	xori		x4,  x4,  -1
	xori		x5,  x5,  -1
	xori		x6,  x6,  -1
	xori		x7,  x7,  -1
	xori		x8,  x8,  -1
	xori		x9,  x9,  -1
	xori		x10, x10, -1
	xori		x11, x11, -1
	xori		x12, x12, -1
	xori		x13, x13, -1
	xori		x14, x14, -1
	xori		x15, x15, -1
	xor		x18, x1,  x18
	xor		x18, x2,  x18
	xor		x18, x3,  x18
	xor		x18, x4,  x18
	xor		x18, x5,  x18
	xor		x18, x6,  x18
	xor		x18, x7,  x18
	xor		x18, x8,  x18
	xor		x18, x9,  x18
	xor		x18, x10, x18
	xor		x18, x11, x18
	xor		x18, x12, x18
	xor		x18, x13, x18
	xor		x18, x14, x18
	xor		x18, x15, x18
	sw		x1,  4(x19)
	sw		x2,  4(x19)
	sw		x3,  4(x19)
	sw		x4,  4(x19)
	sw		x5,  4(x19)
	sw		x6,  4(x19)
	sw		x7,  4(x19)
	sw		x8,  4(x19)
	sw		x9,  4(x19)
	sw		x10, 4(x19)
	sw		x11, 4(x19)
	sw		x12, 4(x19)
	sw		x13, 4(x19)
	sw		x14, 4(x19)
	sw		x15, 4(x19)

	or		x1, zero, x17
	or		a0, zero, x18
	or 		x2, zero, x19
	la		x6, RF_PATTERNS

	p.lw 		x16, 0(x6!)
	p.lw 		x17, 0(x6!)
	p.lw 		x18, 0(x6!)
	p.lw 		x19, 0(x6!)
	p.lw 		x20, 0(x6!)
	p.lw 		x21, 4(x6!)
	p.lw 		x22, 0(x6!)
	p.lw 		x23, 0(x6!)
	p.lw 		x24, 0(x6!)
	p.lw 		x25, 0(x6!)
	p.lw 		x26, 4(x6!)
	p.lw 		x27, 0(x6!)
	p.lw 		x28, 0(x6!)
	p.lw 		x29, 0(x6!)
	p.lw 		x30, 0(x6!)
	p.lw 		x31, 0(x6!)
	xor		a0, x16, a0
	xor		a0, x17, a0
	xor		a0, x18, a0
	xor		a0, x19, a0
	xor		a0, x20, a0
	xor		a0, x21, a0
	xor		a0, x22, a0
	xor		a0, x23, a0
	xor		a0, x24, a0
	xor		a0, x25, a0
	xor		a0, x26, a0
	xor		a0, x27, a0
	xor		a0, x28, a0
	xor		a0, x29, a0
	xor		a0, x30, a0
	xor		a0, x31, a0
	sw		x16, 4(sp)
	sw		x17, 4(sp)
	sw		x18, 4(sp)
	sw		x19, 4(sp)
	sw		x20, 4(sp)
	sw		x21, 4(sp)
	sw		x22, 4(sp)
	sw		x23, 4(sp)
	sw		x24, 4(sp)
	sw		x25, 4(sp)
	sw		x26, 4(sp)
	sw		x27, 4(sp)
	sw		x28, 4(sp)
	sw		x29, 4(sp)
	sw		x30, 4(sp)
	sw		x31, 4(sp)
	xori		x16, x16, -1
	xori		x17, x17, -1
	xori		x18, x18, -1
	xori		x19, x19, -1
	xori		x20, x20, -1
	xori		x21, x21, -1
	xori		x22, x22, -1
	xori		x23, x23, -1
	xori		x24, x24, -1
	xori		x25, x25, -1
	xori		x26, x26, -1
	xori		x27, x27, -1
	xori		x28, x28, -1
	xori		x29, x29, -1
	xori		x30, x30, -1
	xori		x31, x31, -1
	xor		a0, x16, a0
	xor		a0, x17, a0
	xor		a0, x18, a0
	xor		a0, x19, a0
	xor		a0, x20, a0
	xor		a0, x21, a0
	xor		a0, x22, a0
	xor		a0, x23, a0
	xor		a0, x24, a0
	xor		a0, x25, a0
	xor		a0, x26, a0
	xor		a0, x27, a0
	xor		a0, x28, a0
	xor		a0, x29, a0
	xor		a0, x30, a0
	xor		a0, x31, a0
	sw		x16, 4(sp)
	sw		x17, 4(sp)
	sw		x18, 4(sp)
	sw		x19, 4(sp)
	sw		x20, 4(sp)
	sw		x21, 4(sp)
	sw		x22, 4(sp)
	sw		x23, 4(sp)
	sw		x24, 4(sp)
	sw		x25, 4(sp)
	sw		x26, 4(sp)
	sw		x27, 4(sp)
	sw		x28, 4(sp)
	sw		x29, 4(sp)
	sw		x30, 4(sp)
	sw		x31, 4(sp)
	
	ret
	
// -------------------------------------
/*
	.section ".TEST_DATA", "aw"
	.global test_result
test_result:
	.space 4
return_address:
	.space 4
*/
// -------------------------------------
	.section ".TEST_RODATA", "a"
RF_PATTERNS:
	.long 0xf0f0f0f0
	.long 0x33333333
	.long 0x55555555
