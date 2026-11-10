
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

void Input_infix(char infix[], int& ni) {
    ni = 0;
    char c;
    while (cin >> c && c != '#') {

        if (ni < 100) {
            infix[ni++] = c;
        }
    }
}

int getPrecedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/' || op == '%') return 2;
    if (op == '^') return 3;
    return 0;
}

void infix_to_postfix(char infix[], int ni, char postfix[], int& np) {
    stack s;
    CreateEmptyStack(s);
    np = 0;

    for (int i = 0; i < ni; i++) {
        char c = infix[i];

        if (c >= '0' && c <= '9') {
            postfix[np++] = c;
        }
        else if (c == '(') {
            push(s, c);
        }
        else if (c == ')') {
            while (!empty(s) && top(s) != '(') {
                postfix[np++] = top(s);
                pop(s);
            }
            if (!empty(s) && top(s) == '(') {
                pop(s);
            }
        }

        else if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^' || c == '%') {
            while (!empty(s) && top(s) != '(') {
                char topOp = top(s);
                if (getPrecedence(topOp) >= getPrecedence(c)) {
                    postfix[np++] = topOp;
                    pop(s);
                }
                else {
                    break;
                }
            }
            push(s, c);
        }
    }

    while (!empty(s)) {
        postfix[np++] = top(s);
        pop(s);
    }
}

void Output(char postfix[], int np) {
    if (np == 0) return;

    for (int i = 0; i < np; i++) {
        cout << postfix[i];
        if (i < np - 1) cout << " ";
    }

    cout << "\n";
}


int main() {
    char infix[MAXN], postfix[MAXN];
    int ni, np;

    Input_infix(infix, ni);

    infix_to_postfix(infix, ni, postfix, np);

    Output(postfix, np);

    return 0;
}
