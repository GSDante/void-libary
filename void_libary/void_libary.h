#include <iostream>
#include <cstring>

using byte = unsigned char;
using Compare = (bool*) ( int * , int*);

bool cmp_equal_char( const void * a, const void * b);

bool cmp_equal_byte( const void * a, const void * b);

bool cmp_big_than_byte( const void * a, const void * b);

bool cmp_equa_int( const void * a, const void * b);

bool cmp_big_than_int( const void * a, const void * b);

bool cmp_equal_float( const void * a, const void * b);

bool cmp_big_than_float( const void * a, const void * b);

void* void_linear_search( void* first, void* last, size_t size, Compare cmp, void* x);

void void_swap( void* a, void * b, size_t size);
