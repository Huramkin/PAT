#include <stdio.h>

typedef struct peopleInfo PINFO;
struct peopleInfo{
	char name[6];
	int year;
	int month;
	int day;
};

int AisOlder(PINFO A, PINFO B) {//���B��A����С������1����A�����ͬ������0
	if (B.year > A.year)
		return 1;
	else if (B.year == A.year && B.month > A.month)
		return 1;
	else if (B.year == A.year && B.month == A.month && B.day > A.day)
		return 1;
	else
		return 0;
}

int main() {
	int num;
	PINFO people[100000];
	scanf("%d", &num);
	for (int i = 0; i < num; i++) {
		scanf("%s%d/%d/%d", people[i].name, &people[i].year, &people[i].month, &people[i].day);
	}
	int oldestID = -1, youngestID = -1, count = 0;
	PINFO today = { "today", 2014, 9, 6 }, year200 = { "y200", 2014 - 200, 9, 6 };//����200�겻�㲻��������
	for (int i = 0; i < num; i++) {
		if (AisOlder(today, people[i]))//�����ʵ�ʳ������仹�ϣ�˵��ʵ�ʳ��������ڽ���֮�󣬲�����
			continue;
		else if (AisOlder(people[i], year200)) //��200��ǰ�������˻��ϣ�˵���������200��������
			continue;
		else {
			count++;
			if (oldestID == -1)
				oldestID = i;
			if (youngestID == -1)
				youngestID = i;
			if (AisOlder(people[i], people[oldestID]))
				oldestID = i;
			if (AisOlder(people[youngestID], people[i]))
				youngestID = i;
		}
	}
	
	if(oldestID == -1 && youngestID == -1) //����������䶼�ǲ������
		printf("%d\n", count);
	else
		printf("%d %s %s\n", count, people[oldestID].name, people[youngestID].name);
	return 0;
}