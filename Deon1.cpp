
#include <iostream>

using namespace std;

#include <algorithm>

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

void selectionsort(int a[], int n) {
    for (int i = 0;i < n-1;i++) {
        int minindex = i;
        for (int j = i;j < n;j++) {
            if (a[j] < a[minindex]) {
                minindex = j;
            }
        }
        swap(a[i], a[minindex]);
    }
}

bool binary_search(int a[], int n, int target) {
    int left = 0;
    int right = n - 1;
    selectionsort(a, n);

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (a[mid] == target) {
            return a[mid] == target;
        }
        else if (target < a[mid]) right = mid - 1;
        else left = mid + 1;
    }
    return 0;
}


int main() {
    int x; cin >> x;
    int n; cin >> n;

    int* a = new int[n];

    for (int i = 0; i < n; i++)
        cin >> a[i];

    cout << std::boolalpha << binary_search(a, n, x);;

    return 0;
}

