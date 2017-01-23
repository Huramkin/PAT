#include <stdio.h>
#include <math.h>

typedef struct fenshu FENSHU;
struct fenshu {
	int front;
	int top;
	int under;
};

int GCD(int top, int under) {
	top = abs(top);
	under = abs(under);
	if (under % top == 0)
		return top;
	else {
		int temp = top;
		top = under % top;
		under = temp;
		return GCD(top, under);
	}
}

FENSHU simplify1(FENSHU num) { //���򵽼ٷ�����ʽ�����ڼ���
	if (num.top) {//������Ӳ�Ϊ0
		int gcd = GCD(abs(num.top), num.under);
		num.top /= gcd;
		num.under /= gcd;
	}
	return num;
}

void simplifyANDprint(FENSHU num) { //���򵽴�������ʽ��������ʾ
	//�жϷ���
	if (num.top == 0)
		printf("0");
	else {
		int negative_flag = 0;
		if (num.top < 0 && num.under < 0)
			;//����䣬ʲô������
		else if (num.top < 0 || num.under < 0) {
			negative_flag = 1;
			printf("(-");
		}
		num.top = abs(num.top);
		num.under = abs(num.under);
		int gcd = GCD(num.top, num.under);
		num.front = num.top / num.under;
		num.top /= gcd;
		num.under /= gcd;
		num.top -= num.front * num.under;
		if (num.top == 0)//����front��topȫΪ0��ʱ��Ҳ���0
			printf("%d", num.front);
		else if (num.front == 0)
			printf("%d/%d", num.top, num.under);
		else
			printf("%d %d/%d", num.front, num.top, num.under);

		if (negative_flag)
			printf(")");
	}
	return;
}

FENSHU plus(FENSHU num1, FENSHU num2) {
	FENSHU ans;
	int undergcd = GCD(num1.under, num2.under);
	ans.under = num1.under / undergcd * num2.under;
	ans.top = num1.top * ans.under / num1.under + num2.top * ans.under / num2.under;
	return ans;
}

FENSHU minus(FENSHU num1, FENSHU num2) {
	FENSHU ans;
	int undergcd = GCD(num1.under, num2.under);
	ans.under = num1.under / undergcd * num2.under;
	ans.top = num1.top * ans.under / num1.under - num2.top * ans.under / num2.under;
	return ans;
}

FENSHU mult(FENSHU num1, FENSHU num2) {
	FENSHU ans;
	if (!num1.top || !num2.top) {//��һ������Ϊ0���˷������һ��Ϊ0
		ans.top = 0;
		ans.under = 1;
	}
	else {
		int gcd1 = GCD(num1.top, num2.under);
		int gcd2 = GCD(num2.top, num1.under);
		ans.under = (num1.under / gcd2) * (num2.under / gcd1);
		ans.top = (num1.top / gcd1) * (num2.top / gcd2);
	}
	return ans;
}

int dev(FENSHU num1, FENSHU num2, FENSHU *ans) {//�����num1/num2
	if (num2.top == 0)
		return 0;
	else {
		int temp = num2.top;
		num2.top = num2.under;
		num2.under = temp;
		*ans = mult(num1, num2);//�ѳ���ת���ɳ˷���
		return 1;
	}
}

int main() {
	
	FENSHU num1, num2;
	num1.front = 0; num2.front = 0;
	scanf("%d/%d%d/%d", &num1.top, &num1.under, &num2.top, &num2.under);
	if(num1.top)
		num1 = simplify1(num1);
	if(num2.top)
		num2 = simplify1(num2);
	FENSHU ansplus, ansminus, ansmult, ansdev;
	//����ӷ�
	simplifyANDprint(num1);
	printf(" + ");
	simplifyANDprint(num2);
	printf(" = ");
	ansplus = plus(num1, num2);
	simplifyANDprint(ansplus);
	printf("\n");
	//�������
	simplifyANDprint(num1);
	printf(" - ");
	simplifyANDprint(num2);
	printf(" = ");
	ansminus = minus(num1, num2);
	simplifyANDprint(ansminus);
	printf("\n");
	//����˷�
	simplifyANDprint(num1);
	printf(" * ");
	simplifyANDprint(num2);
	printf(" = ");
	ansmult = mult(num1, num2);
	simplifyANDprint(ansmult);
	printf("\n");
	//�������
	simplifyANDprint(num1);
	printf(" / ");
	simplifyANDprint(num2);
	printf(" = ");
	if (!dev(num1, num2, &ansdev))
		printf("Inf\n");
	else
		simplifyANDprint(ansdev);
	printf("\n");

	return 0;
}