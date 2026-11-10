
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
	int x, n;
	cin >> n; // Số lượng phần tử của danh sách
	while (n-- > 0) {
		cin >> x;
		p = CreateNode(x);
		AddTail(L, p);
	}
}

void Partition(LIST& L, LIST& L1, NODE*& pivot, LIST& L2) {
	if (L.pHead == NULL) return;

	pivot = L.pHead;
	NODE* p = pivot->pNext;
	pivot->pNext = NULL;

	CreateEmptyList(L1);
	CreateEmptyList(L2);

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

	CreateEmptyList(L1);
	CreateEmptyList(L2);
}

void quicksort_ascending(LIST& L) {
	if (L.pHead == NULL || L.pHead == L.pTail) return;

	LIST L1, L2;
	NODE* pivot;

	Partition(L, L1, pivot, L2);

	quicksort_ascending(L1);
	quicksort_ascending(L2);

	Join(L, L1, pivot, L2);
}



int length(NODE* p) {
	int i = 0;
	while (p) {
		i++;
		p = p->pNext;
	}
	return i;
}

void PrintList(NODE* p) {
	if (p == NULL)
		cout << "Empty List.";
	else {
		// cout << boolalpha << is_ascending(p) << endl;
		cout << length(p) << endl;
		while (p) {
			cout << p->info << " ";
			p = p->pNext;
		}
	}
}



int main() {
	LIST L;
	CreateEmptyList(L);

	CreateList(L);
	quicksort_ascending(L);
	PrintList(L.pHead);

	return 0;
}
