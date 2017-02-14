#include <stdio.h>
#include <algorithm>
using namespace std;
//!!!ע�����⣡������E���ﳵ����EӢ��ǳ�������������ȣ�
/*���Ͽ���˼·��
(1)i from 1 to n�����������ݽ��дӴ�С����
(2)a[i]<=iʱ��break;
(3)i-1��Ϊ����
*/


#define MAXDAY 100010
int dist[MAXDAY] = { 0 };

bool cmp(int a, int b) {
	return a > b;
}

int main() {
	int day;
	scanf("%d", &day);
	for (int i = 0; i < day; i++)
		scanf("%d", &dist[i]);
	
	sort(dist, dist + day, cmp);
	int find_flag = 0;
	for (int i = 0; i < day; i++) {
		if (i + 1 >= dist[i]) { //�������ĳ��������ȵ������󣬾�˵��ǰһ���Ǵ𰸣���������Ŵ�1, i + 1����������
			printf("%d\n", i);
			find_flag = 1;
			break;
		}
	}
	if (!find_flag) {
		printf("%d\n", day);
	}
	return 0;
}