#ifndef RANDOMBYTES_H
#define RANDOMBYTES_H

#include <oqs/rand.h>
#include <stddef.h>

static inline int randombytes(void* buf, size_t len) {
    OQS_randombytes(buf, len);
    return len;
}

#endif
