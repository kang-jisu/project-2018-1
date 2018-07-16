#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>

using namespace std;


int main() {
	std::ios::sync_with_stdio(false);

	int arr[100001][2];
	int n,k;
	int r, a, b, c;
	int t;
	cin >> n>>k;

	set<int> s;
	for (int i = 0; i <= n; i++) {
		arr[i][0] = 1;
		arr[i][1] = 1;

	}

	for (int i = 0; i < k; i++) {
		cin >> r;
		if (r == 1) {
			cin >> a >> b >> c;
			int ah = 0;
			int bh = 0;
			int aa = a;
			int bb = b;
			while (arr[aa][0] != 1 || aa != 1) {
				ah++;
				aa = arr[aa][0];
			}
			while (arr[bb][0] != 1 || bb != 1) {
				bh++;
				bb = arr[bb][0];
			}

			if (bh > ah) {
				t = bh;
				bh = ah;
				ah = t;
				t = b;
				b = a;
				a = t;
			}
			

			aa = a;
			bb = b;
			/*cout << aa << bb << ah << bh <<endl;

*/
			for (int k = 0; k < ah - bh; k++) {
				arr[aa][1] = c;
				aa = arr[aa][0];
			}

			for (int k = 0; k < ah - (ah - bh); k++) {
				if (arr[aa][0] == arr[bb][0]) {
					if (aa == bb) {
						break;
					}
					arr[aa][1] = c;
					arr[bb][1] = c;
					break;
				}
				else {
					if(aa != bb) {
						arr[aa][1] = c;
						arr[bb][1] = c;
						aa = arr[aa][0];
						bb = arr[bb][0];
				}
				}
			}

		}
		else if (r == 2) {
			cin >> a >> b;
			arr[a][0] = b;

		}
		else if (r == 3) {
			cin >> a >> b;
			if (a == b) cout << "0\n"; 
			else {
				s.clear();
				int ah = 0;
				int bh = 0;
				int aa = a;
				int bb = b;
				while (arr[aa][0] != 1 || aa != 1) {
					ah++;
					aa = arr[aa][0];
				}
				while (arr[bb][0] != 1 || bb != 1) {
					bh++;
					bb = arr[bb][0];
				}

				if (bh > ah) {
					t = bh;
					bh = ah;
					ah = t;
					t = b;
					b = a;
					a = t;
				}


				aa = a;
				bb = b;
				/*cout << aa << bb << ah << bh << endl;
*/

				for (int k = 0; k < ah - bh; k++) {
					s.insert(arr[aa][1]);
					aa = arr[aa][0];
				}

				for (int k = 0; k < ah - (ah - bh); k++) {
					if (arr[aa][0] == arr[bb][0]) {
						if (aa == bb) {
							break;
						}
						s.insert(arr[aa][1]);
						s.insert(arr[bb][1]);
						break;
					}
					else {
						if (aa != bb) {
							s.insert(arr[aa][1]);
							s.insert(arr[bb][1]);
							aa = arr[aa][0];
							bb = arr[bb][0];
						}
					}
				}

				cout << s.size() << "\n"; }
		}


	/*	for (int x = 0; x <= n; x++) {
			cout << x << " : " << arr[x][0] << " " << arr[x][1] << "\n";
		}
	*/}

	return 0;
}