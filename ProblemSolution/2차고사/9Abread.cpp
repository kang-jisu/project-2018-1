#include <iostream>
#include <algorithm>
using namespace std;


int ho[10003];
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;

	int n, m;
	int sum;
	for (int t = 0; t < T; t++) {
		cin >> n >> m;
		sum = 0;
		for (int i = 0; i < n; i++) {
			cin >> ho[i];
			sum += ho[i];
		}


		int k=0;
		int rsum = 0;
		int remain = n;
		int select = 0;
		k = m / remain;
		if (sum < m) {
			cout << sum << "\n";
		}
		else {
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					if (ho[j] != 0 && ho[j] <= k) {
						m -= ho[j];
						rsum += ho[j];
						remain--;
						select++;
						ho[j] = 0;
					}
					else {
					}
				}

				if (select == 0) {
					break;
				}
				select = 0;
				k = m / remain;
			}
			rsum += k * (remain);
			cout << rsum << "\n";
		}

	}

	return 0;
}