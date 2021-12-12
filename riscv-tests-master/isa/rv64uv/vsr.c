#include "vector_macros.h"
#include <stdio.h>

/* ARITHMETIC RIGHT SHIFT */

TEST_CASE(test1) {
  set_vregmax(2);
  set_vtype(0, V_INT32);
  set_vtype(1, V_INT32);
  set_vtype(2, V_INT32);
  set_vl(5);

  VEC_VLD_VREG_S32(0, 0x80000000, 0x80000000, 0x80000000, 0x80000000, 0x80000000);
  VEC_VLD_VREG_S32(1,          0,          1,          7,         14,         31);

  asm volatile ("vsr v2, v0, v1");
  VEC_CMP_S32(2, 0x80000000, 0xc0000000, 0xff000000, 0xfffe0000, 0xffffffff);
}

TEST_CASE(test2) {
  set_vregmax(2);
  set_vtype(0, V_INT32);
  set_vtype(1, V_INT32);
  set_vtype(2, V_INT32);
  set_vl(5);

  VEC_VLD_VREG_S32(0, 0x7fffffff, 0x7fffffff, 0x7fffffff, 0x7fffffff, 0x7fffffff);
  VEC_VLD_VREG_S32(1,          0,          1,          7,         14,         31);

  asm volatile ("vsr v2, v0, v1");
  VEC_CMP_S32(2, 0x7fffffff, 0x3fffffff, 0x00ffffff, 0x0001ffff, 0x00000000);
}

TEST_CASE(test3) {
  set_vregmax(2);
  set_vtype(0, V_INT64);
  set_vtype(1, V_INT64);
  set_vtype(2, V_INT64);
  set_vl(6);

  VEC_VLD_VREG_S64(0, 0x8000000000000000, 0x8000000000000000, 0x8000000000000000, 0x8000000000000000, 0x8000000000000000, 0x8000000000000000);
  VEC_VLD_VREG_S64(1,                  0,                  1,                  7,                 14,                 31,                 63);

  asm volatile ("vsr v2, v0, v1");
  VEC_CMP_S64(2, 0x8000000000000000, 0xc000000000000000, 0xff00000000000000, 0xfffe000000000000, 0xffffffff00000000, 0xffffffffffffffff);
}

TEST_CASE(test4) {
  set_vregmax(2);
  set_vtype(0, V_INT64);
  set_vtype(1, V_INT64);
  set_vtype(2, V_INT64);
  set_vl(6);

  VEC_VLD_VREG_S64(0, 0x7fffffffffffffff, 0x7fffffffffffffff, 0x7fffffffffffffff, 0x7fffffffffffffff, 0x7fffffffffffffff, 0x7fffffffffffffff);
  VEC_VLD_VREG_S64(1,                  0,                  1,                  7,                 14,                 31,                 63);

  asm volatile ("vsr v2, v0, v1");
  VEC_CMP_S64(2, 0x7fffffffffffffff, 0x3fffffffffffffff, 0x00ffffffffffffff, 0x0001ffffffffffff, 0x00000000ffffffff, 0x0000000000000000);
}

TEST_CASE(test5) {
  set_vregmax(2);
  set_vtype(0, V_INT32);
  set_vtype(1, V_INT32);
  set_vtype(2, V_INT32);
  set_vl(5);

  VEC_VLD_VREG_S32(0, 0x81818181, 0x81818181, 0x81818181, 0x81818181, 0x81818181);
  VEC_VLD_VREG_S32(1,          0,          1,          7,         14,         31);

  asm volatile ("vsr v2, v0, v1");

  VEC_CMP_S32(2, 0x81818181, 0xc0c0c0c0, 0xff030303, 0xfffe0606, 0xffffffff);
}

//Verify that shifts only use bottom five bits

TEST_CASE(test6) {
  set_vregmax(2);
  set_vtype(0, V_INT32);
  set_vtype(1, V_INT32);
  set_vtype(2, V_INT32);
  set_vl(5);

  VEC_VLD_VREG_S32(0, 0x81818181, 0x81818181, 0x81818181, 0x81818181, 0x81818181);
  VEC_VLD_VREG_S32(1, 0xffffffc0, 0xffffffc1, 0xffffffc7, 0xffffffce, 0xffffffff);

  asm volatile ("vsr v2, v0, v1");

  VEC_CMP_S32(2, 0x81818181, 0xc0c0c0c0, 0xff030303, 0xfffe0606, 0xffffffff);
}

TEST_CASE(test7) {
  set_vregmax(2);
  set_vtype(0, V_INT16);
  set_vtype(1, V_INT16);
  set_vtype(2, V_INT16);
  set_vl(4);

  VEC_VLD_VREG_S16(0, 0x8000, 0x8000, 0x8000, 0x8000);
  VEC_VLD_VREG_S16(1,      0,      1,      7,     14);

  asm volatile ("vsr v2, v0, v1");
  VEC_CMP_S16(2, 0x8000, 0xc000, 0xff00, 0xfffe);
}

TEST_CASE(test8) {
  set_vregmax(2);
  set_vtype(0, V_INT8);
  set_vtype(1, V_INT8);
  set_vtype(2, V_INT8);
  set_vl(3);

  VEC_VLD_VREG_S8(0, 0x81, 0x81, 0x81);
  VEC_VLD_VREG_S8(1,    0,    1,    7);

  asm volatile ("vsr v2, v0, v1");

  VEC_CMP_S8(2, 0x81, 0xc0, 0xff);
}

//Verify that shifts only use bottom three bits

TEST_CASE(test9) {
  set_vregmax(2);
  set_vtype(0, V_INT8);
  set_vtype(1, V_INT8);
  set_vtype(2, V_INT8);
  set_vl(3);

  VEC_VLD_VREG_S8(0, 0x81, 0x81, 0x81);
  VEC_VLD_VREG_S8(1, 0xf8, 0xf9, 0xfe);

  asm volatile ("vsr v2, v0, v1");

  VEC_CMP_S8(2, 0x81, 0xc0, 0xfe);
}

TEST_CASE(test10) {
  set_vregmax(1);
  set_vtype(0, V_INT32);
  set_vtype(1, V_INT32);
  set_vl(1);

  VEC_VLD_VREG_S32(0, 0x80000000);
  VEC_VLD_VREG_S32(1, 7);

  asm volatile ("vsr v0, v0, v1");
  VEC_CMP_S32(0, 0xff000000);
}

TEST_CASE(test11) {
  set_vregmax(1);
  set_vtype(0, V_INT32);
  set_vtype(1, V_INT32);
  set_vl(1);

  VEC_VLD_VREG_S32(0, 0x80000000);
  VEC_VLD_VREG_S32(1, 14);

  asm volatile ("vsr v1, v0, v1");
  VEC_CMP_S32(1, 0xfffe0000);
}

TEST_CASE(test12) {
  set_vregmax(1);
  set_vtype(0, V_INT32);
  set_vl(1);

  VEC_VLD_VREG_S32(0, 7);

  asm volatile ("vsr v0, v0, v0");
  VEC_CMP_S32(0, 0);
}

/* LOGIC RIGHT SHIFT */

TEST_CASE(test13) {
  set_vregmax(2);
  set_vtype(0, V_UINT32);
  set_vtype(1, V_UINT32);
  set_vtype(2, V_UINT32);
  set_vl(5);

  VEC_VLD_VREG_U32(0, 0x80000000, 0x80000000, 0x80000000, 0x80000000, 0x80000000);
  VEC_VLD_VREG_U32(1,          0,          1,          7,         14,         31);

  asm volatile ("vsr v2, v0, v1");
  VEC_CMP_U32(2, 0x80000000, 0x40000000, 0x01000000, 0x00020000, 0x0000001);
}

TEST_CASE(test14) {
  set_vregmax(2);
  set_vtype(0, V_UINT32);
  set_vtype(1, V_UINT32);
  set_vtype(2, V_UINT32);
  set_vl(5);

  VEC_VLD_VREG_U32(0, 0x7fffffff, 0x7fffffff, 0x7fffffff, 0x7fffffff, 0x7fffffff);
  VEC_VLD_VREG_U32(1,          0,          1,          7,         14,         31);

  asm volatile ("vsr v2, v0, v1");
  VEC_CMP_U32(2, 0x7fffffff, 0x3fffffff, 0x00ffffff, 0x0001ffff, 0x00000000);
}

TEST_CASE(test15) {
  set_vregmax(2);
  set_vtype(0, V_UINT64);
  set_vtype(1, V_UINT64);
  set_vtype(2, V_UINT64);
  set_vl(6);

  VEC_VLD_VREG_U64(0, 0x8000000000000000, 0x8000000000000000, 0x8000000000000000, 0x8000000000000000, 0x8000000000000000, 0x8000000000000000);
  VEC_VLD_VREG_U64(1,                  0,                  1,                  7,                 14,                 31,                 63);

  asm volatile ("vsr v2, v0, v1");
  VEC_CMP_U64(2, 0x8000000000000000, 0x4000000000000000, 0x0100000000000000, 0x0002000000000000, 0x0000000100000000, 0x0000000000000001);
}

TEST_CASE(test16) {
  set_vregmax(2);
  set_vtype(0, V_UINT64);
  set_vtype(1, V_UINT64);
  set_vtype(2, V_UINT64);
  set_vl(6);

  VEC_VLD_VREG_U64(0, 0x7fffffffffffffff, 0x7fffffffffffffff, 0x7fffffffffffffff, 0x7fffffffffffffff, 0x7fffffffffffffff, 0x7fffffffffffffff);
  VEC_VLD_VREG_U64(1,                  0,                  1,                  7,                 14,                 31,                 63);

  asm volatile ("vsr v2, v0, v1");
  VEC_CMP_U64(2, 0x7fffffffffffffff, 0x3fffffffffffffff, 0x00ffffffffffffff, 0x0001ffffffffffff, 0x00000000ffffffff, 0x0000000000000000);
}

TEST_CASE(test17) {
  set_vregmax(2);
  set_vtype(0, V_UINT32);
  set_vtype(1, V_UINT32);
  set_vtype(2, V_UINT32);
  set_vl(5);

  VEC_VLD_VREG_U32(0, 0x81818181, 0x81818181, 0x81818181, 0x81818181, 0x81818181);
  VEC_VLD_VREG_U32(1,          0,          1,          7,         14,         31);

  asm volatile ("vsr v2, v0, v1");

  VEC_CMP_U32(2, 0x81818181, 0x40c0c0c0, 0x01030303, 0x00020606, 0x00000001);
}

//Verify that shifts only use bottom five bits

TEST_CASE(test18) {
  set_vregmax(2);
  set_vtype(0, V_UINT32);
  set_vtype(1, V_UINT32);
  set_vtype(2, V_UINT32);
  set_vl(5);

  VEC_VLD_VREG_U32(0, 0x81818181, 0x81818181, 0x81818181, 0x81818181, 0x81818181);
  VEC_VLD_VREG_U32(1, 0xffffffc0, 0xffffffc1, 0xffffffc7, 0xffffffce, 0xffffffff);

  asm volatile ("vsr v2, v0, v1");

  VEC_CMP_U32(2, 0x81818181, 0x40c0c0c0, 0x01030303, 0x00020606, 0x00000001);
}

TEST_CASE(test19) {
  set_vregmax(2);
  set_vtype(0, V_UINT16);
  set_vtype(1, V_UINT16);
  set_vtype(2, V_UINT16);
  set_vl(4);

  VEC_VLD_VREG_U16(0, 0x8000, 0x8000, 0x8000, 0x8000);
  VEC_VLD_VREG_U16(1,      0,      1,      7,     14);

  asm volatile ("vsr v2, v0, v1");
  VEC_CMP_U16(2, 0x8000, 0x4000, 0x0100, 0x0002);
}

TEST_CASE(test20) {
  set_vregmax(2);
  set_vtype(0, V_UINT8);
  set_vtype(1, V_UINT8);
  set_vtype(2, V_UINT8);
  set_vl(3);

  VEC_VLD_VREG_U8(0, 0x81, 0x81, 0x81);
  VEC_VLD_VREG_U8(1,    0,    1,    7);

  asm volatile ("vsr v2, v0, v1");

  VEC_CMP_U8(2, 0x81, 0x40, 0x01);
}

//Verify that shifts only use bottom three bits

TEST_CASE(test21) {
  set_vregmax(2);
  set_vtype(0, V_UINT8);
  set_vtype(1, V_UINT8);
  set_vtype(2, V_UINT8);
  set_vl(3);

  VEC_VLD_VREG_U8(0, 0x81, 0x81, 0x81);
  VEC_VLD_VREG_U8(1, 0xf8, 0xf9, 0xfe);

  asm volatile ("vsr v2, v0, v1");

  VEC_CMP_U8(2, 0x81, 0x40, 0x02);
}

TEST_CASE(test22) {
  set_vregmax(1);
  set_vtype(0, V_UINT32);
  set_vtype(1, V_UINT32);
  set_vl(1);

  VEC_VLD_VREG_U32(0, 0x80000000);
  VEC_VLD_VREG_U32(1, 7);

  asm volatile ("vsr v0, v0, v1");
  VEC_CMP_U32(0, 0x01000000);
}

TEST_CASE(test23) {
  set_vregmax(1);
  set_vtype(0, V_UINT32);
  set_vtype(1, V_UINT32);
  set_vl(1);

  VEC_VLD_VREG_U32(0, 0x80000000);
  VEC_VLD_VREG_U32(1, 14);

  asm volatile ("vsr v1, v0, v1");
  VEC_CMP_U32(1, 0x00020000);
}

TEST_CASE(test24) {
  set_vregmax(1);
  set_vtype(0, V_UINT32);
  set_vl(1);

  VEC_VLD_VREG_U32(0, 7);

  asm volatile ("vsr v0, v0, v0");
  VEC_CMP_U32(0, 0);
}

TEST_CASE(test25) {
  set_vregmax(3);
  set_vtype(0, V_INT32);
  set_vtype(1, V_INT16);
  set_vtype(2, V_INT32);
  set_vtype(3, V_INT32);
  set_vl(5);

  VEC_VLD_VREG_U16(1,          0,          1,          0,          1,          0)
  VEC_VLD_VREG_S32(2, 0x80000000, 0x80000000, 0x80000000, 0x80000000, 0x80000000);
  VEC_VLD_VREG_S32(3,          0,          1,          7,         14,         31);

  asm volatile ("vsr v0, v2, v3, v1.t");
  VEC_CMP_S32(0, 0x00000000, 0xc0000000, 0x00000000, 0xfffe0000, 0x00000000);
}

TEST_CASE(test26) {
  set_vregmax(3);
  set_vtype(0, V_INT32);
  set_vtype(1, V_INT16);
  set_vtype(2, V_INT32);
  set_vtype(3, V_INT32);
  set_vl(5);

  VEC_VLD_VREG_U16(1,          0,          1,          0,          1,          0)
  VEC_VLD_VREG_S32(2, 0x80000000, 0x80000000, 0x80000000, 0x80000000, 0x80000000);
  VEC_VLD_VREG_S32(3,          0,          1,          7,         14,         31);

  asm volatile ("vsr v0, v2, v3, v1.f");
  VEC_CMP_S32(0, 0x80000000, 0x00000000, 0xff000000, 0x00000000, 0xffffffff);
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
  DECLARE_TEST(test21);
  DECLARE_TEST(test22);
  DECLARE_TEST(test23);
  DECLARE_TEST(test24);
  DECLARE_TEST(test25);
  DECLARE_TEST(test26);

  return run_all_tests();
}
