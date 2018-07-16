#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>

using namespace std;

int sum(int a00, int a01, int a10, int a11) {
	int s = a00 + a01 + a10 + a11;
	if (s == 4 && (a00&a01&a10&a11) == 1)return 1;
	else if (s == 0) return 0;
	else return 2;
}

int main() {
	std::ios::sync_with_stdio(false);

	int t;
	cin >> t;

	int n;
	int arr[257][257];
	int a;
	int cnt[3];
	for (int tc = 0; tc < t; tc++) {
		cin >> n;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> arr[i][j];
			}
		}
		cnt[0] = 0;
		cnt[1] = 0;

		
		for (int num = n; num > 1; num /= 2) {
			for (int i = 0; i < num; i += 2) {
				for (int j = 0; j < num; j += 2) {
					a = sum(arr[i][j], arr[i + 1][j], arr[i][j + 1], arr[i + 1][j + 1]);
					if (a == 1 || a == 0) {
						arr[i / 2][j / 2] = a;
					}
					else if (a == 2) {
						cnt[arr[i][j]]++;
						cnt[arr[i+1][j]]++;
						cnt[arr[i][j+1]]++;
						cnt[arr[i+1][j+1]]++;
						arr[i / 2][j / 2] = 2;
					}
				}
			}
		}
		cout << cnt[0] << " " << cnt[1] << "\n";
	}



	return 0;
}