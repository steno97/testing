	.section .text
	.global _sbst_mul
	.type _sbst_mul, @function

_sbst_mul:
	xor x30, x30, x30
	xor x31, x31, x31
	li x3, 0x2bcf00e9
	li x4, 0xb011c6bc
	pv.dotup.b x30, x3, x4
	sw x30, 4(sp)
	xor	x31, x31, x30
	li x6, 0xc6c0c6c0
	li x7, 0x3e303e30
	pv.dotup.b x30, x6, x7
	sw x30, 4(sp)
	xor	x31, x31, x30
	li x9, 0xf943904e
	li x10, 0xd1f4d389
	p.mac x30, x9, x10
	sw x30, 4(sp)
	xor	x31, x31, x30
	li x12, 0xdac708c7
	li x13, 0x9e2d842d
	pv.dotup.b x30, x12, x13
	sw x30, 4(sp)
	xor	x31, x31, x30
	li x15, 0x3230323
	li x16, 0x30083008
	pv.dotup.b x30, x15, x16
	sw x30, 4(sp)
	xor	x31, x31, x30
	li x18, 0xc1a7be55
	li x19, 0x902cfc74
	mulhsu x30, x18, x19
	sw x30, 4(sp)
	xor	x31, x31, x30
	li x21, 0x111711dc
	li x22, 0x1138113f
	pv.dotup.b x30, x21, x22
	sw x30, 4(sp)
	xor	x31, x31, x30
	li x24, 0x1eff476e
	li x25, 0x77cc1b00
	mulhu x30, x24, x25
	sw x30, 4(sp)
	xor	x31, x31, x30
	li x27, 0x2ab02ab
	li x28, 0x6410641
	pv.dotup.b x30, x27, x28
	sw x30, 4(sp)
	xor	x31, x31, x30
	li x3, 0x8000800
	li x4, 0x55045504
	pv.dotup.b x30, x3, x4
	sw x30, 4(sp)
	xor	x31, x31, x30
	li x6, 0xc100c100
	li x7, 0x55205520
	pv.dotup.b x30, x6, x7
	sw x30, 4(sp)
	xor	x31, x31, x30
	li x9, 0xdf80df82
	li x10, 0x1af41af4
	pv.dotup.b x30, x9, x10
	sw x30, 4(sp)
	xor	x31, x31, x30
	li x12, 0xa31ddd1d
	li x13, 0x70e5cae5
	pv.dotup.b x30, x12, x13
	sw x30, 4(sp)
	xor	x31, x31, x30
	li x15, 0x7407c9f6
	li x16, 0x1201fff8
	pv.dotup.h x30, x15, x16
	sw x30, 4(sp)
	xor	x31, x31, x30
	li x18, 0x16ce2a46
	li x19, 0x8ee04be0
	pv.dotup.h x30, x18, x19
	sw x30, 4(sp)
	xor	x31, x31, x30
	li x21, 0x8b564900
	li x22, 0x5a094216
	pv.dotup.h x30, x21, x22
	sw x30, 4(sp)
	xor	x31, x31, x30
	li x24, 0x450025f
	li x25, 0x8001cfef
	p.msu x30, x24, x25
	sw x30, 4(sp)
	xor	x31, x31, x30
	li x27, 0x104c138
	li x28, 0xa2cf3d8
	p.msu x30, x27, x28
	sw x30, 4(sp)
	xor	x31, x31, x30
	li x3, 0x902b55fc
	li x4, 0xf7780707
	pv.dotup.h x30, x3, x4
	sw x30, 4(sp)
	xor	x31, x31, x30
	li x6, 0x3440344
	li x7, 0x68146814
	pv.dotup.h x30, x6, x7
	sw x30, 4(sp)
	xor	x31, x31, x30
	li x9, 0xa101801a
	li x10, 0xe22fd20a
	p.mac x30, x9, x10
	sw x30, 4(sp)
	xor	x31, x31, x30
	li x12, 0x78efb80e
	li x13, 0x72e20955
	pv.dotup.h x30, x12, x13
	sw x30, 4(sp)
	xor	x31, x31, x30
	li x15, 0x80302b15
	li x16, 0x444598fb
	p.msu x30, x15, x16
	sw x30, 4(sp)
	xor	x31, x31, x30
	li x18, 0x5399e399
	li x19, 0xa2eca2ec
	pv.dotup.h x30, x18, x19
	sw x30, 4(sp)
	xor	x31, x31, x30
	li x21, 0x1f80a05f
	li x22, 0xd03f2080
	p.mac x30, x21, x22
	sw x30, 4(sp)
	xor	x31, x31, x30
	li x24, 0xc04ef30
	li x25, 0x84bc007e
	p.msu x30, x24, x25
	sw x30, 4(sp)
	xor	x31, x31, x30
	li x27, 0x82000a14
	li x28, 0xc5c01105
	p.mac x30, x27, x28
	sw x30, 4(sp)
	xor	x31, x31, x30
	li x3, 0xdfa9a0f1
	li x4, 0xfbda1069
	pv.dotup.b x30, x3, x4
	sw x30, 4(sp)
	xor	x31, x31, x30
	li x6, 0x447f9af2
	li x7, 0xcdd92dc8
	pv.dotup.b x30, x6, x7
	sw x30, 4(sp)
	xor	x31, x31, x30
	li x9, 0xc988f00
	li x10, 0x4440036e
	p.mac x30, x9, x10
	sw x30, 4(sp)
	xor	x31, x31, x30
	li x12, 0x9e20e2c8
	li x13, 0x16390f1a
	p.mac x30, x12, x13
	sw x30, 4(sp)
	xor	x31, x31, x30
	li x15, 0xaead2b1e
	li x16, 0xc0d09b6a
	pv.dotup.b x30, x15, x16
	sw x30, 4(sp)
	xor	x31, x31, x30
	li x18, 0x5756958f
	li x19, 0x60684db5
	pv.dotup.b x30, x18, x19
	sw x30, 4(sp)
	xor	x31, x31, x30
	li x21, 0x88a8f97d
	li x22, 0xaa979ebb
	pv.dotup.b x30, x21, x22
	sw x30, 4(sp)
	xor	x31, x31, x30
	li x24, 0x44547cbe
	li x25, 0xd54bcf5d
	pv.dotup.b x30, x24, x25
	sw x30, 4(sp)
	xor	x31, x31, x30
	li x27, 0xaa82c722
	li x28, 0xc0327915
	pv.dotup.b x30, x27, x28
	sw x30, 4(sp)
	xor	x31, x31, x30
	li x3, 0x5de99aec
	li x4, 0xca8ea231
	pv.dotup.b x30, x3, x4
	sw x30, 4(sp)
	xor	x31, x31, x30
	li x6, 0x265c340b
	li x7, 0xcfd0cfa3
	pv.dotup.b x30, x6, x7
	sw x30, 4(sp)
	xor	x31, x31, x30
	li x9, 0x132e1a05
	li x10, 0xe7e867d1
	pv.dotup.b x30, x9, x10
	sw x30, 4(sp)
	xor	x31, x31, x30
	li x12, 0x813ff47f
	li x13, 0x5963ad53
	pv.dotup.b x30, x12, x13
	sw x30, 4(sp)
	xor	x31, x31, x30
	li x15, 0x409ffa3f
	li x16, 0xacb1d6a9
	pv.dotup.b x30, x15, x16
	sw x30, 4(sp)
	xor	x31, x31, x30
	li x18, 0xa8e70462
	li x19, 0x7ccf75ef
	pv.dotup.b x30, x18, x19
	sw x30, 4(sp)
	xor	x31, x31, x30
	li x21, 0x54738231
	li x22, 0x3e67baf7
	pv.dotup.b x30, x21, x22
	sw x30, 4(sp)
	xor	x31, x31, x30
	li x24, 0x2a39c118
	li x25, 0x9f33dd7b
	pv.dotup.b x30, x24, x25
	sw x30, 4(sp)
	xor	x31, x31, x30
	li x27, 0x134ad71c
	li x28, 0xc4038ba4
	p.mac x30, x27, x28
	sw x30, 4(sp)
	xor	x31, x31, x30
	li x3, 0x8672f585
	li x4, 0x5810a6b8
	pv.dotup.h x30, x3, x4
	sw x30, 4(sp)
	xor	x31, x31, x30
	li x6, 0xc3397ac2
	li x7, 0xac08535c
	pv.dotup.h x30, x6, x7
	sw x30, 4(sp)
	xor	x31, x31, x30
	li x9, 0x6934441c
	li x10, 0xfc93b715
	pv.dotup.h x30, x9, x10
	sw x30, 4(sp)
	xor	x31, x31, x30
	li x12, 0x2c16034
	li x13, 0x498a161a
	p.msu x30, x12, x13
	sw x30, 4(sp)
	xor	x31, x31, x30
	li x15, 0x27856b8
	li x16, 0x5ed57f14
	mulh x30, x15, x16
	sw x30, 4(sp)
	xor	x31, x31, x30
	li x18, 0x12e5e87a
	li x19, 0x95b3737e
	pv.dotup.h x30, x18, x19
	sw x30, 4(sp)
	xor	x31, x31, x30
	li x21, 0x5406392e
	li x22, 0x91e67027
	p.msu x30, x21, x22
	sw x30, 4(sp)
	xor	x31, x31, x30
	li x24, 0x80ed06a0
	li x25, 0x70271382
	pv.dotup.h x30, x24, x25
	sw x30, 4(sp)
	xor	x31, x31, x30
	li x27, 0xc0768350
	li x28, 0x381389c1
	pv.dotup.h x30, x27, x28
	sw x30, 4(sp)
	xor	x31, x31, x30
	li x3, 0xe03b41a8
	li x4, 0x1c09c4e0
	pv.dotup.h x30, x3, x4
	sw x30, 4(sp)
	xor	x31, x31, x30
	li x6, 0x701da0d4
	li x7, 0xe04e270
	pv.dotup.h x30, x6, x7
	sw x30, 4(sp)
	xor	x31, x31, x30
	li x9, 0x305a2857
	li x10, 0x9470f9b8
	p.msu x30, x9, x10
	sw x30, 4(sp)
	xor	x31, x31, x30
	li x12, 0x77f1b9e
	li x13, 0x6c6410ca
	p.msu x30, x12, x13
	sw x30, 4(sp)
	xor	x31, x31, x30
	li x15, 0xe0018
	li x16, 0xae1c5ff8
	p.mac x30, x15, x16
	sw x30, 4(sp)
	xor	x31, x31, x30
	li x18, 0x420f87
	li x19, 0x5612e190
	p.mac x30, x18, x19
	sw x30, 4(sp)
	xor	x31, x31, x30
	li x21, 0x89dba9c
	li x22, 0xfb9d43a
	pv.dotup.b x30, x21, x22
	sw x30, 4(sp)
	xor	x31, x31, x30
	li x24, 0x8942e3
	li x25, 0x1ddc1d02
	p.mac x30, x24, x25
	sw x30, 4(sp)
	xor	x31, x31, x30
	li x27, 0x8a8f97da
	li x28, 0xa979ebb5
	pv.dotup.b x30, x27, x28
	sw x30, 4(sp)
	xor	x31, x31, x30
	li x3, 0x4547cbed
	li x4, 0x54bcf5da
	pv.dotup.b x30, x3, x4
	sw x30, 4(sp)
	xor	x31, x31, x30
	li x6, 0x22a3e5f6
	li x7, 0xaa5e7aed
	pv.dotup.b x30, x6, x7
	sw x30, 4(sp)
	xor	x31, x31, x30
	li x9, 0x1151f2fb
	li x10, 0x552f3d76
	pv.dotup.h x30, x9, x10
	sw x30, 4(sp)
	xor	x31, x31, x30
	li x12, 0xb829cf32
	li x13, 0xacc2f09c
	p.mac x30, x12, x13
	sw x30, 4(sp)
	xor	x31, x31, x30
	li x15, 0xd75db974
	li x16, 0x5be622a6
	pv.dotup.b x30, x15, x16
	sw x30, 4(sp)
	xor	x31, x31, x30
	li x18, 0x4515ae52
	li x19, 0x9a3f541f
	pv.dotup.b x30, x18, x19
	sw x30, 4(sp)
	xor	x31, x31, x30
	li x21, 0xc31a5c1
	li x22, 0xfad3ef43
	pv.dotup.b x30, x21, x22
	sw x30, 4(sp)
	xor	x31, x31, x30
	li x24, 0x28a3a008
	li x25, 0x4aa5b2ed
	pv.dotup.b x30, x24, x25
	sw x30, 4(sp)
	xor	x31, x31, x30
	li x27, 0x1451d004
	li x28, 0x2552d976
	pv.dotup.b x30, x27, x28
	sw x30, 4(sp)
	xor	x31, x31, x30
	li x3, 0x24939aea
	li x4, 0xa56529f7
	pv.dotup.b x30, x3, x4
	sw x30, 4(sp)
	xor	x31, x31, x30
	li x6, 0x9249cd75
	li x7, 0x52b294fb
	pv.dotup.b x30, x6, x7
	sw x30, 4(sp)
	xor	x31, x31, x30
	li x9, 0xe79f9452
	li x10, 0x1e950f31
	pv.dotup.b x30, x9, x10
	sw x30, 4(sp)
	xor	x31, x31, x30
	li x12, 0xf3cfca29
	li x13, 0xf4a8798
	pv.dotup.h x30, x12, x13
	sw x30, 4(sp)
	xor	x31, x31, x30
	li x15, 0xf9e7e514
	li x16, 0x87a543cc
	pv.dotup.h x30, x15, x16
	sw x30, 4(sp)
	xor	x31, x31, x30
	li x18, 0xf1533bf3
	li x19, 0x843c68ba
	mulh x30, x18, x19
	sw x30, 4(sp)
	xor	x31, x31, x30
	li x21, 0xf8a99df9
	li x22, 0xc21e345d
	mulh x30, x21, x22
	sw x30, 4(sp)
	xor	x31, x31, x30
	li x24, 0x52488062
	li x25, 0xf41ee4aa
	pv.dotup.h x30, x24, x25
	sw x30, 4(sp)
	xor	x31, x31, x30
	li x27, 0x8c445548
	li x28, 0xc7395b59
	p.mac x30, x27, x28
	sw x30, 4(sp)
	xor	x31, x31, x30
	li x3, 0xc3cf996c
	li x4, 0xe6e19b8c
	pv.dotup.h x30, x3, x4
	sw x30, 4(sp)
	xor	x31, x31, x30
	li x6, 0x4f5cbe5e
	li x7, 0xc4bc888a
	pv.dotup.h x30, x6, x7
	sw x30, 4(sp)
	xor	x31, x31, x30
	li x9, 0x6cafce9
	li x10, 0x2018e75a
	p.mac x30, x9, x10
	sw x30, 4(sp)
	xor	x31, x31, x30
	li x12, 0x3d6c5d7f
	li x13, 0x6e3676e
	pv.dotup.h x30, x12, x13
	sw x30, 4(sp)
	xor	x31, x31, x30
	li x15, 0x7f164c22
	li x16, 0x5fed329d
	mulh x30, x15, x16
	sw x30, 4(sp)
	xor	x31, x31, x30
	li x18, 0x300d5c57
	li x19, 0x34bdf6fb
	pv.dotup.h x30, x18, x19
	sw x30, 4(sp)
	xor	x31, x31, x30
	li x21, 0x1806ae2b
	li x22, 0x9a5efb7d
	pv.dotup.h x30, x21, x22
	sw x30, 4(sp)
	xor	x31, x31, x30
	li x24, 0xc035715
	li x25, 0xcd2f7dbe
	pv.dotup.h x30, x24, x25
	sw x30, 4(sp)
	xor	x31, x31, x30
	li x27, 0x801201da
	li x28, 0xe506fcef
	p.msu x30, x27, x28
	sw x30, 4(sp)
	xor	x31, x31, x30
	li x3, 0xc0e00299
	li x4, 0x70f1c421
	p.mac x30, x3, x4
	sw x30, 4(sp)
	xor	x31, x31, x30
	li x6, 0x4f3b180a
	li x7, 0xe69aafb
	pv.dotup.b x30, x6, x7
	sw x30, 4(sp)
	xor	x31, x31, x30
	li x9, 0x8926feed
	li x10, 0xb0f89031
	pv.dotup.b x30, x9, x10
	sw x30, 4(sp)
	xor	x31, x31, x30
	li x12, 0x82c02e14
	li x13, 0x679cff81
	p.msu x30, x12, x13
	sw x30, 4(sp)
	xor	x31, x31, x30
	li x15, 0x751406cf
	li x16, 0x37d806aa
	pv.dotup.b x30, x15, x16
	sw x30, 4(sp)
	xor	x31, x31, x30
	li x18, 0x1431718f
	li x19, 0x2c204619
	pv.dotup.b x30, x18, x19
	sw x30, 4(sp)
	xor	x31, x31, x30
	li x21, 0x8a18b8c7
	li x22, 0x9610230c
	pv.dotup.b x30, x21, x22
	sw x30, 4(sp)
	xor	x31, x31, x30
	li x24, 0xebb72e8b
	li x25, 0x7cc454ca
	pv.dotup.h x30, x24, x25
	sw x30, 4(sp)
	xor	x31, x31, x30
	li x27, 0x75db9745
	li x28, 0xbe622a65
	pv.dotup.h x30, x27, x28
	sw x30, 4(sp)
	xor	x31, x31, x30
	li x3, 0xbaedcba2
	li x4, 0xdf311532
	pv.dotup.b x30, x3, x4
	sw x30, 4(sp)
	xor	x31, x31, x30
	li x6, 0x5d76e5d1
	li x7, 0x6f988a99
	pv.dotup.b x30, x6, x7
	sw x30, 4(sp)
	xor	x31, x31, x30
	li x9, 0xfe2c9844
	li x10, 0xbfda653a
	pv.dotup.b x30, x9, x10
	sw x30, 4(sp)
	xor	x31, x31, x30
	li x12, 0x7f164c22
	li x13, 0x5fed329d
	pv.dotup.b x30, x12, x13
	sw x30, 4(sp)
	xor	x31, x31, x30
	li x15, 0xc1a7be55
	li x16, 0x902cfc74
	pv.dotup.b x30, x15, x16
	sw x30, 4(sp)
	xor	x31, x31, x30
	li x18, 0x1eff476e
	li x19, 0x77cc1b00
	pv.dotup.b x30, x18, x19
	sw x30, 4(sp)
	xor	x31, x31, x30
	li x21, 0xf1533bf3
	li x22, 0x843c68ba
	pv.dotup.b x30, x21, x22
	sw x30, 4(sp)
	xor	x31, x31, x30
	li x24, 0xbaedcba2
	li x25, 0xdf311532
	mulh x30, x24, x25
	sw x30, 4(sp)
	xor	x31, x31, x30
	li x27, 0xf8a99df9
	li x28, 0xc21e345d
	pv.dotup.b x30, x27, x28
	sw x30, 4(sp)
	xor	x31, x31, x30
	li x3, 0x27856b8
	li x4, 0x5ed57f14
	pv.dotup.b x30, x3, x4
	sw x30, 4(sp)
	xor	x31, x31, x30
	li x6, 0x813c2b5c
	li x7, 0x2f6abf8a
	pv.dotup.b x30, x6, x7
	sw x30, 4(sp)
	xor	x31, x31, x30
	li x9, 0xfe2c9844
	li x10, 0xbfda653a
	mulh x30, x9, x10
	sw x30, 4(sp)
	xor	x31, x31, x30
	li x12, 0xbeb28dea
	li x13, 0xa86f3aff
	pv.dotup.b x30, x12, x13
	sw x30, 4(sp)
	xor	x31, x31, x30
	li x15, 0xdf5946f5
	li x16, 0x54379d7f
	pv.dotup.h x30, x15, x16
	sw x30, 4(sp)
	xor	x31, x31, x30
	li x18, 0xefaca37a
	li x19, 0xaa1bcebf
	pv.dotup.h x30, x18, x19
	sw x30, 4(sp)
	xor	x31, x31, x30
	li x21, 0x9fac9f9
	li x22, 0xead78265
	pv.dotup.h x30, x21, x22
	sw x30, 4(sp)
	xor	x31, x31, x30
	li x24, 0xf2c8d9ca
	li x25, 0x78c28d6c
	p.mac x30, x24, x25
	sw x30, 4(sp)
	xor	x31, x31, x30
	li x27, 0x4098e76a
	li x28, 0xad760c38
	pv.dotup.h x30, x27, x28
	sw x30, 4(sp)
	xor	x31, x31, x30
	li x3, 0xa506e4e9
	li x4, 0x5b4c7d1f
	p.msu x30, x3, x4
	sw x30, 4(sp)
	xor	x31, x31, x30
	li x6, 0xacd04cbb
	li x7, 0x108727c5
	p.msu x30, x6, x7
	sw x30, 4(sp)
	xor	x31, x31, x30
	li x9, 0x281c05de
	li x10, 0xb7093387
	p.msu x30, x9, x10
	sw x30, 4(sp)
	xor	x31, x31, x30
	li x12, 0x14200143
	li x13, 0xd90077fa
	p.msu x30, x12, x13
	sw x30, 4(sp)
	xor	x31, x31, x30
	li x15, 0xa4a7222
	li x16, 0xed666588
	pv.dotup.b x30, x15, x16
	sw x30, 4(sp)
	xor	x31, x31, x30
	li x18, 0x85253911
	li x19, 0x76b332c4
	pv.dotup.h x30, x18, x19
	sw x30, 4(sp)
	xor	x31, x31, x30
	li x21, 0x42929c88
	li x22, 0xbb599962
	pv.dotup.h x30, x21, x22
	sw x30, 4(sp)
	xor	x31, x31, x30
	li x24, 0xdf41bf03
	li x25, 0xe207810a
	p.msu x30, x24, x25
	sw x30, 4(sp)
	xor	x31, x31, x30
	li x27, 0x9118268b
	li x28, 0xcfb1ddff
	p.msu x30, x27, x28
	sw x30, 4(sp)
	xor	x31, x31, x30
	li x3, 0x5d76e5d1
	li x4, 0x6f988a99
	mulh x30, x3, x4
	sw x30, 4(sp)
	xor	x31, x31, x30
	li x6, 0xac8ea807
	li x7, 0xb2859a6c
	pv.dotup.b x30, x6, x7
	sw x30, 4(sp)
	xor	a0, x31, x30

	ret
