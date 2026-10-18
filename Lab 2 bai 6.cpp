
#include <iostream>
#include <algorithm>
#include <climits>
#include <cmath>
using namespace std;
#define MAXN 500000

void Nhap(int* arr, int& n) {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
}

void swap(int& a, int& b) {
    int temp = a;
    a = b; b = temp;
}

void QuickSort(int* a, int left, int right) {
    if (left >= right)return;

    int pivot = a[(left + right) / 2];
    int i = left;
    int j = right;

    while (i <= j) {
        while (a[i] < pivot) i++;
        while (a[j] > pivot) j--;

        if (i <= j) {
            swap(a[i], a[j]);
            i++;
            j--;
        }
    }

    if (left < j) QuickSort(a, left, j);
    if (i < right) QuickSort(a, i, right);
}

int findMinValueOfPairs(int *a, int n) {
    QuickSort(a, 0, n - 1);

    int mindis = MAXN;

    for (int i = 1;i < n;i++) {
        int distance = a[i] - a[i - 1];
        if (distance < mindis) {
            mindis = distance;
        }
    }
    return mindis;
}


int main() {
    int* arr = new int[MAXN];
    int n;
    Nhap(arr, n);

    cout << findMinValueOfPairs(arr, n);

    delete[] arr;
    return 0;
}

