#include "vector_macros.h"
#include <stdio.h>

TEST_CASE(test1) {
  set_vregmax(2);
  set_vtype(0, V_UINT64);
  set_vtype(2, V_UINT64);
  set_vl(4);

  VEC_VLD_VREG_U64(0, 0xff00ff00ff00ff00, 0x0ff00ff00ff00ff0, 0x00ff00ff00ff00ff, 0xf00ff00ff00ff00f);

  asm volatile ("vxori v2,-16(v0)"); //0xf0
  VEC_CMP_U64(2, 0x00ff00ff00ff00f0, 0xf00ff00ff00ff000, 0xff00ff00ff00ff0f, 0x0ff00ff00ff00fff);
}

TEST_CASE(test2) {
  set_vregmax(2);
  set_vtype(0, V_UINT32);
  set_vtype(2, V_UINT32);
  set_vl(4);

  VEC_VLD_VREG_U32(0, 0xff00ff00, 0x0ff00ff0, 0x00ff00ff, 0xf00ff00f);

  asm volatile ("vxori v2,15(v0)"); //0x0f
  VEC_CMP_U32(2, 0xff00ff0f, 0x0ff00fff, 0x00ff00f0, 0xf00ff000);
}

TEST_CASE(test3) {
  set_vregmax(1);
  set_vtype(0, V_UINT32);
  set_vl(4);

  VEC_VLD_VREG_U32(0, 0xff00ff00, 0x0ff00ff0, 0x00ff00ff, 0xf00ff00f);

  asm volatile ("vxori v0,-16(v0)"); //0xf0
  VEC_CMP_U32(0, 0x00ff00f0, 0xf00ff000, 0xff00ff0f, 0x0ff00fff);
}

TEST_CASE(test4) {
  set_vregmax(2);
  set_vtype(0, V_UINT32);
  set_vtype(1, V_UINT16);
  set_vtype(2, V_UINT32);
  set_vl(4);

  VEC_VLD_VREG_U32(0, 0xff00ff00, 0x0ff00ff0, 0x00ff00ff, 0xf00ff00f);
  VEC_VLD_VREG_U16(1, 1, 0, 1, 0);

  asm volatile ("vxori v2,-16(v0),v1.t"); //0xf0
  VEC_CMP_U32(2, 0x00ff00f0, 0x00000000, 0xff00ff0f, 0x00000000);
}

TEST_CASE(test5) {
  set_vregmax(2);
  set_vtype(0, V_UINT32);
  set_vtype(1, V_UINT16);
  set_vtype(2, V_UINT32);
  set_vl(4);

  VEC_VLD_VREG_U32(0, 0xff00ff00, 0x0ff00ff0, 0x00ff00ff, 0xf00ff00f);
  VEC_VLD_VREG_U16(1, 1, 0, 1, 0);

  asm volatile ("vxori v2,-16(v0),v1.f"); //0xf0
  VEC_CMP_U32(2, 0x00000000, 0xf00ff000, 0x00000000, 0x0ff00fff);
}

TEST_CASE(test6) {
  set_vregmax(2);
  set_vtype(0, V_UINT16);
  set_vtype(2, V_UINT16);
  set_vl(2);

  VEC_VLD_VREG_U16(0, 0xf0f0, 0x0f0f);

  asm volatile ("vxori v2,-16(v0)"); //0xf0
  VEC_CMP_U16(2, 0x0f00, 0xf0ff);
}

TEST_CASE(test7) {
  set_vregmax(2);
  set_vtype(0, V_UINT16);
  set_vtype(2, V_UINT16);
  set_vl(2);

  VEC_VLD_VREG_U16(0, 0xf0f0, 0x0f0f);

  asm volatile ("vxori v2,15(v0)"); //0x0f
  VEC_CMP_U16(2, 0xf0ff, 0x0f00);
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
