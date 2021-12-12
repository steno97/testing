#include "vector_macros.h"
#include <stdio.h>

TEST_CASE(test1) {
  set_vregmax(2);
  set_vtype(0, V_UINT32);
  set_vtype(1, V_UINT32);
  set_vtype(2, V_UINT32);
  set_vl(5);

  VEC_VLD_VREG_U32(0, 0x00000001, 0x00000001, 0x00000001, 0x00000001, 0x00000001);
  VEC_VLD_VREG_U32(1,          0,          1,          7,         14,         31);

  asm volatile ("vsl v2, v0, v1");
  VEC_CMP_U32(2, 0x00000001, 0x00000002, 0x00000080, 0x00004000, 0x80000000);
}

TEST_CASE(test2) {
  set_vregmax(2);
  set_vtype(0, V_UINT32);
  set_vtype(1, V_UINT32);
  set_vtype(2, V_UINT32);
  set_vl(5);

  VEC_VLD_VREG_U32(0, 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff);
  VEC_VLD_VREG_U32(1,          0,          1,          7,         14,         31);

  asm volatile ("vsl v2, v0, v1");
  VEC_CMP_U32(2, 0xffffffff, 0xfffffffe, 0xffffff80, 0xffffc000, 0x80000000);
}

TEST_CASE(test3) {
  set_vregmax(2);
  set_vtype(0, V_UINT32);
  set_vtype(1, V_UINT32);
  set_vtype(2, V_UINT32);
  set_vl(5);

  VEC_VLD_VREG_U32(0, 0x21212121, 0x21212121, 0x21212121, 0x21212121, 0x21212121);
  VEC_VLD_VREG_U32(1,          0,          1,          7,         14,         31);

  asm volatile ("vsl v2, v0, v1");

  VEC_CMP_U32(2, 0x21212121, 0x42424242, 0x90909080, 0x48484000, 0x80000000);
}

//Verify that shifts only use bottom five bits

TEST_CASE(test4) {
  set_vregmax(2);
  set_vtype(0, V_UINT32);
  set_vtype(1, V_UINT32);
  set_vtype(2, V_UINT32);
  set_vl(4);

  VEC_VLD_VREG_U32(0, 0x21212121, 0x21212121, 0x21212121, 0x21212121);
  VEC_VLD_VREG_U32(1, 0xffffffc0, 0xffffffc1, 0xffffffc7, 0xffffffce);

  asm volatile ("vsl v2, v0, v1");

  VEC_CMP_U32(2, 0x21212121, 0x42424242, 0x90909080, 0x48484000);
}

TEST_CASE(test5) {
  set_vregmax(2);
  set_vtype(0, V_UINT16);
  set_vtype(1, V_UINT16);
  set_vtype(2, V_UINT16);
  set_vl(4);

  VEC_VLD_VREG_U16(0, 0x0001, 0x0001, 0x0001, 0x0001);
  VEC_VLD_VREG_U16(1,      0,      1,      7,     14);

  asm volatile ("vsl v2, v0, v1");
  VEC_CMP_U16(2, 0x0001, 0x0002, 0x0080, 0x4000);
}

TEST_CASE(test6) {
  set_vregmax(2);
  set_vtype(0, V_UINT16);
  set_vtype(1, V_UINT16);
  set_vtype(2, V_UINT16);
  set_vl(4);

  VEC_VLD_VREG_U16(0, 0xffff, 0xffff, 0xffff, 0xffff);
  VEC_VLD_VREG_U16(1,      0,      1,      7,     14);

  asm volatile ("vsl v2, v0, v1");
  VEC_CMP_U16(2, 0xffff, 0xfffe, 0xff80, 0xc000);
}

TEST_CASE(test7) {
  set_vregmax(2);
  set_vtype(0, V_UINT8);
  set_vtype(1, V_UINT8);
  set_vtype(2, V_UINT8);
  set_vl(3);

  VEC_VLD_VREG_U8(0, 0x21, 0x21, 0x21);
  VEC_VLD_VREG_U8(1,    0,    1,    7);

  asm volatile ("vsl v2, v0, v1");

  VEC_CMP_U8(2, 0x21, 0x42, 0x80);
}

//Verify that shifts only use bottom four bits

TEST_CASE(test8) {
  set_vregmax(2);
  set_vtype(0, V_UINT16);
  set_vtype(1, V_UINT16);
  set_vtype(2, V_UINT16);
  set_vl(4);

  VEC_VLD_VREG_U16(0, 0x2121, 0x2121, 0x2121, 0x2121);
  VEC_VLD_VREG_U16(1, 0xfff0, 0xfff1, 0xfff7, 0xfffe);

  asm volatile ("vsl v2, v0, v1");

  VEC_CMP_U16(2, 0x2121, 0x4242, 0x9080, 0x4000);
}

TEST_CASE(test9) {
  set_vregmax(1);
  set_vtype(0, V_UINT32);
  set_vtype(1, V_UINT32);
  set_vl(1);

  VEC_VLD_VREG_U32(0, 0x00000001);
  VEC_VLD_VREG_U32(1, 7);

  asm volatile ("vsl v0, v0, v1");
  VEC_CMP_U32(0, 0x00000080);
}

TEST_CASE(test10) {
  set_vregmax(1);
  set_vtype(0, V_UINT32);
  set_vtype(1, V_UINT32);
  set_vl(1);

  VEC_VLD_VREG_U32(0, 0x00000001);
  VEC_VLD_VREG_U32(1, 14);

  asm volatile ("vsl v1, v0, v1");
  VEC_CMP_U32(1, 0x00004000);
}

TEST_CASE(test11) {
  set_vregmax(1);
  set_vtype(0, V_UINT32);
  set_vl(1);

  VEC_VLD_VREG_U32(0, 3);

  asm volatile ("vsl v0, v0, v0");
  VEC_CMP_U32(0, 24);
}

TEST_CASE(test12) {
  set_vregmax(3);
  set_vtype(0, V_UINT32);
  set_vtype(1, V_UINT32);
  set_vtype(2, V_UINT32);
  set_vtype(3, V_UINT32);
  set_vl(5);

  VEC_VLD_VREG_U32(1, 0x00000001, 0xfffffffe, 0x00000001, 0x00000000, 0x0f0f0f0f);
  VEC_VLD_VREG_U32(2, 0x00000001, 0x00000001, 0x00000001, 0x00000001, 0x00000001);
  VEC_VLD_VREG_U32(3,          0,          1,          7,         14,         31);

  asm volatile ("vsl v0, v2, v3, v1.t");
  VEC_CMP_U32(0, 0x00000001, 0x00000000, 0x00000080, 0x00000000, 0x80000000);
}

TEST_CASE(test13) {
  set_vregmax(3);
  set_vtype(0, V_UINT32);
  set_vtype(1, V_UINT32);
  set_vtype(2, V_UINT32);
  set_vtype(3, V_UINT32);
  set_vl(5);

  VEC_VLD_VREG_U32(1, 0x00000001, 0xfffffffe, 0x00000001, 0x00000000, 0x0f0f0f0f);
  VEC_VLD_VREG_U32(2, 0x00000001, 0x00000001, 0x00000001, 0x00000001, 0x00000001);
  VEC_VLD_VREG_U32(3,          0,          1,          7,         14,         31);

  asm volatile ("vsl v0, v2, v3, v1.f");
  VEC_CMP_U32(0, 0x00000000, 0x00000002, 0x00000000, 0x00004000, 0x00000000);
}

TEST_CASE(test14) {
  set_vregmax(2);
  set_vtype(0, V_UINT64);
  set_vtype(1, V_UINT64);
  set_vtype(2, V_UINT64);
  set_vl(6);

  VEC_VLD_VREG_U64(0, 0x0000000000000001, 0x0000000000000001, 0x0000000000000001, 0x0000000000000001, 0x0000000000000001, 0x0000000000000001);
  VEC_VLD_VREG_U64(1,                  0,                  1,                  7,                 14,                 31,                 63);

  asm volatile ("vsl v2, v0, v1");
  VEC_CMP_U64(2, 0x0000000000000001, 0x0000000000000002, 0x0000000000000080, 0x0000000000004000, 0x0000000080000000, 0x8000000000000000);
}

TEST_CASE(test15) {
  set_vregmax(2);
  set_vtype(0, V_UINT64);
  set_vtype(1, V_UINT64);
  set_vtype(2, V_UINT64);
  set_vl(4);

  VEC_VLD_VREG_U64(0, 0x0000000021212121, 0x0000000000000001, 0xffffffffffffffff, 0x0000000021212121);
  VEC_VLD_VREG_U64(1, 0xffffffffffffffff, 63, 39, 43);

  asm volatile ("vsl v2, v0, v1");
  VEC_CMP_U64(2, 0x8000000000000000, 0x8000000000000000, 0xffffff8000000000, 0x0909080000000000);
}

int main(void) {
  DECLARE_TEST(test1);
  DECLARE_TEST(test2);
  DECLARE_TEST(test3);
  DECLARE_TEST(test4);
  DECLARE_TEST(test5);
  DECLARE_TEST(test6);
  DECLARE_TEST(test7);
  DECLARE_TEST(test8);
  DECLARE_TEST(test9);
  DECLARE_TEST(test10);
  DECLARE_TEST(test11);
  DECLARE_TEST(test12);
  DECLARE_TEST(test13);
  DECLARE_TEST(test14);
  DECLARE_TEST(test15);

  return run_all_tests();
}
