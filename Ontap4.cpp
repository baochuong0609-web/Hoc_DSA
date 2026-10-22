#include <iostream>
#include <vector>
using namespace std;

void Output(vector <int> &a, int n) {
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

int main() {
	int n; 
	cin >> n;
	vector <int>a(n);
	for (int i = 0;i < n;i++) {
		cin >> a[i];
	}
	cout << "Mang truoc khi sap xep:" << "\n";
	Output(a, n);
	cout << "\n";
	cout << "Sap xep:" << "\n";

	for (int i = 0;i < n-1;i++) {
		cout << "i = " << i+1 << "\n";

		cout << "Mang truoc khi swap: ";
		Output(a, n);

		int maxlocate = i;
		for (int j = i;j < n;j++) {
			if (a[j] > a[maxlocate]) {
				maxlocate = j;
			}
		}

		cout << "Phan tu lon nhat trong doan [" << i + 1 << ", " << n - 1 << "]: " << maxlocate;
		swap(a[i], a[maxlocate]);

		cout << "\nMang sau khi swap: ";
		Output(a, n);
		cout << "\n";
	}
	cout << "Mang sau khi sap xep:\n"; 
	Output(a, n);
	return 0;
}
