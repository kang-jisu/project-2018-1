#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>

using namespace std;

int main() {
	std::ios::sync_with_stdio(false);

	int t;
	cin >> t;
	int coin[501] = { 0 };
	int dp[10001] = { 0 };
	for (int tc = 0; tc < t; tc++) {
		int p, n;
		cin >> p >> n;
		int change = 10000 - p;
		for (int i = 0; i <= change; i++) {
			dp[i] = 10001;
		}

		for (int i = 0; i < n; i++) {
			cin >> coin[i];
			dp[coin[i]] = 1;

		}
		
		for (int i = 1; i <= change; i++) {
			for (int j = 0; j < n; j++) {
				if (i - coin[j] >=0 && dp[i-coin[j]]!=10001) {
					
					dp[i] = min(dp[i - coin[j]] + 1, dp[i]);
				}
			}
		}

		if (dp[change] == 10001) {
			cout << "0\n";
		}else cout << dp[change] << "\n";
	}



	return 0;
}