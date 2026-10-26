#include <iostream>
#include <climits>
//#include <bits/stdc++.h>
#define MAXN 150000

void NhapMang(int A[], int& N) {
    std::cin >> N;
    for (int i = 0; i < N; i++)
        std::cin >> A[i];
}

#include <vector>
using namespace std;

void merge_2_Sorted_subArray(int a[], int left, int mid, int right) {
    int i = left;
    int j = mid + 1;
    vector <int> temp;

    while (i <= mid && j <= right) {
        if (a[i] < a[j]) {
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
    
    for(int k = 0;k<temp.size();k++){
        a[left + k] = temp[k];
    }
}



void XuatMang(int A[], const int& N) {
    std::cout << N << std::endl;
    for (int i = 0; i < N; i++)
        std::cout << A[i] << " ";
}

int main() {
    int a[MAXN], n;

    NhapMang(a, n);

    int l = 0, r = n - 1, middle = (l + r) / 2;
    merge_2_Sorted_subArray(a, l, middle, r);

    XuatMang(a, n);

    return 0;
}
