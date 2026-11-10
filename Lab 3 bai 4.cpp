

#include <iostream>
#include <string.h>

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
	NODE* p;
	p = new NODE;
	//if (p == NULL)
	//		exit(1);

	p->info = x;
	p->pNext = NULL;
	return p;
}
void AddTail(LIST& L, NODE* p) {
	if (L.pHead == NULL) {
		L.pHead = p;
		L.pTail = L.pHead;
	}
	else {
		L.pTail->pNext = p;
		L.pTail = p;
	}
}

void CreateEmptyList(LIST& L) {
	L.pHead = NULL;
	L.pTail = NULL;
}
void CreateList(LIST& L) {
	NODE* p;
	int x;
	do {
		cin >> x;
		if (x == -1) break;
		p = CreateNode(x);
		AddTail(L, p);
	} while (true);
}
void PrintList(LIST L) {
	NODE* p;

	if (L.pHead == NULL)
		cout << "Empty List.";
	else {
		p = L.pHead;
		while (p) {
			cout << p->info << " ";
			p = p->pNext;
		}
	}
	cout << endl;
}

void Partition(LIST& L, LIST& L1, NODE*& pivot, LIST& L2) {
	if (L.pHead == NULL) return;

	pivot = L.pHead;

	
	NODE* p = pivot->pNext;

	
	pivot->pNext = NULL;

	while (p != NULL) {
		
		NODE* nextNode = p->pNext;

		
		p->pNext = NULL;

		if (p->info <= pivot->info) {
			
			AddTail(L1, p);
		}
		else {
			
			AddTail(L2, p);
		}

		
		p = nextNode;
	}

	
	CreateEmptyList(L);
}


int main() {
	LIST L, L1, L2;
	NODE* pivot;

	CreateEmptyList(L);
	CreateEmptyList(L1);
	CreateEmptyList(L2);
	CreateList(L);

	if (L.pHead == NULL) {
		cout << "Empty List.";
		return 0;
	}

	Partition(L, L1, pivot, L2);

	cout << pivot->info << endl;
	PrintList(L1);
	PrintList(L2);
	PrintList(L);

	return 0;
}

