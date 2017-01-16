#include <stdio.h>
#include <algorithm>

using namespace std;

int findMaxNum(unsigned int numarr[], unsigned long int mult, int start, int end) {//���ֲ��ҵ�˼��
	if (start == end) {
		if (numarr[start] <= mult)
			return start;
		else
			return start - 1;
	}
	if (numarr[(start + end) / 2] < mult)
		return findMaxNum(numarr, mult, (start + end) / 2 + 1, end);
	else if (numarr[(start + end) / 2] > mult)
		return findMaxNum(numarr, mult, start, (start + end) / 2 - 1);
	else //ǡ���ҵ���ȵĵ㣨�������������û��ֵ�ظ��ĵ㣬��֪���Բ��ԣ�
		return (start + end) / 2;
}

int main() {
	int num;
	unsigned int p, numarr[100000];
	scanf("%d%d", &num, &p);
	for (int i = 0; i < num; i++) {
		scanf("%d", &numarr[i]);
	}
	
	sort(numarr, numarr + num);
	int ans, maxans = 0;
	for (int i = 0; i < num; i++) {
		unsigned long int mult = numarr[i] * p;
		ans = findMaxNum(numarr, mult, i, num - 1) - i + 1;
		if (ans > maxans)
			maxans = ans;
		if (num - i - 1 < ans) //���ʣ�µ����е�������û�����д𰸸ߣ���ô������Ĵ𰸾Ͳ����ܳ������еĴ𰸣�����û��Ҫ����
			break;
	}
	printf("%d\n", maxans);
	return 0;
}