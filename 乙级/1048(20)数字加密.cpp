#include <stdio.h>
#include <string.h>

#define MAXCHAR 101

/*���������������˼Ӧ�þ������һ������λ����С����Ҫ��ǰ���0������*/

char encodeOdd(char cA, char cB) {
	int num = cA + cB - '0' * 2;
	num %= 13;
	if (num < 10)
		return num + '0';
	else switch (num)
	{
	case(10):return 'J';
	case(11):return 'Q';
	case(12):return 'K';
	}
}

char encodeEven(char cA, char cB) {
	if (cB - cA < 0)
		return cB - cA + 10 + '0';
	else
		return cB - cA + '0';
}

int main() {
	char numA[MAXCHAR], numB[MAXCHAR], numAns[MAXCHAR] = { '\0' };
	scanf("%s %s", numA, numB);
	int id1 = strlen(numA) - 1; //����id1��������A��ĩλID
	int id2 = strlen(numB) - 1; //���id�Ǵ�0��ʼ�ģ�����idΪż����λ����������
	int isOdd = 1;
	if (id2 >= id1) {
		while (id1 >= 0) {
			if (isOdd) {
				numAns[id2] = encodeOdd(numA[id1], numB[id2]); //���һλ���Ǹ�λ����˴Ӻ���ǰ���ǰ���������ż����������
				isOdd = 0;
			}
			else {
				numAns[id2] = encodeEven(numA[id1], numB[id2]);
				isOdd = 1;
			}
			id1--; id2--;
		}
		while (id2 >= 0) {//������ǰ��û���ˣ�����0������������ʵ���䣬����ֱ�Ӹ��Ʊ��������м���
			numAns[id2] = numB[id2];
			id2--;
		}
	}
	else {//��������ǰ��û���ˣ�����0���ᵼ�������֣������Ҫ����
		while (id2 >= 0) {
			if (isOdd) {
				numAns[id1] = encodeOdd(numA[id1], numB[id2]);
				isOdd = 0;
			}
			else {
				numAns[id1] = encodeEven(numA[id1], numB[id2]);
				isOdd = 1;
			}
			id1--; id2--;
		}
		while (id1 >= 0) {
			if (isOdd) {
				numAns[id1] = encodeOdd(numA[id1], '0');
				isOdd = 0;
			}
			else {
				numAns[id1] = encodeEven(numA[id1], '0');
				isOdd = 1;
			}
			id1--;
		}
	}
	printf("%s\n", numAns);
	return 0;
}