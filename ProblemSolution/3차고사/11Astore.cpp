#include <iostream>
using namespace std;
int a[505][505];
int b[505][505];
int res[505][505];

int main() {
	std::ios::sync_with_stdio(false);
	int T;
	cin >> T;
	int r, c;
	for (int t = 0; t < T; t++) {
		int max = 0;
		cin >> r >> c;
		int num;
		char ch;		
		for (int i = 0; i <= r; i++) {
			for (int j = 0; j <= c; j++) {
				res[i][j] = 0;
				a[i][j] = 0;
				b[i][j] = 0;
			}
		}
		for (int i = 0; i <r; i++) {
			int tend = 0;
			int tstart = 0;
			for (int j = 0; j < c; j+=num) {
				cin >> num >> ch;
				 if (ch== 'e') {
					 tend += num;
					for (int k = tstart; k < tend; k++) {
						a[i][k] = 0;
						b[i][k] = 0;
					}
					tstart = tend;
				}
				else if (ch == 'f') {
					tend += num;
					for (int k = tstart; k < tend; k++) {
						a[i][k] = 1;
						b[i][k] = 1;
					}
					tstart = tend;
				}
			}
		}

		for (int i = r-1; i >= 0; i--) {
			for (int j = c - 1; j >= 0; j--) {

				if (a[i][j] == 1) {
					a[i][j] += a[i][j + 1];
				}
				if (b[i][j] == 1) {
					b[i][j] += b[i + 1][j];
				}
			}
		}


		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				if (a[i][j] == 0) { continue; }
				int col = a[i][j];
				int row = b[i][j];
				int cnt = 0;
				bool tf = true;

				while (col--) {
					tf = true;
					cnt = 0;

					for (int k = 0; k <row; k++) {
						int temcnt = 0;
						for (int l = 0; l <= col; l++) {
							if (a[i + k][j + l] == 0) {
								tf = false;
								break;
							}
							else temcnt++;
						}

						if (tf == true)cnt += temcnt;
					}
					if (cnt > res[i][j])res[i][j] = cnt;
				}
				if (max < res[i][j])max = res[i][j];

			}
		}

		cout << max << "\n";

	}
	


	return 0;
}