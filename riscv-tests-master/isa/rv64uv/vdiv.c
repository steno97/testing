#include "vector_macros.h"
#include <stdio.h>

/* Floating point tests */

TEST_CASE(test1) {
  set_vregmax(2);
  set_vtype(0, V_FP64);
  set_vtype(1, V_FP64);
  set_vtype(2, V_FP64);
  set_vl(3);

  VEC_VLD_VREG_F64(0, _d(3.14159265).i,  _d(-1234).i, _d(3.14159265).i);
  VEC_VLD_VREG_F64(1, _d(2.71828182).i, _d(1235.1).i,        _d(1.0).i);

  asm volatile ("vdiv v2, v0, v1");
  VEC_CMP_F64(2, _d(1.1557273520668288).i, _d(-0.9991093838555584).i, _d(3.14159265).i);
}

TEST_CASE(test2) {
  set_vregmax(2);
  set_vtype(0, V_FP64);
  set_vtype(1, V_UINT32);
  set_vtype(2, V_FP64);
  set_vl(3);

  VEC_VLD_VREG_F64(0, _d(3.14159265).i,  _d(-1234).i, _d(3.14159265).i);
  VEC_VLD_VREG_F64(2, _d(2.71828182).i, _d(1235.1).i,        _d(1.0).i);
  VEC_VLD_VREG_U32(1, 1, 1, 0);

  asm volatile ("vdiv v2, v0, v2, v1.t");
  VEC_CMP_F64(2, _d(1.1557273520668288).i, _d(-0.9991093838555584).i, 0);
}

TEST_CASE(test3) {
  set_vregmax(2);
  set_vtype(0, V_FP64);
  set_vtype(1, V_UINT32);
  set_vtype(2, V_FP64);
  set_vl(3);

  VEC_VLD_VREG_F64(0, _d(3.14159265).i,  _d(-1234).i, _d(3.14159265).i);
  VEC_VLD_VREG_F64(2, _d(2.71828182).i, _d(1235.1).i,        _d(1.0).i);
  VEC_VLD_VREG_U32(1, 1, 1, 0);

  asm volatile ("vdiv v2, v0, v2, v1.f");
  VEC_CMP_F64(2, 0, 0, _d(3.14159265).i);
}

TEST_CASE(test4) {
  set_vregmax(2);
  set_vtype(0, V_FP32);
  set_vtype(1, V_FP32);
  set_vtype(2, V_FP32);
  set_vl(3);

  VEC_VLD_VREG_F32(0, _f(3.14159265).i,  _f(-1234).i, _f(3.14159265).i);
  VEC_VLD_VREG_F32(1, _f(2.71828182).i, _f(1235.1).i,        _f(1.0).i);

  asm volatile ("vdiv v2, v0, v1");
  VEC_CMP_F32(2, _f(1.1557273520668288).i, _f(-0.9991093838555584).i, _f(3.14159265).i);
}

TEST_CASE(test5) {
  set_vregmax(2);
  set_vtype(0, V_FP32);
  set_vtype(1, V_UINT16);
  set_vtype(2, V_FP32);
  set_vl(3);

  VEC_VLD_VREG_F32(0, _f(3.14159265).i,  _f(-1234).i, _f(3.14159265).i);
  VEC_VLD_VREG_F32(2, _f(2.71828182).i, _f(1235.1).i,        _f(1.0).i);
  VEC_VLD_VREG_U16(1, 1, 1, 0);

  asm volatile ("vdiv v2, v0, v2, v1.t");
  VEC_CMP_F32(2, _f(1.1557273520668288).i, _f(-0.9991093838555584).i, 0);
}

TEST_CASE(test6) {
  set_vregmax(2);
  set_vtype(0, V_FP32);
  set_vtype(1, V_UINT16);
  set_vtype(2, V_FP32);
  set_vl(3);

  VEC_VLD_VREG_F32(0, _f(3.14159265).i,  _f(-1234).i, _f(3.14159265).i);
  VEC_VLD_VREG_F32(2, _f(2.71828182).i, _f(1235.1).i,        _f(1.0).i);
  VEC_VLD_VREG_U16(1, 1, 1, 0);

  asm volatile ("vdiv v2, v0, v2, v1.f");
  VEC_CMP_F32(2, 0, 0, _f(3.14159265).i);
}

TEST_CASE(test7) {
  set_vregmax(2);
  set_vtype(0, V_FP16);
  set_vtype(1, V_FP16);
  set_vtype(2, V_FP16);
  set_vl(3);

  VEC_VLD_VREG_F16(0, _h(3.14159265).i,  _h(-1234).i, _h(3.14159265).i);
  VEC_VLD_VREG_F16(1, _h(2.71828182).i, _h(1235.1).i,        _h(1.0).i);

  asm volatile ("vdiv v2, v0, v1");
  VEC_CMP_F16(2, _h(1.1557273520668288).i, _h(-0.9991093838555584).i, _h(3.14159265).i);
}

TEST_CASE(test8) {
  set_vregmax(2);
  set_vtype(0, V_FP16);
  set_vtype(1, V_UINT8);
  set_vtype(2, V_FP16);
  set_vl(3);

  VEC_VLD_VREG_F16(0, _h(3.14159265).i,  _h(-1234).i, _h(3.14159265).i);
  VEC_VLD_VREG_F16(2, _h(2.71828182).i, _h(1235.1).i,        _h(1.0).i);
  VEC_VLD_VREG_U8(1, 1, 1, 0);

  asm volatile ("vdiv v2, v0, v2, v1.t");
  VEC_CMP_F16(2, _h(1.1557273520668288).i, _h(-0.9991093838555584).i, 0);
}

TEST_CASE(test9) {
  set_vregmax(2);
  set_vtype(0, V_FP16);
  set_vtype(1, V_UINT8);
  set_vtype(2, V_FP16);
  set_vl(3);

  VEC_VLD_VREG_F16(0, _h(3.14159265).i,  _h(-1234).i, _h(3.14159265).i);
  VEC_VLD_VREG_F16(2, _h(2.71828182).i, _h(1235.1).i,        _h(1.0).i);
  VEC_VLD_VREG_U8(1, 1, 1, 0);

  asm volatile ("vdiv v2, v0, v2, v1.f");
  VEC_CMP_F16(2, 0, 0, _h(3.14159265).i);
}

int main(void) {
#ifdef __FLOAT_SUPPORT__
  DECLARE_TEST(test1);
  DECLARE_TEST(test2);
  DECLARE_TEST(test3);
  DECLARE_TEST(test4);
  DECLARE_TEST(test5);
  DECLARE_TEST(test6);
  DECLARE_TEST(test7);
  DECLARE_TEST(test8);
  DECLARE_TEST(test9);
#endif

  return run_all_tests();
}
