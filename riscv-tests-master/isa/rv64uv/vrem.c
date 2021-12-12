#include "vector_macros.h"
#include <stdio.h>

TEST_CASE(test1) {
  set_vregmax(2);
  set_vtype(0, V_INT64);
  set_vtype(1, V_INT64);
  set_vtype(2, V_INT64);
  set_vl(4);

  VEC_VLD_VREG_S64(0, 20, -20, 20, -20);
  VEC_VLD_VREG_S64(1,  6,   6, -6,  -6);

  asm volatile ("vrem v2, v0, v1");
  VEC_CMP_S64(2, 2, -2, 2, -2);
}

TEST_CASE(test2) {
  set_vregmax(2);
  set_vtype(0, V_INT32);
  set_vtype(1, V_INT32);
  set_vtype(2, V_INT32);
  set_vl(2);

  VEC_VLD_VREG_S32(0, -1<<31, -1<<31);
  VEC_VLD_VREG_S32(1,      1,     -1);

  asm volatile ("vrem v2, v0, v1");
  VEC_CMP_S32(2, 0, 0);
}

TEST_CASE(test3) {
  set_vregmax(2);
  set_vtype(0, V_INT32);
  set_vtype(1, V_INT32);
  set_vtype(2, V_INT32);
  set_vl(3);

  VEC_VLD_VREG_S32(0, -1<<31, 1, 0);
  VEC_VLD_VREG_S32(1,      0, 0, 0);

  asm volatile ("vrem v2, v0, v1");
  VEC_CMP_S32(2, -1<<31, 1, 0);
}

TEST_CASE(test4) {
  set_vregmax(3);
  set_vtype(0, V_INT32);
  set_vtype(1, V_INT32);
  set_vtype(2, V_INT32);
  set_vtype(3, V_INT32);
  set_vl(4);

  VEC_VLD_VREG_S32(1,  0,   1,  0,   1);
  VEC_VLD_VREG_S32(2, 20, -20, 20, -20);
  VEC_VLD_VREG_S32(3,  6,   6, -6,  -6);

  asm volatile ("vrem v0, v2, v3, v1.t");
  VEC_CMP_S32(0, 0, -2, 0, -2);
}

TEST_CASE(test5) {
  set_vregmax(3);
  set_vtype(0, V_INT32);
  set_vtype(1, V_INT32);
  set_vtype(2, V_INT32);
  set_vtype(3, V_INT32);
  set_vl(4);

  VEC_VLD_VREG_S32(1,  0,   1,  0,   1);
  VEC_VLD_VREG_S32(2, 20, -20, 20, -20);
  VEC_VLD_VREG_S32(3,  6,   6, -6,  -6);

  asm volatile ("vrem v0, v2, v3, v1.f");
  VEC_CMP_S32(0, 2, 0, 2, 0);
}

TEST_CASE(test6) {
  set_vregmax(3);
  set_vtype(0, V_UINT32);
  set_vtype(1, V_UINT32);
  set_vtype(2, V_UINT32);
  set_vtype(3, V_UINT32);
  set_vl(4);

  VEC_VLD_VREG_U32(0, 20, -20, 20, -20);
  VEC_VLD_VREG_U32(1,  6,   6, -6,  -6);

  asm volatile ("vrem v2, v0, v1");
  VEC_CMP_U32(2, 2, 2, 20, -20);
}

TEST_CASE(test7) {
  set_vregmax(3);
  set_vtype(0, V_UINT32);
  set_vtype(1, V_UINT32);
  set_vtype(2, V_UINT32);
  set_vtype(3, V_UINT32);
  set_vl(2);

  VEC_VLD_VREG_U32(0, -1<<31, -1<<31);
  VEC_VLD_VREG_U32(1,      1,     -1);

  asm volatile ("vrem v2, v0, v1");
  VEC_CMP_U32(2, 0, -1<<31);
}

TEST_CASE(test8) {
  set_vregmax(3);
  set_vtype(0, V_UINT32);
  set_vtype(1, V_UINT32);
  set_vtype(2, V_UINT32);
  set_vtype(3, V_UINT32);
  set_vl(3);

  VEC_VLD_VREG_U32(0, -1<<31, 1, 0);
  VEC_VLD_VREG_U32(1,      0, 0, 0);

  asm volatile ("vrem v2, v0, v1");
  VEC_CMP_U32(2, -1<<31, 1, 0);
}

TEST_CASE(test9) {
  set_vregmax(2);
  set_vtype(0, V_INT16);
  set_vtype(1, V_INT16);
  set_vtype(2, V_INT16);
  set_vl(4);

  VEC_VLD_VREG_S16(0, 20, -20, 20, -20);
  VEC_VLD_VREG_S16(1,  6,   6, -6,  -6);

  asm volatile ("vrem v2, v0, v1");
  VEC_CMP_S16(2, 2, -2, 2, -2);
}

TEST_CASE(test10) {
  set_vregmax(2);
  set_vtype(0, V_INT16);
  set_vtype(1, V_INT16);
  set_vtype(2, V_INT16);
  set_vl(2);

  VEC_VLD_VREG_S16(0, -1<<15, -1<<15);
  VEC_VLD_VREG_S16(1,      1,     -1);

  asm volatile ("vrem v2, v0, v1");
  VEC_CMP_S16(2, 0, 0);
}

TEST_CASE(test11) {
  set_vregmax(2);
  set_vtype(0, V_INT16);
  set_vtype(1, V_INT16);
  set_vtype(2, V_INT16);
  set_vl(3);

  VEC_VLD_VREG_S16(0, -1<<15, 1, 0);
  VEC_VLD_VREG_S16(1,      0, 0, 0);

  asm volatile ("vrem v2, v0, v1");
  VEC_CMP_S16(2, -1<<15, 1, 0);
}

TEST_CASE(test12) {
  set_vregmax(2);
  set_vtype(0, V_UINT16);
  set_vtype(1, V_UINT16);
  set_vtype(2, V_UINT16);
  set_vl(4);

  VEC_VLD_VREG_U16(0, 20, -20, 20, -20);
  VEC_VLD_VREG_U16(1,  6,   6, -6,  -6);

  asm volatile ("vrem v2, v0, v1");
  VEC_CMP_U16(2, 2, 2, 20, -20);
}

TEST_CASE(test13) {
  set_vregmax(2);
  set_vtype(0, V_UINT16);
  set_vtype(1, V_UINT16);
  set_vtype(2, V_UINT16);
  set_vl(2);

  VEC_VLD_VREG_U16(0, -1<<15, -1<<15);
  VEC_VLD_VREG_U16(1,      1,     -1);

  asm volatile ("vrem v2, v0, v1");
  VEC_CMP_U16(2, 0, -1<<15);
}

TEST_CASE(test14) {
  set_vregmax(2);
  set_vtype(0, V_UINT16);
  set_vtype(1, V_UINT16);
  set_vtype(2, V_UINT16);
  set_vl(3);

  VEC_VLD_VREG_U16(0, -1<<15, 1, 0);
  VEC_VLD_VREG_U16(1,      0, 0, 0);

  asm volatile ("vrem v2, v0, v1");
  VEC_CMP_U16(2, -1<<15, 1, 0);
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

  return run_all_tests();
}
