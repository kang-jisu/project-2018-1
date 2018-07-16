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

	int n, m;
	int arr[100][100];
	int dp[100][100];
	int min;
	for (int tc = 0; tc < t; tc++) {
		cin >> n >> m;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> arr[i][j];
			}
		}
		
		for (int i = 0; i < n; i++) {
			dp[i][0] = arr[i][0];
		}

		for (int j = 1; j < m; j++) {
			for (int i = 0; i < n; i++) {
				min = 8000000;
				for (int k = 0; k < n; k++) {
					if (i != k) {
						if (min > dp[k][j - 1])min = dp[k][j - 1];
					}

				}
				dp[i][j] = min + arr[i][j];
			}
		}
		min = 8000000;
		for (int i = 0; i < n; i++) {
			if (min > dp[i][m - 1])min = dp[i][m - 1];
		}
		cout << min<<"\n";
		
	}



	return 0;
}