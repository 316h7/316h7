
#include "mergesort.h"
#include <stdlib.h>
#include <string.h>
#include<stddef.h>

 void mergesort(void* source, void* temp,size_t size, size_t offset, size_t nmemb, int (*compar)(const void*, const void*)) 
{
    if (nmemb < 2) 
    {
        return;
    }

    size_t mid = nmemb/2; // /2

    mergesort(temp, 
                   source, 
                   size, 
                   offset, 
                   mid,
                   compar);

    mergesort(temp, 
                   source, 
                   size, 
                   offset + mid, 
                   nmemb - mid,
                   compar);

    void* l_start_ = source + offset * size;
    void* l_end_ = l_start_ + mid * size;

    void* r_start_ = l_end_;
    void* r_end_ = source + (offset + nmemb) * size;

    void* temp_arr_ = temp + offset * size;

    while (l_start_ < l_end_ && r_start_ < r_end_) 
    {
        if (compar(r_start_, l_start_) < 0)
        {
            memcpy(temp_arr_, r_start_, size);
            temp_arr_   += size;
            r_start_ += size;
        }
        else 
        {
            memcpy(temp_arr_, l_start_, size);
            temp_arr_  += size;
            l_start_ += size;
        }
    }

        memcpy(temp_arr_, l_start_, l_end_ - l_start_);

   		memcpy(temp_arr_, r_start_, r_end_ - r_start_);
}


void msort(void* base, size_t num, size_t size, int (*compar)(const void*, const void*))
{
    void* temp = malloc(num * size);
    memcpy(temp, base, num * size);
    mergesort(temp, base, size, 0, num, compar);
    free(temp);
}
