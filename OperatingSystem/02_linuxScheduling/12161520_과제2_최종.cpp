#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

FILE *stream;

int main() {




	int p, v, t; // priority, value, burst time 입력받는 값 3가지
	int size = 0;  // CFS 스케줄링 출력을 위한 변수
	int min;  //cfs에서 vruntime이 제일 작은 값을 저장하는 변수

	freopen_s(&stream, "input.txt", "r", stdin);
	freopen_s(&stream, "output.txt", "w", stdout);
	int time = 0;

	int list[140] = { 0 }; // priority를 입력받았는지 여부와 real time은 받은 개수 저장(다 출력되면 1씩 빼줌)
	vector < queue<pair<int, int> > > rr(100); //round robin schduling을 위한 vector. 우선순위마다 인덱스로 접근하고 값들을 queue에 넣어준다.

	int cfs[40][5] = { 0 }; //cfs 값 저장을 위한 배열 


	vector<int> cfslist; //입력받은 cfslist를 접근 
	while (scanf_s("%d %d %d", &p, &v, &t) != (int)EOF) {	

		if (p < 100) {
			rr[p].push(make_pair(v, t));  //p가 100보다 작으면 rr에 value와 time을 쌍으로 queue에 push해준다.
		}
		else if (p >= 100 && p < 140) {  // p가 100이상 140미만이면 cfs에 저장해준다 
			cfs[p - 100][0] = v;  //value값
			cfs[p - 100][1] = t; //time 값
								 //cfs[p-100][2]=0;  //vruntime저장 초기값=0
			cfs[p - 100][3] = 1200 / (10 - 2 * ((p - 100) / 10));  //vruntime에 매번 추가될 변수
			cfs[p - 100][4] = 0; //time저장용
			cfslist.push_back(p - 100);
		}
		list[p]++;
	}

	size = cfslist.size(); //cfs변수의 개수


						   //RR SCHEDULING
	pair<int, int>temp;
	bool tf = false;//endl 출력 확인을 위한 변수
	for (int i = 0; i < 100; i++) {
		while (list[i] > 0) { //rr 0~99까지 list안에 값이 있다면 값이 없어질때까지 모두 출력한다.
			tf = true;
			temp = rr[i].front(); //queue제일 앞에있는 값을 가져온다.
			rr[i].pop();

			//2초동안 출력한다. 
			for (int j = 0; j < 2; j++) {
				if (temp.second > 0) {
					cout << i << " " << temp.first << " ";
					temp.second--;
				}
			}
			//burst time이 남아있을 경우 다시 뒤로 넣어준다.
			if (temp.second > 0) {
				rr[i].push(make_pair(temp.first, temp.second));
			}
			//burst time을 다했을 경우 list[i]에서 삭제해준다.
			else if (temp.second == 0)list[i]--;
		}
		if (tf == true) { cout << "\n"; tf = false; }
	}


	//////CFS SCHEDULING 

	//처음 -> 우선순위대로 출력 
	for (int i = 0; i < 40; i++) {
		if (list[i + 100] == 1) {
			cout << 100 + i << " " << cfs[i][0] << "\n";
			cfs[i][1]--; //burst time을 빼준다.
			cfs[i][2] += cfs[i][3]; //vruntime을 바꿔준다.
			if (cfs[i][1] == 0) { //burst time이 끝나면 지워준다.
				size--; list[i + 100]--;
			}
			cfs[i][4] = time;
			time++;
		}
	}

	int x; //임시변수
	bool swap;

	while (size>0) { //출력할 cfs가 남아있다면 
		time++;
		//vruntime들의 최솟값을 찾는다.
		min = 9999999;
		for (int i = 0; i < cfslist.size(); i++) {
			if (list[100 + cfslist[i]] == 1 && min > cfs[cfslist[i]][2]) {  //list에 값이 존재할 때만 비교한다.
				min = cfs[cfslist[i]][2];
			}
		}

		//cfs리스트의 값들을 time순으로 정렬해준다.
		for (int i = 0; i < cfslist.size(); i++) {
			for (int j = 0; j < cfslist.size()-1; j++) {
				if (cfs[cfslist[j]][4] > cfs[cfslist[j+1]][4]) {
					int temp = cfslist[j];
					cfslist[j] = cfslist[j + 1];
					cfslist[j + 1] = temp;
				}
			}
		}

		//지금까지를 비교해서 vruntime이 min값과 같은 task를 출력해준다.
		for (int i = 0; i <= time; i++) {
			for (int j = 0; j < cfslist.size(); j++) {
				x = cfslist[j];
				if (cfs[x][2] == min && list[x + 100] == 1) { //처음 설정할때와 같다.
					cout << 100 + x << " " << cfs[x][0] << "\n";
					cfs[x][1]--;
					cfs[x][2] += cfs[x][3];
					if (cfs[x][1] == 0) {
						size--;
						list[x + 100]--;
					}
					cfs[x][4] = time;
				}
			}
		}
	}


	return 0;
}


