#include "vector_macros.h"
#include <stdio.h>

TEST_CASE(test1) {
  set_vregmax(2);
  set_vtype(0, V_FP64);
  set_vtype(1, V_FP64);
  set_vtype(2, V_FP64);
  set_vl(4);

  VEC_VLD_VREG_F64(0, 0x1234567812345678, 0x1234567812345678, 0x9234567812345678, 0x9234567812345678);
  VEC_VLD_VREG_F64(1, 0x0000000000000000, 0xFFFFFFFFFFFFFFFF, 0x0000000000000000, 0xFFFFFFFFFFFFFFFF);

  asm volatile ("vsgnjn v2, v0, v1");
  VEC_CMP_F64(2, 0x9234567812345678, 0x1234567812345678, 0x9234567812345678, 0x1234567812345678);
}

TEST_CASE(test2) {
  set_vregmax(2);
  set_vtype(0, V_FP32);
  set_vtype(1, V_FP32);
  set_vtype(2, V_FP32);
  set_vl(4);

  VEC_VLD_VREG_F32(0, 0x12345678, 0x12345678, 0x92345678, 0x92345678);
  VEC_VLD_VREG_F32(1, 0x00000000, 0xFFFFFFFF, 0x00000000, 0xFFFFFFFF);

  asm volatile ("vsgnjn v2, v0, v1");
  VEC_CMP_F32(2, 0x92345678, 0x12345678, 0x92345678, 0x12345678);
}

TEST_CASE(test3) {
  set_vregmax(2);
  set_vtype(0, V_FP16);
  set_vtype(1, V_FP16);
  set_vtype(2, V_FP16);
  set_vl(4);

  VEC_VLD_VREG_F16(0, 0x1234, 0x1234, 0x9234, 0x9234);
  VEC_VLD_VREG_F16(1, 0x0000, 0xFFFF, 0x0000, 0xFFFF);

  asm volatile ("vsgnjn v2, v0, v1");
  VEC_CMP_F16(2, 0x9234, 0x1234, 0x9234, 0x1234);
}

TEST_CASE(test4) {
  set_vregmax(2);
  set_vtype(0, V_FP64);
  set_vtype(1, V_UINT64);
  set_vtype(2, V_FP64);
  set_vl(4);

  VEC_VLD_VREG_F64(0, 0x1234567812345678, 0x1234567812345678, 0x9234567812345678, 0x9234567812345678);
  VEC_VLD_VREG_F64(2, 0x0000000000000000, 0xFFFFFFFFFFFFFFFF, 0x0000000000000000, 0xFFFFFFFFFFFFFFFF);
  VEC_VLD_VREG_U64(1, 0, 1, 0, 1);

  asm volatile ("vsgnjn v2, v0, v2, v1.t");
  VEC_CMP_F64(2, 0, 0x1234567812345678, 0, 0x1234567812345678);
}

TEST_CASE(test5) {
  set_vregmax(2);
  set_vtype(0, V_FP64);
  set_vtype(1, V_UINT64);
  set_vtype(2, V_FP64);
  set_vl(4);

  VEC_VLD_VREG_F64(0, 0x1234567812345678, 0x1234567812345678, 0x9234567812345678, 0x9234567812345678);
  VEC_VLD_VREG_F64(2, 0x0000000000000000, 0xFFFFFFFFFFFFFFFF, 0x0000000000000000, 0xFFFFFFFFFFFFFFFF);
  VEC_VLD_VREG_U64(1, 0, 1, 0, 1);

  asm volatile ("vsgnjn v2, v0, v2, v1.f");
  VEC_CMP_F64(2, 0x9234567812345678, 0, 0x9234567812345678, 0);
}

int main(void) {
#ifdef __FLOAT_SUPPORT__
  DECLARE_TEST(test1);
  DECLARE_TEST(test2);
  DECLARE_TEST(test3);
  DECLARE_TEST(test4);
  DECLARE_TEST(test5);
#endif

  return run_all_tests();
}
