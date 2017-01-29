#include <stdio.h>

#define MAXLEN 100001

int main() {
	char pats[100001];
	gets_s(pats);

	/*countPͳ��ĿǰP�ĸ�����countPAͳ��Ŀǰ��Ч��PA������countPATͳ��Ŀǰ��Ч��PAT����
	countP�϶����ᳬ��int�ķ�Χ��countPA�п��ܳ�����countPAT���п��ܡ�����countPATÿ�ζ�
	����countPA������countPAT�Ľ��ģһ��������ôcountPA�Ľ��Ҳģ�����������Ӱ�쵽PAT�Ľ����*/
	int countP = 0, countPA = 0, countPAT = 0;
	for (int i = 0; i < MAXLEN; i++) {
		if (pats[i]) {
			if (pats[i] == 'P')
				countP++;
			else if (pats[i] == 'A') {
				countPA += countP;
				if (countPA >= 1000000007)
					countPA %= 1000000007;
			}
			else if (pats[i] == 'T') {
				countPAT += countPA;
				if (countPAT >= 1000000007)
					countPAT %= 1000000007;
			}
		}
		else
			break;
	}
	printf("%d", countPAT);
	return 0;
}