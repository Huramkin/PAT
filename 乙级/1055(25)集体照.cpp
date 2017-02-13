#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

typedef struct person Person;
struct person {
	char name[10];
	int height;
};

#define MAXNUM 10010
Person people[MAXNUM];
Person ans[10][MAXNUM];

bool cmp(Person a, Person b) {
	if (a.height != b.height)
		return a.height > b.height;
	else
		return strcmp(a.name, b.name) <= 0; //strcmp����ǰ���ַ������ں���ʱ��������ֵ����ȷ���0��С�ڷ��ظ�ֵ
}

int main() {
	int num, row;
	scanf("%d%d", &num, &row);
	for (int i = 0; i < num; i++)
		scanf("%s%d", &people[i].name, &people[i].height);

	sort(people, people + num, cmp);

	int rowsize = num / row;
	int lastrowsize = num - rowsize * row + rowsize;
	int peopleID = 0; //��¼���ŵ��ĸ�����
	int lastmiddle = lastrowsize / 2; //�������е�λ��Ҫ��ʵ�ʵ�λ��С1
	int lastcount = lastrowsize, move = 1, left0right1 = 0;//�ȸ��м����߰���λ��

	//�����һ�ŵ��м䰲��λ��
	ans[row - 1][lastmiddle] = people[peopleID];
	peopleID++;
	lastcount--;
	//�����һ�ŵ�����λ�ð���
	while (lastcount > 0) {
		if (left0right1 == 0) {
			ans[row - 1][lastmiddle - move] = people[peopleID];
			left0right1 = 1;
		}
		else{
			ans[row - 1][lastmiddle + move] = people[peopleID];
			left0right1 = 0;
			move++;
		}
		peopleID++;
		lastcount--;
	}

	//������һ��λ��
	for (int i = 0; i < lastrowsize; i++) {
		if (i == 0)
			printf("%s", ans[row - 1][i].name);
		else
			printf(" %s", ans[row - 1][i].name);
	}
	printf("\n");

	//�������Ű���λ��
	int middle = rowsize / 2; //�������е�λ��Ҫ��ʵ�ʵ�λ��С1
	for (int i = row - 2; i >= 0; i--) {
		int count = rowsize, move = 1, left0right1 = 0;
		ans[i][middle] = people[peopleID];
		peopleID++;
		count--;
		while (count > 0) {//�ٸ�����λ�ð�����
			if (left0right1 == 0) {
				ans[i][middle - move] = people[peopleID];
				left0right1 = 1;
			}
			else {
				ans[i][middle + move] = people[peopleID];
				left0right1 = 0;
				move++;
			}
			peopleID++;
			count--;
		}
		//������
		for (int j = 0; j < rowsize; j++) {
			if (j == 0)
				printf("%s", ans[i][j].name);
			else
				printf(" %s", ans[i][j].name);
		}
		printf("\n");
	}
	return 0;
}
