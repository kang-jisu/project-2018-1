#include <iostream>
#include <algorithm>
using namespace std;


int main() {

	std::ios::sync_with_stdio(false);
	int T;
	cin >> T;
	int n;
	int ta, tb;
	int wid, hei;
	for (int t = 0; t < T; t++) {
		cin >> n;
		int amin = 10001;
		int amax = -10001;
		int bmin = 10001;
		int bmax = -10001;
		for (int i = 0; i < n; i++) {
			cin >> ta >> tb;
			if (ta < amin)amin=ta;
			if (ta > amax)amax = ta;
			if (tb < bmin)bmin = tb;
			if (tb > bmax)bmax = tb;
		}
		//cout << amin << " " << amax << " " << bmin << " " << bmax << endl;
		if (amax == amin || bmin == bmax)cout << "0\n";
		else {
			wid = amax - amin;
			hei = bmax - bmin;
			cout << wid * hei << "\n";
		}

	}
	return 0;
}