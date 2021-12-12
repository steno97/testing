#include "vector_macros.h"
#include <stdio.h>

/* Unsigned comparison */

TEST_CASE(test1) {
  set_vregmax(2);
  set_vtype(0, V_UINT32);
  set_vtype(1, V_UINT32);
  set_vtype(2, V_UINT32);
  set_vl(4);

  VEC_VLD_VREG_U32(0, 0x00000000, 0x00000001, 0x00000003, 0x00000007);
  VEC_VLD_VREG_U32(1, 0x00000000, 0x00000001, 0x00000007, 0x00000003);

  asm volatile ("vslt v2, v0, v1");
  VEC_CMP_U32(2, 0, 0, 1, 0);
}

TEST_CASE(test2) {
  set_vregmax(2);
  set_vtype(0, V_UINT8);
  set_vtype(1, V_UINT8);
  set_vtype(2, V_UINT16);
  set_vl(4);

  VEC_VLD_VREG_U8(0, 0x00, 0x01, 0x03, 0x07);
  VEC_VLD_VREG_U8(1, 0x00, 0x01, 0x07, 0x03);

  asm volatile ("vslt v2, v0, v1");
  VEC_CMP_U16(2, 0, 0, 1, 0);
}

TEST_CASE(test3) {
  set_vregmax(2);
  set_vtype(0, V_UINT32);
  set_vtype(1, V_UINT32);
  set_vtype(2, V_UINT32);
  set_vl(3);

  VEC_VLD_VREG_U32(0, 0x00000000, 0x80000000, 0x80000000);
  VEC_VLD_VREG_U32(1, 0xffff8000, 0x00000000, 0xffff8000);

  asm volatile ("vslt v2, v0, v1");
  VEC_CMP_U32(2, 1, 0, 1);
}

TEST_CASE(test4) {
  set_vregmax(2);
  set_vtype(0, V_UINT32);
  set_vtype(1, V_UINT32);
  set_vtype(2, V_UINT32);
  set_vl(3);

  VEC_VLD_VREG_U32(0, 0x00000000, 0x7fffffff, 0x7fffffff);
  VEC_VLD_VREG_U32(1, 0x00007fff, 0x00000000, 0x00007fff);

  asm volatile ("vslt v2, v0, v1");
  VEC_CMP_U32(2, 1, 0, 0);
}

TEST_CASE(test5) {
  set_vregmax(2);
  set_vtype(0, V_UINT32);
  set_vtype(1, V_UINT32);
  set_vtype(2, V_UINT32);
  set_vl(2);

  VEC_VLD_VREG_U32(0, 0x80000000, 0x7fffffff);
  VEC_VLD_VREG_U32(1, 0x00007fff, 0xffff8000);

  asm volatile ("vslt v2, v0, v1");
  VEC_CMP_U32(2, 0, 1);
}

TEST_CASE(test6) {
  set_vregmax(2);
  set_vtype(0, V_UINT32);
  set_vtype(1, V_UINT32);
  set_vtype(2, V_UINT32);
  set_vl(3);

  VEC_VLD_VREG_U32(0, 0x00000000, 0xffffffff, 0xffffffff);
  VEC_VLD_VREG_U32(1, 0xffffffff, 0x00000001, 0xffffffff);

  asm volatile ("vslt v2, v0, v1");
  VEC_CMP_U32(2, 1, 0, 0);
}

TEST_CASE(test7) {
  set_vregmax(2);
  set_vtype(0, V_UINT64);
  set_vtype(1, V_UINT64);
  set_vtype(2, V_UINT64);
  set_vl(3);

  VEC_VLD_VREG_U64(0, 0x0000000000000000, 0xffffffffffffffff, 0xffffffffffffffff);
  VEC_VLD_VREG_U64(1, 0xffffffffffffffff, 0x0000000000000001, 0xffffffffffffffff);

  asm volatile ("vslt v2, v0, v1");
  VEC_CMP_U64(2, 1, 0, 0);
}

TEST_CASE(test8) {
  set_vregmax(1);
  set_vtype(0, V_UINT64);
  set_vtype(1, V_UINT64);
  set_vl(1);

  VEC_VLD_VREG_U64(0, 14);
  VEC_VLD_VREG_U64(1, 13);

  asm volatile ("vslt v0, v0, v1");
  VEC_CMP_U64(0, 0);
}

TEST_CASE(test9) {
  set_vregmax(1);
  set_vtype(0, V_UINT64);
  set_vtype(1, V_UINT64);
  set_vl(1);

  VEC_VLD_VREG_U64(0, 11);
  VEC_VLD_VREG_U64(1, 13);

  asm volatile ("vslt v1, v0, v1");
  VEC_CMP_U64(1, 1);
}

TEST_CASE(test10) {
  set_vregmax(1);
  set_vtype(0, V_UINT64);
  set_vl(1);

  VEC_VLD_VREG_U64(0, 13);

  asm volatile ("vslt v0, v0, v0");
  VEC_CMP_U64(0, 0);
}

TEST_CASE(test11) {
  set_vregmax(3);
  set_vtype(0, V_UINT32);
  set_vtype(1, V_UINT16);
  set_vtype(2, V_UINT32);
  set_vtype(3, V_UINT32);
  set_vl(4);

  VEC_VLD_VREG_U16(1, 0x01, 0xf0, 0xff, 0x81);
  VEC_VLD_VREG_U32(2, 0x00000000, 0x00000001, 0x00000003, 0x00000007);
  VEC_VLD_VREG_U32(3, 0x00000000, 0x00000001, 0x00000007, 0x00000003);

  asm volatile ("vslt v0, v2, v3, v1.t");
  VEC_CMP_U32(0, 0, 0, 1, 0);
}

TEST_CASE(test12) {
  set_vregmax(3);
  set_vtype(0, V_UINT32);
  set_vtype(1, V_UINT16);
  set_vtype(2, V_UINT32);
  set_vtype(3, V_UINT32);
  set_vl(4);

  VEC_VLD_VREG_U16(1, 0x01, 0xf0, 0xff, 0x81);
  VEC_VLD_VREG_U32(2, 0x00000000, 0x00000001, 0x00000003, 0x00000007);
  VEC_VLD_VREG_U32(3, 0x00000000, 0x00000001, 0x00000007, 0x00000003);

  asm volatile ("vslt v0, v2, v3, v1.f");
  VEC_CMP_U32(0, 0, 0, 0, 0);
}

/* Signed comparison */

TEST_CASE(test13) {
  set_vregmax(2);
  set_vtype(0, V_UINT32);
  set_vtype(1, V_UINT32);
  set_vtype(2, V_INT32);
  set_vl(4);

  VEC_VLD_VREG_U32(0, 0x00000000, 0x00000001, 0x00000003, 0x00000007);
  VEC_VLD_VREG_U32(1, 0x00000000, 0x00000001, 0x00000007, 0x00000003);

  asm volatile ("vslt v2, v0, v1");
  VEC_CMP_S32(2, 0, 0, 1, 0);
}

TEST_CASE(test14) {
  set_vregmax(2);
  set_vtype(0, V_INT8);
  set_vtype(1, V_INT8);
  set_vtype(2, V_INT16);
  set_vl(4);

  VEC_VLD_VREG_S8(0, 0x00, 0x01, 0x03, 0x07);
  VEC_VLD_VREG_S8(1, 0x00, 0x01, 0x07, 0x03);

  asm volatile ("vslt v2, v0, v1");
  VEC_CMP_S16(2, 0, 0, 1, 0);
}

TEST_CASE(test15) {
  set_vregmax(2);
  set_vtype(0, V_INT32);
  set_vtype(1, V_INT32);
  set_vtype(2, V_INT32);
  set_vl(3);

  VEC_VLD_VREG_S32(0, 0x00000000, 0x80000000, 0x80000000);
  VEC_VLD_VREG_S32(1, 0xffff8000, 0x00000000, 0xffff8000);

  asm volatile ("vslt v2, v0, v1");
  VEC_CMP_S32(2, 0, 1, 1);
}

TEST_CASE(test16) {
  set_vregmax(2);
  set_vtype(0, V_INT32);
  set_vtype(1, V_INT32);
  set_vtype(2, V_INT32);
  set_vl(3);

  VEC_VLD_VREG_U32(0, 0x00000000, 0x7fffffff, 0x7fffffff);
  VEC_VLD_VREG_U32(1, 0x00007fff, 0x00000000, 0x00007fff);

  asm volatile ("vslt v2, v0, v1");
  VEC_CMP_S32(2, 1, 0, 0);
}

TEST_CASE(test17) {
  set_vregmax(2);
  set_vtype(0, V_INT32);
  set_vtype(1, V_INT32);
  set_vtype(2, V_INT32);
  set_vl(2);

  VEC_VLD_VREG_S32(0, 0x80000000, 0x7fffffff);
  VEC_VLD_VREG_S32(1, 0x00007fff, 0xffff8000);

  asm volatile ("vslt v2, v0, v1");
  VEC_CMP_S32(2, 1, 0);
}

TEST_CASE(test18) {
  set_vregmax(2);
  set_vtype(0, V_INT32);
  set_vtype(1, V_INT32);
  set_vtype(2, V_INT32);
  set_vl(3);

  VEC_VLD_VREG_S32(0, 0x00000000, 0xffffffff, 0xffffffff);
  VEC_VLD_VREG_S32(1, 0xffffffff, 0x00000001, 0xffffffff);

  asm volatile ("vslt v2, v0, v1");
  VEC_CMP_S32(2, 0, 1, 0);
}

TEST_CASE(test19) {
  set_vregmax(2);
  set_vtype(0, V_INT64);
  set_vtype(1, V_INT64);
  set_vtype(2, V_INT64);
  set_vl(3);

  VEC_VLD_VREG_S64(0, 0x0000000000000000, 0xffffffffffffffff, 0xffffffffffffffff);
  VEC_VLD_VREG_S64(1, 0xffffffffffffffff, 0x0000000000000001, 0xffffffffffffffff);

  asm volatile ("vslt v2, v0, v1");
  VEC_CMP_S64(2, 0, 1, 0);
}

TEST_CASE(test20) {
  set_vregmax(1);
  set_vtype(0, V_INT32);
  set_vtype(1, V_INT32);
  set_vl(1);

  VEC_VLD_VREG_S32(0, 14);
  VEC_VLD_VREG_S32(1, 13);

  asm volatile ("vslt v0, v0, v1");
  VEC_CMP_S32(0, 0);
}

TEST_CASE(test21) {
  set_vregmax(1);
  set_vtype(0, V_INT32);
  set_vtype(1, V_INT32);
  set_vl(1);

  VEC_VLD_VREG_S32(0, 11);
  VEC_VLD_VREG_S32(1, 13);

  asm volatile ("vslt v1, v0, v1");
  VEC_CMP_S32(1, 1);
}

TEST_CASE(test22) {
  set_vregmax(1);
  set_vtype(0, V_INT32);
  set_vl(1);

  VEC_VLD_VREG_S32(0, 13);

  asm volatile ("vslt v0, v0, v0");
  VEC_CMP_S32(0, 0);
}

TEST_CASE(test23) {
  set_vregmax(2);
  set_vtype(0, V_FP64);
  set_vtype(1, V_FP64);
  set_vtype(2, V_INT64);
  set_vl(4);

  VEC_VLD_VREG_F64(0, _d(-1.36).i, _d(-1.37).i, _d(1.36).i, _d(1.37).i);
  VEC_VLD_VREG_F64(1, _d(-1.36).i, _d(-1.36).i, _d(1.36).i, _d(1.36).i);

  asm volatile ("vslt v2, v0, v1");
  VEC_CMP_S64(2, 0, 1, 0, 0);
}

TEST_CASE(test24) {
  set_vregmax(2);
  set_vtype(0, V_FP32);
  set_vtype(1, V_FP32);
  set_vtype(2, V_INT32);
  set_vl(4);

  VEC_VLD_VREG_F32(0, _f(-1.36).i, _f(-1.37).i, _f(1.36).i, _f(1.37).i);
  VEC_VLD_VREG_F32(1, _f(-1.36).i, _f(-1.36).i, _f(1.36).i, _f(1.36).i);

  asm volatile ("vslt v2, v0, v1");
  VEC_CMP_S32(2, 0, 1, 0, 0);
}

TEST_CASE(test25) {
  set_vregmax(2);
  set_vtype(0, V_FP16);
  set_vtype(1, V_FP16);
  set_vtype(2, V_INT16);
  set_vl(4);

  VEC_VLD_VREG_F16(0, _h(-1.36).i, _h(-1.37).i, _h(1.36).i, _h(1.37).i);
  VEC_VLD_VREG_F16(1, _h(-1.36).i, _h(-1.36).i, _h(1.36).i, _h(1.36).i);

  asm volatile ("vslt v2, v0, v1");
  VEC_CMP_S16(2, 0, 1, 0, 0);
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
#ifdef __FLOAT_SUPPORT__
  DECLARE_TEST(test23);
  DECLARE_TEST(test24);
  DECLARE_TEST(test25);
#endif

  return run_all_tests();
}
