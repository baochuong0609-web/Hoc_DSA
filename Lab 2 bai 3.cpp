#include <iostream>
#include <climits>

#define MAXN 150000

void NhapMang(int A[], int& N) {
    std::cin >> N;
    for (int i = 0; i < N; i++)
        std::cin >> A[i];
}


void XuatMang(int A[], const int& N) {
    std::cout << N << std::endl;
    for (int i = 0; i < N; i++)
        std::cout << A[i] << " ";
}
#include <vector>
using namespace std;

void merge_2_Sorted_subArray(int a[], int l, int middle, int r) {
    if (l >= r || l < 0)return;

    int n_temp = r - l + 1;

    vector<int> temp(n_temp);

    int i = l;
    int j = middle + 1;
    int k = 0;


    while (i <= middle && j <= r) {
        if (a[i] <= a[j]) {
            temp[k++] = a[i++];
        }
        else {
            temp[k++] = a[j++];

        }
    }

    while (i <= middle) {
        temp[k++] = a[i++];
    }
    while (j <= r) {
        temp[k++] = a[j++];
    }
    for (int p = 0; p < k;p++) {
        a[l + p] = temp[p];
    }

}




int main() {
    int a[MAXN], n;

    NhapMang(a, n);

    int l = 0, r = n - 1, middle = (l + r) / 2;
    merge_2_Sorted_subArray(a, l, middle, r);

    XuatMang(a, n);

    return 0;
}
