#include <stdio.h>
#include <string.h>

/*������Ҫ�ر�ע������Ĺ�����ϸ�����������������������13���Ƶ���λ���������λ��Ϊ0���������ʮλ ��λ�������Ǹ�λΪ1�Ļ�����ֻ�������λ����
Ҳ����˵��0����ַ�ֻ��ֵΪ0��ʱ����������ʱ�򶼲������*/
int power(int a, int b) {
	int ans = 1;
	for (int i = 0; i < b; i++) 
		ans *= a;
	return ans;
}
int str2int(char str[]) {
	int len = strlen(str), ans = 0;
	for (int i = 0; i < len; i++) {
		ans += (str[i] - '0') * power(10, len - i - 1);
	}
	return ans;
}

int main() {
	char mar[13][5] = { "tret","jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec" };
	char marhigh[12][5] = { "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou" };

	int num; char total[10], str1[5], str2[5], enter;
	scanf("%d", &num);
	scanf("%c", &enter);//�Ե��س�
	for (int i = 0; i < num; i++) {
		gets_s(total);
		if (total[0] >= '0' && total[0] <= '9') {//˵��������
			int number = str2int(total);
			int tenth = number / 13;
			int ones = number % 13;
			if (tenth > 0) {
				if (ones == 0) //�����λ��0��������������Ĺ��򣬲����
					printf("%s\n", marhigh[tenth - 1]);
				else {
					printf("%s ", marhigh[tenth - 1]);
					printf("%s\n", mar[ones]);
				}
			}
			else//ֻ�и�λ����ô�����ǲ���0�������
				printf("%s\n", mar[ones]);
		}
		else {//˵���ǻ�����
			int two_digit_flag = 0, stopid;
			//�����һλ�Ļ����ģ��ͻ�ֱ�ӵ���������û�пո�ֱ�����б����ҵ���ӡ
			for (int i = 0; i < 10; i++) {
				if (total[i]) {
					if (total[i] == ' ') {
						two_digit_flag = 1;
						str1[i] = '\0';
						stopid = i;
						break;
					}
					else {
						str1[i] = total[i];
					}
				}
				else {
					str1[i] = '\0';
					break;
				}
			}

			if (!two_digit_flag) { //˵����һλ������
				int find = 0;
				for (int i = 0; i < 13; i++) {
					if (!strcmp(mar[i], total)) {
						printf("%d\n", i);
						find = 1; //�ڸ�λ�����ҵ���
						break;
					}
				}
				if (!find) {
					for (int i = 0; i < 12; i++) {
						if (!strcmp(marhigh[i], total)) {
							printf("%d\n", (i + 1) * 13);
							break;
						}
					}
				}
			}
			else {//��λ�Ļ�����
				int sum = 0;
				for (int i = stopid + 1; i < stopid + 5; i++) {
					if (total[i]) {
						str2[i - stopid - 1] = total[i];
					}
					else {
						str2[i - stopid - 1] = '\0';
						break;
					}
				}
				for (int i = 0; i < 13; i++) {
					if (!strcmp(mar[i], str2)) {
						sum += i;
						break;
					}
				}
				for (int i = 0; i < 12; i++) {
					if (!strcmp(marhigh[i], str1)) {
						sum += (i + 1) * 13;
						break;
					}
				}
				printf("%d\n", sum);
			}
		}
	}
	return 0;
}