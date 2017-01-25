#include <stdio.h>
#include <algorithm>
using namespace std;

#define MAXNUM 100

int if_merge(int originarr[], int midarr[], int len, int num) {
	int part = num / len;
	int last_flag = 0; //������ʣ�³��Ȳ�����һ���֣���һ����ҲҪ������õ�
	if (num % len)
		last_flag = 1;
	/*����merge sort���ص㣬ÿһС�ζ�������õġ����������뷨�ǲ鿴�ǲ���ÿһС�ε�ǰ���ֵ���Ⱥ����ֵС
	����ǣ��Ǿ���merge sort��������ǣ��Ǿ���insertion sort����������뷨�����еĿ��ܡ�����ԭʼ��������
	5 4 3 2 1 6 7 8������insertion sort����4�κ󣬴�Ϊ1 2 3 4 5 6 7 8����������𰸻ᱻ�ж�Ϊ��merge 
	sort�Ľ������Ϊ����ÿ��С��4���㣨1 2 3 4��5 6 7 8�������������������Բ���merge sort����Ϊÿ��С��
	���ֵ�����С�����ֵ�ǲ�ͬ�ģ������merge sort�Ļ������е���һ����ʱ��ǰ��С�ε��ĸ��㻹�������5 4 3 2
	�ĸ��㣬ֻ��˳������2 3 4 5���ѡ���Ҳ˵������Ŀ������������в�����û�õģ�ÿ�������������õģ�����޸�
	�ж��������ĳ�����merge sort��˼·�ڶ�Ӧ��ÿһ��С���������������������ĳһ������Ŀ�������м�������ȫ
	һ�����Ǿ�ȷ��һ����merge sort���ɡ�*/
	for (int i = 0; i < part; i++) {
		sort(originarr + i * len, originarr + (i + 1) * len);
		for (int j = i * len + 1; j < (i + 1) * len; j++) {
			if (midarr[j] != originarr[j])
				return 0;
		}
	}
	if (last_flag) {
		sort(midarr + part * len, midarr + num);
		for (int j = part * len + 1; j < num; j++) {
			if (midarr[j] != originarr[j])
				return 0;
		}
	}
	return len;
}

void mergeOneMore(int midarr[], int len, int num) {
	len *= 2;
	int part = num / len;
	int last_flag = 0; //������ʣ�³��Ȳ�����һ���֣���һ����ҲҪ������õ�
	if (num % len)
		last_flag = 1;
	for (int i = 0; i < part; i++) 
		sort(midarr + i * len, midarr + (i + 1) * len);
	if (last_flag)
		sort(midarr + part * len, midarr + num);
}

void insertOneMore(int midarr[], int num) {
	for (int i = 1; i < num; i++) {
		if (midarr[i - 1] > midarr[i]) {
			int temp = midarr[i];
			for (int j = 0; j < i; j++) {
				if (midarr[j] > temp) {//��һ����temp���ֵ��λ�þ���temp��λ��
					//��j��ʼ������ƶ�һ��λ��
					for (int p = i; p > j; p--) {
						midarr[p] = midarr[p - 1];
					}
					midarr[j] = temp;
					return;
				}
			}
		}
	}
}

int main() {
	int num, arr[MAXNUM], midarr[MAXNUM];
	scanf("%d", &num);
	for (int i = 0; i < num; i++)
		scanf("%d", &arr[i]);
	for (int i = 0; i < num; i++)
		scanf("%d", &midarr[i]);

	int insert_len;
	for (int len = 2; len < num; len *= 2) {
		insert_len = if_merge(arr, midarr, len, num);
		if (insert_len) {
			printf("Merge Sort\n");
			mergeOneMore(midarr, insert_len, num);
			printf("%d", midarr[0]);
			for (int i = 1; i < num; i++)
				printf(" %d", midarr[i]);
			printf("\n");
			return 0;
		}
	}
	printf("Insertion Sort\n");
	insertOneMore(midarr, num);
	printf("%d", midarr[0]);
	for (int i = 1; i < num; i++)
		printf(" %d", midarr[i]);
	printf("\n");
	return 0;
}