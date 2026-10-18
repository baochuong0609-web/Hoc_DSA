#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct SinhVien {
	int gpa;
	int id;
};
    
bool compare(const SinhVien& a, const SinhVien& b) {
	if (a.gpa != b.gpa) return a.gpa < b.gpa;
	return a.id < b.id;
}
void swap(SinhVien& a, SinhVien& b) {
    SinhVien temp = a;
    a = b; b = temp;
}

void QuickSort(vector<SinhVien> &a, int left, int right) {
    if (left >= right)return;

    SinhVien pivot = a[(left + right) / 2];
    int i = left;
    int j = right;

    while (i <= j) {
        while (compare(a[i],pivot)) i++;    
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
    

    vector <SinhVien>sv(n);
    for (int i = 0;i < n;i++) {
        cin >> sv[i].gpa;
        sv[i].id = i;
    }

    QuickSort(sv, 0, n - 1);

    for (int i = 0;i < n;i++) {
        cout << sv[i].id << " ";
    }
    return 0;
   
}