#include <iostream>
#include <algorithm>
using namespace std;

int d[1005][1005];
int pos[1005];
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);

	int tc;
	cin >> tc;
	int n, m;
	for (int t = 0; t < tc; t++) {
		cin >> n >> m;
		pos[0] = 0;
		pos[1] = n;
		for (int i = 2; i < m + 2; i++) {
			cin >> pos[i];
		}
		for (int i = 0; i < m + 2; i++) {
			for (int j = 0; j < m + 2; j++) {
				d[i][j] = 999999999;
			}
		}
		int max = 999999999;
		d[0][1] = 0;

		for (int i = 2; i < m + 2; i++) {
			for (int j = 0; j < i; j++) {
				if (d[i][i - 1] > d[j][i - 1] + abs(pos[j] - pos[i])) {
					d[i][i - 1] = d[j][i - 1] + abs(pos[j] - pos[i]);
				}
				if (d[j][i] > d[j][i - 1] + abs(pos[i - 1] - pos[i])) {
					d[j][i] = d[j][i - 1] + abs(pos[i - 1] - pos[i]);

				}
			}
			for (int j = 0; j < i; j++) {
				if (d[i][j] > d[i - 1][j] + abs(pos[i - 1] - pos[i])) {
					d[i][j] = d[i - 1][j] + abs(pos[i - 1] - pos[i]);
				}
				if (d[i - 1][i] > d[i - 1][j] + abs(pos[j] - pos[i])) {
					d[i - 1][i] = d[i - 1][j] + abs(pos[j] - pos[i]);
				}
			}
		}

		for (int i = 0; i < m + 2; i++) {
			if (max> d[i][m + 1])max = d[i][m + 1];
		}
		for (int i = 0; i < m + 2; i++) {
			if (max > d[m + 1][i])max = d[m + 1][i];
		}
		cout << max << endl;
	}
	return 0;

}
