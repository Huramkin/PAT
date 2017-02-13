#include <stdio.h>

#define MAXQ 105
#define MAXSTU 1005

int ans2id(char ans) {
	switch (ans)
	{
	case('a'):return 0;
	case('b'):return 1;
	case('c'):return 2;
	case('d'):return 3;
	case('e'):return 4;
	}
}

int main() {
	int stunum, quenum, ansnum, rightnum, quescore[MAXQ], queans[MAXQ][5] = { 0 }, 
		queWrongSum[MAXQ] = { 0 }, stuscore[MAXSTU] = { 0 };
	char ans;
	scanf("%d%d", &stunum, &quenum);
	//�����
	for (int i = 0; i < quenum; i++) {
		scanf("%d", &quescore[i]);
		scanf("%d", &ansnum);
		scanf("%d", &rightnum);
		for (int j = 0; j < rightnum; j++) {
			scanf(" %c", &ans); //ע��Ե��ո�
			queans[i][ans2id(ans)] = 1;
		}
	}

	/*// ��֤����ȷ��
	for (int i = 0; i < quenum; i++) {
		for (int j = 0; j < 5; j++) {
			printf("%d", queans[i][j]);
		}
		printf("\n");
	}
	*/
	//����ѧ���𰸲��ж�
	char kuohao;//������������
	for (int i = 0; i < stunum; i++) {//i����ѧ��
		for (int j = 0; j < quenum; j++) {//j������Ŀ
			int stuans[5] = { 0 };
			scanf(" %c %d", &kuohao, &ansnum);//���������ź�ѧ��ѡ��ѡ���������������߿����пո񣬳Ե��ո�
			//�����
			for (int k = 0; k < ansnum; k++) {//k����ѡ��
				scanf(" %c", &ans);
				stuans[ans2id(ans)] = 1;
			}
			scanf("%c", &kuohao);//����������
			
			//�жϴ��Ƿ���ȷ
			int wrong = 0;
			for (int k = 0; k < 5; k++) {
				if (stuans[k] != queans[j][k]) {
					wrong = 1;
					break;
				}
			}
			if (wrong)
				queWrongSum[j]++;
			else
				stuscore[i] += quescore[j];
		}
	}
	//���ѧ���ɼ�
	for (int i = 0; i < stunum; i++) 
		printf("%d\n", stuscore[i]);

	//ͳ�ƴ������������
	int maxwrong = 0;
	for (int i = 0; i < quenum; i++) {
		if (queWrongSum[i] > maxwrong)
			maxwrong = queWrongSum[i];
	}
	if (maxwrong == 0) //˵��������Ŀ���������Ϊ0��û�д���
		printf("Too simple\n");
	else {
		printf("%d", maxwrong);
		for (int i = 0; i < quenum; i++) {
			if (queWrongSum[i] == maxwrong) 
				printf(" %d", i + 1); //��Ŵ�1��ʼ�������е���Ŵ�0��ʼ 
		}
		printf("\n");
	}
	return 0;
}