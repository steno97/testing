	.section .text
	.global _sbst_alu
	.type _sbst_alu, @function

_sbst_alu:
	li t0, 0x695e66f3
	li t1, 0x9b2eba82
	p.subRN t2, t0, t1, 6
	sw t2, 4(sp)
	li t0, 0x52d9bb3f
	li t1, 0x7ccded1
	sub t2, t0, t1
	sw t2, 4(sp)
	li t0, 0x459bfe87
	li t1, 0x9617fdfb
	p.addRN t2, t0, t1, 11
	sw t2, 4(sp)
	li t0, 0xbce9ffd5
	li t1, 0x1c3e0004
	p.subuRN t2, t0, t1, 7
	sw t2, 4(sp)
	li t0, 0xb221b6ec
	li t1, 0x4f2181b0
	p.subuRN t2, t0, t1, 1
	sw t2, 4(sp)
	li t0, 0x24b0a80a
	li t1, 0x8068b6f0
	p.adduRN t2, t0, t1, 3
	sw t2, 4(sp)
	li t0, 0xf909802b
	li t1, 0x7936783f
	p.addRN t2, t0, t1, 12
	sw t2, 4(sp)
	li t0, 0xb471b2f5
	li t1, 0x1b8e4d09
	p.addRN t2, t0, t1, 18
	sw t2, 4(sp)
	li t0, 0x3edffe8a
	li t1, 0x5ffa7fad
	add t2, t0, t1
	sw t2, 4(sp)
	li t0, 0xc775a013
	li t1, 0xf00267fc
	p.subRN t2, t0, t1, 2
	sw t2, 4(sp)
	li t0, 0xe1eefbc7
	li t1, 0xe1eefe9f
	p.addRN t2, t0, t1, 0
	sw t2, 4(sp)
	li t0, 0x29e26b1c
	li t1, 0x29e26b1c
	p.subRN t2, t0, t1, 23
	sw t2, 4(sp)
	li t0, 0x98c693d2
	li t1, 0xda21a76a
	sub t2, t0, t1
	sw t2, 4(sp)
	li t0, 0x5be3bd78
	li t1, 0x65e3bd79
	p.subRN t2, t0, t1, 1
	sw t2, 4(sp)
	li t0, 0xe37b433b
	li t1, 0x97f58a68
	p.addRN t2, t0, t1, 3
	sw t2, 4(sp)
	li t0, 0xe6bcf7fc
	li t1, 0x36c2f865
	p.subuRN t2, t0, t1, 8
	sw t2, 4(sp)
	li t0, 0xe6bcd002
	li t1, 0xba334a93
	p.addRN t2, t0, t1, 22
	sw t2, 4(sp)
	li t0, 0xf9aabde5
	li t1, 0x7ababe01
	p.subRN t2, t0, t1, 6
	sw t2, 4(sp)
	li t0, 0xeb37ff96
	li t1, 0xeb37ff96
	p.adduRN t2, t0, t1, 30
	sw t2, 4(sp)
	li t0, 0xc45407fb
	li t1, 0x54480802
	p.subRN t2, t0, t1, 5
	sw t2, 4(sp)
	li t0, 0xa2bfec4b
	li t1, 0xf33ee3b3
	p.addRN t2, t0, t1, 2
	sw t2, 4(sp)
	li t0, 0x9bde0e3f
	li t1, 0xba887cef
	add t2, t0, t1
	sw t2, 4(sp)
	li t0, 0xaf7fcdc
	li t1, 0xccf80a03
	p.subuRN t2, t0, t1, 13
	sw t2, 4(sp)
	li t0, 0x4463c415
	li t1, 0xc38231be
	p.subRN t2, t0, t1, 4
	sw t2, 4(sp)
	li t0, 0xe6fc4456
	li t1, 0xe2fc4456
	p.adduRN t2, t0, t1, 20
	sw t2, 4(sp)
	li t0, 0x9719dbce
	li t1, 0x9719dbc6
	p.adduRN t2, t0, t1, 22
	sw t2, 4(sp)
	li t0, 0xf576e5ab
	li t1, 0xf576e5eb
	p.subuRN t2, t0, t1, 24
	sw t2, 4(sp)
	li t0, 0xc618b1af
	li t1, 0x6978ca29
	p.subRN t2, t0, t1, 8
	sw t2, 4(sp)
	li t0, 0x38c27d08
	li t1, 0x472e7e2a
	p.addRN t2, t0, t1, 6
	sw t2, 4(sp)
	li t0, 0x103b583
	li t1, 0x123b583
	p.subRN t2, t0, t1, 23
	sw t2, 4(sp)
	li t0, 0x42f682d6
	li t1, 0x955aa78b
	p.subuRN t2, t0, t1, 21
	sw t2, 4(sp)
	li t0, 0x233a41eb
	li t1, 0xca5b73c5
	p.subRN t2, t0, t1, 18
	sw t2, 4(sp)
	li t0, 0xb68e0bd3
	li t1, 0xb68ecad3
	p.subRN t2, t0, t1, 15
	sw t2, 4(sp)
	li t0, 0xb073447b
	li t1, 0x5b02eb12
	p.adduN t2, t0, t1, 1
	sw t2, 4(sp)
	li t0, 0x2d561733
	li t1, 0x8d561736
	p.subRN t2, t0, t1, 3
	sw t2, 4(sp)
	li t0, 0x3e0703bb
	li t1, 0x62f1f220
	p.subRN t2, t0, t1, 25
	sw t2, 4(sp)
	li t0, 0xc6ff3bf5
	li t1, 0x6ff4a35
	p.subRN t2, t0, t1, 31
	sw t2, 4(sp)
	li t0, 0xd88794be
	li t1, 0xa5cf82d6
	p.subuRN t2, t0, t1, 4
	sw t2, 4(sp)
	li t0, 0xceaf42bd
	li t1, 0xe4a82408
	p.subuRN t2, t0, t1, 8
	sw t2, 4(sp)
	li t0, 0x52b2507
	li t1, 0x642b2507
	p.addRN t2, t0, t1, 30
	sw t2, 4(sp)
	li t0, 0xc7ffff11
	li t1, 0xd7ffff11
	p.addRN t2, t0, t1, 28
	sw t2, 4(sp)
	li t0, 0x4e10efe4
	li t1, 0x4e50efe4
	p.adduN t2, t0, t1, 15
	sw t2, 4(sp)
	li t0, 0x827a1a24
	li t1, 0x827a1224
	p.addRN t2, t0, t1, 19
	sw t2, 4(sp)
	li t0, 0xbd3552ce
	li t1, 0xbd3552ce
	p.addRN t2, t0, t1, 29
	sw t2, 4(sp)
	li t0, 0xff659979
	li t1, 0xff659879
	p.addRN t2, t0, t1, 26
	sw t2, 4(sp)
	li t0, 0xe4294648
	li t1, 0xe4294448
	p.subRN t2, t0, t1, 10
	sw t2, 4(sp)
	li t0, 0x45342ee2
	li t1, 0x45346ee2
	sub t2, t0, t1
	sw t2, 4(sp)
	li t0, 0x9fd5ff25
	li t1, 0x9fd5bf25
	p.subuN t2, t0, t1, 11
	sw t2, 4(sp)
	li t0, 0xf21a23f3
	li t1, 0xb21a23f3
	p.adduN t2, t0, t1, 9
	sw t2, 4(sp)
	li t0, 0x7d4e2a8a
	li t1, 0xfd4e2a8a
	add t2, t0, t1
	sw t2, 4(sp)
	li t0, 0x3e67666c
	li t1, 0x1e67666c
	p.addRN t2, t0, t1, 31
	sw t2, 4(sp)
	li t0, 0x4296b770
	li t1, 0x4396b770
	p.adduRN t2, t0, t1, 1
	sw t2, 4(sp)
	li t0, 0xfeffffc9
	li t1, 0xffffffc9
	p.addRN t2, t0, t1, 24
	sw t2, 4(sp)
	li t0, 0x967fff96
	li t1, 0x977ff982
	add t2, t0, t1
	sw t2, 4(sp)
	li t0, 0x2ad5016c
	li t1, 0x52d5bf00
	p.subuRN t2, t0, t1, 17
	sw t2, 4(sp)
	li t0, 0xd61f2b08
	li t1, 0x88f09ca7
	p.subRN t2, t0, t1, 12
	sw t2, 4(sp)
	li t0, 0x49e5925f
	li t1, 0xf2372484
	p.subuRN t2, t0, t1, 8
	sw t2, 4(sp)
	li t0, 0x504a742f
	li t1, 0x8fb58aa2
	p.addRN t2, t0, t1, 10
	sw t2, 4(sp)
	li t0, 0x30944f7f
	li t1, 0x4ac21004
	p.subuRN t2, t0, t1, 5
	sw t2, 4(sp)
	li t0, 0xffffffff
	li t1, 0xa5610e00
	p.subRN t2, t0, t1, 2
	sw t2, 4(sp)
	li t0, 0x63a21af1
	li t1, 0x63a21ab1
	p.adduN t2, t0, t1, 0
	sw t2, 4(sp)
	li t0, 0x669c3069
	li t1, 0x669c304c
	p.subRN t2, t0, t1, 1
	sw t2, 4(sp)
	li t0, 0xafc37dbb
	li t1, 0xafc17dbb
	p.addRN t2, t0, t1, 31
	sw t2, 4(sp)
	li t0, 0x25452ad
	li t1, 0x5452ad
	p.addRN t2, t0, t1, 28
	sw t2, 4(sp)
	li t0, 0xb8af3f19
	li t1, 0xb0af3f19
	p.addRN t2, t0, t1, 29
	sw t2, 4(sp)
	li t0, 0x1cb52c78
	li t1, 0x6cf70bb0
	p.subuRN t2, t0, t1, 23
	sw t2, 4(sp)
	li t0, 0x63fff8e6
	li t1, 0x637ff8e6
	p.addRN t2, t0, t1, 20
	sw t2, 4(sp)
	li t0, 0xe37abf5e
	li t1, 0xab1ae764
	p.subuRN t2, t0, t1, 12
	sw t2, 4(sp)
	li t0, 0x49e34e9a
	li t1, 0x8ad7d118
	p.addRN t2, t0, t1, 9
	sw t2, 4(sp)
	li t0, 0xa4f19645
	li t1, 0xc569ab3e
	p.adduN t2, t0, t1, 0
	sw t2, 4(sp)
	li t0, 0x8b6c9f08
	li t1, 0x8b6e9f08
	p.adduRN t2, t0, t1, 2
	sw t2, 4(sp)
	li t0, 0x497394c9
	li t1, 0x497314c9
	sub t2, t0, t1
	sw t2, 4(sp)
	li t0, 0xe2d7d417
	li t1, 0x5724aebf
	p.subuRN t2, t0, t1, 26
	sw t2, 4(sp)
	li t0, 0x57fbfa2b
	li t1, 0xe010474f
	p.subRN t2, t0, t1, 27
	sw t2, 4(sp)
	li t0, 0xbafd1c0e
	li t1, 0xaafd1c0e
	add t2, t0, t1
	sw t2, 4(sp)
	li t0, 0xe4397ffb
	li t1, 0x35667ff7
	p.addRN t2, t0, t1, 5
	sw t2, 4(sp)
	li t0, 0xca527fdf
	li t1, 0xc5e48018
	p.subuRN t2, t0, t1, 7
	sw t2, 4(sp)
	li t0, 0xe4433200
	li t1, 0xe4433200
	p.adduRN t2, t0, t1, 13
	sw t2, 4(sp)
	li t0, 0x3a58fece
	li t1, 0x3a58dece
	p.addRN t2, t0, t1, 3
	sw t2, 4(sp)
	li t0, 0xdaec2084
	li t1, 0x34d6bc98
	p.subRN t2, t0, t1, 3
	sw t2, 4(sp)
	li t0, 0xb1367db2
	li t1, 0xb13e7db2
	p.subuRN t2, t0, t1, 27
	sw t2, 4(sp)
	li t0, 0x4aafd7c6
	li t1, 0x4aabd7c6
	p.adduRN t2, t0, t1, 28
	sw t2, 4(sp)
	li t0, 0x8fe9db76
	li t1, 0x8fa9db76
	p.subuRN t2, t0, t1, 5
	sw t2, 4(sp)
	li t0, 0xe5931e93
	li t1, 0xe5921e93
	p.adduRN t2, t0, t1, 16
	sw t2, 4(sp)
	li t0, 0x8548852a
	li t1, 0x8c475711
	p.subRN t2, t0, t1, 20
	sw t2, 4(sp)
	li t0, 0x7af733ff
	li t1, 0x99772800
	p.subRN t2, t0, t1, 1
	sw t2, 4(sp)
	li t0, 0x525f9da
	li t1, 0x13e5bf3c
	p.adduRN t2, t0, t1, 13
	sw t2, 4(sp)
	li t0, 0x3accfc91
	li t1, 0xd6acabea
	p.adduRN t2, t0, t1, 14
	sw t2, 4(sp)
	li t0, 0x9d666200
	li t1, 0xeb5609b0
	p.addRN t2, t0, t1, 12
	sw t2, 4(sp)
	li t0, 0x371cde02
	li t1, 0x371cce02
	p.addRN t2, t0, t1, 28
	sw t2, 4(sp)
	li t0, 0x7b6dbffa
	li t1, 0x556002cd
	p.subuRN t2, t0, t1, 19
	sw t2, 4(sp)
	li t0, 0x5883f588
	li t1, 0x5883f508
	p.subuRN t2, t0, t1, 19
	sw t2, 4(sp)
	li t0, 0x9c1d4b5f
	li t1, 0x9c1d4b5f
	p.adduN t2, t0, t1, 14
	sw t2, 4(sp)
	li t0, 0xe17900c3
	li t1, 0x7d78fd81
	p.subRN t2, t0, t1, 15
	sw t2, 4(sp)
	li t0, 0x70bca1e1
	li t1, 0xbebc6ec0
	p.addRN t2, t0, t1, 9
	sw t2, 4(sp)
	li t0, 0x28a30c28
	li t1, 0x175ce5a1
	p.addRN t2, t0, t1, 14
	sw t2, 4(sp)
	li t0, 0x8a2872fd
	li t1, 0x8a3872fd
	sub t2, t0, t1
	sw t2, 4(sp)
	li t0, 0x4426c7f9
	li t1, 0x4426c7d9
	p.adduN t2, t0, t1, 2
	sw t2, 4(sp)
	li t0, 0x5c373999
	li t1, 0x5c373998
	p.subuN t2, t0, t1, 25
	sw t2, 4(sp)
	li t0, 0xd9c48ee9
	li t1, 0xd9c49ee9
	p.subRN t2, t0, t1, 0
	sw t2, 4(sp)
	li t0, 0x9c39057f
	li t1, 0xc4665090
	p.subuRN t2, t0, t1, 5
	sw t2, 4(sp)
	li t0, 0x8d85e6f0
	li t1, 0x8d85e6f1
	sub t2, t0, t1
	sw t2, 4(sp)
	li t0, 0xe7802da6
	li t1, 0x3e75e197
	p.adduN t2, t0, t1, 21
	sw t2, 4(sp)
	li t0, 0x732c0493
	li t1, 0x1e62400b
	p.adduN t2, t0, t1, 25
	sw t2, 4(sp)
	li t0, 0xb9f77beb
	li t1, 0x8e317060
	p.subuN t2, t0, t1, 23
	sw t2, 4(sp)
	li t0, 0x9dc1491e
	li t1, 0xc941eddb
	sub t2, t0, t1
	sw t2, 4(sp)
	li t0, 0x2d08ffe3
	li t1, 0x2d88ffe3
	p.adduN t2, t0, t1, 14
	sw t2, 4(sp)
	li t0, 0x46bbadeb
	li t1, 0xb6bbb880
	p.subRN t2, t0, t1, 29
	sw t2, 4(sp)
	li t0, 0xe2889abf
	li t1, 0x5475e539
	p.addRN t2, t0, t1, 6
	sw t2, 4(sp)
	li t0, 0xa4999fd0
	li t1, 0xa4999fd2
	p.subuRN t2, t0, t1, 4
	sw t2, 4(sp)
	li t0, 0x71ec4850
	li t1, 0x71ec4877
	sub t2, t0, t1
	sw t2, 4(sp)
	li t0, 0xfdab51bf
	li t1, 0x633bb163
	p.subuRN t2, t0, t1, 3
	sw t2, 4(sp)
	li t0, 0x5fffffc0
	li t1, 0x60000035
	p.subRN t2, t0, t1, 7
	sw t2, 4(sp)
	li t0, 0x3c9f2898
	li t1, 0x3c9f2c98
	p.adduN t2, t0, t1, 11
	sw t2, 4(sp)
	li t0, 0x8110b3ff
	li t1, 0x8110bbff
	p.adduN t2, t0, t1, 8
	sw t2, 4(sp)
	li t0, 0xbfdab418
	li t1, 0x633bb35
	p.subRN t2, t0, t1, 10
	sw t2, 4(sp)
	li t0, 0x9ea67664
	li t1, 0xdd96823
	p.addRN t2, t0, t1, 16
	sw t2, 4(sp)
	li t0, 0xbeba4790
	li t1, 0x3eba4790
	p.addRN t2, t0, t1, 18
	sw t2, 4(sp)
	li t0, 0x47c29706
	li t1, 0xbd73f75
	p.subRN t2, t0, t1, 20
	sw t2, 4(sp)
	li t0, 0xdad8703c
	li t1, 0xdad8701c
	p.subuRN t2, t0, t1, 25
	sw t2, 4(sp)
	li t0, 0x6f2c4801
	li t1, 0x6f2c6801
	p.subRN t2, t0, t1, 16
	sw t2, 4(sp)
	li t0, 0xa8614495
	li t1, 0xc7365e7a
	p.subRN t2, t0, t1, 26
	sw t2, 4(sp)
	li t0, 0x15f6ffa9
	li t1, 0xed841a80
	p.subRN t2, t0, t1, 23
	sw t2, 4(sp)
	li t0, 0xb4e63685
	li t1, 0xb4e63684
	p.adduRN t2, t0, t1, 27
	sw t2, 4(sp)
	li t0, 0xf02d88ae
	li t1, 0xf82d88ae
	p.adduRN t2, t0, t1, 6
	sw t2, 4(sp)
	li t0, 0x2c5b3f37
	li t1, 0x2c5b3fb7
	sub t2, t0, t1
	sw t2, 4(sp)
	li t0, 0xfe45dfca
	li t1, 0xd3a44207
	p.subRN t2, t0, t1, 13
	sw t2, 4(sp)
	li t0, 0xd8f6d6b6
	li t1, 0xd8f6d6b2
	p.addRN t2, t0, t1, 30
	sw t2, 4(sp)
	li t0, 0xe349761c
	li t1, 0x1cb687e2
	p.addRN t2, t0, t1, 10
	sw t2, 4(sp)
	li t0, 0xbf3e8776
	li t1, 0x40bf7888
	p.addRN t2, t0, t1, 18
	sw t2, 4(sp)
	li t0, 0xf970729
	li t1, 0xf064f8d4
	p.addRN t2, t0, t1, 19
	sw t2, 4(sp)
	li t0, 0x589993c3
	li t1, 0x91d0121b
	p.subuN t2, t0, t1, 20
	sw t2, 4(sp)
	li t0, 0x5203f2a3
	li t1, 0x1b4c1312
	p.subuN t2, t0, t1, 18
	sw t2, 4(sp)
	li t0, 0xa90fb951
	li t1, 0x8dbc8989
	add t2, t0, t1
	sw t2, 4(sp)
	li t0, 0x3681058a
	li t1, 0x296204da
	p.addRN t2, t0, t1, 30
	sw t2, 4(sp)
	li t0, 0x15e251f5
	li t1, 0xa03056d
	add t2, t0, t1
	sw t2, 4(sp)
	li t0, 0xab1e9fa
	li t1, 0x855d07b6
	sub t2, t0, t1
	sw t2, 4(sp)
	li t0, 0xfb71ffbf
	li t1, 0x910cfddc
	p.adduRN t2, t0, t1, 14
	sw t2, 4(sp)
	li t0, 0x5e283fff
	li t1, 0x7e284005
	p.subRN t2, t0, t1, 30
	sw t2, 4(sp)
	li t0, 0xc1e5be7f
	li t1, 0x8d909fff
	p.adduRN t2, t0, t1, 10
	sw t2, 4(sp)
	li t0, 0x186fedf7
	li t1, 0x906ff1a0
	p.subRN t2, t0, t1, 28
	sw t2, 4(sp)
	li t0, 0x8f5b8ffe
	li t1, 0xcab61800
	p.subuRN t2, t0, t1, 3
	sw t2, 4(sp)
	li t0, 0xb9e8305b
	li t1, 0xb6ff5cf0
	p.subuN t2, t0, t1, 4
	sw t2, 4(sp)
	li t0, 0x22b1e36c
	li t1, 0x8dbf40e
	p.adduRN t2, t0, t1, 2
	sw t2, 4(sp)
	li t0, 0x9158f1d7
	li t1, 0x846dfa22
	add t2, t0, t1
	sw t2, 4(sp)
	li t0, 0xc8ac78bb
	li t1, 0xc236fd00
	p.subRN t2, t0, t1, 5
	sw t2, 4(sp)
	li t0, 0x65494b6d
	li t1, 0xe3494c8c
	p.subuRN t2, t0, t1, 26
	sw t2, 4(sp)
	li t0, 0x55f3dd89
	li t1, 0x55f3dd99
	p.adduN t2, t0, t1, 10
	sw t2, 4(sp)
	li t0, 0x66a521d9
	li t1, 0xaa5addbc
	p.adduRN t2, t0, t1, 25
	sw t2, 4(sp)
	li t0, 0x4d28588c
	li t1, 0x6a858e5
	p.subRN t2, t0, t1, 24
	sw t2, 4(sp)
	li t0, 0x58b31af5
	li t1, 0xd08ed60f
	p.subuRN t2, t0, t1, 6
	sw t2, 4(sp)
	li t0, 0x2c598dfe
	li t1, 0xe8476b7f
	p.addRN t2, t0, t1, 8
	sw t2, 4(sp)
	li t0, 0xe82cc424
	li t1, 0xe82cc424
	p.addRN t2, t0, t1, 11
	sw t2, 4(sp)
	li t0, 0x342b9edf
	li t1, 0xd3ad01c0
	p.subuRN t2, t0, t1, 17
	sw t2, 4(sp)
	li t0, 0xe41ff72d
	li t1, 0x3a5ebdff
	p.adduRN t2, t0, t1, 16
	sw t2, 4(sp)
	li t0, 0xf22fda37
	li t1, 0x9d22f5ff
	p.adduRN t2, t0, t1, 14
	sw t2, 4(sp)
	li t0, 0xf91bffab
	li t1, 0x4e8f697f
	p.adduRN t2, t0, t1, 18
	sw t2, 4(sp)
	li t0, 0xfdabf685
	li t1, 0xa63eb43f
	p.addRN t2, t0, t1, 21
	sw t2, 4(sp)
	li t0, 0x8ba707aa
	li t1, 0x87d9f8f4
	p.subuRN t2, t0, t1, 22
	sw t2, 4(sp)
	li t0, 0xc3e7e7f5
	li t1, 0x4604645a
	sub t2, t0, t1
	sw t2, 4(sp)
	li t0, 0x6df66c40
	li t1, 0x2eeac6c9
	add t2, t0, t1
	sw t2, 4(sp)
	li t0, 0x3f22bffa
	li t1, 0x945ac000
	p.subuRN t2, t0, t1, 7
	sw t2, 4(sp)

	li t2, 0x33333333
	li t1, 0x33333333
	ori t0, zero, 12
	p.addNr t2, t1, t0
	sw t2, 4(sp)

	li t2, 0x55555555
	li t1, 0x55555555
	ori t0, zero, 12
	p.addNr t2, t1, t0
	sw t2, 4(sp)
	
	li t2, 0x33333333
	li t1, 0x33333333
	ori t0, zero, 12
	p.subNr t2, t1, t0
	sw t2, 4(sp)

	li t2, 0x55555555
	li t1, 0x55555555
	ori t0, zero, 12
	p.subNr t2, t1, t0
	sw t2, 4(sp)

	pv.add.b t0, t1, t2		
	sw t0, 4(sp)
	
	ret
