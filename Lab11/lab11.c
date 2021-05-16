//
// Created by Noah Wimmer on 4/26/21.
//

#include "lab11.h"



int binarySearch(void* arr, int l, int r, void* query, int size, int (*cmp)(void*, void*)) {
    if(l<r) {
        int mid = (l+r) / 2;

        if(cmp(arr + (mid * size), &query) == 0) {
            return mid;
        }

        //if mid < query
        if(cmp(arr + (mid * size), &query) > 0) {
            return binarySearch(arr, mid+1, r, query, size, cmp);
        } else {
            return binarySearch(arr, 0, mid - 1, query, size, cmp);
        }
    }
    return -1;
}

int binarySearch_l(void* arr, int l, int r, void* query, int size, int (*cmp)(void*, void*)) {
    int mid;
    while(l <= r) {
        mid = (l+r) / 2;
        // query > mid
        if(cmp(arr + (mid * size), &query) > 0) {
            l = mid + 1;
        } else if(cmp(arr + (mid * size), &query) < 0) {
            r = mid-1;
        } else {
            return mid;
        }
    }
    return -1;
}
