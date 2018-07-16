#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

FILE *stream;

int main() {




	int p, v, t; // priority, value, burst time �Է¹޴� �� 3����
	int size = 0;  // CFS �����ٸ� ����� ���� ����
	int min;  //cfs���� vruntime�� ���� ���� ���� �����ϴ� ����

	freopen_s(&stream, "input.txt", "r", stdin);
	freopen_s(&stream, "output.txt", "w", stdout);
	int time = 0;

	int list[140] = { 0 }; // priority�� �Է¹޾Ҵ��� ���ο� real time�� ���� ���� ����(�� ��µǸ� 1�� ����)
	vector < queue<pair<int, int> > > rr(100); //round robin schduling�� ���� vector. �켱�������� �ε����� �����ϰ� ������ queue�� �־��ش�.

	int cfs[40][5] = { 0 }; //cfs �� ������ ���� �迭 


	vector<int> cfslist; //�Է¹��� cfslist�� ���� 
	while (scanf_s("%d %d %d", &p, &v, &t) != (int)EOF) {	

		if (p < 100) {
			rr[p].push(make_pair(v, t));  //p�� 100���� ������ rr�� value�� time�� ������ queue�� push���ش�.
		}
		else if (p >= 100 && p < 140) {  // p�� 100�̻� 140�̸��̸� cfs�� �������ش� 
			cfs[p - 100][0] = v;  //value��
			cfs[p - 100][1] = t; //time ��
								 //cfs[p-100][2]=0;  //vruntime���� �ʱⰪ=0
			cfs[p - 100][3] = 1200 / (10 - 2 * ((p - 100) / 10));  //vruntime�� �Ź� �߰��� ����
			cfs[p - 100][4] = 0; //time�����
			cfslist.push_back(p - 100);
		}
		list[p]++;
	}

	size = cfslist.size(); //cfs������ ����


						   //RR SCHEDULING
	pair<int, int>temp;
	bool tf = false;//endl ��� Ȯ���� ���� ����
	for (int i = 0; i < 100; i++) {
		while (list[i] > 0) { //rr 0~99���� list�ȿ� ���� �ִٸ� ���� ������������ ��� ����Ѵ�.
			tf = true;
			temp = rr[i].front(); //queue���� �տ��ִ� ���� �����´�.
			rr[i].pop();

			//2�ʵ��� ����Ѵ�. 
			for (int j = 0; j < 2; j++) {
				if (temp.second > 0) {
					cout << i << " " << temp.first << " ";
					temp.second--;
				}
			}
			//burst time�� �������� ��� �ٽ� �ڷ� �־��ش�.
			if (temp.second > 0) {
				rr[i].push(make_pair(temp.first, temp.second));
			}
			//burst time�� ������ ��� list[i]���� �������ش�.
			else if (temp.second == 0)list[i]--;
		}
		if (tf == true) { cout << "\n"; tf = false; }
	}


	//////CFS SCHEDULING 

	//ó�� -> �켱������� ��� 
	for (int i = 0; i < 40; i++) {
		if (list[i + 100] == 1) {
			cout << 100 + i << " " << cfs[i][0] << "\n";
			cfs[i][1]--; //burst time�� ���ش�.
			cfs[i][2] += cfs[i][3]; //vruntime�� �ٲ��ش�.
			if (cfs[i][1] == 0) { //burst time�� ������ �����ش�.
				size--; list[i + 100]--;
			}
			cfs[i][4] = time;
			time++;
		}
	}

	int x; //�ӽú���
	bool swap;

	while (size>0) { //����� cfs�� �����ִٸ� 
		time++;
		//vruntime���� �ּڰ��� ã�´�.
		min = 9999999;
		for (int i = 0; i < cfslist.size(); i++) {
			if (list[100 + cfslist[i]] == 1 && min > cfs[cfslist[i]][2]) {  //list�� ���� ������ ���� ���Ѵ�.
				min = cfs[cfslist[i]][2];
			}
		}

		//cfs����Ʈ�� ������ time������ �������ش�.
		for (int i = 0; i < cfslist.size(); i++) {
			for (int j = 0; j < cfslist.size()-1; j++) {
				if (cfs[cfslist[j]][4] > cfs[cfslist[j+1]][4]) {
					int temp = cfslist[j];
					cfslist[j] = cfslist[j + 1];
					cfslist[j + 1] = temp;
				}
			}
		}

		//���ݱ����� ���ؼ� vruntime�� min���� ���� task�� ������ش�.
		for (int i = 0; i <= time; i++) {
			for (int j = 0; j < cfslist.size(); j++) {
				x = cfslist[j];
				if (cfs[x][2] == min && list[x + 100] == 1) { //ó�� �����Ҷ��� ����.
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


