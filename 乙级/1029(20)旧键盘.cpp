#include <stdio.h>
#include <string.h>
int main() {
	int isCharBroken[26] = { 0 }, isNumBroken[10] = { 0 }, is_Broken = 0;//���ڱ����ظ����
	char before[81] = { '\0' }, after[81] = { '\0' };//��Ϊbefore�ر�after�������ܻ���after����û�и�ֵ�Ĳ��ֱȽϣ�����Ҫ��ʼ�����������ֵ
	gets_s(before);//�ύʱҪ�ĳ�gets()
	gets_s(after);//�ύʱҪ�ĳ�gets()

	int len = strlen(before);
	int afterID = 0, brokenCount = 0;
	for (int i = 0; i < len; i++) {
		if (before[i] == after[afterID])
			afterID++;
		else {//˵��������
			if (before[i] >= 'A' && before[i] <= 'Z' && !isCharBroken[before[i] - 'A']) {
				isCharBroken[before[i] - 'A'] = 1;
				printf("%c", before[i]);
			}
			else if (before[i] >= 'a' && before[i] <= 'z' && !isCharBroken[before[i] - 'a']) {
				isCharBroken[before[i] - 'a'] = 1;
				printf("%c", before[i] - 'a' + 'A');
			}
			else if (before[i] >= '0' && before[i] <= '9' && !isNumBroken[before[i] - '0']) {
				isNumBroken[before[i] - '0'] = 1;
				printf("%c", before[i]);
			}
			else if (before[i] == '_' && !is_Broken) {
				is_Broken = 1;
				printf("_");
			}
			else
				continue;
		}
	}
	printf("\n");
	return 0;
}