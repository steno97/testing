#include "vector_macros.h"
#include <stdio.h>

TEST_CASE(test1) {
  set_vregmax(3);
  set_vtype(0, V_UINT32);
  set_vtype(2, V_UINT32);
  set_vtype(3, V_UINT32);
  set_vl(4);

  VEC_VLD_VREG_U32(0, 0, 1, 3, 7);
  VEC_VLD_VREG_U32(2, 0, 1, 7, 3);

  asm volatile ("vmerge v3, v0, v2");
  VEC_CMP_U32(3, 0, 1, 7, 3);
}

TEST_CASE(test2) {
  set_vregmax(3);
  set_vtype(0, V_UINT32);
  set_vtype(1, V_UINT16);
  set_vtype(2, V_UINT32);
  set_vtype(3, V_UINT32);
  set_vl(4);

  VEC_VLD_VREG_U32(0, 0, 1, 3, 7);
  VEC_VLD_VREG_U32(2, 0, 1, 7, 3);
  VEC_VLD_VREG_U16(1, 1, 0, 1, 0);

  asm volatile ("vmerge v3, v0, v2, v1.t");
  VEC_CMP_U32(3, 0, 1, 7, 7);
}

TEST_CASE(test3) {
  set_vregmax(3);
  set_vtype(0, V_UINT16);
  set_vtype(1, V_UINT8);
  set_vtype(2, V_UINT16);
  set_vtype(3, V_UINT16);
  set_vl(4);

  VEC_VLD_VREG_U16(0, 0, 1, 3, 7);
  VEC_VLD_VREG_U16(2, 0, 1, 7, 3);
  VEC_VLD_VREG_U8(1, 1, 0, 1, 0);

  asm volatile ("vmerge v3, v0, v2, v1.f");
  VEC_CMP_U16(3, 0, 1, 3, 3);
}

TEST_CASE(test4) {
  set_vregmax(3);
  set_vtype(0, V_FP32);
  set_vtype(1, V_UINT16);
  set_vtype(2, V_FP32);
  set_vtype(3, V_FP32);
  set_vl(3);

  VEC_VLD_VREG_F32(0, _f(2.5).i, _f(-1235.1).i, _f(3.14159265).i);
  VEC_VLD_VREG_U16(1, 1, 0, 1);
  VEC_VLD_VREG_F32(2, _f(1.0).i,     _f(1.1).i, _f(0.00000001).i);

  asm volatile ("vmerge v3, v0, v2, v1.t");
  VEC_CMP_F32(3, _f(1.0).i, _f(-1235.1).i, _f(0.00000001).i);
}

TEST_CASE(test5) {
  set_vregmax(3);
  set_vtype(0, V_FP64);
  set_vtype(1, V_UINT32);
  set_vtype(2, V_FP64);
  set_vtype(3, V_FP64);
  set_vl(3);

  VEC_VLD_VREG_F64(0, _d(2.5).i, _d(-1235.1).i, _d(3.14159265).i);
  VEC_VLD_VREG_U32(1, 0, 1, 0);
  VEC_VLD_VREG_F64(2, _d(1.0).i,     _d(1.1).i, _d(0.00000001).i);

  asm volatile ("vmerge v3, v0, v2, v1.f");
  VEC_CMP_F64(3, _d(1.0).i, _d(-1235.1).i, _d(0.00000001).i);
}

int main(void) {
  DECLARE_TEST(test1);
  DECLARE_TEST(test2);
  DECLARE_TEST(test3);
#ifdef __FLOAT_SUPPORT__
  DECLARE_TEST(test4);
  DECLARE_TEST(test5);
#endif

  return run_all_tests();
}
