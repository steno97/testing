	.section .text
	.global _sbst_alu
	.type _sbst_alu, @function

_sbst_alu:
	li t0, 0x10e5d2a4
	li t1, 0x9ccfd160
	pv.cmpgt.h t2, t0, t1
	sw t2, 4(sp)
	li t0, 0x6512
	p.cnt t2, t0
	sw t2, 4(sp)
	li t0, 0x298efbed
	li t1, 0x298e9b85
	pv.packlo.b t2, t0, t1
	sw t2, 4(sp)
	li t0, 0x98778009
	li t1, 0x8b02ee40
	pv.sub.h t2, t0, t1
	sw t2, 4(sp)
	li t0, 0xd996b403
	li t1, 0xd9fdf05d
	pv.shuffle.b t2, t0, t1
	sw t2, 4(sp)
	li t0, 0x846e4b5b
	li t1, 0x859ff8b1
	pv.shuffle2.b t2, t0, t1
	sw t2, 4(sp)
	li t0, 0x90d952b1
	li t1, 0x4f23f4e2
	sll t2, t0, t1
	sw t2, 4(sp)
	li t0, 0xc8324a62
	li t1, 0xc8324a62
	and t2, t0, t1
	sw t2, 4(sp)
	li t0, 0x7f39000
	pv.abs.h t2, t0
	sw t2, 4(sp)
	li t0, 0x76be3802
	p.extract t2, t0, 15, 11
	sw t2, 4(sp)
	li t0, 0xd8a1dd9c
	li t1, 0xd0a1f00b
	pv.xor.h t2, t0, t1
	sw t2, 4(sp)
	li t0, 0xb7cbf81e
	li t1, 0xe5b49398
	pv.sub.h t2, t0, t1
	sw t2, 4(sp)
	li t0, 0xdcef5e4b
	li t1, 0xdcef764b
	sra t2, t0, t1
	sw t2, 4(sp)
	li t0, 0x8f14d177
	li t1, 0xf092ef02
	pv.add.b t2, t0, t1
	sw t2, 4(sp)
	li t0, 0x22da86e5
	li t1, 0x26da86e5
	pv.packlo.b t2, t0, t1
	sw t2, 4(sp)
	li t0, 0xaa4bcb25
	li t1, 0x8a8e22fd
	pv.shuffle2.b t2, t0, t1
	sw t2, 4(sp)
	li t0, 0x25044004
	li t1, 0x8280bffb
	pv.or.h t2, t0, t1
	sw t2, 4(sp)
	li t0, 0xdab17b52
	li t1, 0xdaf1407e
	pv.or.h t2, t0, t1
	sw t2, 4(sp)
	li t0, 0x3a6f2ef5
	li t1, 0xb3bf48f3
	pv.cmpge.b t2, t0, t1
	sw t2, 4(sp)
	li t0, 0x4841bfa7
	li t1, 0x4851e2b3
	pv.shuffle2.h t2, t0, t1
	sw t2, 4(sp)
	li t0, 0x1b450f24
	p.insert t2, t0, 25, 7
	sw t2, 4(sp)
	li t0, 0x24bc436d
	li t1, 0x24bc436d
	p.ror t2, t0, t1
	sw t2, 4(sp)
	li t0, 0x29807495
	p.exthz t2, t0
	sw t2, 4(sp)
	li t0, 0x1254fe12
	li t1, 0xd67f1fbf
	p.ror t2, t0, t1
	sw t2, 4(sp)
	li t0, 0x2bef3d53
	li t1, 0x3bb40099
	pv.sll.b t2, t0, t1
	sw t2, 4(sp)
	li t0, 0xd2ad438c
	li t1, 0xdada824e
	pv.shuffle.b t2, t0, t1
	sw t2, 4(sp)
	li t0, 0x7141a588
	pv.abs.b t2, t0
	sw t2, 4(sp)
	li t0, 0x32a95156
	p.bset t2, t0, 7, 19
	sw t2, 4(sp)
	li t0, 0x3e044e9b
	li t1, 0xcc3780e3
	p.subRN t2, t0, t1, 30
	sw t2, 4(sp)
	li t0, 0x43d5c0ad
	li t1, 0x5fcfbf7e
	p.addRN t2, t0, t1, 16
	sw t2, 4(sp)
	li t0, 0x1040000
	p.clb t2, t0
	sw t2, 4(sp)
	li t0, 0x20000
	p.fl1 t2, t0
	sw t2, 4(sp)
	li t0, 0xdd8878cb
	li t1, 0x2877afa3
	xor t2, t0, t1
	sw t2, 4(sp)
	li t0, 0x7fffffff
	li t1, 0x15c1b59c
	and t2, t0, t1
	sw t2, 4(sp)
	li t0, 0xef5bc357
	li t1, 0x3e86ca16
	pv.sll.h t2, t0, t1
	sw t2, 4(sp)
	li t0, 0x81a68c7e
	li t1, 0xb9d1e52d
	pv.sra.h t2, t0, t1
	sw t2, 4(sp)
	li t0, 0x1adf0217
	p.abs t2, t0
	sw t2, 4(sp)
	li t0, 0x3c339f0a
	p.bclr t2, t0, 19, 8
	sw t2, 4(sp)
	li t0, 0x37070ac3
	pv.abs.h t2, t0
	sw t2, 4(sp)
	li t0, 0x7b2649db
	li t1, 0x98266918
	pv.cmpgeu.h t2, t0, t1
	sw t2, 4(sp)
	li t0, 0x3454cc0a
	p.abs t2, t0
	sw t2, 4(sp)
	li t0, 0xb350e6cb
	li t1, 0x76f3e74f
	pv.shuffle2.b t2, t0, t1
	sw t2, 4(sp)
	li t0, 0x6ae2ea05
	li t1, 0x6ae0ea05
	sra t2, t0, t1
	sw t2, 4(sp)
	li t0, 0x80052e38
	li t1, 0xfd3f4e30
	or t2, t0, t1
	sw t2, 4(sp)
	li t0, 0x22901619
	p.abs t2, t0
	sw t2, 4(sp)
	li t0, 0x4c0cd2a3
	li t1, 0xb7f31d5e
	p.subuRN t2, t0, t1, 2
	sw t2, 4(sp)
	li t0, 0x2bf475e7
	li t1, 0x2bb40524
	pv.sll.h t2, t0, t1
	sw t2, 4(sp)
	li t0, 0x5fab0b17
	li t1, 0x699502b3
	pv.sll.h t2, t0, t1
	sw t2, 4(sp)
	li t0, 0x33e8498
	p.clip t2, t0, 20
	sw t2, 4(sp)
	li t0, 0x27668000
	p.ff1 t2, t0
	sw t2, 4(sp)
	li t0, 0xd6524b01
	li t1, 0xaa5dc613
	pv.shuffle2.b t2, t0, t1
	sw t2, 4(sp)
	li t0, 0xfc0
	p.cnt t2, t0
	sw t2, 4(sp)
	li t0, 0xf35c89f5
	li t1, 0x239148bb
	pv.packhi.b t2, t0, t1
	sw t2, 4(sp)
	li t0, 0x30b6e37b
	li t1, 0x30b6f37b
	sll t2, t0, t1
	sw t2, 4(sp)
	li t0, 0xa9f9e121
	p.extract t2, t0, 21, 20
	sw t2, 4(sp)
	li t0, 0x86d7bedb
	p.bclr t2, t0, 1, 0
	sw t2, 4(sp)
	li t0, 0x56b5fb8
	li t1, 0x56b5fb0
	p.ror t2, t0, t1
	sw t2, 4(sp)
	li t0, 0x7a3d2e1d
	li t1, 0x3b7b67c
	p.ror t2, t0, t1
	sw t2, 4(sp)
	li t0, 0x3a8ddd2e
	li t1, 0x81dbdb3f
	pv.packhi.b t2, t0, t1
	sw t2, 4(sp)
	li t0, 0xa5b207fd
	li t1, 0x7bc9dc7f
	p.subRN t2, t0, t1, 6
	sw t2, 4(sp)
	li t0, 0xffff575d
	p.cnt t2, t0
	sw t2, 4(sp)
	li t0, 0x5bcc67a1
	li t1, 0x5c33985e
	p.adduRN t2, t0, t1, 1
	sw t2, 4(sp)
	li t0, 0xcb253d0
	p.clip t2, t0, 10
	sw t2, 4(sp)
	li t0, 0xffffffff
	p.clb t2, t0
	sw t2, 4(sp)
	li t0, 0xffefffff
	p.cnt t2, t0
	sw t2, 4(sp)
	li t0, 0xdc5ff890
	li t1, 0x86aa5ca
	pv.pack.h t2, t0, t1
	sw t2, 4(sp)
	li t0, 0xb7effcdc
	li t1, 0xa21e4265
	pv.and.b t2, t0, t1
	sw t2, 4(sp)
	li t0, 0xf39143d4
	li t1, 0xf1ca43d4
	pv.cmpgt.h t2, t0, t1
	sw t2, 4(sp)
	li t0, 0x81c8c088
	li t1, 0xd1e14903
	pv.shuffle2.b t2, t0, t1
	sw t2, 4(sp)
	li t0, 0xc0ddefa5
	li t1, 0x8df750f8
	p.ror t2, t0, t1
	sw t2, 4(sp)
	li t0, 0x19f6fc5b
	p.extract t2, t0, 1, 28
	sw t2, 4(sp)
	li t0, 0x4db95ac
	li t1, 0x62ced66
	xor t2, t0, t1
	sw t2, 4(sp)
	li t0, 0x128e27f4
	li t1, 0xe41223cd
	pv.shuffle2.h t2, t0, t1
	sw t2, 4(sp)
	li t0, 0x161d0cd
	p.clip t2, t0, 5
	sw t2, 4(sp)
	li t0, 0xe932b042
	li t1, 0xcc461ffd
	p.addRN t2, t0, t1, 12
	sw t2, 4(sp)
	li t0, 0x80010000
	p.ff1 t2, t0
	sw t2, 4(sp)
	li t0, 0xc008e17f
	li t1, 0xbff7c880
	p.addRN t2, t0, t1, 7
	sw t2, 4(sp)
	li t0, 0xe13798a
	li t1, 0x79bfe260
	pv.maxu.b t2, t0, t1
	sw t2, 4(sp)
	li t0, 0x876bfc0c
	li t1, 0x3c71550c
	pv.cmpgeu.b t2, t0, t1
	sw t2, 4(sp)
	li t0, 0x254e826f
	p.insert t2, t0, 24, 0
	sw t2, 4(sp)
	li t0, 0xf0284394
	li t1, 0xe0c74394
	pv.cmpge.h t2, t0, t1
	sw t2, 4(sp)
	li t0, 0x99c1b6c3
	li t1, 0x99c1bac3
	bge t0, t1, branch0
branch0:
	sw t2, 4(sp)
	li t0, 0x7bf35e7a
	li t1, 0x735f19c1
	pv.shuffle2.b t2, t0, t1
	sw t2, 4(sp)
	li t0, 0xd3c28bf3
	li t1, 0xd3c24bf3
	pv.cmpeq.h t2, t0, t1
	sw t2, 4(sp)
	li t0, 0xfffff7f4
	p.cnt t2, t0
	sw t2, 4(sp)
	li t0, 0xab202c4e
	p.extract t2, t0, 8, 0
	sw t2, 4(sp)
	li t0, 0x3b9a713
	p.abs t2, t0
	sw t2, 4(sp)
	li t0, 0x1de41589
	li t1, 0xc0bb6fb
	p.subRN t2, t0, t1, 29
	sw t2, 4(sp)
	li t0, 0x4d1701c2
	li t1, 0x5f176453
	p.ror t2, t0, t1
	sw t2, 4(sp)
	li t0, 0x91d141fa
	li t1, 0x72e298ac
	pv.min.b t2, t0, t1
	sw t2, 4(sp)
	li t0, 0x1dcf7bc3
	li t1, 0x30eee526
	pv.sll.b t2, t0, t1
	sw t2, 4(sp)
	li t0, 0x2788889f
	li t1, 0x2a88888b
	bgeu t0, t1, branch1
branch1:
	sw t2, 4(sp)
	li t0, 0x80cf8456
	p.extract t2, t0, 19, 17
	sw t2, 4(sp)
	li t0, 0x800000
	p.fl1 t2, t0
	sw t2, 4(sp)
	li t0, 0xfc64feda
	li t1, 0xfc64feda
	bne t0, t1, branch2
branch2:
	sw t2, 4(sp)
	li t0, 0x8956449a
	li t1, 0xfe63ea99
	pv.min.b t2, t0, t1
	sw t2, 4(sp)
	li t0, 0x44af227b
	li t1, 0x7f31013f
	pv.pack.h t2, t0, t1
	sw t2, 4(sp)
	li t0, 0x2255913d
	li t1, 0xf795fa9d
	pv.pack.h t2, t0, t1
	sw t2, 4(sp)
	li t0, 0x2000000
	p.fl1 t2, t0
	sw t2, 4(sp)
	li t0, 0x1028102
	p.clb t2, t0
	sw t2, 4(sp)
	li t0, 0x59ca8033
	p.ff1 t2, t0
	sw t2, 4(sp)
	li t0, 0xffdfffff
	p.cnt t2, t0
	sw t2, 4(sp)
	li t0, 0xc640cb72
	li t1, 0x746aa49e
	p.ror t2, t0, t1
	sw t2, 4(sp)
	li t0, 0x4e58c42c
	li t1, 0x4eca0d17
	pv.maxu.b t2, t0, t1
	sw t2, 4(sp)
	li t0, 0x20745db8
	li t1, 0x20795db8
	pv.cmplt.b t2, t0, t1
	sw t2, 4(sp)
	li t0, 0x9ac76e6f
	li t1, 0x52d4feb5
	pv.pack.h t2, t0, t1
	sw t2, 4(sp)
	li t0, 0xcfd3155b
	li t1, 0xcfd315ad
	pv.cmpgeu.h t2, t0, t1
	sw t2, 4(sp)
	li t0, 0x80000000
	p.ff1 t2, t0
	sw t2, 4(sp)
	li t0, 0x8be7cbb1
	li t1, 0xebab01ce
	sll t2, t0, t1
	sw t2, 4(sp)
	li t0, 0x7a219d3c
	p.extract t2, t0, 5, 9
	sw t2, 4(sp)
	li t0, 0xf379014f
	p.extract t2, t0, 29, 16
	sw t2, 4(sp)
	li t0, 0x65e1b0bb
	li t1, 0x73e1acbb
	pv.cmpltu.b t2, t0, t1
	sw t2, 4(sp)
	li t0, 0xec362046
	li t1, 0xec092006
	pv.cmpeq.h t2, t0, t1
	sw t2, 4(sp)
	li t0, 0x2e000000
	p.ff1 t2, t0
	sw t2, 4(sp)
	li t0, 0xdc4fc098
	li t1, 0x96a3e943
	sll t2, t0, t1
	sw t2, 4(sp)
	li t0, 0x57389fee
	p.clip t2, t0, 13
	sw t2, 4(sp)
	li t0, 0x1b9fe0c3
	li t1, 0x1a98e0c3
	pv.cmpleu.b t2, t0, t1
	sw t2, 4(sp)
	li t0, 0xfffffffe
	p.cnt t2, t0
	sw t2, 4(sp)
	li t0, 0x6ade8f4a
	li t1, 0x6cde8e4c
	pv.cmpleu.b t2, t0, t1
	sw t2, 4(sp)
	li t0, 0xed76c80a
	p.extract t2, t0, 16, 11
	sw t2, 4(sp)
	li t0, 0xf6bb6405
	p.extract t2, t0, 12, 21
	sw t2, 4(sp)
	li t0, 0x99125178
	li t1, 0x8f40675d
	p.ror t2, t0, t1
	sw t2, 4(sp)
	li t0, 0x5964e58f
	p.clip t2, t0, 2
	sw t2, 4(sp)
	li t0, 0xf1b2dff1
	li t1, 0xc8fcbfef
	pv.max.b t2, t0, t1
	sw t2, 4(sp)
	li t0, 0x56da1e08
	p.ff1 t2, t0
	sw t2, 4(sp)
	li t0, 0xfaf06f7a
	li t1, 0xb3e2b679
	p.ror t2, t0, t1
	sw t2, 4(sp)
	li t0, 0xa1be37bd
	li t1, 0xa1bd5b38
	p.slet t2, t0, t1
	sw t2, 4(sp)
	li t0, 0xfcba5a78
	p.extract t2, t0, 20, 23
	sw t2, 4(sp)
	li t0, 0x165d2d3c
	p.extract t2, t0, 29, 27
	sw t2, 4(sp)
	li t0, 0x46f3165c
	p.clip t2, t0, 4
	sw t2, 4(sp)
	li t0, 0x3a6feea8
	p.clip t2, t0, 21
	sw t2, 4(sp)
	li t0, 0x2000
	p.clipu t2, t0, 26
	sw t2, 4(sp)
	li t0, 0x6da149cc
	pv.abs.b t2, t0
	sw t2, 4(sp)
	li t0, 0xda2d0f46
	li t1, 0xdaffccd7
	pv.packlo.b t2, t0, t1
	sw t2, 4(sp)
	li t0, 0xc81621c5
	p.extract t2, t0, 22, 31
	sw t2, 4(sp)
	li t0, 0x6a69fc37
	p.extract t2, t0, 23, 17
	sw t2, 4(sp)
	li t0, 0x1d924581
	li t1, 0x1d9545c1
	pv.cmpltu.h t2, t0, t1
	sw t2, 4(sp)
	li t0, 0x77
	p.fl1 t2, t0
	sw t2, 4(sp)
	li t0, 0x205b0f73
	li t1, 0x612e0f98
	pv.cmpne.b t2, t0, t1
	sw t2, 4(sp)
	li t0, 0xc1457793
	p.insert t2, t0, 6, 6
	sw t2, 4(sp)
	li t0, 0x2828baf7
	li t1, 0x61aa3380
	pv.sll.b t2, t0, t1
	sw t2, 4(sp)
	li t0, 0x585ddab4
	p.clip t2, t0, 4
	sw t2, 4(sp)
	li t0, 0xe62ecdcc
	li t1, 0x613f4cc6
	pv.min.b t2, t0, t1
	sw t2, 4(sp)
	li t0, 0x4000
	p.ff1 t2, t0
	sw t2, 4(sp)
	li t0, 0x10f1a4ce
	p.fl1 t2, t0
	sw t2, 4(sp)
	li t0, 0x5f9c89ff
	li t1, 0x669a88fe
	pv.cmpleu.b t2, t0, t1
	sw t2, 4(sp)
	li t0, 0x57b105d7
	li t1, 0x6b5c0bf0
	pv.sll.h t2, t0, t1
	sw t2, 4(sp)
	li t0, 0x488c9aa7
	li t1, 0x6e397bf
	pv.cmpne.b t2, t0, t1
	sw t2, 4(sp)
	li t0, 0xebe50485
	li t1, 0x9c66fb48
	pv.sll.b t2, t0, t1
	sw t2, 4(sp)
	li t0, 0x9a8726e3
	li t1, 0x51883bd0
	pv.srl.h t2, t0, t1
	sw t2, 4(sp)
	li t0, 0x9ac9a19b
	p.clip t2, t0, 27
	sw t2, 4(sp)
	li t0, 0xfa349961
	li t1, 0xf173087d
	pv.max.b t2, t0, t1
	sw t2, 4(sp)
	li t0, 0x591a0401
	pv.abs.b t2, t0
	sw t2, 4(sp)
	li t0, 0xdd77e5e0
	p.ff1 t2, t0
	sw t2, 4(sp)
	li t0, 0x6d7c5fdb
	p.extract t2, t0, 25, 13
	sw t2, 4(sp)
	li t0, 0x8687ab7f
	p.extract t2, t0, 30, 9
	sw t2, 4(sp)
	li t0, 0x8343d5bf
	p.extract t2, t0, 31, 24
	sw t2, 4(sp)
	li t0, 0x1c261b93
	li t1, 0x5dc99347
	pv.minu.h t2, t0, t1
	sw t2, 4(sp)
	li t0, 0x10019084
	p.clip t2, t0, 17
	sw t2, 4(sp)
	li t0, 0x80
	p.clipu t2, t0, 11
	sw t2, 4(sp)
	li t0, 0x777de41f
	li t1, 0xef40d22f
	pv.max.b t2, t0, t1
	sw t2, 4(sp)
	li t0, 0xe707b6c6
	li t1, 0xe7d38698
	p.slet t2, t0, t1
	sw t2, 4(sp)
	li t0, 0x9a399a7d
	p.extract t2, t0, 30, 30
	sw t2, 4(sp)
	li t0, 0xa0ca9ae9
	p.extract t2, t0, 11, 20
	sw t2, 4(sp)
	li t0, 0xe832a6ba
	li t1, 0x4d6da891
	pv.shuffle2.b t2, t0, t1
	sw t2, 4(sp)
	li t0, 0xffffdfd2
	p.cnt t2, t0
	sw t2, 4(sp)
	li t0, 0xba9bd070
	p.clip t2, t0, 5
	sw t2, 4(sp)
	li t0, 0x922e9e50
	p.clip t2, t0, 26
	sw t2, 4(sp)
	li t0, 0xdd800000
	p.ff1 t2, t0
	sw t2, 4(sp)
	li t0, 0x800
	p.ff1 t2, t0
	sw t2, 4(sp)
	li t0, 0x2cc63e00
	p.ff1 t2, t0
	sw t2, 4(sp)
	li t0, 0x32cf9d1b
	li t1, 0x32cf54cd
	pv.cmpgtu.h t2, t0, t1
	sw t2, 4(sp)
	li t0, 0x3f35e06a
	p.extract t2, t0, 17, 28
	sw t2, 4(sp)
	li t0, 0x5008df53
	li t1, 0xe663df70
	pv.cmpne.b t2, t0, t1
	sw t2, 4(sp)
	li t0, 0x400000
	p.fl1 t2, t0
	sw t2, 4(sp)
	li t0, 0xbae904ad
	li t1, 0x5f4d287f
	sll t2, t0, t1
	sw t2, 4(sp)
	li t0, 0x3645d0c2
	p.clip t2, t0, 26
	sw t2, 4(sp)
	li t0, 0x1b9ea3d2
	p.clip t2, t0, 28
	sw t2, 4(sp)
	li t0, 0xc596650b
	li t1, 0xc518c0d6
	pv.cmple.b t2, t0, t1
	sw t2, 4(sp)
	li t0, 0xc14b3285
	li t1, 0x9e0c606b
	pv.shuffle2.b t2, t0, t1
	sw t2, 4(sp)
	li t0, 0xee63a375
	li t1, 0xecca99af
	pv.cmpge.h t2, t0, t1
	sw t2, 4(sp)
	li t0, 0xbc98e8dd
	li t1, 0xbc32a66b
	pv.cmpleu.b t2, t0, t1
	sw t2, 4(sp)
	li t0, 0x430ecab8
	li t1, 0x410dee41
	p.addRN t2, t0, t1, 19
	sw t2, 4(sp)
	li t0, 0xbbec3910
	p.ff1 t2, t0
	sw t2, 4(sp)
	li t0, 0x9c5c90ff
	p.clip t2, t0, 11
	sw t2, 4(sp)
	li t0, 0x77fa8b00
	p.clip t2, t0, 21
	sw t2, 4(sp)
	li t0, 0xedc65a39
	li t1, 0x88b37e3a
	pv.max.b t2, t0, t1
	sw t2, 4(sp)
	li t0, 0x1000
	p.ff1 t2, t0
	sw t2, 4(sp)
	li t0, 0x80000
	p.fl1 t2, t0
	sw t2, 4(sp)

	li t0, 0x33333333
	li t1, 0x55555555
	add t2, t0, t1
	sw t2, 4(sp)
	ret
