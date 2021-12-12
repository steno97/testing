#include "vector_macros.h"
#include <stdio.h>

TEST_CASE(test1) {
  set_vregmax(10);
  set_vtype(2, V_UINT32);
  set_vtype(10, V_UINT16);
  set_vl(4);

  volatile uint32_t S[] = {0xffffffff, 0x00000000, 0x0f0f0f0f, 0xf0f0f0f0};

  VEC_VLD_VREG_U16(10, 0, 4, 8, 12);

  asm volatile ("vldx v2, 0(%0, v10)" : : "r" (S));

  VEC_CMP_U32(2, 0xffffffff, 0x00000000, 0x0f0f0f0f, 0xf0f0f0f0);
}

TEST_CASE(test2) {
  set_vregmax(10);
  set_vtype(2, V_UINT32);
  set_vtype(10, V_UINT16);
  set_vl(2);

  volatile uint32_t S[] = {0xffffffff, 0x00000000, 0x0f0f0f0f, 0xf0f0f0f0};

  VEC_VLD_VREG_U16(10, 0, 8);

  asm volatile ("vldx v2, 1(%0, v10)" : : "r" (S));

  VEC_CMP_U32(2, 0x00000000, 0xf0f0f0f0);
}

TEST_CASE(test3) {
  set_vregmax(10);
  set_vtype(2, V_UINT32);
  set_vtype(10, V_INT32);
  set_vl(4);

  volatile uint32_t S[] = {0xffffffff, 0x00000000, 0x0f0f0f0f, 0xf0f0f0f0};

  VEC_VLD_VREG_S32(10, 0, -4, -8, -12);

  asm volatile ("vldx v2, 3(%0, v10)" : : "r" (S));

  VEC_CMP_U32(2, 0xf0f0f0f0, 0x0f0f0f0f, 0x00000000, 0xffffffff);
}

TEST_CASE(test4) {
  set_vregmax(10);
  set_vtype(2, V_UINT16);
  set_vtype(10, V_INT16);
  set_vl(2);

  volatile uint16_t S[] = {0xffff, 0x0000, 0x0f0f, 0xf0f0};

  VEC_VLD_VREG_S16(10, 0, -4);

  asm volatile ("vldx v2, 3(%0, v10)" : : "r" (S));

  VEC_CMP_U16(2, 0xf0f0, 0x0000);
}

TEST_CASE(test5) {
  set_vregmax(10);
  set_vtype(2, V_UINT16);
  set_vtype(10, V_INT16);
  set_vl(4);

  volatile uint16_t S[] = {0xffff, 0x0000, 0x0f0f, 0xf0f0};

  VEC_VLD_VREG_S16(10, 0, -2, -4, -6);

  asm volatile ("vldx v2, 3(%0, v10)" : : "r" (S));

  VEC_CMP_U16(2, 0xf0f0, 0x0f0f, 0x0000, 0xffff);
}

TEST_CASE(test6) {
  set_vregmax(10);
  set_vtype(1, V_UINT16);
  set_vtype(2, V_UINT32);
  set_vtype(10, V_UINT16);
  set_vl(4);

  volatile uint32_t S[] = {0xffffffff, 0x00000000, 0x0f0f0f0f, 0xf0f0f0f0};

  VEC_VLD_VREG_U16(1, 0x01, 0xf0, 0xff, 0xfe);
  VEC_VLD_VREG_U16(10, 0, 4, 8, 12);

  asm volatile ("vldx v2, 0(%0, v10), v1.t" : : "r" (S));

  VEC_CMP_U32(2, 0xffffffff, 0x00000000, 0x0f0f0f0f, 0x00000000);
}

TEST_CASE(test7) {
  set_vregmax(10);
  set_vtype(1, V_UINT16);
  set_vtype(2, V_UINT32);
  set_vtype(10, V_UINT16);
  set_vl(4);

  volatile uint32_t S[] = {0xffffffff, 0x00000000, 0x0f0f0f0f, 0xf0f0f0f0};

  VEC_VLD_VREG_U16(1, 0x01, 0xf0, 0xff, 0xfe);
  VEC_VLD_VREG_U16(10, 0, 4, 8, 12);

  asm volatile ("vldx v2, 0(%0, v10), v1.f" : : "r" (S));

  VEC_CMP_U32(2, 0x00000000, 0x00000000, 0x00000000, 0xf0f0f0f0);
}

TEST_CASE(test8) {
  set_vregmax(10);
  set_vtype(2, V_UINT64);
  set_vtype(10, V_UINT32);
  set_vl(4);

  volatile uint64_t S[] = {0xdeadbeefffffffff, 0xdeadbeef00000000, 0xdeadbeef0f0f0f0f, 0xdeadbeeff0f0f0f0};

  VEC_VLD_VREG_U32(10, 0, 8, 24, 16);

  asm volatile ("vldx v2, 0(%0, v10)" : : "r" (S));

  VEC_CMP_U64(2, 0xdeadbeefffffffff, 0xdeadbeef00000000, 0xdeadbeeff0f0f0f0, 0xdeadbeef0f0f0f0f);
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

  return run_all_tests();
}
