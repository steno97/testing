#include "vector_macros.h"
#include <stdio.h>

TEST_CASE(test1) {
  set_vregmax(2);
  set_vtype(2, V_UINT32);
  set_vl(4);

  volatile uint32_t S[] = {0xffffffff, 0x00000000, 0x0f0f0f0f, 0xf0f0f0f0};

  MEMBARRIER;
  asm volatile ("vld v2, 0(%0)" : : "r" (S));

  VEC_CMP_U32(2, 0xffffffff, 0x00000000, 0x0f0f0f0f, 0xf0f0f0f0);
}

TEST_CASE(test2) {
  set_vregmax(2);
  set_vtype(2, V_UINT16);
  set_vl(3);

  volatile uint16_t S[] = {0xffff, 0x0000, 0x0f0f, 0xf0f0};

  MEMBARRIER;
  asm volatile ("vld v2, 1(%0)" : : "r" (S));

  VEC_CMP_U16(2, 0x0000, 0x0f0f, 0xf0f0);
}

TEST_CASE(test3) {
  set_vregmax(2);
  set_vtype(2, V_UINT8);
  set_vl(4);

  volatile uint8_t S[] = {0xff, 0x00, 0x0f, 0xf0};

  MEMBARRIER;
  asm volatile ("vld v2, -1(%0)" : : "r" (S+1));

  VEC_CMP_U8(2, 0xff, 0x00, 0x0f, 0xf0);
}

TEST_CASE(test4) {
  set_vregmax(2);
  set_vtype(2, V_UINT8);
  set_vl(8);

  volatile uint16_t S[] = {0xffff, 0x0000, 0x0ff0, 0xf00f};

  MEMBARRIER;
  asm volatile ("vld v2, 0(%0)" : : "r" (S));

  VEC_CMP_U8(2, 0xff, 0xff, 0x00, 0x00, 0xf0, 0x0f, 0x0f, 0xf0);
}

TEST_CASE(test5) {
  set_vregmax(2);
  set_vtype(2, S_UINT32);
  set_vl(4);

  volatile uint32_t S[] = {0xdeadbeef, 0xffff0000, 0x0f0f0f0f, 0xf0f0f0f0};

  MEMBARRIER;
  asm volatile ("vld v2, 0(%0)" : : "r" (S));

  VEC_CMP_U32(2, 0xdeadbeef,  0xdeadbeef,  0xdeadbeef,  0xdeadbeef);
}

TEST_CASE(test6) {
  set_vregmax(2);
  set_vtype(2, S_UINT8);
  set_vl(4);

  volatile uint16_t S[] = {0xbeef, 0xdead, 0x0f0f, 0xf0f0};

  MEMBARRIER;
  asm volatile ("vld v2, 0(%0)" : : "r" (S));

  VEC_CMP_U8(2, 0xef, 0xef, 0xef, 0xef);
}

TEST_CASE(test7) {
  set_vregmax(2);
  set_vtype(1, V_UINT16);
  set_vtype(2, V_UINT32);
  set_vl(4);

  volatile uint32_t S[] = {0xffffffff, 0x80000000, 0x0f0f0f0f, 0xf0f0f0f0};

  VEC_VLD_VREG_U16(1, 0x01, 0xf0, 0xff, 0xfe);

  MEMBARRIER;
  asm volatile ("vld v2, 0(%0), v1.t" : : "r" (S));

  VEC_CMP_U32(2, 0xffffffff, 0x00000000, 0x0f0f0f0f, 0x00000000);
}

TEST_CASE(test8) {
  set_vregmax(2);
  set_vtype(1, V_UINT16);
  set_vtype(2, V_UINT32);
  set_vl(4);

  volatile uint32_t S[] = {0xffffffff, 0x80000000, 0x0f0f0f0f, 0xf0f0f0f0};

  VEC_VLD_VREG_U16(1, 0x01, 0xf0, 0xff, 0xfe);

  MEMBARRIER;
  asm volatile ("vld v2, 0(%0), v1.f" : : "r" (S));

  VEC_CMP_U32(2, 0x00000000, 0x80000000, 0x00000000, 0xf0f0f0f0);
}

TEST_CASE(test9) {
  set_vregmax(2);
  set_vtype(2, S_UINT64);
  set_vl(4);

  volatile uint64_t S[] = {0xdeadbeefdeadbeef, 0xdeadbeefffff0000, 0xdeadbeef0f0f0f0f, 0xdeadbeeff0f0f0f0};

  MEMBARRIER;
  asm volatile ("vld v2, 0(%0)" : : "r" (S));

  VEC_CMP_U64(2, 0xdeadbeefdeadbeef,  0xdeadbeefdeadbeef,  0xdeadbeefdeadbeef,  0xdeadbeefdeadbeef);
}

TEST_CASE(test10) {
  set_vregmax(2);
  set_vtype(2, V_UINT64);
  set_vl(4);

  volatile uint64_t S[] = {0xdeadbeefdeadbeef, 0xdeadbeefffff0000, 0xdeadbeef0f0f0f0f, 0xdeadbeeff0f0f0f0};

  MEMBARRIER;
  asm volatile ("vld v2, 0(%0)" : : "r" (S));

  VEC_CMP_U64(2, 0xdeadbeefdeadbeef, 0xdeadbeefffff0000, 0xdeadbeef0f0f0f0f, 0xdeadbeeff0f0f0f0);
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

  return run_all_tests();
}
