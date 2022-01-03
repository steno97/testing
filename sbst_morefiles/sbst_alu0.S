	.section .text
	.global _sbst_alu0
	.type _sbst_alu0, @function

_sbst_alu0:
	xor x31, x31, x31
	xor x30, x30, x30

	li x3, 0x7dfb83c4
	li x4, 0x800376c4
	pv.cmpge.h x30, x3, x4
	sw x30, 4(sp)
	xor x31, x31, x30
	li x6, 0x285a0151
	p.clb x30, x6
	sw x30, 4(sp)
	xor x31, x31, x30
	li x9, 0x3e000000
	p.ff1 x30, x9
	sw x30, 4(sp)
	xor x31, x31, x30
	li x12, 0xb136f82a
	li x13, 0xb13617c7
	p.subRN x30, x12, x13, 8
	sw x30, 4(sp)
	xor x31, x31, x30
	li x15, 0x4ff5f5ee
	li x16, 0x4d8adc11
	pv.packlo.b x30, x15, x16
	sw x30, 4(sp)
	xor x31, x31, x30
	li x18, 0x5e2ef8d3
	li x19, 0x5e264dd2
	pv.sra.h x30, x18, x19
	sw x30, 4(sp)
	xor x31, x31, x30
	li x21, 0x73cd6f42
	li x22, 0x7322907d
	pv.or.b x30, x21, x22
	sw x30, 4(sp)
	xor x31, x31, x30
	li x24, 0xb4aabf1c
	li x25, 0xde07dcf4
	pv.sll.h x30, x24, x25
	sw x30, 4(sp)
	xor x31, x31, x30
	li x27, 0xc94a93ae
	li x28, 0x25bbeda8
	pv.sub.h x30, x27, x28
	sw x30, 4(sp)
	xor x31, x31, x30
	li x3, 0xde52a544
	li x4, 0xe279fff6
	pv.and.h x30, x3, x4
	sw x30, 4(sp)
	xor x31, x31, x30
	li x6, 0xf3df2526
	li x7, 0x6970d2cb
	pv.xor.b x30, x6, x7
	sw x30, 4(sp)
	xor x31, x31, x30
	li x9, 0xc42eabf
	li x10, 0x1b7dea80
	pv.cmplt.h x30, x9, x10
	sw x30, 4(sp)
	xor x31, x31, x30
	li x12, 0x6d38c0e6
	p.exths x30, x12
	sw x30, 4(sp)
	xor x31, x31, x30
	li x15, 0x0
	p.cnt x30, x15
	sw x30, 4(sp)
	xor x31, x31, x30
	li x18, 0xffffffff
	p.cnt x30, x18
	sw x30, 4(sp)
	xor x31, x31, x30
	li x21, 0xd47d4ad3
	li x22, 0x2e26fd00
	pv.sll.h x30, x21, x22
	sw x30, 4(sp)
	xor x31, x31, x30
	li x24, 0x7e3f871f
	li x25, 0x7e3fa71f
	p.ror x30, x24, x25
	sw x30, 4(sp)
	xor x31, x31, x30
	li x27, 0xc7d7c85d
	li x28, 0x6e6aff62
	p.subuN x30, x27, x28, 1
	sw x30, 4(sp)
	xor x31, x31, x30
	li x3, 0x9228410
	pv.abs.b x30, x3
	sw x30, 4(sp)
	xor x31, x31, x30
	li x6, 0xe3fd265c
	li x7, 0x3ea0257
	p.subuN x30, x6, x7, 1
	sw x30, 4(sp)
	xor x31, x31, x30
	li x9, 0x8656d2ba
	p.extract x30, x9, 30, 0
	sw x30, 4(sp)
	xor x31, x31, x30
	li x12, 0x56dbe998
	p.abs x30, x12
	sw x30, 4(sp)
	xor x31, x31, x30
	li x15, 0x9ce5f3c0
	li x16, 0xeaa7ffc0
	p.addRN x30, x15, x16, 1
	sw x30, 4(sp)
	xor x31, x31, x30
	li x18, 0x4bfffffb
	p.extract x30, x18, 31, 3
	sw x30, 4(sp)
	xor x31, x31, x30
	li x21, 0x29e72fbf
	li x22, 0xb69efec2
	sra x30, x21, x22
	sw x30, 4(sp)
	xor x31, x31, x30
	li x24, 0x71339565
	li x25, 0x758a0828
	pv.sll.b x30, x24, x25
	sw x30, 4(sp)
	xor x31, x31, x30
	li x27, 0x6d19400
	li x28, 0x46d8e26e
	pv.packlo.b x30, x27, x28
	sw x30, 4(sp)
	xor x31, x31, x30
	li x3, 0xfffffffd
	p.cnt x30, x3
	sw x30, 4(sp)
	xor x31, x31, x30
	li x6, 0xfffbffff
	p.cnt x30, x6
	sw x30, 4(sp)
	xor x31, x31, x30
	li x9, 0x8ddfaa7e
	pv.abs.h x30, x9
	sw x30, 4(sp)
	xor x31, x31, x30
	li x12, 0x6d3247d1
	li x13, 0xcd3247d1
	p.addRN x30, x12, x13, 12
	sw x30, 4(sp)
	xor x31, x31, x30
	li x15, 0x210a51ce
	li x16, 0x214a51ce
	sra x30, x15, x16
	sw x30, 4(sp)
	xor x31, x31, x30
	li x18, 0x98e0c8e8
	p.bset x30, x18, 19, 7
	sw x30, 4(sp)
	xor x31, x31, x30
	li x21, 0xd55edca2
	pv.abs.h x30, x21
	sw x30, 4(sp)
	xor x31, x31, x30
	li x24, 0xce3ef6cb
	p.extract x30, x24, 2, 11
	sw x30, 4(sp)
	xor x31, x31, x30
	li x27, 0xbede9025
	p.abs x30, x27
	sw x30, 4(sp)
	xor x31, x31, x30
	li x3, 0x63c29020
	li x4, 0x7be752d2
	pv.shuffle.b x30, x3, x4
	sw x30, 4(sp)
	xor x31, x31, x30
	li x6, 0xd2d61893
	p.bset x30, x6, 0, 2
	sw x30, 4(sp)
	xor x31, x31, x30
	li x9, 0x3c1e58f5
	p.insert x30, x9, 15, 3
	sw x30, 4(sp)
	xor x31, x31, x30
	li x12, 0xd2738a90
	li x13, 0xe54212c2
	p.adduRN x30, x12, x13, 1
	sw x30, 4(sp)
	xor x31, x31, x30
	li x15, 0xb72baf43
	li x16, 0x8f1074ba
	pv.sll.h x30, x15, x16
	sw x30, 4(sp)
	xor x31, x31, x30
	li x18, 0xfdbc4c78
	li x19, 0x78c3a53
	p.ror x30, x18, x19
	sw x30, 4(sp)
	xor x31, x31, x30
	li x21, 0x5b4b5834
	li x22, 0x99d4f891
	pv.sll.h x30, x21, x22
	sw x30, 4(sp)
	xor x31, x31, x30
	li x24, 0xd10f5dd5
	li x25, 0xd10b5dd5
	p.ror x30, x24, x25
	sw x30, 4(sp)
	xor x31, x31, x30
	li x27, 0xf871ac00
	p.clip x30, x27, 10
	sw x30, 4(sp)
	xor x31, x31, x30
	li x3, 0xeb1109c3
	li x4, 0xeb0bebf7
	pv.cmpltu.h x30, x3, x4
	sw x30, 4(sp)
	xor x31, x31, x30
	li x6, 0x53bcbb01
	li x7, 0xcebb3b85
	pv.packhi.b x30, x6, x7
	sw x30, 4(sp)
	xor x31, x31, x30
	li x9, 0x3020000
	p.clb x30, x9
	sw x30, 4(sp)
	xor x31, x31, x30
	li x12, 0xea460fb6
	li x13, 0xbd0bb441
	p.subRN x30, x12, x13, 13
	sw x30, 4(sp)
	xor x31, x31, x30
	li x15, 0x4f526b96
	li x16, 0x602ef1a4
	pv.sll.b x30, x15, x16
	sw x30, 4(sp)
	xor x31, x31, x30
	li x18, 0xb43f5d1d
	li x19, 0xb03f5d1d
	pv.xor.b x30, x18, x19
	sw x30, 4(sp)
	xor x31, x31, x30
	li x21, 0xc1d55278
	li x22, 0xc1d5527a
	p.ror x30, x21, x22
	sw x30, 4(sp)
	xor x31, x31, x30
	li x24, 0x4f13d5e8
	li x25, 0x4f14e9d9
	pv.cmpleu.h x30, x24, x25
	sw x30, 4(sp)
	xor x31, x31, x30
	li x27, 0x2ace8e24
	li x28, 0x1d316fa8
	p.adduN x30, x27, x28, 1
	sw x30, 4(sp)
	xor x31, x31, x30
	li x3, 0x1c2ff88c
	li x4, 0x1c2f0f6d
	pv.maxu.b x30, x3, x4
	sw x30, 4(sp)
	xor x31, x31, x30
	li x6, 0x59d73807
	li x7, 0x59d73847
	p.ror x30, x6, x7
	sw x30, 4(sp)
	xor x31, x31, x30
	li x9, 0x2080407
	li x10, 0x6e773a82
	pv.sub.b x30, x9, x10
	sw x30, 4(sp)
	xor x31, x31, x30
	li x12, 0xbd846a63
	li x13, 0x42d3a530
	xor x30, x12, x13
	sw x30, 4(sp)
	xor x31, x31, x30
	li x15, 0x34f4020a
	li x16, 0x6fe0f93d
	p.ror x30, x15, x16
	sw x30, 4(sp)
	xor x31, x31, x30
	li x18, 0xf165411
	li x19, 0xf87a47e8
	pv.shuffle2.h x30, x18, x19
	sw x30, 4(sp)
	xor x31, x31, x30
	li x21, 0xfffffbfd
	p.cnt x30, x21
	sw x30, 4(sp)
	xor x31, x31, x30
	li x24, 0x7fff51ff
	li x25, 0x1d8b7eba
	pv.and.h x30, x24, x25
	sw x30, 4(sp)
	xor x31, x31, x30
	li x27, 0x707b83c4
	li x28, 0xf7b8378
	bne x27, x28, branchx0
	branchx0:
	sw x30, 4(sp)
	xor x31, x31, x30
	li x3, 0xcbdd6e85
	p.insert x30, x3, 7, 7
	sw x30, 4(sp)
	xor x31, x31, x30
	li x6, 0xd4050005
	li x7, 0xe42effff
	p.subRN x30, x6, x7, 5
	sw x30, 4(sp)
	xor x31, x31, x30
	li x9, 0xa32b12a6
	li x10, 0x1cc8a67f
	p.subRN x30, x9, x10, 19
	sw x30, 4(sp)
	xor x31, x31, x30
	li x12, 0x2079e9c5
	li x13, 0x9beeeaba
	p.ror x30, x12, x13
	sw x30, 4(sp)
	xor x31, x31, x30
	li x15, 0xa389f038
	li x16, 0xa389f03c
	p.ror x30, x15, x16
	sw x30, 4(sp)
	xor x31, x31, x30
	li x18, 0xdfdbb77c
	li x19, 0xe899b1be
	pv.sra.h x30, x18, x19
	sw x30, 4(sp)
	xor x31, x31, x30
	li x21, 0x109a505e
	p.clip x30, x21, 31
	sw x30, 4(sp)
	xor x31, x31, x30
	li x24, 0xffffffff
	p.clb x30, x24
	sw x30, 4(sp)
	xor x31, x31, x30
	li x27, 0xefe28416
	p.cnt x30, x27
	sw x30, 4(sp)
	xor x31, x31, x30
	li x3, 0x94a8e41a
	li x4, 0x71d77fed
	pv.shuffle2.b x30, x3, x4
	sw x30, 4(sp)
	xor x31, x31, x30
	li x6, 0x31ecffbf
	li x7, 0x38650b45
	pv.and.b x30, x6, x7
	sw x30, 4(sp)
	xor x31, x31, x30
	li x9, 0xfbe87378
	li x10, 0xfbe87378
	bne x9, x10, branchx1
	branchx1:
	sw x30, 4(sp)
	xor x31, x31, x30
	li x12, 0x8f5fffd3
	p.bclr x30, x12, 12, 6
	sw x30, 4(sp)
	xor x31, x31, x30
	li x15, 0xfc9c94f6
	li x16, 0xfc9996cc
	pv.cmpleu.h x30, x15, x16
	sw x30, 4(sp)
	xor x31, x31, x30
	li x18, 0x4c1b247b
	li x19, 0xd86a25e2
	sub x30, x18, x19
	sw x30, 4(sp)
	xor x31, x31, x30
	li x21, 0x797909f8
	p.extract x30, x21, 6, 24
	sw x30, 4(sp)
	xor x31, x31, x30
	li x24, 0xbc78915f
	p.extract x30, x24, 8, 11
	sw x30, 4(sp)
	xor x31, x31, x30
	li x27, 0x593ce9ab
	li x28, 0xeb59b924
	sll x30, x27, x28
	sw x30, 4(sp)
	xor x31, x31, x30
	li x3, 0x1d89f6a6
	li x4, 0x9b83a2ab
	pv.shuffle2.b x30, x3, x4
	sw x30, 4(sp)
	xor x31, x31, x30
	li x6, 0x478f1b3c
	li x7, 0x47901bfc
	pv.cmplt.h x30, x6, x7
	sw x30, 4(sp)
	xor x31, x31, x30
	li x9, 0xc375af58
	li x10, 0x62ca1313
	pv.shuffle2.b x30, x9, x10
	sw x30, 4(sp)
	xor x31, x31, x30
	li x12, 0x14bd015d
	li x13, 0xd748f631
	pv.shuffle2.h x30, x12, x13
	sw x30, 4(sp)
	xor x31, x31, x30
	li x15, 0xffffdffc
	p.cnt x30, x15
	sw x30, 4(sp)
	xor x31, x31, x30
	li x18, 0x4295e1ab
	li x19, 0xbeef79c6
	pv.sra.b x30, x18, x19
	sw x30, 4(sp)
	xor x31, x31, x30
	li x21, 0x85e8ff2e
	li x22, 0xfd1ebc97
	pv.sub.h x30, x21, x22
	sw x30, 4(sp)
	xor x31, x31, x30
	li x24, 0x35b2fadb
	p.extract x30, x24, 0, 20
	sw x30, 4(sp)
	xor x31, x31, x30
	li x27, 0x8b34e51d
	p.abs x30, x27
	sw x30, 4(sp)
	xor x31, x31, x30
	li x3, 0x5af85a02
	li x4, 0xea8f0576
	p.ror x30, x3, x4
	sw x30, 4(sp)
	xor x31, x31, x30
	li x6, 0x1c8c134f
	pv.abs.b x30, x6
	sw x30, 4(sp)
	xor x31, x31, x30
	li x9, 0xf3ffffff
	p.cnt x30, x9
	sw x30, 4(sp)
	xor x31, x31, x30
	li x12, 0x4d46d355
	li x13, 0x8ea10191
	pv.shuffle2.b x30, x12, x13
	sw x30, 4(sp)
	xor x31, x31, x30
	li x15, 0xff9eb215
	li x16, 0xc99fe184
	p.adduRN x30, x15, x16, 0
	sw x30, 4(sp)
	xor x31, x31, x30
	li x18, 0x901d1eaa
	li x19, 0x902d1eb2
	pv.cmplt.b x30, x18, x19
	sw x30, 4(sp)
	xor x31, x31, x30
	li x21, 0x843d4924
	li x22, 0x31a25322
	pv.cmpgtu.b x30, x21, x22
	sw x30, 4(sp)
	xor x31, x31, x30
	li x24, 0xee5feabb
	li x25, 0x85a35c9e
	srl x30, x24, x25
	sw x30, 4(sp)
	xor x31, x31, x30
	li x27, 0x9d0a29f8
	p.abs x30, x27
	sw x30, 4(sp)
	xor x31, x31, x30
	li x3, 0x32ef3ddb
	li x4, 0x3221ba49
	pv.sll.b x30, x3, x4
	sw x30, 4(sp)
	xor x31, x31, x30
	li x6, 0x3e3dab1d
	li x7, 0x457f9627
	pv.shuffle.b x30, x6, x7
	sw x30, 4(sp)
	xor x31, x31, x30
	li x9, 0xaf5d9820
	p.ff1 x30, x9
	sw x30, 4(sp)
	xor x31, x31, x30
	li x12, 0xd537c83b
	li x13, 0xa0060a14
	pv.pack.h x30, x12, x13
	sw x30, 4(sp)
	xor x31, x31, x30
	li x15, 0xbcffe39c
	li x16, 0x9cff2068
	p.addRN x30, x15, x16, 0
	sw x30, 4(sp)
	xor x31, x31, x30
	li x18, 0xcd692323
	li x19, 0x73bc685f
	p.ror x30, x18, x19
	sw x30, 4(sp)
	xor x31, x31, x30
	li x21, 0x79fe6f6f
	p.extract x30, x21, 31, 31
	sw x30, 4(sp)
	xor x31, x31, x30
	li x24, 0x14c9edcc
	li x25, 0x2bc4ecc7
	pv.minu.b x30, x24, x25
	sw x30, 4(sp)
	xor x31, x31, x30
	li x27, 0x0
	p.ff1 x30, x27
	sw x30, 4(sp)
	xor x31, x31, x30
	li x3, 0xffffeff4
	p.cnt x30, x3
	sw x30, 4(sp)
	xor x31, x31, x30
	li x6, 0xe1944347
	li x7, 0xe037e6ff
	pv.cmpgeu.h x30, x6, x7
	sw x30, 4(sp)
	xor x31, x31, x30
	li x9, 0x6bb9f9a3
	li x10, 0xa69df779
	pv.shuffle.b x30, x9, x10
	sw x30, 4(sp)
	xor x31, x31, x30
	li x12, 0x4d28461f
	p.extract x30, x12, 5, 16
	sw x30, 4(sp)
	xor x31, x31, x30
	li x15, 0x4b481187
	p.extract x30, x15, 10, 11
	sw x30, 4(sp)
	xor x31, x31, x30
	li x18, 0x7dd0aeca
	li x19, 0xf8f571c5
	pv.shuffle.b x30, x18, x19
	sw x30, 4(sp)
	xor x31, x31, x30
	li x21, 0x390d73bc
	li x22, 0x64fb6d80
	pv.sub.h x30, x21, x22
	sw x30, 4(sp)
	xor x31, x31, x30
	li x24, 0x1fe4356
	li x25, 0x2eadd306
	p.addRN x30, x24, x25, 3
	sw x30, 4(sp)
	xor x31, x31, x30
	li x27, 0x94d30362
	li x28, 0x562040a
	pv.packhi.b x30, x27, x28
	sw x30, 4(sp)
	xor x31, x31, x30
	li x3, 0xfa8198f8
	li x4, 0x72818008
	p.subuN x30, x3, x4, 18
	sw x30, 4(sp)
	xor x31, x31, x30
	li x6, 0xb6685431
	li x7, 0x9c7118cd
	pv.shuffle2.h x30, x6, x7
	sw x30, 4(sp)
	xor x31, x31, x30
	li x9, 0xc6482891
	li x10, 0x5ff98424
	pv.pack.h x30, x9, x10
	sw x30, 4(sp)
	xor x31, x31, x30
	li x12, 0x20
	p.fl1 x30, x12
	sw x30, 4(sp)
	xor x31, x31, x30
	li x15, 0x40200025
	p.clb x30, x15
	sw x30, 4(sp)
	xor x31, x31, x30
	li x18, 0x1c3a2dd
	p.fl1 x30, x18
	sw x30, 4(sp)
	xor x31, x31, x30
	li x21, 0x66769f93
	li x22, 0x69769e94
	pv.cmpgeu.b x30, x21, x22
	sw x30, 4(sp)
	xor x31, x31, x30
	li x24, 0x5763f77e
	p.bclr x30, x24, 31, 1
	sw x30, 4(sp)
	xor x31, x31, x30
	li x27, 0x2b81fbb3
	li x28, 0x68f33e39
	p.ror x30, x27, x28
	sw x30, 4(sp)
	xor x31, x31, x30
	li x3, 0x6350d060
	li x4, 0x6350cf6d
	p.slet x30, x3, x4
	sw x30, 4(sp)
	xor x31, x31, x30
	li x6, 0x1d09bc
	p.extract x30, x6, 16, 27
	sw x30, 4(sp)
	xor x31, x31, x30
	li x9, 0xc0fb517
	p.bset x30, x9, 28, 3
	sw x30, 4(sp)
	xor x31, x31, x30
	li x12, 0xd614037b
	li x13, 0x80254cb5
	pv.shuffle.b x30, x12, x13
	sw x30, 4(sp)
	xor x31, x31, x30
	li x15, 0x806b
	p.fl1 x30, x15
	sw x30, 4(sp)
	xor x31, x31, x30
	li x18, 0x80100000
	p.ff1 x30, x18
	sw x30, 4(sp)
	xor x31, x31, x30
	li x21, 0xf83197c1
	p.abs x30, x21
	sw x30, 4(sp)
	xor x31, x31, x30
	li x24, 0xc3479ca3
	p.clipu x30, x24, 17
	sw x30, 4(sp)
	xor x31, x31, x30
	li x27, 0xade8849
	p.clip x30, x27, 28
	sw x30, 4(sp)
	xor x31, x31, x30
	li x3, 0xcef1af62
	li x4, 0xcef1afbe
	p.slet x30, x3, x4
	sw x30, 4(sp)
	xor x31, x31, x30
	li x6, 0x1d91fdab
	p.clb x30, x6
	sw x30, 4(sp)
	xor x31, x31, x30
	li x9, 0x4000
	p.ff1 x30, x9
	sw x30, 4(sp)
	xor x31, x31, x30
	li x12, 0xe5d3b54c
	li x13, 0x7d25fb51
	xor x30, x12, x13
	sw x30, 4(sp)
	xor x31, x31, x30
	li x15, 0x66e9fbfb
	li x16, 0x62b2fbfb
	pv.cmpgt.h x30, x15, x16
	sw x30, 4(sp)
	xor x31, x31, x30
	li x18, 0x410415e1
	li x19, 0xb6739491
	pv.shuffle2.b x30, x18, x19
	sw x30, 4(sp)
	xor x31, x31, x30
	li x21, 0xcf5b2dca
	li x22, 0xcf5b1f63
	bge x21, x22, branchx2
	branchx2:
	sw x30, 4(sp)
	xor x31, x31, x30
	li x24, 0x5458fee5
	p.extract x30, x24, 4, 13
	sw x30, 4(sp)
	xor x31, x31, x30
	li x27, 0xcecb9b37
	p.extract x30, x27, 12, 19
	sw x30, 4(sp)
	xor x31, x31, x30
	li x3, 0x45f777fc
	li x4, 0x45b377bc
	pv.cmpeq.h x30, x3, x4
	sw x30, 4(sp)
	xor x31, x31, x30
	li x6, 0xd9e10f3f
	p.cnt x30, x6
	sw x30, 4(sp)
	xor x31, x31, x30
	li x9, 0x70f8baa
	p.abs x30, x9
	sw x30, 4(sp)
	xor x31, x31, x30
	li x12, 0xfffeffff
	p.cnt x30, x12
	sw x30, 4(sp)
	xor x31, x31, x30
	li x15, 0x4c5b7e80
	p.ff1 x30, x15
	sw x30, 4(sp)
	xor x31, x31, x30
	li x18, 0x5c3d506d
	li x19, 0xaf02506d
	pv.cmpleu.h x30, x18, x19
	sw x30, 4(sp)
	xor x31, x31, x30
	li x21, 0x129eab0a
	li x22, 0x120108d1
	p.slet x30, x21, x22
	sw x30, 4(sp)
	xor x31, x31, x30
	li x24, 0xb75e16c2
	p.extract x30, x24, 17, 27
	sw x30, 4(sp)
	xor x31, x31, x30
	li x27, 0x7f337995
	li x28, 0xdc7297bc
	p.ror x30, x27, x28
	sw x30, 4(sp)
	xor x31, x31, x30
	li x3, 0x40aa
	p.fl1 x30, x3
	sw x30, 4(sp)
	xor x31, x31, x30
	li x6, 0x88845ea2
	p.bset x30, x6, 15, 5
	sw x30, 4(sp)
	xor x31, x31, x30
	li x9, 0x713a8bd4
	p.extract x30, x9, 15, 15
	sw x30, 4(sp)
	xor x31, x31, x30
	li x12, 0x2bef955
	p.clip x30, x12, 4
	sw x30, 4(sp)
	xor x31, x31, x30
	li x15, 0x2000
	p.clipu x30, x15, 25
	sw x30, 4(sp)
	xor x31, x31, x30
	li x18, 0xdf6387c1
	li x19, 0xdf3289c0
	pv.maxu.b x30, x18, x19
	sw x30, 4(sp)
	xor x31, x31, x30
	li x21, 0x9471c8d2
	li x22, 0x13f900bc
	pv.pack.h x30, x21, x22
	sw x30, 4(sp)
	xor x31, x31, x30
	li x24, 0x4a38e469
	li x25, 0x9fcffde
	pv.pack.h x30, x24, x25
	sw x30, 4(sp)
	xor x31, x31, x30
	li x27, 0xfffffffa
	p.cnt x30, x27
	sw x30, 4(sp)
	xor a0, x31, x30

ret
