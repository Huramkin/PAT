#include <stdio.h>
#include <math.h>

using namespace std;

int is_prime(int num){
    int maxm = sqrt(num);
    for(int i = 2; i <= maxm; i++){
        if (num % i == 0)
            return 0;
    }
    return 1;
}

int main(){
    int prime[100000], n;
    scanf("%d", &n);

    int result_no = 0;
    for(int i = 3; i <= n; i++){ //2��3���������������Բ���Ҫ��������2�������������2����ô�����is����prime����ҲҪ��ø�����
        if (is_prime(i)){
            prime[result_no] = i;
            result_no++;
        }
    }
    int sum = 0;
    for(int i = 0; i < result_no - 1; i++){ //2��3���������������Բ���Ҫ��������2�������������2����ô�����is����prime����ҲҪ��ø�����
        if ((prime[i + 1] - prime[i]) == 2)
            sum++;
    }
    printf("%d", sum);
    return 0;
}
