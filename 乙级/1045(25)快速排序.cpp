#include <stdio.h>

/*˼·����������˳������������Σ������ҵ�ʱ�򣬼�¼���ֵ�����ϸ��£����һ��ֵ��Ϊ�����ֵ��˵�����
��ֵ������С����¼������㣻���ҵ���ʱ����¼��Сֵ�����ϸ��£����һ��ֵ��Ϊ����Сֵ��˵���ұߵ�ֵ��������
Ҳ��¼������㡣���ͳ��������¼�����һ���㼴��Ϊ����Сֵ���ֳ�Ϊ�����ֵ���ǾͿ�������Ԫ��*/

#define MAXNUM 100000

int main() {
	int num, numarr[MAXNUM], isMin[MAXNUM] = { 0 }, isMax[MAXNUM] = { 0 };
	scanf("%d", &num);
	//���������Լ��������
	int maxleft = 0;
	for (int i = 0; i < num; i++) {
		scanf("%d", &numarr[i]);
		if (numarr[i] > maxleft) {
			maxleft = numarr[i];
			isMax[i] = 1;
		}
	}

	//�������
	int minright = 1000000001;
	for (int i = num - 1; i >= 0; i--) {
		if (numarr[i] < minright) {
			minright = numarr[i];
			isMin[i] = 1;
		}
	}
	//ͳ�Ƹ�������Ҫ����һ��
	int count = 0;
	for (int i = 0; i < num; i++) {
		if (isMax[i] && isMin[i])
			count++;
	}
	printf("%d\n", count);

	//�������maxҲ��min�ĵ�
	int first_flag = 1;
	for (int i = 0; i < num; i++) {
		if (isMax[i] && isMin[i]) {
			if (first_flag) {
				printf("%d", numarr[i]);
				first_flag = 0;
			}
			else {
				printf(" %d", numarr[i]);
			}
		}
	}
	printf("\n");
	return 0;
}