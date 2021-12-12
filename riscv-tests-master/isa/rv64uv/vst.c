#include "vector_macros.h"
#include <stdio.h>

TEST_CASE(test1) {
  set_vregmax(1);
  set_vtype(0, V_UINT64);
  set_vl(4);

  volatile uint64_t S[4] = {0xdeadbeef, 0xdeadbeef, 0xdeadbeef, 0xdeadbeef};

  VEC_VLD_VREG_U64(0, 0xffffffffffffffff, 0x0000000000000000, 0x0f0f0f0f0f0f0f0f, 0xf0f0f0f0f0f0f0f0);

  asm volatile ("vst v0, 0(%0)" : : "r" (S));

  VEC_EQUAL_U64(S, 0xffffffffffffffff, 0x0000000000000000, 0x0f0f0f0f0f0f0f0f, 0xf0f0f0f0f0f0f0f0);
}

TEST_CASE(test2) {
  set_vregmax(1);
  set_vtype(0, V_UINT16);
  set_vl(4);

  volatile uint16_t S[4] = {0xdead, 0xbeef, 0xdead, 0xbeef};

  VEC_VLD_VREG_U16(0, 0xffff, 0x0000, 0x0f0f, 0xf0f0);

  asm volatile ("vst v0, 0(%0)" : : "r" (S));

  VEC_EQUAL_U16(S, 0xffff, 0x0000, 0x0f0f, 0xf0f0);
}

TEST_CASE(test3) {
  set_vregmax(1);
  set_vtype(0, V_UINT8);
  set_vl(4);

  volatile uint8_t S[8] = {0xde, 0xad, 0xbe, 0xef, 0xde, 0xad, 0xbe, 0xef};

  VEC_VLD_VREG_U8(0, 0xff, 0x00, 0x0f, 0xf0);

  asm volatile ("vst v0, 0(%0)" : : "r" (S));

  VEC_EQUAL_U8(S, 0xff, 0x00, 0x0f, 0xf0, 0xde, 0xad, 0xbe, 0xef);
}

TEST_CASE(test4) {
  set_vregmax(1);
  set_vtype(0, V_UINT8);
  set_vl(4);

  volatile uint16_t S[] = {0xdead, 0xbeef, 0xdead, 0xbeef};

  VEC_VLD_VREG_U8(0, 0x00, 0x0f, 0xf0, 0xff);

  asm volatile ("vst v0, 2(%0)" : : "r" (S));

  VEC_EQUAL_U16(S, 0xdead, 0x0f00, 0xfff0, 0xbeef);
}

TEST_CASE(test5) {
  set_vregmax(1);
  set_vtype(0, S_UINT32);
  set_vl(3);

  volatile uint32_t S[] = {0xdeadbeef, 0xffff0000, 0x0f0f0f0f, 0xf0f0f0f0};

  SCA_VLD_VREG_U32(0, 0xbeefffff);

  asm volatile ("vst v0, 0(%0)" : : "r" (S));

  VEC_EQUAL_U32(S, 0xbeefffff, 0xbeefffff, 0xbeefffff, 0xf0f0f0f0);
}

TEST_CASE(test6) {
  set_vregmax(1);
  set_vtype(0, S_UINT16);
  set_vl(4);

  volatile uint32_t S[] = {0xdeadbeef, 0xffff0000, 0x0f0f0f0f, 0xf0f0f0f0};

  SCA_VLD_VREG_U16(0, 0xc0c0);

  asm volatile ("vst v0, 1(%0)" : : "r" (S));

  VEC_EQUAL_U32(S, 0xc0c0beef, 0xc0c0c0c0, 0x0f0fc0c0, 0xf0f0f0f0);
}

TEST_CASE(test7) {
  set_vregmax(1);
  set_vtype(0, V_UINT16);
  set_vtype(1, V_UINT8);
  set_vl(4);

  volatile uint16_t S[4] = {0xdead, 0xbeef, 0xdead, 0xbeef};

  VEC_VLD_VREG_U16(0, 0xffff, 0x0ff0, 0x0f0f, 0xf0f0);
  VEC_VLD_VREG_U8(1, 1, 0, 1, 0);

  asm volatile ("vst v0, 0(%0), v1.t" : : "r" (S));

  VEC_EQUAL_U16(S, 0xffff, 0xbeef, 0x0f0f, 0xbeef);
}

TEST_CASE(test8) {
  set_vregmax(1);
  set_vtype(0, V_UINT16);
  set_vtype(1, V_UINT8);
  set_vl(4);

  volatile uint16_t S[4] = {0xdead, 0xbeef, 0xdead, 0xbeef};

  VEC_VLD_VREG_U16(0, 0xffff, 0x0ff0, 0x0f0f, 0xf0f0);
  VEC_VLD_VREG_U8(1, 1, 0, 1, 0);

  asm volatile ("vst v0, 0(%0), v1.f" : : "r" (S));

  VEC_EQUAL_U16(S, 0xdead, 0x0ff0, 0xdead, 0xf0f0);
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
