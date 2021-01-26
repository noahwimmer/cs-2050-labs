#include "lab1.h"

//file remains "as given" except for lines: 26-28

void readArray(FILE *file, int size, float *array);
void printArray(float *array, int size);

char *filename = "numbers.txt";

int main() {
    // opening the file
	FILE *file = fopen(filename, "r");
	if(!file) {
		fprintf(stderr, "The file [ %s ] was not successfully opened\n", filename);
		return -1;
	}

    // reading the array size and creating the array
	int size;
	fscanf(file, "%d", &size);
	float array[size];
	readArray(file, size, array);
	printArray(array, size);

    // --- Your function call goes here ---
    float result;
    int error;
    error = maxBelow(array, size, &result, 3);
    //error returns 1 if the function ran successfully, else returns 0
    if(error) {
        printf("the max float below the ceiling is %f\n", result);
    } else {
        printf("There was not a number less than 0 in the array.\n");
    }

	fclose(file);
    printf("The program exited with error code: %d\n", error);
    return error;
}

void readArray(FILE *file, int size, float *array) {
	if(!file) {
		return;
	}
	for(int i = 0; i < size; ++i) {
		fscanf(file, "%f", (array + i));
	}
}

void printArray(float *array, int size) {
    printf("[ ");
	for(int i = 0; i < size; ++i) {
		printf("%.2f%s", array[i], ((i + 1 == size) ? "" : ", "));
	}
    puts(" ]");
}
