#include <iostream>
#include <vector>
using namespace std;

struct td {
	float x;
	float y;
	float z;
};

bool isEqual(td &a, td &b) {
	if ((a.x == b.x) && (a.y == b.y) && (a.z == b.z))
		return true;
	return false;
}

bool isLess(td& a, td& b) {
	if (a.x != b.x) return a.x < b.x;
	if (a.y != b.y) return a.y < b.y;
	return a.z < b.z;
	
}

int binsearch(vector<td> &a, td target) {
	int left = 0;
	int right = a.size() - 1;
	
	int time = 0;
	while (left <= right) {
		time++;
		int mid = left + (right - left) / 2;
		if (isEqual(target, a[mid])) {
			return time;
		}
		else if (isLess(a[mid], target)) {
			left = mid + 1;
			
		}
		else {
			right = mid - 1;
			
		}

	}
	return -1;
}

int main() {
	int n;
	cin >> n;
	vector<td> toado(n);
	for (int i = 0;i < n;i++) {
		cin >> toado[i].x >> toado[i].y >> toado[i].z;
	}

	int x;
	cin >> x;
	td search;
	while (x--) {
		cin >> search.x >> search.y >> search.z;
		int index = binsearch(toado, search);

		if (index != -1) {
			cout << index<<"\n";
		}
		else cout << "KHONG\n";
	}
	return 0;
}