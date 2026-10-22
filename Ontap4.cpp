#include <iostream>
#include <vector>
using namespace std;

void Output(const vector <int>& a, int n) {
	for (int i = 0;i < n;i++) {
		cout << a[i] << " " ;
	}
	cout << "\n";
}

void swap (int& a, int& b){
	int temp = a;
	a = b;
	b = temp;
}

int main() {
	int n;
	cin >> n;
	vector<int>a(n);
	for (int i = 0;i < n;i++) {
		cin >> a[i];
	}

	cout << "Mang truoc khi sap xep:\n";
	Output(a, n);
	cout << "\n";

	cout << "Sap xep:\n";
	for (int i = 0;i < n - 1;i++) {
		cout << "i = " << i<<"\n";
		cout << "Mang truoc khi swap: ";
		Output(a, n);
		cout << "Phan tu lon nhat trong doan [" << i + 1 << ", " << n-1 << "]: ";

		int maxindex = i;
		for (int j = i;j < n;j++) {
			if (a[j] > a[maxindex]) {
				maxindex = j;
			}
		}
		cout << a[maxindex] <<"\n";

		cout << "Swap " << i << " va " << a[maxindex] <<"\n";
		swap(a[i], a[maxindex]);
		
		cout << "Mang sau khi swap: ";
		Output(a,n);
		cout << "\n";
	}
	cout << "Mang sau khi sap xep:\n";
	Output(a,n);
	return 0;
}