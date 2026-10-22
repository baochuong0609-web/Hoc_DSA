//LowerBound: Phải Sort xong Search. tìm vị trí của phần tử đầu tiên lớn hơn hoặc bằng một giá trị (target) cho trước

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int BinSearch(const vector<int>& a, int target) {
	int left = 0;
	int right = a.size() - 1;
	int midind = -1;
	while (left <= right) {
		int mid = left + (right - left) / 2;

		//midind tìm phần tử đầu tiên lớn hơn HOẶC bằng target. Sau đó nó tiếp tục ép biên phải xuống
		if (target <= a[mid]) {	
			midind = mid;
			right = mid - 1;
		}
		else left = mid + 1;
	}
	return midind;
}

int main() {
	int n, q;
	cin >> n >> q;
	vector<int> a(n);

	for (int i = 0;i < n;i++) {
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	
	while(q--){
		int x; 
		cin >> x;
		int index = BinSearch(a, x);
		if (index != -1) {
			cout << a[index] << "\n";
		}
		else {
			cout << -1 << "\n";
		}
	}

}