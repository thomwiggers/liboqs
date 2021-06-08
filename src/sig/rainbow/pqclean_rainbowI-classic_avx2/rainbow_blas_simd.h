/// @file rainbow_blas_simd.h
///
///
#ifndef _RAINBOW_BLAS_SIMD_H_
#define _RAINBOW_BLAS_SIMD_H_

#include "blas_config.h"

#include "rainbow_config.h"

#ifndef _BLAS_AVX2_
error here.
#endif


#include "gf16_avx2.h"
#include "blas_avx2.h"
#include "blas_matrix_avx2.h"

#include "parallel_matrix_op_avx2.h"


#ifdef _USE_GF16

#define gfv_generate_multab            gf16v_generate_multab_sse
#define gfmat_prod_multab              PQCLEAN_RAINBOWICLASSIC_AVX2_gf16mat_prod_multab_avx2
#define batch_quad_trimat_eval_multab  PQCLEAN_RAINBOWICLASSIC_AVX2_batch_quad_trimat_eval_multab_gf16_avx2

#define batch_trimat_madd_multab    PQCLEAN_RAINBOWICLASSIC_AVX2_batch_trimat_madd_multab_gf16_avx2
#define batch_trimatTr_madd_multab  PQCLEAN_RAINBOWICLASSIC_AVX2_batch_trimatTr_madd_multab_gf16_avx2
#define batch_2trimat_madd_multab   PQCLEAN_RAINBOWICLASSIC_AVX2_batch_2trimat_madd_multab_gf16_avx2
#define batch_matTr_madd_multab     PQCLEAN_RAINBOWICLASSIC_AVX2_batch_matTr_madd_multab_gf16_avx2
#define batch_bmatTr_madd_multab    PQCLEAN_RAINBOWICLASSIC_AVX2_batch_bmatTr_madd_multab_gf16_avx2
#define batch_mat_madd_multab       PQCLEAN_RAINBOWICLASSIC_AVX2_batch_mat_madd_multab_gf16_avx2

#else

#define gfv_generate_multab            gf256v_generate_multab_sse
#define gfmat_prod_multab              PQCLEAN_RAINBOWICLASSIC_AVX2_gf256mat_prod_multab_avx2
#define batch_quad_trimat_eval_multab  PQCLEAN_RAINBOWICLASSIC_AVX2_batch_quad_trimat_eval_multab_gf256_avx2

#define batch_trimat_madd_multab    PQCLEAN_RAINBOWICLASSIC_AVX2_batch_trimat_madd_multab_gf256_avx2
#define batch_trimatTr_madd_multab  PQCLEAN_RAINBOWICLASSIC_AVX2_batch_trimatTr_madd_multab_gf256_avx2
#define batch_2trimat_madd_multab   PQCLEAN_RAINBOWICLASSIC_AVX2_batch_2trimat_madd_multab_gf256_avx2
#define batch_matTr_madd_multab     PQCLEAN_RAINBOWICLASSIC_AVX2_batch_matTr_madd_multab_gf256_avx2
#define batch_bmatTr_madd_multab    PQCLEAN_RAINBOWICLASSIC_AVX2_batch_bmatTr_madd_multab_gf256_avx2
#define batch_mat_madd_multab       PQCLEAN_RAINBOWICLASSIC_AVX2_batch_mat_madd_multab_gf256_avx2

#endif


#endif // _RAINBOW_BLAS_SIMD_H_


