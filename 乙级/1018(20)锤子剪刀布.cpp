#include <stdio.h>

int main() {
	int times, A_C = 0, A_BCJ[3] = { 0 }, B_BCJ[3] = { 0 }; //BCJ�ֱ��ǲ������ӡ�����Ӯ�ô����������ŷ�����ĸ˳��
	int A_record[3] = { 0 }, B_record[3] = { 0 }; //record�ֱ���ʤƽ������
	char A, B;

	scanf("%d", &times);
	for (int i = 0; i < times; i++) {
		scanf(" %c %c", &A, &B);
		if (A == B) {
			A_record[1]++;
			B_record[1]++;
		}
		else if (A == 'B' && B == 'C') {
			A_record[0]++;
			B_record[2]++;
			A_BCJ[0]++;
		}
		else if (A == 'B' && B == 'J') {
			A_record[2]++;
			B_record[0]++;
			B_BCJ[2]++;
		}
		else if (A == 'C' && B == 'B') {
			A_record[2]++;
			B_record[0]++;
			B_BCJ[0]++;
		}
		else if (A == 'C' && B == 'J') {
			A_record[0]++;
			B_record[2]++;
			A_BCJ[1]++;
		}
		else if (A == 'J' && B == 'C') {
			A_record[2]++;
			B_record[0]++;
			B_BCJ[1]++;
		}
		else if (A == 'J' && B == 'B') {
			A_record[0]++;
			B_record[2]++;
			A_BCJ[2]++;
		}
	}

	//���
	for (int i = 0; i < 3; i++) {
		if (i == 0)
			printf("%d", A_record[i]);
		else
			printf(" %d", A_record[i]);
	}
	printf("\n");
	for (int i = 0; i < 3; i++) {
		if(i == 0)
			printf("%d", B_record[i]);
		else
			printf(" %d", B_record[i]);
	}
	printf("\n");

	//������ʤ������������
	int max = -1, maxid;
	for (int i = 0; i < 3; i++) {
		if (A_BCJ[i] > max) {
			max = A_BCJ[i];
			maxid = i;
		}
	}
	if (maxid == 0)
		printf("B");
	else if (maxid == 1)
		printf("C");
	else
		printf("J");
	printf(" ");

	max = -1;
	for (int i = 0; i < 3; i++) {
		if (B_BCJ[i] > max) {
			max = B_BCJ[i];
			maxid = i;
		}
	}
	if (maxid == 0)
		printf("B");
	else if (maxid == 1)
		printf("C");
	else
		printf("J");
	printf("\n");
	return 0;
}