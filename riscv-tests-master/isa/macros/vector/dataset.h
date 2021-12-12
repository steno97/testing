#ifndef   __DATASET_H__
#define   __DATASET_H__

#define SIZE 8

static volatile uint64_t Au64[SIZE] __attribute__ ((aligned (64)));
static volatile uint32_t Au32[SIZE] __attribute__ ((aligned (64)));
static volatile uint16_t Au16[SIZE] __attribute__ ((aligned (64)));
static volatile uint8_t  Au8 [SIZE] __attribute__ ((aligned (64)));
static volatile int64_t  As64[SIZE] __attribute__ ((aligned (64)));
static volatile int32_t  As32[SIZE] __attribute__ ((aligned (64)));
static volatile int16_t  As16[SIZE] __attribute__ ((aligned (64)));
static volatile int8_t   As8 [SIZE] __attribute__ ((aligned (64)));
static volatile uint64_t Af64[SIZE] __attribute__ ((aligned (64)));
static volatile uint32_t Af32[SIZE] __attribute__ ((aligned (64)));
static volatile uint16_t Af16[SIZE] __attribute__ ((aligned (64)));

static volatile uint64_t Ru64[SIZE] __attribute__ ((aligned (64)));
static volatile uint32_t Ru32[SIZE] __attribute__ ((aligned (64)));
static volatile uint16_t Ru16[SIZE] __attribute__ ((aligned (64)));
static volatile uint8_t  Ru8 [SIZE] __attribute__ ((aligned (64)));
static volatile int64_t  Rs64[SIZE] __attribute__ ((aligned (64)));
static volatile int32_t  Rs32[SIZE] __attribute__ ((aligned (64)));
static volatile int16_t  Rs16[SIZE] __attribute__ ((aligned (64)));
static volatile int8_t   Rs8 [SIZE] __attribute__ ((aligned (64)));
static volatile uint64_t Rf64[SIZE] __attribute__ ((aligned (64)));
static volatile uint32_t Rf32[SIZE] __attribute__ ((aligned (64)));
static volatile uint16_t Rf16[SIZE] __attribute__ ((aligned (64)));

#undef SIZE

#endif // __DATASET__H__
