#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Thuoc {
	string tenthuoc;
	int sl;
};

int main() {
	int n;
	cin >> n;

	int min = 999;
	string minname = "";

	vector<Thuoc> mec(n);
	for (int i = 0;i < n;i++) {
		cin >> mec[i].tenthuoc >> mec[i].sl;
	}

	for (int i = 0;i < n;i++) {
		if (mec[i].sl < min) {
			min = mec[i].sl;
			minname = mec[i].tenthuoc;
		}
	}
	cout << minname;
	return 0;

}