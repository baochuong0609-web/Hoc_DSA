
#include <bits/stdc++.h>
using namespace std;

struct NODE {
    int info;
    NODE* pNext;
};


struct LIST {
    NODE* pHead;
    NODE* pTail;
};

void CreateEmptyList(LIST& L) {
    L.pHead = NULL;
    L.pTail = NULL;
}

NODE* CreateNode(int x) {
    NODE* p = new NODE;
    if (p == NULL)
        exit(1);
    p->info = x;
    p->pNext = NULL;
    return p;
}

void PrintList(LIST L)
{
    NODE* p = L.pHead;
    while (p != NULL)
    {
        cout << p->info << " ";
        p = p->pNext;
    }
}

void InsertTail(LIST& L, NODE* p) {
    if (L.pHead == NULL) {
        L.pTail = p;
        L.pHead = L.pTail;
    }
    else {
        L.pTail->pNext = p;
        L.pTail = p;
    }
}

void TimKiemVaXoa(LIST&, int);


void TimKiemVaXoa(LIST& L, int k) {
    bool found = false;
    NODE* current = L.pHead;
    NODE* previous = NULL;

    while (current != NULL) {
        if (current->info == k) {
            found = true;
            NODE* nodeToDelete = current;

            
            if (previous == NULL) {
                L.pHead = current->pNext;
                current = L.pHead;
            }
          
            else {
                previous->pNext = current->pNext;
                current = previous->pNext;
            }

           
            if (nodeToDelete == L.pTail) {
                L.pTail = previous;
            }

            delete nodeToDelete;
        }
        else {
            previous = current;
            current = current->pNext;
        }
    }

    if (!found) {
        cout << "-1";
    }
    else if (L.pHead != NULL) {
        PrintList(L);
    }
}




int main()
{
    LIST L;
    CreateEmptyList(L);
    int n; cin >> n;
    int x;
    for (int i = 0; i < n; i++) {
        cin >> x;
        InsertTail(L, CreateNode(x));
    }
    int k; cin >> k;
    TimKiemVaXoa(L, k);
    return 0;
}
