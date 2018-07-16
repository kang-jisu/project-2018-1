#include <iostream>
using namespace std;

int a[501];
int b[501];
int ra[10001];
int rb[10001];
int cake;
int main() {
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);
	int t;
	cin >> t;

	for (int tc = 0; tc < t; tc++) {
		cin >> cake;

		for (int i = 0; i <= cake; i++) {
			ra[i] = 0;
			rb[i] = 0;
		}
		int n, m;
		int asum = 0;
		int bsum = 0;
		cin >> n >> m;

		for (int i = 0; i < n; i++) {
			cin >> a[i];
			asum += a[i];
		}
		if(asum<=cake)ra[asum]++;
		//이거 이런조건 걸어주는거 주의!!
		for (int i = 0; i < n; i++) {
			int tem = 0;
			for (int j = 0; j < n - 1; j++) {
				tem += a[(i + j) % n];
				if(tem<=cake)ra[tem]++;
			}
		}
		for (int i = 0; i < m; i++) {
			cin >> b[i];
			bsum += b[i];
		}
		if(bsum<=cake)rb[bsum]++;

		if (cake > asum + bsum) {
			cout << "0\n";
			continue;
		}
		for (int i = 0; i < m; i++) {
			int tem = 0;
			for (int j = 0; j < m - 1; j++) {
				tem += b[(i + j) % m];
				if(tem<=cake)rb[tem]++;
			}
		}

		int result = ra[cake] + rb[cake];
		for (int i = 1; i < cake; i++) {
			result += ra[i] * rb[cake - i];
		}
		cout << result << "\n";
	}
}