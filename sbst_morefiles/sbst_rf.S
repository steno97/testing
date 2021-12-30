	.section .text
	.global _sbst_rf
	.type _sbst_rf, @function

_sbst_rf:
	
	// Loading special pattern
	la		t0, return_address
	sw		x1, (t0)
	la		x1, RF_PATTERNS
	la		x31, test_result
	lw		x16, (x1)

	                
	or 		x1, zero, x16
	or 		x2, zero, x16
	or 		x3, zero, x16
	or 		x4, zero, x16
	or 		x5, zero, x16
	or 		x6, zero, x16
	or 		x7, zero, x16
	or 		x8, zero, x16
	or 		x9, zero, x16
	or 		x10, zero, x16
	or 		x11, zero, x16
	or 		x12, zero, x16
	or 		x13, zero, x16
	or 		x14, zero, x16
	or 		x15, zero, x16
	sw		x1, (x31)
	sw		x2, (x31)
	sw		x3, (x31)
	sw		x4, (x31)
	sw		x5, (x31)
	sw		x6, (x31)
	sw		x7, (x31)
	sw		x8, (x31)
	sw		x9, (x31)
	sw		x10, (x31)
	sw		x11, (x31)
	sw		x12, (x31)
	sw		x13, (x31)
	sw		x14, (x31)
	sw		x15, (x31)
	xori		x1, x1, -1
	xori		x2, x2, -1
	xori		x3, x3, -1
	xori		x4, x4, -1
	xori		x5, x5, -1
	xori		x6, x6, -1
	xori		x7, x7, -1
	xori		x8, x8, -1
	xori		x9, x9, -1
	xori		x10, x10, -1
	xori		x11, x11, -1
	xori		x12, x12, -1
	xori		x13, x13, -1
	xori		x14, x14, -1
	xori		x15, x15, -1
	sw		x1, (x31)
	sw		x2, (x31)
	sw		x3, (x31)
	sw		x4, (x31)
	sw		x5, (x31)
	sw		x6, (x31)
	sw		x7, (x31)
	sw		x8, (x31)
	sw		x9, (x31)
	sw		x10, (x31)
	sw		x11, (x31)
	sw		x12, (x31)
	sw		x13, (x31)
	sw		x14, (x31)
	sw		x15, (x31)

	la		x1, RF_PATTERNS
	lw		x6, 4(x1)
	or		x1, x31, zero

	or 		x17, zero, x6
	or 		x18, zero, x6
	or 		x19, zero, x6
	or 		x20, zero, x6
	or 		x21, zero, x6
	or 		x22, zero, x6
	or 		x23, zero, x6
	or 		x24, zero, x6
	or 		x25, zero, x6
	or 		x26, zero, x6
	or 		x27, zero, x6
	or 		x28, zero, x6
	or 		x29, zero, x6
	or 		x30, zero, x6
	or 		x31, zero, x6
	sw		x16, (x1)
	sw		x17, (x1)
	sw		x18, (x1)
	sw		x19, (x1)
	sw		x20, (x1)
	sw		x21, (x1)
	sw		x22, (x1)
	sw		x23, (x1)
	sw		x24, (x1)
	sw		x25, (x1)
	sw		x26, (x1)
	sw		x27, (x1)
	sw		x28, (x1)
	sw		x29, (x1)
	sw		x30, (x1)
	sw		x31, (x1)
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
	sw		x16, (x1)
	sw		x17, (x1)
	sw		x18, (x1)
	sw		x19, (x1)
	sw		x20, (x1)
	sw		x21, (x1)
	sw		x22, (x1)
	sw		x23, (x1)
	sw		x24, (x1)
	sw		x25, (x1)
	sw		x26, (x1)
	sw		x27, (x1)
	sw		x28, (x1)
	sw		x29, (x1)
	sw		x30, (x1)
	sw		x31, (x1)
/*
	or 		x2, zero, x16
	sw		x2, (x31)
	srli		x2, x2, 1
	sw		x2, (x31)

	or 		x3, zero, x16
	sw		x3, (x31)
	srli		x3, x3, 1
	sw		x3, (x31)
	
	or 		x4, zero, x16
	sw		x4, (x31)
	srli		x4, x4, 1
	sw		x4, (x31)

	or 		x5, zero, x16
	sw		x5, (x31)
	srli		x5, x5, 1
	sw		x5, (x31)
	
	or 		x6, zero, x16
	sw		x6, (x31)
	srli		x6, x6, 1
	sw		x6, (x31)

	or 		x7, zero, x16
	sw		x7, (x31)
	srli		x7, x7, 1
	sw		x7, (x31)
	
	or 		x8, zero, x16
	sw		x8, (x31)
	srli		x8, x8, 1
	sw		x8, (x31)

	or 		x9, zero, x16
	sw		x9, (x31)
	srli		x9, x9, 1
	sw		x9, (x31)
	
	or 		x10, zero, x16
	sw		x10, (x31)
	srli		x10, x10, 1
	sw		x10, (x31)

	or 		x11, zero, x16
	sw		x11, (x31)
	srli		x11, x11, 1
	sw		x11, (x31)
	
	or 		x12, zero, x16
	sw		x12, (x31)
	srli		x12, x12, 1
	sw		x12, (x31)

	or 		x13, zero, x16
	sw		x13, (x31)
	srli		x13, x13, 1
	sw		x13, (x31)
	
	or 		x14, zero, x16
	sw		x14, (x31)
	srli		x14, x14, 1
	sw		x14, (x31)

	or 		x15, zero, x16
	sw		x15, (x31)
	srli		x15, x15, 1
	sw		x15, (x31)

	or		x1, x16, zero
	
	or 		x16, zero, x1
	sw		x16, (x31)
	srli		x16, x16, 1
	sw		x16, (x31)

	or 		x17, zero, x1
	sw		x17, (x31)
	srli		x17, x17, 1
	sw		x17, (x31)
	
	or 		x18, zero, x1
	sw		x18, (x31)
	srli		x18, x18, 1
	sw		x18, (x31)

	or 		x19, zero, x1
	sw		x19, (x31)
	srli		x19, x19, 1
	sw		x19, (x31)
	
	or 		x20, zero, x1
	sw		x20, (x31)
	srli		x20, x20, 1
	sw		x20, (x31)

	or 		x21, zero, x1
	sw		x21, (x31)
	srli		x21, x21, 1
	sw		x21, (x31)
	
	or 		x22, zero, x1
	sw		x22, (x31)
	srli		x22, x22, 1
	sw		x22, (x31)

	or 		x23, zero, x1
	sw		x23, (x31)
	srli		x23, x23, 1
	sw		x23, (x31)
	
	or 		x24, zero, x1
	sw		x24, (x31)
	srli		x24, x24, 1
	sw		x24, (x31)

	or 		x25, zero, x1
	sw		x25, (x31)
	srli		x25, x25, 1
	sw		x25, (x31)
	
	or 		x26, zero, x1
	sw		x26, (x31)
	srli		x26, x26, 1
	sw		x26, (x31)

	or 		x27, zero, x1
	sw		x27, (x31)
	srli		x27, x27, 1
	sw		x27, (x31)
	
	or 		x28, zero, x1
	sw		x28, (x31)
	srli		x28, x28, 1
	sw		x28, (x31)

	or 		x29, zero, x1
	sw		x29, (x31)
	srli		x29, x29, 1
	sw		x29, (x31)
	
	or 		x30, zero, x1
	sw		x30, (x31)
	srli		x30, x30, 1
	sw		x30, (x31)

	or		x2, zero, x31

	or 		x31, zero, x1
	sw		x31, (x2)
	srli		x31, x31, 1
	sw		x31, (x2)

	xor		x3, x3, x1
	xor		x3, x3, x2
	xor		x3, x3, x4
	xor		x3, x3, x5	
	xor		x3, x3, x6	
	xor		x3, x3, x7	
	xor		x3, x3, x8
	xor		x3, x3, x9	
	xor		x3, x3, x10	
	xor		x3, x3, x11	
	xor		x3, x3, x12
	xor		x3, x3, x13	
	xor		x3, x3, x14	
	xor		x3, x3, x15	
	xor		x3, x3, x16
	xor		x3, x3, x17	
	xor		x3, x3, x18	
	xor		x3, x3, x19	
	xor		x3, x3, x20
	xor		x3, x3, x21	
	xor		x3, x3, x22	
	xor		x3, x3, x23	
	xor		x3, x3, x24
	xor		x3, x3, x25	
	xor		x3, x3, x26	
	xor		x3, x3, x27	
	xor		x3, x3, x28
	xor		x3, x3, x29	
	xor		x3, x3, x30	
	xor		x3, x3, x31	
*/
	// here I used tX registers, you should do it for all x1-x31
	
	la		x2, test_result
	sw		x3, (x2)
	la		t0, return_address
	lw		x1, (t0)
	ret
	
// -------------------------------------
	.section ".TEST_DATA", "aw"
	.global test_result
test_result:
	.space 4
return_address:
	.space 4

// -------------------------------------
	.section ".TEST_RODATA", "a"

RF_PATTERNS:
//	.long 0x12345678
//	.long 0xcafecafe
//	.long 0xdeadbeef
//	.long 0xdeeeeead	//9acfcf12
//	.long 0xfe392012
//	.long 0x84928349
//	.long 0x924bc0d2
//	.long 0x90192001	//40005340
//
//	.long 0x10f2ed2a
//	.long 0x69213a64
//	.long 0x8503ab84
//	.long 0x457629cf	//848e5021
//	.long 0xfba758c3
//	.long 0x85928ca9
//	.long 0x37211112
//	.long 0x20a0c00c	//5d8a06ab
//
//	.long 0x948392ca
//	.long 0xcfacc462
//	.long 0xc8a9ccc8
//	.long 0x11111111	//9b753bb0
//	.long 0x29385201
//	.long 0x93485221
//	.long 0x93759381
//	.long 0x90192ccc	//7b84a01f
//
//	.long 0x99999990
//	.long 0xf9203421
//	.long 0xdacfaaaa
//	.long 0x57932423	//40a13c9d
//	.long 0x68391294
//	.long 0x438282aa
//	.long 0xcccccc89	//b9299e64
//	.long 0x42939112	//fbbd2f76

	.long 0xF0F0F0F0
	.long 0x00000000
	.long 0x55555555
	.long 0xaaaaaaaa
	.long 0x55555555
	.long 0xaaaaaaaa
	.long 0x55555555
	.long 0xaaaaaaaa
	
	.long 0x55555555
	.long 0xaaaaaaaa
	.long 0x55555555
	.long 0xaaaaaaaa
	.long 0x55555555
	.long 0xaaaaaaaa
	.long 0x55555555
	.long 0xaaaaaaaa
	
	.long 0x55555555
	.long 0xaaaaaaaa
	.long 0x55555555
	.long 0xaaaaaaaa
	.long 0x55555555
	.long 0xaaaaaaaa
	.long 0x55555555
	.long 0xaaaaaaaa
	
	.long 0x55555555
	.long 0xaaaaaaaa
	.long 0x55555555
	.long 0xaaaaaaaa
	.long 0x55555555
	.long 0xaaaaaaaa
	.long 0x55555555
	.long 0xaaaaaaaa
OTHER_PATTERNS:
	.long 0x0
	.long 0x0
