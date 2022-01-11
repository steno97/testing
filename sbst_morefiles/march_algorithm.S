	.section .text
	.global _run_march_algorithm
    .type _run_march_algorithm, @function

_run_march_algorithm:
	
        /* Write 0 */
        lui	    t0, %hi(__RAM_SIZE)
        addi	t0, t0, %lo(__RAM_SIZE)
        srli	t0, t0, 2
        lui	    t1, %hi(__RAM_START)
        addi	t1, t1, %lo(__RAM_START)
        lp.setup x0, t0, el0
        sw 	    x0, (t1)
el0:	addi 	t1, t1, 4

        /* Read 0, write 1 */
        lui	    t0, %hi(__RAM_SIZE)
        addi	t0, t0, %lo(__RAM_SIZE)
        srli	t0, t0, 2
        lui	    t1, %hi(__RAM_END)
        addi	t1, t1, %lo(__RAM_END)
        addi	t1, t1, -4
        lp.setup x0, t0, el1
        lw      t2, (t1)
        bne     t2, x0, fail
        ori     t2, x0, -1
        sw       t2, (t1)
el1:	addi    t1, t1, -4

        /* Read 1, write 0 */
        lui	    t0, %hi(__RAM_SIZE)
        addi	t0, t0, %lo(__RAM_SIZE)
        srli	t0, t0, 2
        lui	    t1, %hi(__RAM_START)
        addi	t1, t1, %lo(__RAM_START)
        ori	    t3, x0, -1
        lp.setup x0, t0, el2
        lw      t2, (t1)
        bne     t2, t3, fail
        sw      x0, (t1)
el2:	addi    t1, t1, 4

        or      a0, x0, x0
        ret

fail:   ori     a0, x0, 1
        ret
