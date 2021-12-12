#include "vector_macros.h"
#include <stdio.h>

TEST_CASE(test1) {
  set_vregmax(2);
  set_vtype(0, V_UINT32);
  set_vtype(1, V_UINT32);
  set_vtype(2, V_UINT32);
  set_vl(3);

  VEC_VLD_VREG_U32(0, 0x00000004, 0x00000001, 0x00000003);
  VEC_VLD_VREG_U32(1, 0x00000003, 0x00000001, 0x00000007);

  asm volatile ("vadd v2, v0, v1");
  VEC_CMP_U32(2, 0x00000007, 0x00000002, 0x0000000a);
}

TEST_CASE(test2) {
  set_vregmax(2);
  set_vtype(0, V_UINT32);
  set_vtype(1, V_UINT32);
  set_vtype(2, V_UINT32);
  set_vl(3);

  VEC_VLD_VREG_U32(0, 0x00000000, 0x80000000, 0x80000000);
  VEC_VLD_VREG_U32(1, 0xffff8000, 0x00000000, 0xffff8000);

  asm volatile ("vadd v2, v0, v1");
  VEC_CMP_U32(2, 0xffff8000, 0x80000000, 0x7fff8000);
}

TEST_CASE(test3) {
  set_vregmax(2);
  set_vtype(0, V_UINT16);
  set_vtype(1, V_UINT16);
  set_vtype(2, V_UINT16);
  set_vl(3);

  VEC_VLD_VREG_U16(0, 0x0000, 0x8000, 0x8000);
  VEC_VLD_VREG_U16(1, 0xff80, 0x0000, 0xff80);

  asm volatile ("vadd v2, v0, v1");

  VEC_CMP_U16(2, 0xff80, 0x8000, 0x7f80);
}

TEST_CASE(test4) {
  set_vregmax(2);
  set_vtype(0, V_UINT32);
  set_vtype(1, V_UINT32);
  set_vtype(2, V_UINT32);
  set_vl(3);

  VEC_VLD_VREG_U32(0, 0x00000000, 0x7fffffff, 0x7fffffff);
  VEC_VLD_VREG_U32(1, 0x00007fff, 0x00000000, 0x00007fff);

  asm volatile ("vadd v2, v0, v1");
  VEC_CMP_U32(2, 0x00007fff, 0x7fffffff, 0x80007ffe);
}

TEST_CASE(test5) {
  set_vregmax(2);
  set_vtype(0, V_UINT32);
  set_vtype(1, V_UINT32);
  set_vtype(2, V_UINT32);
  set_vl(2);

  VEC_VLD_VREG_U32(0, 0xffff8000, 0x00007fff);
  VEC_VLD_VREG_U32(1, 0x0000007f, 0xffffff80);

  asm volatile ("vadd v2, v0, v1");
  VEC_CMP_U32(2, 0xffff807f, 0x00007f7f);
}

TEST_CASE(test6) {
  set_vregmax(2);
  set_vtype(0, V_UINT32);
  set_vtype(1, V_UINT32);
  set_vtype(2, V_UINT32);
  set_vl(3);

  VEC_VLD_VREG_U32(0, 0x00000000, 0xffffffff, 0xffffffff);
  VEC_VLD_VREG_U32(1, 0xffffffff, 0x00000001, 0xffffffff);

  asm volatile ("vadd v2, v0, v1");
  VEC_CMP_U32(2, 0xffffffff, 0x00000000, 0xfffffffe);
}

TEST_CASE(test7) {
  set_vregmax(1);
  set_vtype(0, V_UINT32);
  set_vtype(1, V_UINT32);
  set_vl(3);

  VEC_VLD_VREG_U32(0, 0x00000000, 0x00000001, 0x00000003);
  VEC_VLD_VREG_U32(1, 0x00000000, 0x00000001, 0x00000007);

  asm volatile ("vadd v0, v0, v1");
  VEC_CMP_U32(0, 0x00000000, 0x00000002, 0x0000000a);
}

TEST_CASE(test8) {
  set_vregmax(1);
  set_vtype(0, V_UINT32);
  set_vtype(1, V_UINT32);
  set_vl(3);

  VEC_VLD_VREG_U32(0, 0x00000000, 0x00000001, 0x00000003);
  VEC_VLD_VREG_U32(1, 0x00000000, 0x00000001, 0x00000007);

  asm volatile ("vadd v1, v0, v1");
  VEC_CMP_U32(1, 0x00000000, 0x00000002, 0x0000000a);
}

TEST_CASE(test9) {
  set_vregmax(1);
  set_vtype(0, V_UINT32);
  set_vl(3);

  VEC_VLD_VREG_U32(0, 0x00000000, 0x00000001, 0x00000003);

  asm volatile ("vadd v0, v0, v0");
  VEC_CMP_U32(0, 0x00000000, 0x00000002, 0x00000006);
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

  asm volatile ("vadd v0, v2, v3, v1.t");
  VEC_CMP_U32(0, 0x00000010, 0x00000000, 0x0000000a);
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

  asm volatile ("vadd v0, v2, v3, v1.f");
  VEC_CMP_U32(0, 0x00000000, 0x00000002, 0x00000000);
}

TEST_CASE(test12) {
  set_vregmax(2);
  set_vtype(0, V_UINT64);
  set_vtype(1, V_UINT64);
  set_vtype(2, V_UINT64);
  set_vl(3);

  VEC_VLD_VREG_U64(0, 0x0000000000000000, 0xffffffff80000000, 0xffffffff80000000);
  VEC_VLD_VREG_U64(1, 0xffffffffffff8000, 0x00000000, 0xffffffffffff8000);

  asm volatile ("vadd v2, v0, v1");
  VEC_CMP_U64(2, 0xffffffffffff8000, 0xffffffff80000000, 0xffffffff7fff8000);
}

TEST_CASE(test13) {
  set_vregmax(2);
  set_vtype(0, V_UINT64);
  set_vtype(1, V_UINT64);
  set_vtype(2, V_UINT64);
  set_vl(2);

  VEC_VLD_VREG_U64(0, 0xffffffff80000000, 0x000000007fffffff);
  VEC_VLD_VREG_U64(1, 0x0000000000007fff, 0xffffffffffff8000);

  asm volatile ("vadd v2, v0, v1");
  VEC_CMP_U64(2, 0xffffffff80007fff, 0x000000007fff7fff);
}

/* Floating point */

TEST_CASE(test14) {
  set_vregmax(2);
  set_vtype(0, V_FP64);
  set_vtype(1, V_FP64);
  set_vtype(2, V_FP64);
  set_vl(3);

  VEC_VLD_VREG_F64(0, _d(2.5).i, _d(-1235.1).i, _d(3.14159265).i);
  VEC_VLD_VREG_F64(1, _d(1.0).i,     _d(1.1).i, _d(0.00000001).i);

  asm volatile ("vadd v2, v0, v1");
  VEC_CMP_F64(2, _d(3.5).i, _d(-1234).i, _d(3.14159266).i);
}

TEST_CASE(test15) {
  set_vregmax(2);
  set_vtype(0, V_FP64);
  set_vtype(1, V_UINT32);
  set_vtype(2, V_FP64);
  set_vl(3);

  VEC_VLD_VREG_F64(0, _d(2.5).i, _d(-1235.1).i, _d(3.14159265).i);
  VEC_VLD_VREG_F64(2, _d(1.0).i,     _d(1.1).i, _d(0.00000001).i);
  VEC_VLD_VREG_U32(1, 0, 1, 0);

  asm volatile ("vadd v2, v0, v2, v1.t");
  VEC_CMP_F64(2, 0, _d(-1234).i, 0);
}

TEST_CASE(test16) {
  set_vregmax(2);
  set_vtype(0, V_FP64);
  set_vtype(1, V_UINT32);
  set_vtype(2, V_FP64);
  set_vl(3);

  VEC_VLD_VREG_F64(0, _d(2.5).i, _d(-1235.1).i, _d(3.14159265).i);
  VEC_VLD_VREG_F64(2, _d(1.0).i,     _d(1.1).i, _d(0.00000001).i);
  VEC_VLD_VREG_U32(1, 0, 1, 0);

  asm volatile ("vadd v2, v0, v2, v1.f");
  VEC_CMP_F64(2, _d(3.5).i, 0, _d(3.14159266).i);
}

TEST_CASE(test17) {
  set_vregmax(2);
  set_vtype(0, V_FP32);
  set_vtype(1, V_FP32);
  set_vtype(2, V_FP32);
  set_vl(3);

  VEC_VLD_VREG_F32(0, _f(2.5).i, _f(-1235.1).i, _f(3.14159265).i);
  VEC_VLD_VREG_F32(1, _f(1.0).i,     _f(1.1).i, _f(0.00000001).i);

  asm volatile ("vadd v2, v0, v1");
  VEC_CMP_F32(2, _f(3.5).i, _f(-1234).i, _f(3.14159265).i);
}

TEST_CASE(test18) {
  set_vregmax(3);
  set_vtype(0, V_FP32);
  set_vtype(1, V_UINT16);
  set_vtype(2, V_FP32);
  set_vtype(3, V_FP32);
  set_vl(3);

  VEC_VLD_VREG_F32(0, _f(2.5).i, _f(-1235.1).i, _f(3.14159265).i);
  VEC_VLD_VREG_F32(2, _f(1.0).i,     _f(1.1).i, _f(0.00000001).i);
  VEC_VLD_VREG_U16(1, 0, 1, 0);

  asm volatile ("vadd v3, v0, v2, v1.t");
  VEC_CMP_F32(3, 0, _f(-1234).i, 0);
}

TEST_CASE(test19) {
  set_vregmax(3);
  set_vtype(0, V_FP32);
  set_vtype(1, V_UINT16);
  set_vtype(2, V_FP32);
  set_vtype(3, V_FP32);
  set_vl(3);

  VEC_VLD_VREG_F32(0, _f(2.5).i, _f(-1235.1).i, _f(3.14159265).i);
  VEC_VLD_VREG_F32(2, _f(1.0).i,     _f(1.1).i, _f(0.00000001).i);
  VEC_VLD_VREG_U16(1, 0, 1, 0);

  asm volatile ("vadd v3, v0, v2, v1.f");
  VEC_CMP_F32(3, _f(3.5).i, 0, _f(3.14159265).i);
}

TEST_CASE(test20) {
  set_vregmax(2);
  set_vtype(0, V_FP16);
  set_vtype(1, V_FP16);
  set_vtype(2, V_FP16);
  set_vl(3);

  VEC_VLD_VREG_F16(0, _h(2.5).i, _h(-1235.1).i, _h(3.14159265).i);
  VEC_VLD_VREG_F16(1, _h(1.0).i,     _h(1.1).i, _h(0.00000001).i);

  asm volatile ("vadd v2, v0, v1");
  VEC_CMP_F16(2, _h(3.5).i, _h(-1234).i, _h(3.14159265).i);
}

TEST_CASE(test21) {
  set_vregmax(3);
  set_vtype(0, V_FP16);
  set_vtype(1, V_UINT8);
  set_vtype(2, V_FP16);
  set_vtype(3, V_FP16);
  set_vl(3);

  VEC_VLD_VREG_F16(0, _h(2.5).i, _h(-1235.1).i, _h(3.14159265).i);
  VEC_VLD_VREG_F16(2, _h(1.0).i,     _h(1.1).i, _h(0.00000001).i);
  VEC_VLD_VREG_U8(1, 0, 1, 0);

  asm volatile ("vadd v3, v0, v2, v1.t");
  VEC_CMP_F16(3, 0, _h(-1234).i, 0);
}

TEST_CASE(test22) {
  set_vregmax(3);
  set_vtype(0, V_FP16);
  set_vtype(1, V_UINT8);
  set_vtype(2, V_FP16);
  set_vtype(3, V_FP16);
  set_vl(3);

  VEC_VLD_VREG_F16(0, _h(2.5).i, _h(-1235.1).i, _h(3.14159265).i);
  VEC_VLD_VREG_F16(2, _h(1.0).i,     _h(1.1).i, _h(0.00000001).i);
  VEC_VLD_VREG_U8(1, 0, 1, 0);

  asm volatile ("vadd v3, v0, v2, v1.f");
  VEC_CMP_F16(3, _h(3.5).i, 0, _h(3.14159265).i);
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
#ifdef __FLOAT_SUPPORT__
  DECLARE_TEST(test14);
  DECLARE_TEST(test15);
  DECLARE_TEST(test16);
  DECLARE_TEST(test17);
  DECLARE_TEST(test18);
  DECLARE_TEST(test19);
  DECLARE_TEST(test20);
  DECLARE_TEST(test21);
  DECLARE_TEST(test22);
#endif

  return run_all_tests();
}
