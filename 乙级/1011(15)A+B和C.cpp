#include <stdio.h>

int main(){
    int num;
    scanf("%d", &num);
    for(int i = 1; i <= num; i++){
        long long a, b, c;
        scanf("%I64d%I64d%I64d", &a, &b, &c); // ��windows�����long long��%I64d,linux����%lld������ύʱҪ����%lld
        if (a + b > c)
            printf("Case #%d: true\n", i);
        else
            printf("Case #%d: false\n", i);
    }
    return 0;
}

//�ύ��
/*
#include <stdio.h>

int main(){
    int num;
    scanf("%d", &num);
    for(int i = 1; i <= num; i++){
        long long a, b, c;
        scanf("%lld%lld%lld", &a, &b, &c);
        if (a + b > c)
            printf("Case #%d: true\n", i);
        else
            printf("Case #%d: false\n", i);
    }
    return 0;
}
*/
