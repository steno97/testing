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

  asm volatile ("vmul v2, v0, v1");
  VEC_CMP_U32(2, 0x00000000, 0x00000001, 0x00000015);
}

TEST_CASE(test2) {
  set_vregmax(2);
  set_vtype(0, V_UINT32);
  set_vtype(1, V_UINT32);
  set_vtype(2, V_UINT32);
  set_vl(3);

  VEC_VLD_VREG_U32(0, 0x00000000, 0x80000000, 0x80000000);
  VEC_VLD_VREG_U32(1, 0xffff8000, 0x00000000, 0xffff8000);

  asm volatile ("vmul v2, v0, v1");
  VEC_CMP_U32(2, 0x00000000, 0x00000000, 0x00000000);
}

TEST_CASE(test3) {
  set_vregmax(2);
  set_vtype(0, V_UINT32);
  set_vtype(1, V_UINT32);
  set_vtype(2, V_UINT32);
  set_vl(4);

  VEC_VLD_VREG_U32(0, 0x00007e00, 0x00007fc0, 0xaaaaaaab, 0x0002fe7d);
  VEC_VLD_VREG_U32(1, 0xb6db6db7, 0xb6db6db7, 0x0002fe7d, 0xaaaaaaab);

  asm volatile ("vmul v2, v0, v1");
  VEC_CMP_U32(2, 0x00001200, 0x00001240, 0x0000ff7f, 0x0000ff7f);
}

TEST_CASE(test4) {
  set_vregmax(2);
  set_vtype(0, V_UINT32);
  set_vtype(1, V_UINT32);
  set_vtype(2, V_UINT32);
  set_vl(4);

  VEC_VLD_VREG_U32(0, 0x00000000, 0x00000001, 0xffffffff, 0xffffffff);
  VEC_VLD_VREG_U32(1, 0xff000000, 0xffffffff, 0xffffffff, 0x00000001);

  asm volatile ("vmul v2, v0, v1");
  VEC_CMP_U32(2, 0x00000000, 0xffffffff, 0x00000001, 0xffffffff);
}

TEST_CASE(test5) {
  set_vregmax(2);
  set_vtype(0, V_UINT16);
  set_vtype(1, V_UINT16);
  set_vtype(2, V_UINT32);
  set_vl(3);

  VEC_VLD_VREG_U16(0, 0x0000, 0x0001, 0x0003);
  VEC_VLD_VREG_U16(1, 0x0000, 0x0001, 0x0007);

  asm volatile ("vmul v2, v0, v1");
  VEC_CMP_U32(2, 0x00000000, 0x00000001, 0x00000015);
}

TEST_CASE(test6) {
  set_vregmax(2);
  set_vtype(0, V_UINT16);
  set_vtype(1, V_UINT16);
  set_vtype(2, V_UINT32);
  set_vl(3);

  VEC_VLD_VREG_U16(0, 0x0000, 0x8000, 0x8000);
  VEC_VLD_VREG_U16(1, 0xff80, 0x0000, 0xff80);

  asm volatile ("vmul v2, v0, v1");
  VEC_CMP_U32(2, 0x00000000, 0x00000000, 0x7fc00000);
}

TEST_CASE(test7) {
  set_vregmax(2);
  set_vtype(0, V_INT16);
  set_vtype(1, V_INT16);
  set_vtype(2, V_INT32);
  set_vl(3);

  VEC_VLD_VREG_S16(0, 0x0000, 0x8000, 0x8000);
  VEC_VLD_VREG_S16(1, 0xff80, 0x0000, 0xff80);

  asm volatile ("vmul v2, v0, v1");
  VEC_CMP_S32(2, 0x00000000, 0x00000000, 0x00400000);
}

TEST_CASE(test8) {
  set_vregmax(2);
  set_vtype(0, V_UINT8);
  set_vtype(1, V_UINT8);
  set_vtype(2, V_UINT16);
  set_vl(3);

  VEC_VLD_VREG_U8(0, 0x00, 0x80, 0x80);
  VEC_VLD_VREG_U8(1, 0xf8, 0x00, 0xf8);

  asm volatile ("vmul v2, v0, v1");
  VEC_CMP_U16(2, 0x0000, 0x0000, 0x7c00);
}

TEST_CASE(test9) {
  set_vregmax(2);
  set_vtype(0, V_UINT8);
  set_vtype(1, V_UINT8);
  set_vtype(2, V_UINT8);
  set_vl(3);

  VEC_VLD_VREG_U8(0, 0x00, 0x80, 0x80);
  VEC_VLD_VREG_U8(1, 0xf8, 0x00, 0xf8);

  asm volatile ("vmul v2, v0, v1");
  VEC_CMP_S8(2, 0x00, 0x00, 0x00);
}

TEST_CASE(test10) {
  set_vregmax(1);
  set_vtype(0, V_UINT32);
  set_vtype(1, V_UINT32);
  set_vl(1);

  VEC_VLD_VREG_U32(0, 13);
  VEC_VLD_VREG_U32(1, 11);

  asm volatile ("vmul v0, v0, v1");
  VEC_CMP_U32(0, 143);
}

TEST_CASE(test11) {
  set_vregmax(1);
  set_vtype(0, V_UINT32);
  set_vtype(1, V_UINT32);
  set_vl(1);

  VEC_VLD_VREG_U32(0, 14);
  VEC_VLD_VREG_U32(1, 11);

  asm volatile ("vmul v1, v0, v1");
  VEC_CMP_U32(1, 154);
}

TEST_CASE(test12) {
  set_vregmax(1);
  set_vtype(0, V_UINT32);
  set_vl(1);

  VEC_VLD_VREG_U32(0, 13);

  asm volatile ("vmul v0, v0, v0");
  VEC_CMP_U32(0, 169);
}

TEST_CASE(test13) {
  set_vregmax(3);
  set_vtype(0, V_UINT32);
  set_vtype(1, V_UINT16);
  set_vtype(2, V_UINT32);
  set_vtype(3, V_UINT32);
  set_vl(3);

  VEC_VLD_VREG_U16(1, 0, 1, 0);
  VEC_VLD_VREG_U32(2, 0x00000000, 0x00000001, 0x00000003);
  VEC_VLD_VREG_U32(3, 0x00000000, 0x00000001, 0x00000007);

  asm volatile ("vmul v0, v2, v3, v1.t");
  VEC_CMP_U32(0, 0x00000000, 0x00000001, 0x00000000);
}

TEST_CASE(test14) {
  set_vregmax(3);
  set_vtype(0, V_UINT32);
  set_vtype(1, V_UINT16);
  set_vtype(2, V_UINT32);
  set_vtype(3, V_UINT32);
  set_vl(3);

  VEC_VLD_VREG_U16(1, 0, 1, 0);
  VEC_VLD_VREG_U32(2, 0x00000000, 0x00000001, 0x00000003);
  VEC_VLD_VREG_U32(3, 0x00000000, 0x00000001, 0x00000007);

  asm volatile ("vmul v0, v2, v3, v1.f");
  VEC_CMP_U32(0, 0x00000000, 0x00000000, 0x00000015);
}

TEST_CASE(test15) {
  set_vregmax(3);
  set_vtype(0, V_UINT64);
  set_vtype(2, V_UINT64);
  set_vtype(3, V_UINT64);
  set_vl(2);

  VEC_VLD_VREG_U64(2, 0xffffffff80000000, 0xffffffff80000000);
  VEC_VLD_VREG_U64(3, 0x0000000000000000, 0xffffffffffff8000);

  asm volatile ("vmul v0, v2, v3");
  VEC_CMP_U64(0, 0x0000000000000000, 0x0000400000000000);
}

TEST_CASE(test16) {
  set_vregmax(2);
  set_vtype(0, V_FP64);
  set_vtype(1, V_FP64);
  set_vtype(2, V_FP64);
  set_vl(3);

  VEC_VLD_VREG_F64(0, _d(2.5).i, _d(-1235.1).i, _d(3.14159265).i);
  VEC_VLD_VREG_F64(1, _d(1.0).i,     _d(1.1).i, _d(0.00000001).i);

  asm volatile ("vmul v2, v0, v1");
  VEC_CMP_F64(2, _d(2.5).i, _d(-1358.61).i, _d(3.14159265e-8).i);
}

TEST_CASE(test17) {
  set_vregmax(2);
  set_vtype(0, V_FP64);
  set_vtype(1, V_UINT32);
  set_vtype(2, V_FP64);
  set_vl(3);

  VEC_VLD_VREG_F64(0, _d(2.5).i, _d(-1235.1).i, _d(3.14159265).i);
  VEC_VLD_VREG_F64(2, _d(1.0).i,     _d(1.1).i, _d(0.00000001).i);
  VEC_VLD_VREG_U32(1, 0, 1, 0);

  asm volatile ("vmul v2, v0, v2, v1.t");
  VEC_CMP_F64(2, 0, _d(-1358.61).i, 0);
}

TEST_CASE(test18) {
  set_vregmax(2);
  set_vtype(0, V_FP64);
  set_vtype(1, V_UINT32);
  set_vtype(2, V_FP64);
  set_vl(3);

  VEC_VLD_VREG_F64(0, _d(2.5).i, _d(-1235.1).i, _d(3.14159265).i);
  VEC_VLD_VREG_F64(2, _d(1.0).i,     _d(1.1).i, _d(0.00000001).i);
  VEC_VLD_VREG_U32(1, 0, 1, 0);

  asm volatile ("vmul v2, v0, v2, v1.f");
  VEC_CMP_F64(2, _d(2.5).i, 0, _d(3.14159265e-8).i);
}

TEST_CASE(test19) {
  set_vregmax(2);
  set_vtype(0, V_FP32);
  set_vtype(1, V_FP32);
  set_vtype(2, V_FP32);
  set_vl(3);

  VEC_VLD_VREG_F32(0, _f(2.5).i, _f(-1235.1).i, _f(3.14159265).i);
  VEC_VLD_VREG_F32(1, _f(1.0).i,     _f(1.1).i, _f(0.00000001).i);

  asm volatile ("vmul v2, v0, v1");
  VEC_CMP_F32(2, _f(2.5).i, _f(-1358.61).i, _f(3.14159265e-8).i);
}

TEST_CASE(test20) {
  set_vregmax(3);
  set_vtype(0, V_FP32);
  set_vtype(1, V_UINT16);
  set_vtype(2, V_FP32);
  set_vtype(3, V_FP32);
  set_vl(3);

  VEC_VLD_VREG_F32(0, _f(2.5).i, _f(-1235.1).i, _f(3.14159265).i);
  VEC_VLD_VREG_F32(2, _f(1.0).i,     _f(1.1).i, _f(0.00000001).i);
  VEC_VLD_VREG_U16(1, 0, 1, 0);

  asm volatile ("vmul v3, v0, v2, v1.t");
  VEC_CMP_F32(3, 0, _f(-1358.61).i, 0);
}

TEST_CASE(test21) {
  set_vregmax(3);
  set_vtype(0, V_FP32);
  set_vtype(1, V_UINT16);
  set_vtype(2, V_FP32);
  set_vtype(3, V_FP32);
  set_vl(3);

  VEC_VLD_VREG_F32(0, _f(2.5).i, _f(-1235.1).i, _f(3.14159265).i);
  VEC_VLD_VREG_F32(2, _f(1.0).i,     _f(1.1).i, _f(0.00000001).i);
  VEC_VLD_VREG_U16(1, 0, 1, 0);

  asm volatile ("vmul v3, v0, v2, v1.f");
  VEC_CMP_F32(3, _f(2.5).i, 0, _f(3.14159265e-8).i);
}

TEST_CASE(test22) {
  set_vregmax(2);
  set_vtype(0, V_FP16);
  set_vtype(1, V_FP16);
  set_vtype(2, V_FP16);
  set_vl(2);

  VEC_VLD_VREG_F16(0, _h(2.5).i, _h(3.14159265).i);
  VEC_VLD_VREG_F16(1, _h(1.0).i, _h(0.01).i);

  asm volatile ("vmul v2, v0, v1");
  VEC_CMP_F16(2, _h(2.5).i, _h(3.14159265e-2).i);
}

TEST_CASE(test23) {
  set_vregmax(3);
  set_vtype(0, V_FP16);
  set_vtype(1, V_UINT8);
  set_vtype(2, V_FP16);
  set_vtype(3, V_FP16);
  set_vl(2);

  VEC_VLD_VREG_F16(0, _h(2.5).i, _h(3.14159265).i);
  VEC_VLD_VREG_F16(2, _h(1.0).i, _h(0.01).i);
  VEC_VLD_VREG_U8(1, 0, 1);

  asm volatile ("vmul v3, v0, v2, v1.t");
  VEC_CMP_F16(3, 0, _h(3.14159265e-2).i);
}

TEST_CASE(test24) {
  set_vregmax(3);
  set_vtype(0, V_FP16);
  set_vtype(1, V_UINT8);
  set_vtype(2, V_FP16);
  set_vtype(3, V_FP16);
  set_vl(2);

  VEC_VLD_VREG_F16(0, _h(2.5).i, _h(3.14159265).i);
  VEC_VLD_VREG_F16(2, _h(1.0).i, _h(0.01).i);
  VEC_VLD_VREG_U8(1, 0, 1);

  asm volatile ("vmul v3, v0, v2, v1.f");
  VEC_CMP_F16(3, _h(2.5).i, 0);
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
#ifdef __FLOAT_SUPPORT__
  DECLARE_TEST(test16);
  DECLARE_TEST(test17);
  DECLARE_TEST(test18);
  DECLARE_TEST(test19);
  DECLARE_TEST(test20);
  DECLARE_TEST(test21);
  DECLARE_TEST(test22);
  DECLARE_TEST(test23);
  DECLARE_TEST(test24);
#endif

  return run_all_tests();
}
