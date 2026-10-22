#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int BinarySearch(vector <string>& a, string target) {
	
	int left = 0;
	int right = a.size() - 1;

	while (left <= right) {
		int mid = left + (right - left) / 2;

		if (a[mid] == target) return mid;
		else if (a[mid] < target) left = mid + 1;
		else right = mid - 1;

	}
	return -1;
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	int n;
	cin >> n;
	vector <string> a(n);
	for (int i = 0;i < n;i++) {
		cin >> a[i];
	}
	string x;
	cin >> x;
	int index = BinarySearch(a, x);
	if (index != -1) {
		cout << index + 1;
	}
	else {
		cout << -1;
	}

}