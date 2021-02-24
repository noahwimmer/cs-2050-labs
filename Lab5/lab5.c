#include "lab5.h"



Employee* readEmployeeArray(FILE* fp) {
    int size;
    fscanf(fp, "%d", &size);
    Employee* emps = NULL;
    int* temp = malloc(size * sizeof(Employee) + sizeof(int));
    if(temp == NULL) {
        //malloc failed
        return NULL;
    }
    temp[0] = size;
    temp++;
    emps = (Employee*) temp;
    int jobType = 0;
    float salary = 0;

    for(int i = 0; i < size; i++) {
        printf("test: %d\n", i);
        fscanf(fp, "%d, %d, %f", &(emps[i].empID), &jobType, &salary);
        setEmpSalary(emps, i, salary);
        setEmpJobType(emps, i, jobType);
    }

    return emps;
}

int setEmpSalary(Employee* emps, int empID, float salary) {
    emps[empID].salary = salary;
    return 0;
}

int getEmpSalary(Employee* emps, int empID, float* salary) {
    *salary = emps[empID].salary;
    return 0;
}

int setEmpJobType(Employee* emps, int empID, int job) {
    emps[empID].jobType = job;
    return 0;
}

int getEmpJobType(Employee* emps, int empID, int* job) {
    *job = emps[empID].jobType;
    return 0;
}

int getArraySize(Employee* arr) {
    int* array = (int*) arr;
    return array[-1];
}

void freeEmployeeArray(Employee* emps) {
    int* temp = (int*) emps;
    temp--;
    free(temp);
}
