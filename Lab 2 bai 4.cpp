#include <iostream>
#include <string>
using namespace std;

struct SanPham {
    int ma;
    string ten;
    int gia;
};

bool isLess(const SanPham& a, const SanPham& b) {
    if (a.gia != b.gia) return a.gia < b.gia;
    return a.ma < b.ma;
    
}

void Merge(SanPham a[], int l, int middle, int r) {
    int n_temp = r - l + 1;

    SanPham* temp = new SanPham[n_temp];

    int i = l;
    int j = middle + 1;
    int k = 0;

    while (i <= middle && j <= r) {
        if (isLess(a[i], a[j])) {
            temp[k++] = a[i++];
        }
        else {
            temp[k++] = a[j++];
        }
    }

    while (i <= middle) temp[k++] = a[i++];
    while (j <= r) temp[k++] = a[j++];

    for (int p = 0;p < k;p++) {
        a[l + p] = temp[p];
    }
    delete[] temp;
}


void mergeSort(SanPham a[], int l, int r) {
    if (l < r) {
        int middle = l + (r - l) / 2;

        mergeSort(a, l, middle);
        mergeSort(a, middle + 1, r);

        Merge(a, l, middle, r);
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
