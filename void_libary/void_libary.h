#include <iostream>
#include <cstring>

using byte = unsigned char;
using Compare = (bool*) ( int * , int*);
using Predicate = (bool*) ( const void*);

bool cmp_equal_char( const void * a, const void * b);

bool cmp_equal_byte( const void * a, const void * b);

bool cmp_big_than_byte( const void * a, const void * b);

bool cmp_equa_int( const void * a, const void * b);

bool cmp_big_than_int( const void * a, const void * b);

bool cmp_equal_float( const void * a, const void * b);

bool cmp_big_than_float( const void * a, const void * b);

void* void_linear_search( void* first, void* last, size_t size, Compare cmp, void* x);

void* void_binary_search( const void *key, const void *ptr, size_t count, size_t size,Compare cmp_equal_byte);

const void * min ( const void *first , const void * last, size_t size, Compare cmp);

void reverse ( void * first, void * last, size_t size);

void * copy ( const void * first, const void * last, const void * d_first, size_t size);

void * clone( const void * first, const void * last, size_t size);

int compare_ints( const void * aa, const void * bb );
