#include "vector_macros.h"
#include <stdio.h>

TEST_CASE(test1) {
  set_vregmax(2);
  set_vtype(0, V_UINT32);
  set_vtype(2, V_UINT32);
  set_vl(3);

  VEC_VLD_VREG_U32(0, 0x00000001, 0xffffffff, 0x21212121);

  asm volatile ("vsli v2, 0(v0)");
  VEC_CMP_U32(2, 0x00000001, 0xffffffff, 0x21212121);
}

TEST_CASE(test2) {
  set_vregmax(2);
  set_vtype(0, V_UINT32);
  set_vtype(2, V_UINT32);
  set_vl(3);

  VEC_VLD_VREG_U32(0, 0x00000001, 0xffffffff, 0x21212121);

  asm volatile ("vsli v2, 1(v0)");
  VEC_CMP_U32(2, 0x00000002, 0xfffffffe, 0x42424242);
}

TEST_CASE(test3) {
  set_vregmax(2);
  set_vtype(0, V_UINT32);
  set_vtype(2, V_UINT32);
  set_vl(3);

  VEC_VLD_VREG_U32(0, 0x00000001, 0xffffffff, 0x21212121);

  asm volatile ("vsli v2, 7(v0)");
  VEC_CMP_U32(2, 0x00000080, 0xffffff80, 0x90909080);
}

TEST_CASE(test4) {
  set_vregmax(2);
  set_vtype(0, V_UINT32);
  set_vtype(2, V_UINT32);
  set_vl(3);

  VEC_VLD_VREG_U32(0, 0x00000001, 0xffffffff, 0x21212121);

  asm volatile ("vsli v2, 14(v0)");
  VEC_CMP_U32(2, 0x00004000, 0xffffc000, 0x48484000);
}

TEST_CASE(test5) {
  set_vregmax(2);
  set_vtype(0, V_UINT32);
  set_vtype(2, V_UINT32);
  set_vl(3);

  VEC_VLD_VREG_U32(0, 0x00000001, 0xffffffff, 0x21212121);

  asm volatile ("vsli v2, 31(v0)");
  VEC_CMP_U32(2, 0x80000000, 0x80000000, 0x80000000);
}

TEST_CASE(test6) {
  set_vregmax(1);
  set_vtype(0, V_UINT32);
  set_vl(3);

  VEC_VLD_VREG_U32(0, 0x00000001, 0xffffffff, 0x21212121);

  asm volatile ("vsli v0, 14(v0)");
  VEC_CMP_U32(0, 0x00004000, 0xffffc000, 0x48484000);
}

TEST_CASE(test7) {
  set_vregmax(2);
  set_vtype(0, V_UINT16);
  set_vtype(2, V_UINT16);
  set_vl(3);

  VEC_VLD_VREG_U16(0, 0x0001, 0xffff, 0x2121);

  asm volatile ("vsli v2, 7(v0)");
  VEC_CMP_U16(2, 0x0080, 0xff80, 0x9080);
}

TEST_CASE(test8) {
  set_vregmax(2);
  set_vtype(0, V_UINT16);
  set_vtype(2, V_UINT16);
  set_vl(3);

  VEC_VLD_VREG_U16(0, 0x0001, 0xffff, 0x2121);

  asm volatile ("vsli v2, 14(v0)");
  VEC_CMP_U16(2, 0x4000, 0xc000, 0x4000);
}

TEST_CASE(test9) {
  set_vregmax(2);
  set_vtype(0, V_UINT32);
  set_vtype(1, V_INT16);
  set_vtype(2, V_UINT32);
  set_vl(3);

  VEC_VLD_VREG_U32(0, 0x00000001, 0xffffffff, 0x21212121);
  VEC_VLD_VREG_S16(1, 0xff, 0xfe, 0x01);

  asm volatile ("vsli v2, 0(v0), v1.t");
  VEC_CMP_U32(2, 0x00000001, 0x00000000, 0x21212121);
}

TEST_CASE(test10) {
  set_vregmax(2);
  set_vtype(0, V_UINT32);
  set_vtype(1, V_INT16);
  set_vtype(2, V_UINT32);
  set_vl(3);

  VEC_VLD_VREG_U32(0, 0x00000001, 0xffffffff, 0x21212121);
  VEC_VLD_VREG_S16(1, 0xff, 0xfe, 0x01);

  asm volatile ("vsli v2, 1(v0), v1.f");
  VEC_CMP_U32(2, 0x00000000, 0xfffffffe, 0x00000000);
}

TEST_CASE(test11) {
  set_vregmax(2);
  set_vtype(0, V_UINT64);
  set_vtype(1, V_INT32);
  set_vtype(2, V_UINT64);
  set_vl(3);

  VEC_VLD_VREG_U64(0, 0x00000001, 0xffffffff, 0x21212121);
  VEC_VLD_VREG_S32(1, 0xff, 0xfe, 0x01);

  asm volatile ("vsli v2, 1(v0), v1.f");
  VEC_CMP_U64(2, 0x0000000000000000, 0x1fffffffe, 0x0000000000000000);
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

  return run_all_tests();
}
