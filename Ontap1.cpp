#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Thuoc {
	int sl;
	string ten;
};

int main() {
	int n;
	cin >> n;
	vector<Thuoc> a(n);
	int min = 999;
	string namemin = "";
	for (int i = 0;i < n;i++) {
		cin >> a[i].ten >> a[i].sl;
	}
	for (int i = 0;i < n;i++) {
		if (a[i].sl < min) {
			min = a[i].sl;
			namemin = a[i].ten;
		}
	}
	cout << namemin;
	return 0;
}