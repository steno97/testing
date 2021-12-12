#include "vector_macros.h"
#include <stdio.h>

TEST_CASE(test1) {
  set_vregmax(2);
  set_vtype(0, V_UINT32);
  set_vtype(1, V_UINT32);
  set_vtype(2, V_UINT32);
  set_vl(3);

  VEC_VLD_VREG_U32(0, 0x00000000, 0x00000001, 0x00000003);
  VEC_VLD_VREG_U32(1, 0x00000000, 0x00000001, 0x00000007);

  asm volatile ("vmax v2, v0, v1");
  VEC_CMP_U32(2, 0x00000000, 0x00000001, 0x00000007);
}

TEST_CASE(test2) {
  set_vregmax(2);
  set_vtype(0, V_UINT32);
  set_vtype(1, V_UINT32);
  set_vtype(2, V_UINT32);
  set_vl(3);

  VEC_VLD_VREG_U32(0, 0x00000000, 0x80000000, 0x80000000);
  VEC_VLD_VREG_U32(1, 0xffff8000, 0x00000000, 0xffff8000);

  asm volatile ("vmax v2, v0, v1");
  VEC_CMP_U32(2, 0xffff8000, 0x80000000, 0xffff8000);
}

TEST_CASE(test3) {
  set_vregmax(2);
  set_vtype(0, V_UINT16);
  set_vtype(1, V_UINT16);
  set_vtype(2, V_UINT16);
  set_vl(3);

  VEC_VLD_VREG_U16(0, 0x0000, 0x8000, 0x8000);
  VEC_VLD_VREG_U16(1, 0xff80, 0x0000, 0xff80);

  asm volatile ("vmax v2, v0, v1");

  VEC_CMP_U16(2, 0xff80, 0x8000, 0xff80);
}

TEST_CASE(test4) {
  set_vregmax(2);
  set_vtype(0, V_UINT32);
  set_vtype(1, V_UINT32);
  set_vtype(2, V_UINT32);
  set_vl(3);

  VEC_VLD_VREG_U32(0, 0x00000000, 0x7fffffff, 0x7fffffff);
  VEC_VLD_VREG_U32(1, 0x00007fff, 0x00000000, 0x00007fff);

  asm volatile ("vmax v2, v0, v1");
  VEC_CMP_U32(2, 0x00007fff, 0x7fffffff, 0x7fffffff);
}

TEST_CASE(test5) {
  set_vregmax(2);
  set_vtype(0, V_UINT32);
  set_vtype(1, V_UINT32);
  set_vtype(2, V_UINT32);
  set_vl(3);

  VEC_VLD_VREG_U32(0, 0xffff8000, 0x00007fff);
  VEC_VLD_VREG_U32(1, 0x0000007f, 0xffffff80);

  asm volatile ("vmax v2, v0, v1");
  VEC_CMP_U32(2, 0xffff8000, 0xffffff80);
}

TEST_CASE(test6) {
  set_vregmax(2);
  set_vtype(0, V_UINT32);
  set_vtype(1, V_UINT32);
  set_vtype(2, V_UINT32);
  set_vl(3);

  VEC_VLD_VREG_U32(0, 0x00000000, 0xffffffff, 0xffffffff);
  VEC_VLD_VREG_U32(1, 0xffffffff, 0x00000001, 0xffffffff);

  asm volatile ("vmax v2, v0, v1");
  VEC_CMP_U32(2, 0xffffffff, 0xffffffff, 0xffffffff);
}

TEST_CASE(test7) {
  set_vregmax(1);
  set_vtype(0, V_UINT32);
  set_vtype(1, V_UINT32);
  set_vl(3);

  VEC_VLD_VREG_U32(0, 0x00000000, 0x00000001, 0x00000003);
  VEC_VLD_VREG_U32(1, 0x00000000, 0x00000001, 0x00000007);

  asm volatile ("vmax v0, v0, v1");
  VEC_CMP_U32(0, 0x00000000, 0x00000001, 0x00000007);
}

TEST_CASE(test8) {
  set_vregmax(1);
  set_vtype(0, V_UINT32);
  set_vtype(1, V_UINT32);
  set_vl(3);

  VEC_VLD_VREG_U32(0, 0x00000000, 0x00000001, 0x00000003);
  VEC_VLD_VREG_U32(1, 0x00000000, 0x00000001, 0x00000007);

  asm volatile ("vmax v1, v0, v1");
  VEC_CMP_U32(1, 0x00000000, 0x00000001, 0x00000007);
}

TEST_CASE(test9) {
  set_vregmax(1);
  set_vtype(0, V_UINT32);
  set_vl(3);

  VEC_VLD_VREG_U32(0, 0x00000000, 0x00000001, 0x00000003);

  asm volatile ("vmax v0, v0, v0");
  VEC_CMP_U32(0, 0x00000000, 0x00000001, 0x00000003);
}

TEST_CASE(test10) {
  set_vregmax(3);
  set_vtype(0, V_UINT32);
  set_vtype(1, V_UINT16);
  set_vtype(2, V_UINT32);
  set_vtype(3, V_UINT32);
  set_vl(3);

  VEC_VLD_VREG_U16(1, 0x01, 0xf0, 0xff);
  VEC_VLD_VREG_U32(2, 0x00000008, 0x00000001, 0x00000003);
  VEC_VLD_VREG_U32(3, 0x00000008, 0x00000001, 0x00000007);

  asm volatile ("vmax v0, v2, v3, v1.t");
  VEC_CMP_U32(0, 0x00000008, 0x00000000, 0x00000007);
}

TEST_CASE(test11) {
  set_vregmax(3);
  set_vtype(0, V_UINT32);
  set_vtype(1, V_UINT16);
  set_vtype(2, V_UINT32);
  set_vtype(3, V_UINT32);
  set_vl(3);

  VEC_VLD_VREG_U16(1, 0x01, 0xf0, 0xff);
  VEC_VLD_VREG_U32(2, 0x00000008, 0x00000001, 0x00000003);
  VEC_VLD_VREG_U32(3, 0x00000008, 0x00000001, 0x00000007);

  asm volatile ("vmax v0, v2, v3, v1.f");
  VEC_CMP_U32(0, 0x00000000, 0x00000001, 0x00000000);
}

TEST_CASE(test12) {
  set_vregmax(2);
  set_vtype(0, V_INT32);
  set_vtype(1, V_INT32);
  set_vtype(2, V_INT32);
  set_vl(3);

  VEC_VLD_VREG_S32(0, 0x00000000, 0x00000001, 0x00000003);
  VEC_VLD_VREG_S32(1, 0x00000000, 0x00000001, 0x00000007);

  asm volatile ("vmax v2, v0, v1");
  VEC_CMP_S32(2, 0x00000000, 0x00000001, 0x00000007);
}

TEST_CASE(test13) {
  set_vregmax(2);
  set_vtype(0, V_INT32);
  set_vtype(1, V_INT32);
  set_vtype(2, V_INT32);
  set_vl(3);

  VEC_VLD_VREG_S32(0, 0x00000000, 0x80000000, 0x80000000);
  VEC_VLD_VREG_S32(1, 0xffff8000, 0x00000000, 0xffff8000);

  asm volatile ("vmax v2, v0, v1");
  VEC_CMP_S32(2, 0x00000000, 0x00000000, 0xffff8000);
}

TEST_CASE(test14) {
  set_vregmax(2);
  set_vtype(0, V_INT16);
  set_vtype(1, V_INT16);
  set_vtype(2, V_INT16);
  set_vl(3);

  VEC_VLD_VREG_S16(0, 0x0000, 0x8000, 0x8000);
  VEC_VLD_VREG_S16(1, 0xff80, 0x0000, 0xff80);

  asm volatile ("vmax v2, v0, v1");

  VEC_CMP_S16(2, 0x0000, 0x0000, 0xff80);
}

TEST_CASE(test15) {
  set_vregmax(2);
  set_vtype(0, V_INT32);
  set_vtype(1, V_INT32);
  set_vtype(2, V_INT32);
  set_vl(3);

  VEC_VLD_VREG_S32(0, 0x00000000, 0x7fffffff, 0x7fffffff);
  VEC_VLD_VREG_S32(1, 0x00007fff, 0x00000000, 0x00007fff);

  asm volatile ("vmax v2, v0, v1");
  VEC_CMP_S32(2, 0x00007fff, 0x7fffffff, 0x7fffffff);
}

TEST_CASE(test16) {
  set_vregmax(2);
  set_vtype(0, V_INT32);
  set_vtype(1, V_INT32);
  set_vtype(2, V_INT32);
  set_vl(2);

  VEC_VLD_VREG_S32(0, 0xffff8000, 0x00007fff);
  VEC_VLD_VREG_S32(1, 0x0000007f, 0xffffff80);

  asm volatile ("vmax v2, v0, v1");
  VEC_CMP_S32(2, 0x0000007f, 0x00007fff);
}

TEST_CASE(test17) {
  set_vregmax(2);
  set_vtype(0, V_INT32);
  set_vtype(1, V_INT32);
  set_vtype(2, V_INT32);
  set_vl(3);

  VEC_VLD_VREG_S32(0, 0x00000000, 0xffffffff, 0xffffffff);
  VEC_VLD_VREG_S32(1, 0xffffffff, 0x00000001, 0xffffffff);

  asm volatile ("vmax v2, v0, v1");
  VEC_CMP_S32(2, 0x00000000, 0x00000001, 0xffffffff);
}

TEST_CASE(test18) {
  set_vregmax(2);
  set_vtype(0, V_INT64);
  set_vtype(1, V_INT64);
  set_vtype(2, V_INT64);
  set_vl(3);

  VEC_VLD_VREG_S64(0, 0x0000000000000000, 0xffffffffffffffff, 0xffffffffffffffff);
  VEC_VLD_VREG_S64(1, 0xffffffffffffffff, 0x0000000000000001, 0xffffffffffffffff);

  asm volatile ("vmax v2, v0, v1");
  VEC_CMP_S64(2, 0x0000000000000000, 0x0000000000000001, 0xffffffffffffffff);
}

TEST_CASE(test19) {
  set_vregmax(2);
  set_vtype(0, V_FP64);
  set_vtype(1, V_FP64);
  set_vtype(2, V_FP64);
  set_vl(3);

  VEC_VLD_VREG_F64(0, _d(1.234).i, _d(-1.234e10).i, _d(3.1415926e-1).i);
  VEC_VLD_VREG_F64(1, _d(4.321).i,     _d(-1e10).i, _d(2.7182818e+1).i);

  asm volatile ("vmax v2, v0, v1");
  VEC_CMP_F64(2, _d(4.321).i, _d(-1e10).i, _d(2.7182818e+1).i);
}

TEST_CASE(test20) {
  set_vregmax(3);
  set_vtype(0, V_FP32);
  set_vtype(1, V_UINT16);
  set_vtype(2, V_FP32);
  set_vtype(3, V_FP32);
  set_vl(3);

  VEC_VLD_VREG_F32(0, _f(1.234).i, _f(-1.234e10).i, _f(3.1415926e-1).i);
  VEC_VLD_VREG_F32(2, _f(4.321).i,     _f(-1e10).i, _f(2.7182818e+1).i);
  VEC_VLD_VREG_U16(1, 0, 1, 0);

  asm volatile ("vmax v3, v0, v2, v1.t");
  VEC_CMP_F32(3, 0, _f(-1e10).i, 0);
}

TEST_CASE(test21) {
  set_vregmax(3);
  set_vtype(0, V_FP32);
  set_vtype(1, V_UINT16);
  set_vtype(2, V_FP32);
  set_vtype(3, V_FP32);
  set_vl(3);

  VEC_VLD_VREG_F32(0, _f(1.234).i, _f(-1.234e10).i, _f(3.1415926e-1).i);
  VEC_VLD_VREG_F32(2, _f(4.321).i,     _f(-1e10).i, _f(2.7182818e+1).i);
  VEC_VLD_VREG_U16(1, 0, 1, 0);

  asm volatile ("vmax v3, v0, v2, v1.f");
  VEC_CMP_F32(3, _f(4.321).i, 0, _f(2.7182818e+1).i);
}

TEST_CASE(test22) {
  set_vregmax(2);
  set_vtype(0, V_FP64);
  set_vtype(1, V_FP64);
  set_vtype(2, V_FP64);
  set_vl(6);

  VEC_VLD_VREG_F64(0, _d(2.5).i, _d(-1235.1).i, _d(1.1).i, _d((0.0/0.0) /* NaN */).i, _d(3.14159265).i, _d(-1.0).i);
  VEC_VLD_VREG_F64(1, _d(1.0).i, _d(1.1).i, _d(-1235.1).i, _d(-1235.1).i, _d(0.00000001).i, _d(-2.0).i);

  asm volatile ("vmax v2, v0, v1");
  VEC_VLD_VREG_F64(1, _d(2.5).i, _d(1.1).i, _d(1.1).i, _d(-1235.1).i, _d(3.14159265).i, _d(-1.0).i);
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
#ifdef __FLOAT_SUPPORT__
  DECLARE_TEST(test19);
  DECLARE_TEST(test20);
  DECLARE_TEST(test21);
  DECLARE_TEST(test22);
#endif

  return run_all_tests();
}
