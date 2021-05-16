//
// Created by Noah Wimmer on 4/26/21.
//

#include <stdio.h>
#include <stdlib.h>

#ifndef LAB11_LAB11_H
#define LAB11_LAB11_H

// binary sort loop and recursive

int binarySearch(void* arr, int l, int r, void* query, int size, int (*cmp)(void*, void*));

int binarySearch_l(void* arr, int l, int r, void* query, int size, int (*cmp)(void*, void*));

#endif //LAB11_LAB11_H
