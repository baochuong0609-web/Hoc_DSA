// Tìm kiếm nhị phân là phép tìm kiếm mà ta cần sort mảng trước, sau đó sẽ định vị
//mid là số ở giữa left+(right-left)/2, left là 0 và right là n-1
//Nếu target < mid thì cắt mảng bên phải, biên phải dịch về trái và ngược lại


#include <iostream>
#include <vector>
using namespace std;

int BinSearch(const vector<int>& a, int target) {
	int left = 0;
	int right = a.size()-1;

	while (left <= right) {
		int mid = left + (right - left) / 2;

		if (a[mid] == target) return mid;
		else if (target < a[mid]) right = mid - 1;
		else left = mid + 1;
	}
	return -1;
}

int main() {
	int n;
	cin >> n;
	vector<int> code(n);
	vector <int> price(n);
	for (int i = 0;i < n;i++) {
		cin >> code[i] >> price[i];
	}

	int aim;
	cin >> aim;

	int index = BinSearch(code, aim);
	if (index != -1) {
		cout << price[index];
	}
	else {
		cout << "Not Found";
	}
	return 0;
}