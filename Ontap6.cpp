#include <iostream>
#include <vector>
using namespace std;

struct sv {
	int id;
	string name;
	int score;
};

bool isLess(sv& a, sv& b) {
	if (a.score != b.score) return a.score > b.score;
	return a.name < b.name;
}

void insertionsort(vector<sv>& a, int n) {
	for (int i = 1;i < n;i++) {
		int q = i - 1;
		sv temp = a[i];

		while (q >= 0) {
			if (isLess(temp, a[q])) {
				a[q + 1] = a[q];
				q--;
			}
			else break;
		}
		a[q + 1] = temp;
	}
}

int main() {
	int n;
	cin >> n;
	vector <sv>a(n);
	for (int i = 0;i < n;i++) {
		cin >> a[i].id >> a[i].name >> a[i].score;
	}

	insertionsort(a, n);
	for (int i = 0;i < n;i++) {
		cout << a[i].id << " " << a[i].name << " " << a[i].score << "\n";
	}
}