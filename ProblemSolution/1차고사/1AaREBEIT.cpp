#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>

using namespace std;

int main(){
	std::ios::sync_with_stdio(false);

	int t;
	cin >> t;
	int coin[15];
	int cnt;
	for (int tc = 0; tc < t; tc++) {
		int p, n;
		cin >> p >> n;
		int change = 10000 - p;

		for (int i = 0; i < n; i++) {
			cin >> coin[i];
		}
		cnt = 0;
		if (change%coin[0] != 0) {
			cout << "0\n";
			continue;
		}
		else {
			for (int i = n - 1; i >= 0; i--) {
				if (change / coin[i] >= 1) {
					cnt += change / coin[i];
					change %= coin[i];
				}
			}
		}

		cout << cnt << "\n";
	}



	return 0;
}