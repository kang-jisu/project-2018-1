#include <iostream>
#include <stdio.h>
using namespace std;

FILE *stream;

int TLB[32][2]; //TLB 배열 TLB[][0]이 page #, TLB[][1]이 frame #
int frames[256][2]; //frame no.를 인덱스로 하는 frame table. [0]은 free or used, [1]은 page number
int ptable[256]; //page no.을 인덱스로 하는 page table 값은 frame no.
int main() {
	
	freopen_s(&stream, "memory_manager_addresses.txt", "r", stdin);

	//logical address값을 입력받고 page number와 offset을 저장할 변수
	int addr;  //입력받는 logical number
	int pageNo; //page no.
	int offset; //offset

	int fcnt = 0;//frame table의 인덱스가 될 frame no. (+ frame table에 있는 값 개수count)

	//tlb fifo를 위한 변수, 처음엔 빈상태로 초기화
	int front = 0;
	int rear = 0;

	bool tlbcheck = false; //TLB의 hit/miss여부 확인하기 위한 변수

	//tlb hit ratio 체크
	int hcnt = 0; //분모(전체 경우)
	int hit = 0;  //hit된 수 count

	//TLB ,page table 값 -1로 초기화 ( 값에 0도 있으므로)
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
		hcnt++;//전체 경우의 수 증가(hit ratio 계산 분모)

		pageNo = (addr & 65280) >> 8; //page no.계산 9~15번째 bit 추출
		offset = addr & 255; // offset 계산 1~8번째 bit 추출

		tlbcheck = false; //tlbcheck변수 초기화
		
		//TLB hit 여부 확인
		for (int i = 0; i < 32; i++) {
			if (TLB[i][0] == pageNo) { //배열의 값 중 page no.와 일치하는게 있다면 hit
				tlbcheck = true;
				hit++;
				cout << TLB[i][1] * 256 + offset <<" "; //physical address출력
				break;
			}
		}

		//miss (TLB hit X) 인 경우
		if(tlbcheck==false) {
			//이전에 page no.값이 들어온 적 없다면 page table과 frame table에 값을 넣어준다.
			if (ptable[pageNo] == -1) {
				ptable[pageNo] = fcnt;
				frames[fcnt][0] = 1; //used 표시
				frames[fcnt][1] = pageNo;

				fcnt++;//다음차례 mapping을 위해 frame number증가시켜줌
			}

			//fifo 방식 < 원형 queue 구현 > 으로 tlb에 값 저장
			//꽉찼다면 first in 된것을 내보내고 그 위치에 넣기 위해서
			//front 값을 한칸 이동시켜준다.
			if ((rear + 1) % 32 == front) { 
				front = (front + 1) % 32;
			}
			TLB[rear][0] = pageNo;
			TLB[rear][1] = ptable[pageNo];
			rear = ++rear % 32;
			
			cout << ptable[pageNo] * 256 + offset << " ";  //physical address 출력
			
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