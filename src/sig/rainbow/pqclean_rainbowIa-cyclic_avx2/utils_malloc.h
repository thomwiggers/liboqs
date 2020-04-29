/// @file utils_malloc.h
/// @brief the interface for adapting malloc functions.
///
///

#ifndef _UTILS_MALLOC_H_
#define _UTILS_MALLOC_H_
#define _POSIX_C_SOURCE 200112L


#include <stdlib.h>


#if !defined( _ALIGN_ )
#if defined(__GNUC__) || defined(__clang__)
#define _ALIGN_(x)  __attribute__((aligned(x)))
#elif defined(_MSC_VER)
#define _ALIGN_(x)  __declspec(align(x))
#else
#define _ALIGN_(x)
#endif
#endif



#if defined(_ISOC11_SOURCE)
#define _HAS_ALIGNED_ALLOC_
#elif defined(_POSIX_C_SOURCE) && _POSIX_C_SOURCE >= 200112L
#define _HAS_POSIX_MEMALIGN_
#endif




static inline
void* adapted_alloc( size_t alignment, size_t size ) {
#if defined(_HAS_ALIGNED_ALLOC_)
    return aligned_alloc( alignment, size );
#elif defined(_HAS_POSIX_MEMALIGN_)
    void* retaddr;
    posix_memalign(&retaddr, alignment, size);
    return retaddr;
#else
    (void)alignment;
    return malloc( size );
#endif
}






#endif // _UTILS_MALLOC_H_


