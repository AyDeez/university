#include <stdio.h>

#define MAX_ACTIONS 10

int run = 1;

// declare a function pointer type void f(int)
typedef void (*ActionPtrFn)(int);

void actionFn0(int event) {
    printf("Action 0, key entered %d\n", event);
}
void actionFn1(int event) {
    printf("Action 1, key entered %d\n", event);
}
void actionFnDefault(int event) {
    printf("Default action, key entered %d\n", event);
}
void actionFnQuit(int event) {
    printf("Quitting %d\n", event);
    run = 0;
}

// array of pointers to functions
ActionPtrFn actions[MAX_ACTIONS];

int main() {

    for (int i=0; i<MAX_ACTIONS; i++) {
        actions[i] = actionFnDefault;
    }

    actions[0] = actionFn0;
    actions[1] = actionFn1;
    actions[8] = actionFn0;
    actions[9] = actionFnQuit;

    while (run) {
        int v;
        scanf("%d",&v);
        if (v<0||v>=MAX_ACTIONS) {
            printf("invalid index %d",v);
            continue;
        }
        (*actions[v])(v);
    }

}