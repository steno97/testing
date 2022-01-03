  .section .text
        .global _run_march_algorithm
        .type _run_march_algorithm, @function

                .equ TEST_MARCH_SUCCESS, 0
                .equ TEST_MARCH_FAIL, 1
                .equ mem, 0x001C0000
                .equ value0,    0x00200000
                .equ finemem,   0x00240000
_run_march_algorithm:
                //scrivo zero in memoria
                //salvo la memoria all'indirizzo 0x00240000


        li t0,finemem
        //mv t6,mem
        li t4,value0
step1:  lw t3,(t4)
        nop
        nop
        nop
        nop
        nop
        //sw t3,(t6)            //salvo il valore nello spazio libero
        mv t3, x0
        sw t3,(t4)              //carico il valore zero nella memoria
        addi t4,t4,4            //incremento entrambi gli indirizzi
        //addi t6,t6,4
        blt t4,t0, step1        //itero fino a che non raggiungo la fine di dataram (0x0020000)


        li t0,finemem
        li t4,value0    //inizzializzo di nuovo gli indirizzi di memoria
step2:  lw t3,(t4)
        nop
        nop
        nop
        nop
        nop
        bnez t3,fail
        li t3,1       //successivamente se non sono arrivato all'inizio della memoria riciclo
        sw t3,(t4)
        addi t4,t4,4 //in questo ciclo leggo zero e scrivo uno, e incremento la memoria
        blt t4,t0, step2


        li t0,value0
        li t1,0x1
        li t2,0x4
        //li t4,finemem
        li t4,finemem
        sub t4,t4,t2
step3:  nop
        nop
        nop
        lw t3,(t4)
        nop
        nop
        nop
        nop
        nop
        bne t3,t1,fail  //in questo ciclo leggo 1 e scrivo zero, leggo subito zero e decremento gli indirizzi
                //riciclo finche non arrivo all'inzio della memoria
        sw t3,(t4)
        nop
        nop
        nop
        nop
        nop
        lw t3,(t4)
        nop
        nop
        nop
        nop
        sub t4,t4,t2
        bnez t3,fail
        bge t4,t0, step3

/*
        mv t6,mem
        li t0,finemem
step4:  lw t3,(t6)
        nop
        nop
        nop
        nop
        addi t6,t6,4
        sw t3,(t4)      //ricarico i vecchi valori nella memoria
        addi t4,t4,4                    //incremento entrambi gli indirizzi
        blt t4,t0, step4
*/

        li t6,TEST_MARCH_SUCCESS
        sw t6,(sp)
        ret

fail:   li t6,TEST_MARCH_FAIL
        sw t6, (sp)
        ret

