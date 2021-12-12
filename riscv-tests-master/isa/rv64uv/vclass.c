#include "vector_macros.h"
#include <stdio.h>

TEST_CASE(test1) {
  set_vregmax(3);
  set_vtype(0, V_FP64);
  set_vtype(3, V_UINT64);
  set_vl(5);

  VEC_VLD_VREG_F64(0, 0xfff0000000000000, 0xbff0000000000000, 0x800fffffffffffff, 0x8000000000000000, 0x0000000000000000);

  asm volatile ("vclass v3, v0");
  VEC_CMP_U64(3, 1<<0, 1<<1, 1<<2, 1<<3, 1<<4);
}

TEST_CASE(test2) {
  set_vregmax(3);
  set_vtype(0, V_FP64);
  set_vtype(3, V_UINT64);
  set_vl(5);

  VEC_VLD_VREG_F64(0, 0x000fffffffffffff, 0x3ff0000000000000, 0x7ff0000000000000, 0x7ff0000000000001, 0x7ff8000000000000);

  asm volatile ("vclass v3, v0");
  VEC_CMP_U64(3, 1<<5, 1<<6, 1<<7, 1<<8, 1<<9);
}

TEST_CASE(test3) {
  set_vregmax(3);
  set_vtype(0, V_FP32);
  set_vtype(3, V_UINT32);
  set_vl(5);

  VEC_VLD_VREG_F32(0, 0xff800000, 0xbf800000, 0x807fffff, 0x80000000, 0x00000000);

  asm volatile ("vclass v3, v0");
  VEC_CMP_U32(3, 1<<0, 1<<1, 1<<2, 1<<3, 1<<4);
}

TEST_CASE(test4) {
  set_vregmax(3);
  set_vtype(0, V_FP32);
  set_vtype(3, V_UINT32);
  set_vl(5);

  VEC_VLD_VREG_F32(0, 0x007fffff, 0x3f800000, 0x7f800000, 0x7f800001, 0x7fc00000);

  asm volatile ("vclass v3, v0");
  VEC_CMP_U32(3, 1<<5, 1<<6, 1<<7, 1<<8, 1<<9);
}

TEST_CASE(test5) {
  set_vregmax(3);
  set_vtype(0, V_FP16);
  set_vtype(3, V_UINT16);
  set_vl(5);

  VEC_VLD_VREG_F16(0, 0xfc00, 0xbff0, 0x803f, 0x8000, 0x0000);

  asm volatile ("vclass v3, v0");
  VEC_CMP_U16(3, 1<<0, 1<<1, 1<<2, 1<<3, 1<<4);
}

TEST_CASE(test6) {
  set_vregmax(3);
  set_vtype(0, V_FP16);
  set_vtype(3, V_UINT16);
  set_vl(5);

  VEC_VLD_VREG_F16(0, 0x003f, 0x3f80, 0x7c00, 0x7c01, 0x7e00);

  asm volatile ("vclass v3, v0");
  VEC_CMP_U16(3, 1<<5, 1<<6, 1<<7, 1<<8, 1<<9);
}

TEST_CASE(test7) {
  set_vregmax(3);
  set_vtype(0, V_FP64);
  set_vtype(1, V_INT64);
  set_vtype(3, V_UINT64);
  set_vl(5);

  VEC_VLD_VREG_F64(0, 0xfff0000000000000, 0xbff0000000000000, 0x800fffffffffffff, 0x8000000000000000, 0x0000000000000000);
  VEC_VLD_VREG_S64(1, 0, 1, 0, 1, 0);

  asm volatile ("vclass v3, v0, v1.t");
  VEC_CMP_U64(3, 0, 1<<1, 0, 1<<3, 0);
}

TEST_CASE(test8) {
  set_vregmax(3);
  set_vtype(0, V_FP64);
  set_vtype(1, V_INT64);
  set_vtype(3, V_UINT64);
  set_vl(5);

  VEC_VLD_VREG_F64(0, 0xfff0000000000000, 0xbff0000000000000, 0x800fffffffffffff, 0x8000000000000000, 0x0000000000000000);
  VEC_VLD_VREG_S64(1, 0, 1, 0, 1, 0);

  asm volatile ("vclass v3, v0, v1.f");
  VEC_CMP_U64(3, 1<<0, 0, 1<<2, 0, 1<<4);
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
#endif

  return run_all_tests();
}
