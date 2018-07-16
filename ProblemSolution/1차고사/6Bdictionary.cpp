#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
int main() {
	std::ios::sync_with_stdio(false);

	int t;
	cin >> t;

	string s;
	vector<int> arr;
	for (int tc = 0; tc < t; tc++) {

		cin >> s;
		for (int i = 0; i < s.length(); i++) {
			arr.push_back(s[i]);
		}//ÁÖÀÇ


		if (next_permutation(arr.begin(), arr.end())) {

			for (int i = 0; i < (int)arr.size(); i++)cout << (char)(arr[i]);
			cout << "\n";
		}
		else {
			prev_permutation(arr.begin(), arr.end());

			for (int i = 0; i < (int)arr.size(); i++)cout << (char)(arr[i]);
			cout << "\n";
		}


		arr.clear();
	}
	return 0;
}