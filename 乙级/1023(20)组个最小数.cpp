#include <stdio.h>

int main() {
	int digits[10];
	for (int i = 0; i < 10; i++) {
		scanf("%d", &digits[i]);
	}
	for (int i = 1; i < 10; i++) { //�Թ�0���ҵ�һ�����ִ�����Ϊ0������
		if (digits[i]) {
			printf("%d", i);
			digits[i]--;
			break;
		}
	}
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < digits[i]; j++) {
			printf("%d", i);
		}
	}
	printf("\n");
	return 0;
}