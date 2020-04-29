#ifndef _HASH_H
#define _HASH_H

#include "arch.h"
#include "choice_crypto.h"
#include "parameters_HFE.h"
#include "predicate.h"
#include "init.h"


/******************************************************************/
/****************** Choice of the hash functions ******************/
/******************************************************************/


/* Choice of the hash function */
/* The user is allowed to switch between SHA2 and SHA3 */
#define CHOICE_HASH_SHA3

/******************************************************************/
/******************** Enable the hash functions *******************/
/******************************************************************/


/* Use of third libraries */
/* The user is allowed to switch between OpenSSL and XKCP */
/* The user can define several macros, while several SHA3 are not defined
   (if several SHA3 are defined, XKCP has priority). */
#define ENABLED_SHA3_XKCP


#define ENABLED_SHAKE_XKCP
/* #define ENABLED_TUPLEHASH_XKCP XXX Disabled XXX */


/******************************************************************/
/***************** Include for the hash functions *****************/
/******************************************************************/


/* We minimize the numbers of #include to decrease the dependencies with the
   third libraries. */
#if (defined(ENABLED_SHA1_OPENSSL)||defined(ENABLED_SHA2_OPENSSL))
    #include <openssl/sha.h>
#endif


#ifdef ENABLED_SHA2_OPENSSL
    #include "randombytes.h"

    #if ENABLED_OPENSSL_FIPS
        #include <openssl/err.h>
        #include <openssl/crypto.h>
    #endif
#endif


#ifdef ENABLED_SHA3_OPENSSL
    #include <stddef.h>
    #include "prefix_name.h"
    int PREFIX_NAME(sha3_256)(unsigned char *output, const unsigned char *m,
                                                     size_t len);
    int PREFIX_NAME(sha3_384)(unsigned char *output, const unsigned char *m,
                                                     size_t len);
    int PREFIX_NAME(sha3_512)(unsigned char *output, const unsigned char *m,
                                                     size_t len);
    #define sha3_256 PREFIX_NAME(sha3_256)
    #define sha3_384 PREFIX_NAME(sha3_384)
    #define sha3_512 PREFIX_NAME(sha3_512)
#endif


#if (defined(ENABLED_SHA3_XKCP)||defined(ENABLED_SHAKE_XKCP))
    BEGIN_EXTERNC
        #include "fips202.h"
    END_EXTERNC
#endif


#ifdef ENABLED_SHAKE_XKCP
    BEGIN_EXTERNC
        #include "fips202.h"
    END_EXTERNC
#endif


#ifdef ENABLED_TUPLEHASH_XKCP
    BEGIN_EXTERNC
        #include "sp800-185.h"
    END_EXTERNC
#endif


/******************************************************************/
/**************** Macro to call the hash functions ****************/
/******************************************************************/


    /* SHA3_* is inlined from SimpleFIPS202.c */
#define SHA3_256_XKCP(output,m,len) sha3_256(output, m, len)
#define SHA3_384_XKCP(output,m,len) sha3_384(output, m, len)
#define SHA3_512_XKCP(output,m,len) sha3_512(output, m, len)

/* SHAKE* is inlined from SimpleFIPS202.c */
#define SHAKE128_XKCP(output,outputByteLen,m,len) shake128(output, outputByteLen, m, len)
#define SHAKE256_XKCP(output,outputByteLen,m,len) shake256(output, outputByteLen, m, len

/* To call with:
        Keccak_HashInstance hashInstance;
        Keccak_HashIUF_SHAKE*_XKCP(&hashInstance,data,databitlen);
   And after a call to Keccak_HashIUF_SHAKE*_XKCP, to use one or several times:
        Keccak_HashSqueeze(&hashInstance,output,outputbitlen);
  XXX Here, length in bits XXX
*/
#define Keccak_HashIUF_SHAKE128_XKCP(hashInstance,data,databitlen) \
        shake128_absorb(hashInstance, data, (databitlen)/8);
#define Keccak_HashIUF_SHAKE256_XKCP(hashInstance,data,databitlen) \
        shake256_absorb(hashInstance, data, (databitlen)/8);


#define TUPLEHASH128_XKCP TupleHash128
#define TUPLEHASH256_XKCP TupleHash256


/************************************************************************/
/* Macro to call the hash functions corresponding to the security level */
/************************************************************************/


/* Choice of the hash function */
#if (K<=128)
    #if ENABLED_OPENSSL_FIPS
        #define SHA2 SHA256_OPENSSL_FIPS
    #else
        #define SHA2 SHA256_OPENSSL
    #endif

    #ifdef ENABLED_SHA3_XKCP
        #define SHA3 SHA3_256_XKCP
    #elif defined(ENABLED_SHA3_OPENSSL)
        #define SHA3 sha3_256
    #endif
#elif (K<=192)
    #if ENABLED_OPENSSL_FIPS
        #define SHA2 SHA384_OPENSSL_FIPS
    #else
        #define SHA2 SHA384_OPENSSL
    #endif

    #ifdef ENABLED_SHA3_XKCP
        #define SHA3 SHA3_384_XKCP
    #elif defined(ENABLED_SHA3_OPENSSL)
        #define SHA3 sha3_384
    #endif
#else
    #if ENABLED_OPENSSL_FIPS
        #define SHA2 SHA512_OPENSSL_FIPS
    #else
        #define SHA2 SHA512_OPENSSL
    #endif

    #ifdef ENABLED_SHA3_XKCP
        #define SHA3 SHA3_512_XKCP
    #elif defined(ENABLED_SHA3_OPENSSL)
        #define SHA3 sha3_512
    #endif
#endif


/* Choice of SHAKE and TupleHash */
#if (K<=128)
    #define expandSeedCxtDeclaration shake128ctx hashInstance
    #define SHAKE SHAKE128_XKCP
    #define Keccak_HashIUF_SHAKE Keccak_HashIUF_SHAKE128_XKCP
    #define TUPLEHASH TUPLEHASH128_XKCP
#else
    #define expandSeedCxtDeclaration shake256ctx hashInstance
    #define SHAKE SHAKE256_XKCP
    #define Keccak_HashIUF_SHAKE Keccak_HashIUF_SHAKE256_XKCP
    #define TUPLEHASH TUPLEHASH256_XKCP
#endif


/******************************************************************/
/******** Macro to call the chosen hash function of MQsoft ********/
/******************************************************************/


#ifdef CHOICE_HASH_SHA1
    #define HASH SHA1
#elif defined(CHOICE_HASH_SHA2)
    #define HASH SHA2
#else
    #define HASH SHA3
#endif


/******************************************************************/
/************************** Other tools ***************************/
/******************************************************************/


BEGIN_EXTERNC
    /* For KeccakWidth1600_Sponge */
END_EXTERNC


#if (K<=80)
    #define SIZE_DIGEST 20
    #define SIZE_DIGEST_UINT 3
#elif (K<=128)
    #define SIZE_DIGEST 32
    #define SIZE_DIGEST_UINT 4
    #define SIZE_2_DIGEST 64
    #define EQUALHASH_NOCST ISEQUAL4_NOCST
    #define COPYHASH COPY4
#elif (K<=192)
    #define SIZE_DIGEST 48
    #define SIZE_DIGEST_UINT 6
    #define SIZE_2_DIGEST 96
    #define EQUALHASH_NOCST ISEQUAL6_NOCST
    #define COPYHASH COPY6
#else
    #define SIZE_DIGEST 64
    #define SIZE_DIGEST_UINT 8
    #define SIZE_2_DIGEST 128
    #define EQUALHASH_NOCST ISEQUAL8_NOCST
    #define COPYHASH COPY8
#endif


#define EQUALHASH(a,b) f_ISEQUAL(a,b,SIZE_DIGEST_UINT)


/* XXX Bytes XXX */
#define expandSeed(output,outputByteLen,seed,seedByteLen) \
        SHAKE(output,outputByteLen,seed,seedByteLen)

#define expandSeedIUF Keccak_HashIUF_SHAKE
#define expandSeedSqueeze Keccak_HashSqueeze


#endif

