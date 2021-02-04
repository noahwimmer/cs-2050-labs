#include "lab2.h"

/*
	function takes in an array and the size of the array and prints it to the terminal
*/
void printLongArray(long *array, int size) {
	printf("[ ");
	for(int i = 0; i < size; ++i) {
		printf("%ld%s", array[i], ((i + 1 == size) ? "" : ", "));
	}
	printf(" ]\n");
}

int main() {
	//opening file
	char* filename = "integers.txt";
	FILE* file = fopen(filename, "r");

	//validating file
	if(!file) {
        fprintf(stderr, "The file [ %s ] was not successfully opened\n", filename);
        return -1;
    }

	//reading array and printing
	int length;
	long* arr = readLongFromFile(file, &length);
	printLongArray(arr, length);

	//free array
	freeLongArray(&arr);

	//printLongArray(arr, length); //uncomment code to check if freeLongArray correctly results in a seg fault

	//closing file and exiting program
	fclose(file);
	return 0;
}
