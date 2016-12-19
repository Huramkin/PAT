#include <stdio.h>
#include <algorithm>
using namespace std;

#define MAXSTU 100010
typedef struct student STUDENT;
struct student {
	int id;
	int de;
	int cai;
	int category; //���������ʵ�������Ǹ��������Ȱ������������������ͬ���ڰ����ܷ�����
};

STUDENT stulist[MAXSTU];

bool cmp(STUDENT a, STUDENT b) {
	if (a.category != b.category)
		return a.category < b.category; //����ǰ�����ı��ҪС
	else if (a.de + a.cai != b.de + b.cai)
		return a.de + a.cai > b.de + b.cai; //����ǰ����ָܷ�
	else if (a.de != b.de)
		return a.de > b.de;//����ǰ��ĵ·ָ�
	else
		return a.id < b.id; //����ǰ��Ŀ���С
}

int main() {
	int stunum, lowline, highline, numLowline = 0;
	scanf("%d%d%d", &stunum, &lowline, &highline);
	for (int i = 0; i < stunum; i++) {
		scanf("%d%d%d", &stulist[i].id, &stulist[i].de, &stulist[i].cai);
		if (stulist[i].de >= lowline && stulist[i].cai >= lowline) { //��һ��ﲻ������ߵ��˲����
			numLowline++;
			if (stulist[i].de >= highline && stulist[i].cai >= highline)
				stulist[i].category = 1;
			else if (stulist[i].de >= highline)
				stulist[i].category = 2;
			else if (stulist[i].de >= stulist[i].cai)
				stulist[i].category = 3;
			else //��һ������ܶ��ֿ��ܣ�����ŷֵ��ߵ·ֲ����ߵȵȣ���֮ǰ�漸������ϸ�����Ŀ�������֣���һ������ǶԵ�
				stulist[i].category = 4; 
		}
		else
			stulist[i].category = 5; //��һ�಻���
	}

	sort(stulist, stulist + stunum, cmp);

	printf("%d\n", numLowline);
	for (int i = 0; i < numLowline; i++)
		printf("%d %d %d\n", stulist[i].id, stulist[i].de, stulist[i].cai);
	return 0;
}