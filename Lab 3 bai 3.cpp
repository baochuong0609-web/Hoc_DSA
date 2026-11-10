
#include <iostream>
using namespace std;

// Cấu trúc của một node
struct NODE {
	int info;
	NODE* pNext;
};
// Cấu trúc của một DSLK
struct LIST {
	NODE* pHead;
	NODE* pTail;
};

NODE* CreateNode(int x) {
    NODE* p = new NODE;
    p->info = x;
    p->pNext = NULL;
    return p;
}

void CreateEmptyList(LIST& l) {
    l.pHead = l.pTail = NULL;
}

void AddTail(LIST& l, NODE* p) {
    if (l.pHead == NULL) {
        l.pHead = l.pTail = p;
    }
    else {
        l.pTail->pNext = p;
        l.pTail = p;
    }
}

void CreateList(LIST& l) {
    int x;
    while (cin >> x && x != -1) {
        AddTail(l, CreateNode(x));
    }
}

void Join(LIST& L, LIST& L1, NODE* pivot, LIST& L2) {
    pivot->pNext = L2.pHead;

    if (L1.pHead == NULL) {
        L.pHead = pivot;
    }
    else {
        L.pHead = L1.pHead;
        L1.pTail->pNext = pivot;
    }

    if (L2.pHead == NULL) {
        L.pTail = pivot;
    }
    else {
        L.pTail = L2.pTail;
    }

    L1.pHead = L1.pTail = NULL;
    L2.pHead = L2.pTail = NULL;
}

void PrintList(LIST l) {
    for (NODE* p = l.pHead; p != NULL; p = p->pNext) {
        cout << p->info << " ";
    }
}


int main() {
    LIST L, L1, L2;

    int x;
    NODE* pivot;

    CreateEmptyList(L);
    CreateEmptyList(L1);
    CreateEmptyList(L2);

    CreateList(L1);
    cin >> x;
    pivot = CreateNode(x);
    CreateList(L2);


    Join(L, L1, pivot, L2);
    PrintList(L);

    return 0;
}
