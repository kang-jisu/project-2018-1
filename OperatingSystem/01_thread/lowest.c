#include <stdlib.h>
#include <pthread.h>
#include <stdio.h>

//배열의 시작과 끝 index넘겨주는 구조체
typedef struct tTHREAD
{
	int s;//start index
	int e;//end index
	int index;//결과res배열의 index
	int spin; //spinlock
}THREAD;


void *findlow(void *p);//개별thread ->lowest숫자찾기 
void *parentfindlow(void *arg);//처음 부르는 부모 thread

pthread_t tid[3]; //thread의 id

int arr[10]; //입력 받는 배열 ,전역변수
int res[3] = { 0 }; //3개 thread의 결과값 저장
int cnt = 0; //spin_lock확인 위한 변수

int main(int argc, char *argv[]) {

	pthread_t parentid; //parent thread 생성 id
	pthread_attr_t attr;

	pthread_attr_init(&attr);

	//parent thread 에 넘겨줄 struct
	//start index:0 end index : 10(-1)
	THREAD st;
	st.s = 0;
	st.e = 10;

	//부모 thread 생성
	pthread_create(&parentid, &attr, parentfindlow, (void*)&st);

	int result; //lowest result
	pthread_join(parentid, (void**)&result); //parent thread 끝나면 result에 값 반환

	printf("\nlowest:%d\n", result);

	return 0;
}

//개별thread ->lowest숫자찾기 . 인자는 index들의 struct
void *findlow(void *p) {


	//인자로 받은 struct 값들 얻어옴
	THREAD* pp = (THREAD*)p;
	int s = pp->s;
	int e = pp->e;
	int i = pp->index;
	int spinlo = pp->spin;


	while (cnt != spinlo) {
	//전 쓰레드가 끝나기전까지는 기다림
	}


	//startindex ~ endindex 까지 작은 값 계산
	int min = arr[s];
	for (int j = s; j<e; j++) {
		if (min>arr[j])min = arr[j];
	}

	//결과값 res배열에 넣어줌
	res[i] = min;


	////printf("\n%d번째쓰레드cnt%d 결과%d\n",i,cnt,res[i]);


	//printf("\nthread생성 min값은%d\n", res[i]);
	cnt++;//(spinlock위한 변수 , thread가 몇개 끝났는지 )
	pthread_exit(0);

}

//부모 thread 생성 인자는 struct 
void *parentfindlow(void *arg) {

	//입력값 받음
	freopen("input.txt", "r", stdin);

	//인자 값 얻어옴. 인덱스는 0~10(10미만)
	THREAD* pp = (THREAD*)arg;
	int s = pp->s;
	int e = pp->e;

	//arr[10]에 입력받음
	for (int i = s; i < e; i++) {
		scanf("%d", &arr[i]);
	}

	pthread_attr_t attr;
	pthread_attr_init(&attr);


	//생성할 3개의 thread에 인덱스구조체 전달하기 위해 구조체 생성
	THREAD first;
	first.s = 0;
	first.e = 3;
	first.index = 0;
	first.spin = 0;

	THREAD second;
	second.s = 3;
	second.e = 6;
	second.index = 1;
	second.spin = 1;

	THREAD third;
	third.s = 6;
	third.e = 10;
	third.index = 2;
	third.spin = 2;

	//thread 3개 생성 
	pthread_create(&tid[0], &attr, findlow, (void *)&first);

	pthread_create(&tid[1], &attr, findlow, (void *)&second);

	pthread_create(&tid[2], &attr, findlow, (void *)&third);

	while (cnt<3) {} //cnt가 3개(thread 3개 값 반환)끝날때까지 기다림
	
	//3개의 쓰레드에서 받은 res값중 min값 계산
	int min = res[0];

	for (int i = 0; i < 3; i++) {
		if (min>res[i])min = res[i];
	}

	//min값을 반환하며 부모쓰레드 종료
	pthread_exit((void*)min);


}