#include <stdio.h>

int main() {
	int num;
	char mark;
	scanf("%d %c", &num, &mark);
	int i = 3, sum = 1;
	while (sum + 2*i <= num) {
		sum += 2 * i;
		i += 2;
	}
	i -= 2;//i������һ�еķ��Ÿ�����Ҳ�Ǵ�ӡ��������
	//��ӡ����Ĳ���
	for (int j = 0; j < i / 2; j++) {
		for (int m = 0; m < j; m++)
			printf(" ");
		for (int m = 0; m < i - 2 * j; m++)
			printf("%c", mark);
		printf("\n");
	}
	//��ӡ�м�һ��
	for (int m = 0; m < i / 2; m++)
		printf(" ");
	printf("%c\n", mark);
	//��ӡ����Ĳ���
	for (int j = i / 2 - 1; j >= 0; j--) {
		for (int m = 0; m < j; m++)
			printf(" ");
		for (int m = 0; m < i - 2 * j; m++)
			printf("%c", mark);
		printf("\n");
	}
	printf("%d\n", num - sum);
	return 0;
}