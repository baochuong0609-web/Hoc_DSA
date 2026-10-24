#include <iostream>
#include <vector>
using namespace std;


struct toado {
	double x;
	double y;
	double z;
};

bool isEqual(toado& a, toado& b) {
	return (a.x == b.x) && (a.y == b.y) && (a.z == b.z);
}

bool isLess(toado& a, toado& b) {
	if (a.x != b.x) return a.x < b.x;
	if (a.y != b.y) return a.y < b.y;
	return a.z < b.z;
}

int binarysearch(vector<toado>& a, toado target) {
	int left = 0;
	int right = a.size() - 1;
	int time = 0;
	
	while (left <= right) {
		int mid = left + (right - left) / 2;
		time++;

		if (isEqual(a[mid], target)) return time;
		else if (isLess(target,a[mid])) right = mid - 1;
		else left = mid + 1;
	}
	return -1;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	vector<toado>a(n);
	for (int i = 0;i < n;i++) {
		cin >> a[i].x >> a[i].y >> a[i].z;
	}

	int x;
	cin >> x;
	toado find;
	while (x--) {
		cin >> find.x >> find.y>>find.z;

		int index = binarysearch(a,find);
		if (index != -1) cout << index << "\n";
		else cout << "KHONG" << "\n";
	}
	return 0;

}