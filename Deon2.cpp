#include <iostream>
#include<vector>
#include <string>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<string>a(n);
	for (int i = 0;i < n;i++) {
		cin >> a[i];
	}

	string x;
	cin >> x;

	int index = -1;
	for (int i = 0;i < n;i++) {
		if (a[i] == x) {
			index = i;
			break;
		}
	}
	if (index != -1) {
		cout << index + 1;
	}
	else cout << -1;
	return 0;
}