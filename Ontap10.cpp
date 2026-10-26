

#include <iostream>
#include <string>
using namespace std;

struct SanPham {
    int ma;
    string ten;
    int gia;
};


#include <vector>
bool isLess(SanPham& a, SanPham& b) {
    if (a.gia != b.gia) return a.gia < b.gia;
    return a.ma < b.ma;
}

void mergeSort(SanPham a[], int left, int right) {
    if (left >= right) return;
    int mid = left + (right - left) / 2;
    int i = left;
    int j = mid + 1;
    vector <SanPham> temp;

    mergeSort(a, left, mid);
    mergeSort(a, mid + 1, right);
    
    

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
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    SanPham* a = new SanPham[n];
    for (int i = 0; i < n; i++) cin >> a[i].ma >> a[i].ten >> a[i].gia;

    if (n > 0) mergeSort(a, 0, n - 1);

    for (int i = 0; i < n; i++) {
        cout << a[i].ma << ' ' << a[i].ten << ' ' << a[i].gia << '\n';
    }
    return 0;
}
