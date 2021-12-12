#include "vector_macros.h"
#include <stdio.h>

TEST_CASE(test1) {
  set_vregmax(10);
  set_vtype(0, V_UINT32);
  set_vtype(10, V_UINT16);
  set_vl(4);

  volatile uint32_t S[4] = {0xdeadbeef, 0xdeadbeef, 0xdeadbeef, 0xdeadbeef};

  VEC_VLD_VREG_U16(10, 0, 4, 8, 12);
  VEC_VLD_VREG_U32(0, 0xffffffff, 0x00000000, 0x0f0f0f0f, 0xf0f0f0f0);

  asm volatile ("vstx v0, 0(%0, v10)" : : "r" (S));

  VEC_EQUAL_U32(S, 0xffffffff, 0x00000000, 0x0f0f0f0f, 0xf0f0f0f0);
}

TEST_CASE(test2) {
  set_vregmax(10);
  set_vtype(0, V_UINT16);
  set_vtype(10, V_UINT8);
  set_vl(2);

  volatile uint16_t S[4] = {0xdead, 0xbeef, 0xdead, 0xbeef};

  VEC_VLD_VREG_U8(10, 4, 0);
  VEC_VLD_VREG_U16(0, 0xffff, 0x0000);

  asm volatile ("vstx v0, 0(%0, v10)" : : "r" (S));

  VEC_EQUAL_U16(S, 0x0000, 0xbeef, 0xffff, 0xbeef);
}

TEST_CASE(test3) {
  set_vregmax(10);
  set_vtype(0, V_UINT32);
  set_vtype(10, V_INT16);
  set_vl(4);

  volatile uint32_t S[4] = {0xdeadbeef, 0xdeadbeef, 0xdeadbeef, 0xdeadbeef};

  VEC_VLD_VREG_U32(0, 0xffffffff, 0x00000000, 0x0f0f0f0f, 0xf0f0f0f0);
  VEC_VLD_VREG_S16 (10, 0, -4, -8, -12);

  asm volatile ("vstx v0, 3(%0, v10)" : : "r" (S));

  VEC_EQUAL_U32(S, 0xf0f0f0f0, 0x0f0f0f0f, 0x00000000, 0xffffffff);
}

TEST_CASE(test4) {
  set_vregmax(10);
  set_vtype(0, V_UINT16);
  set_vtype(10, V_INT8);
  set_vl(4);

  volatile uint16_t S[4] = {0xdead, 0xbeef, 0xdead, 0xbeef};

  VEC_VLD_VREG_U16(0, 0xffff, 0x0000, 0x0f0f, 0xf0f0);
  VEC_VLD_VREG_S8 (10, 0, -2, -4, -6);

  asm volatile ("vstx v0, 3(%0, v10)" : : "r" (S));

  VEC_EQUAL_U16(S, 0xf0f0, 0x0f0f, 0x0000, 0xffff);
}

TEST_CASE(test5) {
  set_vregmax(10);
  set_vtype(0, V_UINT32);
  set_vtype(1, V_UINT32);
  set_vtype(10, V_UINT16);
  set_vl(4);

  volatile uint32_t S[4] = {0xdeadbeef, 0xdeadbeef, 0xdeadbeef, 0xdeadbeef};

  VEC_VLD_VREG_U32(0, 0xffffffff, 0x00ffff00, 0x0f0f0f0f, 0xf0f0f0f0);
  VEC_VLD_VREG_U32(1, 1, 0, 1, 0);
  VEC_VLD_VREG_U16(10, 0, 12, 4, 8);

  asm volatile ("vstx v0, 0(%0, v10), v1.t" : : "r" (S));

  VEC_EQUAL_U32(S, 0xffffffff, 0x0f0f0f0f, 0xdeadbeef, 0xdeadbeef);
}

TEST_CASE(test6) {
  set_vregmax(10);
  set_vtype(0, V_UINT32);
  set_vtype(1, V_UINT32);
  set_vtype(10, V_UINT16);
  set_vl(4);

  volatile uint32_t S[4] = {0xdeadbeef, 0xdeadbeef, 0xdeadbeef, 0xdeadbeef};

  VEC_VLD_VREG_U32(0, 0xffffffff, 0x00ffff00, 0x0f0f0f0f, 0xf0f0f0f0);
  VEC_VLD_VREG_U32(1, 1, 0, 1, 0);
  VEC_VLD_VREG_U16(10, 0, 12, 4, 8);

  asm volatile ("vstx v0, 0(%0, v10), v1.f" : : "r" (S));

  VEC_EQUAL_U32(S, 0xdeadbeef, 0xdeadbeef, 0xf0f0f0f0, 0x00ffff00);
}

int main(void) {
  DECLARE_TEST(test1);
  DECLARE_TEST(test2);
  DECLARE_TEST(test3);
  DECLARE_TEST(test4);
  DECLARE_TEST(test5);
  DECLARE_TEST(test6);

  return run_all_tests();
}
