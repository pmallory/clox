#include <stdlib.h>

#include "chunk.h"
#include "memory.h"

void* reallocate(void* previous, size_t oldSize, size_t newSize) {
	//Supress gcc warnings
	(void)oldSize;

	return realloc(previous, newSize);
}
