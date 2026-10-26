#include <iostream>
#include <vector>
using namespace std;

struct hs {
	int id;
	int gpa;
};

bool isLess(hs& a, hs& b) {
	if (a.gpa != b.gpa) return a.gpa < b.gpa;
	return a.id < b.id;
}

void mergesort(vector<hs>& a, int left, int right) {
	if (left >= right) return;
	int mid = left + (right - left) / 2;
	int i = left;
	int j = mid + 1;

	vector<hs>temp;

	mergesort(a, left, mid);
	mergesort(a, mid + 1, right);

	while (i <= mid && j <= right) {
		if (isLess(a[i],a[j])) {
			temp.push_back(a[i]);
			i++;
		}
		else {
			temp.push_back(a[j]);
			j++;
		}
	}

	while (i <= mid) {
		temp.push_back(a[i]);
		i++;
	}

	while (j <= right) {
		temp.push_back(a[j]);
		j++;
	}

	for (int k = 0;k < temp.size();k++) {
		a[left + k] = temp[k];
	}
}

int main() {
	int n;
	cin >> n;
	vector<hs>a(n);
	for (int i = 0;i < n;i++) {
		cin >> a[i].gpa;
		a[i].id = i;
	}

	mergesort(a, 0, n - 1);

	for (int i = 0;i < n;i++) {
		cout << a[i].id << " ";
	}
	return 0;
}