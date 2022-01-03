	.section .text
	.global _sbst_boot
	.type _sbst_boot, @function

_sbst_boot:

	//lui	a0, %hi(__TEST_DATA_START)
	//addi	a0, a0, %lo(__TEST_DATA_START)
	la	t0, current_state

	// Preserving all non-volatile registers (use section .TEST_DATA)
	p.sw	ra,  4(t0!) 
	p.sw	sp,  4(t0!) 
	p.sw 	gp,  4(t0!) 
	p.sw	tp,  4(t0!) 
	p.sw	s0,  4(t0!) 
	p.sw	s1,  4(t0!) 
	p.sw	s2,  4(t0!) 
	p.sw	s3,  4(t0!) 
	p.sw	s4,  4(t0!) 
	p.sw	s5,  4(t0!) 
	p.sw	s6,  4(t0!) 
	p.sw	s7,  4(t0!) 
	p.sw	s8,  4(t0!) 
	p.sw	s9,  4(t0!) 
	p.sw	s10, 4(t0!)
	p.sw	s11, 4(t0!)

	// Disabling interrupts
	csrrs 	t1, 0x300, zero	
	ori 	t0, zero, 8		
	csrrc 	t0, 0x300, t0	
	la	t0, interrupt
	sw 	t1, (t0)

 	// Sbst routines
	la	t0, flags_selection
	lw	t0, (t0)
	andi	t0, t0, 0x1
	p.bneimm t0, 0x1, alu0
	call 	_sbst_rf
	la	t0, signatures
	lw	t1, (t0)
	bne	t1, a0, _sbst_fail

alu0:	
	la	t0, flags_selection
	lw	t0, (t0)
	andi	t0, t0, 0x2
	p.bneimm t0, 0x2, alu1
	call 	_sbst_alu0
	la	t0, signatures
	lw	t1, 4(t0)
	bne	t1, a0, _sbst_fail

alu1:
	la	t0, flags_selection
	lw	t0, (t0)
	andi	t0, t0, 0x4
	p.bneimm t0, 0x4, alu2
	call	_sbst_alu1
	la	t0, signatures
	lw	t1, 8(t0)
	bne	t1, a0, _sbst_fail

alu2:
	la	t0, flags_selection
	lw	t0, (t0)
	andi	t0, t0, 0x8
	p.bneimm t0, 0x8, mul0
	call	_sbst_alu2
	la	t0, signatures
	lw	t1, 12(t0)
	bne	t1, a0, _sbst_fail

mul0:
	la	t0, flags_selection
	lw	t0, (t0)
	andi	t0, t0, 0x10
	srl	t0, t0, 4
	p.bneimm t0, 0x1, end_sbst
	call 	_sbst_mul
	la	t0, signatures
	lw	t1, 16(t0)
	bne	t1, a0, _sbst_fail

end_sbst:
	// Restoring non-volatile registers
	la	t0, current_state
	p.lw	ra,  4(t0!)
	p.lw	sp,  4(t0!)
	p.lw 	gp,  4(t0!)
	p.lw	tp,  4(t0!)
	p.lw	s0,  4(t0!)
	p.lw	s1,  4(t0!)
	p.lw	s2,  4(t0!)
	p.lw	s3,  4(t0!)
	p.lw	s4,  4(t0!)
	p.lw	s5,  4(t0!)
	p.lw	s6,  4(t0!)
	p.lw	s7,  4(t0!)
	p.lw	s8,  4(t0!)
	p.lw	s9,  4(t0!)
	p.lw	s10, 4(t0!) 
	p.lw	s11, 4(t0!) 

	// Restoring interrupts
	la 	t0, interrupt
	lw 	t1, (t0)	
	andi 	t1, t1, 0x0008
	csrrc 	t1, 0x300, t1
	
	ori 	a0, zero, 1
	ret

_sbst_fail:
	li	x10, 0xdeaaaaad
	j 	_sbst_fail	# halts the machine


// -------------------------------------
	.section ".TEST_DATA", "aw"
	.global state
current_state:
	.space 64
interrupt:
	.space 4

// -------------------------------------
	.section ".TEST_RODATA", "a"
	.global sbst
flags_selection:
	.long	0x1f
signatures:
	.long 	0xffffffff
	.long	0x23782bea
	.long	0x11f88cfc
	.long	0x1da0a90f
	.long	0x747a297c
