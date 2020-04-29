#ifndef OQS_SIG_GEMSS_H
#define OQS_SIG_GEMSS_H

#include <oqs/oqs.h>

#ifdef OQS_ENABLE_SIG_gemss_128
#define OQS_SIG_gemss_128_length_public_key 352188
#define OQS_SIG_gemss_128_length_secret_key 13438
#define OQS_SIG_gemss_128_length_signature 33

OQS_SIG *OQS_SIG_gemss_128_new(void);
OQS_API OQS_STATUS OQS_SIG_gemss_128_keypair(uint8_t *public_key, uint8_t *secret_key);
OQS_API OQS_STATUS OQS_SIG_gemss_128_sign(uint8_t *signature, size_t *signature_len, const uint8_t *message, size_t message_len, const uint8_t *secret_key);
OQS_API OQS_STATUS OQS_SIG_gemss_128_verify(const uint8_t *message, size_t message_len, const uint8_t *signature, size_t signature_len, const uint8_t *public_key);
#endif

#endif
