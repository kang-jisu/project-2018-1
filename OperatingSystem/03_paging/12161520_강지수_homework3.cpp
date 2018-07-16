#include <iostream>
#include <stdio.h>
using namespace std;

FILE *stream;

int TLB[32][2]; //TLB �迭 TLB[][0]�� page #, TLB[][1]�� frame #
int frames[256][2]; //frame no.�� �ε����� �ϴ� frame table. [0]�� free or used, [1]�� page number
int ptable[256]; //page no.�� �ε����� �ϴ� page table ���� frame no.
int main() {
	
	freopen_s(&stream, "memory_manager_addresses.txt", "r", stdin);

	//logical address���� �Է¹ް� page number�� offset�� ������ ����
	int addr;  //�Է¹޴� logical number
	int pageNo; //page no.
	int offset; //offset

	int fcnt = 0;//frame table�� �ε����� �� frame no. (+ frame table�� �ִ� �� ����count)

	//tlb fifo�� ���� ����, ó���� ����·� �ʱ�ȭ
	int front = 0;
	int rear = 0;

	bool tlbcheck = false; //TLB�� hit/miss���� Ȯ���ϱ� ���� ����

	//tlb hit ratio üũ
	int hcnt = 0; //�и�(��ü ���)
	int hit = 0;  //hit�� �� count

	//TLB ,page table �� -1�� �ʱ�ȭ ( ���� 0�� �����Ƿ�)
	for (int i = 0; i < 33; i++) {
		TLB[i][0] = -1;
		TLB[i][1] = -1;
	}
	for (int i = 0; i < 256; i++) {
		ptable[i] = -1;
		frames[i][1] = -1;
	}

	freopen_s(&stream, "Physical.txt", "w", stdout);
	while (scanf_s("%d", &addr) != (int)EOF) {
		hcnt++;//��ü ����� �� ����(hit ratio ��� �и�)

		pageNo = (addr & 65280) >> 8; //page no.��� 9~15��° bit ����
		offset = addr & 255; // offset ��� 1~8��° bit ����

		tlbcheck = false; //tlbcheck���� �ʱ�ȭ
		
		//TLB hit ���� Ȯ��
		for (int i = 0; i < 32; i++) {
			if (TLB[i][0] == pageNo) { //�迭�� �� �� page no.�� ��ġ�ϴ°� �ִٸ� hit
				tlbcheck = true;
				hit++;
				cout << TLB[i][1] * 256 + offset <<" "; //physical address���
				break;
			}
		}

		//miss (TLB hit X) �� ���
		if(tlbcheck==false) {
			//������ page no.���� ���� �� ���ٸ� page table�� frame table�� ���� �־��ش�.
			if (ptable[pageNo] == -1) {
				ptable[pageNo] = fcnt;
				frames[fcnt][0] = 1; //used ǥ��
				frames[fcnt][1] = pageNo;

				fcnt++;//�������� mapping�� ���� frame number����������
			}

			//fifo ��� < ���� queue ���� > ���� tlb�� �� ����
			//��á�ٸ� first in �Ȱ��� �������� �� ��ġ�� �ֱ� ���ؼ�
			//front ���� ��ĭ �̵������ش�.
			if ((rear + 1) % 32 == front) { 
				front = (front + 1) % 32;
			}
			TLB[rear][0] = pageNo;
			TLB[rear][1] = ptable[pageNo];
			rear = ++rear % 32;
			
			cout << ptable[pageNo] * 256 + offset << " ";  //physical address ���
			
		}

	}
	cout << "\n";


	freopen_s(&stream, "TLB hit ratio.txt", "w", stdout);
	cout.precision(4);
	cout << "hit ratio :" << (double)hit / hcnt << endl;
		for (int i = 0; i < 32; i++) {
			cout << i << ": " <<"("<<TLB[i][0] << ", "<<TLB[i][1]<<")"<<endl;
		}
	//freopen_s(&stream, "page table.txt", "w", stdout);
	//for (int i = 0; i < 256; i++) {
	//	if (ptable[i] == -1) cout << i << ": " << "-" << endl;
	//else cout << i<<": "<<ptable[i] << endl;
	//}
	freopen_s(&stream, "Frame_table.txt", "w", stdout);
	for (int i = 0; i < 256; i++) {
		cout << i << " " << frames[i][0] << " " << frames[i][1] << endl;
	}

	return 0;
}