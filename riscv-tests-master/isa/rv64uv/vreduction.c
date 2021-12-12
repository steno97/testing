#include "vector_macros.h"
#include <stdio.h>

TEST_CASE(test1) {
  set_vregmax(1);
  set_vtype(0, V_UINT32);
  set_vtype(1, S_UINT32);
  set_vl(8);

  VEC_VLD_VREG_U32(0, 1, 2, 3, 4, 5, 6, 7, 8);
  VEC_VLD_VREG_U32(1, 0);

  asm volatile ("vadd v1, v0, v1");
  VEC_CMP_U32(1, 36);
}

TEST_CASE(test2) {
  set_vregmax(1);
  set_vtype(0, V_FP32);
  set_vtype(1, S_FP32);
  set_vl(8);

  VEC_VLD_VREG_F32(0, _f(1).i, _f(2).i, _f(3).i, _f(4).i, _f(5).i, _f(6).i, _f(7).i, _f(8).i);
  VEC_VLD_VREG_F32(1, _f(0).i);

  asm volatile ("vadd v1, v0, v1");
  VEC_CMP_F32(1, _f(36).i);
}

TEST_CASE(test3) {
  set_vregmax(1);
  set_vtype(0, V_UINT64);
  set_vtype(1, S_UINT64);
  set_vl(8);

  VEC_VLD_VREG_U64(0, 1, 2, 3, 4, 5, 6, 7, 8);
  VEC_VLD_VREG_U64(1, 0);

  asm volatile ("vadd v1, v0, v1");
  VEC_CMP_U64(1, 36);
}

TEST_CASE(test4) {
  set_vregmax(1);
  set_vtype(0, V_FP64);
  set_vtype(1, S_FP64);
  set_vl(8);

  VEC_VLD_VREG_F64(0, _d(1).i, _d(2).i, _d(3).i, _d(4).i, _d(5).i, _d(6).i, _d(7).i, _d(8).i);
  VEC_VLD_VREG_F64(1, _d(0).i);

  asm volatile ("vadd v1, v0, v1");
  VEC_CMP_F64(1, _d(36).i);
}

TEST_CASE(test5) {
  set_vregmax(1);
  set_vtype(0, V_UINT32);
  set_vtype(1, S_UINT32);
  set_vl(8);

  VEC_VLD_VREG_U32(0, 0x1, 0x2, 0x4, 0x8, 0x10, 0x20, 0x40, 0x80);
  VEC_VLD_VREG_U32(1, 0xFFFFFFFF);

  asm volatile ("vand v1, v0, v1");
  VEC_CMP_U32(1, 0);
}

TEST_CASE(test6) {
  set_vregmax(1);
  set_vtype(0, V_UINT32);
  set_vtype(1, S_UINT32);
  set_vl(8);

  VEC_VLD_VREG_U32(0, 0x1, 0x2, 0x4, 0x8, 0x10, 0x20, 0x40, 0x80);
  VEC_VLD_VREG_U32(1, 0);

  asm volatile ("vor v1, v0, v1");
  VEC_CMP_U32(1, 0xFF);
}

TEST_CASE(test7) {
  set_vregmax(1);
  set_vtype(0, V_UINT32);
  set_vtype(1, S_UINT32);
  set_vl(8);

  VEC_VLD_VREG_U32(0, 0x1, 0x2, 0x4, 0x8, 0x10, 0x20, 0x40, 0x80);
  VEC_VLD_VREG_U32(1, 0x0);

  asm volatile ("vxor v1, v0, v1");
  VEC_CMP_U32(1, 0xFF);
}

TEST_CASE(test8) {
  set_vregmax(1);
  set_vtype(0, V_UINT64);
  set_vtype(1, S_UINT64);
  set_vl(8);

  VEC_VLD_VREG_U64(0, 0x1, 0x2, 0x4, 0x8, 0x10, 0x20, 0x40, 0x80);
  VEC_VLD_VREG_U64(1, 0xFFFFFFFF);

  asm volatile ("vand v1, v0, v1");
  VEC_CMP_U64(1, 0);
}

TEST_CASE(test9) {
  set_vregmax(1);
  set_vtype(0, V_UINT64);
  set_vtype(1, S_UINT64);
  set_vl(8);

  VEC_VLD_VREG_U64(0, 0x1, 0x2, 0x4, 0x8, 0x10, 0x20, 0x40, 0x80);
  VEC_VLD_VREG_U64(1, 0);

  asm volatile ("vor v1, v0, v1");
  VEC_CMP_U64(1, 0xFF);
}

TEST_CASE(test10) {
  set_vregmax(1);
  set_vtype(0, V_UINT64);
  set_vtype(1, S_UINT64);
  set_vl(8);

  VEC_VLD_VREG_U64(0, 0x1, 0x2, 0x4, 0x8, 0x10, 0x20, 0x40, 0x80);
  VEC_VLD_VREG_U64(1, 0);

  asm volatile ("vxor v1, v0, v1");
  VEC_CMP_U64(1, 0xFF);
}

TEST_CASE(test11) {
  set_vregmax(2);
  set_vtype(0, V_UINT32);
  set_vtype(1, V_UINT32);
  set_vtype(2, S_UINT32);
  set_vl(8);

  VEC_VLD_VREG_U32(0, 1, 2, 3, 4, 5, 6, 7, 8);
  VEC_VLD_VREG_U32(1, 1, 2, 3, 4, 5, 6, 7, 8);
  VEC_VLD_VREG_U32(2, -64);

  asm volatile ("vmadd v2, v0, v1, v2");
  VEC_CMP_U32(2, 140);
}

TEST_CASE(test12) {
  set_vregmax(2);
  set_vtype(0, V_FP32);
  set_vtype(1, V_FP32);
  set_vtype(2, S_FP32);
  set_vl(8);

  VEC_VLD_VREG_F32(0, _f(1).i, _f(2).i, _f(3).i, _f(4).i, _f(5).i, _f(6).i, _f(7).i, _f(8).i);
  VEC_VLD_VREG_F32(1, _f(1).i, _f(2).i, _f(3).i, _f(4).i, _f(5).i, _f(6).i, _f(7).i, _f(8).i);
  VEC_VLD_VREG_F32(2, _f(-64).i);

  asm volatile ("vmadd v2, v0, v1, v2");
  VEC_CMP_F32(2, _f(140).i);
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

  return run_all_tests();
}
