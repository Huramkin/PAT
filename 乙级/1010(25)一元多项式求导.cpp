#include <stdio.h>


int main(){
    int poly[2001] = {0}, power, coeff;
    char mark;
    do{
        scanf("%d%d%c", &coeff, &power, &mark);
        power += 1000;
        poly[power] = coeff;
    }while(mark != '\n');

    //���
    int first_flag = 1;
    for(int i = 2000; i >= 0; i--){
        if (i == 1000) //��������Ϊ0�������
            continue;
        else if (poly[i]){
            if (first_flag){
                printf("%d %d",poly[i] * (i - 1000),i - 1001);
                first_flag = 0;
            }
            else
                printf(" %d %d",poly[i] * (i - 1000),i - 1001);
        }
    }
    if (first_flag) //˵��û������������0����ʽ��Ӧ�����0 0
        printf("0 0");
    printf("\n");
    return 0;
}
