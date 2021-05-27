
//Taken from https://www.sanfoundry.com/multiple-choice-questions-c-pointers-function-arguments/

#include <stdio.h>
#include<stdlib.h>
#include<string.h>

void foo(int ** x)
{
    int j = 11;
    *x = &j;
    printf("%d\n", **x);
}

int main()
{

    int i = 10;
    int *const p = &i; //constant pointer to an int (means p cannot be assigned a different address)
    

    /*method's arg type is int ** therefore warning: 
    "passing 'int *const *' to parameter of type 'int **' discards qualifiers"
    therefore const is dropped and now *x can make pointer p point to a different address.
    */          
    foo(&p); 
    
    printf("%d\n", *p);
}
