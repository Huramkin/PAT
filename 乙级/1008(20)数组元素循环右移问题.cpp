#include <stdio.h>
#define N 100

//����Ϊm������ѭ������nλ���൱�ڰ�����ĺ�nλ��ǰ���m-nλ���Է�ת���ٰ��������鷴ת

void myreverse(int arr[], int start, int endd){
    int temp;
    for(; start < endd; start++, endd--){
        temp = arr[start];
        arr[start] = arr[endd];
        arr[endd] = temp;
    }
}

int main(){

    int arrlen, m, arr[N];
    scanf("%d%d", &arrlen, &m);
    for(int i = 0; i < arrlen; i++){
        scanf("%d", &arr[i]);
    }

    m %= arrlen; //��ֹ�ƶ�λ����������������

    myreverse(arr, 0, arrlen - m - 1);
    myreverse(arr, arrlen - m, arrlen - 1);
    myreverse(arr, 0, arrlen - 1);

    for(int i = 0; i < arrlen; i++){
        if (i == 0)
            printf("%d", arr[i]);
        else
            printf(" %d", arr[i]);
    }
    printf("\n");
    return 0;
}
