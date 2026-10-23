
#include <iostream>
#define MAXN 30000

void NhapMang(int A[], int& N) {
    std::cin >> N;
    for (int i = 0; i < N; i++)
        std::cin >> A[i];
}

using namespace std;

void SapXepChen_Decending(int a[], int n) {
    for (int i = 1;i < n;i++) {
        int q = i - 1;
        int temp = a[i];
        while (q >= 0) {
            if (a[q] < temp) {
                a[q + 1] = a[q];
                q--;
            }
            else break;
        }
        a[q+1] = temp;
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

    SapXepChen_Decending(a, n);

    XuatMang(a, n);

    return 0;
}
