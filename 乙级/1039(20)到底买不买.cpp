#include <stdio.h>

#define MAXCHAR 1001

int main() {
	int sum09[10] = { 0 }, sumaz[26] = { 0 }, sumAZ[26] = { 0 }; //�ṩ����ɫͳ��
	int want09[10] = { 0 }, wantaz[26] = { 0 }, wantAZ[26] = { 0 };//��Ҫ����ɫͳ��
	char provide[MAXCHAR], want[MAXCHAR];
	gets_s(provide);
	gets_s(want);
	//ͳ���ṩ��
	for (int i = 0; i < MAXCHAR; i++) {
		if (provide[i]) {
			if (provide[i] >= '0' && provide[i] <= '9')
				sum09[provide[i] - '0']++;
			else if (provide[i] >= 'a' && provide[i] <= 'z')
				sumaz[provide[i] - 'a']++;
			else if (provide[i] >= 'A' && provide[i] <= 'Z')
				sumAZ[provide[i] - 'A']++;
		}
		else
			break;
	}
	//ͳ����Ҫ��
	for (int i = 0; i < MAXCHAR; i++) {
		if (want[i]) {
			if (want[i] >= '0' && want[i] <= '9')
				want09[want[i] - '0']++;
			else if (want[i] >= 'a' && want[i] <= 'z')
				wantaz[want[i] - 'a']++;
			else if (want[i] >= 'A' && want[i] <= 'Z')
				wantAZ[want[i] - 'A']++;
		}
		else
			break;
	}
	//ͳ��ȱ�˶���
	int lack = 0;
	for (int i = 0; i < 10; i++) {
		if (want09[i] > sum09[i])
			lack += want09[i] - sum09[i];
	}
	for (int i = 0; i < 26; i++) {
		if (wantaz[i] > sumaz[i])
			lack += wantaz[i] - sumaz[i];
		if (wantAZ[i] > sumAZ[i])
			lack += wantAZ[i] - sumAZ[i];
	}
	if (lack)
		printf("No %d", lack);
	else {//���lack����0��˵����ȱ��ɫ
		int len = 0, wantlen = 0;
		for (int i = 0; i < 10; i++) {
			len += sum09[i];
			wantlen += want09[i];
		}
		for (int i = 0; i < 26; i++) {
			len += sumaz[i];
			wantlen += wantaz[i];
			len += sumAZ[i];
			wantlen += wantAZ[i];
		}
		printf("Yes %d", len - wantlen);
	}
	return 0;
}