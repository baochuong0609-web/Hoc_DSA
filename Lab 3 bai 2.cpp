
#include <iostream>
using namespace std;
#define MAXN 100

struct NODE {
    char info;
    NODE* pNext;
};

NODE* CreateNode(char x) {
    NODE* p = new NODE;
    p->info = x;
    p->pNext = NULL;
    return p;
}
struct stack {
    NODE* top;
};
bool empty(const stack& s) {
    return (s.top == NULL);
}
void CreateEmptyStack(stack& s) {
    s.top = NULL;
}
void push(stack& s, char x) {
    NODE* p = CreateNode(x);
    if (s.top == NULL) s.top = p;
    else {
        p->pNext = s.top;
        s.top = p;
    }
}
void pop(stack& s) {
    if (s.top == NULL) return;
    NODE* p = s.top;
    s.top = s.top->pNext;
    delete p;
}
char& top(stack s) {
    return s.top->info;
}

void Input_infix(char infix[], int &ni){
    ni = 0;
    char c;
    while (cin >> c && c != '#') {
        infix[ni++] = c;
    }
}


void Output(char postfix[], int np) {
    for (int i = 0;i < np;i++) {
        cout << postfix[i] << " ";
    }
}




int main() {
    char infix[MAXN], postfix[MAXN];
    int ni, np;

    Input_infix(infix, ni);

    infix_to_postfix(infix, ni, postfix, np);

    Output(postfix, np);

    return 0;
}
