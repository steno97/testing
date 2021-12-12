#ifndef VEC_CSR_H
#define VEC_CSR_H

static inline unsigned int set_vl(unsigned int vl) {
  asm volatile ("vsetvl %0, %1\n" : "+r" (vl) : "r" (vl));
  return vl;
}

static inline void set_vregmax(unsigned int vregmax) {
  asm volatile ("csrw vregmax, %0\n" : : "r" (vregmax));
}

static inline uint64_t get_vcfg(const unsigned int vcfg) {
  if (vcfg > 14)
    return -1;

  uint64_t type;
  switch (vcfg) {
  case 0:   asm volatile ("csrr %0,  vcfg0\n" : "=r" (type)); break;
  case 2:   asm volatile ("csrr %0,  vcfg2\n" : "=r" (type)); break;
  case 4:   asm volatile ("csrr %0,  vcfg4\n" : "=r" (type)); break;
  case 6:   asm volatile ("csrr %0,  vcfg6\n" : "=r" (type)); break;
  case 8:   asm volatile ("csrr %0,  vcfg8\n" : "=r" (type)); break;
  case 10:  asm volatile ("csrr %0, vcfg10\n" : "=r" (type)); break;
  case 12:  asm volatile ("csrr %0, vcfg12\n" : "=r" (type)); break;
  case 14:  asm volatile ("csrr %0, vcfg14\n" : "=r" (type)); break;
  }

  return type;
}

static inline void set_vcfg(const unsigned int vcfg, const uint64_t type) {
  if (vcfg > 14)
    return;

  switch (vcfg) {
  case 0:   asm volatile ("csrw  vcfg0, %0\n" : : "r" (type)); break;
  case 2:   asm volatile ("csrw  vcfg2, %0\n" : : "r" (type)); break;
  case 4:   asm volatile ("csrw  vcfg4, %0\n" : : "r" (type)); break;
  case 6:   asm volatile ("csrw  vcfg6, %0\n" : : "r" (type)); break;
  case 8:   asm volatile ("csrw  vcfg8, %0\n" : : "r" (type)); break;
  case 10:  asm volatile ("csrw vcfg10, %0\n" : : "r" (type)); break;
  case 12:  asm volatile ("csrw vcfg12, %0\n" : : "r" (type)); break;
  case 14:  asm volatile ("csrw vcfg14, %0\n" : : "r" (type)); break;
  }
}

static inline uint16_t get_vtype(const unsigned int vt) {
  uint64_t vcfg = get_vcfg((vt >> 2) << 1);
  return (vcfg >> (16 * (vt % 4)) & 0xFFFF);
}

static inline void set_vtype(const unsigned int vt, const uint16_t type) {
  const uint64_t mask  = (uint64_t)0xFFFF << (16 * (vt % 4));
  uint64_t       vcfg = get_vcfg((vt >> 2) << 1);

  vcfg &= ~mask;
  vcfg |= (uint64_t)type << (16 * (vt % 4));
  set_vcfg((vt >> 2) << 1, vcfg);
}

unsigned int      set_vl(unsigned int      vl);
void         set_vregmax(unsigned int vregmax);

uint64_t get_vcfg(const unsigned int v);
void     set_vcfg(const unsigned int v, const uint64_t type);

uint16_t get_vtype(const unsigned int v);
void     set_vtype(const unsigned int v, const uint16_t type);

#endif
