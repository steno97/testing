#include "vector_macros.h"
#include <stdio.h>

TEST_CASE(test1) {
  set_vregmax(2);
  set_vtype(2, V_UINT64);
  set_vl(5);

  VEC_VLD_VREG_U64(2, 0x000000000000000, 0x0000000000000001, 0x0000000000000007, 0xFFFFFFFFFFFFFFFD, 0xFFFFFFFFFFFFFFFF);

  volatile uint64_t res;
  volatile uint64_t ind = 0;

  asm volatile ("vext %[res], v2, %[ind]" : [res] "=r" (res) : [ind] "r" (ind));

  SCA_EQUAL(res, 0);
}

TEST_CASE(test2) {
  set_vregmax(2);
  set_vtype(2, V_UINT64);
  set_vl(5);

  VEC_VLD_VREG_U64(2, 0x000000000000000, 0x0000000000000001, 0x0000000000000007, 0xFFFFFFFFFFFFFFFD, 0xFFFFFFFFFFFFFFFF);

  volatile uint64_t res;
  volatile uint64_t ind = 1;

  asm volatile ("vext %[res], v2, %[ind]" : [res] "=r" (res) : [ind] "r" (ind));

  SCA_EQUAL(res, 1);
}

TEST_CASE(test3) {
  set_vregmax(2);
  set_vtype(2, V_UINT64);
  set_vl(5);

  VEC_VLD_VREG_U64(2, 0x000000000000000, 0x0000000000000001, 0x0000000000000007, 0xFFFFFFFFFFFFFFFD, 0xFFFFFFFFFFFFFFFF);

  volatile uint64_t res;
  volatile uint64_t ind = 3;

  asm volatile ("vext %[res], v2, %[ind]" : [res] "=r" (res) : [ind] "r" (ind));

  SCA_EQUAL(res, 0xFFFFFFFFFFFFFFFD);
}

TEST_CASE(test4) {
  set_vregmax(2);
  set_vtype(2, V_UINT64);
  set_vl(5);

  VEC_VLD_VREG_U64(2, 0x000000000000000, 0x0000000000000001, 0x0000000000000007, 0xFFFFFFFFFFFFFFFD, 0xFFFFFFFFFFFFFFFF);

  volatile uint64_t res;
  volatile uint64_t ind = 4;

  asm volatile ("vext %[res], v2, %[ind]" : [res] "=r" (res) : [ind] "r" (ind));

  SCA_EQUAL(res, 0xFFFFFFFFFFFFFFFF);
}

TEST_CASE(test5) {
  set_vregmax(2);
  set_vtype(2, V_INT32);
  set_vl(5);

  VEC_VLD_VREG_S32(2, 0x00000000, 0x00000001, 0x00000007, 0xFFFFFFFD, 0xFFFFFFFF);

  volatile uint64_t res;
  volatile uint64_t ind = 0;

  asm volatile ("vext %[res], v2, %[ind]" : [res] "=r" (res) : [ind] "r" (ind));

  SCA_EQUAL(res, 0);
}

TEST_CASE(test6) {
  set_vregmax(2);
  set_vtype(2, V_INT32);
  set_vl(5);

  VEC_VLD_VREG_S32(2, 0x00000000, 0x00000001, 0x00000007, 0xFFFFFFFD, 0xFFFFFFFF);

  volatile uint64_t res;
  volatile uint64_t ind = 1;

  asm volatile ("vext %[res], v2, %[ind]" : [res] "=r" (res) : [ind] "r" (ind));

  SCA_EQUAL(res, 1);
}

TEST_CASE(test7) {
  set_vregmax(2);
  set_vtype(2, V_INT32);
  set_vl(5);

  VEC_VLD_VREG_S32(2, 0x00000000, 0x00000001, 0x00000007, 0xFFFFFFFD, 0xFFFFFFFF);

  volatile uint64_t res;
  volatile uint64_t ind = 3;

  asm volatile ("vext %[res], v2, %[ind]" : [res] "=r" (res) : [ind] "r" (ind));

  SCA_EQUAL(res, 0xFFFFFFFD);
}

TEST_CASE(test8) {
  set_vregmax(2);
  set_vtype(2, V_INT32);
  set_vl(5);

  VEC_VLD_VREG_S32(2, 0x00000000, 0x00000001, 0x00000007, 0xFFFFFFFD, 0xFFFFFFFF);

  volatile uint64_t res;
  volatile uint64_t ind = 4;

  asm volatile ("vext %[res], v2, %[ind]" : [res] "=r" (res) : [ind] "r" (ind));

  SCA_EQUAL(res, 0xFFFFFFFF);
}

TEST_CASE(test9) {
  set_vregmax(2);
  set_vtype(2, V_INT16);
  set_vl(5);

  VEC_VLD_VREG_S16(2, 0x0000, 0x0001, 0x0007, 0xFFFD, 0xFFFF);

  volatile uint64_t res;
  volatile uint64_t ind = 3;

  asm volatile ("vext %[res], v2, %[ind]" : [res] "=r" (res) : [ind] "r" (ind));

  SCA_EQUAL(res, 0xFFFD);
}

TEST_CASE(test10) {
  set_vregmax(2);
  set_vtype(2, V_INT8);
  set_vl(5);

  VEC_VLD_VREG_S8(2, 0x00, 0x01, 0x07, 0xFD, 0xFF);

  volatile uint64_t res;
  volatile uint64_t ind = 4;

  asm volatile ("vext %[res], v2, %[ind]" : [res] "=r" (res) : [ind] "r" (ind));

  SCA_EQUAL(res, 0xFF);
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
