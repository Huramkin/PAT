#include <stdio.h>

#define MAXSTU 100000

int main() {
	int stunum, score, checknum, scorenum[101] = { 0 };
	scanf("%d", &stunum);
	for (int i = 0; i < stunum; i++) {
		scanf("%d", &score);
		scorenum[score]++;
	}
	scanf("%d", &checknum);
	//��һ�������ǰ�治�ÿո�
	scanf("%d", &score);
	printf("%d", scorenum[score]);
	//����ÿ�����ǰ���һ��
	for (int i = 1; i < checknum; i++) {
		scanf(" %d", &score);
		printf(" %d", scorenum[score]);
	}
	return 0;
}