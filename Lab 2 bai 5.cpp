#include <iostream>
using namespace std;

void Output(long long a[], int n) {
	for (int i = 0;i < n;i++) {
		cout << a[i] << " ";
	}
	cout << "\n";
}

void QuickSort(long long a[], int n, int left, int right) {
	if (left >= right) return;

	int i = left;
	int j = right;

	long long pivot = a[(left + right) / 2];

	cout << "Truoc: ";
	Output(a, n);
	cout << "Left=" << left << " - Right=" << right << " - Pivot=" << pivot << "\n";

	while (i < j) {
		while (a[i] > pivot)i++;
		while (a[j] < pivot)j--;

		if (i <= j) {
			long long temp = a[i];
			a[i] = a[j];
			a[j] = temp;
			i++;
			j--;
		}
	}

	cout << "Sau: ";
	Output(a,n);
	cout << "\n";

	if (left < j) QuickSort(a, n, left, j);
	if (i < right) QuickSort(a, n, i, right);
}

int main() {
	long long a[10005];
	int n;
	cin >> n; 
	
	for (int i = 0;i < n;i++) { 
		cin >> a[i]; 
	}
	cout << "Mang truoc khi sap xep:\n";
	Output(a, n);
	cout << "\nSap xep:\n";
	QuickSort(a, n, 0, n - 1);
	cout << "Mang sau khi sap xep:\n";
	Output(a, n);
	return 0;
}