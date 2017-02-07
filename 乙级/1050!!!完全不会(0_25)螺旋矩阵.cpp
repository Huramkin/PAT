#include <stdio.h>
#include <math.h>
#include <algorithm>
using namespace std;

/*˼·����������m��n����������*/

#define MAXNUM 10000

int numarr[MAXNUM], ansarr[MAXNUM][MAXNUM] = { 0 }; //������ע�⣬ansarr�������int main����һ����ҵģ���Ϊջ�Ͽռ�϶������Է�������顣����ȫ�ֱ�����������Ŀռ��ܶ࣬������ȫ�ֱ����Ϳ���

bool cmp(int a, int b) {
	return a > b;
}

int main() {
	int N;
	scanf("%d", &N);

	//������������size
	int row = N, col = 1; //��������N���������������
	for (int i = 2; i < sqrt(N); i++) { //����ó���N��ƽ�������ٴ�col��Ҫ����row��
		if (N % i == 0) {
			if (N / i - i < row - col) {
				row = N / i;
				col = i;
			}
		}
	}

	//�������в�����
	for (int i = 0; i < N; i++) 
		scanf("%d", &numarr[i]);
	sort(numarr, numarr + N, cmp); //���ս�������

	//������
	int k = 0; //��¼��numarr�еĵ��λ��
	int i = 0; //ansarr�е�������
	int j = 0; //ansarr�е�������
	int col_reduce = 0, row_reduce = 0;
	while (k < N) {
		for (; i < col - col_reduce; i++) {
			ansarr[j][i] = numarr[k];
			k++;
		}
		for (; j < row - row_reduce; j++) {
			ansarr[j][i] = numarr[k];
			k++;
		}
		for (; i >= col_reduce; i--) {
			ansarr[j][i] = numarr[k];
			k++;
		}
		for (; j >= row_reduce; j--) {
			ansarr[j][i] = numarr[k];
			k++;
		}
		col_reduce++; row_reduce++;
	}

	//��ӡ
	for (int idx1 = 0; idx1 < row; idx1++) {
		for (int idx2 = 0; idx2 < col; idx2++) {
			if (idx2 == 0)
				printf("%d", ansarr[idx1][idx2]);
			else
				printf(" %d", ansarr[idx1][idx2]);
		}
		printf("\n");
	}
	return 0;
}