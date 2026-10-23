#include <iostream>
#include <vector>
using namespace std;

void Output(const vector <int>&a, int n) {
	for (int i = 0; i < n;i++) {
		cout << a[i] << " ";
	}
	cout << "\n";
}

int main() {
	int n;
	cin >> n;
	vector <int>a(n);
	for (int i = 0;i < n;i++) {
		cin >> a[i];
	}

	cout << "Mang truoc khi sap xep:\n";
	Output(a, n);
	cout << "\n";

	cout << "Sap xep:\n";
	for (int i = 1;i < n;i++) {
		cout << "i = " << i  << "\n";

		cout << "Mang truoc khi xu ly: ";Output(a, n);
		cout << "Phan tu dang xet A[" << i << "] = " << a[i] << "\n";

		int temp = a[i];
		int locate;
		int q=i-1;
		while(q>=0) {
			if (a[q] < temp) {
				a[q + 1] = a[q];
				q--;
			}
			
			else break;
		}
		a[q + 1] = temp;
		locate = q + 1;

		cout << "Chen " << temp << " vao vi tri k = "<< locate << "\n";


		cout << "Mang sau khi xu ly: ";
		Output(a, n);
		cout << "\n";
	}
	cout << "Mang sau khi sap xep:";
	Output(a, n);
	return 0;

}