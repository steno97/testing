#include "vector_macros.h"
#include <stdio.h>

TEST_CASE(test1) {
  set_vregmax(1);
  set_vtype(0, V_INT32);
  set_vtype(1, V_INT32);
  set_vl(3);

  VEC_VLD_VREG_S32(0, 0x00000000, 0x00000001, 0x00000003);

  asm volatile ("vaddi v1, 7(v0)");
  VEC_CMP_U32(1, 0x00000007, 0x00000008, 0x0000000a);
}

TEST_CASE(test2) {
  set_vregmax(1);
  set_vtype(0, V_UINT64);
  set_vtype(1, V_UINT64);
  set_vl(2);

  VEC_VLD_VREG_U64(0, 0x0000000000000000, 0x8000000000000000);

  asm volatile ("vaddi v1, -128(v0)");
  VEC_CMP_U64(1, 0xffffffffffffff80, 0x7fffffffffffff80);
}

TEST_CASE(test3) {
  set_vregmax(1);
  set_vtype(0, V_INT32);
  set_vtype(1, V_INT32);
  set_vl(2);

  VEC_VLD_VREG_S32(0, 0x00000000, 0x7fffffff);

  asm volatile ("vaddi v1, 127(v0)");
  VEC_CMP_U32(1, 0x0000007f, 0x8000007e);
}

TEST_CASE(test4) {
  set_vregmax(1);
  set_vtype(0, V_INT32);
  set_vtype(1, V_INT32);
  set_vl(2);

  VEC_VLD_VREG_S32(0, 0x80000000, 0x7fffffff);

  asm volatile ("vaddi v1, 0(v0)");
  VEC_CMP_U32(1, 0x80000000, 0x7fffffff);
}

TEST_CASE(test5) {
  set_vregmax(1);
  set_vtype(0, V_INT32);
  set_vtype(1, V_INT32);
  set_vl(2);

  VEC_VLD_VREG_S32(0, 0x00000000, 0xffffffff);

  asm volatile ("vaddi v1, -1(v0)");
  VEC_CMP_U32(1, 0xffffffff, 0xfffffffe);
}

TEST_CASE(test6) {
  set_vregmax(1);
  set_vtype(0, V_INT32);
  set_vtype(1, V_INT32);
  set_vl(1);

  VEC_VLD_VREG_S32(0, 0xffffffff);

  asm volatile ("vaddi v1, 1(v0)");
  VEC_CMP_U32(1, 0x00000000);
}

TEST_CASE(test7) {
  set_vregmax(1);
  set_vtype(0, V_INT32);
  set_vl(3);

  VEC_VLD_VREG_S32(0, 0x00000000, 0x00000001, 0x00000003);

  asm volatile ("vaddi v0, 7(v0)");
  VEC_CMP_S32(0, 0x00000007, 0x00000008, 0x0000000a);
}

TEST_CASE(test8) {
  set_vregmax(3);
  set_vtype(1, V_UINT32);
  set_vtype(2, V_INT64);
  set_vtype(3, V_INT64);
  set_vl(3);

  VEC_VLD_VREG_U32(1, 1, 0, 1);
  VEC_VLD_VREG_S64(2, 0x0000000000000000, 0x0000000000000001, 0x0000000000000003);

  asm volatile ("vaddi v3, 7(v2), v1.t");
  VEC_CMP_S64(3, 0x0000000000000007, 0x0000000000000000, 0x000000000000000a);
}

TEST_CASE(test9) {
  set_vregmax(3);
  set_vtype(1, V_UINT32);
  set_vtype(2, V_INT64);
  set_vtype(3, V_INT64);
  set_vl(3);

  VEC_VLD_VREG_U32(1, 1, 0, 1);
  VEC_VLD_VREG_S64(2, 0x0000000000000000, 0x0000000000000001, 0x0000000000000003);

  asm volatile ("vaddi v3, 7(v2), v1.f");
  VEC_CMP_S64(3, 0x0000000000000000, 0x0000000000000008, 0x0000000000000000);
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

  return run_all_tests();
}
