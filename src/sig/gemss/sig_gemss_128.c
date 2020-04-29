#include <stdlib.h>

#include <oqs/sig_gemss.h>

#if defined(OQS_ENABLE_SIG_gemss_128)

OQS_SIG *OQS_SIG_gemss_128_new() {

	OQS_SIG *sig = malloc(sizeof(OQS_SIG));
	if (sig == NULL) {
		return NULL;
	}
	sig->method_name = OQS_SIG_alg_gemss_128;
	sig->alg_version = "SUPERCOP GeMMS v2";

	sig->claimed_nist_level = 1;
	sig->euf_cma = true;

	sig->length_public_key = OQS_SIG_gemss_128_length_public_key;
	sig->length_secret_key = OQS_SIG_gemss_128_length_secret_key;
	sig->length_signature = OQS_SIG_gemss_128_length_signature;

	sig->keypair = OQS_SIG_gemss_128_keypair;
	sig->sign = OQS_SIG_gemss_128_sign;
	sig->verify = OQS_SIG_gemss_128_verify;

	return sig;
}

int PQCLEAN_GEMSS128_AVX2_crypto_sign_keypair(uint8_t *pk, uint8_t *sk);
int PQCLEAN_GEMSS128_AVX2_crypto_sign_signature(uint8_t *sig, size_t *siglen, const uint8_t *m, size_t mlen, const uint8_t *sk);
int PQCLEAN_GEMSS128_AVX2_crypto_sign_verify(const uint8_t *sig, size_t siglen, const uint8_t *m, size_t mlen, const uint8_t *pk);

OQS_API OQS_STATUS OQS_SIG_gemss_128_keypair(uint8_t *public_key, uint8_t *secret_key) {
	return (OQS_STATUS) PQCLEAN_GEMSS128_AVX2_crypto_sign_keypair(public_key, secret_key);
}

OQS_API OQS_STATUS OQS_SIG_gemss_128_sign(uint8_t *signature, size_t *signature_len, const uint8_t *message, size_t message_len, const uint8_t *secret_key) {
	return (OQS_STATUS) PQCLEAN_GEMSS128_AVX2_crypto_sign_signature(signature, signature_len, message, message_len, secret_key);
}

OQS_API OQS_STATUS OQS_SIG_gemss_128_verify(const uint8_t *message, size_t message_len, const uint8_t *signature, size_t signature_len, const uint8_t *public_key) {
	return (OQS_STATUS) PQCLEAN_GEMSS128_AVX2_crypto_sign_verify(signature, signature_len, message, message_len, public_key);
}

#endif
