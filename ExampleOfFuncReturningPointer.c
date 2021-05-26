#include <stdio.h>
#include<stdlib.h>

int *f();

int main()
{
    int *p = f();
    printf("%d\n", *p);
}

int *f()
{
    int *j = (int*)malloc(sizeof(int));
    *j = 10;
    return j;

}

/*A practical example*/

/*
#include <stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct{
    int age;
    int marks;
    char name[20];
}
Student;

Student *f();

int main()
{
    Student *p = f();
    printf("p marks = %d \n", p->marks);
    printf("p name = %s \n", p->name);
}

Student *f()
{
    Student *j = (Student*)malloc(sizeof(Student));
    j->age = 10;
    j->marks = 57;
    strcpy(j->name, "Divender");
    return j;
}
*/