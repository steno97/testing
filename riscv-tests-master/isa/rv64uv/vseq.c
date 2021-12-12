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

  asm volatile ("vseq v2, v0, v1");
  VEC_CMP_U32(2, 1, 1, 0);
}

TEST_CASE(test2) {
  set_vregmax(2);
  set_vtype(0, V_UINT32);
  set_vtype(1, V_UINT32);
  set_vtype(2, V_UINT32);
  set_vl(3);

  VEC_VLD_VREG_U32(0, 0x00000000, 0x80000000, 0xfffffffe);
  VEC_VLD_VREG_U32(1, 0x80000000, 0x00000000, 0xffffffff);

  asm volatile ("vseq v2, v0, v1");
  VEC_CMP_U32(2, 0, 0, 0);
}

TEST_CASE(test3) {
  set_vregmax(2);
  set_vtype(0, V_UINT32);
  set_vtype(1, V_UINT64);
  set_vtype(2, V_UINT64);
  set_vl(4);

  VEC_VLD_VREG_U32(0,             0xffff,             0xffff,             0x8000,             0x7fff);
  VEC_VLD_VREG_U64(1, 0xffffffffffffffff, 0x000000000000ffff, 0xffffffffffff8000, 0x0000000000007fff);

  asm volatile ("vseq v2, v0, v1");

  VEC_CMP_U64(2, 0, 1, 0, 1);
}

TEST_CASE(test4) {
  set_vregmax(2);
  set_vtype(0, V_INT16);
  set_vtype(1, V_INT32);
  set_vtype(2, V_UINT32);
  set_vl(4);

  VEC_VLD_VREG_S16(0,     0xffff,     0xffff,     0x8000,     0x7fff);
  VEC_VLD_VREG_S32(1, 0xffffffff, 0x0000ffff, 0xffff8000, 0x00007fff);

  asm volatile ("vseq v2, v0, v1");

  VEC_CMP_U32(2, 1, 0, 1, 1);
}

TEST_CASE(test5) {
  set_vregmax(2);
  set_vtype(0, V_UINT32);
  set_vtype(1, V_UINT32);
  set_vtype(2, V_UINT32);
  set_vl(3);

  VEC_VLD_VREG_U32(0, 0x00000000, 0x00000001, 0x00000003);
  VEC_VLD_VREG_U32(1, 0x00000000, 0x00000001, 0x00000007);

  asm volatile ("vseq v0, v0, v1");
  VEC_CMP_U32(0, 1, 1, 0);
}

TEST_CASE(test6) {
  set_vregmax(1);
  set_vtype(0, V_UINT32);
  set_vtype(1, V_UINT32);
  set_vl(3);

  VEC_VLD_VREG_U32(0, 0x00000000, 0x00000001, 0x00000003);
  VEC_VLD_VREG_U32(1, 0x00000000, 0x00000001, 0x00000007);

  asm volatile ("vseq v1, v0, v1");
  VEC_CMP_U32(1, 1, 1, 0);
}

TEST_CASE(test7) {
  set_vregmax(1);
  set_vtype(0, V_UINT32);
  set_vl(3);

  VEC_VLD_VREG_U32(0, 0x00000000, 0x00000001, 0x00000003);

  asm volatile ("vseq v0, v0, v0");
  VEC_CMP_U32(0, 1, 1, 1);
}

TEST_CASE(test8) {
  set_vregmax(3);
  set_vtype(0, V_UINT32);
  set_vtype(1, V_UINT16);
  set_vtype(2, V_UINT32);
  set_vtype(3, V_UINT32);
  set_vl(3);

  VEC_VLD_VREG_U16(1, 0x01, 0xf0, 0xff);
  VEC_VLD_VREG_U32(2, 0x00000008, 0x00000001, 0x00000003);
  VEC_VLD_VREG_U32(3, 0x00000008, 0x00000001, 0x00000007);

  asm volatile ("vseq v0, v2, v3, v1.t");
  VEC_CMP_U32(0, 1, 0, 0);
}

TEST_CASE(test9) {
  set_vregmax(3);
  set_vtype(0, V_UINT32);
  set_vtype(1, V_UINT16);
  set_vtype(2, V_UINT32);
  set_vtype(3, V_UINT32);
  set_vl(3);

  VEC_VLD_VREG_U16(1, 0x01, 0xf0, 0xff);
  VEC_VLD_VREG_U32(2, 0x00000008, 0x00000001, 0x00000003);
  VEC_VLD_VREG_U32(3, 0x00000008, 0x00000001, 0x00000007);

  asm volatile ("vseq v0, v2, v3, v1.f");
  VEC_CMP_U32(0, 0, 1, 0);
}

TEST_CASE(test10) {
  set_vregmax(2);
  set_vtype(0, V_FP64);
  set_vtype(1, V_FP64);
  set_vtype(2, V_INT64);
  set_vl(4);

  VEC_VLD_VREG_F64(0, _d(-1.36).i, _d(-1.37).i, _d(1.36).i, _d(1.37).i);
  VEC_VLD_VREG_F64(1, _d(-1.36).i, _d(-1.36).i, _d(1.36).i, _d(1.36).i);

  asm volatile ("vseq v2, v0, v1");
  VEC_CMP_S64(2, 1, 0, 1, 0);
}

TEST_CASE(test11) {
  set_vregmax(2);
  set_vtype(0, V_FP32);
  set_vtype(1, V_FP32);
  set_vtype(2, V_INT32);
  set_vl(4);

  VEC_VLD_VREG_F32(0, _f(-1.36).i, _f(-1.37).i, _f(1.36).i, _f(1.37).i);
  VEC_VLD_VREG_F32(1, _f(-1.36).i, _f(-1.36).i, _f(1.36).i, _f(1.36).i);

  asm volatile ("vseq v2, v0, v1");
  VEC_CMP_S32(2, 1, 0, 1, 0);
}

TEST_CASE(test12) {
  set_vregmax(2);
  set_vtype(0, V_FP16);
  set_vtype(1, V_FP16);
  set_vtype(2, V_INT32);
  set_vl(4);

  VEC_VLD_VREG_F16(0, _h(-1.36).i, _h(-1.37).i, _h(1.36).i, _h(1.37).i);
  VEC_VLD_VREG_F16(1, _h(-1.36).i, _h(-1.36).i, _h(1.36).i, _h(1.36).i);

  asm volatile ("vseq v2, v0, v1");
  VEC_CMP_S32(2, 1, 0, 1, 0);
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
#ifdef __FLOAT_SUPPORT__
  DECLARE_TEST(test10);
  DECLARE_TEST(test11);
  DECLARE_TEST(test12);
#endif

  return run_all_tests();
}
