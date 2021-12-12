#include "vector_macros.h"
#include <stdio.h>

TEST_CASE(test1) {
  set_vregmax(3);
  set_vtype(0, V_UINT32);
  set_vtype(1, V_UINT32);
  set_vtype(2, V_UINT32);
  set_vtype(3, V_UINT32);
  set_vl(3);

  VEC_VLD_VREG_U32(0, 0x00000000, 0x00000001, 0x00000003);
  VEC_VLD_VREG_U32(1, 0x00000000, 0x00000001, 0x00000007);
  VEC_VLD_VREG_U32(2, 0x00000001, 0x00000001, 0x00000001);

  asm volatile ("vnmsub v3, v0, v1, v2");
  VEC_CMP_U32(3, 0x00000001, 0x00000000, 0xffffffec);
}

TEST_CASE(test2) {
  set_vregmax(3);
  set_vtype(0, V_UINT32);
  set_vtype(1, V_UINT32);
  set_vtype(2, V_UINT32);
  set_vtype(3, V_UINT32);
  set_vl(3);

  VEC_VLD_VREG_U32(0, 0x00000000, 0x80000000, 0x80000000);
  VEC_VLD_VREG_U32(1, 0xffff8000, 0x00000000, 0xffff8000);
  VEC_VLD_VREG_U32(2, 0xffffffff, 0xffffffff, 0xffffffff);

  asm volatile ("vnmsub v3, v0, v1, v2");
  VEC_CMP_U32(3, 0xffffffff, 0xffffffff, 0xffffffff);
}

TEST_CASE(test3) {
  set_vregmax(3);
  set_vtype(0, V_UINT32);
  set_vtype(1, V_UINT32);
  set_vtype(2, V_UINT32);
  set_vl(4);

  VEC_VLD_VREG_U32(0, 0x00007e00, 0x00007fc0, 0xaaaaaaab, 0x0002fe7d);
  VEC_VLD_VREG_U32(1, 0xb6db6db7, 0xb6db6db7, 0x0002fe7d, 0xaaaaaaab);
  VEC_VLD_VREG_U32(2, 0x00001200, 0x00001240, 0x0000ff7f, 0x0000ff7f);

  asm volatile ("vnmsub v2, v0, v1, v2");
  VEC_CMP_U32(2, 0x00000000, 0x00000000, 0x00000000, 0x00000000);
}

TEST_CASE(test4) {
  set_vregmax(3);
  set_vtype(0, V_UINT32);
  set_vtype(1, V_UINT32);
  set_vtype(2, V_UINT32);
  set_vl(4);

  VEC_VLD_VREG_U32(0, 0x00000000, 0x00000001, 0xffffffff, 0xffffffff);
  VEC_VLD_VREG_U32(1, 0xff000000, 0xffffffff, 0xffffffff, 0x00000001);
  VEC_VLD_VREG_U32(2, 0xffffffff, 0x00000001, 0xffffffff, 0x00000000);

  asm volatile ("vnmsub v2, v0, v1, v2");
  VEC_CMP_U32(2, 0xffffffff, 0x00000002, 0xfffffffe, 0x00000001);
}

TEST_CASE(test5) {
  set_vregmax(3);
  set_vtype(0, V_INT16);
  set_vtype(1, V_INT16);
  set_vtype(2, S_INT16);
  set_vtype(3, V_INT32);
  set_vl(3);

  VEC_VLD_VREG_S16(0, 0x0000, 0x0001, 0x0003);
  VEC_VLD_VREG_S16(1, 0x0000, 0x0001, 0x0007);
  SCA_VLD_VREG_S16(2, 0xffff);

  asm volatile ("vnmsub v3, v0, v1, v2");
  VEC_CMP_S32(3, 0xffffffff, 0xfffffffe, 0xffffffea);
}

TEST_CASE(test6) {
  set_vregmax(3);
  set_vtype(0, V_UINT16);
  set_vtype(1, V_UINT16);
  set_vtype(2, S_INT16);
  set_vtype(3, V_INT32);
  set_vl(3);

  VEC_VLD_VREG_U16(0, 0x0000, 0x8000, 0x8000);
  VEC_VLD_VREG_U16(1, 0xff80, 0x0000, 0xff80);
  SCA_VLD_VREG_S16(2, 0xffff);

  asm volatile ("vnmsub v3, v0, v1, v2");
  VEC_CMP_U32(3, 0xffffffff, 0xffffffff, 0x803fffff);
}

TEST_CASE(test7) {
  set_vregmax(3);
  set_vtype(0, V_INT16);
  set_vtype(1, V_INT16);
  set_vtype(2, V_INT16);
  set_vtype(3, V_INT32);
  set_vl(3);

  VEC_VLD_VREG_S16(0, 0x0000, 0x8000, 0x8000);
  VEC_VLD_VREG_S16(1, 0xff80, 0x0000, 0xff80);
  VEC_VLD_VREG_S16(2, 0x0000, 0x8000, 0x8000);

  asm volatile ("vnmsub v3, v0, v1, v2");
  VEC_CMP_S32(3, 0x00000000, 0xffff8000, 0xffbf8000);
}

TEST_CASE(test8) {
  set_vregmax(3);
  set_vtype(0, V_UINT8);
  set_vtype(1, V_UINT8);
  set_vtype(2, V_UINT16);
  set_vtype(3, V_UINT16);
  set_vl(3);

  VEC_VLD_VREG_U8(0, 0x00,     0x80,   0x80);
  VEC_VLD_VREG_U8(1, 0xf8,     0x00,   0xf8);
  VEC_VLD_VREG_U16(2, 0xfff8, 0x0000, 0xffff);

  asm volatile ("vnmsub v3, v0, v1, v2");
  VEC_CMP_U16(3, 0xfff8, 0x0000, 0x83ff);
}

TEST_CASE(test9) {
  set_vregmax(3);
  set_vtype(0, V_UINT8);
  set_vtype(1, V_UINT8);
  set_vtype(2, V_UINT8);
  set_vtype(3, V_UINT8);
  set_vl(3);

  VEC_VLD_VREG_U8(0, 0x00, 0x80, 0x80);
  VEC_VLD_VREG_U8(1, 0xf8, 0x00, 0xf8);
  VEC_VLD_VREG_U8(2, 0xf8, 0x00, 0xff);

  asm volatile ("vnmsub v3, v0, v1, v2");
  VEC_CMP_S8(3, 0xf8, 0x00, 0xff);
}

TEST_CASE(test10) {
  set_vregmax(2);
  set_vtype(0, V_INT32);
  set_vtype(1, V_INT32);
  set_vtype(2, V_INT32);
  set_vl(1);

  VEC_VLD_VREG_S32(0, 13);
  VEC_VLD_VREG_S32(1, 11);
  VEC_VLD_VREG_S32(2, 43);

  asm volatile ("vnmsub v0, v0, v1, v2");
  VEC_CMP_U32(0, -100);
}

TEST_CASE(test11) {
  set_vregmax(2);
  set_vtype(0, V_UINT32);
  set_vtype(1, V_UINT32);
  set_vtype(2, V_UINT32);
  set_vl(1);

  VEC_VLD_VREG_S32(0, 14);
  VEC_VLD_VREG_S32(1, 11);
  VEC_VLD_VREG_S32(2, -1);

  asm volatile ("vnmsub v1, v0, v1, v2");
  VEC_CMP_S32(1, -155);
}

TEST_CASE(test12) {
  set_vregmax(1);
  set_vtype(0, V_UINT32);
  set_vl(1);

  VEC_VLD_VREG_S32(0, 13);

  asm volatile ("vnmsub v0, v0, v0, v0");
  VEC_CMP_S32(0, -156);
}

TEST_CASE(test13) {
  set_vregmax(4);
  set_vtype(0, V_UINT32);
  set_vtype(1, V_UINT16);
  set_vtype(2, V_UINT32);
  set_vtype(3, V_UINT32);
  set_vtype(4, S_UINT32);
  set_vl(3);

  VEC_VLD_VREG_U16(1, 0, 1, 0);
  VEC_VLD_VREG_U32(2, 0x00000000, 0x00000001, 0x00000003);
  VEC_VLD_VREG_U32(3, 0x00000000, 0x00000001, 0x00000007);
  SCA_VLD_VREG_U32(4, 0x10101010);

  asm volatile ("vnmsub v0, v2, v3, v4, v1.t");
  VEC_CMP_U32(0, 0x00000000, 0x1010100f, 0x00000000);
}

TEST_CASE(test14) {
  set_vregmax(4);
  set_vtype(0, V_UINT32);
  set_vtype(1, V_UINT16);
  set_vtype(2, V_UINT32);
  set_vtype(3, V_UINT32);
  set_vtype(4, S_UINT32);
  set_vl(3);

  VEC_VLD_VREG_U16(1, 0, 1, 0);
  VEC_VLD_VREG_U32(2, 0x00000000, 0x00000001, 0x00000003);
  VEC_VLD_VREG_U32(3, 0x00000000, 0x00000001, 0x00000007);
  SCA_VLD_VREG_U32(4, 0x10101010);

  asm volatile ("vnmsub v0, v2, v3, v4, v1.f");
  VEC_CMP_U32(0, 0x10101010, 0x00000000, 0x10100ffb);
}

/* Floating point tests */

TEST_CASE(test15) {
  set_vregmax(3);
  set_vtype(0, V_FP64);
  set_vtype(1, V_FP64);
  set_vtype(2, V_FP64);
  set_vtype(3, V_FP64);
  set_vl(3);

  VEC_VLD_VREG_F64(0, _d(1.0).i,    _d(-1.0).i,  _d(2.0).i);
  VEC_VLD_VREG_F64(1, _d(2.5).i, _d(-1235.1).i, _d(-5.0).i);
  VEC_VLD_VREG_F64(2, _d(1.0).i,     _d(1.1).i, _d(-2.0).i);

  asm volatile ("vnmsub v3, v0, v1, v2");
  VEC_CMP_F64(3, _d(-1.5).i, _d(-(double)(-1.0) * (double)(-1235.1) + (double)(1.1)).i, _d(8.0).i);
}

TEST_CASE(test16) {
  set_vregmax(3);
  set_vtype(0, V_FP32);
  set_vtype(1, V_FP32);
  set_vtype(2, V_FP32);
  set_vtype(3, V_FP32);
  set_vl(3);

  VEC_VLD_VREG_F32(0, _f(1.0).i,    _f(-1.0).i,  _f(2.0).i);
  VEC_VLD_VREG_F32(1, _f(2.5).i, _f(-1235.1).i, _f(-5.0).i);
  VEC_VLD_VREG_F32(2, _f(1.0).i,     _f(1.1).i, _f(-2.0).i);

  asm volatile ("vnmsub v3, v0, v1, v2");
  VEC_CMP_F32(3, _f(-1.5).i, _f(-1234).i, _f(8.0).i);
}

TEST_CASE(test17) {
  set_vregmax(3);
  set_vtype(0, V_FP16);
  set_vtype(1, V_FP16);
  set_vtype(2, V_FP16);
  set_vtype(3, V_FP16);
  set_vl(3);

  VEC_VLD_VREG_F16(0, _h(1.0).i,    _h(-1.0).i,  _h(2.0).i);
  VEC_VLD_VREG_F16(1, _h(2.5).i, _h(-1235.1).i, _h(-5.0).i);
  VEC_VLD_VREG_F16(2, _h(1.0).i,     _h(1.1).i, _h(-2.0).i);

  asm volatile ("vnmsub v3, v0, v1, v2");
  VEC_CMP_F16(3, _h(-1.5).i, _h(-1234).i, _h(8.0).i);
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
#ifdef __FLOAT_SUPPORT__
  DECLARE_TEST(test15);
  DECLARE_TEST(test16);
  DECLARE_TEST(test17);
#endif

  return run_all_tests();
}
