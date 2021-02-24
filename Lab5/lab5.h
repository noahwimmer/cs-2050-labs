#include <stdio.h>
#include <stdlib.h>

typedef struct employee {
    int empID, jobType;
    float salary;
} Employee;

Employee* readEmployeeArray(FILE* fp);

int setEmpSalary(Employee*, int empID, float salary);
int getEmpSalary(Employee*, int empID, float* salary);
int setEmpJobType(Employee*, int empID, int job);
int getEmpJobType(Employee*, int empID, int* job);
int getArraySize(Employee* arr);
void freeEmployeeArray(Employee* emps);
