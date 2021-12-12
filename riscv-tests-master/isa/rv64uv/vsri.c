#include "vector_macros.h"
#include <stdio.h>

/* ARITHMETIC RIGHT SHIFT */

TEST_CASE(test1) {
  set_vregmax(2);
  set_vtype(0, V_INT32);
  set_vtype(2, V_INT32);
  set_vl(5);

  VEC_VLD_VREG_S32(0, 0x80000000, 0x7fffffff, 0x81818181);

  asm volatile ("vsri v2, 0(v0)");
  VEC_CMP_S32(2, 0x80000000, 0x7fffffff, 0x81818181);
}

TEST_CASE(test2) {
  set_vregmax(2);
  set_vtype(0, V_INT64);
  set_vtype(2, V_INT64);
  set_vl(3);

  VEC_VLD_VREG_S64(0, 0x8000000000000000, 0x7fffffffffffffff, 0x8181818181818181);

  asm volatile ("vsri v2, 1(v0)");
  VEC_CMP_S64(2, 0xc000000000000000, 0x3fffffffffffffff, 0xc0c0c0c0c0c0c0c0);
}

TEST_CASE(test3) {
  set_vregmax(2);
  set_vtype(0, V_INT32);
  set_vtype(2, V_INT32);
  set_vl(5);

  VEC_VLD_VREG_S32(0, 0x80000000, 0x7fffffff, 0x81818181);

  asm volatile ("vsri v2, 7(v0)");
  VEC_CMP_S32(2, 0xff000000, 0x00ffffff, 0xff030303);
}

TEST_CASE(test4) {
  set_vregmax(2);
  set_vtype(0, V_INT32);
  set_vtype(2, V_INT32);
  set_vl(5);

  VEC_VLD_VREG_S32(0, 0x80000000, 0x7fffffff, 0x81818181);

  asm volatile ("vsri v2, 14(v0)");
  VEC_CMP_S32(2, 0xfffe0000, 0x0001ffff, 0xfffe0606);
}

TEST_CASE(test5) {
  set_vregmax(2);
  set_vtype(0, V_INT32);
  set_vtype(2, V_INT32);
  set_vl(3);

  VEC_VLD_VREG_S32(0, 0x80000000, 0x7fffffff, 0x81818181);

  asm volatile ("vsri v2, 31(v0)");
  VEC_CMP_S32(2, 0xffffffff, 0x00000000, 0xffffffff);
}

TEST_CASE(test6) {
  set_vregmax(2);
  set_vtype(0, V_INT16);
  set_vtype(2, V_INT32);
  set_vl(3);

  VEC_VLD_VREG_S16(0, 0x8000, 0x7fff, 0x8181);

  asm volatile ("vsri v2, 7(v0)");
  VEC_CMP_S32(2, 0xffffff00, 0x00000ff, 0xffffff03);
}

TEST_CASE(test7) {
  set_vregmax(2);
  set_vtype(0, V_INT8);
  set_vtype(2, V_INT8);
  set_vl(3);

  VEC_VLD_VREG_S8(0, 0x80, 0x7f, 0x82);

  asm volatile ("vsri v2, 1(v0)");

  VEC_CMP_S8(2, 0xc0, 0x3f, 0xc1);
}

//Verify that shifts only use bottom three bits

TEST_CASE(test8) {
  set_vregmax(2);
  set_vtype(0, V_INT8);
  set_vtype(2, V_INT8);
  set_vl(3);

  VEC_VLD_VREG_S8(0, 0x80, 0x7f, 0x82);

  asm volatile ("vsri v2, 25(v0)");

  VEC_CMP_S8(2, 0xc0, 0x3f, 0xc1);
}

TEST_CASE(test9) {
  set_vregmax(2);
  set_vtype(0, V_INT32);
  set_vl(1);

  VEC_VLD_VREG_S32(0, 0x80000000);

  asm volatile ("vsri v0, 7(v0)");
  VEC_CMP_S32(0, 0xff000000);
}

TEST_CASE(test10) {
  set_vregmax(2);
  set_vtype(0, V_INT32);
  set_vtype(1, V_INT32);
  set_vtype(2, V_INT32);
  set_vl(3);

  VEC_VLD_VREG_S32(0, 0x80000000, 0x7fffffff, 0x81818181);
  VEC_VLD_VREG_S32(1, 0, 1, 0);

  asm volatile ("vsri v2, 1(v0), v1.t");
  VEC_CMP_S32(2, 0x00000000, 0x3fffffff, 0x00000000);
}

TEST_CASE(test11) {
  set_vregmax(2);
  set_vtype(0, V_INT32);
  set_vtype(1, V_INT32);
  set_vtype(2, V_INT32);
  set_vl(3);

  VEC_VLD_VREG_S32(0, 0x80000000, 0x7fffffff, 0x81818181);
  VEC_VLD_VREG_S32(1, 0, 1, 0);

  asm volatile ("vsri v2, 1(v0), v1.f");
  VEC_CMP_S32(2, 0xc0000000, 0x00000000, 0xc0c0c0c0);
}

/* LOGIC RIGHT SHIFT */

TEST_CASE(test12) {
  set_vregmax(2);
  set_vtype(0, V_UINT32);
  set_vtype(2, V_UINT32);
  set_vl(3);

  VEC_VLD_VREG_U32(0, 0x80000000, 0x7fffffff, 0x81818181);

  asm volatile ("vsri v2, 0(v0)");
  VEC_CMP_U32(2, 0x80000000, 0x7fffffff, 0x81818181);
}

TEST_CASE(test13) {
  set_vregmax(2);
  set_vtype(0, V_UINT64);
  set_vtype(2, V_UINT64);
  set_vl(3);

  VEC_VLD_VREG_U64(0, 0x8000000000000000, 0x7fffffffffffffff, 0x8181818181818181);

  asm volatile ("vsri v2, 1(v0)");
  VEC_CMP_U64(2, 0x4000000000000000, 0x3fffffffffffffff, 0x40c0c0c0c0c0c0c0);
}

TEST_CASE(test14) {
  set_vregmax(2);
  set_vtype(0, V_UINT32);
  set_vtype(2, V_UINT32);
  set_vl(3);

  VEC_VLD_VREG_U32(0, 0x80000000, 0x7fffffff, 0x81818181);

  asm volatile ("vsri v2, 7(v0)");
  VEC_CMP_U32(2, 0x01000000, 0x00ffffff, 0x01030303);
}

TEST_CASE(test15) {
  set_vregmax(2);
  set_vtype(0, V_UINT32);
  set_vtype(2, V_UINT32);
  set_vl(3);

  VEC_VLD_VREG_U32(0, 0x80000000, 0x7fffffff, 0x81818181);

  asm volatile ("vsri v2, 14(v0)");
  VEC_CMP_U32(2, 0x00020000, 0x0001ffff, 0x00020606);
}

TEST_CASE(test16) {
  set_vregmax(2);
  set_vtype(0, V_UINT32);
  set_vtype(2, V_UINT32);
  set_vl(3);

  VEC_VLD_VREG_U32(0, 0x80000000, 0x7fffffff, 0x81818181);

  asm volatile ("vsri v2, 31(v0)");
  VEC_CMP_U32(2, 0x00000001, 0x00000000, 0x00000001);
}

TEST_CASE(test17) {
  set_vregmax(2);
  set_vtype(0, V_UINT16);
  set_vtype(2, V_UINT32);
  set_vl(3);

  VEC_VLD_VREG_U16(0, 0x8000, 0x7fff, 0x8181);

  asm volatile ("vsri v2, 7(v0)");
  VEC_CMP_U32(2, 0x00000100, 0x00000ff, 0x00000103);
}

TEST_CASE(test18) {
  set_vregmax(2);
  set_vtype(0, V_UINT8);
  set_vtype(2, V_UINT8);
  set_vl(3);

  VEC_VLD_VREG_U8(0, 0x80, 0x7f, 0x82);

  asm volatile ("vsri v2, 1(v0)");

  VEC_CMP_S8(2, 0x40, 0x3f, 0x41);
}

//Verify that shifts only use bottom three bits

TEST_CASE(test19) {
  set_vregmax(2);
  set_vtype(0, V_UINT8);
  set_vtype(2, V_UINT8);
  set_vl(3);

  VEC_VLD_VREG_U8(0, 0x80, 0x7f, 0x82);

  asm volatile ("vsri v2, 25(v0)");

  VEC_CMP_S8(2, 0x40, 0x3f, 0x41);
}

TEST_CASE(test20) {
  set_vregmax(1);
  set_vtype(0, V_UINT32);
  set_vl(1);

  VEC_VLD_VREG_U32(0, 0x80000000);

  asm volatile ("vsri v0, 7(v0)");
  VEC_CMP_U32(0, 0x01000000);
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
  DECLARE_TEST(test16);
  DECLARE_TEST(test17);
  DECLARE_TEST(test18);
  DECLARE_TEST(test19);
  DECLARE_TEST(test20);

  return run_all_tests();
}
