#include <stdio.h>
#define tick 100

int main() {
	int start, end;
	scanf("%d%d", &start, &end);
	int time = (((float) (end - start)) / 100 + 0.5); //��������int��ʱ���ȼ�0.5�ڱ�int����������Ч��һ�¡�
	int hou = time / 3600;
	int min = (time - hou * 3600) / 60;
	int sec = time % 60;
	printf("%02d:%02d:%02d", hou, min, sec);
	return 0;
}