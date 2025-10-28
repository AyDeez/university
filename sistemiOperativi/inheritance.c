
/* --- SIMPLE INHERITANCE --- */

/*

can be implemented in c setting as first variable
in the derived struct an instance of the base class

a pointer to the derived class will also be a pointer to
the first member variable in the struct which is of type A

*/

#include <stdio.h>


typedef struct {
    int my_int;
    float my_float;
} A;

typedef struct {
    A parent;
    int my_other_int;
} B;


void printMyInt(A* a);


int main() {

    B b;
    b.parent.my_int = 3;
    printMyInt((A*)&b);

    A a;
    a.my_int = 4;
    printMyInt(&a);

    a = b.parent;
    printMyInt(&a);

}


void printMyInt(A* a) {
    printf("my_int = %d\n", a->my_int);
}