#include <stdlib.h>
#include <pthread.h>
#include <stdio.h>

//�迭�� ���۰� �� index�Ѱ��ִ� ����ü
typedef struct tTHREAD
{
	int s;//start index
	int e;//end index
	int index;//���res�迭�� index
	int spin; //spinlock
}THREAD;


void *findlow(void *p);//����thread ->lowest����ã�� 
void *parentfindlow(void *arg);//ó�� �θ��� �θ� thread

pthread_t tid[3]; //thread�� id

int arr[10]; //�Է� �޴� �迭 ,��������
int res[3] = { 0 }; //3�� thread�� ����� ����
int cnt = 0; //spin_lockȮ�� ���� ����

int main(int argc, char *argv[]) {

	pthread_t parentid; //parent thread ���� id
	pthread_attr_t attr;

	pthread_attr_init(&attr);

	//parent thread �� �Ѱ��� struct
	//start index:0 end index : 10(-1)
	THREAD st;
	st.s = 0;
	st.e = 10;

	//�θ� thread ����
	pthread_create(&parentid, &attr, parentfindlow, (void*)&st);

	int result; //lowest result
	pthread_join(parentid, (void**)&result); //parent thread ������ result�� �� ��ȯ

	printf("\nlowest:%d\n", result);

	return 0;
}

//����thread ->lowest����ã�� . ���ڴ� index���� struct
void *findlow(void *p) {


	//���ڷ� ���� struct ���� ����
	THREAD* pp = (THREAD*)p;
	int s = pp->s;
	int e = pp->e;
	int i = pp->index;
	int spinlo = pp->spin;


	while (cnt != spinlo) {
	//�� �����尡 �������������� ��ٸ�
	}


	//startindex ~ endindex ���� ���� �� ���
	int min = arr[s];
	for (int j = s; j<e; j++) {
		if (min>arr[j])min = arr[j];
	}

	//����� res�迭�� �־���
	res[i] = min;


	////printf("\n%d��°������cnt%d ���%d\n",i,cnt,res[i]);


	//printf("\nthread���� min����%d\n", res[i]);
	cnt++;//(spinlock���� ���� , thread�� � �������� )
	pthread_exit(0);

}

//�θ� thread ���� ���ڴ� struct 
void *parentfindlow(void *arg) {

	//�Է°� ����
	freopen("input.txt", "r", stdin);

	//���� �� ����. �ε����� 0~10(10�̸�)
	THREAD* pp = (THREAD*)arg;
	int s = pp->s;
	int e = pp->e;

	//arr[10]�� �Է¹���
	for (int i = s; i < e; i++) {
		scanf("%d", &arr[i]);
	}

	pthread_attr_t attr;
	pthread_attr_init(&attr);


	//������ 3���� thread�� �ε�������ü �����ϱ� ���� ����ü ����
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

	//thread 3�� ���� 
	pthread_create(&tid[0], &attr, findlow, (void *)&first);

	pthread_create(&tid[1], &attr, findlow, (void *)&second);

	pthread_create(&tid[2], &attr, findlow, (void *)&third);

	while (cnt<3) {} //cnt�� 3��(thread 3�� �� ��ȯ)���������� ��ٸ�
	
	//3���� �����忡�� ���� res���� min�� ���
	int min = res[0];

	for (int i = 0; i < 3; i++) {
		if (min>res[i])min = res[i];
	}

	//min���� ��ȯ�ϸ� �θ𾲷��� ����
	pthread_exit((void*)min);


}