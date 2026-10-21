#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

struct SinhVien {
	string raw_line;
	string ten;
	string ho;
	int diemtoan;
	int id;
};

bool compare(SinhVien& a, SinhVien& b) {
	if (a.ten != b.ten) return a.ten < b.ten;
	if (a.ho != b.ho) return a.ho < b.ho;
	if (a.diemtoan != b.diemtoan) return a.diemtoan > b.diemtoan;
	return a.id < b.id;
}

void swap(SinhVien& a, SinhVien& b) {
	SinhVien temp = a;
	a = b;
	b = temp;
}

void QuickSort(vector<SinhVien>& a, int left, int right) {
	if (left >= right) return;

	SinhVien pivot = a[(left + right) / 2];
	int i = left;
	int j = right;


	while (i <= j) {
		while (compare(a[i], pivot)) i++;
		while (compare(pivot, a[j])) j--;

		if (i <= j) {
			swap(a[i], a[j]);
			i++;
			j--;
		}
	}

	if (left < j) QuickSort(a, left, j);
	if (i < right) QuickSort(a, i, right);
}

int main() {


	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	cin.ignore();
	vector<SinhVien> sv(n);

	for (int i = 0;i < n;i++) {
		getline(cin, sv[i].raw_line);
		sv[i].id = i;

		stringstream ss(sv[i].raw_line);
		string token;
		vector<string> fields;

		while (getline(ss, token, '|')) {
			fields.push_back(token);
		}

		if (fields.size() >= 6) {
			string hoten = fields[1];
			sv[i].diemtoan = stoi(fields[5]);
			size_t last_space = hoten.find_last_of(' ');

			if (last_space != string::npos) {
				sv[i].ten = hoten.substr(last_space + 1);
				sv[i].ho = hoten.substr(0, last_space);
			}

			else {
				sv[i].ten = hoten;
				sv[i].ho = "";
			}
		}
	}
	QuickSort(sv, 0, n - 1);

	for (int i = 0; i < n; i++) {
		cout << sv[i].raw_line << "\n";
	}
	return 0;
}