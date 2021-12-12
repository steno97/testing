#include "vector_macros.h"
#include <stdio.h>

TEST_CASE(test1) {
  set_vregmax(3);
  set_vtype(0, V_FP64);
  set_vtype(3, V_FP64);
  set_vl(4);

  VEC_VLD_VREG_F64(0, _d(3.14159265).i, _d(10000).i, _d(171.0).i, _d(1.60795e-7).i);

  asm volatile ("vsqrt v3, v0");
  VEC_CMP_F64(3, _d(1.7724538498928541).i, _d(100).i, _d(13.076696830622021).i, _d(0.00040099251863345283320230749702).i);
}

TEST_CASE(test2) {
  set_vregmax(3);
  set_vtype(0, V_FP32);
  set_vtype(3, V_FP32);
  set_vl(4);

  VEC_VLD_VREG_F32(0, _f(3.14159265).i, _f(10000).i, _f(171.0).i, _f(1.60795e-7).i);

  asm volatile ("vsqrt v3, v0");
  VEC_CMP_F32(3, _f(1.7724538498928541).i, _f(100).i, _f(13.076696830622021).i, _f(0.00040099251863345283320230749702).i);
}

TEST_CASE(test3) {
  set_vregmax(3);
  set_vtype(0, V_FP16);
  set_vtype(3, V_FP16);
  set_vl(3);

  VEC_VLD_VREG_F16(0, _h(3.14159265).i, _h(10000).i, _h(171.0).i);

  asm volatile ("vsqrt v3, v0");
  VEC_CMP_F16(3, _h(1.7724538498928541).i, _h(100).i, _h(13.076696830622021).i);
}

TEST_CASE(test4) {
  set_vregmax(3);
  set_vtype(0, V_FP64);
  set_vtype(3, V_FP64);
  set_vl(1);

  VEC_VLD_VREG_F64(0, _d(-1.0).i);

  asm volatile ("vsqrt v3, v0");
  VEC_CMP_F64(3, 0x7FF8000000000000);
}

TEST_CASE(test5) {
  set_vregmax(3);
  set_vtype(0, V_FP64);
  set_vtype(1, V_UINT32);
  set_vtype(3, V_FP64);
  set_vl(4);

  VEC_VLD_VREG_F64(0, _d(3.14159265).i, _d(10000).i, _d(171.0).i, _d(1.60795e-7).i);
  VEC_VLD_VREG_U32(1, 1, 0, 1, 0);

  asm volatile ("vsqrt v3, v0, v1.t");
  VEC_CMP_F64(3, _d(1.7724538498928541).i, 0, _d(13.076696830622021).i, 0);
}

TEST_CASE(test6) {
  set_vregmax(3);
  set_vtype(0, V_FP64);
  set_vtype(1, V_UINT32);
  set_vtype(3, V_FP64);
  set_vl(4);

  VEC_VLD_VREG_F64(0, _d(3.14159265).i, _d(10000).i, _d(171.0).i, _d(1.60795e-7).i);
  VEC_VLD_VREG_U32(1, 1, 0, 1, 0);

  asm volatile ("vsqrt v3, v0, v1.f");
  VEC_CMP_F64(3, 0, _d(100).i, 0, _d(0.00040099251863345283320230749702).i);
}

int main(void) {
#ifdef __FLOAT_SUPPORT__
  DECLARE_TEST(test1);
  DECLARE_TEST(test2);
  DECLARE_TEST(test3);
  DECLARE_TEST(test4);
  DECLARE_TEST(test5);
  DECLARE_TEST(test6);
#endif

  return run_all_tests();
}
