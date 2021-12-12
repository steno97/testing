#include "vector_macros.h"
#include <stdio.h>

TEST_CASE(test1) {
  set_vregmax(1);
  set_vtype(0, V_UINT16);
  set_vtype(1, V_UINT16);
  set_vl(8);

  volatile const int32_t slamt = 2;

  VEC_VLD_VREG_U16(0, 0, 1, 2, 3, 4, 5, 6, 7);

  asm volatile ("vslide v1, v0, %0" : : "r" (slamt));
  VEC_CMP_U16(1, 2, 3, 4, 5, 6, 7, 0, 0);
}

TEST_CASE(test2) {
  set_vregmax(1);
  set_vtype(0, V_INT8);
  set_vtype(1, V_INT8);
  set_vl(4);

  volatile const int32_t slamt = 4;

  VEC_VLD_VREG_S8(0, -1, -2, -3, -4);

  asm volatile ("vslide v1, v0, %0" : : "r" (slamt));
  VEC_CMP_S8(1, 0, 0, 0, 0);
}

TEST_CASE(test3) {
  set_vregmax(1);
  set_vtype(0, V_INT32);
  set_vtype(1, V_INT32);
  set_vl(4);

  volatile const int32_t slamt = 32;

  VEC_VLD_VREG_S32(0, -1, -2, -3, -4);

  asm volatile ("vslide v1, v0, %0" : : "r" (slamt));
  VEC_CMP_S32(1, 0, 0, 0, 0);
}

TEST_CASE(test4) {
  set_vregmax(1);
  set_vtype(0, V_INT16);
  set_vl(8);

  volatile const int32_t slamt = 2;

  VEC_VLD_VREG_U16(0, 0, 1, 2, 3, 4, 5, 6, 7);

  asm volatile ("vslide v0, v0, %0" : : "r" (slamt));
  VEC_CMP_U16(0, 2, 3, 4, 5, 6, 7, 0, 0);
}

TEST_CASE(test5) {
  set_vregmax(1);
  set_vtype(0, V_UINT16);
  set_vtype(1, V_INT16);
  set_vl(8);

  volatile const int16_t slamt = 2;

  VEC_VLD_VREG_U16(0, 0, 1, 2, 3, 4, 5, 6, 7);
  VEC_VLD_VREG_S16(1, 0, 1, 0, 1, 0, 1, 0, 1);

  asm volatile ("vslide v0, v0, %0, v1.t" : : "r" (slamt));
  VEC_CMP_U16(0, 0, 3, 0, 5, 0, 7, 0, 0);
}

TEST_CASE(test6) {
  set_vregmax(1);
  set_vtype(0, V_UINT16);
  set_vtype(1, V_INT16);
  set_vl(8);

  volatile const int16_t slamt = 2;

  VEC_VLD_VREG_U16(0, 0, 1, 2, 3, 4, 5, 6, 7);
  VEC_VLD_VREG_S16(1, 0, 1, 0, 1, 0, 1, 0, 1);

  asm volatile ("vslide v0, v0, %0, v1.f" : : "r" (slamt));
  VEC_CMP_U16(0, 2, 0, 4, 0, 6, 0, 0, 0);
}

TEST_CASE(test7) {
  set_vregmax(1);
  set_vtype(0, V_UINT64);
  set_vtype(1, V_UINT64);
  set_vl(8);

  volatile const int32_t slamt = 2;

  VEC_VLD_VREG_U64(0, 0, 1, 2, 3, 4, 5, 6, 7);

  asm volatile ("vslide v1, v0, %0" : : "r" (slamt));
  VEC_CMP_U64(1, 2, 3, 4, 5, 6, 7, 0, 0);
}

TEST_CASE(test8) {
  set_vregmax(1);
  set_vtype(0, V_INT64);
  set_vtype(1, V_INT64);
  set_vl(4);

  volatile const int32_t slamt = 4;

  VEC_VLD_VREG_S64(0, -1, -2, -3, -4);

  asm volatile ("vslide v1, v0, %0" : : "r" (slamt));
  VEC_CMP_S64(1, 0, 0, 0, 0);
}

TEST_CASE(test9) {
  set_vregmax(1);
  set_vtype(0, V_INT64);
  set_vtype(1, V_INT64);
  set_vl(4);

  volatile const int32_t slamt = 64;

  VEC_VLD_VREG_S64(0, -1, -2, -3, -4);

  asm volatile ("vslide v1, v0, %0" : : "r" (slamt));
  VEC_CMP_S64(1, 0, 0, 0, 0);
}

TEST_CASE(test10) {
  set_vregmax(1);
  set_vtype(0, V_INT64);
  set_vl(8);

  volatile const int32_t slamt = 2;

  VEC_VLD_VREG_U64(0, 0, 1, 2, 3, 4, 5, 6, 7);

  asm volatile ("vslide v0, v0, %0" : : "r" (slamt));
  VEC_CMP_U64(0, 2, 3, 4, 5, 6, 7, 0, 0);
}

TEST_CASE(test11) {
  set_vregmax(1);
  set_vtype(0, V_UINT64);
  set_vtype(1, V_INT64);
  set_vl(8);

  volatile const int64_t slamt = 2;

  VEC_VLD_VREG_U64(0, 0, 1, 2, 3, 4, 5, 6, 7);
  VEC_VLD_VREG_S64(1, 0, 1, 0, 1, 0, 1, 0, 1);

  asm volatile ("vslide v0, v0, %0, v1.t" : : "r" (slamt));
  VEC_CMP_U64(0, 0, 3, 0, 5, 0, 7, 0, 0);
}

TEST_CASE(test12) {
  set_vregmax(1);
  set_vtype(0, V_UINT64);
  set_vtype(1, V_INT64);
  set_vl(8);

  volatile const int64_t slamt = 2;

  VEC_VLD_VREG_U64(0, 0, 1, 2, 3, 4, 5, 6, 7);
  VEC_VLD_VREG_S64(1, 0, 1, 0, 1, 0, 1, 0, 1);

  asm volatile ("vslide v0, v0, %0, v1.f" : : "r" (slamt));
  VEC_CMP_U64(0, 2, 0, 4, 0, 6, 0, 0, 0);
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
  DECLARE_TEST(test11);
  DECLARE_TEST(test12);

  return run_all_tests();
}
