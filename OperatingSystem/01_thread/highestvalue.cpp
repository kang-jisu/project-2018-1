#include <iostream>
#include <stdlib.h>
#include <pthread.h>
#include <stdio.h>

using namespace std;

int pthcnt = 0; //printf 생성,끝 확인 위한 변수 pthread count

void *runner(void *arg); //sub thread 함수
void *parentrunner(void *arg);//parent thread 함수

int main(int argc, char *argv[]) {
	
	pthread_t parentid;//parent thread id
	pthread_attr_t attr;
	pthread_attr_init(&attr);
	

	//parentthread생성 (4번째인자는의미없음)
	pthread_create(&parentid, &attr, parentrunner, (void*)argv);


	//결과 highest value 값
	int result;
	pthread_join(parentid, (void**)&result); //parentthread 끝나고 결과값 반환

	cout << "maximum number:" << result << "\n";

	return 0;
}

//3x3 배열 highest값 찾는 sub thread (인자는 9개 값 가진 배열)
void *runner(void *arg) {

	//배열 얻어옴
	int *a = (int *)arg;
	
	//배열 값 중 max값 계산
	int max = a[0];
	int k = a[9]; //배열의 9번째인덱스는 pthcnt
	for (int i = 1; i<9; i++) {
		if (max<a[i])max = a[i];
	}
	
	//max값을 반환하며 thread종료
	pthread_exit((void *)max);
}

//main thread(parent thread). 
//여기서 9개 쓰레드 출력후 반환값의 max값을 계산해 main으로 반환
void *parentrunner(void *arg) {
	
	pthread_t tid[9]; //sub thread의 id 배열
	pthread_attr_t attr;
	pthread_attr_init(&attr);

	//input txt 얻어옴
	freopen("highest_input.txt", "r", stdin);
	
	//입력받은 81개 수 arr[9][9]배열에 저장
	int arr[9][10];

	//각 thread의 결과값 res배열에 저장
	int res[9] = { 0 };

	//9x9배열을 3x3배열 9개로 저장
	int a = 0;
	int b = 0;
	int c = 0;

	for (int i = 0; i < 3; i++) {

		for (int j = 0; j < 3; j++) {
			cin >> arr[0][a++];
		}
		for (int j = 3; j < 6; j++) {
			cin >> arr[1][b++];
		}
		for (int j = 6; j < 9; j++) {
			cin >> arr[2][c++];
		}
	}

	a = 0;
	b = 0;
	c = 0;
	for (int i = 3; i < 6; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> arr[3][a++];
		}
		for (int j = 3; j < 6; j++) {
			cin >> arr[4][b++];
		}
		for (int j = 6; j < 9; j++) {
			cin >> arr[5][c++];
		}
	}
	a = 0;
	b = 0;
	c = 0;
	for (int i = 6; i < 9; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> arr[6][a++];
		}
		for (int j = 3; j < 6; j++) {
			cin >> arr[7][b++];
		}
		for (int j = 6; j < 9; j++) {
			cin >> arr[8][c++];
		}
	}
	
	//sub thread 9개 호출  
	for (int i = 0; i <9; i++) {
		arr[i][9] = pthcnt++; //출력으로 확인할 쓰레드 번호 매겨주기위해 [][9]인자에 번호줌 
		pthread_create(&tid[i], &attr, runner, (void *)arr[i]);//sub thread호출
	}

	//join으로 끝날때까지 기다리며 result값 받음
	for (int i = 0; i<9; i++) {
		pthread_join(tid[i], (void**)&res[i]);
	}

	//9개 쓰레드 result값의 최댓값구하기
	int max = res[0];
	//cout << res[0]<<endl;
	for (int i = 1; i < 9; i++) {
		if (max<res[i])max = res[i];
		//cout << res[i]<<endl;
	}

	//최종max값을 반환하며 종료
	pthread_exit((void *)max);


}
