
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
    a = b;
    b = temp;
}

void quick(int a[], int left, int right) {
    if (left >= right) return;
    int pivot = a[(left + right) / 2];

    int i = left;
    int j = right;

    while (i < j) {
        while (a[i] < pivot) i++;
        while (a[j] > pivot) j--;
        if (i <= j) {
            swap(a[i], a[j]);
            i++;
            j--;
        }
    }
    quick(a, left, j);
    quick(a, i, right);
}




int findMinValueOfPairs(int *a, int n) {
    quick(a, 0, n - 1);

    long long mindistance = MAXN;
    
    for (int i = 1;i < n;i++) {
     long long distance = a[i] - a[i-1];
        if (distance < mindistance) {
            mindistance = distance;
        }
    }
    return mindistance;
}


int main() {
    int arr[MAXN], n;
    Nhap(arr, n);

    cout << findMinValueOfPairs(arr, n);
   
    return 0;
}
