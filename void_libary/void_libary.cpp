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
	int *ptr_a = static_cast < int*> (const_cast< void*>(a));
	int *ptr_b = static_cast < int*> (const_cast< void*>(b));

	return *ptr_a < *ptr_b;
}

bool cmp_equal_float( const void * a, const void * b)
{
	return static_cast<const float*>(a) == static_cast<const float*>(b);
}

bool cmp_big_than_float( const void * a, const void * b)
{
	return static_cast<const float*>(a) > static_cast<const float*>(b);
}

void* void_linear_search( void* first, void* last, size_t size, Compare cmp, void* ptr)
{
	byte * ptr_first = (byte*) first;
	byte * ptr_last = (byte*) last;
	byte *find = (byte*) ptr;

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

void* void_binary_search( const void *key, const void *ptr, size_t count, size_t size,Compare cmp_equal_byte)
{
	size_t left{0};
    size_t right{count-1};

	byte *A = (byte*) ptr;
 
 	while( left <= right )
    {
        size_t mid = (left+right)/2;

 		if ( not cmp_equal_byte( (A + mid*size) , key) and
             not cmp_equal_byte( key, (A + mid*size) ) ) // A[mid] == key
            return A + mid*size;
		else if  ( cmp_equal_byte( key, (A + mid*size))) right = mid-1; // go left
        else left = mid+1; // go left.
    }

	return nullptr;

}

const void * min ( const void *first , const void * last, size_t size, Compare cmp)
{
	//byte * true_first = static_cast< byte *> ( const_cast < void*> (first));
	//byte * true_last = static_cast< byte *> ( const_cast < void*> (last));
	//
	byte * true_first = (byte*) first;
	//
	byte * true_last = (byte*) last;
	byte * min = (byte*) first;

	if( true_first == nullptr) std::cout << "Empty Array \n";

	while( (true_first+size) != true_last){
		
		if( cmp_big_than_int(true_first,(true_first+size)) == true)
		{
			min = true_first;
		}

		true_first +=size;
	}	

	
	return min;
}

void reverse ( void * first, void * last, size_t size)
{
	byte * true_first = (byte*)first;
	byte * true_last = (byte*)last-size;
	byte * aux =  new byte[size] ;

	while( true_first < true_last )
	{
		std::memcpy( aux, true_first,size);
		std::memcpy( true_first, true_last,size);
		std::memcpy( true_last, aux,size);

		true_first+=size;
		true_last-=size;
	}

	delete [] aux;
}

void * copy ( const void * first, const void * last, const void * d_first, size_t size)
{
	byte *ptr_first = static_cast < byte*> (const_cast< void*>(first));
	byte *ptr_d_first = static_cast < byte*> (const_cast< void*>(d_first));

	while( ptr_first != last )
	{
		std::memcpy( ptr_d_first, ptr_first, size);
		ptr_first+=size;
		ptr_d_first+=size;
	}
	return ptr_d_first+size;
}

void * clone( const void * first, const void * last, size_t size)
{
	byte * true_first = (byte*) first;
	byte * true_last = (byte*) last;
	byte * new_first =  new byte[size];

	size_t new_size = size*(true_last - true_first);

	for ( size_t i = 0 ; i <= new_size ; i++)
	{
		std::memcpy( new_first+i, true_first+i,size);
	}

	return new_first;

}

int compare_ints( const void * aa, const void * bb )
{
    const int *a = static_cast< const int *> (aa);
    const int *b = static_cast< const int *> (bb);
    if ( *a < *b ) return -1;
    else if ( *a > *b ) return 1;
    else return 0;
}