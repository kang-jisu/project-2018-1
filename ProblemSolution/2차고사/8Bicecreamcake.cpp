#include <iostream>
#include <queue>
#include <vector>
using namespace std;


int main() {

	std::ios::sync_with_stdio(false);
	int n;
	cin >> n;
	int x, y;
	int f[8] = { 0 };

	vector <queue<int>> v(256);

	int cnt = -1;
	unsigned int fr = 0;
	unsigned int o = 0;
	unsigned int temp = 0;
	unsigned int res = 0;

	for (int t = 0; t < n; t++) {

		char r;
		cin >> r;
		if (r == 'D') {
			cin >> x;
			int ischange = f[x];
			f[x]++;
			fr |= 1 << x;
			if (f[x] == 1 && ischange != f[x]) {
				int job = 9999999;
				int k;
				for (int i = 0; i < 256; i++) {
					if (((fr&i) == i) && !v[i].empty()) {
						if (job > v[i].front()) {
							job = v[i].front();
							k = i;
						}
					}
				}
				if (job != 9999999) {
					cout << job << "\n";
					v[k].pop();
					for (int i = 0; i < 8; i++) {
						if (k % 2 == 1)
							f[i]--;
						k /= 2;
					}
					for (int i = 0; i < 8; i++) {
						if (f[i] == 0) {
							temp = 255;
							temp ^= 1 << i;
							fr &= temp;
						}
					}
				}

			}
	
		
		}
		else if (r == 'O') {
			o = 0;
			cin >> y;
			cnt++;
			for (int j = 0; j < y; j++) {
				int tem;
				cin >> tem;
				o |= 1 << tem;
			}

			res = fr & o;

			if (res == o) {
				cout << cnt << "\n";
				for (int i = 0; i < 8; i++) {
					if (1<<i == (o & (1 << i))) {
						f[i]--;
						if (f[i] == 0) {
							temp = 255;
							temp ^= 1 << i;
							fr &= temp;
						}
					}
				}
			}
			else {
				v[(int)o].push(cnt);
			}
		}
	
	}
	v.clear();
	return 0;
}
