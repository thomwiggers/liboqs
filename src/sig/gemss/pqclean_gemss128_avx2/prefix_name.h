#ifndef _PREFIX_NAME_H
#define _PREFIX_NAME_H



/** This macro permits to prefix the name of all functions with the name of the
 *  current cryptosystem. */
/* For example, if you use GeMSS with a level of security 128 bits, 
   PREFIX_NAME(function) will generate GeMSS_128U_function. */
#define PREFIX_NAME(name) PQCLEAN_GEMSS128_AVX2_##name


#endif

