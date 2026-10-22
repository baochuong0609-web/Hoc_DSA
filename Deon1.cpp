
#include <iostream>

using namespace std;

#include <algorithm>

//Mảng đã xếp sẵn từ cao xuống thấp nên nếu target lớn hơn mid thì biên phải sẽ phải lùi
//Còn mảng xếp từ thấp lên cao mới ngược lại
bool binary_search(int a[], int n, int target) {
    int left = 0;
    int right = n - 1;
    

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (a[mid] == target) {
            return true;
        }
        else if (target < a[mid]) left = mid + 1;
        else right = mid - 1;
    }
    return false;
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

