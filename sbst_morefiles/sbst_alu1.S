	.section .text
	.global _sbst_alu1
	.type _sbst_alu1, @function

_sbst_alu1:
	xor x31, x31, x31
	xor x30, x30, x30
	
	li x3, 0x80000000
	p.ff1 x30, x3
	sw x30, 4(sp)
	xor x31, x31, x30
	li x6, 0xfef09234
	p.cnt x30, x6
	sw x30, 4(sp)
	xor x31, x31, x30
	li x9, 0x10
	p.fl1 x30, x9
	sw x30, 4(sp)
	xor x31, x31, x30
	li x12, 0xa4fa2610
	li x13, 0xa4fab2b9
	pv.cmpeq.h x30, x12, x13
	sw x30, 4(sp)
	xor x31, x31, x30
	li x15, 0xf2f613fc
	li x16, 0xf4f513f0
	pv.cmpge.b x30, x15, x16
	sw x30, 4(sp)
	xor x31, x31, x30
	li x18, 0x1f41e23c
	p.extract x30, x18, 11, 30
	sw x30, 4(sp)
	xor x31, x31, x30
	li x21, 0xdfa1f11e
	p.extract x30, x21, 12, 27
	sw x30, 4(sp)
	xor x31, x31, x30
	li x24, 0x77
	p.fl1 x30, x24
	sw x30, 4(sp)
	xor x31, x31, x30
	li x27, 0x831
	p.fl1 x30, x27
	sw x30, 4(sp)
	xor x31, x31, x30
	li x3, 0x2b31158b
	li x4, 0x9c472e5f
	p.subRN x30, x3, x4, 11
	sw x30, 4(sp)
	xor x31, x31, x30
	li x6, 0xfe260b3
	p.clip x30, x6, 2
	sw x30, 4(sp)
	xor x31, x31, x30
	li x9, 0xaba7d5e2
	pv.abs.b x30, x9
	sw x30, 4(sp)
	xor x31, x31, x30
	li x12, 0xf17a0e8
	li x13, 0xf14c80c1
	sltu x30, x12, x13
	sw x30, 4(sp)
	xor x31, x31, x30
	li x15, 0x80
	p.fl1 x30, x15
	sw x30, 4(sp)
	xor x31, x31, x30
	li x18, 0xc4c13240
	p.ff1 x30, x18
	sw x30, 4(sp)
	xor x31, x31, x30
	li x21, 0x75e18a71
	li x22, 0x75e20e6c
	pv.cmple.b x30, x21, x22
	sw x30, 4(sp)
	xor x31, x31, x30
	li x24, 0x98d8c521
	li x25, 0x97958722
	pv.cmpgt.b x30, x24, x25
	sw x30, 4(sp)
	xor x31, x31, x30
	li x27, 0x4292eb0a
	li x28, 0x263ac16a
	pv.and.h x30, x27, x28
	sw x30, 4(sp)
	xor x31, x31, x30
	li x3, 0x21497085
	li x4, 0x131d65ae
	p.ror x30, x3, x4
	sw x30, 4(sp)
	xor x31, x31, x30
	li x6, 0x405a3be0
	p.extract x30, x6, 7, 17
	sw x30, 4(sp)
	xor x31, x31, x30
	li x9, 0x50168ef8
	p.extract x30, x9, 3, 28
	sw x30, 4(sp)
	xor x31, x31, x30
	li x12, 0x38b5c4de
	p.extract x30, x12, 19, 12
	sw x30, 4(sp)
	xor x31, x31, x30
	li x15, 0xac8461cd
	p.bclr x30, x15, 25, 0
	sw x30, 4(sp)
	xor x31, x31, x30
	li x18, 0x56462166
	li x19, 0xb9655798
	p.subuRN x30, x18, x19, 5
	sw x30, 4(sp)
	xor x31, x31, x30
	li x21, 0x400
	p.ff1 x30, x21
	sw x30, 4(sp)
	xor x31, x31, x30
	li x24, 0x8e096557
	li x25, 0x17a0f4b1
	sll x30, x24, x25
	sw x30, 4(sp)
	xor x31, x31, x30
	li x27, 0xfeeaf109
	li x28, 0xfeb0b277
	pv.or.h x30, x27, x28
	sw x30, 4(sp)
	xor x31, x31, x30
	li x3, 0x8b8f9884
	p.abs x30, x3
	sw x30, 4(sp)
	xor x31, x31, x30
	li x6, 0x56e83aa1
	li x7, 0x4f008e9f
	pv.minu.b x30, x6, x7
	sw x30, 4(sp)
	xor x31, x31, x30
	li x9, 0xfff7ffff
	p.cnt x30, x9
	sw x30, 4(sp)
	xor x31, x31, x30
	li x12, 0x80c73e5f
	p.fl1 x30, x12
	sw x30, 4(sp)
	xor x31, x31, x30
	li x15, 0x109c
	p.fl1 x30, x15
	sw x30, 4(sp)
	xor x31, x31, x30
	li x18, 0x7
	p.fl1 x30, x18
	sw x30, 4(sp)
	xor x31, x31, x30
	li x21, 0xc50a30a6
	p.extract x30, x21, 4, 30
	sw x30, 4(sp)
	xor x31, x31, x30
	li x24, 0x76cc7fe0
	p.extract x30, x24, 27, 20
	sw x30, 4(sp)
	xor x31, x31, x30
	li x27, 0x73663ff0
	p.extract x30, x27, 0, 26
	sw x30, 4(sp)
	xor x31, x31, x30
	li x3, 0x39331ff8
	p.extract x30, x3, 21, 31
	sw x30, 4(sp)
	xor x31, x31, x30
	li x6, 0xdc20e84f
	p.extract x30, x6, 13, 24
	sw x30, 4(sp)
	xor x31, x31, x30
	li x9, 0xeee91394
	p.extract x30, x9, 8, 27
	sw x30, 4(sp)
	xor x31, x31, x30
	li x12, 0x5c53a3ca
	li x13, 0x5c53a3b9
	pv.cmpleu.h x30, x12, x13
	sw x30, 4(sp)
	xor x31, x31, x30
	li x15, 0xffffbff4
	p.cnt x30, x15
	sw x30, 4(sp)
	xor x31, x31, x30
	li x18, 0x4ab
	p.fl1 x30, x18
	sw x30, 4(sp)
	xor x31, x31, x30
	li x21, 0x5afdb600
	p.insert x30, x21, 20, 5
	sw x30, 4(sp)
	xor x31, x31, x30
	li x24, 0x56460a33
	p.extract x30, x24, 0, 24
	sw x30, 4(sp)
	xor x31, x31, x30
	li x27, 0xebda62aa
	li x28, 0x97034d1c
	sll x30, x27, x28
	sw x30, 4(sp)
	xor x31, x31, x30
	li x3, 0x10000000
	p.ff1 x30, x3
	sw x30, 4(sp)
	xor x31, x31, x30
	li x6, 0xfffffffe
	p.cnt x30, x6
	sw x30, 4(sp)
	xor x31, x31, x30
	li x9, 0xa7f3e0d2
	li x10, 0xa6d7aad2
	pv.cmpgeu.b x30, x9, x10
	sw x30, 4(sp)
	xor x31, x31, x30
	li x12, 0x94b676a5
	p.abs x30, x12
	sw x30, 4(sp)
	xor x31, x31, x30
	li x15, 0xbadb5b52
	p.extract x30, x15, 24, 21
	sw x30, 4(sp)
	xor x31, x31, x30
	li x18, 0x6ea2eb03
	p.extract x30, x18, 30, 30
	sw x30, 4(sp)
	xor x31, x31, x30
	li x21, 0xf7417581
	p.extract x30, x21, 31, 27
	sw x30, 4(sp)
	xor x31, x31, x30
	li x24, 0x3bbcbac0
	p.extract x30, x24, 14, 21
	sw x30, 4(sp)
	xor x31, x31, x30
	li x27, 0xee1b1bca
	p.extract x30, x27, 29, 30
	sw x30, 4(sp)
	xor x31, x31, x30
	li x3, 0xfffff7f4
	p.cnt x30, x3
	sw x30, 4(sp)
	xor x31, x31, x30
	li x6, 0x28acdca4
	p.clip x30, x6, 26
	sw x30, 4(sp)
	xor x31, x31, x30
	li x9, 0x7e106eea
	p.clip x30, x9, 26
	sw x30, 4(sp)
	xor x31, x31, x30
	li x12, 0x400
	p.clipu x30, x12, 5
	sw x30, 4(sp)
	xor x31, x31, x30
	li x15, 0xf346916f
	li x16, 0xf346916f
	sltu x30, x15, x16
	sw x30, 4(sp)
	xor x31, x31, x30
	li x18, 0x659e8d54
	li x19, 0x1aab7cbe
	or x30, x18, x19
	sw x30, 4(sp)
	xor x31, x31, x30
	li x21, 0x40000
	p.fl1 x30, x21
	sw x30, 4(sp)
	xor x31, x31, x30
	li x24, 0xbf5e0000
	p.ff1 x30, x24
	sw x30, 4(sp)
	xor x31, x31, x30
	li x27, 0x4df729a3
	li x28, 0x4e8857e8
	p.sletu x30, x27, x28
	sw x30, 4(sp)
	xor x31, x31, x30
	li x3, 0xa3e523fd
	p.extract x30, x3, 26, 31
	sw x30, 4(sp)
	xor x31, x31, x30
	li x6, 0x1bfa91fe
	p.extract x30, x6, 22, 15
	sw x30, 4(sp)
	xor x31, x31, x30
	li x9, 0xe6d0d0b5
	p.extract x30, x9, 18, 9
	sw x30, 4(sp)
	xor x31, x31, x30
	li x12, 0x1368685a
	p.extract x30, x12, 23, 8
	sw x30, 4(sp)
	xor x31, x31, x30
	li x15, 0x86e8749
	p.fl1 x30, x15
	sw x30, 4(sp)
	xor x31, x31, x30
	li x18, 0xd3c9a423
	p.extractu x30, x18, 1, 4
	sw x30, 4(sp)
	xor x31, x31, x30
	li x21, 0x3969a6f7
	p.clip x30, x21, 26
	sw x30, 4(sp)
	xor x31, x31, x30
	li x24, 0x21ace190
	li x25, 0xb1b75f4f
	pv.shuffle2.h x30, x24, x25
	sw x30, 4(sp)
	xor x31, x31, x30
	li x27, 0x548ed6ab
	li x28, 0x81d6d6ab
	pv.cmplt.h x30, x27, x28
	sw x30, 4(sp)
	xor x31, x31, x30
	li x3, 0x8ab1d32e
	p.ff1 x30, x3
	sw x30, 4(sp)
	xor x31, x31, x30
	li x6, 0xfffffff7
	p.cnt x30, x6
	sw x30, 4(sp)
	xor x31, x31, x30
	li x9, 0x3ed43c54
	li x10, 0x3ec4811b
	pv.cmple.b x30, x9, x10
	sw x30, 4(sp)
	xor x31, x31, x30
	li x12, 0xc161427b
	p.extract x30, x12, 18, 18
	sw x30, 4(sp)
	xor x31, x31, x30
	li x15, 0x702e1df0
	p.extract x30, x15, 11, 12
	sw x30, 4(sp)
	xor x31, x31, x30
	li x18, 0xb8160ef8
	p.extract x30, x18, 20, 26
	sw x30, 4(sp)
	xor x31, x31, x30
	li x21, 0xdce39da1
	li x22, 0xbdaff9cb
	pv.shuffle2.b x30, x21, x22
	sw x30, 4(sp)
	xor x31, x31, x30
	li x24, 0xffff7f0d
	p.cnt x30, x24
	sw x30, 4(sp)
	xor x31, x31, x30
	li x27, 0x100
	p.ff1 x30, x27
	sw x30, 4(sp)
	xor x31, x31, x30
	li x3, 0x5b0ecfde
	p.extract x30, x3, 11, 5
	sw x30, 4(sp)
	xor x31, x31, x30
	li x6, 0x64e6cde1
	p.clip x30, x6, 16
	sw x30, 4(sp)
	xor x31, x31, x30
	li x9, 0x800
	p.clipu x30, x9, 0
	sw x30, 4(sp)
	xor x31, x31, x30
	li x12, 0xe5b11b58
	li x13, 0x93bca866
	pv.max.b x30, x12, x13
	sw x30, 4(sp)
	xor x31, x31, x30
	li x15, 0x20000000
	p.ff1 x30, x15
	sw x30, 4(sp)
	xor x31, x31, x30
	li x18, 0xfdf26e0d
	p.cnt x30, x18
	sw x30, 4(sp)
	xor x31, x31, x30
	li x21, 0x1
	p.fl1 x30, x21
	sw x30, 4(sp)
	xor x31, x31, x30
	li x24, 0x3a27b08
	p.ff1 x30, x24
	sw x30, 4(sp)
	xor x31, x31, x30
	li x27, 0x69080000
	p.ff1 x30, x27
	sw x30, 4(sp)
	xor x31, x31, x30
	li x3, 0x66469695
	li x4, 0x655071d3
	pv.cmpge.b x30, x3, x4
	sw x30, 4(sp)
	xor x31, x31, x30
	li x6, 0x85401a7b
	p.abs x30, x6
	sw x30, 4(sp)
	xor x31, x31, x30
	li x9, 0xfa9ce0e7
	p.extract x30, x9, 21, 22
	sw x30, 4(sp)
	xor x31, x31, x30
	li x12, 0xd3d5c45b
	p.extract x30, x12, 22, 28
	sw x30, 4(sp)
	xor x31, x31, x30
	li x15, 0xe9e2c025
	li x16, 0xb5a64487
	p.addRN x30, x15, x16, 19
	sw x30, 4(sp)
	xor x31, x31, x30
	li x18, 0x4d838b7
	p.fl1 x30, x18
	sw x30, 4(sp)
	xor x31, x31, x30
	li x21, 0x1f0fce2d
	li x22, 0xf8e6d546
	p.addRN x30, x21, x22, 16
	sw x30, 4(sp)
	xor x31, x31, x30
	li x24, 0xca9ed679
	li x25, 0x7c81bf64
	p.addRN x30, x24, x25, 17
	sw x30, 4(sp)
	xor x31, x31, x30
	li x27, 0xebd3c80
	p.abs x30, x27
	sw x30, 4(sp)
	xor x31, x31, x30
	li x3, 0x427ccfe
	p.clip x30, x3, 27
	sw x30, 4(sp)
	xor x31, x31, x30
	li x6, 0x2b9ba1df
	p.clip x30, x6, 19
	sw x30, 4(sp)
	xor x31, x31, x30
	li x9, 0x1000
	p.clipu x30, x9, 3
	sw x30, 4(sp)
	xor x31, x31, x30
	li x12, 0x8000
	p.clipu x30, x12, 18
	sw x30, 4(sp)
	xor x31, x31, x30
	li x15, 0x2
	p.clipu x30, x15, 13
	sw x30, 4(sp)
	xor x31, x31, x30
	li x18, 0xf49199d
	li x19, 0x6c59ee02
	pv.cmpne.h x30, x18, x19
	sw x30, 4(sp)
	xor x31, x31, x30
	li x21, 0xfffdffff
	p.cnt x30, x21
	sw x30, 4(sp)
	xor x31, x31, x30
	li x24, 0x1000000
	p.ff1 x30, x24
	sw x30, 4(sp)
	xor x31, x31, x30
	li x27, 0xfffffdf1
	p.cnt x30, x27
	sw x30, 4(sp)
	xor x31, x31, x30
	li x3, 0x7956ba64
	p.fl1 x30, x3
	sw x30, 4(sp)
	xor x31, x31, x30
	li x6, 0xff800000
	p.ff1 x30, x6
	sw x30, 4(sp)
	xor x31, x31, x30
	li x9, 0x10e5d2a4
	li x10, 0x9ccfd160
	pv.cmpgt.h x30, x9, x10
	sw x30, 4(sp)
	xor x31, x31, x30
	li x12, 0x298efbed
	li x13, 0x298e9b85
	pv.packlo.b x30, x12, x13
	sw x30, 4(sp)
	xor x31, x31, x30
	li x15, 0x8f14d177
	li x16, 0xf092ef02
	pv.add.b x30, x15, x16
	sw x30, 4(sp)
	xor x31, x31, x30
	li x18, 0xaa4bcb25
	li x19, 0x8a8e22fd
	pv.shuffle2.b x30, x18, x19
	sw x30, 4(sp)
	xor x31, x31, x30
	li x21, 0x3a6f2ef5
	li x22, 0xb3bf48f3
	pv.cmpge.b x30, x21, x22
	sw x30, 4(sp)
	xor x31, x31, x30
	li x24, 0x4841bfa7
	li x25, 0x4851e2b3
	pv.shuffle2.h x30, x24, x25
	sw x30, 4(sp)
	xor x31, x31, x30
	li x27, 0x1b450f24
	p.insert x30, x27, 25, 7
	sw x30, 4(sp)
	xor x31, x31, x30
	li x3, 0x2bef3d53
	li x4, 0x3bb40099
	pv.sll.b x30, x3, x4
	sw x30, 4(sp)
	xor x31, x31, x30
	li x6, 0xd2ad438c
	li x7, 0xdada824e
	pv.shuffle.b x30, x6, x7
	sw x30, 4(sp)
	xor x31, x31, x30
	li x9, 0x32a95156
	p.bset x30, x9, 7, 19
	sw x30, 4(sp)
	xor x31, x31, x30
	li x12, 0x3e044e9b
	li x13, 0xcc3780e3
	p.subRN x30, x12, x13, 30
	sw x30, 4(sp)
	xor x31, x31, x30
	li x15, 0x43d5c0ad
	li x16, 0x5fcfbf7e
	p.addRN x30, x15, x16, 16
	sw x30, 4(sp)
	xor x31, x31, x30
	li x18, 0xef5bc357
	li x19, 0x3e86ca16
	pv.sll.h x30, x18, x19
	sw x30, 4(sp)
	xor x31, x31, x30
	li x21, 0x3c339f0a
	p.bclr x30, x21, 19, 8
	sw x30, 4(sp)
	xor x31, x31, x30
	li x24, 0x37070ac3
	pv.abs.h x30, x24
	sw x30, 4(sp)
	xor x31, x31, x30
	li x27, 0x7b2649db
	li x28, 0x98266918
	pv.cmpgeu.h x30, x27, x28
	sw x30, 4(sp)
	xor x31, x31, x30
	li x3, 0xb350e6cb
	li x4, 0x76f3e74f
	pv.shuffle2.b x30, x3, x4
	sw x30, 4(sp)
	xor x31, x31, x30
	li x6, 0x4c0cd2a3
	li x7, 0xb7f31d5e
	p.subuRN x30, x6, x7, 2
	sw x30, 4(sp)
	xor x31, x31, x30
	li x9, 0x2bf475e7
	li x10, 0x2bb40524
	pv.sll.h x30, x9, x10
	sw x30, 4(sp)
	xor x31, x31, x30
	li x12, 0x5fab0b17
	li x13, 0x699502b3
	pv.sll.h x30, x12, x13
	sw x30, 4(sp)
	xor x31, x31, x30
	li x15, 0x33e8498
	p.clip x30, x15, 20
	sw x30, 4(sp)
	xor x31, x31, x30
	li x18, 0x27668000
	p.ff1 x30, x18
	sw x30, 4(sp)
	xor x31, x31, x30
	li x21, 0xd6524b01
	li x22, 0xaa5dc613
	pv.shuffle2.b x30, x21, x22
	sw x30, 4(sp)
	xor x31, x31, x30
	li x24, 0xf35c89f5
	li x25, 0x239148bb
	pv.packhi.b x30, x24, x25
	sw x30, 4(sp)
	xor x31, x31, x30
	li x27, 0x86d7bedb
	p.bclr x30, x27, 1, 0
	sw x30, 4(sp)
	xor x31, x31, x30
	li x3, 0x3a8ddd2e
	li x4, 0x81dbdb3f
	pv.packhi.b x30, x3, x4
	sw x30, 4(sp)
	xor x31, x31, x30
	li x6, 0xa5b207fd
	li x7, 0x7bc9dc7f
	p.subRN x30, x6, x7, 6
	sw x30, 4(sp)
	xor x31, x31, x30
	li x9, 0x5bcc67a1
	li x10, 0x5c33985e
	p.adduRN x30, x9, x10, 1 //super speciale
	sw x30, 4(sp)
	xor x31, x31, x30
	li x12, 0xe932b042
	li x13, 0xcc461ffd
	p.addRN x30, x12, x13, 12
	sw x30, 4(sp)
	xor x31, x31, x30
	li x15, 0xc008e17f
	li x16, 0xbff7c880
	p.addRN x30, x15, x16, 7
	sw x30, 4(sp)
	xor x31, x31, x30
	li x18, 0x7bf35e7a
	li x19, 0x735f19c1
	pv.shuffle2.b x30, x18, x19
	sw x30, 4(sp)
	xor x31, x31, x30
	li x21, 0xab202c4e
	p.extract x30, x21, 8, 0
	sw x30, 4(sp)
	xor x31, x31, x30
	li x24, 0x1de41589
	li x25, 0xc0bb6fb
	p.subRN x30, x24, x25, 29
	sw x30, 4(sp)
	xor x31, x31, x30
	li x27, 0x80cf8456
	p.extract x30, x27, 19, 17
	sw x30, 4(sp)
	xor x31, x31, x30
	li x3, 0x800000
	p.fl1 x30, x3
	sw x30, 4(sp)
	xor x31, x31, x30
	li x6, 0x2000000
	p.fl1 x30, x6
	sw x30, 4(sp)
	xor x31, x31, x30
	li x9, 0x59ca8033
	p.ff1 x30, x9
	sw x30, 4(sp)
	xor x31, x31, x30
	li x12, 0x7a219d3c
	p.extract x30, x12, 5, 9
	sw x30, 4(sp)
	xor x31, x31, x30
	li x15, 0xf379014f
	p.extract x30, x15, 29, 16
	sw x30, 4(sp)
	xor x31, x31, x30
	li x18, 0x2e000000
	p.ff1 x30, x18
	sw x30, 4(sp)
	xor x31, x31, x30
	li x21, 0xed76c80a
	p.extract x30, x21, 16, 11
	sw x30, 4(sp)
	xor x31, x31, x30
	li x24, 0xf6bb6405
	p.extract x30, x24, 12, 21
	sw x30, 4(sp)
	xor x31, x31, x30
	li x27, 0x56da1e08
	p.ff1 x30, x27
	sw x30, 4(sp)
	xor x31, x31, x30
	li x3, 0xfcba5a78
	p.extract x30, x3, 20, 23
	sw x30, 4(sp)
	xor x31, x31, x30
	li x6, 0x165d2d3c
	p.extract x30, x6, 29, 27
	sw x30, 4(sp)
	xor x31, x31, x30
	li x9, 0xc81621c5
	p.extract x30, x9, 22, 31
	sw x30, 4(sp)
	xor x31, x31, x30
	li x12, 0x6a69fc37
	p.extract x30, x12, 23, 17
	sw x30, 4(sp)
	xor x31, x31, x30
	li x15, 0x77
	p.fl1 x30, x15
	sw x30, 4(sp)
	xor x31, x31, x30
	li x18, 0x205b0f73
	li x19, 0x612e0f98
	pv.cmpne.b x30, x18, x19
	sw x30, 4(sp)
	xor x31, x31, x30
	li x21, 0x585ddab4
	p.clip x30, x21, 4
	sw x30, 4(sp)
	xor x31, x31, x30
	li x24, 0x4000
	p.ff1 x30, x24
	sw x30, 4(sp)
	xor x31, x31, x30
	li x27, 0x10f1a4ce
	p.fl1 x30, x27
	sw x30, 4(sp)
	xor x31, x31, x30
	li x3, 0x5f9c89ff
	li x4, 0x669a88fe
	pv.cmpleu.b x30, x3, x4
	sw x30, 4(sp)
	xor x31, x31, x30
	li x6, 0x488c9aa7
	li x7, 0x6e397bf
	pv.cmpne.b x30, x6, x7
	sw x30, 4(sp)
	xor x31, x31, x30
	li x9, 0xdd77e5e0
	p.ff1 x30, x9
	sw x30, 4(sp)
	xor x31, x31, x30
	li x12, 0x6d7c5fdb
	p.extract x30, x12, 25, 13
	sw x30, 4(sp)
	xor x31, x31, x30
	li x15, 0x8687ab7f
	p.extract x30, x15, 30, 9
	sw x30, 4(sp)
	xor x31, x31, x30
	li x18, 0x8343d5bf
	p.extract x30, x18, 31, 24
	sw x30, 4(sp)
	xor x31, x31, x30
	li x21, 0x9a399a7d
	p.extract x30, x21, 30, 30
	sw x30, 4(sp)
	xor x31, x31, x30
	li x24, 0xa0ca9ae9
	p.extract x30, x24, 11, 20
	sw x30, 4(sp)
	xor x31, x31, x30
	li x27, 0xe832a6ba
	li x28, 0x4d6da891
	pv.shuffle2.b x30, x27, x28
	sw x30, 4(sp)
	xor x31, x31, x30
	li x3, 0xdd800000
	p.ff1 x30, x3
	sw x30, 4(sp)
	xor x31, x31, x30
	li x6, 0x800
	p.ff1 x30, x6
	sw x30, 4(sp)
	xor x31, x31, x30
	li x9, 0x2cc63e00
	p.ff1 x30, x9
	sw x30, 4(sp)
	xor x31, x31, x30
	li x12, 0x32cf9d1b
	li x13, 0x32cf54cd
	pv.cmpgtu.h x30, x12, x13
	sw x30, 4(sp)
	xor x31, x31, x30
	li x15, 0x3f35e06a
	p.extract x30, x15, 17, 28
	sw x30, 4(sp)
	xor x31, x31, x30
	li x18, 0x5008df53
	li x19, 0xe663df70
	pv.cmpne.b x30, x18, x19
	sw x30, 4(sp)
	xor x31, x31, x30
	li x21, 0x400000
	p.fl1 x30, x21
	sw x30, 4(sp)
	xor x31, x31, x30
	li x24, 0xc596650b
	li x25, 0xc518c0d6
	pv.cmple.b x30, x24, x25
	sw x30, 4(sp)
	xor x31, x31, x30
	li x27, 0xc14b3285
	li x28, 0x9e0c606b
	pv.shuffle2.b x30, x27, x28
	sw x30, 4(sp)
	xor a0, x31, x30

	ret
