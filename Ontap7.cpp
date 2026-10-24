#include <iostream>
#include <vector>
using namespace std;

void Output(const vector<int>a, int n) {
	for (int i = 0;i < n;i++) {
		cout << a[i] << " ";
	}
	cout << "\n";
}

void swap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}


void quicksorttrace(vector<int>& a, int left, int right) {
	int n = a.size();
	if (left >= right) return;
	int pivot = a[(left + right) / 2];

	cout << "Truoc: ";
	Output(a, n);

	cout << "Left=" << left << " - " << "Right=" << right << " - " << "Pivot=" << pivot << "\n";

	int i = left;int j = right;

	while (i <= j) {
		while (a[i] > pivot) i++;
		while (a[j] < pivot) j--;
		if (i <= j) {
			swap(a[i], a[j]);
			i++;
			j--;
		}
	}

	cout << "Sau: ";
	Output(a, n);
	cout << "\n";

	quicksorttrace(a, left, j);
	quicksorttrace(a, i, right);

}


int main() {
	int n;
	cin >> n;
	vector<int> a(n);

	for (int i = 0;i < n;i++) {
		cin >> a[i];
	}

	cout << "Mang truoc khi sap xep:\n";
	Output(a,n);
	cout << "\n";

	cout << "Sap xep:\n";
	quicksorttrace(a, 0, n - 1);

	cout << "Mang sau khi sap xep:\n";
	Output(a, n);
	return 0;

}