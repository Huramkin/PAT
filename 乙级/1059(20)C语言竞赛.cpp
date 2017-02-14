#include <stdio.h>
#include <math.h>

int rank[10000], checked[10000] = { 0 };

int is_prime(int num) {//���������������1�����򷵻�0
	for (int i = 2; i <= sqrt(num); i++) {
		if (num % i == 0)
			return 0;
	}
	return 1;
}

int main() {
	int stunum, checknum, stuid;
	scanf("%d", &stunum);
	for (int i = 0; i < stunum; i++)
		scanf("%d", &rank[i]);
	
	scanf("%d", &checknum);
	for (int i = 0; i < checknum; i++) {
		scanf("%d", &stuid);
		int find_flag = 0;
		if (checked[stuid]) {
			printf("%04d: Checked\n", stuid);
			continue;
		}
		for (int i = 0; i < stunum; i++) {
			if (rank[i] == stuid) {
				find_flag = 1;
				checked[stuid] = 1;
				if (i == 0)
					printf("%04d: Mystery Award\n", stuid);
				else if (is_prime(i + 1)) //ѧ������������ż�1��������1��ʼ��������Ŵ�0��ʼ��
					printf("%04d: Minion\n", stuid);
				else
					printf("%04d: Chocolate\n", stuid);
				break;
			}
		}
		if (!find_flag) {
			printf("%04d: Are you kidding?\n", stuid);
		}
	}
	return 0;
}