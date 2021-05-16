//
// Created by Noah Wimmer on 5/4/21.
//

#include "Lab12.h"

Tree* initTree() {
    Tree* tree = malloc(sizeof(Tree));
    if(!tree) {
        fprintf(stderr, "Error: Could not allocate memory for Tree.\nReturning NULL...\n");
        return NULL;
    } else {
        tree->data = -1;
        tree->left = NULL;
        tree->right = NULL;
        return tree;
    }
}

void freeTree(Tree* tree) {
    if(tree == NULL) return;

    freeTree(tree->left);

    free(tree);

    freeTree(tree->right);
}

void writeToArray(Tree* tree, double* arr, int* i) {
    if(tree == NULL) return;

    writeToArray(tree->left, arr, i);

    arr[*i] = tree->data;
    (*i)++;

    writeToArray(tree->right, arr, i);
}

Tree* insert(Tree* tree, double d) {
    if(tree == NULL) {
        Tree* newTree = initTree();
        newTree->data = d;
        return newTree;
    }

    if(d < tree->data) {
        tree->left = insert(tree->left, d);
    } else {
        tree->right = insert(tree->right, d);
    }

    return tree;
}


int finalPrelabSort(double *array, int n) {
    Tree* root = NULL;
    root = insert(root, array[0]);

    int* j = malloc(sizeof(int));
    *j = 0;
    for(int i = 1; i < n; i++) {
        root = insert(root, array[i]);
    }
    writeToArray(root, array, j);
    freeTree(root);
    free(j);
}
