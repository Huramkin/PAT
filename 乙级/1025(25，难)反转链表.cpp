#include <stdio.h>

/* Reversing Linked List
Given a constant KK and a singly linked list LL, you are supposed to reverse the links of every KK elements on LL.
For example, given LL being 1��2��3��4��5��6, if K = 3, then you must output 3��2��1��6��5��4; if K = 4, you must 
output 4��3��2��1��5��6.
Input Specification:Each input file contains one test case. For each case, the first line contains the address
of the first node, a positive N(<=10^5) which is the total number of nodes, and a positive K(<=N) which is the 
length of the sublist to be reversed. The address of a node is a 5-digit nonnegative integer, and NULL is represented by -1.
Then NN lines follow, each describes a node in the format: Address Data Next.
Address Data Nextwhere Address is the position of the node, Data is an integer, and Next is the position of the next node.

Sample Input:
00100 6 4
00000 4 99999
00100 1 12309
68237 6 -1
33218 3 00000
99999 5 68237
12309 2 33218
Sample Output:

00000 4 33218
33218 3 12309
12309 2 00100
00100 1 99999
99999 5 68237
68237 6 -1
*/

#define N 100001

//�ýṹ������ģ��Input���������ڴ��еĴ洢���
struct linklist {
	int value;
	int next;
};

void listread(struct linklist lis[], int num) {
	int loc, value, next;
	for (int i = 0; i < num; i++) {
		scanf("%d%d%d", &loc, &value, &next);
		lis[loc].value = value;
		lis[loc].next = next;
	}
	return;
}

void listprint(struct linklist lis[], int loc) {
	while (lis[loc].next != -1) {
		printf("%05d %d %05d\n", loc, lis[loc].value, lis[loc].next);
		loc = lis[loc].next;
	}
	//������һ��node����nextֵΪ-1�������ʽ��������next��ʽ��ͬ��
	printf("%05d %d %d\n", loc, lis[loc].value, lis[loc].next);
	return;
}

int count_num(struct linklist lis[], int loc) {
	int num = 1;
	while (lis[loc].next != -1) {
		loc = lis[loc].next;
		num++;
	}
	return num;
}

void reverseK(struct linklist lis[], int K, int listlen) {
	int revnum = listlen / K, count;
	int head = N - 1, first, second, third, head_next; /*first, second, third��˳��������˳��ÿ����ת������secondָ��ָ���Ԫ��
										��next������ָ��first��third�����þ���second��¼�����Ԫ�أ����second����Ԫ�ص�nextָ��
										first����������Ԫ�ض�ʧ*/
	while (revnum > 0) {
		count = K - 1; //ÿK����ת��ֻ��Ҫ��תK-1�ξ���
		first = lis[head].next;
		second = lis[first].next;
		third = lis[second].next;
		while (count > 0) {
			lis[second].next = first;
			first = second;
			second = third;
			third = lis[third].next;
			count--;
		}
		head_next = lis[head].next;
		lis[head_next].next = second;
		lis[head].next = first;
		head = head_next;
		revnum--;
	}
}

int main() {
	struct linklist lis[N];
	int start, num, revK, real_num;
	scanf("%d%d%d", &start, &num, &revK);
	listread(lis, num);
	lis[N - 1].next = start; //���ɵ��������ĿҪ�����ֵ��һ�������������һ��λ��N-1��ģ�������ͷ��㣬�������һ����lis[N - 1]��ʼ
	//���������п��ܺ��в��������ϵĵ㣬�����Ҫ�õ�����������Ľ�����������ͨ�������õ�
	real_num = count_num(lis, lis[N - 1].next);
	reverseK(lis, revK, real_num);
	listprint(lis, lis[N - 1].next);
	return 0;
}