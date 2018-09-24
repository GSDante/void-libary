#include <iostream> 
#include "../include/void_libary.h"

bool cmp_equal_char( const void * a, const void * b)
{
	return static_cast<const char*>(a) == static_cast<const char*>(b);
}

bool cmp_equal_byte( const void * a, const void * b)
{
	return static_cast<const byte*>(a) == static_cast<const byte*>(b);
}

bool cmp_big_than_byte( const void * a, const void * b)
{
	return static_cast<const byte*>(a) > static_cast<const byte*>(b);
}

bool cmp_equa_int( const void * a, const void * b)
{
	return static_cast<const int*>(a) == static_cast<const int*>(b);
}

bool cmp_big_than_int( const void * a, const void * b)
{
	return static_cast<const int*>(a) > static_cast<const int*>(b);
}

bool cmp_equal_float( const void * a, const void * b)
{
	return static_cast<const float*>(a) == static_cast<const float*>(b);
}

bool cmp_big_than_float( const void * a, const void * b)
{
	return static_cast<const float*>(a) > static_cast<const float*>(b);
}

void* void_linear_search( void* first, void* last, size_t size, Compare cmp, void* x)
{
	byte * ptr_first = (byte*) first;
	byte * ptr_last = (byte*) last;
	byte *find = (byte*) x;

	while ( ptr_first != ptr_last)
	{
		if(cmp_equal(ptr_first,find) == true)
		{
			return ptr_first;
		}
		ptr_first+= size;
	}

	return nullptr;
}

void void_swap( void* a, void * b, size_t size)
{
	byte * aux[size];

	std::memmcpy( aux, a, size);
	std::memmcpy( a, b , size);
	std::memmcpy( b, aux, size);

	delete [] aux;
}