#include <iostream>
#include <vector>
using namespace std;


void Output(vector<int>& a, int n) {
	for (int i = 0;i < n;i++) {
		cout << a[i] << " ";
	}
	cout << "\n";
}
void swap(int& a, int& b) {
	int temp = a;
	a = b;b = temp;
}
int quicksort(vector<int>& a, int left, int right) {
	if (left >= right) return left;
	
	
	int pivot = a[right];

	int i = left - 1;
	
	for(int j=left;j<right;j++) {
		if (a[j] <= pivot) {
			i++;
			swap(a[i], a[j]);
		}
	}
	swap(a[i + 1], a[right]);
	return i + 1;
	//quicksort(a, left, i);
	//quicksort(a, i+2, right);		// có 2 dòng này là sort tăng dần tới cùng
}

int main() {
	int n;
	cin >> n;
	vector<int>a(n);

	for (int i = 0;i < n;i++) {
		cin >> a[i];
	}

	int index = quicksort(a, 0, n - 1);
	Output(a, n);
	cout <<index;
	return 0;
}