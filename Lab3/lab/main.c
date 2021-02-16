#include "lab3.h"

char* filename = "gameScores.txt";

int main() {
    //opening the file
    FILE* file = fopen(filename, "r");
    if(!file) {
        fprintf(stderr, "The file [ %s ] was not successfully opened.\n", filename);
        return -1;
    }


    int min, size; //min index and size of the array
    int* scores; // array that holds scores.

    //loading game scores from file into array
    scores = loadGameScores(file, &min, &size);

    //printing scores.
    for(int i = min; i < min + size; i++) {
        printf("score %d: %d\n", i, scores[i]);
    }

    //freeing the array
    freeIntArray(&scores, min);


    //asserting a seg fault happens if we access the array after its been freed
    // for(int i = min; i < min + size; i++)
    //     printf("score %d: %d\n", i, scores[i]);
    return 0;
}
