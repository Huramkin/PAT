#include <stdio.h>
#include <algorithm>
using namespace std;

int main() {
	int num, arr[4];
	scanf("%d", &num);
	//��һ���ύ��һ�����������뵽����corner case����������0000��6174,���Ҫ�����������α�����һ�Σ�����whileѭ����Ϊdo whileѭ��
	do{
		int des = 0, aes = 0;
		for (int newnum = num, i = 0; i < 4; i++) {
			arr[i] = newnum % 10;
			newnum /= 10;
		}
		sort(arr, arr + 4);
		for (int i = 0; i < 4; i++) {
			aes = aes * 10 + arr[i];
		}
		for (int i = 3; i >= 0; i--) {
			des = des * 10 + arr[i];
		}
		num = des - aes;
		printf("%04d - %04d = %04d\n", des, aes, num);
	} while (num != 0 && num != 6174);
	return 0;
}