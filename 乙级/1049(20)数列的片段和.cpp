#include <stdio.h>

//!!!����ת��������������

/*˼·�����еĹ���������ܹ���n�������Ǿ���n + (n - 1) + (n - 2) + ... + 1 = (n + 1) * n / 2��Ƭ�Σ�
���г��ֵ�һ��������1 * n�Σ��ڶ������ֳ���2 * (n - 1)�Σ�����������3 * (n - 2)��...���һ�����ֳ���n * 1�Ρ�
��˾Ϳ��Լ�����ˡ�*/

int main() {
	int num;
	double number, sum = 0;
	scanf("%d", &num);
	int times1 = num, times2 = 1;
	for (int i = 0; i < num; i++) {
		scanf("%lf", &number);
		/*����Ҫע�⣬ǰ������intҪǿת��double�ڼ��㣬�����������������ĳЩ���Ե�����ˡ�C������һ������ֻ��һ�����ݳɷ֣�
		���������кü������㡣���ǰ������int��ǿת����ô����int��int�����Ϊint���ٺͺ����double��ˣ����Ϊdouble�������о�
		�����������ǰ������ǿת����ô��������double��ˣ����ͻ��С�ˡ�����Ҳ������number * times1 * times2��Ч����ǿת
		һ������Ϊǰ��double��int��int�ͻ�ת��double�����Ҳ��double������int��ˣ�ͬ��intҲҪת��double�ٳˣ�������ʵҲ�൱��
		����double���ˡ�*/
		sum += (double) times1 * (double) times2 * number;
		times1--; times2++;
	}
	printf("%.2f\n", sum);
	return 0;
}