	.section .text
	.global _sbst_boot
	.type _sbst_boot, @function

_sbst_boot:

	lui	a0, %hi(__TEST_DATA_START)
	addi	a0, a0, %lo(__TEST_DATA_START)

	// Preserving all non-volatile registers (use section .TEST_DATA)
	sw	ra, (a0)  
	sw	sp, 4(a0) 
	sw 	gp, 8(a0) 
	sw	tp, 12(a0)
	sw	s0, 16(a0)
	sw	s1, 20(a0)
	sw	s2, 24(a0)
	sw	s3, 28(a0)
	sw	s4, 32(a0)
	sw	s5, 36(a0)
	sw	s6, 40(a0)
	sw	s7, 44(a0)
	sw	s8, 48(a0)
	sw	s9, 52(a0)
	sw	s10, 56(a0)
	sw	s11, 60(a0)

	// Disabling interrupts
	csrrs t1, 0x300, zero	
	ori t0, zero, 8		
	csrrc t0, 0x300, t0	
	la a0, interrupt
	sw t1, (a0)

	//call _sbst_rf
	call _sbst_alu
	
	// Restoring non-volatile registers
	la	a0, current_state
	lw	ra, (a0)  
	lw	sp, 4(a0) 
	lw 	gp, 8(a0) 
	lw	tp, 12(a0)
	lw	s0, 16(a0)
	lw	s1, 20(a0)
	lw	s2, 24(a0)
	lw	s3, 28(a0)
	lw	s4, 32(a0)
	lw	s5, 36(a0)
	lw	s6, 40(a0)
	lw	s7, 44(a0)
	lw	s8, 48(a0)
	lw	s9, 52(a0)
	lw	s10, 56(a0)
	lw	s11, 60(a0)

	// Restoring interrupts
	la a0, interrupt
	lw t0, (a0)	
	andi t0, t0, 0x0008
	csrrc t0, 0x300, t0
	ret

// -------------------------------------
	.section ".TEST_DATA", "aw"
	.global state
current_state:
	.space 64
interrupt:
	.space 4

