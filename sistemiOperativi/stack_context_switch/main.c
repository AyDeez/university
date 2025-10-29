#include <stdio.h>
#include <ucontext.h>

#define STACK_SIZE 8192

ucontext_t main_context,
            f0_context,
            f1_context,
            f2_context,
            f3_context,
            f4_context,
            f5_context,
            f6_context,
            f7_context,
            f8_context,
            f9_context;

int num_iterations = 10;

void initialize_context();
void f0();
void f1();
void f2();
void f3();
void f4();
void f5();
void f6();
void f7();
void f8();
void f9();

char f0_stack[STACK_SIZE];
char f1_stack[STACK_SIZE];
char f2_stack[STACK_SIZE];
char f3_stack[STACK_SIZE];
char f4_stack[STACK_SIZE];
char f5_stack[STACK_SIZE];
char f6_stack[STACK_SIZE];
char f7_stack[STACK_SIZE];
char f8_stack[STACK_SIZE];
char f9_stack[STACK_SIZE];

int main() {

    // get a context from main
    getcontext(&f0_context);

    // set the stack of f1 to the right place, then create a trampoline for the first function
    f0_context.uc_stack.ss_sp = f0_stack;
    f0_context.uc_stack.ss_size = STACK_SIZE;
    f0_context.uc_stack.ss_flags = 0;
    f0_context.uc_link = &main_context;
    makecontext(&f0_context, f0, 0, 0);

    // always remember to initialize a new context from something known, then create a trampoline
    initialize_context(&f0_context, &f1_context, f1, f1_stack);
    initialize_context(&f0_context, &f2_context, f2, f2_stack);
    initialize_context(&f0_context, &f3_context, f3, f3_stack);
    initialize_context(&f0_context, &f4_context, f4, f4_stack);
    initialize_context(&f0_context, &f5_context, f5, f5_stack);
    initialize_context(&f0_context, &f6_context, f6, f6_stack);
    initialize_context(&f0_context, &f7_context, f7, f7_stack);
    initialize_context(&f0_context, &f8_context, f8, f8_stack);
    initialize_context(&f0_context, &f9_context, f9, f9_stack);

    // this passes control to f2 and saves the current context in main_context
    swapcontext(&main_context, &f0_context);
    // we will jump back here

    printf("exiting\n");

}


void initialize_context(ucontext_t* old, ucontext_t* context, void(*func)(), void* stack) {
    *context = *old;
    context->uc_stack.ss_sp = stack;
    context->uc_stack.ss_size = STACK_SIZE;
    context->uc_stack.ss_flags = 0;
    context->uc_link = &main_context;
    makecontext(context, func, 0, 0);
}


void f0() {
    printf("f0 started\n");
    for (int i=0; i<num_iterations; i++) {
        printf("f0: %d\n", i);
        swapcontext(&f0_context, &f1_context);
    }
    setcontext(&main_context);
}

void f1() {
    printf("f1 started\n");
    for (int i=0; i<num_iterations; i++) {
        printf("f1: %d\n", i);
        swapcontext(&f1_context, &f2_context);
    }
    setcontext(&main_context);
}

void f2() {
    printf("f2 started\n");
    for (int i=0; i<num_iterations; i++) {
        printf("f2: %d\n", i);
        swapcontext(&f2_context, &f3_context);
    }
    setcontext(&main_context);
}

void f3() {
    printf("f3 started\n");
    for (int i=0; i<num_iterations; i++) {
        printf("f3: %d\n", i);
        swapcontext(&f3_context, &f4_context);
    }
    setcontext(&main_context);
}

void f4() {
    printf("f4 started\n");
    for (int i=0; i<num_iterations; i++) {
        printf("f4: %d\n", i);
        swapcontext(&f4_context, &f5_context);
    }
    setcontext(&main_context);
}

void f5() {
    printf("f5 started\n");
    for (int i=0; i<num_iterations; i++) {
        printf("f5: %d\n", i);
        swapcontext(&f5_context, &f6_context);
    }
    setcontext(&main_context);
}

void f6() {
    printf("f6 started\n");
    for (int i=0; i<num_iterations; i++) {
        printf("f6: %d\n", i);
        swapcontext(&f6_context, &f7_context);
    }
    setcontext(&main_context);
}

void f7() {
    printf("f7 started\n");
    for (int i=0; i<num_iterations; i++) {
        printf("f7: %d\n", i);
        swapcontext(&f7_context, &f8_context);
    }
    setcontext(&main_context);
}

void f8() {
    printf("f8 started\n");
    for (int i=0; i<num_iterations; i++) {
        printf("f8: %d\n", i);
        swapcontext(&f8_context, &f9_context);
    }
    setcontext(&main_context);
}

void f9() {
    printf("f9 started\n");
    for (int i=0; i<num_iterations; i++) {
        printf("f9: %d\n", i);
        swapcontext(&f9_context, &f0_context);
    }
    setcontext(&main_context);
}
