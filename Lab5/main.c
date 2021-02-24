#include "lab5.h"

char* filename = "Employees.txt";

int main(void) {
    printf("Started Program...\n");
    FILE * file = fopen(filename, "r");
    if(!file) {
        fprintf(stderr, "The file [ %s ] was not successfully opened\n", filename);
        return -1;
    }

    printf("File Opened successfully...\n");

    Employee* emps = readEmployeeArray(file);

    printf("Employee Array initialzed...\n");

    for(int i = 0; i < getArraySize(emps); i++) {
        int jobType = 0;
        float salary = 0;
        getEmpJobType(emps, i, &jobType);
        getEmpSalary(emps, i, &salary);
        printf("Employee ID: %d\nJob Type: %d\nSalary: %f\n\n", i, jobType, salary);
    }

    freeEmployeeArray(emps);


    return 0;
}
