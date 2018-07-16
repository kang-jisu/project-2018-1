#include <iostream>
using namespace std;

int arr[51][51];
int res[51][2];
 int main() {

	std::ios::sync_with_stdio(false);

	cin.tie(NULL);

	int T;
	cin >> T;
	int n, m;
	int a, b;
	bool tf;
	for (int t = 0; t < T; t++) {
		tf = true;
		cin >> n >> m;

		for (int i = 0; i <= n; i++) {
			for (int j = 0; j <= n; j++) {
				arr[i][j] = 0;
			}
		}
		for (int i = 0; i < m; i++) {
			cin >> a >> b;
			arr[a][b] = 1;
		}

		for (int k = 0; k <= n; k++) {
			for (int i = 0; i <= n; i++) {
				for (int j = 0; j <= n; j++) {
					if (arr[i][k] && arr[k][j])arr[i][j] = 1;
				}
			}
		}
		
		for (int i = 0; i <= n; i++) {
			int ac = 0;
			for (int j = 0; j <= n; j++) {
				if (arr[i][j]&&arr[j][i]) { tf = false; 
				break;
				}
				else if (arr[i][j]) {
					ac++;
				}
			}
			res[i][0] = ac;
		}
		for (int i = 0; i <= n; i++) {
			int bc = 0;
			for (int j = 0; j <= n; j++) {
				 if (arr[j][i]) {
					bc++;
				}
			}
			res[i][1] = bc;
		}

/*
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				cout << arr[i][j] << " ";
			}
			cout << "\n";
		}*/
		if (tf == false) {
			cout << "-1\n";
			continue;
		}
		else {
			for (int i = 1; i <=n; i++) {
				cout << res[i][1] << " " << res[i][0] << "\n";
			}
		}

	}

	return 0;
}