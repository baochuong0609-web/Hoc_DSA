#include <iostream>
#include <vector>
using namespace std;

int binary(vector<long long> n, long long target) {
	int left = 0;
	int right = n.size() - 1;
	
	int midind = -1;
	while (left <= right) {
		int mid = left + (right - left) / 2;

		if (target <= n[mid]) {
			right = mid - 1;
			midind= mid;
		}
		
		else left = mid + 1;
	}
	//if (midind != target && midind != -1) {
	//	return -1;
	//}
	return midind;
}

int main() {
	int n;
	cin >> n;
	vector <long long> code(n);
	for (int i = 0;i < n;i++) {
		cin >> code[i];
	}

	long long x;
	cin >> x;
	int index=binary(code, x);
	if (index != -1) {
		cout << index + 1;
	}
	else cout << -1;
}