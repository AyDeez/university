#include <stdio.h>

// forward declaration of A
struct A;

// pointer to print fn
typedef void (*A_PrintFnPtr)(struct A*);

// A print function
void A_print_impl(struct A* a) { printf("A\n"); }

// B print function
void B_print_impl(struct A* a) { printf("B\n"); }

typedef struct {
    A_PrintFnPtr print_fn;
} A_ops;

// A class
typedef struct A {
    A_ops* ops;
} A;

// VMT is inherited
typedef struct B {
    A parent;
} B;

// global variables representing vmt
A_ops a_ops = { .print_fn = A_print_impl };
A_ops b_ops = { .print_fn = B_print_impl };

// wrapper, crawls in VMT and calls right function
void A_print(struct A* a_ptr) {
    (*a_ptr -> ops -> print_fn)(a_ptr);
}

int main() {

    A a1 = {.ops = &a_ops};
    A a2 = {.ops = &a_ops};
    B b1 = {.parent.ops = &b_ops};
    B b2 = {.parent.ops = &b_ops};

    A* a_ptr = &a1;
    A_print(a_ptr);

    a_ptr = (A*)&b1;
    A_print(a_ptr);

    a_ptr = &a2;
    A_print(a_ptr);

    a_ptr = (A*)&b2;
    A_print(a_ptr);

}