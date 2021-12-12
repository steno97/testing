.section .text
         .global _march
         .type _march, @function
         
		.equ TEST_MARCH_SUCCESS 1
		.equ TEST_MARCH_FAIL 0
		.equ mem 0x00240000
		.equ value1	0xFFFFFFFF
		.equ value0	0x00000000
_march:
		;scrivo zero in memoria
		;salvo la memoria all'indirizzo 0x00240000
step1:	mv x1,mem		
		mv a0,value0
		lw a1,(a0)			
		sw a1,(x1)  				;salvo il valore nello spazio libero
		mv a1, x0
		sw a1,(a0)					;carico il valore zero nella memoria
		add a0,4 					;incremento entrambi gli indirizzi	
		add x1,4
		bne	a0,0x00240000, step1	;itero fino a che non raggiungo la fine di dataram (0x0020000)
		
		mv a0,0x00000000			;inizzializzo di nuovo gli indirizzi di memoria
		mv x1,0x00024000
step2:	lw a1,(a0)
		bnez a1,fail	
		add a0,4
		add x1,4					;in questo ciclo leggo zero e scrivo uno, e incremento la memoria
		mv a1,1						;successivamente se non sono arrivato all'inizio della memoria riciclo
		sw a1,(a0)
		bne a0,0x00240000, step2
		
			
step3:	sub a0,4
		sub x1,4
		lw a1,(a0)
		bne a1,1,fail				;in questo ciclo leggo 1 e scrivo zero, leggo subito zero e decremento gli indirizzi
		mv a1,0						;riciclo finche non arrivo all'inzio della memoria
		sw a1,(a0)
		lw a1,(a0)
		bnez a1,fail
		bne a0,0x00000000, step2
		
		
step4:	lw a1,(x1)			
		sw a1,(a0)  				;ricarico i vecchi valori nella memoria
		add a0,4 					;incremento entrambi gli indirizzi	
		add x1,4
		bne	a0,0x00240000, step4
		

		
		
			



		mv TEST_MARCH_SUCCESS,x1
		ret


fail:	mv TEST_MARCH_FAIL,x1
		ret

















