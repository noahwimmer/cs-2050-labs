//
// Created by Noah Wimmer on 5/4/21.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#ifndef LAB12_LAB12_H
#define LAB12_LAB12_H

typedef struct tree {
    double data;
    struct tree* left;
    struct tree* right;
} Tree;

/* This function sorts an array of n doubles into
        ascending sorted order.
        A return value of 1 signifies success, 0 signifies
        failure due to insufficient memory.
        Run-time complexity: expected O(n log(n))
        Space complexity: O(n)
*/
int finalPrelabSort(double *array, int n);

//Initializes a tree structure
Tree* initTree();

void writeToArray(Tree* tree, double* arr, int* i);

Tree* insert(Tree* tree, double d);

#endif //LAB12_LAB12_H
