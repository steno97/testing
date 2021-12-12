#include "vector_macros.h"
#include <stdio.h>

TEST_CASE(test1) {
  set_vregmax(1);
  set_vtype(1, V_UINT32);
  set_vl(5);

  volatile uint32_t res;

  VEC_VLD_VREG_U32(1, 0x00000000, 0x00000001, 0x00000007, 0xFFFFFFFE, 0xFFFFFFFF);

  asm volatile ("vmpop %[res], v1.t" : [res] "=r" (res));

  SCA_EQUAL(res, 3);
}

TEST_CASE(test2) {
  set_vregmax(1);
  set_vtype(1, V_UINT16);
  set_vl(5);

  volatile uint32_t res;

  VEC_VLD_VREG_U16(1, 0x0000, 0x0001, 0x0007, 0xFFFE, 0xFFFF);

  asm volatile ("vmpop %[res], v1.t" : [res] "=r" (res));

  SCA_EQUAL(res, 3);
}

TEST_CASE(test3) {
  set_vregmax(1);
  set_vtype(1, V_UINT8);
  set_vl(5);

  volatile uint32_t res;

  VEC_VLD_VREG_U8(1, 0, 1, 0, 1, 0)

  asm volatile ("vmpop %[res]" : [res] "=r" (res));

  SCA_EQUAL(res, 5);
}

TEST_CASE(test4) {
  set_vregmax(1);
  set_vtype(1, V_UINT8);
  set_vl(5);

  volatile uint32_t res;

  VEC_VLD_VREG_U8(1, 0, 1, 0, 1, 0)

  asm volatile ("vmpop %[res], v1.f" : [res] "=r" (res));

  SCA_EQUAL(res, 3);
}

TEST_CASE(test5) {
  set_vregmax(1);
  set_vtype(1, V_UINT8);
  set_vl(6);

  volatile uint32_t res;

  VEC_VLD_VREG_U8(1, 0, 1, 0, 1, 0, 1)

  asm volatile ("vmpop %[res]" : [res] "=r" (res));

  SCA_EQUAL(res, 6);
}

TEST_CASE(test6) {
  set_vregmax(1);
  set_vtype(1, V_UINT8);
  set_vl(5);

  volatile uint32_t res;

  VEC_VLD_VREG_U8(1, 0, 1, 0, 1, 0)

  asm volatile ("vmpop %[res], v1.t" : [res] "=r" (res));

  SCA_EQUAL(res, 2);
}

TEST_CASE(test7) {
  set_vregmax(1);
  set_vtype(1, V_UINT32);
  set_vl(5);

  volatile uint32_t res;

  VEC_VLD_VREG_U32(1, 0, 1, 0, 1, 0)

  asm volatile ("vmpop %[res], v1.f" : [res] "=r" (res));

  SCA_EQUAL(res, 3);
}

int main(void) {
  DECLARE_TEST(test1);
  DECLARE_TEST(test2);
  DECLARE_TEST(test3);
  DECLARE_TEST(test4);
  DECLARE_TEST(test5);
  DECLARE_TEST(test6);
  DECLARE_TEST(test7);

  return run_all_tests();
}
