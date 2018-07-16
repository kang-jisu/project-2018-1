#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <set>

using namespace std;

int main() {
	std::ios::sync_with_stdio(false);

	int t;
	cin >> t;
	string a, b;
	bool result;
	for (int tc = 0; tc < t; tc++) {
		cin >> a >> b;
		int arr[26] = { 0 };
		
		result = true;
		for (int i = 0; i < a.length(); i++) {
			arr[a[i] - 'A']++;
		}

		for (int i = 0; i < b.length(); i++) {
			if (arr[b[i] - 'A'] >= 1) {
				arr[b[i] - 'A'] = 2;
			}
			else if (arr[b[i] - 'A'] == 0) {
				result = false;
				break;
			}
		}

		if (result == false) {
			cout << "NO\n";
			continue;
		}
		else {
			for (int i = 0; i < 26 && result!=false; i++) {
				if (arr[i] == 1) {
					cout << "NO\n";
					result = false;
				}
			}
			if (result == true)cout << "YES\n";
		}

	}



	return 0;
}