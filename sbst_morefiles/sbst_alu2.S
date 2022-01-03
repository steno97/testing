	.section .text
	.global _sbst_alu2
	.type _sbst_alu2, @function

_sbst_alu2:
	xor x31, x31, x31
	xor x30, x30, x30
	
	li x3, 0xee63a375
	li x4, 0xecca99af
	pv.cmpge.h x30, x3, x4
	sw x30, 4(sp)
	xor x31, x31, x30
	li x6, 0xbc98e8dd
	li x7, 0xbc32a66b
	pv.cmpleu.b x30, x6, x7
	sw x30, 4(sp)
	xor x31, x31, x30
	li x9, 0x430ecab8
	li x10, 0x410dee41
	p.addRN x30, x9, x10, 19
	sw x30, 4(sp)
	xor x31, x31, x30
	li x12, 0xbbec3910
	p.ff1 x30, x12
	sw x30, 4(sp)
	xor x31, x31, x30
	li x15, 0x1000
	p.ff1 x30, x15
	sw x30, 4(sp)
	xor x31, x31, x30
	li x18, 0x80000
	p.fl1 x30, x18
	sw x30, 4(sp)
	xor x31, x31, x30
	li x21, 0x60000000
	p.ff1 x30, x21
	sw x30, 4(sp)
	xor x31, x31, x30
	li x24, 0xa0ececdf
	li x25, 0xa2ec6000
	pv.packlo.b x30, x24, x25
	sw x30, 4(sp)
	xor x31, x31, x30
	li x27, 0xda015452
	p.bset x30, x27, 27, 0
	sw x30, 4(sp)
	xor x31, x31, x30
	li x3, 0xcec69972
	li x4, 0xcec89972
	pv.cmpgeu.h x30, x3, x4
	sw x30, 4(sp)
	xor x31, x31, x30
	li x6, 0x2b5651e2
	p.abs x30, x6
	sw x30, 4(sp)
	xor x31, x31, x30
	li x9, 0xf7beb801
	li x10, 0x1d006eff
	pv.sub.h x30, x9, x10
	sw x30, 4(sp)
	xor x31, x31, x30
	li x12, 0xa7be39c4
	li x13, 0xa7be70b4
	pv.sll.h x30, x12, x13
	sw x30, 4(sp)
	xor x31, x31, x30
	li x15, 0x788fbc21
	li x16, 0x5852efff
	pv.packlo.b x30, x15, x16
	sw x30, 4(sp)
	xor x31, x31, x30
	li x18, 0x6bb0169f
	li x19, 0x6a199a17
	pv.shuffle.b x30, x18, x19
	sw x30, 4(sp)
	xor x31, x31, x30
	li x21, 0x3d6bf03
	li x22, 0x8370f7ff
	pv.packhi.b x30, x21, x22
	sw x30, 4(sp)
	xor x31, x31, x30
	li x24, 0xdc104e7e
	p.abs x30, x24
	sw x30, 4(sp)
	xor x31, x31, x30
	li x27, 0xb522a471
	li x28, 0xb562a471
	pv.shuffle.h x30, x27, x28
	sw x30, 4(sp)
	xor x31, x31, x30
	li x3, 0x81316f4c
	p.insert x30, x3, 30, 14
	sw x30, 4(sp)
	xor x31, x31, x30
	li x6, 0xfeb44911
	p.cnt x30, x6
	sw x30, 4(sp)
	xor x31, x31, x30
	li x9, 0x9bbee988
	li x10, 0xfb0d22f2
	pv.shuffle2.b x30, x9, x10
	sw x30, 4(sp)
	xor x31, x31, x30
	li x12, 0x7c0ff884
	p.bclr x30, x12, 23, 14
	sw x30, 4(sp)
	xor x31, x31, x30
	li x15, 0x5afe3188
	p.bclr x30, x15, 6, 19
	sw x30, 4(sp)
	xor x31, x31, x30
	li x18, 0x8e000000
	p.ff1 x30, x18
	sw x30, 4(sp)
	xor x31, x31, x30
	li x21, 0xffffffff
	p.insert x30, x21, 0, 0
	sw x30, 4(sp)
	xor x31, x31, x30
	li x24, 0x1c7e996
	p.clip x30, x24, 6
	sw x30, 4(sp)
	xor x31, x31, x30
	li x27, 0x1c0a2882
	p.clb x30, x27
	sw x30, 4(sp)
	xor x31, x31, x30
	li x3, 0x1
	p.fl1 x30, x3
	sw x30, 4(sp)
	xor x31, x31, x30
	li x6, 0x10
	p.fl1 x30, x6
	sw x30, 4(sp)
	xor x31, x31, x30
	li x9, 0xa0fd41a2
	p.exthz x30, x9
	sw x30, 4(sp)
	xor x31, x31, x30
	li x12, 0x8711f8b4
	p.abs x30, x12
	sw x30, 4(sp)
	xor x31, x31, x30

	li x15, 0x87a32a51
	p.extract x30, x15, 5, 8
	sw x30, 4(sp)
	xor x31, x31, x30
	li x18, 0xa57f57eb
	li x19, 0xa511e0c2
	pv.minu.h x30, x18, x19
	sw x30, 4(sp)
	xor x31, x31, x30
	li x21, 0xe4ff82c
	li x22, 0xfa8b2ecf
	pv.shuffle.b x30, x21, x22
	sw x30, 4(sp)
	xor x31, x31, x30
	li x24, 0xffffffff
	p.clb x30, x24
	sw x30, 4(sp)
	xor x31, x31, x30
	li x27, 0xb27bbe91
	li x28, 0xe7c60db
	pv.add.b x30, x27, x28
	sw x30, 4(sp)
	xor x31, x31, x30
	li x3, 0xa59d8000
	p.extract x30, x3, 25, 16
	sw x30, 4(sp)
	xor x31, x31, x30
	li x6, 0xc6629384
	p.extract x30, x6, 18, 24
	sw x30, 4(sp)
	xor x31, x31, x30
	li x9, 0xfcae718e
	li x10, 0x5cec609b
	pv.shuffle2.b x30, x9, x10
	sw x30, 4(sp)
	xor x31, x31, x30
	li x12, 0xa111baf8
	li x13, 0x1282f0f
	p.subuRN x30, x12, x13, 21
	sw x30, 4(sp)
	xor x31, x31, x30
	li x15, 0x618981c
	li x16, 0xf1af6ff6
	p.subRN x30, x15, x16, 7
	sw x30, 4(sp)
	xor x31, x31, x30
	li x18, 0x5311f6b7
	p.clip x30, x18, 25
	sw x30, 4(sp)
	xor x31, x31, x30
	li x21, 0x60d0db7d
	li x22, 0xbc1f7769
	pv.shuffle2.b x30, x21, x22
	sw x30, 4(sp)
	xor x31, x31, x30
	li x24, 0xfcb6c3df
	p.extract x30, x24, 2, 30
	sw x30, 4(sp)
	xor x31, x31, x30
	li x27, 0xa45e5b62
	li x28, 0xed86c092
	pv.shuffle2.b x30, x27, x28
	sw x30, 4(sp)
	xor x31, x31, x30
	li x3, 0x8aa4da8c
	li x4, 0x40faf7f1
	pv.shuffle2.b x30, x3, x4
	sw x30, 4(sp)
	xor x31, x31, x30
	li x6, 0x17de7f0e
	li x7, 0x2787e843
	pv.shuffle2.b x30, x6, x7
	sw x30, 4(sp)
	xor x31, x31, x30
	li x9, 0xb8ba031c
	li x10, 0xb840011a
	pv.maxu.b x30, x9, x10
	sw x30, 4(sp)
	xor x31, x31, x30
	li x12, 0x2bdf26b4
	li x13, 0x604056ba
	pv.pack.h x30, x12, x13
	sw x30, 4(sp)
	xor x31, x31, x30
	li x15, 0xfffdffff
	p.cnt x30, x15
	sw x30, 4(sp)
	xor x31, x31, x30
	li x18, 0xff9fab9b
	p.cnt x30, x18
	sw x30, 4(sp)
	xor x31, x31, x30
	li x21, 0x3ef1861b
	p.extract x30, x21, 24, 25
	sw x30, 4(sp)
	xor x31, x31, x30
	li x24, 0x8c306186
	p.extract x30, x24, 22, 24
	sw x30, 4(sp)
	xor x31, x31, x30
	li x27, 0xe2fe138a
	li x28, 0x9faafa06
	pv.packhi.b x30, x27, x28
	sw x30, 4(sp)
	xor x31, x31, x30
	li x3, 0xffffbffd
	p.cnt x30, x3
	sw x30, 4(sp)
	xor x31, x31, x30
	li x6, 0xb5b34eb7
	li x7, 0x7947b1be
	pv.sra.b x30, x6, x7
	sw x30, 4(sp)
	xor x31, x31, x30
	li x9, 0x27b11a4f
	li x10, 0xc59f66c9
	pv.shuffle2.h x30, x9, x10
	sw x30, 4(sp)
	xor x31, x31, x30
	li x12, 0x38
	p.ff1 x30, x12
	sw x30, 4(sp)
	xor x31, x31, x30
	li x15, 0x100000
	p.fl1 x30, x15
	sw x30, 4(sp)
	xor x31, x31, x30
	li x18, 0xe103e6ef
	p.extract x30, x18, 31, 16
	sw x30, 4(sp)
	xor x31, x31, x30
	li x21, 0xd940fffb
	p.bclr x30, x21, 31, 0
	sw x30, 4(sp)
	xor x31, x31, x30
	li x24, 0x6526dc5b
	li x25, 0x6526dc4b
	pv.cmpeq.h x30, x24, x25
	sw x30, 4(sp)
	xor x31, x31, x30
	li x27, 0x93fec40f
	li x28, 0x255778e8
	pv.sra.h x30, x27, x28
	sw x30, 4(sp)
	xor x31, x31, x30
	li x3, 0x3dc69e72
	li x4, 0x77c11e74
	pv.max.b x30, x3, x4
	sw x30, 4(sp)
	xor x31, x31, x30
	li x6, 0x5b7014e2
	li x7, 0x49d72004
	pv.pack.h x30, x6, x7
	sw x30, 4(sp)
	xor x31, x31, x30
	li x9, 0x42f3365d
	li x10, 0x9fbf9e76
	pv.pack.h x30, x9, x10
	sw x30, 4(sp)
	xor x31, x31, x30
	li x12, 0x285e66cb
	p.clb x30, x12
	sw x30, 4(sp)
	xor x31, x31, x30
	li x15, 0x4
	p.fl1 x30, x15
	sw x30, 4(sp)
	xor x31, x31, x30
	li x18, 0xc3f95380
	p.extract x30, x18, 5, 24
	sw x30, 4(sp)
	xor x31, x31, x30
	li x21, 0x39faa9c0
	p.extract x30, x21, 17, 28
	sw x30, 4(sp)
	xor x31, x31, x30
	li x24, 0x90fe54e0
	p.extract x30, x24, 21, 8
	sw x30, 4(sp)
	xor x31, x31, x30
	li x27, 0x40f011a
	p.fl1 x30, x27
	sw x30, 4(sp)
	xor x31, x31, x30
	li x3, 0x9c8ba034
	p.abs x30, x3
	sw x30, 4(sp)
	xor x31, x31, x30
	li x6, 0x374f416a
	li x7, 0xbcc17eef
	sra x30, x6, x7
	sw x30, 4(sp)
	xor x31, x31, x30
	li x9, 0x61aac49b
	p.clip x30, x9, 16
	sw x30, 4(sp)
	xor x31, x31, x30
	li x12, 0xc99ca688
	li x13, 0xc4325c82
	pv.maxu.b x30, x12, x13
	sw x30, 4(sp)
	xor x31, x31, x30
	li x15, 0x59540cce
	p.extract x30, x15, 1, 28
	sw x30, 4(sp)
	xor x31, x31, x30
	li x18, 0x18d97843
	p.extract x30, x18, 17, 30
	sw x30, 4(sp)
	xor x31, x31, x30
	li x21, 0x7e020000
	p.ff1 x30, x21
	sw x30, 4(sp)
	xor x31, x31, x30
	li x24, 0xfbf45d8d
	p.cnt x30, x24
	sw x30, 4(sp)
	xor x31, x31, x30
	li x27, 0x154535b2
	p.clip x30, x27, 2
	sw x30, 4(sp)
	xor x31, x31, x30
	li x3, 0x93cdf893
	li x4, 0x513df3c
	pv.pack.h x30, x3, x4
	sw x30, 4(sp)
	xor x31, x31, x30
	li x6, 0x4e105c70
	li x7, 0x4be5b9a0
	p.subuRN x30, x6, x7, 9
	sw x30, 4(sp)
	xor x31, x31, x30
	li x9, 0xc64b2c38
	p.extract x30, x9, 10, 25
	sw x30, 4(sp)
	xor x31, x31, x30
	li x12, 0xf1ead07b
	li x13, 0x13f4eff5
	pv.add.h x30, x12, x13
	sw x30, 4(sp)
	xor x31, x31, x30
	li x15, 0xc7cb08dd
	li x16, 0x33470c6e
	pv.shuffle2.b x30, x15, x16
	sw x30, 4(sp)
	xor x31, x31, x30
	li x18, 0x10000000
	p.ff1 x30, x18
	sw x30, 4(sp)
	xor x31, x31, x30
	li x21, 0xeff0d96a
	p.cnt x30, x21
	sw x30, 4(sp)
	xor x31, x31, x30
	li x24, 0xaaecd924
	li x25, 0xb0bd36b3
	p.adduRN x30, x24, x25, 5
	sw x30, 4(sp)
	xor x31, x31, x30
	li x27, 0xb296b385
	p.insert x30, x27, 16, 10
	sw x30, 4(sp)
	xor x31, x31, x30
	li x3, 0x27518b96
	p.clip x30, x3, 13
	sw x30, 4(sp)
	xor x31, x31, x30
	li x6, 0x3a953fc1
	li x7, 0xd6a719b2
	pv.max.b x30, x6, x7
	sw x30, 4(sp)
	xor x31, x31, x30
	li x9, 0x420dd666
	pv.abs.h x30, x9
	sw x30, 4(sp)
	xor x31, x31, x30
	li x12, 0x2a9
	p.fl1 x30, x12
	sw x30, 4(sp)
	xor x31, x31, x30
	li x15, 0xcda69016
	p.extract x30, x15, 24, 14
	sw x30, 4(sp)
	xor x31, x31, x30
	li x18, 0x26d3480b
	p.extract x30, x18, 30, 15
	sw x30, 4(sp)
	xor x31, x31, x30
	li x21, 0x4de
	p.fl1 x30, x21
	sw x30, 4(sp)
	xor x31, x31, x30
	li x24, 0x9411c69b
	p.clip x30, x24, 21
	sw x30, 4(sp)
	xor x31, x31, x30
	li x27, 0xfd1ecd95
	li x28, 0x8dfd3b98
	pv.max.b x30, x27, x28
	sw x30, 4(sp)
	xor x31, x31, x30
	li x3, 0xf7c8fc7
	p.extract x30, x3, 27, 18
	sw x30, 4(sp)
	xor x31, x31, x30
	li x6, 0x31db283
	p.clip x30, x6, 18
	sw x30, 4(sp)
	xor x31, x31, x30
	li x9, 0x10000
	p.fl1 x30, x9
	sw x30, 4(sp)
	xor x31, x31, x30
	li x12, 0x80212575
	p.abs x30, x12
	sw x30, 4(sp)
	xor x31, x31, x30
	li x15, 0x400000
	p.fl1 x30, x15
	sw x30, 4(sp)
	xor x31, x31, x30
	li x18, 0x13d440bb
	p.clip x30, x18, 31
	sw x30, 4(sp)
	xor x31, x31, x30
	li x21, 0x5dbc4e8
	p.clip x30, x21, 11
	sw x30, 4(sp)
	xor x31, x31, x30
	li x24, 0x4
	p.clipu x30, x24, 1
	sw x30, 4(sp)
	xor x31, x31, x30
	li x27, 0x25beeb68
	li x28, 0xd0b903fb
	pv.shuffle2.h x30, x27, x28
	sw x30, 4(sp)
	xor x31, x31, x30
	li x3, 0xcc0804f7
	p.extract x30, x3, 4, 0
	sw x30, 4(sp)
	xor x31, x31, x30
	li x6, 0x26040000
	p.ff1 x30, x6
	sw x30, 4(sp)
	xor x31, x31, x30
	li x9, 0x3c4633f9
	p.clip x30, x9, 22
	sw x30, 4(sp)
	xor x31, x31, x30
	li x12, 0xbb53fead
	p.clip x30, x12, 13
	sw x30, 4(sp)
	xor x31, x31, x30
	li x15, 0x4ec6b371
	p.extract x30, x15, 18, 20
	sw x30, 4(sp)
	xor x31, x31, x30
	li x18, 0xc066f40c
	li x19, 0xb2378deb
	pv.xor.h x30, x18, x19
	sw x30, 4(sp)
	xor x31, x31, x30
	li x21, 0x200
	p.ff1 x30, x21
	sw x30, 4(sp)
	xor x31, x31, x30
	li x24, 0x3309d1a9
	p.clip x30, x24, 6
	sw x30, 4(sp)
	xor x31, x31, x30
	li x27, 0x80
	p.clipu x30, x27, 15
	sw x30, 4(sp)
	xor x31, x31, x30
	li x3, 0xd5a54d5f
	p.extract x30, x3, 7, 10
	sw x30, 4(sp)
	xor x31, x31, x30
	li x6, 0xffffffdf
	p.cnt x30, x6
	sw x30, 4(sp)
	xor x31, x31, x30
	li x9, 0x3d800000
	p.ff1 x30, x9
	sw x30, 4(sp)
	xor x31, x31, x30

	//int_div_div section, reach 89%
	li x12, 0x82b92a82
	li x13, 0x7492bc6d
	rem x30, x12, x13
	sw x30, 4(sp)
	xor x31, x31, x30
	div x30, x13, x12
	sw x30, 4(sp)
	xor x31, x31, x30
	xori x18, x12, -1
	xori x19, x13, -1
	rem x30, x18, x19
	sw x30, 4(sp)
	xor x31, x31, x30
	div x30, x19, x18
	sw x30, 4(sp)
	xor x31, x31, x30
	ori x24, zero, -1
	rem x30, x24, x19
	sw x30, 4(sp)
	xor x31, x31, x30
	div x30, x19, x24
	sw x30, 4(sp)
	xor x31, x31, x30
	xori x3, x19, -1
	xori x4, x24, -1
	rem x30, x3, x4
	sw x30, 4(sp)
	xor x31, x31, x30
	div x30, x4, x3
	sw x30, 4(sp)
	xor x31, x31, x30
	li x9, 0x97e4f78f
	li x10, 0x2d7b55ca
	rem x30, x9, x10
	sw x30, 4(sp)
	xor x31, x31, x30
	div x30, x10, x9
	sw x30, 4(sp)
	xor x31, x31, x30
	xori x15, x10, -1
	xori x16, x9, -1
	rem x30, x16, x15
	sw x30, 4(sp)
	xor x31, x31, x30
	li x18, 0x12312312
	li x19, 0xf0f0f0f0
	rem x30, x18, x19
	sw x30, 4(sp)
	xor x31, x31, x30
	xori x21, x19, -1
	xori x22, x18, -1
	rem x30, x21, x22
	sw x30, 4(sp)
	xor x31, x31, x30
	li x24, 0xf2312312
	li x25, 0xdeadbeef
	remu x30, x24, x25
	sw x30, 4(sp)
	xor x31, x31, x30
	li x27, 0x77777777
	li x28, 0x35353535
	rem x30, x27, x28
	sw x30, 4(sp)
	xor x31, x31, x30

	//Custom made section
	li x3, 0x000000ff
	p.extbs x30, x3
	sw x30, 4(sp)
	xor x31, x31, x30
	p.extbz x30, x6
	li x6, 0x55555555
	p.extbs x30, x6
	sw x30, 4(sp)
	xor x31, x31, x30
	p.extbz x30, x9
	li x9, 0x33333333
	li x10, 0x55555555
	pv.shuffleI0.sci.b x30, x9, 63
	sw x30, 4(sp)
	xor x31, x31, x30
	pv.shuffleI1.sci.b x30, x10, 43
	sw x30, 4(sp)
	xor x31, x31, x30
	pv.shuffleI2.sci.b x30, x9, 21
	sw x30, 4(sp)
	xor x31, x31, x30
	pv.shuffleI3.sci.b x30, x10, 52
	sw x30, 4(sp)
	xor x31, x31, x30
	pv.shuffle.sci.h x30, x9, 53
	sw x30, 4(sp)
	xor x31, x31, x30
	p.min x30, x9, x10
	sw x30, 4(sp)
	xor x31, x31, x30
	p.max x30, x10, x9
	sw x30, 4(sp)
	xor x31, x31, x30
	pv.avg.b x30, x9, x10
	sw x30, 4(sp)
	xor x31, x31, x30
	pv.avg.h x30, x10, x9
	sw x30, 4(sp)
	xor x31, x31, x30
	pv.avg.sci.b x30, x9, 22
	sw x30, 4(sp)
	xor a0, x31, x30

	ret
