#include "lab0.h"

/* REQUIRED CODE GOES HERE */

// Linear search through array to find amount of occurrences of a target number
int countOccurrences(int length, int arr[], int target) {
    int amount = 0;
    for(int i = 0; i < length; i++) {
        if(arr[i] == target) amount++;
    }
    return (amount == 0) ? -1 : amount;
}
