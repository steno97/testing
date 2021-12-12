#include "vector_macros.h"
#include <stdio.h>

TEST_CASE(test1) {
  set_vregmax(1);
  set_vtype(0, V_UINT64);
  set_vl(4);

  volatile uint64_t S[4] = {0xdeadbeef, 0xdeadbeef, 0xdeadbeef, 0xdeadbeef};
  volatile uint32_t stride = 8;

  VEC_VLD_VREG_U64(0, 0xffffffffffffffff, 0x0000000000000000, 0x0f0f0f0f0f0f0f0f, 0xf0f0f0f0f0f0f0f0);

  asm volatile ("vsts v0, 0(%0, %1)" : : "r" (S), "r" (stride));

  VEC_EQUAL_U64(S, 0xffffffffffffffff, 0x0000000000000000, 0x0f0f0f0f0f0f0f0f, 0xf0f0f0f0f0f0f0f0);
}

TEST_CASE(test2) {
  set_vregmax(1);
  set_vtype(0, V_UINT16);
  set_vl(2);

  volatile uint16_t S[4] = {0xdead, 0xbeef, 0xdead, 0xbeef};
  volatile uint32_t stride = 4;

  VEC_VLD_VREG_U16(0, 0xffff, 0x0000);

  asm volatile ("vsts v0, 0(%0, %1)" : : "r" (S), "r" (stride));

  VEC_EQUAL_U16(S, 0xffff, 0xbeef, 0x0000, 0xbeef);
}

TEST_CASE(test3) {
  set_vregmax(1);
  set_vtype(0, V_UINT32);
  set_vl(4);

  volatile uint32_t S[4] = {0xdeadbeef, 0xdeadbeef, 0xdeadbeef, 0xdeadbeef};
  volatile uint32_t stride = -4;

  VEC_VLD_VREG_U32(0, 0xffffffff, 0x00000000, 0x0f0f0f0f, 0xf0f0f0f0);

  asm volatile ("vsts v0, 3(%0, %1)" : : "r" (S), "r" (stride));

  VEC_EQUAL_U32(S, 0xf0f0f0f0, 0x0f0f0f0f, 0x00000000, 0xffffffff);
}

TEST_CASE(test4) {
  set_vregmax(1);
  set_vtype(0, V_UINT16);
  set_vl(4);

  volatile uint16_t S[4] = {0xdead, 0xbeef, 0xdead, 0xbeef};
  volatile uint32_t stride = -2;

  VEC_VLD_VREG_U16(0, 0xffff, 0x0000, 0x0f0f, 0xf0f0);

  asm volatile ("vsts v0, 3(%0, %1)" : : "r" (S), "r" (stride));

  VEC_EQUAL_U16(S, 0xf0f0, 0x0f0f, 0x0000, 0xffff);
}

TEST_CASE(test5) {
  set_vregmax(1);
  set_vtype(0, V_UINT32);
  set_vtype(1, V_UINT32);
  set_vl(4);

  volatile uint32_t S[4] = {0xdeadbeef, 0xdeadbeef, 0xdeadbeef, 0xdeadbeef};
  volatile uint32_t stride = 4;

  VEC_VLD_VREG_U32(0, 0xffffffff, 0x00ffff00, 0x0f0f0f0f, 0xf0f0f0f0);
  VEC_VLD_VREG_U32(1, 1, 0, 1, 0);

  asm volatile ("vsts v0, 0(%0, %1), v1.t" : : "r" (S), "r" (stride));

  VEC_EQUAL_U32(S, 0xffffffff, 0xdeadbeef, 0x0f0f0f0f, 0xdeadbeef);
}

TEST_CASE(test6) {
  set_vregmax(1);
  set_vtype(0, V_UINT32);
  set_vtype(1, V_UINT32);
  set_vl(4);

  volatile uint32_t S[4] = {0xdeadbeef, 0xdeadbeef, 0xdeadbeef, 0xdeadbeef};
  volatile uint32_t stride = 4;

  VEC_VLD_VREG_U32(0, 0xffffffff, 0x00ffff00, 0x0f0f0f0f, 0xf0f0f0f0);
  VEC_VLD_VREG_U32(1, 1, 0, 1, 0);

  asm volatile ("vsts v0, 0(%0, %1), v1.f" : : "r" (S), "r" (stride));

  VEC_EQUAL_U32(S, 0xdeadbeef, 0x00ffff00, 0xdeadbeef, 0xf0f0f0f0);
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
