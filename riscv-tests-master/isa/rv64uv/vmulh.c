#include "vector_macros.h"
#include <stdio.h>

/* mulh */

TEST_CASE(test1) {
  set_vregmax(2);
  set_vtype(0, V_INT32);
  set_vtype(1, V_INT32);
  set_vtype(2, V_INT32);
  set_vl(3);

  VEC_VLD_VREG_S32(0, 0x00000000, 0x00000001, 0x00000003);
  VEC_VLD_VREG_S32(1, 0x00000000, 0x00000001, 0x00000007);

  asm volatile ("vmulh v2, v0, v1");
  VEC_CMP_S32(2, 0x00000000, 0x00000000, 0x00000000);
}

TEST_CASE(test2) {
  set_vregmax(2);
  set_vtype(0, V_INT32);
  set_vtype(1, V_INT32);
  set_vtype(2, V_INT32);
  set_vl(2);

  VEC_VLD_VREG_S32(0, 0x00000000, 0x80000000);
  VEC_VLD_VREG_S32(1, 0xffff8000, 0x00000000);

  asm volatile ("vmulh v2, v0, v1");
  VEC_CMP_S32(2, 0x00000000, 0x00000000);
}

TEST_CASE(test3) {
  set_vregmax(2);
  set_vtype(0, V_INT32);
  set_vtype(1, V_INT32);
  set_vtype(2, V_INT32);
  set_vl(2);

  VEC_VLD_VREG_S32(0, 0xaaaaaaab, 0x0002fe7d);
  VEC_VLD_VREG_S32(1, 0x0002fe7d, 0xaaaaaaab);

  asm volatile ("vmulh v2, v0, v1");
  VEC_CMP_S32(2, 0xffff0081, 0xffff0081);
}

TEST_CASE(test4) {
  set_vregmax(2);
  set_vtype(0, V_INT32);
  set_vtype(1, V_INT32);
  set_vtype(2, V_INT32);
  set_vl(1);

  VEC_VLD_VREG_S32(0, 0xff000000);
  VEC_VLD_VREG_S32(1, 0xff000000);

  asm volatile ("vmulh v2, v0, v1");
  VEC_CMP_S32(2, 0x00010000);
}

TEST_CASE(test5) {
  set_vregmax(2);
  set_vtype(0, V_INT32);
  set_vtype(1, V_INT32);
  set_vtype(2, V_INT32);
  set_vl(3);

  VEC_VLD_VREG_S32(0, 0xffffffff, 0xffffffff, 0x00000001);
  VEC_VLD_VREG_S32(1, 0xffffffff, 0x00000001, 0xffffffff);

  asm volatile ("vmulh v2, v0, v1");
  VEC_CMP_S32(2, 0x00000000, 0xffffffff, 0xffffffff);
}

TEST_CASE(test6) {
  set_vregmax(2);
  set_vtype(0, V_INT32);
  set_vtype(1, V_INT32);
  set_vtype(2, V_INT32);
  set_vl(3);

  VEC_VLD_VREG_S32(0, 13 << 20, 14 << 20, 15 << 20);
  VEC_VLD_VREG_S32(1, 11 << 20, 11 << 20, 11 << 20);

  asm volatile ("vmulh v1, v0, v1");
  VEC_CMP_S32(1, 36608, 39424, 42240);
}

TEST_CASE(test7) {
  set_vregmax(2);
  set_vtype(0, V_INT16);
  set_vtype(1, V_INT16);
  set_vtype(2, V_INT16);
  set_vl(3);

  VEC_VLD_VREG_S16(0, 0xffff, 0xffff, 0x0001);
  VEC_VLD_VREG_S16(1, 0xffff, 0x0001, 0xffff);

  asm volatile ("vmulh v2, v0, v1");
  VEC_CMP_S16(2, 0x0000, 0xffff, 0xffff);
}

TEST_CASE(test8) {
  set_vregmax(3);
  set_vtype(0, V_INT32);
  set_vtype(1, V_INT32);
  set_vtype(2, V_INT32);
  set_vtype(3, V_INT32);
  set_vl(3);

  VEC_VLD_VREG_S32(1, 1, 0, 1);
  VEC_VLD_VREG_S32(2, 13 << 20, 14 << 20, 15 << 20);
  VEC_VLD_VREG_S32(3, 11 << 20, 11 << 20, 11 << 20);

  asm volatile ("vmulh v0, v2, v3, v1.t");
  VEC_CMP_S32(0, 36608, 0, 42240);
}

TEST_CASE(test9) {
  set_vregmax(3);
  set_vtype(0, V_INT32);
  set_vtype(1, V_INT32);
  set_vtype(2, V_INT32);
  set_vtype(3, V_INT32);
  set_vl(3);

  VEC_VLD_VREG_S32(1, 1, 0, 1);
  VEC_VLD_VREG_S32(2, 13 << 20, 14 << 20, 15 << 20);
  VEC_VLD_VREG_S32(3, 11 << 20, 11 << 20, 11 << 20);

  asm volatile ("vmulh v0, v2, v3, v1.f");
  VEC_CMP_S32(0, 0, 39424, 0);
}

/* mulhu */

TEST_CASE(test10) {
  set_vregmax(2);
  set_vtype(0, V_UINT32);
  set_vtype(1, V_UINT32);
  set_vtype(2, V_UINT32);
  set_vl(3);

  VEC_VLD_VREG_U32(0, 0x00000000, 0x00000001, 0x00000003);
  VEC_VLD_VREG_U32(1, 0x00000000, 0x00000001, 0x00000007);

  asm volatile ("vmulh v2, v0, v1");
  VEC_CMP_U32(2, 0x00000000, 0x00000000, 0x00000000);
}

TEST_CASE(test11) {
  set_vregmax(2);
  set_vtype(0, V_UINT32);
  set_vtype(1, V_UINT32);
  set_vtype(2, V_UINT32);
  set_vl(2);

  VEC_VLD_VREG_U32(0, 0x00000000, 0x80000000);
  VEC_VLD_VREG_U32(1, 0xffff8000, 0x00000000);

  asm volatile ("vmulh v2, v0, v1");
  VEC_CMP_U32(2, 0x00000000, 0x00000000);
}

TEST_CASE(test12) {
  set_vregmax(2);
  set_vtype(0, V_UINT32);
  set_vtype(1, V_UINT32);
  set_vtype(2, V_UINT32);
  set_vl(2);

  VEC_VLD_VREG_U32(0, 0xaaaaaaab, 0x0002fe7d);
  VEC_VLD_VREG_U32(1, 0x0002fe7d, 0xaaaaaaab);

  asm volatile ("vmulh v2, v0, v1");
  VEC_CMP_U32(2, 0x0001fefe, 0x0001fefe);
}

TEST_CASE(test13) {
  set_vregmax(2);
  set_vtype(0, V_UINT32);
  set_vtype(1, V_UINT32);
  set_vtype(2, V_UINT32);
  set_vl(1);

  VEC_VLD_VREG_U32(0, 0xff000000);
  VEC_VLD_VREG_U32(1, 0xff000000);

  asm volatile ("vmulh v2, v0, v1");
  VEC_CMP_U32(2, 0xfe010000);
}

TEST_CASE(test14) {
  set_vregmax(2);
  set_vtype(0, V_UINT32);
  set_vtype(1, V_UINT32);
  set_vtype(2, V_UINT32);
  set_vl(3);

  VEC_VLD_VREG_U32(0, 0xffffffff, 0xffffffff, 0x00000001);
  VEC_VLD_VREG_U32(1, 0xffffffff, 0x00000001, 0xffffffff);

  asm volatile ("vmulh v2, v0, v1");
  VEC_CMP_U32(2, 0xfffffffe, 0x00000000, 0x00000000);
}

TEST_CASE(test15) {
  set_vregmax(2);
  set_vtype(0, V_UINT32);
  set_vtype(1, V_UINT32);
  set_vtype(2, V_UINT32);
  set_vl(3);

  VEC_VLD_VREG_U32(0, 13 << 20, 14 << 20, 15 << 20);
  VEC_VLD_VREG_U32(1, 11 << 20, 11 << 20, 11 << 20);

  asm volatile ("vmulh v1, v0, v1");
  VEC_CMP_U32(1, 36608, 39424, 42240);
}

TEST_CASE(test16) {
  set_vregmax(2);
  set_vtype(0, V_UINT16);
  set_vtype(1, V_UINT16);
  set_vtype(2, V_UINT16);
  set_vl(3);

  VEC_VLD_VREG_U16(0, 0xffff, 0xffff, 0x0001);
  VEC_VLD_VREG_U16(1, 0xffff, 0x0001, 0xffff);

  asm volatile ("vmulh v2, v0, v1");
  VEC_CMP_U16(2, 0xfffe, 0x0000, 0x0000);
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

  return run_all_tests();
}
