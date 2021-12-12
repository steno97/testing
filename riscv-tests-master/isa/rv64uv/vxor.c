#include "vector_macros.h"
#include <stdio.h>

TEST_CASE(test1) {
  set_vregmax(2);
  set_vtype(0, V_UINT64);
  set_vtype(1, V_UINT64);
  set_vtype(2, V_UINT64);
  set_vl(4);

  VEC_VLD_VREG_U64(0, 0xff00ff00ff00ff00, 0x0ff00ff00ff00ff0, 0x00ff00ff00ff00ff, 0xf00ff00ff00ff00f);
  VEC_VLD_VREG_U64(1, 0x0f0f0f0f0f0f0f0f, 0xf0f0f0f0f0f0f0f0, 0x0f0f0f0f0f0f0f0f, 0xf0f0f0f0f0f0f0f0);

  asm volatile ("vxor v2, v0, v1");
  VEC_CMP_U64(2, 0xf00ff00ff00ff00f, 0xff00ff00ff00ff00, 0x0ff00ff00ff00ff0, 0x00ff00ff00ff00ff);
}

TEST_CASE(test2) {
  set_vregmax(1);
  set_vtype(0, V_UINT32);
  set_vtype(1, V_UINT32);
  set_vl(1);

  VEC_VLD_VREG_U32(0, 0xff00ff00);
  VEC_VLD_VREG_U32(1, 0x0f0f0f0f);

  asm volatile ("vxor v0, v0, v1");
  VEC_CMP_U32(0, 0xf00ff00f);
}

TEST_CASE(test3) {
  set_vregmax(1);
  set_vtype(0, V_UINT64);
  set_vtype(1, V_UINT64);
  set_vl(1);

  VEC_VLD_VREG_U32(0, 0xf0f0f0f0);
  VEC_VLD_VREG_U32(1, 0x0ff00ff0);

  asm volatile ("vxor v1, v0, v1");
  VEC_CMP_U32(1, 0xff00ff00);
}

TEST_CASE(test4) {
  set_vregmax(1);
  set_vtype(0, V_UINT32);
  set_vl(1);

  VEC_VLD_VREG_U32(0, 0xff00ff00);

  asm volatile ("vxor v0, v0, v0");
  VEC_CMP_U32(0, 0x00000000);
}

TEST_CASE(test5) {
  set_vregmax(3);
  set_vtype(0, V_UINT32);
  set_vtype(1, V_UINT32);
  set_vtype(2, V_UINT32);
  set_vtype(3, V_UINT16);
  set_vl(4);

  VEC_VLD_VREG_U32(1, 0x01, 0xf0, 0xff, 0x07);
  VEC_VLD_VREG_U32(2, 0xff00ff00, 0x0ff00ff0, 0x00ff00ff, 0xf00ff00f);
  VEC_VLD_VREG_U16(3, 0x0f0f, 0xf0f0, 0x0f0f, 0xf0f0);

  asm volatile ("vxor v0, v2, v3, v1.t");
  VEC_CMP_U32(0, 0xff00f00f, 0x00000000, 0x00ff0ff0, 0xf00f00ff);
}

TEST_CASE(test6) {
  set_vregmax(3);
  set_vtype(0, V_UINT32);
  set_vtype(1, V_UINT32);
  set_vtype(2, V_UINT32);
  set_vtype(3, V_UINT16);
  set_vl(4);

  VEC_VLD_VREG_U32(1, 0x01, 0xf0, 0xff, 0x07);
  VEC_VLD_VREG_U32(2, 0xff00ff00, 0x0ff00ff0, 0x00ff00ff, 0xf00ff00f);
  VEC_VLD_VREG_U16(3, 0x0f0f, 0xf0f0, 0x0f0f, 0xf0f0);

  asm volatile ("vxor v0, v2, v3, v1.f");
  VEC_CMP_U32(0, 0x00000000, 0x0ff0ff00, 0x00000000, 0x00000000);
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
