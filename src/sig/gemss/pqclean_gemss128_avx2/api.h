#ifndef PQCLEAN_GEMSS128_AVX2_API_H
#define PQCLEAN_GEMSS128_AVX2_API_H

#include <stdint.h>
#include <stddef.h>

/** Size of the secret-key in bytes. */
#define PQCLEAN_GEMSS128_AVX2_CRYPTO_SECRETKEYBYTES 13438

/** Size of the public-key in bytes. */
#define PQCLEAN_GEMSS128_AVX2_CRYPTO_PUBLICKEYBYTES 352188
/** Size of the signature (without the document) in bytes. */
#define PQCLEAN_GEMSS128_AVX2_CRYPTO_BYTES 33

#define PQCLEAN_GEMSS128_AVX2_CRYPTO_ALGNAME "GeMSS128"


int PQCLEAN_GEMSS128_AVX2_crypto_sign_keypair(uint8_t *pk, uint8_t *sk);

int PQCLEAN_GEMSS128_AVX2_crypto_sign(uint8_t *sm, size_t *smlen,
                         const uint8_t *m, size_t mlen,
                         const uint8_t *sk);

int PQCLEAN_GEMSS128_AVX2_crypto_sign_open(uint8_t *m, size_t *mlen,
                              const uint8_t *sm, size_t smlen,
                              const uint8_t *pk);


int PQCLEAN_GEMSS128_AVX2_crypto_sign_signature(
    uint8_t *sig, size_t *siglen,
    const uint8_t *m, size_t mlen, const uint8_t *sk);

int PQCLEAN_GEMSS128_AVX2_crypto_sign_verify(
    const uint8_t *sig, size_t siglen,
    const uint8_t *m, size_t mlen, const uint8_t *pk);




#endif

