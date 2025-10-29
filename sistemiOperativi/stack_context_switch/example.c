#include <stdio.h>
#include <ucontext.h>

#define STACK_SIZE 8192

ucontext_t main_context, f0_context, f1_context;

int num_iterations = 10;

void f0();
void f1();

char f0_stack[STACK_SIZE];
char f1_stack[STACK_SIZE];

int main() {

    // get a context from main
    getcontext(&f0_context);

    // set the stack of f1 to the right place
    f0_context.uc_stack.ss_sp = f0_stack;
    f0_context.uc_stack.ss_size = STACK_SIZE;
    f0_context.uc_stack.ss_flags = 0;
    f0_context.uc_link = &main_context;

    // create a trampoline for the first function
    makecontext(&f0_context, f0, 0, 0);

    // always remember to initialize a new context from something known
    f1_context = f0_context;
    f1_context.uc_stack.ss_sp = f1_stack;
    f1_context.uc_stack.ss_size = STACK_SIZE;
    f1_context.uc_stack.ss_flags = 0;
    f1_context.uc_link = &main_context;

    // create a trampoline for the second function
    makecontext(&f1_context, f1, 0, 0);

    // this passes control to f2 and saves the current context in main_context
    swapcontext(&main_context, &f0_context);
    // we will jump back here

    printf("exiting\n");

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
        swapcontext(&f1_context, &f0_context);
    }
    setcontext(&main_context);
}