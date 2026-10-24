#include <iostream>
#include <vector>
using namespace std;

struct SV {
	int code;
	string ten;
	int diem;
};

bool isLess(SV& a, SV& b) {
	if (a.diem != b.diem) return a.diem > b.diem;
	return a.ten < b.ten;
}

void insertionsort(vector <SV>& a, int n) {
	for (int i = 1;i < n;i++) {
		int q = i - 1;
		SV temp;
		temp = a[i];
		while (q >= 0) {
			if (isLess(temp, a[q])) {
				a[q + 1] = a[q];
				q--;
			}
			else break;
		}
		a[q + 1] = temp;
	}
}

int main() {
	int n;
	cin >> n;
	vector <SV>a(n);
	for (int i = 0;i < n;i++) {
		cin >> a[i].code >> a[i].ten >> a[i].diem;
	}

	insertionsort(a, n);
	for (int i = 0;i < n;i++) {
		cout << a[i].code << " " << a[i].ten << " " << a[i].diem <<"\n";
	}
	return 0;
}