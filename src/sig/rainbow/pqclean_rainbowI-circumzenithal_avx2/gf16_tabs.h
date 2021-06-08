/// @file gf16_tabs.h
/// @brief Defining the constant tables for performing GF arithmetics.
///

#ifndef _GF16_TABS_H_
#define _GF16_TABS_H_

#include <stdint.h>

//IF_CRYPTO_CORE:define CRYPTO_NAMESPACE

#ifdef  __cplusplus
extern  "C" {
#endif

extern const unsigned char PQCLEAN_RAINBOWICIRCUMZENITHAL_AVX2___mask_0x55[];
extern const unsigned char PQCLEAN_RAINBOWICIRCUMZENITHAL_AVX2___mask_low[];
extern const unsigned char PQCLEAN_RAINBOWICIRCUMZENITHAL_AVX2___mask_16[];
extern const unsigned char PQCLEAN_RAINBOWICIRCUMZENITHAL_AVX2___gf16_inv[];
extern const unsigned char PQCLEAN_RAINBOWICIRCUMZENITHAL_AVX2___gf16_squ[];
extern const unsigned char PQCLEAN_RAINBOWICIRCUMZENITHAL_AVX2___gf16_squ_x8[];
extern const unsigned char PQCLEAN_RAINBOWICIRCUMZENITHAL_AVX2___gf16_squ_sl4[];
extern const unsigned char PQCLEAN_RAINBOWICIRCUMZENITHAL_AVX2___gf16_exp[];
extern const char PQCLEAN_RAINBOWICIRCUMZENITHAL_AVX2___gf16_log[];
#define __gf16_mul PQCLEAN_RAINBOWICIRCUMZENITHAL_AVX2___gf16_mul_
extern const unsigned char * __gf16_mul;
extern const unsigned char PQCLEAN_RAINBOWICIRCUMZENITHAL_AVX2___gf256_mul[];
extern const unsigned char PQCLEAN_RAINBOWICIRCUMZENITHAL_AVX2___gf16_mulx2[];


#ifdef  __cplusplus
}
#endif



#endif // _GF16_TABS_H_
