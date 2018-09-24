#include "../include/graal.h"
#include <iostream>


bool cmp ( const void * a, const void * b)
{
	int *ptr_a = static_cast < int*> (a);
	int *ptr_b = static_cast < int*> (b);

	return *ptr_a < *ptr_b;
}

const void * min ( const void *first , const void * last, size_t size, Compare cmp)
{
	byte * true_first = static_cast< byte *> ( const_cast < void*> (first));
	byte * true_last = static_cast< byte *> ( const_cast < void*> (last));
	byte * min;

	if( true_first == nullptr) std::cout << "Empty Array \n";

	while( (true_first+size) != true_last){
		
		if( !(cmp(*true_first,*(true_first+size))))
		{
			min = true_first+size;
		}

		true_first +=size;
	}	

	return (const_cast< const void*>(min));
}