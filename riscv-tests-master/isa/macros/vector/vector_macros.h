#ifndef  __VECTOR_MACROS_H__
#define  __VECTOR_MACROS_H__

#include <stdio.h>
#include "dataset.h"
#include "veccfg.h"
#include "vecconstants.h"

#define TEST_OK 0
#define TEST_KO 1
#define MAX_NUM_TESTS 64

#ifdef __VERBOSE__
#define VPRINTF(args...) fprintf(stderr, args);
#else
#define VPRINTF(args...)
#endif

#define MEMBARRIER                              \
  do {                                          \
  asm volatile ("fence");                       \
  } while (0)

#define VEC_EQUAL(T, A, Bv...)                                  \
  do {                                                          \
    MEMBARRIER;                                                 \
    T B[] = {Bv};                                               \
    int cmp = TEST_OK;                                          \
    for (unsigned int i = 0; i < sizeof(B)/sizeof(T); ++i)      \
      if (A[i] != B[i]) {                                       \
        VPRINTF("%d: Got %016lX Exp %016lX\n", i, A[i], B[i]);  \
        cmp = TEST_KO;                                          \
      }                                                         \
    set_vregmax(0);                                             \
    return cmp;                                                 \
  } while(0)

#define SCA_EQUAL(A, B)                                         \
  do {                                                          \
    MEMBARRIER;                                                 \
    int cmp = TEST_OK;                                          \
    if (A != B) {                                               \
      VPRINTF("Got %016lX Exp %016lX\n", A, B);                 \
      cmp = TEST_KO;                                            \
    }                                                           \
    set_vregmax(0);                                             \
    return cmp;                                                 \
  } while(0)

#define VEC_SET(T, A, Bv...)                                            \
  do {                                                                  \
    T B[]                                                       = {Bv}; \
    for (unsigned int i = 0; i < sizeof(B)/sizeof(T); ++i) A[i] = B[i]; \
    MEMBARRIER;                                                         \
  } while(0)

#define VEC_VLD(T, vr, A, Av...)                                \
  do {                                                          \
    VEC_SET(T, A, Av);                                          \
    asm volatile ("vld v" #vr ", %0\n" : : "r" (A));            \
  } while(0)

#define VEC_VST(T, vr, A)                                             \
  do {                                                                \
    T* A ##_t = (T*) A;                                               \
    asm volatile ("vst v" #vr ", %0\n" : "+r" (A ##_t) :);            \
  } while(0)

int numTests = 0;
int (*tests[MAX_NUM_TESTS]) (void); // Pointers to the tests

#define TEST_CASE(name) int name(void)
#define DECLARE_TEST(name)                      \
  tests[numTests++] = name

int run_all_tests(void) {
  for (unsigned int t = 0; t < numTests; ++t) {
    VPRINTF("Running test %d...\n", t + 1);
      if (tests[t]() == TEST_KO) {
          VPRINTF("Error in test %d.\n", t + 1);
          return TEST_KO;
        }
    }
  VPRINTF("Everything ok.\n");
  return TEST_OK;
}

#define VEC_EQUAL_U64(A, Bv...) VEC_EQUAL(uint64_t, A, Bv)
#define VEC_EQUAL_U32(A, Bv...) VEC_EQUAL(uint32_t, A, Bv)
#define VEC_EQUAL_U16(A, Bv...) VEC_EQUAL(uint16_t, A, Bv)
#define VEC_EQUAL_U8(A, Bv...)  VEC_EQUAL(uint8_t, A, Bv)

#define VEC_EQUAL_S64(A, Bv...) VEC_EQUAL(int64_t, A, Bv)
#define VEC_EQUAL_S32(A, Bv...) VEC_EQUAL(int32_t, A, Bv)
#define VEC_EQUAL_S16(A, Bv...) VEC_EQUAL(int16_t, A, Bv)
#define VEC_EQUAL_S8(A, Bv...)  VEC_EQUAL(int8_t, A, Bv)

#define VEC_EQUAL_F64(A, Bv...) VEC_EQUAL(uint64_t, A, Bv)
#define VEC_EQUAL_F32(A, Bv...) VEC_EQUAL(uint32_t, A, Bv)
#define VEC_EQUAL_F16(A, Bv...) VEC_EQUAL(uint16_t, A, Bv)

#define VEC_SET_U64(A, Bv...) VEC_SET(uint64_t, A, Bv)
#define VEC_SET_U32(A, Bv...) VEC_SET(uint32_t, A, Bv)
#define VEC_SET_U16(A, Bv...) VEC_SET(uint16_t, A, Bv)
#define VEC_SET_U8(A, Bv...)  VEC_SET(uint8_t, A, Bv)

#define VEC_SET_S64(A, Bv...) VEC_SET(int64_t, A, Bv)
#define VEC_SET_S32(A, Bv...) VEC_SET(int32_t, A, Bv)
#define VEC_SET_S16(A, Bv...) VEC_SET(int16_t, A, Bv)
#define VEC_SET_S8(A, Bv...)  VEC_SET(int8_t, A, Bv)

#define VEC_SET_F64(A, Bv...) VEC_SET(uint64_t, A, Bv)
#define VEC_SET_F32(A, Bv...) VEC_SET(uint32_t, A, Bv)
#define VEC_SET_F16(A, Bv...) VEC_SET(uint16_t, A, Bv)

#define VEC_VLD_VREG_U64(vr, Av...) {VEC_VLD(uint64_t, vr, Au64, Av);}
#define VEC_VLD_VREG_U32(vr, Av...) {VEC_VLD(uint32_t, vr, Au32, Av);}
#define VEC_VLD_VREG_U16(vr, Av...) {VEC_VLD(uint16_t, vr, Au16, Av);}
#define VEC_VLD_VREG_U8(vr, Av...)  {VEC_VLD(uint8_t, vr, Au8, Av);}

#define VEC_VLD_VREG_S64(vr, Av...) {VEC_VLD(int64_t, vr, As64, Av);}
#define VEC_VLD_VREG_S32(vr, Av...) {VEC_VLD(int32_t, vr, As32, Av);}
#define VEC_VLD_VREG_S16(vr, Av...) {VEC_VLD(int16_t, vr, As16, Av);}
#define VEC_VLD_VREG_S8(vr, Av...)  {VEC_VLD(int8_t, vr, As8, Av);}

#define VEC_VLD_VREG_F64(vr, Av...) {VEC_VLD(uint64_t, vr, Af64, Av);}
#define VEC_VLD_VREG_F32(vr, Av...) {VEC_VLD(uint32_t, vr, Af32, Av);}
#define VEC_VLD_VREG_F16(vr, Av...) {VEC_VLD(uint16_t, vr, Af16, Av);}

#define SCA_VLD_VREG_U64(vr, Av) {VEC_VLD(uint64_t, vr, Au64, Av);}
#define SCA_VLD_VREG_U32(vr, Av) {VEC_VLD(uint32_t, vr, Au32, Av);}
#define SCA_VLD_VREG_U16(vr, Av) {VEC_VLD(uint16_t, vr, Au16, Av);}
#define SCA_VLD_VREG_U8(vr, Av)  {VEC_VLD(uint8_t, vr, Au8, Av);}

#define SCA_VLD_VREG_S64(vr, Av) {VEC_VLD(int64_t, vr, As64, Av);}
#define SCA_VLD_VREG_S32(vr, Av) {VEC_VLD(int32_t, vr, As32, Av);}
#define SCA_VLD_VREG_S16(vr, Av) {VEC_VLD(int16_t, vr, As16, Av);}
#define SCA_VLD_VREG_S8(vr, Av)  {VEC_VLD(int8_t, vr, As8, Av);}

#define SCA_VLD_VREG_F64(vr, Av) {VEC_VLD(uint64_t, vr, Af64, Av);}
#define SCA_VLD_VREG_F32(vr, Av) {VEC_VLD(uint32_t, vr, Af32, Av);}
#define SCA_VLD_VREG_F16(vr, Av) {VEC_VLD(uint16_t, vr, Af16, Av);}

#define VEC_VST_VREG_U64(vr) {VEC_VST(uint64_t, vr, Ru64);}
#define VEC_VST_VREG_U32(vr) {VEC_VST(uint32_t, vr, Ru32);}
#define VEC_VST_VREG_U16(vr) {VEC_VST(uint16_t, vr, Ru16);}
#define VEC_VST_VREG_U8(vr)  {VEC_VST(uint8_t, vr, Ru8);}

#define VEC_VST_VREG_S64(vr) {VEC_VST(int64_t, vr, Rs64);}
#define VEC_VST_VREG_S32(vr) {VEC_VST(int32_t, vr, Rs32);}
#define VEC_VST_VREG_S16(vr) {VEC_VST(int16_t, vr, Rs16);}
#define VEC_VST_VREG_S8(vr)  {VEC_VST(int8_t, vr, Rs8);}

#define VEC_VST_VREG_F64(vr) {VEC_VST(uint64_t, vr, Rf64);}
#define VEC_VST_VREG_F32(vr) {VEC_VST(uint32_t, vr, Rf32);}
#define VEC_VST_VREG_F16(vr) {VEC_VST(uint16_t, vr, Rf16);}

#define VEC_CMP_U64(vr, val...) {VEC_VST_VREG_U64(vr); VEC_EQUAL_U64(Ru64, val);}
#define VEC_CMP_U32(vr, val...) {VEC_VST_VREG_U32(vr); VEC_EQUAL_U32(Ru32, val);}
#define VEC_CMP_U16(vr, val...) {VEC_VST_VREG_U16(vr); VEC_EQUAL_U16(Ru16, val);}
#define VEC_CMP_U8(vr, val...)  {VEC_VST_VREG_U8(vr); VEC_EQUAL_U8(Ru8, val);}

#define VEC_CMP_S64(vr, val...) {VEC_VST_VREG_S64(vr); VEC_EQUAL_S64(Rs64, val);}
#define VEC_CMP_S32(vr, val...) {VEC_VST_VREG_S32(vr); VEC_EQUAL_S32(Rs32, val);}
#define VEC_CMP_S16(vr, val...) {VEC_VST_VREG_S16(vr); VEC_EQUAL_S16(Rs16, val);}
#define VEC_CMP_S8(vr, val...)  {VEC_VST_VREG_S8(vr); VEC_EQUAL_S8(Rs8, val);}

#define VEC_CMP_F64(vr, val...) {VEC_VST_VREG_F64(vr); VEC_EQUAL_F64(Rf64, val);}
#define VEC_CMP_F32(vr, val...) {VEC_VST_VREG_F32(vr); VEC_EQUAL_F32(Rf32, val);}
#define VEC_CMP_F16(vr, val...) {VEC_VST_VREG_F16(vr); VEC_EQUAL_F16(Rf16, val);}


/* Float conversions */

typedef union {
  uint64_t i;
  uint16_t h;
  float    f;
  double   d;
} v_fconv;

static inline v_fconv _i(uint64_t i) {
  v_fconv r;
  r.i   = i;
  return  r;
}

static inline v_fconv _h(float f) {
  /* Source (modified): https://github.com/numpy/numpy/blob/master/numpy/core/src/npymath/halffloat.c */
  v_fconv r;
  r.f = f;

  uint32_t f_exp, f_sig;
  uint16_t h_sgn, h_exp, h_sig;

  h_sgn = (uint16_t) ((r.i&0x80000000u) >> 16);
  f_exp = (r.i&0x7f800000u);

  /* Exponent overflow/NaN converts to signed inf/NaN */
  if (f_exp >= 0x47800000u) {
    if (f_exp == 0x7f800000u) {
      /* Inf or NaN */
      f_sig = (r.i&0x007fffffu);
      if (f_sig != 0) {
        /* NaN - propagate the flag in the significand... */
        uint16_t ret = (uint16_t) (0x7c00u + (f_sig >> 13));
        /* ...but make sure it stays a NaN */
        if (ret == 0x7c00u) {
          ret++;
        }
        r.i = (uint16_t) h_sgn + ret;
        return r;
      } else {
        /* signed inf */
        r.i = (uint16_t) (h_sgn + 0x7c00u);
        return r;
      }
    } else {
      r.i = (uint16_t) (h_sgn + 0x7c00u);
      return r;
    }
  }

  /* Exponent underflow converts to a subnormal half or signed zero */
  if (f_exp <= 0x38000000u) {
    /*
     * Signed zeros, subnormal floats, and floats with small
     * exponents all convert to signed zero half-floats.
     */
    if (f_exp < 0x33000000u) {
      r.i = h_sgn;
      return r;
    }
    /* Make the subnormal significand */
    f_exp >>= 23;
    f_sig = (0x00800000u + (r.i&0x007fffffu));
    f_sig >>= (113 - f_exp);
    f_sig += 0x00001000u;
    h_sig = (uint16_t) (f_sig >> 13);
    /*
     * If the rounding causes a bit to spill into h_exp, it will
     * increment h_exp from zero to one and h_sig will be zero.
     * This is the correct result.
     */
    r.i = (uint16_t) (h_sgn + h_sig);
    return r;
  }

  /* Regular case with no overflow or underflow */
  h_exp = (uint16_t) ((f_exp - 0x38000000u) >> 13);
  /* Handle rounding by adding 1 to the bit beyond half precision */
  f_sig = (r.i&0x007fffffu);
  f_sig += 0x00001000u;
  h_sig = (uint16_t) (f_sig >> 13);
  r.i = (uint16_t) h_sgn + h_exp + h_sig;
  return  r;
}

static inline v_fconv _f(float f) {
  v_fconv r;
  r.f   = f;
  return  r;
}

static inline v_fconv _d(double d) {
  v_fconv r;
  r.d   = d;
  return  r;
}

#endif //__VECTOR_MACROS_H__
