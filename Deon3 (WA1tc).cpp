#include <iostream>
#include <vector>
using namespace std;

int binary(vector<long long> &n, long long target) {
	if (n.empty()) return -1;
	int left = 0;
	int right = (int)n.size() - 1;
	
	int midind = -1;
	while (left <= right) {
		int mid = left + (right - left) / 2;

		if (target <= n[mid]) {
			right = mid - 1;
			midind= mid;
		}
		
		else left = mid + 1;
	}
	if (midind != -1 && n[midind] == target) {
		return midind;
	}
	return -1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	long long x;
	cin >> x;

	int n;
	cin >> n;
	vector <long long> code(n);
	for (int i = 0;i < n;i++) {
		cin >> code[i];
	}

	
	int index=binary(code, x);
	if (index != -1) {
		cout << index+1;
	}
	else cout << -1;
}