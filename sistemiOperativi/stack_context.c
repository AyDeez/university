#include <stdio.h>
#include <ucontext.h>

// --------------------------------- //
//                                   //
//    CONTEXT SWITCH ON A PROCESS    //
//                                   //
// --------------------------------- //



ucontext_t main_context, f1_context, f2_context;
int num_iteration = 10;

// saves the current context in ucp
int getcontext(ucontext_t* ucp);

// sets the current context to ucp, that was previously saved
int setcontext(const ucontext_t* ucp);

// creates a trampoline context for function func
void makecontext(ucontext_t* ucp, void (*func)(), int argc, ...);

// saves the current context in oucp, and jumps to ucp
int swapcontext(ucontext_t* oucp, const ucontext_t* ucp);



int main() {

    return 0;

}



int getcontext(ucontext_t* ucp) {
    return 0;
}

int setcontext(const ucontext_t* ucp) {
    return 0;
}

void makecontext(ucontext_t* ucp, void (*func)(), int argc, ...) {
    return 0;
}

int swapcontext(ucontext_t* oucp, const ucontext_t* ucp) {
    return 0;
}