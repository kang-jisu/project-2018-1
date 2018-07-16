#include <iostream>
#include <bitset>

using namespace std;
bitset<30000001> bset;
int arr[1000001];
int main() {
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	int T;
	cin >> T;
	int cnt;
	int n;
	int x;
	for (int t = 0; t < T; t++) {
		bset.reset();
		cnt = 0;
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> x;
			bset.set(x);
		}
		for (int i = 0; i < n; i++) {
			cin >> x;
			if (bset[x] == 0) {
				arr[cnt++] = x;
			}
		}
		if (cnt == 0)cout << "0\n";
		else {
			for (int i = 0; i < cnt; i++) {
				cout << arr[i] << " ";
			}
			cout << "\n";
		}
	}

	return 0;
}