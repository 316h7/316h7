
#include <stdlib.h>
#include <stdlib.h>
#include <string.h>

#ifndef MSORT_H
#define MSORT_H
void msort(void* base, size_t num, size_t size, int (*compar)(const void*, const void*));
#endif
