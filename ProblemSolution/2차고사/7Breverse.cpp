#include <iostream>
#include <string>

using namespace std;
int main() {
	std::ios::sync_with_stdio(false);

	int tc;
	cin >> tc;
	string a, b;
	string c, d;
	for (int t = 0; t < tc; t++) {
		cin >> a;

		b = "";
		for (int i = a.length() - 1; i >= 0; i--) {
			b += a[i];
		}
		c = to_string(stoi(a) + stoi(b));
		d = "";
		for (int i = c.length() - 1; i >= 0; i--) {
			d += c[i];
		}

		if (c.compare(d)==0)cout << "YES\n";
		else cout << "NO\n";
	}


	return 0;
}