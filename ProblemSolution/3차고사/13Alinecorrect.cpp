#include <iostream>
#include <set>
using namespace std;


set< pair<int, int> > s1;
set< pair<int, int> > s2;

int scnt = 0;
int sum = 0;
int preval;
int preval2;
set< pair<int, int> >::iterator i1;
set< pair<int, int> >::iterator i2;
void find(int s, int upmin, int downmin) {
	if (s == 1) {
		i1 = s1.find(make_pair(upmin, downmin));
		if (i1 != s1.end()) {
			i1++;
			for (i1; i1 != s1.end(); i1++) {
				if (i1->first != upmin) return;
				if (preval == i1->first)continue;
				scnt++;
				preval = i1->first;
				sum += abs(i1->first - i1->second);
				find(2, i1->second, i1->first);
				//	}
			}
		}
	}
	else if (s == 2) {
		i2 = s2.find(make_pair(upmin, downmin));
		if (i2 != s2.end()) {
			i2++;
			for (i2; i2 != s2.end(); i2++) {
				if (i2->first != upmin) return;
				if (preval2 == i2->first)continue;
				scnt++;
				preval2 = i2->first;
				sum += abs(i2->first - i2->second);
				find(1, i2->second, i2->first);
			}
		}
	}

}

int main() {

	int n;
	cin >> n;
	int a, b;
	int c, d;
	cin >> c >> d;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		s1.insert(make_pair(a, b));
		s2.insert(make_pair(b, a));
	}
	s1.insert(make_pair(100000001, 100000001));
	s2.insert(make_pair(100000001, 100000001));


	set< pair<int, int> >::iterator iter;
	iter = s1.end();
	iter--;

	int mmmax = 0;
	for (iter = s1.begin(); iter != s1.end(); iter++) {
		if (iter->first == 100000001)break;
		scnt = 1;
		sum = abs(iter->first - iter->second);
		find(2, iter->second, iter->first);
		if (mmmax < scnt*(abs(c - d)) + sum)mmmax = scnt * (abs(c - d)) + sum;
	}

	for (iter = s2.begin(); iter != s2.end(); iter++) {
		if (iter->first == 100000001)break;
		scnt = 1;
		sum = abs(iter->first - iter->second);
		find(1, iter->second, iter->first);
		if (mmmax < scnt*(abs(c - d)) + sum)mmmax = scnt * (abs(c - d)) + sum;
	}
	cout << mmmax << "\n";
	s1.clear();
	s2.clear();
	return 0;
}
