#include <iostream>
using namespace std;

int main() {

	std::ios::sync_with_stdio(false);


	int t;
	cin >> t;
	int r;
	int score;
	int a, b;
	for (int tc = 0; tc < t; tc++) {
		cin >> r >> score;
		for (int k = 0; k < score; k++) {
			cin >> a >> b;

			if (a == b)cout << "1\n";
			else {
				if (a > b) {
					if (a - b > r - a + 2) {
						cout << "0\n";
					}
					else cout << "1\n";

				}
				else if (a < b) {

					if (b - a > r - b + 1) {
						cout << "0\n";
					}
					else cout << "1\n";

				}

			}
		}
	}
	return 0;
}